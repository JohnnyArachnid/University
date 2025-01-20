const express = require('express');
const router = express.Router();
const articleController = require('../controllers/articleController.js');
const aboutTheSiteController = require('../controllers/aboutTheSiteController.js');
const comicBookAnnouncementController = require('../controllers/comicBookAnnouncementController.js');
const characterWikiController = require('../controllers/characterWikiController.js');
const contactController = require('../controllers/contactController.js');

router.get('/', articleController.getAllArticles);

router.post('/', articleController.getSelectedArticles);

router.get('/others/article/:id', articleController.getArticleById);

router.get('/subpages/about_the_site', aboutTheSiteController.getAboutTheSite);

router.get('/subpages/comic_book_announcement/:page', comicBookAnnouncementController.getPaginatedComics);

router.get('/subpages/characters_wiki', characterWikiController.getAllCharacters);

router.get('/others/character/:id', characterWikiController.getCharacterById);

router.get('/subpages/contact', contactController.getContactSite);

router.post('/subpages/contact', contactController.submitContactSite);

module.exports = router;