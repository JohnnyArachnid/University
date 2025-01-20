const { Sequelize } = require('sequelize');

const sequelize = new Sequelize(
  'comicblogproject',  // DB_NAME
  'root',               // DB_USER
  'zaq12wsx',           // DB_PASSWORD
  {
    host: 'localhost',   // DB_HOST
    port: 3306,          // DB_PORT
    dialect: 'mysql',
    logging: false,
  }
);

sequelize
  .authenticate()
  .then(() => {
    console.log('Connection to the database is positive!');
  })
  .catch((err) => {
    console.error('Error while connecting to the database:', err);
});

module.exports = sequelize;