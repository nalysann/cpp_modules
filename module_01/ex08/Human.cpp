#include <iostream>
#include <string>

#include "Human.hpp"

Human::Human(const std::string &name)
        : _name(name) {}

void Human::action (const std::string& action_name,
                    const std::string& target) const {
    static const std::string actions[NUM_ACTIONS] = {
            "melee",
            "ranged",
            "shout",
    };

    static const Human::_attack attacks[NUM_ACTIONS] = {
            &Human::_meleeAttack,
            &Human::_rangedAttack,
            &Human::_intimidatingShout,
    };

    for (size_t i = 0; i < NUM_ACTIONS; ++i) {
        if (action_name == actions[i]) {
            return (this->*attacks[i])(target);
        }
    }

    std::cout << "Unknown action: " << action_name << std::endl;
}

void Human::_meleeAttack(const std::string& target) const {
    std::cout << _name << " headbutts " << target << std::endl;
}

void Human::_rangedAttack(const std::string& target) const {
    std::cout << _name << " throws a rock at " << target << std::endl;
}

void Human::_intimidatingShout(const std::string& target) const {
    std::cout << _name << " intimidates " << target
              << " with a deafening shout" << std::endl;
}
