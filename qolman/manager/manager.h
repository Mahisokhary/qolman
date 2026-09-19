#ifndef _qolman_manager_manager_h_
#define _qolman_manager_manager_h_

#define qolman_manager_handle_trace(m, t, logger, label, description) qolman_manager_handle_quick(m, t, qolman_level_get(-2), logger, label, description)
#define qolman_manager_handle_debug(m, t, logger, label, description) qolman_manager_handle_quick(m, t, qolman_level_get(-1), logger, label, description)
#define qolman_manager_handle_info(m, t, logger, label, description) qolman_manager_handle_quick(m, t, qolman_level_get(0), logger, label, description)
#define qolman_manager_handle_warning(m, t, logger, label, description) qolman_manager_handle_quick(m, t, qolman_level_get(1), logger, label, description)
#define qolman_manager_handle_error(m, t, logger, label, description) qolman_manager_handle_quick(m, t, qolman_level_get(2), logger, label, description)

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Pointer to the atual log manager
 */
typedef struct qolman_manager *qolman_manager_t;

/*
 * Creates a log manager
 */
qolman_result_t qolman_manager_create(qolman_manager_t *manager, qolman_formatter_t formatter);

/*
 * Destroys a log manager
 */
qolman_result_t qolman_manager_destroy(qolman_manager_t manager);

/*
 * Set handlers for log manager
 */
qolman_result_t qolman_manager_handlers_set(qolman_manager_t manager, qolman_handler_t* handlers, size_t length);

/*
 * Returns handlers of the log manager
 * length paramether is ignored if its a nullptr
 */
qolman_handler_t *qolman_manager_handlers(qolman_manager_t manager, size_t *length);

/*
 * Set level of the log manager
 */
qolman_result_t qolman_manager_level_set(qolman_manager_t manager, qolman_level_t level);

/*
 * Returns level of the log manager
 */
qolman_level_t qolman_manager_level(qolman_manager_t manager);

/*
 * Set formatter of the log manager
 */
qolman_result_t qolman_manager_formatter_set(qolman_manager_t manager, qolman_formatter_t formatter);

/*
 * Returns formatter of the log manager
 */
qolman_formatter_t qolman_manager_formatter(qolman_manager_t manager);

/*
 * Handles a log record
 */
qolman_result_t qolman_manager_handle(qolman_manager_t manager, qolman_record_t record);

/*
 * Creates and handler a log record (its quick because you do it in a single function call)
 */
qolman_result_t qolman_manager_handle_quick(qolman_manager_t m, time_t t, qolman_level_t level, const char *logger, const char *label, const char *description);

#ifdef __cplusplus
}
#endif

#endif

