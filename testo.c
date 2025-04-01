#include <stdio.h>
#include <string.h>

// Compilation: gcc -o APP1-SEC2-LPP-STGO testo.c
// Execution: ./APP1-SEC2-LPP-STGO pls

void pls(int x) {
    printf("%i\n", x);
    printf("You called the pls function!\n");
}

int main(int argc, char *argv[]) {
    printf("shishinjkw");

    // Check if an argument was passed
    if (argc > 1) {
        // Compare the argument with the string "pls"
        if (strcmp(argv[1], "pls") == 0) {
            int len = argc;
            pls(len);
        } else {
            printf("Unknown command: %s\n", argv[1]);
        }
    } else {
        printf("No command provided.\n");
    }

    return 0;
}