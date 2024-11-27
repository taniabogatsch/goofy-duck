### Repo Information

At this stage, this repo (goofy-duck) is a proof of concept for writing Go duckdb extensions using the C API instead of the C++ interface. Without the need to write any C code or cgo. I am not entirely there yet, as seen by the C code here: https://github.com/taniabogatsch/goofy-duck/blob/d0737d3097e8baa9d982dc97c8dd0d2047337606/my_addition.go#L4

[duckdb-go-api](https://github.com/taniabogatsch/duckdb-go-api) is a lightweight Go wrapper for duckdb's C API functions. In its current state, it is far from any official wrapper, and I mainly use it for the goofy-duck proof of concept.

It differs from go-duckdb because it does not implement Go's SQL driver interface. It only wraps the C API functions in Go functions. Conceptionally, this means that (at some more distant point in time) go-duckdb could use these wrapper functions to replace most of its C code. However, they are not a substitute for each other.

#### Some copy-pasta for development.
```
go build --buildmode=c-shared ./
python3 append_extension_metadata.py -l main -n goofy_duck -dv v0.0.1 -ev v0.0.1 -p osx_arm64
../duckdb/build/release/duckdb -unsigned 
 load './goofy_duck.duckdb_extension';
```

`append_extension_metadata.py` is copied over from the duckdb repo.
