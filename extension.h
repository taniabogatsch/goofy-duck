typedef struct {
	// v0.0.1
	duckdb_state (*duckdb_open)(const char *path, duckdb_database *out_database);
	duckdb_state (*duckdb_open_ext)(const char *path, duckdb_database *out_database, duckdb_config config,
	                                char **out_error);
	void (*duckdb_close)(duckdb_database *database);
	duckdb_state (*duckdb_connect)(duckdb_database database, duckdb_connection *out_connection);
	void (*duckdb_interrupt)(duckdb_connection connection);
	duckdb_query_progress_type (*duckdb_query_progress)(duckdb_connection connection);
	void (*duckdb_disconnect)(duckdb_connection *connection);
	const char *(*duckdb_library_version)();
	duckdb_state (*duckdb_create_config)(duckdb_config *out_config);
	size_t (*duckdb_config_count)();
	duckdb_state (*duckdb_get_config_flag)(size_t index, const char **out_name, const char **out_description);
	duckdb_state (*duckdb_set_config)(duckdb_config config, const char *name, const char *option);
	void (*duckdb_destroy_config)(duckdb_config *config);
	duckdb_state (*duckdb_query)(duckdb_connection connection, const char *query, duckdb_result *out_result);
	void (*duckdb_destroy_result)(duckdb_result *result);
	const char *(*duckdb_column_name)(duckdb_result *result, idx_t col);
	duckdb_type (*duckdb_column_type)(duckdb_result *result, idx_t col);
	duckdb_statement_type (*duckdb_result_statement_type)(duckdb_result result);
	duckdb_logical_type (*duckdb_column_logical_type)(duckdb_result *result, idx_t col);
	idx_t (*duckdb_column_count)(duckdb_result *result);
	idx_t (*duckdb_rows_changed)(duckdb_result *result);
	const char *(*duckdb_result_error)(duckdb_result *result);
	void *(*duckdb_malloc)(size_t size);
	void (*duckdb_free)(void *ptr);
	idx_t (*duckdb_vector_size)();
	bool (*duckdb_string_is_inlined)(duckdb_string_t string);
	duckdb_date_struct (*duckdb_from_date)(duckdb_date date);
	duckdb_date (*duckdb_to_date)(duckdb_date_struct date);
	bool (*duckdb_is_finite_date)(duckdb_date date);
	duckdb_time_struct (*duckdb_from_time)(duckdb_time time);
	duckdb_time_tz (*duckdb_create_time_tz)(int64_t micros, int32_t offset);
	duckdb_time_tz_struct (*duckdb_from_time_tz)(duckdb_time_tz micros);
	duckdb_time (*duckdb_to_time)(duckdb_time_struct time);
	duckdb_timestamp_struct (*duckdb_from_timestamp)(duckdb_timestamp ts);
	duckdb_timestamp (*duckdb_to_timestamp)(duckdb_timestamp_struct ts);
	bool (*duckdb_is_finite_timestamp)(duckdb_timestamp ts);
	double (*duckdb_hugeint_to_double)(duckdb_hugeint val);
	duckdb_hugeint (*duckdb_double_to_hugeint)(double val);
	double (*duckdb_uhugeint_to_double)(duckdb_uhugeint val);
	duckdb_uhugeint (*duckdb_double_to_uhugeint)(double val);
	duckdb_decimal (*duckdb_double_to_decimal)(double val, uint8_t width, uint8_t scale);
	double (*duckdb_decimal_to_double)(duckdb_decimal val);
	duckdb_state (*duckdb_prepare)(duckdb_connection connection, const char *query,
	                               duckdb_prepared_statement *out_prepared_statement);
	void (*duckdb_destroy_prepare)(duckdb_prepared_statement *prepared_statement);
	const char *(*duckdb_prepare_error)(duckdb_prepared_statement prepared_statement);
	idx_t (*duckdb_nparams)(duckdb_prepared_statement prepared_statement);
	const char *(*duckdb_parameter_name)(duckdb_prepared_statement prepared_statement, idx_t index);
	duckdb_type (*duckdb_param_type)(duckdb_prepared_statement prepared_statement, idx_t param_idx);
	duckdb_state (*duckdb_clear_bindings)(duckdb_prepared_statement prepared_statement);
	duckdb_statement_type (*duckdb_prepared_statement_type)(duckdb_prepared_statement statement);
	duckdb_state (*duckdb_bind_value)(duckdb_prepared_statement prepared_statement, idx_t param_idx, duckdb_value val);
	duckdb_state (*duckdb_bind_parameter_index)(duckdb_prepared_statement prepared_statement, idx_t *param_idx_out,
	                                            const char *name);
	duckdb_state (*duckdb_bind_boolean)(duckdb_prepared_statement prepared_statement, idx_t param_idx, bool val);
	duckdb_state (*duckdb_bind_int8)(duckdb_prepared_statement prepared_statement, idx_t param_idx, int8_t val);
	duckdb_state (*duckdb_bind_int16)(duckdb_prepared_statement prepared_statement, idx_t param_idx, int16_t val);
	duckdb_state (*duckdb_bind_int32)(duckdb_prepared_statement prepared_statement, idx_t param_idx, int32_t val);
	duckdb_state (*duckdb_bind_int64)(duckdb_prepared_statement prepared_statement, idx_t param_idx, int64_t val);
	duckdb_state (*duckdb_bind_hugeint)(duckdb_prepared_statement prepared_statement, idx_t param_idx,
	                                    duckdb_hugeint val);
	duckdb_state (*duckdb_bind_uhugeint)(duckdb_prepared_statement prepared_statement, idx_t param_idx,
	                                     duckdb_uhugeint val);
	duckdb_state (*duckdb_bind_decimal)(duckdb_prepared_statement prepared_statement, idx_t param_idx,
	                                    duckdb_decimal val);
	duckdb_state (*duckdb_bind_uint8)(duckdb_prepared_statement prepared_statement, idx_t param_idx, uint8_t val);
	duckdb_state (*duckdb_bind_uint16)(duckdb_prepared_statement prepared_statement, idx_t param_idx, uint16_t val);
	duckdb_state (*duckdb_bind_uint32)(duckdb_prepared_statement prepared_statement, idx_t param_idx, uint32_t val);
	duckdb_state (*duckdb_bind_uint64)(duckdb_prepared_statement prepared_statement, idx_t param_idx, uint64_t val);
	duckdb_state (*duckdb_bind_float)(duckdb_prepared_statement prepared_statement, idx_t param_idx, float val);
	duckdb_state (*duckdb_bind_double)(duckdb_prepared_statement prepared_statement, idx_t param_idx, double val);
	duckdb_state (*duckdb_bind_date)(duckdb_prepared_statement prepared_statement, idx_t param_idx, duckdb_date val);
	duckdb_state (*duckdb_bind_time)(duckdb_prepared_statement prepared_statement, idx_t param_idx, duckdb_time val);
	duckdb_state (*duckdb_bind_timestamp)(duckdb_prepared_statement prepared_statement, idx_t param_idx,
	                                      duckdb_timestamp val);
	duckdb_state (*duckdb_bind_timestamp_tz)(duckdb_prepared_statement prepared_statement, idx_t param_idx,
	                                         duckdb_timestamp val);
	duckdb_state (*duckdb_bind_interval)(duckdb_prepared_statement prepared_statement, idx_t param_idx,
	                                     duckdb_interval val);
	duckdb_state (*duckdb_bind_varchar)(duckdb_prepared_statement prepared_statement, idx_t param_idx, const char *val);
	duckdb_state (*duckdb_bind_varchar_length)(duckdb_prepared_statement prepared_statement, idx_t param_idx,
	                                           const char *val, idx_t length);
	duckdb_state (*duckdb_bind_blob)(duckdb_prepared_statement prepared_statement, idx_t param_idx, const void *data,
	                                 idx_t length);
	duckdb_state (*duckdb_bind_null)(duckdb_prepared_statement prepared_statement, idx_t param_idx);
	duckdb_state (*duckdb_execute_prepared)(duckdb_prepared_statement prepared_statement, duckdb_result *out_result);
	idx_t (*duckdb_extract_statements)(duckdb_connection connection, const char *query,
	                                   duckdb_extracted_statements *out_extracted_statements);
	duckdb_state (*duckdb_prepare_extracted_statement)(duckdb_connection connection,
	                                                   duckdb_extracted_statements extracted_statements, idx_t index,
	                                                   duckdb_prepared_statement *out_prepared_statement);
	const char *(*duckdb_extract_statements_error)(duckdb_extracted_statements extracted_statements);
	void (*duckdb_destroy_extracted)(duckdb_extracted_statements *extracted_statements);
	duckdb_state (*duckdb_pending_prepared)(duckdb_prepared_statement prepared_statement,
	                                        duckdb_pending_result *out_result);
	void (*duckdb_destroy_pending)(duckdb_pending_result *pending_result);
	const char *(*duckdb_pending_error)(duckdb_pending_result pending_result);
	duckdb_pending_state (*duckdb_pending_execute_task)(duckdb_pending_result pending_result);
	duckdb_pending_state (*duckdb_pending_execute_check_state)(duckdb_pending_result pending_result);
	duckdb_state (*duckdb_execute_pending)(duckdb_pending_result pending_result, duckdb_result *out_result);
	bool (*duckdb_pending_execution_is_finished)(duckdb_pending_state pending_state);
	void (*duckdb_destroy_value)(duckdb_value *value);
	duckdb_value (*duckdb_create_varchar)(const char *text);
	duckdb_value (*duckdb_create_varchar_length)(const char *text, idx_t length);
	duckdb_value (*duckdb_create_int64)(int64_t val);
	duckdb_value (*duckdb_create_struct_value)(duckdb_logical_type type, duckdb_value *values);
	duckdb_value (*duckdb_create_list_value)(duckdb_logical_type type, duckdb_value *values, idx_t value_count);
	duckdb_value (*duckdb_create_array_value)(duckdb_logical_type type, duckdb_value *values, idx_t value_count);
	char *(*duckdb_get_varchar)(duckdb_value value);
	int64_t (*duckdb_get_int64)(duckdb_value val);
	duckdb_logical_type (*duckdb_create_logical_type)(duckdb_type type);
	char *(*duckdb_logical_type_get_alias)(duckdb_logical_type type);
	duckdb_logical_type (*duckdb_create_list_type)(duckdb_logical_type type);
	duckdb_logical_type (*duckdb_create_array_type)(duckdb_logical_type type, idx_t array_size);
	duckdb_logical_type (*duckdb_create_map_type)(duckdb_logical_type key_type, duckdb_logical_type value_type);
	duckdb_logical_type (*duckdb_create_union_type)(duckdb_logical_type *member_types, const char **member_names,
	                                                idx_t member_count);
	duckdb_logical_type (*duckdb_create_struct_type)(duckdb_logical_type *member_types, const char **member_names,
	                                                 idx_t member_count);
	duckdb_logical_type (*duckdb_create_enum_type)(const char **member_names, idx_t member_count);
	duckdb_logical_type (*duckdb_create_decimal_type)(uint8_t width, uint8_t scale);
	duckdb_type (*duckdb_get_type_id)(duckdb_logical_type type);
	uint8_t (*duckdb_decimal_width)(duckdb_logical_type type);
	uint8_t (*duckdb_decimal_scale)(duckdb_logical_type type);
	duckdb_type (*duckdb_decimal_internal_type)(duckdb_logical_type type);
	duckdb_type (*duckdb_enum_internal_type)(duckdb_logical_type type);
	uint32_t (*duckdb_enum_dictionary_size)(duckdb_logical_type type);
	char *(*duckdb_enum_dictionary_value)(duckdb_logical_type type, idx_t index);
	duckdb_logical_type (*duckdb_list_type_child_type)(duckdb_logical_type type);
	duckdb_logical_type (*duckdb_array_type_child_type)(duckdb_logical_type type);
	idx_t (*duckdb_array_type_array_size)(duckdb_logical_type type);
	duckdb_logical_type (*duckdb_map_type_key_type)(duckdb_logical_type type);
	duckdb_logical_type (*duckdb_map_type_value_type)(duckdb_logical_type type);
	idx_t (*duckdb_struct_type_child_count)(duckdb_logical_type type);
	char *(*duckdb_struct_type_child_name)(duckdb_logical_type type, idx_t index);
	duckdb_logical_type (*duckdb_struct_type_child_type)(duckdb_logical_type type, idx_t index);
	idx_t (*duckdb_union_type_member_count)(duckdb_logical_type type);
	char *(*duckdb_union_type_member_name)(duckdb_logical_type type, idx_t index);
	duckdb_logical_type (*duckdb_union_type_member_type)(duckdb_logical_type type, idx_t index);
	void (*duckdb_destroy_logical_type)(duckdb_logical_type *type);
	duckdb_data_chunk (*duckdb_fetch_chunk)(duckdb_result result);
	duckdb_data_chunk (*duckdb_create_data_chunk)(duckdb_logical_type *types, idx_t column_count);
	void (*duckdb_destroy_data_chunk)(duckdb_data_chunk *chunk);
	void (*duckdb_data_chunk_reset)(duckdb_data_chunk chunk);
	idx_t (*duckdb_data_chunk_get_column_count)(duckdb_data_chunk chunk);
	duckdb_vector (*duckdb_data_chunk_get_vector)(duckdb_data_chunk chunk, idx_t col_idx);
	idx_t (*duckdb_data_chunk_get_size)(duckdb_data_chunk chunk);
	void (*duckdb_data_chunk_set_size)(duckdb_data_chunk chunk, idx_t size);
	duckdb_logical_type (*duckdb_vector_get_column_type)(duckdb_vector vector);
	void *(*duckdb_vector_get_data)(duckdb_vector vector);
	uint64_t *(*duckdb_vector_get_validity)(duckdb_vector vector);
	void (*duckdb_vector_ensure_validity_writable)(duckdb_vector vector);
	void (*duckdb_vector_assign_string_element)(duckdb_vector vector, idx_t index, const char *str);
	void (*duckdb_vector_assign_string_element_len)(duckdb_vector vector, idx_t index, const char *str, idx_t str_len);
	duckdb_vector (*duckdb_list_vector_get_child)(duckdb_vector vector);
	idx_t (*duckdb_list_vector_get_size)(duckdb_vector vector);
	duckdb_state (*duckdb_list_vector_set_size)(duckdb_vector vector, idx_t size);
	duckdb_state (*duckdb_list_vector_reserve)(duckdb_vector vector, idx_t required_capacity);
	duckdb_vector (*duckdb_struct_vector_get_child)(duckdb_vector vector, idx_t index);
	duckdb_vector (*duckdb_array_vector_get_child)(duckdb_vector vector);
	bool (*duckdb_validity_row_is_valid)(uint64_t *validity, idx_t row);
	void (*duckdb_validity_set_row_validity)(uint64_t *validity, idx_t row, bool valid);
	void (*duckdb_validity_set_row_invalid)(uint64_t *validity, idx_t row);
	void (*duckdb_validity_set_row_valid)(uint64_t *validity, idx_t row);
	duckdb_scalar_function (*duckdb_create_scalar_function)();
	void (*duckdb_destroy_scalar_function)(duckdb_scalar_function *scalar_function);
	void (*duckdb_scalar_function_set_name)(duckdb_scalar_function scalar_function, const char *name);
	void (*duckdb_scalar_function_add_parameter)(duckdb_scalar_function scalar_function, duckdb_logical_type type);
	void (*duckdb_scalar_function_set_return_type)(duckdb_scalar_function scalar_function, duckdb_logical_type type);
	void (*duckdb_scalar_function_set_extra_info)(duckdb_scalar_function scalar_function, void *extra_info,
	                                              duckdb_delete_callback_t destroy);
	void (*duckdb_scalar_function_set_function)(duckdb_scalar_function scalar_function,
	                                            duckdb_scalar_function_t function);
	duckdb_state (*duckdb_register_scalar_function)(duckdb_connection con, duckdb_scalar_function scalar_function);
	duckdb_table_function (*duckdb_create_table_function)();
	void (*duckdb_destroy_table_function)(duckdb_table_function *table_function);
	void (*duckdb_table_function_set_name)(duckdb_table_function table_function, const char *name);
	void (*duckdb_table_function_add_parameter)(duckdb_table_function table_function, duckdb_logical_type type);
	void (*duckdb_table_function_add_named_parameter)(duckdb_table_function table_function, const char *name,
	                                                  duckdb_logical_type type);
	void (*duckdb_table_function_set_extra_info)(duckdb_table_function table_function, void *extra_info,
	                                             duckdb_delete_callback_t destroy);
	void (*duckdb_table_function_set_bind)(duckdb_table_function table_function, duckdb_table_function_bind_t bind);
	void (*duckdb_table_function_set_init)(duckdb_table_function table_function, duckdb_table_function_init_t init);
	void (*duckdb_table_function_set_local_init)(duckdb_table_function table_function,
	                                             duckdb_table_function_init_t init);
	void (*duckdb_table_function_set_function)(duckdb_table_function table_function, duckdb_table_function_t function);
	void (*duckdb_table_function_supports_projection_pushdown)(duckdb_table_function table_function, bool pushdown);
	duckdb_state (*duckdb_register_table_function)(duckdb_connection con, duckdb_table_function function);
	void *(*duckdb_bind_get_extra_info)(duckdb_bind_info info);
	void (*duckdb_bind_add_result_column)(duckdb_bind_info info, const char *name, duckdb_logical_type type);
	idx_t (*duckdb_bind_get_parameter_count)(duckdb_bind_info info);
	duckdb_value (*duckdb_bind_get_parameter)(duckdb_bind_info info, idx_t index);
	duckdb_value (*duckdb_bind_get_named_parameter)(duckdb_bind_info info, const char *name);
	void (*duckdb_bind_set_bind_data)(duckdb_bind_info info, void *bind_data, duckdb_delete_callback_t destroy);
	void (*duckdb_bind_set_cardinality)(duckdb_bind_info info, idx_t cardinality, bool is_exact);
	void (*duckdb_bind_set_error)(duckdb_bind_info info, const char *error);
	void *(*duckdb_init_get_extra_info)(duckdb_init_info info);
	void *(*duckdb_init_get_bind_data)(duckdb_init_info info);
	void (*duckdb_init_set_init_data)(duckdb_init_info info, void *init_data, duckdb_delete_callback_t destroy);
	idx_t (*duckdb_init_get_column_count)(duckdb_init_info info);
	idx_t (*duckdb_init_get_column_index)(duckdb_init_info info, idx_t column_index);
	void (*duckdb_init_set_max_threads)(duckdb_init_info info, idx_t max_threads);
	void (*duckdb_init_set_error)(duckdb_init_info info, const char *error);
	void *(*duckdb_function_get_extra_info)(duckdb_function_info info);
	void *(*duckdb_function_get_bind_data)(duckdb_function_info info);
	void *(*duckdb_function_get_init_data)(duckdb_function_info info);
	void *(*duckdb_function_get_local_init_data)(duckdb_function_info info);
	void (*duckdb_function_set_error)(duckdb_function_info info, const char *error);
	void (*duckdb_add_replacement_scan)(duckdb_database db, duckdb_replacement_callback_t replacement, void *extra_data,
	                                    duckdb_delete_callback_t delete_callback);
	void (*duckdb_replacement_scan_set_function_name)(duckdb_replacement_scan_info info, const char *function_name);
	void (*duckdb_replacement_scan_add_parameter)(duckdb_replacement_scan_info info, duckdb_value parameter);
	void (*duckdb_replacement_scan_set_error)(duckdb_replacement_scan_info info, const char *error);
	duckdb_state (*duckdb_appender_create)(duckdb_connection connection, const char *schema, const char *table,
	                                       duckdb_appender *out_appender);
	idx_t (*duckdb_appender_column_count)(duckdb_appender appender);
	duckdb_logical_type (*duckdb_appender_column_type)(duckdb_appender appender, idx_t col_idx);
	const char *(*duckdb_appender_error)(duckdb_appender appender);
	duckdb_state (*duckdb_appender_flush)(duckdb_appender appender);
	duckdb_state (*duckdb_appender_close)(duckdb_appender appender);
	duckdb_state (*duckdb_appender_destroy)(duckdb_appender *appender);
	duckdb_state (*duckdb_appender_begin_row)(duckdb_appender appender);
	duckdb_state (*duckdb_appender_end_row)(duckdb_appender appender);
	duckdb_state (*duckdb_append_default)(duckdb_appender appender);
	duckdb_state (*duckdb_append_bool)(duckdb_appender appender, bool value);
	duckdb_state (*duckdb_append_int8)(duckdb_appender appender, int8_t value);
	duckdb_state (*duckdb_append_int16)(duckdb_appender appender, int16_t value);
	duckdb_state (*duckdb_append_int32)(duckdb_appender appender, int32_t value);
	duckdb_state (*duckdb_append_int64)(duckdb_appender appender, int64_t value);
	duckdb_state (*duckdb_append_hugeint)(duckdb_appender appender, duckdb_hugeint value);
	duckdb_state (*duckdb_append_uint8)(duckdb_appender appender, uint8_t value);
	duckdb_state (*duckdb_append_uint16)(duckdb_appender appender, uint16_t value);
	duckdb_state (*duckdb_append_uint32)(duckdb_appender appender, uint32_t value);
	duckdb_state (*duckdb_append_uint64)(duckdb_appender appender, uint64_t value);
	duckdb_state (*duckdb_append_uhugeint)(duckdb_appender appender, duckdb_uhugeint value);
	duckdb_state (*duckdb_append_float)(duckdb_appender appender, float value);
	duckdb_state (*duckdb_append_double)(duckdb_appender appender, double value);
	duckdb_state (*duckdb_append_date)(duckdb_appender appender, duckdb_date value);
	duckdb_state (*duckdb_append_time)(duckdb_appender appender, duckdb_time value);
	duckdb_state (*duckdb_append_timestamp)(duckdb_appender appender, duckdb_timestamp value);
	duckdb_state (*duckdb_append_interval)(duckdb_appender appender, duckdb_interval value);
	duckdb_state (*duckdb_append_varchar)(duckdb_appender appender, const char *val);
	duckdb_state (*duckdb_append_varchar_length)(duckdb_appender appender, const char *val, idx_t length);
	duckdb_state (*duckdb_append_blob)(duckdb_appender appender, const void *data, idx_t length);
	duckdb_state (*duckdb_append_null)(duckdb_appender appender);
	duckdb_state (*duckdb_append_data_chunk)(duckdb_appender appender, duckdb_data_chunk chunk);
	void (*duckdb_execute_tasks)(duckdb_database database, idx_t max_tasks);
	duckdb_task_state (*duckdb_create_task_state)(duckdb_database database);
	void (*duckdb_execute_tasks_state)(duckdb_task_state state);
	idx_t (*duckdb_execute_n_tasks_state)(duckdb_task_state state, idx_t max_tasks);
	void (*duckdb_finish_execution)(duckdb_task_state state);
	bool (*duckdb_task_state_is_finished)(duckdb_task_state state);
	void (*duckdb_destroy_task_state)(duckdb_task_state state);
	bool (*duckdb_execution_is_finished)(duckdb_connection con);
	duckdb_profiling_info (*duckdb_get_profiling_info)(duckdb_connection connection);
	duckdb_value (*duckdb_profiling_info_get_value)(duckdb_profiling_info info, const char *key);
	idx_t (*duckdb_profiling_info_get_child_count)(duckdb_profiling_info info);
	duckdb_profiling_info (*duckdb_profiling_info_get_child)(duckdb_profiling_info info, idx_t index);
	duckdb_value (*duckdb_profiling_info_get_metrics)(duckdb_profiling_info info);
	void (*duckdb_scalar_function_set_varargs)(duckdb_scalar_function scalar_function, duckdb_logical_type type);
	void (*duckdb_scalar_function_set_special_handling)(duckdb_scalar_function scalar_function);
	void (*duckdb_scalar_function_set_volatile)(duckdb_scalar_function scalar_function);
	void *(*duckdb_scalar_function_get_extra_info)(duckdb_function_info info);
	void (*duckdb_scalar_function_set_error)(duckdb_function_info info, const char *error);
	duckdb_state (*duckdb_table_description_create)(duckdb_connection connection, const char *schema, const char *table,
	                                                duckdb_table_description *out);
	void (*duckdb_table_description_destroy)(duckdb_table_description *table_description);
	const char *(*duckdb_table_description_error)(duckdb_table_description table_description);
	duckdb_error_type (*duckdb_result_error_type)(duckdb_result *result);
	uint32_t (*duckdb_string_t_length)(duckdb_string_t string);
	const char *(*duckdb_string_t_data)(duckdb_string_t *string);
	duckdb_value (*duckdb_create_bool)(bool input);
	duckdb_value (*duckdb_create_int8)(int8_t input);
	duckdb_value (*duckdb_create_uint8)(uint8_t input);
	duckdb_value (*duckdb_create_int16)(int16_t input);
	duckdb_value (*duckdb_create_uint16)(uint16_t input);
	duckdb_value (*duckdb_create_int32)(int32_t input);
	duckdb_value (*duckdb_create_uint32)(uint32_t input);
	duckdb_value (*duckdb_create_uint64)(uint64_t input);
	duckdb_value (*duckdb_create_hugeint)(duckdb_hugeint input);
	duckdb_value (*duckdb_create_uhugeint)(duckdb_uhugeint input);
	duckdb_value (*duckdb_create_float)(float input);
	duckdb_value (*duckdb_create_double)(double input);
	duckdb_value (*duckdb_create_date)(duckdb_date input);
	duckdb_value (*duckdb_create_time)(duckdb_time input);
	duckdb_value (*duckdb_create_time_tz_value)(duckdb_time_tz value);
	duckdb_value (*duckdb_create_timestamp)(duckdb_timestamp input);
	duckdb_value (*duckdb_create_interval)(duckdb_interval input);
	duckdb_value (*duckdb_create_blob)(const uint8_t *data, idx_t length);
	bool (*duckdb_get_bool)(duckdb_value val);
	int8_t (*duckdb_get_int8)(duckdb_value val);
	uint8_t (*duckdb_get_uint8)(duckdb_value val);
	int16_t (*duckdb_get_int16)(duckdb_value val);
	uint16_t (*duckdb_get_uint16)(duckdb_value val);
	int32_t (*duckdb_get_int32)(duckdb_value val);
	uint32_t (*duckdb_get_uint32)(duckdb_value val);
	uint64_t (*duckdb_get_uint64)(duckdb_value val);
	duckdb_hugeint (*duckdb_get_hugeint)(duckdb_value val);
	duckdb_uhugeint (*duckdb_get_uhugeint)(duckdb_value val);
	float (*duckdb_get_float)(duckdb_value val);
	double (*duckdb_get_double)(duckdb_value val);
	duckdb_date (*duckdb_get_date)(duckdb_value val);
	duckdb_time (*duckdb_get_time)(duckdb_value val);
	duckdb_time_tz (*duckdb_get_time_tz)(duckdb_value val);
	duckdb_timestamp (*duckdb_get_timestamp)(duckdb_value val);
	duckdb_interval (*duckdb_get_interval)(duckdb_value val);
	duckdb_logical_type (*duckdb_get_value_type)(duckdb_value val);
	duckdb_blob (*duckdb_get_blob)(duckdb_value val);
	duckdb_scalar_function_set (*duckdb_create_scalar_function_set)(const char *name);
	void (*duckdb_destroy_scalar_function_set)(duckdb_scalar_function_set *scalar_function_set);
	duckdb_state (*duckdb_add_scalar_function_to_set)(duckdb_scalar_function_set set, duckdb_scalar_function function);
	duckdb_state (*duckdb_register_scalar_function_set)(duckdb_connection con, duckdb_scalar_function_set set);
	duckdb_aggregate_function_set (*duckdb_create_aggregate_function_set)(const char *name);
	void (*duckdb_destroy_aggregate_function_set)(duckdb_aggregate_function_set *aggregate_function_set);
	duckdb_state (*duckdb_add_aggregate_function_to_set)(duckdb_aggregate_function_set set,
	                                                     duckdb_aggregate_function function);
	duckdb_state (*duckdb_register_aggregate_function_set)(duckdb_connection con, duckdb_aggregate_function_set set);
	idx_t (*duckdb_get_map_size)(duckdb_value value);
	duckdb_value (*duckdb_get_map_key)(duckdb_value value, idx_t index);
	duckdb_value (*duckdb_get_map_value)(duckdb_value value, idx_t index);
	duckdb_aggregate_function (*duckdb_create_aggregate_function)();
	void (*duckdb_destroy_aggregate_function)(duckdb_aggregate_function *aggregate_function);
	void (*duckdb_aggregate_function_set_name)(duckdb_aggregate_function aggregate_function, const char *name);
	void (*duckdb_aggregate_function_add_parameter)(duckdb_aggregate_function aggregate_function,
	                                                duckdb_logical_type type);
	void (*duckdb_aggregate_function_set_return_type)(duckdb_aggregate_function aggregate_function,
	                                                  duckdb_logical_type type);
	void (*duckdb_aggregate_function_set_functions)(duckdb_aggregate_function aggregate_function,
	                                                duckdb_aggregate_state_size state_size,
	                                                duckdb_aggregate_init_t state_init,
	                                                duckdb_aggregate_update_t update,
	                                                duckdb_aggregate_combine_t combine,
	                                                duckdb_aggregate_finalize_t finalize);
	void (*duckdb_aggregate_function_set_destructor)(duckdb_aggregate_function aggregate_function,
	                                                 duckdb_aggregate_destroy_t destroy);
	duckdb_state (*duckdb_register_aggregate_function)(duckdb_connection con,
	                                                   duckdb_aggregate_function aggregate_function);
	void (*duckdb_aggregate_function_set_special_handling)(duckdb_aggregate_function aggregate_function);
	void (*duckdb_aggregate_function_set_extra_info)(duckdb_aggregate_function aggregate_function, void *extra_info,
	                                                 duckdb_delete_callback_t destroy);
	void *(*duckdb_aggregate_function_get_extra_info)(duckdb_function_info info);
	void (*duckdb_aggregate_function_set_error)(duckdb_function_info info, const char *error);
	void (*duckdb_logical_type_set_alias)(duckdb_logical_type type, const char *alias);
	duckdb_state (*duckdb_register_logical_type)(duckdb_connection con, duckdb_logical_type type,
	                                             duckdb_create_type_info info);
	duckdb_cast_function (*duckdb_create_cast_function)();
	void (*duckdb_cast_function_set_source_type)(duckdb_cast_function cast_function, duckdb_logical_type source_type);
	void (*duckdb_cast_function_set_target_type)(duckdb_cast_function cast_function, duckdb_logical_type target_type);
	void (*duckdb_cast_function_set_implicit_cast_cost)(duckdb_cast_function cast_function, int64_t cost);
	void (*duckdb_cast_function_set_function)(duckdb_cast_function cast_function, duckdb_cast_function_t function);
	void (*duckdb_cast_function_set_extra_info)(duckdb_cast_function cast_function, void *extra_info,
	                                            duckdb_delete_callback_t destroy);
	void *(*duckdb_cast_function_get_extra_info)(duckdb_function_info info);
	duckdb_cast_mode (*duckdb_cast_function_get_cast_mode)(duckdb_function_info info);
	void (*duckdb_cast_function_set_error)(duckdb_function_info info, const char *error);
	void (*duckdb_cast_function_set_row_error)(duckdb_function_info info, const char *error, idx_t row,
	                                           duckdb_vector output);
	duckdb_state (*duckdb_register_cast_function)(duckdb_connection con, duckdb_cast_function cast_function);
	void (*duckdb_destroy_cast_function)(duckdb_cast_function *cast_function);
	idx_t (*duckdb_row_count)(duckdb_result *result);
	void *(*duckdb_column_data)(duckdb_result *result, idx_t col);
	bool *(*duckdb_nullmask_data)(duckdb_result *result, idx_t col);
	duckdb_data_chunk (*duckdb_result_get_chunk)(duckdb_result result, idx_t chunk_index);
	bool (*duckdb_result_is_streaming)(duckdb_result result);
	idx_t (*duckdb_result_chunk_count)(duckdb_result result);
	duckdb_result_type (*duckdb_result_return_type)(duckdb_result result);
	bool (*duckdb_value_boolean)(duckdb_result *result, idx_t col, idx_t row);
	int8_t (*duckdb_value_int8)(duckdb_result *result, idx_t col, idx_t row);
	int16_t (*duckdb_value_int16)(duckdb_result *result, idx_t col, idx_t row);
	int32_t (*duckdb_value_int32)(duckdb_result *result, idx_t col, idx_t row);
	int64_t (*duckdb_value_int64)(duckdb_result *result, idx_t col, idx_t row);
	duckdb_hugeint (*duckdb_value_hugeint)(duckdb_result *result, idx_t col, idx_t row);
	duckdb_uhugeint (*duckdb_value_uhugeint)(duckdb_result *result, idx_t col, idx_t row);
	duckdb_decimal (*duckdb_value_decimal)(duckdb_result *result, idx_t col, idx_t row);
	uint8_t (*duckdb_value_uint8)(duckdb_result *result, idx_t col, idx_t row);
	uint16_t (*duckdb_value_uint16)(duckdb_result *result, idx_t col, idx_t row);
	uint32_t (*duckdb_value_uint32)(duckdb_result *result, idx_t col, idx_t row);
	uint64_t (*duckdb_value_uint64)(duckdb_result *result, idx_t col, idx_t row);
	float (*duckdb_value_float)(duckdb_result *result, idx_t col, idx_t row);
	double (*duckdb_value_double)(duckdb_result *result, idx_t col, idx_t row);
	duckdb_date (*duckdb_value_date)(duckdb_result *result, idx_t col, idx_t row);
	duckdb_time (*duckdb_value_time)(duckdb_result *result, idx_t col, idx_t row);
	duckdb_timestamp (*duckdb_value_timestamp)(duckdb_result *result, idx_t col, idx_t row);
	duckdb_interval (*duckdb_value_interval)(duckdb_result *result, idx_t col, idx_t row);
	char *(*duckdb_value_varchar)(duckdb_result *result, idx_t col, idx_t row);
	duckdb_string (*duckdb_value_string)(duckdb_result *result, idx_t col, idx_t row);
	char *(*duckdb_value_varchar_internal)(duckdb_result *result, idx_t col, idx_t row);
	duckdb_string (*duckdb_value_string_internal)(duckdb_result *result, idx_t col, idx_t row);
	duckdb_blob (*duckdb_value_blob)(duckdb_result *result, idx_t col, idx_t row);
	bool (*duckdb_value_is_null)(duckdb_result *result, idx_t col, idx_t row);
	duckdb_state (*duckdb_execute_prepared_streaming)(duckdb_prepared_statement prepared_statement,
	                                                  duckdb_result *out_result);
	duckdb_state (*duckdb_pending_prepared_streaming)(duckdb_prepared_statement prepared_statement,
	                                                  duckdb_pending_result *out_result);
	duckdb_state (*duckdb_column_has_default)(duckdb_table_description table_description, idx_t index, bool *out);
	duckdb_state (*duckdb_query_arrow)(duckdb_connection connection, const char *query, duckdb_arrow *out_result);
	duckdb_state (*duckdb_query_arrow_schema)(duckdb_arrow result, duckdb_arrow_schema *out_schema);
	duckdb_state (*duckdb_prepared_arrow_schema)(duckdb_prepared_statement prepared, duckdb_arrow_schema *out_schema);
	void (*duckdb_result_arrow_array)(duckdb_result result, duckdb_data_chunk chunk, duckdb_arrow_array *out_array);
	duckdb_state (*duckdb_query_arrow_array)(duckdb_arrow result, duckdb_arrow_array *out_array);
	idx_t (*duckdb_arrow_column_count)(duckdb_arrow result);
	idx_t (*duckdb_arrow_row_count)(duckdb_arrow result);
	idx_t (*duckdb_arrow_rows_changed)(duckdb_arrow result);
	const char *(*duckdb_query_arrow_error)(duckdb_arrow result);
	void (*duckdb_destroy_arrow)(duckdb_arrow *result);
	void (*duckdb_destroy_arrow_stream)(duckdb_arrow_stream *stream_p);
	duckdb_state (*duckdb_execute_prepared_arrow)(duckdb_prepared_statement prepared_statement,
	                                              duckdb_arrow *out_result);
	duckdb_state (*duckdb_arrow_scan)(duckdb_connection connection, const char *table_name, duckdb_arrow_stream arrow);
	duckdb_state (*duckdb_arrow_array_scan)(duckdb_connection connection, const char *table_name,
	                                        duckdb_arrow_schema arrow_schema, duckdb_arrow_array arrow_array,
	                                        duckdb_arrow_stream *out_stream);
	duckdb_data_chunk (*duckdb_stream_fetch_chunk)(duckdb_result result);
} duckdb_ext_api_v0;

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