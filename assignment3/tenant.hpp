#ifndef TENANT
#define TENANT

#include <stdlib.h>

class Tenant {
protected:
    int agreeability, budget;

public:
    Tenant();

    bool will_pay_rent(int);
    bool will_leave();
};

#endif