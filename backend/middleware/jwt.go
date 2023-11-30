package middleware

import (
	"fmt"
	"os"

	"github.com/golang-jwt/jwt/v5"
)

type CustomClaims struct {
	UserId int `json:"user_id"`
	jwt.RegisteredClaims
}

func CreateToken(user_id int) (string, error) {

	key := os.Getenv("JWT_KEY")
	t := jwt.NewWithClaims(
		jwt.SigningMethodHS256,
		CustomClaims{
			UserId: user_id,
		},
	)
	s, err := t.SignedString(key)
	if err != nil {
		return "", err
	}
	return s, nil
}

func DecodeToken(token string) (*CustomClaims, error) {

	token_with_claim, err := jwt.Parse(token, func(tokenobj *jwt.Token) (interface{}, error) {
		if _, ok := tokenobj.Method.(*jwt.SigningMethodHMAC); !ok {
			return nil, fmt.Errorf("unexpected signing method: %v", tokenobj.Header["alg"])
		}
		return []byte(os.Getenv("JWT_KEY")), nil
	})
	if err != nil {
		return nil, err
	}
	claim, ok := token_with_claim.Claims.(*CustomClaims)
	if !ok {
		return nil, fmt.Errorf("error in parsing claim")
	}
	return claim, nil
}
