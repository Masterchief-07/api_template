package views

import (
	"backend_template/services"

	"github.com/gofiber/fiber/v2"
)

func HelloRouter(api *fiber.App) {
	hello_router := api.Group("/hello")
	hello_router.Get("/", services.HelloWorld)
	hello_router.Get("/:name", services.HelloCustom)
}
