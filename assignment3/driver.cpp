#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "list.hpp"
#include "tenant.hpp"
#include "business.hpp"

int main() {
    srand(time(NULL));

    List<Tenant> mylist;
    Business a;

    mylist.push_back(a);

    return 0;
}