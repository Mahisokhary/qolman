# Log Formatter
A function which takes a log record and convert it to a string

## Example
Input:
```text
time: 2026-06-26-16:26:26
level: error
label: something went wrong
description: something went really wrong at line 26
```
Output:
```text
[2026-06-26-16:26:26] [error] something went wrong:
description: something went really wrong at line 26
```

## Implementation
- [ ] Formatter core (typedefs, ...)
- [ ] Human-readable text formatter
- [ ] Machine-readable JSON formatter

[back](index.md)
