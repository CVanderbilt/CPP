#include "MiningBarge.hpp"
#include "IMiningLaser.hpp"
#include "IAsteroid.hpp"
#include "KoalaSteroid.hpp"
#include "AsteroKreog.hpp"
#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"
#include <iostream>

/*check_ignore*/

int main(void)
{
    MiningBarge		barge;

    DeepCoreMiner   dcm;
    StripMiner      sm;

    KoalaSteroid	comet;
    AsteroKreog		asteroid;

    barge.equip(&dcm);
    barge.equip(&sm);
    std::cout << "Equiped deep core miner and strip miner" << std::endl;

    std::cout << comet.getName() << std::endl;
    barge.mine(&comet);
    std::cout << asteroid.getName() << std::endl;
    barge.mine(&asteroid);

    barge.equip(&dcm);
    barge.equip(&sm);
    barge.equip(&dcm);
    barge.equip(&sm);
    std::cout << "Equiped deep core miner, strip miner, deep core miner and strip miner" << std::endl;
    std::cout << "overflow so tools will be -> dcm, sm, dcm, sm" << std::endl;

    std::cout << comet.getName() << std::endl;
    barge.mine(&comet);
    std::cout << asteroid.getName() << std::endl;
    barge.mine(&asteroid);

    return (0);
}