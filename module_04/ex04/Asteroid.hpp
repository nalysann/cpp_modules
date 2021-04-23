#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include <string>

#include "DeepCoreMiner.hpp"
#include "IAsteroid.hpp"
#include "StripMiner.hpp"

class Asteroid : public IAsteroid {
  public:
    Asteroid();
    Asteroid(const Asteroid& other);
    Asteroid& operator=(const Asteroid& other);
    ~Asteroid();

    std::string beMined(DeepCoreMiner*) const;
    std::string beMined(StripMiner*) const;
    std::string getName() const;

  private:
    std::string _name;
};

#endif
