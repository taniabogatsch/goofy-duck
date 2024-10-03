package main

import "C"
import (
	"duckdb"
	"fmt"
	"unsafe"
)

//export goofy_duck_init_c_api
func goofy_duck_init_c_api(info unsafe.Pointer, access unsafe.Pointer) {
	api, err := duckdb.InitAPI("v0.0.1", info, access)
	if err != nil {
		return
	}

	// TODO: Any additional extension load steps. For example:
	db := api.DB()
	var conn duckdb.Conn
	if err = api.Connect(db, conn); err != nil {
		panic(err)
	}
	conn.Close()
	fmt.Println("load done")
	api.Close()
}

func main() {
	// We need the main function.
	// It enables the CGO compiler to compile the package as a C shared library.
}
