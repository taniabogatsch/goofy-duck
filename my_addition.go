package main

/*
void callback(void *info, void *in, void *out);
typedef void (*callback_t)(void *info, void *in, void *out);
*/
import "C"
import (
	"duckdb"
	"unsafe"
)

//export callback
func callback(info unsafe.Pointer, in unsafe.Pointer, out unsafe.Pointer) {
	var input duckdb.DataChunk
	input.Set(in)

	var output duckdb.Vector
	output.Set(out)

	size := duckdb.DataChunkGetSize(input)

	left := duckdb.DataChunkGetVector(input, 0)
	leftPtr := duckdb.VectorGetData(left)
	leftData := (*[1 << 30]uint64)(leftPtr)[:size:size]
	leftMask := duckdb.VectorGetValidity(left)

	right := duckdb.DataChunkGetVector(input, 1)
	rightPtr := duckdb.VectorGetData(right)
	rightData := (*[1 << 30]uint64)(rightPtr)[:size:size]
	rightMask := duckdb.VectorGetValidity(right)

	outPtr := duckdb.VectorGetData(output)
	outData := (*[1 << 30]uint64)(outPtr)[:size:size]
	duckdb.VectorEnsureValidityWritable(output)
	outMask := duckdb.VectorGetValidity(output)

	for i := uint64(0); i < size; i++ {
		if !duckdb.ValidityRowIsValid(leftMask, i) || !duckdb.ValidityRowIsValid(rightMask, i) {
			duckdb.ValiditySetRowInvalid(outMask, i)
			continue
		}

		outData[i] = leftData[i] + rightData[i]
	}
}

func registerMyAddition(conn duckdb.Connection, name string) duckdb.State {
	f := duckdb.CreateScalarFunction()
	duckdb.ScalarFunctionSetName(f, name)

	t := duckdb.CreateLogicalType(duckdb.TYPE_BIGINT)
	duckdb.ScalarFunctionAddParameter(f, t)
	duckdb.ScalarFunctionAddParameter(f, t)
	duckdb.ScalarFunctionSetReturnType(f, t)
	duckdb.DestroyLogicalType(&t)

	var cb duckdb.ScalarFunctionT
	cb.Set(unsafe.Pointer(C.callback_t(C.callback)))
	duckdb.ScalarFunctionSetFunction(f, cb)

	state := duckdb.RegisterScalarFunction(conn, f)
	duckdb.DestroyScalarFunction(&f)
	return state
}
