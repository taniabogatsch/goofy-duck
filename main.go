package main

/*
#include <stdlib.h>
#include <duckdb.h>
#include <extension.h>
*/
import "C"
import (
	"fmt"
	"unsafe"
)

//export goofy_duck_init_c_api
func goofy_duck_init_c_api(info C.duckdb_extension_info, access *C.duckdb_extension_access) {
	version := C.CString("v0.0.1")
	api := (*C.duckdb_ext_api_v0)(C.invoke_get_api(access.get_api, info, version))
	C.free(unsafe.Pointer(version))

	if api == nil {
		return
	}

	fmt.Println("extensions in Go are cool")
}

func main() {
	// We need the main function.
	// It enables the CGO compiler to compile the package as a C shared library.
}
