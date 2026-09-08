#ifndef _qolman_qolman_internal_h_
#define _qolman_qolman_internal_h_

#include <qolman/qolman.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#define qolman_run(c) do { \
		qolman_result_t res = c; \
		if (res != QOLMAN_RESULT_OK) return res; \
	} while(0);

#ifdef __cplusplus
}
#endif

#include <qolman/level/level.internal.h>
#include <qolman/record/record.internal.h>
#include <qolman/formatter/formatter.internal.h>

#endif

