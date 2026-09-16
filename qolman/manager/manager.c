#include <qolman/qolman.internal.h>

qolman_result_t qolman_manager_create(qolman_manager_t *manager, qolman_formatter_t formatter) {
	qolman_manager_t m = malloc(sizeof(struct qolman_manager));
	m->level = NULL;
	m->formatter = formatter;
	m->handlers = NULL;
	m->handlers_length = 0;
	*manager = m;
	return QOLMAN_RESULT_OK;
}

qolman_result_t qolman_manager_destroy(qolman_manager_t m) {
	free(m);
	return QOLMAN_RESULT_OK;
}

