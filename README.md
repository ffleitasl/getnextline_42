# Get Next Line - @42Born2Code

## Project objetive

The "Get Next Line" project aims to create a function, get_next_line(int fd), capable of reading a file descriptor and returning the line obtained up to the first newline character.

## Project complexity

The complexity lies in the specific approach we take to address the problem. The peculiarity is that the number of bytes to read until the newline is variable and depends on the BUFFER_SIZE value. The implementation involves using the read function, managing a static variable, and dynamic memory allocation, adding an additional challenge.

## ¿How to solved GNL?

Before diving into implementation, it is crucial to understand how our program will work to obtain the line:

**STEP 1:** The program must read from the descriptor (fd) and store in a buffer as many times as BUFFER_SIZE allows, until encountering a newline character \n.

**STEP 2:** Extract from the buffer the portion stored up to the \n.

**STEP 3:** Modify the buffer to position ourselves after the \n. It's important to note that the function should be able to read an entire file if called repeatedly.

### Graphical Example (BUFFER_SIZE = 4):

Consider a file **EXAMPLE.txt** with the content:

```
Hello
How are
You
```
