package services

import (
	"backend_template/database"
	"backend_template/schemas"
	"fmt"

	"github.com/gofiber/fiber/v2"
	"github.com/gofiber/fiber/v2/log"
)

func GetAllExample(ctx *fiber.Ctx) error {
	examples := []database.Example{}
	database.DB.Find(&examples)
	response := schemas.Response{
		Status:  200,
		Message: "all examples",
		Data:    examples,
	}
	return ctx.Status(200).JSON(response)
}

func GetExample(ctx *fiber.Ctx) error {
	id := ctx.Params("id")
	example := database.Example{}
	if err := database.DB.First(&example, id).Error; err != nil {
		log.Error(err)
		return ctx.Status(404).JSON(
			schemas.Response{
				Status:  404,
				Message: fmt.Sprintf("example id %s is not found", id),
			},
		)
	}
	response := schemas.Response{
		Status:  200,
		Message: "example found",
		Data:    example,
	}
	return ctx.Status(200).JSON(response)
}
func PostExample(ctx *fiber.Ctx) error {
	example_schema := new(schemas.Example)
	if err := schemas.ParseJsonAndValidate(ctx, &example_schema); err != nil {
		return ctx.Status(fiber.StatusNotAcceptable).JSON(
			schemas.Response{
				Status:  fiber.StatusNotAcceptable,
				Message: "error on data",
				// Data:    err,
			},
		)
	}
	example := database.Example{
		Name: example_schema.Name,
	}
	if err := database.DB.Create(&example).Error; err != nil {
		log.Error(err)
		return ctx.Status(fiber.StatusNotAcceptable).JSON(
			schemas.Response{
				Status:  fiber.StatusNotAcceptable,
				Message: "unique constraint",
				// Data:    err,
			},
		)
	}
	return ctx.Status(fiber.StatusCreated).JSON(
		schemas.Response{
			Status:  fiber.StatusCreated,
			Message: "Example created",
			Data:    example,
		},
	)
}
func PatchExample(ctx *fiber.Ctx) error {
	id := ctx.Params("id")
	example_schema := new(schemas.Example)
	if err := schemas.ParseJsonAndValidate(ctx, &example_schema); err != nil {
		log.Error(err)
		return ctx.Status(fiber.StatusNotAcceptable).JSON(
			schemas.Response{
				Status:  fiber.StatusNotAcceptable,
				Message: "error on data",
				// Data:    err,
			},
		)
	}
	example := new(database.Example)
	if err := database.DB.First(&example, id).Error; err != nil {
		log.Error(err)
		return ctx.Status(404).JSON(
			schemas.Response{
				Status:  404,
				Message: fmt.Sprintf("example id %s not found", id),
			},
		)
	}

	example.Name = example_schema.Name
	if err := database.DB.Save(&example).Error; err != nil {
		log.Error(err)
		return ctx.Status(fiber.StatusConflict).JSON(
			schemas.Response{
				Status:  fiber.StatusConflict,
				Message: "unique constrain issue",
				// Data:    err,
			},
		)
	}

	return ctx.Status(200).JSON(
		schemas.Response{
			Status:  200,
			Message: fmt.Sprintf("example id %s updated", id),
			Data:    example,
		},
	)

}
func DeleteExample(ctx *fiber.Ctx) error {
	id := ctx.Params("id")
	example := new(database.Example)
	if err := database.DB.Delete(&example, id).Error; err != nil {
		log.Error(err)
		return ctx.Status(404).JSON(
			schemas.Response{
				Status:  404,
				Message: fmt.Sprintf("can't delete data at id %s", id),
			},
		)
	}
	return ctx.Status(200).JSON(
		schemas.Response{
			Status:  200,
			Message: fmt.Sprintf("example id %s deleted", id),
			Data:    example,
		},
	)
}
