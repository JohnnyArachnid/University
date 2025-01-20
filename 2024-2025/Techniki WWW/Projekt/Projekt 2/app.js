const express = require('express');
const path = require('path');
const session = require('express-session');
const sequelize = require('./config/config.js');

const app = express();

app.use(session({
  secret: 'secret-key',
  resave: false,
  saveUninitialized: true,
  cookie: { secure: false }
}));

app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(express.static(path.join(__dirname, 'public')));

app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));

app.use((req, res, next) => {
  if (!req.session.currentLang) {
    req.session.currentLang = 'pl';
  }
  req.currentLang = req.session.currentLang;
  next();
});

const mainRoutes = require('./routes/main');
app.use('/', mainRoutes);

app.get('/setlang/:lang', (req, res) => {
  const lang = req.params.lang;
  if (['pl', 'en'].includes(lang)) {
    req.session.currentLang = lang;
  }
  const redirectUrl = req.get('Referrer') || '/';
  res.redirect(redirectUrl);
});

app.use((req, res, next) => {
  const error = new Error('Page not found');
  error.status = 404;
  next(error);
});

app.use((err, req, res, next) => {
  console.error(err.stack);
  const lang = req.currentLang;
  const status = err.status || 500;
  const errorMessages = {
    404: {
      pl: 'Nie znaleziono strony',
      en: 'Page not found'
    },
    500: {
      pl: 'Błąd serwera',
      en: 'Server error'
    },
    default: {
      pl: 'Wystąpił błąd',
      en: 'An error occurred'
    }
  };

  const message = errorMessages[status] ? errorMessages[status][req.currentLang] : errorMessages.default[req.currentLang];
  res.status(status).render('error', {
    title: message,
    currentLang: lang,
    status
  });
});

sequelize
  .sync({ alter: true })
  .then(() => {
    const PORT = process.env.PORT || 3000;
    app.listen(PORT, () => {
      console.log(`Serwer is working on the port: ${PORT}`);
      console.log(`http://localhost:${PORT}/`)
    });
  })
  .catch((err) => {
    console.error('There was a error while connecting to the database:', err);
});