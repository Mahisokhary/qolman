# Log Handler
An object containing function to publish log records whether to stdout or a file

## Property
| name      | description                             | arguments               | required | type                 |
|-----------|-----------------------------------------|-------------------------|----------|----------------------|
| handle    | publish record                          | ( `handler`, `char *` ) | yes      | function pointer     |
| destroy   | destroys the handler                    | ( `handler` )           | yes      | function pointer     |
| level     | minimum log level                       | -                       | no       | qolamn log level     |
| formatter | log formatter to be used                | -                       | no       | qolman log formatter |
| data      | internal only data used only by handler | -                       | no       | flexible array       |

> Calling formatter and checking level is responsibility of the [log manager](manager.md) \
> If `formatter` or `level` is not available in handler, the manager should use its own `formatter` or `level`

> `handler` type used in properties is a pointer to handler object in implementation

## Implementation
- [ ] Handler core (typedefs, functions, ...)
- [ ] Stdout handler
- [ ] Stderr handler
- [ ] File handler

[back](index.md)
