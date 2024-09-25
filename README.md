```
go build --buildmode=c-shared ./
python3 append_extension_metadata.py -l main -n plant -dv v0.0.1 -ev v0.0.1 -p osx_arm64
../duckdb/build/release/duckdb -unsigned 
 load './plant.duckdb_extension';
```