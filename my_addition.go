package main

import "duckdb"

/*
void AddVariadicNumbersTogether(duckdb_function_info, duckdb_data_chunk input, duckdb_vector output) {
	// get the total number of rows in this chunk
	auto input_size = duckdb_data_chunk_get_size(input);

	// extract the input vectors
	auto column_count = duckdb_data_chunk_get_column_count(input);
	std::vector<duckdb_vector> inputs;
	std::vector<int64_t *> data_ptrs;
	std::vector<uint64_t *> validity_masks;

	auto result_data = (int64_t *)duckdb_vector_get_data(output);
	duckdb_vector_ensure_validity_writable(output);
	auto result_validity = duckdb_vector_get_validity(output);

	// early-out by setting each row to NULL
	if (column_count == 0) {
		for (idx_t row_idx = 0; row_idx < input_size; row_idx++) {
			duckdb_validity_set_row_invalid(result_validity, row_idx);
		}
		return;
	}

	// setup
	for (idx_t col_idx = 0; col_idx < column_count; col_idx++) {
		inputs.push_back(duckdb_data_chunk_get_vector(input, col_idx));
		auto data_ptr = (int64_t *)duckdb_vector_get_data(inputs.back());
		data_ptrs.push_back(data_ptr);
		auto validity_mask = duckdb_vector_get_validity(inputs.back());
		validity_masks.push_back(validity_mask);
	}

	// execution
	for (idx_t row_idx = 0; row_idx < input_size; row_idx++) {

		// validity check
		auto invalid = false;
		for (idx_t col_idx = 0; col_idx < column_count; col_idx++) {
			if (!duckdb_validity_row_is_valid(validity_masks[col_idx], row_idx)) {
				// not valid, set to NULL
				duckdb_validity_set_row_invalid(result_validity, row_idx);
				invalid = true;
				break;
			}
		}
		if (invalid) {
			continue;
		}

		result_data[row_idx] = 0;
		for (idx_t col_idx = 0; col_idx < column_count; col_idx++) {
			auto data = data_ptrs[col_idx][row_idx];
			result_data[row_idx] += data;
		}
	}
}

static duckdb_scalar_function CAPIGetScalarFunction(duckdb_connection connection, const char *name,
                                                    idx_t parameter_count = 2) {
	auto function = duckdb_create_scalar_function();
	duckdb_scalar_function_set_name(nullptr, name);
	duckdb_scalar_function_set_name(function, nullptr);
	duckdb_scalar_function_set_name(function, name);
	duckdb_scalar_function_set_name(function, name);

	// add a two bigint parameters
	auto type = duckdb_create_logical_type(DUCKDB_TYPE_BIGINT);
	duckdb_scalar_function_add_parameter(nullptr, type);
	duckdb_scalar_function_add_parameter(function, nullptr);
	for (idx_t idx = 0; idx < parameter_count; idx++) {
		duckdb_scalar_function_add_parameter(function, type);
	}

	// set the return type to bigint
	duckdb_scalar_function_set_return_type(nullptr, type);
	duckdb_scalar_function_set_return_type(function, nullptr);
	duckdb_scalar_function_set_return_type(function, type);
	duckdb_destroy_logical_type(&type);

	// set up the function
	duckdb_scalar_function_set_function(nullptr, AddVariadicNumbersTogether);
	duckdb_scalar_function_set_function(function, nullptr);
	duckdb_scalar_function_set_function(function, AddVariadicNumbersTogether);
	return function;
}
*/

func registerMyAddition(conn duckdb.Conn, name string) {
	//var state duckdb.State

}

/*
static void CAPIRegisterAddition(duckdb_connection connection, const char *name, duckdb_state expected_outcome) {
	duckdb_state status;

	// create a scalar function
	auto function = CAPIGetScalarFunction(connection, name);

	// register and cleanup
	status = duckdb_register_scalar_function(connection, function);
	REQUIRE(status == expected_outcome);

	duckdb_destroy_scalar_function(&function);
	duckdb_destroy_scalar_function(&function);
	duckdb_destroy_scalar_function(nullptr);
}

TEST_CASE("Test Scalar Functions C API", "[capi]") {
	CAPITester tester;
	duckdb::unique_ptr<CAPIResult> result;

	REQUIRE(tester.OpenDatabase(nullptr));
	CAPIRegisterAddition(tester.connection, "my_addition", DuckDBSuccess);
	// try to register it again - this should be an error
	CAPIRegisterAddition(tester.connection, "my_addition", DuckDBError);

	// now call it
	result = tester.Query("SELECT my_addition(40, 2)");
	REQUIRE_NO_FAIL(*result);
	REQUIRE(result->Fetch<int64_t>(0, 0) == 42);

	result = tester.Query("SELECT my_addition(40, NULL)");
	REQUIRE_NO_FAIL(*result);
	REQUIRE(result->IsNull(0, 0));

	result = tester.Query("SELECT my_addition(NULL, 2)");
	REQUIRE_NO_FAIL(*result);
	REQUIRE(result->IsNull(0, 0));

	// call it over a vector of values
	result = tester.Query("SELECT my_addition(1000000, i) FROM range(10000) t(i)");
	REQUIRE_NO_FAIL(*result);
	for (idx_t row = 0; row < 10000; row++) {
		REQUIRE(result->Fetch<int64_t>(0, row) == static_cast<int64_t>(1000000 + row));
	}
}
*/
