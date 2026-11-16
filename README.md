# Stack Buffer Overflows and Memory Vulnerabilities

COMP 211 Checkoff 3 | colin wu 

## Introduction

A stack buffer overflow occurs when an input is written past the end of a buffer that was allocated on the stack, leading to crashes, exploitation, and security risks. In this project, I am testing different scenarios when stack buffer overflow occurs and a potential solution to avoid such an issue.

## What I Explored

I've explored how the function strcpy in C's library has no bound checking, increasing the susceptibility of buffer oveflows to out-of-bound variables and even restricted addressess. I created a simulation in 'example1.c' to explore in depth the limits to buffer overflows, and tested a dynamic analysis detection tool in 'overflow.c' that spots stack buffer overflows.

## Key Discoveries and Observations

-'authorized' variable in example.c capped off at a int of 1094795585 once a stack-buffer-overflow occurs
-I looked at the assembly and found where the canary is stored and checked
-Tool AddressSanitizer used on overflow.c detected a stack-buffer-overflow on address 0xffffbc900028 at pc 0xffffbee2b354 bp 0xfffff5a553c0 sp 0xfffff5a54ba0; attempted to WRITE of size 21 at 0xffffbc900028 thread T0
-[32, 40) 'buf' (line 5) <== Memory access at offset 40 overflows this variable
-Aborts the program as soon as issue is detected

## Code Examples

| File | Description |
|------|-------------|
| `example1.c` | Overflow of a char array into an adjacent struct field |
| `overflow.c` | Overflow of a separate local array via `strcpy` |

### Running the examples

Tested on: macOS Tahoe 26.6.2, gcc version 13.3.0

```bash
# Vulnerable demo (protections off for the experiment)
gcc -O0 -g -fno-stack-protector -U_FORTIFY_SOURCE example1.c -o example1
./example1 Bob
./example1 AAAAAAAAAAAA

# AddressSanitizer
gcc -g -O0 -fsanitize=address overflow.c -o overflow_asan
./overflow_asan AAAAAAAAAAAAAAAAAAAA
```

> **Warning:** These programs are intentionally vulnerable. They are for learning only.

## Presentation Materials

- Slides: https://docs.google.com/presentation/d/1G-elGkkOfgnoi5KqC51Gpoh0E_WbVvr4EV9Dz7rGaGQ/edit?usp=sharing

## Additional Resources

- MITRE CWE-121: Stack-based Buffer Overflow
- Aleph One, "Smashing the Stack for Fun and Profit," *Phrack* 49
- Spafford's analysis of the 1988 Morris Worm
- AddressSanitizer documentation (LLVM)
