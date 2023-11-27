package main

import (
	"backend_template/services"

	"github.com/gofiber/fiber/v2"
)

func main() {
	app := fiber.New()

	// app.Get("/", func(c *fiber.Ctx) error {
	// 	return c.SendString("Hello, World!")
	// })
	app.Get("/", services.HelloWorld)
	app.Get("/:name", services.HelloCustom)

	app.Listen(":8000")
}
