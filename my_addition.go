package main

/*
void callback(void *info, void *in, void *out);
typedef void (*callback_t)(void *info, void *in, void *out);
*/
import "C"
import (
	"duckdb"
	"fmt"
	"unsafe"
)

//export callback
func callback(info unsafe.Pointer, in unsafe.Pointer, out unsafe.Pointer) {
	var input duckdb.DataChunk
	input.Set(in)

	var output duckdb.Vector
	output.Set(out)

	version := api.LibraryVersion()
	fmt.Println(version)

	size := api.DataChunkGetSize(input)

	left := api.DataChunkGetVector(input, 0)
	leftPtr := api.VectorGetData(left)
	leftData := (*[1 << 30]uint64)(leftPtr)[:size:size]
	leftMask := api.VectorGetValidity(left)

	right := api.DataChunkGetVector(input, 1)
	rightPtr := api.VectorGetData(right)
	rightData := (*[1 << 30]uint64)(rightPtr)[:size:size]
	rightMask := api.VectorGetValidity(right)

	outPtr := api.VectorGetData(output)
	outData := (*[1 << 30]uint64)(outPtr)[:size:size]
	api.VectorEnsureValidityWritable(output)
	outMask := api.VectorGetValidity(output)

	for i := uint64(0); i < size; i++ {
		if !api.ValidityRowIsValid(leftMask, i) || !api.ValidityRowIsValid(rightMask, i) {
			api.ValiditySetRowInvalid(outMask, i)
			continue
		}

		outData[i] = leftData[i] + rightData[i]
	}
}

func registerMyAddition(conn duckdb.Connection, name string) duckdb.State {
	f := api.CreateScalarFunction()
	api.ScalarFunctionSetName(f, name)

	t := api.CreateLogicalType(duckdb.TYPE_BIGINT)
	api.ScalarFunctionAddParameter(f, t)
	api.ScalarFunctionAddParameter(f, t)
	api.ScalarFunctionSetReturnType(f, t)
	api.DestroyLogicalType(&t)

	var cb duckdb.ScalarFunctionT
	cb.Set(unsafe.Pointer(C.callback_t(C.callback)))
	api.ScalarFunctionSetFunction(f, cb)

	state := api.RegisterScalarFunction(conn, f)
	api.DestroyScalarFunction(&f)
	return state
}
