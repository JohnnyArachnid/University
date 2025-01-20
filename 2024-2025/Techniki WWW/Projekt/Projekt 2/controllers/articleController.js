const Article = require('../models/Article');
const { Op } = require('sequelize');

exports.getAllArticles = async (req, res, next) => {
    try {
        const lang = req.currentLang;

        const articles = await Article.findAll({
            attributes: ['id', 'title', 'title_ang', 'tag', 'tag_ang', 'author', 'number', 'creation_date'],
            order: [['creation_date', 'DESC']]
        });

        if (articles.length === 0) {
            const noArticlesMessage =
                lang === 'pl'
                    ? 'Brak artykułów.'
                    : 'No articles.';
            return res.render('index', {
                articles: [],
                values: { author: 'all' },
                currentLang: lang,
                noArticlesMessage
            });
        }

        res.render('index', {
            articles,
            values: { author: 'all' },
            currentLang: lang,
            noArticlesMessage: null
        });
    } catch (error) {
        console.error('Error fetching articles:', error);
        next(error);
    }
};

exports.getSelectedArticles = async (req, res, next) => {
    try {
        const { title, author, tags, start_date, end_date } = req.body;
        const lang = req.currentLang;
        const values = { title, author, tags, start_date, end_date }

        const filters = {};

        if (title && typeof title === 'string') {
            filters[lang === 'pl' ? 'title' : 'title_ang'] = {
                [Op.like]: `%${title.trim()}%`
            };
        }

        if (author && author !== 'all' && typeof author === 'string') {
            filters.author = author.trim();
        }

        if (tags && Array.isArray(tags)) {
            const tagArray = tags.map(tag => tag.trim());
            
            if (tagArray && tagArray.length > 0) {
                const tagConditions = tagArray.map(tag => ({
                    [Op.like]: `%${tag}%`
                }));
                
                filters[lang === 'pl' ? 'tag' : 'tag_ang'] = {
                    [Op.and]: tagConditions
                };
            }
        }

        if (start_date) {
            const startDateObj = new Date(start_date);
            if (!isNaN(startDateObj)) {
                filters.creation_date = { [Op.gte]: startDateObj };
            }
        }

        if (end_date) {
            const endDateObj = new Date(end_date);
            if (!isNaN(endDateObj)) {
                filters.creation_date = {
                    ...filters.creation_date,
                    [Op.lte]: endDateObj
                };
            }
        }

        const articles = await Article.findAll({
            attributes: ['id', 'title', 'title_ang', 'tag', 'tag_ang', 'author', 'number', 'creation_date'],
            where: filters,
            order: [['creation_date', 'DESC']]
        });

        if (articles.length === 0) {
            const noArticlesMessage =
                lang === 'pl'
                    ? 'Brak artykułów spełniających podane kryteria.'
                    : 'No articles match the given criteria.';
            return res.render('index', {
                articles: [],
                values,
                currentLang: lang,
                noArticlesMessage
            });
        }

        res.render('index', {
            articles,
            values,
            currentLang: lang,
            noArticlesMessage: null
        });
    } catch (error) {
        console.error('Error fetching articles:', error);
        next(error);
    }
};

exports.getArticleById = async (req, res, next) => {
    try {
        const id = req.params.id;
        const lang = req.currentLang;

        const article = await Article.findByPk(id);

        if (!article) {
            const error = new Error('Article not found');
            error.status = 404;
            return next(error);
        }

        const content = lang === 'pl' ? article.content : article.content_ang;
        const formattedContent = content.replace(/\n/g, '<br />');

        return res.render('./others/article', {
            article,
            currentLang: lang,
            formattedContent,
        });
    } catch (error) {
        console.error('Error fetching articles:', error);
        return next(error);
    }
};