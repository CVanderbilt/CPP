#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include <iostream>

#define PUSH(sq, name) std::cout << "PUSHING: " << sq->push(name) << std::endl;

/*check_ignore*/

int main()
{
    ISpaceMarine* bob = new TacticalMarine;
    ISpaceMarine* jim = new AssaultTerminator;
    ISpaceMarine* other = new TacticalMarine;
    ISquad* vlc = new Squad;
    
    PUSH (vlc, bob)
    PUSH (vlc, bob)
    PUSH (vlc, jim)
    PUSH (vlc, jim)
    PUSH (vlc, other)

    for (int i = 0; i < vlc->getCount(); ++i)
    {
        ISpaceMarine* cur = vlc->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }
    delete vlc;
    return 0;
}