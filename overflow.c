#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    char buf[8];
    strcpy(buf, argv[1]);  // no bounds check
    printf("%s\n", buf);
    return 0;
}
// 1). Install 'apt install gcc clang cppcheck gdb' if not already
// 2). write this cmd: gcc -g -O0 -fsanitize=address -fno-omit-frame-pointer
// overflow.c -o overflow_asan 3). Test1:./overflow_asan Bob # short input: runs
// normally 4). Test2:./overflow_asan AAAAAAAAAAAAAAAAAAAA   # long input: ASan
// should abort