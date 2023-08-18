# Practical Pointer Usage
## There are primarily four useful things you can do with pointers in C code:

- Ask the OS for a chunk of memory and use a pointer to work with it. This includes strings and something you haven’t seen yet, structs.

- Pass large blocks of memory (like large structs) to functions with a pointer, so you don’t have to pass the whole thing to them.

- Take the address of a function, so you can use it as a dynamic callback.

- Scan complex chunks of memory, converting bytes off of a network socket into data structures or parsing files.
