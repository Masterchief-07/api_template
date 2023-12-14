package config

import "os"

var DATABASE_URL = os.Getenv("DATABASE_URL")
var REDIS_URL = os.Getenv("REDIS_URL")
var JWT_KEY = os.Getenv("JWT_KEY")
