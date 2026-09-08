#include <test/test.h>
#include <qolman/qolman.internal.h>

bool test_qolman_record_create_destroy() {
	test_run_log("qolman_record_create_destroy");
	struct qolman_level level = { 2147483647, "godlevel" };
	qolman_record_t record;

	bool success = 1;
	success &= qolman_record_create(&record, 1676385060, &level, "phoenix", NULL) == QOLMAN_RESULT_OK;
	success &= qolman_record_time(record) == 1676385060;
	success &= qolman_record_level(record) == &level;
	success &= strcmp(qolman_record_label(record), "phoenix") == 0;
	success &= qolman_record_description(record) == NULL;
	success &= qolman_record_destroy(record) == QOLMAN_RESULT_OK;
	test_result_log(success);
	return success;
}

bool test_qolman_record() {
	bool success = 1;
	success &= test_qolman_record_create_destroy();
	return success;
}

