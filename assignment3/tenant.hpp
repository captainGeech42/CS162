#ifndef TENANT
#define TENANT

class Tenant {
protected:
    int agreeability, budget;
    static int min_budget, max_budget;

public:
    Tenant();
    Tenant(const Tenant&);
    ~Tenant();

    const Tenant& operator=(const Tenant&);
};

#endif