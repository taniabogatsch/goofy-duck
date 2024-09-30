```
go build --buildmode=c-shared ./
python3 append_extension_metadata.py -l main -n goofy_duck -dv v0.0.1 -ev v0.0.1 -p osx_arm64
../duckdb/build/release/duckdb -unsigned 
 load './goofy_duck.duckdb_extension';
```

`append_extension_metadata.py` is copied over from the duckdb repo.
`generate_go_api.py` is adapted from `scripts/generate_c_api.py` (duckdb repo).
