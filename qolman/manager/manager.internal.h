#ifndef _qolman_manager_manager_internal_h_
#define _qolman_manager_manager_internal_h_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Log manager
 */
struct qolman_manager {
	qolman_level_t level;
	qolman_formatter_t formatter;
	qolman_handler_t *handlers;
	size_t handlers_length;
};

#ifdef __cplusplus
}
#endif

#endif

