#ifndef _qolman_level_level_h_
#define _qolman_level_level_h_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Public implementation of log level
 */
struct qolman_level {
	int importance;
	char *label;
};

/*
 * Pointer to actual level
 */
typedef const struct qolman_level *qolman_level_t;

#ifdef __cplusplus
}
#endif

#endif

