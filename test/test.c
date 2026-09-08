#include "test.h"
#include <stdlib.h>

extern bool test_qolman();

int main() {
	setenv("TZ", "Asia/Tehran", 1); // To get predictable times in systems with diffrent time zones

	bool success = 1;
	success &= test_qolman();
	return !success;
}

