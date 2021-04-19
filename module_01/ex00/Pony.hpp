#ifndef PONY_HPP
#define PONY_HPP

#include <string>

class Pony {
  public:
    static void printPonyPopulation();

    explicit Pony(const std::string& name);
    ~Pony();

    void makeMagic() const;

  private:
    static size_t _ponyPopulation;

    const std::string _name;
};

void ponyOnTheStack(const std::string& name);
void ponyOnTheHeap(const std::string& name);

#endif
