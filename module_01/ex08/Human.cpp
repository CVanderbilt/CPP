#include "Human.hpp"

//const std::string Human::actionsNames[] = {"melee", "ranged", "shout"};
//void (* arr [])(std::string s1, std::string s2) = {
//    &(Human::meleeAttack);
//};

void Human::meleeAttack(std::string const & target){
    std::cout << "Human uses melee attack on " << target <<std::endl;
}

void Human::rangedAttack(std::string const & target){
    std::cout << "Human uses ranged attack on " << target <<std::endl;
}

void Human::intimidatingShout(std::string const & target){
    std::cout << "Human uses intimidating shout on " << target <<std::endl;
}

void Human::action(std::string const & action_name, std::string const & target)
{
    //std::string names[] = {"melee", "range", "shout"};
    void (Human::* foo)(std::string const s1);
    long long int i, j, k, n, proof;
    std::string melee = "meleeAttack";
    std::string range = "rangedAttack";
    std::string shout = "intimidatingShout";
    //uint32_t i, j;
    void (Human::* const actions[4])(std::string const &trgt) = {
        NULL,
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};
    i = -1;
    j = (!(melee.find(action_name)) * (!(action_name.length() - melee.length()))) * 1;
    k = (!(range.find(action_name)) * (!(action_name.length() - range.length()))) * 2;
    n = (!(shout.find(action_name)) * (!(action_name.length() - shout.length()))) * 3;
    proof = j + k + n;
    while (proof != 0)
    {
        (this->*actions[proof])(target);
        return ;
    }
    std::cout << "action: (" << action_name << ") not recognized" << std::endl;
}