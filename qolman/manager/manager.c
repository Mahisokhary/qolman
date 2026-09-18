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

qolman_result_t qolman_manager_handlers_set(qolman_manager_t m, qolman_handler_t* handlers, size_t length) {
	qolman_handler_t *hs = malloc(sizeof(qolman_handler_t) * length);
	memcpy(hs, handlers, sizeof(qolman_handler_t) * length);
	if (m->handlers) free(m->handlers);
	m->handlers_length = length;
	m->handlers = hs;
	return QOLMAN_RESULT_OK;
}

qolman_handler_t *qolman_manager_handlers(qolman_manager_t m, size_t *length) {
	if (length) *length = m->handlers_length;
	return m->handlers;
}

qolman_result_t qolman_manager_level_set(qolman_manager_t m, qolman_level_t level) {
	m->level = level;
	return QOLMAN_RESULT_OK;
}

qolman_level_t qolman_manager_level(qolman_manager_t m) {
	return m->level;
}

qolman_result_t qolman_manager_formatter_set(qolman_manager_t m, qolman_formatter_t formatter) {
	m->formatter = formatter;
	return QOLMAN_RESULT_OK;
}

qolman_formatter_t qolman_manager_formatter(qolman_manager_t m) {
	return m->formatter;
}

qolman_result_t qolman_manager_handle(qolman_manager_t m, qolman_record_t r) {
	if (m->level == NULL || r->level->importance >= m->level->importance) {
		qolman_handler_t *handlers = m->handlers;
		size_t handlers_length = m->handlers_length;
		for (int i = 0; i < handlers_length; i++) {
			qolman_handler_t h = handlers[i];
			if (h->level == NULL || r->level->importance >= h->level->importance) {
				qolman_formatter_t formatter = h->formatter;
				if (!formatter) formatter = m->formatter;
				char *str = formatter(r);
				qolman_run(qolman_handler_handle(h, str));
				free(str);
			}
		}
	}
	return QOLMAN_RESULT_OK;
}

qolman_result_t qolman_manager_handle_quick(qolman_manager_t m, time_t t, qolman_level_t level, char *logger, char *label, char *description) {
	struct qolman_record r = { t, level, label, description, logger };
	qolman_run(qolman_manager_handle(m, &r));
	return QOLMAN_RESULT_OK;
}

