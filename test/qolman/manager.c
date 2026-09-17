#include <test/test.h>
#include <qolman/qolman.internal.h>

bool test_qolman_manager_create_destroy() {
	test_run_log("qolman_manager_create_destroy");
	qolman_manager_t manager;
	qolman_handler_t handler;
	qolman_handler_t handlers[1];
	size_t handlers_length = 1;
	struct qolman_level level = { 2147483647, "godlevel" };

	bool success = 1;
	success &= qolman_manager_create(&manager, &qolman_formatter_text) == QOLMAN_RESULT_OK;
	success &= qolman_handler_stdout(&handler) == QOLMAN_RESULT_OK;

	handlers[0] = handler;
	success &= qolman_manager_handlers_set(manager, handlers, handlers_length) == QOLMAN_RESULT_OK;
	success &= manager->handlers[0] == qolman_manager_handlers(manager, &handlers_length)[0];
	success &= handlers_length == 1;

	success &= qolman_manager_level_set(manager, &level) == QOLMAN_RESULT_OK;
	success &= qolman_manager_level(manager) == &level;

	success &= qolman_manager_formatter(manager) == &qolman_formatter_text;
	success &= qolman_manager_formatter_set(manager, NULL) == QOLMAN_RESULT_OK;
	success &= qolman_manager_formatter(manager) == NULL;
	success &= qolman_manager_formatter_set(manager, &qolman_formatter_text) == QOLMAN_RESULT_OK;
	success &= qolman_manager_formatter(manager) == &qolman_formatter_text;

	success &= qolman_manager_destroy(manager) == QOLMAN_RESULT_OK;
	test_result_log(success);
	return success;
}

bool test_qolman_manager() {
	bool success = 1;
	success &= test_qolman_manager_create_destroy();
	return success;
}

