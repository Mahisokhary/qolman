#include <qolman/qolman.internal.h>

qolman_result_t qolman_record_create(qolman_record_t *record, time_t t, qolman_level_t level, const char *logger, const char *label, const char *description) {
	if (!t) time(&t);
	qolman_record_t r; qmalloc(r, sizeof(struct qolman_record));
	r->time = t;
	r->level = level;
	qstrdup(r->logger, logger);
	qstrdup(r->label, label);
	if (description) {
		qstrdup(r->description, description);
	} else r->description = NULL;
	*record = r;
	return QOLMAN_RESULT_OK;
}

qolman_result_t qolman_record_destroy(qolman_record_t r) {
	free(r->logger);
	free(r->label);
	if (r->description) free(r->description);
	free(r);
	return QOLMAN_RESULT_OK;
}

time_t qolman_record_time(qolman_record_t r) {
	return r->time;
}

qolman_level_t qolman_record_level(qolman_record_t r) {
	return r->level;
}

const char *qolman_record_logger(qolman_record_t r) {
	return r->logger;
}

const char *qolman_record_label(qolman_record_t r) {
	return r->label;
}

const char *qolman_record_description(qolman_record_t r) {
	return r->description;
}

