#ifndef GAME_MANAGER
#define GAME_MANAGER

#include <vector>

#include "event.hpp"
#include "list.hpp"
#include "property.hpp"
#include "house.hpp"
#include "apartment_complex.hpp"
#include "business_complex.hpp"
#include "event.hpp"
#include "helper.hpp"

class GameManager {
private:
    List<Property*> available_properties;
    List<Property*> owned_properties;

    int bank_account, months;

    void print_owned();

public:
    enum State {
        kInitalize,
        kUpdateProperties,
        kDebts,
        kTaxes,
        kRent,
        kEvent,
        kPurchase,
        kSell,
        kChangeRent,
    };

    GameManager();
    GameManager(const GameManager&);
    ~GameManager();

    const GameManager& operator=(const GameManager&);

    int get_bank_account() const;

    void generate_properties();

    bool is_game_over();
    void pay_debts();
    void pay_taxes();
    void collect_rent();
    void update_properties();
    void buy_property();
    void sell_property();
    void event();
    void update_rent();
    void print_status();
};

#endif