#include <test/test.h>

extern bool test_qolman_level();

bool test_qolman() {
	bool success = 1;
	success &= test_qolman_level();
	return success;
}

