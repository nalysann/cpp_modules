#ifndef COMET_HPP
#define COMET_HPP

#include <string>

#include "DeepCoreMiner.hpp"
#include "IAsteroid.hpp"
#include "StripMiner.hpp"

class Comet : public IAsteroid {
  public:
    Comet();
    Comet(const Comet& other);
    Comet& operator=(const Comet& other);
    ~Comet();

    std::string beMined(DeepCoreMiner*) const;
    std::string beMined(StripMiner*) const;
    std::string getName() const;

  private:
    std::string _name;
};

#endif
