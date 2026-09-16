#include <test/test.h>
#include <qolman/qolman.internal.h>

bool test_qolman_manager_create_destroy() {
	test_run_log("qolman_manager_create_destroy");
	qolman_manager_t manager;

	bool success = 1;
	success &= qolman_manager_create(&manager, &qolman_formatter_text) == QOLMAN_RESULT_OK;
	success &= qolman_manager_destroy(manager) == QOLMAN_RESULT_OK;
	test_result_log(success);
	return success;
}

bool test_qolman_manager() {
	bool success = 1;
	success &= test_qolman_manager_create_destroy();
	return success;
}

