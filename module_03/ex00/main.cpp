#include <iostream>
#include "FragTrap.hpp"

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

    return (0);
}