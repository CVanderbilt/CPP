#include <iostream>
#include "FragTrap.hpp"

void ft_show(const Fragtrap& f){
    std::cout << " ->Fragtrap: " << f.getName() << "(" << f.getLevel() << ")" << std::endl;
    std::cout << " * hp & max hp: " << f.getHP() << ", " << f.getMaxHP() << std::endl;
    std::cout << " * enery & max energy: " << f.getEnergy() << ", " << f.getMaxEnergy() << std::endl;
    std::cout << " * melee, ranged & armor: " << f.getMeleeDamage() << ", " << f.getRangedDamage() << ", " << f.getArmor() << std::endl;
}

int main(void)
{
    srand (time(NULL));
    Fragtrap robot_1("FR4G_01");
    Fragtrap robot_2("FR4G_02");
    Fragtrap robot_1_cpy(robot_1);

    ft_show(robot_1_cpy);
    ft_show(robot_2);

    robot_1_cpy.meleeAttack(robot_2.getName());
    robot_2.takeDamage(robot_1_cpy.getMeleeDamage());

    robot_2.vaulthunter_dot_exe(robot_1_cpy.getName());
    robot_1_cpy.takeDamage(1);
    robot_2.vaulthunter_dot_exe(robot_1_cpy.getName());
    robot_1_cpy.takeDamage(2);
    robot_2.vaulthunter_dot_exe(robot_1_cpy.getName());
    robot_1_cpy.takeDamage(30);
    ft_show(robot_1_cpy);
    ft_show(robot_2);
    robot_2.vaulthunter_dot_exe(robot_1_cpy.getName());
    robot_1_cpy.takeDamage(99);
    robot_2.vaulthunter_dot_exe(robot_1_cpy.getName());

    ft_show(robot_1_cpy);
    ft_show(robot_2);

    robot_1_cpy.beRepaired(1000);

    ft_show(robot_1_cpy);
    ft_show(robot_2);

    return (0);
}