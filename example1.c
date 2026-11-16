#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    typedef struct {
        char name[8];
        int authorized;
    } FILE_NAME;
    FILE_NAME s = {"", 0};

    strcpy(s.name, argv[1]);  // no bounds check!

    printf("name = %s, authorized = %d\n", s.name, s.authorized);
    return 0;
}

// First run gcc -O0 -fno-stack-protector -U_FORTIFY_SOURCE {NameOfFile.c} -o
// {NameOfFile} Then run some tests: Test 1: ./example1 Bob Test 2: ./example1
// AAAAAAAAAAAA