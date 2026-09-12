#include <test/test.h>
#include <qolman/qolman.internal.h>

static void _handler_handle(qolman_handler_t handler, char *log) {
	char **datap = (char **) handler->data;
	if (*datap) free(*datap);
	*datap = strdup(log); // Stores a copy of log for testing
}

static void _handler_destroy(qolman_handler_t handler) {
	char *data = *((char **) handler->data);
	if (data) free(data);
}

static qolman_result_t _handler_create(qolman_handler_t *handler) {
	qolman_run(qolman_handler_create(handler, &_handler_handle, &_handler_destroy, sizeof(char *)));
	char **datap = (char **) (*handler)->data;
	*datap = NULL;
	return QOLMAN_RESULT_OK;
}

bool test_qolman_handler_create_destroy() {
	test_run_log("qolman_handler_create_destroy");
	qolman_handler_t handler;

	bool success = 1;
	success &= _handler_create(&handler) == QOLMAN_RESULT_OK;
	success &= qolman_handler_handle(handler, "my log") == QOLMAN_RESULT_OK;
	success &= strcmp("my log", *((char **) handler->data)) == 0;
	success &= qolman_handler_destroy(handler) == QOLMAN_RESULT_OK;
	test_result_log(success);
	return success;
}

bool test_qolman_handler() {
	bool success = 1;
	success &= test_qolman_handler_create_destroy();
	return success;
}

