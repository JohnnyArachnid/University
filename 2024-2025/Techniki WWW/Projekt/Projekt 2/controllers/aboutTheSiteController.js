exports.getAboutTheSite = (req, res, next) => {
    try {
        const lang = req.currentLang;
        res.render('subpages/about_the_site', { currentLang: lang });
    } catch (error) {
        console.error('Error rendering about_the_site page:', error);
        next(error);
    }
};