package schemas

import (
	"github.com/gofiber/fiber/v2"
)

func ParseJson[T any](ctx *fiber.Ctx, data *T) error {
	if err := ctx.BodyParser(data); err != nil {
		return err
	}
	return nil
}

func Validate[T any](data *T) error {

	return nil
}

func ParseJsonAndValidate[T any](ctx *fiber.Ctx, data *T) error {

	if err := ParseJson[T](ctx, data); err != nil {
		return err
	}
	if err := Validate[T](data); err != nil {
		return err
	}
	return nil
}
