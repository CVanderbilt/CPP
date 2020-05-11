#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    srand (time(NULL));
    Fragtrap robot_1("FR4G_01");
    Fragtrap robot_2("FR4G_02");
    Fragtrap robot_1_cpy(robot_1);

    robot_1_cpy.meleeAttack(robot_2.getName());
    robot_2.takeDamage(robot_1_cpy.getMeleeDamage());

    robot_2.vaulthunter_dot_exe(robot_1_cpy.getName());
    robot_1_cpy.takeDamage(1);
    robot_2.vaulthunter_dot_exe(robot_1_cpy.getName());
    robot_1_cpy.takeDamage(2);
    robot_2.vaulthunter_dot_exe(robot_1_cpy.getName());
    robot_1_cpy.takeDamage(30);
    robot_2.vaulthunter_dot_exe(robot_1_cpy.getName());
    robot_1_cpy.takeDamage(99);
    robot_2.vaulthunter_dot_exe(robot_1_cpy.getName());

    robot_1_cpy.beRepaired(1000);

    std::cout << std::endl << std::endl << std::endl;

    Scavtrap robot_3("SC4V_01");
    Scavtrap robot_4("SC4V_02");
    Scavtrap robot_3_cpy(robot_3);

    robot_3_cpy.meleeAttack(robot_4.getName());
    robot_4.takeDamage(robot_3_cpy.getMeleeDamage());
    robot_3_cpy.takeDamage(1);
    robot_3_cpy.takeDamage(2);
    robot_3_cpy.takeDamage(30);
    robot_3_cpy.takeDamage(99);
    robot_3_cpy.beRepaired(1000);

    robot_4.challengeNewcomer();
    robot_3_cpy.challengeNewcomer();
    robot_3.challengeNewcomer();
    robot_4.challengeNewcomer();
    robot_4.challengeNewcomer();

    return (0);
}