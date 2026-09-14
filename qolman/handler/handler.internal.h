#ifndef _qolman_handler_handler_internal_h_
#define _qolman_handler_handler_internal_h_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * A log handler
 */
struct qolman_handler {
	qolman_handler_function_handle handle;
	qolman_handler_function_destroy destroy;
	qolman_level_t level;
	qolman_formatter_t formatter;
	char data[];
};

/*
 * Creates a file pointer handler
 * close: whether the file should or shouldnt be closed by the handler
 */
qolman_result_t qolman_handler_filep_create(qolman_handler_t *handler, FILE *fp, bool close);

#ifdef __cplusplus
}
#endif
#endif

