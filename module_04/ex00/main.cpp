#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

/*check_ignore*/

int main()
{
    Sorcerer    robert("Robert", "the Magnificent");
    Victim      jim("Jimmy");
    Peon        joe("Joe");
    
    std::cout << robert << jim << joe;
    robert.polymorph(jim);
    robert.polymorph(joe);

    std::cout << "Extra testing:" << std::endl;
    Victim  *v_ptr = new Victim("ptr_jimmy");
    Peon    *p_ptr = new Peon("ptr_joe");

    std::cout << *v_ptr << *p_ptr << std::endl;
    robert.polymorph(*v_ptr);
    robert.polymorph(*p_ptr);

    delete (v_ptr);
    delete (p_ptr);


    return 0;
}