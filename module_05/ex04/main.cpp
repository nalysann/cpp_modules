#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int main() {
    {
        Intern idiot_one;
        Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
        Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
        OfficeBlock ob;

        ob.setIntern(&idiot_one);
        ob.setSigner(&bob);
        ob.setExecutor(&hermes);

        ob.doBureaucracy("mutant pig termination", "Pigley");
    }

    std::cout << std::endl;

    {
        OfficeBlock ob;

        try {
            ob.doBureaucracy("mutant pig termination", "Pigley");
        } catch (OfficeBlock::MissingInternException&) {
            std::cout << "Intern is missing in the office block..." << std::endl;
        }

        Intern noname;
        ob.setIntern(&noname);

        try {
            ob.doBureaucracy("mutant pig termination", "Pigley");
        } catch (OfficeBlock::MissingSignerException&) {
            std::cout << "Signer is missing in the office block..." << std::endl;
        }

        Bureaucrat cheems("Cheems", Bureaucrat::MIN_GRADE);
        ob.setSigner(&cheems);

        try {
            ob.doBureaucracy("mutant pig termination", "Pigley");
        } catch (OfficeBlock::MissingExecutorException&) {
            std::cout << "Executor is missing in the office block..." << std::endl;
        }

        Bureaucrat swole("Swole", Bureaucrat::MAX_GRADE);
        ob.setExecutor(&swole);

        try {
            ob.doBureaucracy("mutant pig termination", "Pigley");
        } catch (OfficeBlock::SignerJobException&) {
            std::cout << "Signer failed at his job, this incident will be reported!" << std::endl;
        }

        ob.setSigner(&swole);
        ob.setExecutor(&cheems);

        try {
            ob.doBureaucracy("mutant pig termination", "Pigley");
        } catch (OfficeBlock::ExecutorJobException&) {
            std::cout << "Executor failed at his job, this incident will be reported!" << std::endl;
        }

        ob.setExecutor(&swole);

        ob.doBureaucracy("mutant pig termination", "Pigley");

        try {
            ob.doBureaucracy("total extermination", "Humanity");
        } catch (OfficeBlock::InternJobException&) {
            std::cout << "Once again the intern proved his uselessness..." << std::endl;
        }
    }
}
