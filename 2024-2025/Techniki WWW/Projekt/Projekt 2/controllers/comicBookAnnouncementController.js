const Comic_announcement = require('../models/Comic_announcement');

exports.getPaginatedComics = async (req, res, next) => {
    try {
        const lang = req.currentLang;
        const page = parseInt(req.params.page, 10) || 1;
        const limit = 7;
        const offset = (page - 1) * limit;

        const { count, rows: comics } = await Comic_announcement.findAndCountAll({
            attributes: ['title', 'title_ang', 'release_date', 'expectations', 'number'],
            order: [['release_date', 'DESC']],
            limit,
            offset,
        });

        if (count === 0) {
            const noComicsMessage =
                lang === 'pl'
                    ? 'Brak zapowiedzi komiksowych.'
                    : 'No comic book announcements.';
            return res.render('subpages/comic_book_announcement', {
                comic_book_announcement: null,
                currentLang: lang,
                noComicsMessage,
                totalPages: 0,
                currentPage: page,
                prevPage: 0,
                nextPage: 0,
            });
        }

        const totalPages = Math.ceil(count / limit);

        res.render('subpages/comic_book_announcement', {
            comic_book_announcement: comics,
            currentLang: lang,
            noComicsMessage: null,
            totalPages,
            currentPage: page,
            prevPage: page > 1 ? page - 1 : null,
            nextPage: page < totalPages ? page + 1 : null,
        });
    } catch (error) {
        console.error('Error fetching paginated comics:', error);
        next(error);
    }
};