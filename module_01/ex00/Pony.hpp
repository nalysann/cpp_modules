#ifndef PONY_HPP
#define PONY_HPP

#include <string>

class Pony {
  public:
    explicit Pony(const std::string& name);
    ~Pony();

    static void print_pony_population();

    void make_magic() const;

  private:
    static size_t _pony_population;

    const std::string _name;
};

void ponyOnTheStack(const std::string& name);
void ponyOnTheHeap(const std::string& name);

#endif
