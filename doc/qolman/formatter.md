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
- [x] Formatter core (typedefs, ...)
    - Package [record](../../qolman/record): Fully implemented
- [x] Human-readable text formatter
- [ ] Machine-readable JSON formatter: Not planned (since it needs external library)

[back](index.md)
