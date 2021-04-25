#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>

#include "Bureaucrat.hpp"
#include "CentralBureaucracy.hpp"

int main() {
    srand(time(NULL));

    CentralBureaucracy cb;

    const size_t BUREAUCRACY_LEVEL = 20;
    Bureaucrat* bureaucrats[BUREAUCRACY_LEVEL];

    for (size_t i = 0; i < BUREAUCRACY_LEVEL; ++i) {
        bureaucrats[i] = new Bureaucrat("Chad", Bureaucrat::MAX_GRADE);
        cb.feedBureaucrat(bureaucrats[i]);
    }

    const size_t LINE_SIZE = 100;

    for (size_t i = 1; i <= LINE_SIZE; ++i) {
        std::ostringstream oss;
        oss << "target " << i;
        cb.queueUp(oss.str());
    }

    cb.doBureaucracy();

    for (size_t i = 0; i < BUREAUCRACY_LEVEL; ++i) {
        delete bureaucrats[i];
    }
}
