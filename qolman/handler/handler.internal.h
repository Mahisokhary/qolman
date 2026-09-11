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

#ifdef __cplusplus
}
#endif
#endif

