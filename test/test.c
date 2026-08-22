#include "test.h"

extern bool test_qolman();

int main() {
	bool success = 1;
	success &= test_qolman();
	return !success;
}

