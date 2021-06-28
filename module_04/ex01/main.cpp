#include <iostream>
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Character.hpp"

/*check_ignore*/

int main()
{
    Character* me = new Character("me");
    std::cout << *me;
    Enemy* b = new RadScorpion();
    AWeapon* pr = new PlasmaRifle();
    AWeapon* pf = new PowerFist();
    me->equip(pr);
    std::cout << *me;
    me->equip(pf);
    me->attack(b);
    std::cout << *me;
    me->equip(pr);
    std::cout << *me;
    me->attack(b);
    std::cout << *me;
    me->attack(b);
    std::cout << *me;

    std::cout << std::endl << "extra tests:" << std::endl;

    Enemy* s = new (SuperMutant);
    
    me->equip(pf);
    me->attack(s);
    me->attack(s);

    std::cout << *me << std::endl;

    me->recoverAP();
    me->recoverAP();
    me->recoverAP();
    me->recoverAP();

    me->equip(pf);

    me->attack(s);
    me->attack(s);
    
    std::cout << *me << std::endl;



    return 0;
}