const sequelize = require('../config/config.js');
const { DataTypes } = require('sequelize');

const Character_wiki = sequelize.define('Character_wiki', {
    id: {
      type: DataTypes.INTEGER,
      primaryKey: true,
      autoIncrement: true,
    },
    hero_name: {
        type: DataTypes.STRING,
        allowNull: false,
    },
    hero_name_ang: {
      type: DataTypes.STRING,
      allowNull: false,
    },
    short_description: {
        type: DataTypes.STRING,
        allowNull: false,
    },
    short_description_ang: {
        type: DataTypes.STRING,
        allowNull: false,
    },
    real_name: {
        type: DataTypes.STRING,
        allowNull: false,
    },
    age: {
        type: DataTypes.INTEGER,
        allowNull: false,
    },
    description: {
        type: DataTypes.TEXT,
        allowNull: false,
    },
    description_ang: {
        type: DataTypes.TEXT,
        allowNull: false,
    },
    abbilities: {
      type: DataTypes.TEXT,
      allowNull: false,
      get() {
          const value = this.getDataValue('abbilities');
          return value ? JSON.parse(value) : [];
      },
      set(value) {
        this.setDataValue('abbilities', JSON.stringify(value));
      },
    },
    abbilities_ang: {
      type: DataTypes.TEXT,
      allowNull: false,
      get() {
          const value = this.getDataValue('abbilities_ang');
          return value ? JSON.parse(value) : [];
        },
        set(value) {
          this.setDataValue('abbilities_ang', JSON.stringify(value));
      },
    },
    number: {
      type: DataTypes.INTEGER,
      allowNull: false,
    },
  }, {
    tableName: 'characterwiki',
    timestamps: true,
  }
);
  
module.exports = Character_wiki;