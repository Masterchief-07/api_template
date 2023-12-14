package database

import (
	"gorm.io/gorm"
)

func Migrate(db *gorm.DB) error {
	err := db.AutoMigrate(&Example{})
	return err
}

type Example struct {
	// gorm.Model
	Id   int    `json:"id" gorm:"primaryKey, autoIncrement, not null"`
	Name string `json:"name" gorm:"unique:un_, not null"`
	// CreatedAt time.Time `json:"created_at" gorm:"autoCreateTime:milli"`
	// UpdateAt  time.Time `json:"update_at" gorm:"autoUpdateTime:milli"`
}
