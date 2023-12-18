package services

import (
	"fmt"

	"github.com/gofiber/fiber/v2"
)

func HelloWorld(ctx *fiber.Ctx) error {
	return ctx.Status(200).JSON(fiber.Map{
		"status":  200,
		"message": "hello world",
	})
}

func HelloCustom(ctx *fiber.Ctx) error {
	name := ctx.Params("name")

	return ctx.Status(200).JSON(fiber.Map{
		"status":  200,
		"message": fmt.Sprintf("hello %s", name),
	})

}
