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
A record is handled by a handler if its level importance is equal or higher than level of both log manager and log handler
(`record.level >= manager.level && record.level >= handler.level`)
> `NULL` level means allow all

## Implementation
- [x] Properties
    - [x] default level: getter and setter implemented
    - [x] default formatter: getter and sett implemented + constructor arg
    - [x] handlers: getter an setter implemented

[back](index.md)
