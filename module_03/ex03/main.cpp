#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

void ft_show(const Scavtrap& f){
    std::cout << " ->Scavtrap: " << f.getName() << "(" << f.getLevel() << ")" << std::endl;
    std::cout << " * hp & max hp: " << f.getHP() << ", " << f.getMaxHP() << std::endl;
    std::cout << " * enery & max energy: " << f.getEnergy() << ", " << f.getMaxEnergy() << std::endl;
    std::cout << " * melee, ranged & armor: " << f.getMeleeDamage() << ", " << f.getRangedDamage() << ", " << f.getArmor() << std::endl;
}

void ft_show(const Fragtrap& f){
    std::cout << " ->Fragtrap: " << f.getName() << "(" << f.getLevel() << ")" << std::endl;
    std::cout << " * hp & max hp: " << f.getHP() << ", " << f.getMaxHP() << std::endl;
    std::cout << " * enery & max energy: " << f.getEnergy() << ", " << f.getMaxEnergy() << std::endl;
    std::cout << " * melee, ranged & armor: " << f.getMeleeDamage() << ", " << f.getRangedDamage() << ", " << f.getArmor() << std::endl;
}

void ft_show(const Ninjatrap& f){
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


    std::cout << std::endl
     << "________________________________________________" << std::endl << std::endl;

    Scavtrap robot_3("SC4V_01");
    Scavtrap robot_4("SC4V_02");
    Scavtrap robot_3_cpy(robot_3);

    ft_show(robot_3_cpy);
    robot_3_cpy.meleeAttack(robot_4.getName());
    robot_4.takeDamage(robot_3_cpy.getMeleeDamage());
    robot_3_cpy.takeDamage(1);
    robot_3_cpy.takeDamage(2);
    robot_3_cpy.takeDamage(30);
    robot_3_cpy.takeDamage(99);
    ft_show(robot_3_cpy);
    robot_3_cpy.beRepaired(1000);

    robot_4.challengeNewcomer();
    robot_3_cpy.challengeNewcomer();
    robot_3.challengeNewcomer();
    robot_4.challengeNewcomer();
    robot_4.challengeNewcomer();
    ft_show(robot_3_cpy);

     std::cout << std::endl
     << "________________________________________________" << std::endl << std::endl;

    Ninjatrap ninja("Ninja_1");
    Ninjatrap ninja2("Ninja_2");
    Ninjatrap ninja2_cpy(ninja2);

    Claptrap cp;

    ninja2_cpy.meleeAttack(ninja.getName());
    ninja.takeDamage(43);
    ninja.takeDamage(1);
    ninja.takeDamage(2);
    ft_show(ninja2_cpy);
    ninja.takeDamage(30);
    ninja.takeDamage(99);
    ninja.beRepaired(1000);
    ft_show(ninja2_cpy);

    ninja.ninjaShoebox(cp);
    ninja.ninjaShoebox(ninja2_cpy);
    ninja.ninjaShoebox(robot_1);
    ninja.ninjaShoebox(robot_3_cpy);
    ft_show(ninja);


    return (0);
}