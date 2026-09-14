#include <qolman/qolman.internal.h>

struct data {
	FILE *fp;
	bool close;
};

static void _qolman_handler_filep_handle(qolman_handler_t h, char *log) {
	struct data *d = (struct data *) h->data;
	fprintf(d->fp, "%s", log);
}

static void _qolman_handler_filep_destroy(qolman_handler_t h) {
	struct data *d = (struct data *) h->data;
	if (d->close) fclose(d->fp);
}

qolman_result_t qolman_handler_filep_create(qolman_handler_t *handler, FILE *fp, bool close) {
	qolman_run(qolman_handler_create(handler, &_qolman_handler_filep_handle, &_qolman_handler_filep_destroy, sizeof(struct data)));
	struct data *d = (struct data *) (*handler)->data;
	d->fp = fp;
	d->close = close;
	return QOLMAN_RESULT_OK;
}

