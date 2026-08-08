# Log Record
An object to store information about a log record

## Properties
| name              | description                            | example                                  | required |
|-------------------|----------------------------------------|------------------------------------------|:--------:|
| time              | time when the record is logged         | `2026-06-26-16:26:26`                    |   yes    |
| [level](level.md) | level of the log                       | `error`                                  |   yes    |
| label             | one line short info about the log      | `something went wrong`                   |   yes    |
| description       | multiline line full info about the log | `something went really wrong at line 26` |    no    |

## Implementation
Not implemented

[back](index.md)
