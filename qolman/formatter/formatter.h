#ifndef _qolman_formatter_formatter_h_
#define _qolman_formatter_formatter_h_


#ifdef __cplusplus
extern "C" {
#endif

/*
 * A function that take a record and format it for output to file, stdout, ...
 * Returned buffer must be freeable by std free function
 */
typedef char* (*qolman_formatter_t)(qolman_record_t record);

/*
 * Formats record into human-readable text
 */
char *qolman_formatter_text(qolman_record_t record);

#ifdef __cplusplus
}
#endif
#endif

