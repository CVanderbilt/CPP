#include "MininBarge.hpp"
#include "IMiningLaser.hpp"
#include "IAsteroid.hpp"
#include "Asteroid.hpp"
#include "Comet.hpp"
#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"
#include <iostream>

int main(void)
{
    MiningBarge barge;

    DeepCoreMiner   dcm;
    StripMiner      sm;

    Comet       comet;
    Asteroid    asteroid;

    barge.equip(&dcm);
    barge.equip(&sm);
    std::cout << "Equiped deep core miner and strip miner" << std::endl;

    std::cout << "Comet:" << std::endl;
    barge.mine(&comet);
    std::cout << "Asteroid:" << std::endl;
    barge.mine(&asteroid);

    barge.equip(&dcm);
    barge.equip(&sm);
    barge.equip(&dcm);
    barge.equip(&sm);
    std::cout << "Equiped deep core miner, strip miner, deep core miner and strip miner" << std::endl;
    std::cout << "overflow so tools will be -> dcm, sm, dcm, sm" << std::endl;

    std::cout << "Comet:" << std::endl;
    barge.mine(&comet);
    std::cout << "Asteroid:" << std::endl;
    barge.mine(&asteroid);

    return (0);
}