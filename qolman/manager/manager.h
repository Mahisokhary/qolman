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

#ifdef __cplusplus
}
#endif

#endif

