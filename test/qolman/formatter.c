#include <test/test.h>
#include <qolman/qolman.internal.h>

bool test_qolman_formatter_text() {
	test_run_log("qolman_formatter_text");
	struct qolman_level level = { 2147483647, "godlevel" };
	struct qolman_record record = { 1676385060, &level, "phoenix", "some details\nsome more details\n" };
	char *excpected = "[2023-02-14 18:01:00] [godlevel] phoenix\n\tsome details\n\tsome more details\n";
	char *excpected2 = "[2023-02-14 18:01:00] [godlevel] phoenix\n";
	char *formatted;

	bool success = 1;

	formatted = qolman_formatter_text(&record);
	success &= strcmp(excpected, formatted) == 0;
	free(formatted);

	// Should ignore description if empty
	record.description = "";
	formatted = qolman_formatter_text(&record);
	success &= strcmp(excpected2, formatted) == 0;
	free(formatted);

	// Should ignore description if null
	record.description = NULL;
	formatted = qolman_formatter_text(&record);
	success &= strcmp(excpected2, formatted) == 0;
	free(formatted);

	test_result_log(success);
	return success;
}

bool test_qolman_formatter() {
	bool success = 1;
	success &= test_qolman_formatter_text();
	return success;
}

