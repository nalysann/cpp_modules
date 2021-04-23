#ifndef SQUAD_HPP
#define SQUAD_HPP

#include "ISpaceMarine.hpp"
#include "ISquad.hpp"

class Squad : public ISquad {
  public:
    Squad();
    Squad(const Squad& other);
    Squad& operator=(const Squad& other);
    ~Squad();

    int getCount() const;
    ISpaceMarine* getUnit(int idx) const;
    int push(ISpaceMarine* unit);

  private:
    static const int INITIAL_MAX_COUNT = 8;
    static const int GROWTH_RATE = 2;

    void _clear();
    bool _contains(ISpaceMarine* unit);

    int _max_count;
    int _count;
    ISpaceMarine** _units;
};

#endif
