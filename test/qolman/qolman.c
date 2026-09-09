#include <test/test.h>

extern bool test_qolman_level();
extern bool test_qolman_record();
extern bool test_qolman_formatter();
extern bool test_qolman_handler();

bool test_qolman() {
	bool success = 1;
	success &= test_qolman_level();
	success &= test_qolman_record();
	success &= test_qolman_formatter();
	success &= test_qolman_handler();
	return success;
}

