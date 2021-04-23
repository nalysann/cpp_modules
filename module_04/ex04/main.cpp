#include "Asteroid.hpp"
#include "Comet.hpp"
#include "DeepCoreMiner.hpp"
#include "IAsteroid.hpp"
#include "IMiningLaser.hpp"
#include "MiningBarge.hpp"
#include "StripMiner.hpp"

int	main() {
    MiningBarge* barge = new MiningBarge();

    barge->equip(new DeepCoreMiner());
    barge->equip(new StripMiner());
    barge->equip(new DeepCoreMiner());
    barge->equip(new StripMiner());

    IAsteroid* comet = new Comet();
    IAsteroid* asteroid = new Asteroid();

    barge->mine(asteroid);
    barge->mine(comet);

    IMiningLaser* extra = new DeepCoreMiner();

    barge->equip(extra);

    barge->mine(asteroid);
    barge->mine(comet);

    delete barge;
    delete extra;
    delete asteroid;
    delete comet;
}
