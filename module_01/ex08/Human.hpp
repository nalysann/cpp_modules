#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <string>

class Human {
  public:
    explicit Human(const std::string& name);

    void action(const std::string& action_name,
                const std::string& target) const;

  private:
    typedef void (Human::*_attack)(const std::string& target) const;

    void _meleeAttack(const std::string& target) const;
    void _rangedAttack(const std::string& target) const;
    void _intimidatingShout(const std::string& target) const;

    static const size_t NUM_ACTIONS = 3;

    const std::string _name;
};

#endif
