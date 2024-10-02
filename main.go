package main

/*
#include <stdlib.h>

// TODO: we do not need the functions in duckdb.h, and we need to add additional magic back into the generator script (ifdefs, etc.).
#include <duckdb.h>
#include <duckdb_extension.h>

typedef struct duckdb_extension_access _duckdb_extension_access;
typedef void (*set_error)(duckdb_extension_info info, const char *error);

static void _set_error(set_error f, duckdb_extension_info info, const char *error) {
	return f(info, error);
}

typedef duckdb_database *(*get_database)(duckdb_extension_info info);

static duckdb_database *_get_database(get_database f, duckdb_extension_info info) {
	return f(info);
}

typedef void *(*get_api)(duckdb_extension_info info, const char *version);

static void *_get_api(get_api f, duckdb_extension_info info, const char *version) {
	return f(info, version);
}
*/
import "C"
import (
	"fmt"
	"unsafe"
)

var api *C.duckdb_ext_api_v0

func setError(info C.duckdb_extension_info, access *C._duckdb_extension_access, msg string) {
	err := C.CString(msg)
	C._set_error(access.set_error, info, err)
	C.free(unsafe.Pointer(err))
}

func initAPI(minVersion string, info C.duckdb_extension_info, access *C._duckdb_extension_access) {
	version := C.CString(minVersion)
	api = (*C.duckdb_ext_api_v0)(C._get_api(access.get_api, info, version))
	C.free(unsafe.Pointer(version))
	if api == nil {
		setError(info, access, "failed to get the API")
		return
	}

	db := C._get_database(access.get_database, info)
	var con C.duckdb_connection
	if C._duckdb_connect(api.duckdb_connect, *db, &con) == C.DuckDBError {
		setError(info, access, "failed to connect to the database")
		return
	}
	C._duckdb_disconnect(api.duckdb_disconnect, &con)
	fmt.Println("extensions in Go are cool")
}

//export goofy_duck_init_c_api
func goofy_duck_init_c_api(info C.duckdb_extension_info, access *C._duckdb_extension_access) {
	initAPI("v0.0.1", info, access)
	// other init
}

func main() {
	// We need the main function.
	// It enables the CGO compiler to compile the package as a C shared library.
}
