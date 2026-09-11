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

#ifdef __cplusplus
}
#endif
#endif

