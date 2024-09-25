package main

/*
#include <stdlib.h>

typedef struct {
} duckdb_ext_api_v0;

typedef struct _duckdb_connection {
	void *internal_ptr;
} * duckdb_connection;

typedef struct _duckdb_extension_info {
	void *internal_ptr;
} * duckdb_extension_info;

typedef struct _duckdb_database {
	void *internal_ptr;
} * duckdb_database;

typedef struct _duckdb_extension_access duckdb_extension_access;

struct _duckdb_extension_access {
	void (*set_error)(duckdb_extension_info info, const char *error);
	duckdb_database *(*get_database)(duckdb_extension_info info);
	void *(*get_api)(duckdb_extension_info info, const char *version);
};

typedef void (*set_error)(duckdb_extension_info info, const char *error);
typedef void *(*get_api)(duckdb_extension_info info, const char *version);

static void *invoke_get_api(get_api f, duckdb_extension_info info, const char *version) {
	return f(info, version);
}
static void *invoke_get_api(get_api f, duckdb_extension_info info, const char *version) {
	return f(info, version);
}
*/
import "C"
import (
	"fmt"
	"unsafe"
)

//export plant_init_c_api
func plant_init_c_api(info C.duckdb_extension_info, access *C.duckdb_extension_access) {
	version := C.CString("v0.0.1")
	api := (*C.duckdb_ext_api_v0)(C.invoke_get_api(access.get_api, info, version))
	C.free(unsafe.Pointer(version))

	if api == nil {
		return
	}

	fmt.Println("plants are cool")
}

func main() {
	// We need the main function.
	// It enables the CGO compiler to compile the package as a C shared library.
}
