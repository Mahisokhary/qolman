#ifndef _qolman_manager_manager_h_
#define _qolman_manager_manager_h_

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

#ifdef __cplusplus
}
#endif

#endif

