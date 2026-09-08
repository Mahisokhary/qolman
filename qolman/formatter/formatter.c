#include <qolman/qolman.internal.h>

struct buffer {
	char *b;
	size_t s;
	size_t l;
};

static inline void _buffer_write(struct buffer *b, const char *fmt, ...) {
	va_list ap, ap2;
	va_start(ap, fmt);
	va_copy(ap2, ap);

	size_t len = vsnprintf(NULL, 0, fmt, ap2) + 1;
	va_end(ap2);

	if (len > (b->s - b->l)) {
		b->s += len;
		b->b = realloc(b->b, b->s);
	}

	int r = vsnprintf(b->b + b->l, len, fmt, ap);
	b->l += len - 1;	// -1 so next write will write over the null terminator
	va_end(ap);
}

char *qolman_formatter_text(qolman_record_t record) {
	struct buffer b = { NULL, 0, 0 };
	struct tm *t = localtime(&record->time);
	b.b = malloc(b.s);

	_buffer_write(&b, "[%04d-%02d-%02d %02d:%02d:%02d] [%s] %s\n",
		t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec,
		record->level->label,
		record->label
	);

	if (record->description && *record->description) {
		char *od = strdup(record->description);
		char *d = od;
		char *tok;
		while ((tok = strtok_r(d, "\n", &d))) {
			_buffer_write(&b, "\t%s\n", tok);
		}
		free(od);
	}

	return b.b;
}

