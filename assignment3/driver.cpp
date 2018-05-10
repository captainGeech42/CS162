#include <stdio.h>

#include "list.hpp"

int main() {
    List<int> mylist;
    mylist.push_back(5);
    mylist.push_back(7);

    printf("%d\n", mylist[1]);

    return 0;
}