#ifndef CENTRAL_BUREAUCRACY_HPP
#define CENTRAL_BUREAUCRACY_HPP

#include "Bureaucrat.hpp"
#include "OfficeBlock.hpp"

class CentralBureaucracy {
  public:
    CentralBureaucracy();
    CentralBureaucracy(const CentralBureaucracy& other);
    CentralBureaucracy& operator=(const CentralBureaucracy& other);
    ~CentralBureaucracy();

    void feedBureaucrat(const Bureaucrat* bureaucrat);
    void queueUp(const std::string& name);
    void doBureaucracy();

  private:
    struct TargetList {
        TargetList(const std::string& name, TargetList* node);

        const std::string _name;
        TargetList* next;
    };

    void _addTarget(TargetList* target);
    void _recycleInterns();
    void _recycleTargets();

    static const size_t NUM_BLOCKS = 20;

    OfficeBlock _blocks[NUM_BLOCKS];
    size_t _cur_block;
    TargetList* _targets;
    TargetList* _last_target;
};

#endif
