# Log manager
An object holding formatters and handlers \
Creates records amd handles levels

## Properties
| name              | description                                  | required |
|-------------------|----------------------------------------------|:--------:|
| default level     | Default level used to handle record          |    no    |
| default formatter | Default formatter used to format records     |   yes    |
| handlers          | Handlers called by manager to handle records |    no    |

> It just ignores records if no handler is available

## Functionality

### Levels
priority of handler level is the minimum priority handled by the handle
> If level of manager and handler are both null all records are handled by handler

## Implementation
Not implemented

[back](index.md)
