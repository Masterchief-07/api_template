package views

import (
	"backend_template/services"

	"github.com/gofiber/fiber/v2"
)

func ExampleRouter(api *fiber.App) {
	example_router := api.Group("/example")
	example_router.Get("/", services.GetAllExample)
	example_router.Post("/", services.PostExample)
	example_router.Get("/:id", services.GetExample)
	example_router.Patch("/:id", services.PatchExample)
	example_router.Delete("/:id", services.DeleteExample)
}
