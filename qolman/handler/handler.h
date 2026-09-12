#ifndef _qolman_handler_handler_h_
#define _qolman_handler_handler_h_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Pointer to the actual handler
 */
typedef struct qolman_handler *qolman_handler_t;

/*
 * Function to handle a log
 */
typedef void (*qolman_handler_function_handle)(qolman_handler_t handler, char *log);

/*
 * Function to destroy a log handler
 */
typedef void (*qolman_handler_function_destroy)(qolman_handler_t handler);

/*
 * Creates a log handler
 */
qolman_result_t qolman_handler_create(qolman_handler_t *handler, qolman_handler_function_handle handle, qolman_handler_function_destroy destroy, size_t data_size);

/*
 * Destroys the log handler
 */
qolman_result_t qolman_handler_destroy(qolman_handler_t handler);

/*
 * Returns level of handler
 */
qolman_level_t qolman_handler_level(qolman_handler_t handler);

/*
 * Sets level ofhandler
 */
qolman_result_t qolman_handler_level_set(qolman_handler_t handler, qolman_level_t level);

/*
 * Returns formatter of handler
 */
qolman_formatter_t qolman_handler_formatter(qolman_handler_t handler);

/*
 * Sets formatter of handler
 */
qolman_result_t qolman_handler_formatter_set(qolman_handler_t handler, qolman_formatter_t formatter);

/*
 * Handles a log with the log handler
 */
qolman_result_t qolman_handler_handle(qolman_handler_t handler, char *log);

#ifdef __cplusplus
}
#endif
#endif

