#ifndef GAME_MANAGER
#define GAME_MANAGER

#include "event.hpp"
#include "list.hpp"
#include "property.hpp"

class GameManager {
private:
    List<Property> available_properties;
    List<Property> owned_properties;

    int bank_account;

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
};

#endif