package database

import (
	"backend_template/config"

	"gorm.io/driver/mysql"
	"gorm.io/driver/sqlite"
	"gorm.io/gorm"
)

var DB *gorm.DB

func InitMysqlDatabase() {
	var err error
	DB, err = gorm.Open(mysql.Open(config.DATABASE_URL), &gorm.Config{})
	if err != nil {
		panic("can't connect to database")
	}
}

func InitSqliteDatabase() {
	database_url := "./example.db"
	var err error
	DB, err = gorm.Open(sqlite.Open(database_url), &gorm.Config{})
	if err != nil {
		panic("can't connect to database")
	}
}
