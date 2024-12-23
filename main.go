package main

import "C"
import (
	"duckdb"
	"unsafe"
)

//export goofy_duck_init_c_api
func goofy_duck_init_c_api(info unsafe.Pointer, access unsafe.Pointer) bool {
	api, err := duckdb.Init("v1.2.0", info, access)
	if err != nil {
		return false
	}

	// TODO: Any additional extension load steps. For example:
	db := api.Database()
	var conn duckdb.Connection
	if state := duckdb.Connect(db, &conn); state == duckdb.STATE_ERROR {
		return false
	}
	registerMyAddition(conn, "my_addition")
	duckdb.Disconnect(&conn)
	return true
}

func main() {
	// We need the main function.
	// It enables the CGO compiler to compile the package as a C shared library.
}
