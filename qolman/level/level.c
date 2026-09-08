#include <qolman/qolman.internal.h>

/*
 * This array should always be sorted by importance
 * And no skipped importance
 * Example:
 * Wrong: -2 -3 0 (not sorted)
 * Wrong: -2 0 1 2 (-1 is skipped)
 * Correct: -1 0 1 2
 */
const struct qolman_level qolman_level_defaults[] = {
	{ -2, "trace" },
	{ -1, "debug" },
	{ 0, "info" },
	{ 1, "warning" },
	{ 2, "error" },
};

qolman_level_t qolman_level_get(int importance) {
	int index = importance - qolman_level_defaults[0].importance;
	if (0 > index || index >= (sizeof(qolman_level_defaults) / sizeof(struct qolman_level))) return NULL;
	return &qolman_level_defaults[index];
}

