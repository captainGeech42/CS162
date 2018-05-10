#include <stdio.h>

int main() {
    printf("not in a debug\n");

#ifdef DEBUG
    printf("in a debug\n");
#endif

    return 0;
}