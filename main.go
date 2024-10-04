package main

import "C"
import (
	"duckdb"
	"fmt"
	"unsafe"
)

var api duckdb.API

//export goofy_duck_init_c_api
func goofy_duck_init_c_api(info unsafe.Pointer, access unsafe.Pointer) {
	var err error
	api, err = duckdb.Init("v0.0.1", info, access)
	if err != nil {
		return
	}

	// TODO: Any additional extension load steps. For example:
	db := api.Database()
	var conn duckdb.Connection
	if state := api.Connect(db, &conn); state == duckdb.STATE_ERROR {
		return
	}
	registerMyAddition(conn, "my_addition")
	api.Disconnect(&conn)

	fmt.Println("load done")
}

func main() {
	// We need the main function.
	// It enables the CGO compiler to compile the package as a C shared library.
}
