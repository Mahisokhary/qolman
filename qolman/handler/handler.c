#include <qolman/qolman.internal.h>

qolman_result_t qolman_handler_create(qolman_handler_t *handler, qolman_handler_function_handle handle, qolman_handler_function_destroy destroy, size_t data_size) {
	qolman_handler_t h = malloc(sizeof(struct qolman_handler) + data_size);
	h->handle = handle;
	h->destroy = destroy;
	h->level = NULL;
	h->formatter = NULL;
	*handler = h;
	return QOLMAN_RESULT_OK;
}

qolman_result_t qolman_handler_destroy(qolman_handler_t h) {
	h->destroy(h);
	free(h);
	return QOLMAN_RESULT_OK;
}

qolman_level_t qolman_handler_level(qolman_handler_t h) {
	return h->level;
}

qolman_result_t qolman_handler_level_set(qolman_handler_t h, qolman_level_t level) {
	h->level = level;
	return QOLMAN_RESULT_OK;
}

qolman_formatter_t qolman_handler_formatter(qolman_handler_t h) {
	return h->formatter;
}

qolman_result_t qolman_handler_formatter_set(qolman_handler_t h, qolman_formatter_t formatter) {
	h->formatter = formatter;
	return QOLMAN_RESULT_OK;
}

