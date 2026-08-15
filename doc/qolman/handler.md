# Log Handler
An object containing function to publish log records whether to stdout or a file

## Property

| name      | description                              | arguments    | required | type                 |
|-----------|------------------------------------------|--------------|----------|----------------------|
| handle    | publish record                           | ( `char *` ) | yes      | function pointer     |
| destroy   | destroys the handler                     | ( )          | yes      | function pointer     |
| level     | minimum log level                        | -            | no       | qolamn log level     |
| formatter | log formatter to be used                 | -            | no       | qolman log formatter |
| data      | internal only data used only and only by | -            | no       | flexible array       |

> Calling formatter and checking level is responsibility of the [log manager](manager.md) \
> If `formatter` or `level` is not available in handler, the manager should use its own `formatter` or `level`

## Implementation
- [ ] Handler core (typedefs, functions, ...)
- [ ] Stdout handler
- [ ] Stderr handler
- [ ] File handler

[back](index.md)
