const sequelize = require('../config/config.js');
const { DataTypes } = require('sequelize');

const Article = sequelize.define('Article', {
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
    tag: {
      type: DataTypes.STRING,
      allowNull: false,
      get() {
          const value = this.getDataValue('tag');
          return value ? JSON.parse(value) : [];
      },
      set(value) {
        this.setDataValue('tag', JSON.stringify(value));
      },
    },
    tag_ang: {
      type: DataTypes.STRING,
      allowNull: false,
      get() {
          const value = this.getDataValue('tag_ang');
          return value ? JSON.parse(value) : [];
        },
        set(value) {
          this.setDataValue('tag_ang', JSON.stringify(value));
      },
    },
    content: {
        type: DataTypes.TEXT,
        allowNull: false,
    },
    content_ang: {
        type: DataTypes.TEXT,
        allowNull: false,
    },
    author: {
      type: DataTypes.ENUM('Administrator', 'Moderator'),
      allowNull: false,
    },
    number: {
      type: DataTypes.INTEGER,
      allowNull: false,
    },
    creation_date: {
      type: DataTypes.DATEONLY,
      allowNull: false,
    }
  }, {
    tableName: 'article',
    timestamps: true,
  }
);
  
module.exports = Article;