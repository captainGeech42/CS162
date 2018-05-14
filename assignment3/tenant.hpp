#ifndef TENANT
#define TENANT

#include <assert.h>
#include <stdlib.h>

class Tenant {
protected:
    int agreeability, budget, rent;

public:
    Tenant();
    
    int get_budget() const;
    int get_rent() const;
    void set_rent(int);

    bool will_pay_rent();
    bool will_leave();
};

#endif