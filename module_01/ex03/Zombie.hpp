#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
  private:
    static std::string _get_random_name(size_t size = 8);

  public:
    explicit Zombie(const std::string& type = "puncher",
                    const std::string& name = _get_random_name());

    void announce() const;

  private:
    const std::string _type;
    const std::string _name;
};

#endif
