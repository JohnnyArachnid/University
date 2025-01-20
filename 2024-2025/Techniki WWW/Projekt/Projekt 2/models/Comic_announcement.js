const sequelize = require('../config/config.js');
const { DataTypes } = require('sequelize');

const Comic_announcement = sequelize.define('Comic_announcement', {
    id: {
      type: DataTypes.INTEGER,
      primaryKey: true,
      autoIncrement: true,
    },
    title: {
      type: DataTypes.STRING,
      allowNull: false,
    },
    title_ang: {
      type: DataTypes.STRING,
      allowNull: false,
    },
    release_date: {
      type: DataTypes.DATEONLY,
      allowNull: false,
    },
    expectations: {
      type: DataTypes.INTEGER,
      allowNull: false,
      validate: {
        min: 0,
        max: 100,
      },
    },
    number: {
        type: DataTypes.INTEGER,
        allowNull: false,
      },
  }, {
    tableName: 'comicannouncement',
    timestamps: true,
  }
);
  
module.exports = Comic_announcement;