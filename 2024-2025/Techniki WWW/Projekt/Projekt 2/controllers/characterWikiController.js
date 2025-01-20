const Character_wiki = require('../models/Character_wiki');

exports.getAllCharacters = async (req, res, next) => {
    try {
        const lang = req.currentLang;

        const characters = await Character_wiki.findAll({
            attributes: ['id', 'number', 'hero_name', 'hero_name_ang', 'short_description', 'short_description_ang'],
            order: [['id', 'ASC']]
        });

        if (characters.length === 0) {
            const noCharactersMessage =
                lang === 'pl'
                    ? 'Brak postaci.'
                    : 'No characters.';
            return res.render('subpages/characters_wiki', {
                characters: [],
                currentLang: lang,
                noCharactersMessage
            });
        }

        res.render('subpages/characters_wiki', {
            characters,
            currentLang: lang,
            noCharactersMessage: null
        });
    } catch (error) {
        console.error('Error fetching characters:', error);
        next(error);
    }
};

exports.getCharacterById = async (req, res, next) => {
    try {
        const id = req.params.id;
        const lang = req.currentLang;

        const character = await Character_wiki.findByPk(id);

        if (!character) {
            const error = new Error('Character not found');
            error.status = 404;
            return next(error);
        }

        return res.render('others/character', {
            character,
            currentLang: lang,
        });
    } catch (error) {
        console.error('Error fetching character:', error);
        return next(error);
    }
};