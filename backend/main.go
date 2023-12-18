package main

import (
	"backend_template/database"
	"backend_template/views"
	"log"

	"github.com/gofiber/fiber/v2"
)

func main() {
	app := fiber.New()

	//init database
	database.InitMysqlDatabase()
	// database.InitSqliteDatabase()
	// database.Migrate(database.DB)

	//add views
	views.HelloRouter(app)
	views.ExampleRouter(app)

	log.Panic(app.Listen(":80"))
}
