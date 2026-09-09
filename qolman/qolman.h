#ifndef _qolman_qolman_h_
#define _qolman_qolman_h_

#include <stddef.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Result of a qolman function
 */
typedef enum {
	QOLMAN_RESULT_OK = 0,	// Operation was successful
} qolman_result_t;

#ifdef __cplusplus
}
#endif

#include <qolman/level/level.h>
#include <qolman/record/record.h>
#include <qolman/formatter/formatter.h>
#include <qolman/handler/handler.h>

#endif

