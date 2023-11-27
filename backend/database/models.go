package database

type Example struct {
	Id   int    `json:"id" gorm:"type:INT(10) UNSIGNED NOT NULL AUTO_INCREMENT;primary_key`
	Name string `json:"sku"`
}
