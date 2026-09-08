#ifndef _qolman_record_record_internal_h_
#define _qolman_record_record_internal_h_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Record implementation
 */
struct qolman_record {
	time_t time;
	qolman_level_t level;
	char *label;
	char *description;
};

#ifdef __cplusplus
}
#endif
#endif


