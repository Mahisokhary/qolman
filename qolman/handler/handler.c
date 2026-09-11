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

