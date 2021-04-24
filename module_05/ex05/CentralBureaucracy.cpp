#include <cstdlib>
#include <string>

#include "CentralBureaucracy.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

CentralBureaucracy::CentralBureaucracy()
        : _blocks()
        , _cur_block(0)
        , _targets(NULL)
        , _last_target(NULL) {}

CentralBureaucracy::~CentralBureaucracy() {
    _recycleInterns();
    _recycleTargets();
}

void CentralBureaucracy::feedBureaucrat(const Bureaucrat* bureaucrat) {
    if (_cur_block == NUM_BLOCKS) {
        std::cout << "Go find yourself another place to make bureaucracy!" << std::endl;
        return;
    }

    if (!_blocks[_cur_block].getIntern()) {
        _blocks[_cur_block].setIntern(new Intern());
    }

    if (!_blocks[_cur_block].getSigner()) {
        _blocks[_cur_block].setSigner(bureaucrat);
    } else {
        _blocks[_cur_block++].setExecutor(bureaucrat);
    }
}

void CentralBureaucracy::queueUp(const std::string& name) {
    _addTarget(new TargetList(name, NULL));
}

void CentralBureaucracy::doBureaucracy() {
    if (!_targets) {
        std::cout << "No targets - no bureaucracy :(" << std::endl;
        return;
    }

    if (_cur_block == 0) {
        std::cout << "No functioning office blocks at the moment :(" << std::endl;
        return;
    }

    TargetList* head = _targets;

    while (head) {
        for (size_t i = 0; i < _cur_block; ++i) {
            try {
                _blocks[i].doBureaucracy(Form::FORM_NAMES[rand() % Form::NUM_FORMS], head->_name);
            } catch (OfficeBlock::MemberJobException&) {
                std::cout << "Office block " << i << " failed at bureaucracy -_-" << std::endl;
            }
        }
        head = head->next;
    }

    _recycleTargets();
}

void CentralBureaucracy::_addTarget(TargetList* target) {
    if (!_targets) {
        _targets = target;
        _last_target = target;
    } else {
        _last_target->next = target;
        _last_target = target;
    }
}

void CentralBureaucracy::_recycleInterns() {
    for (size_t i = 0; i < NUM_BLOCKS; ++i) {
        delete _blocks[i].getIntern();
        _blocks[i].setIntern(NULL);
    }
}

void CentralBureaucracy::_recycleTargets() {
    while (_targets) {
        TargetList* new_head = _targets->next;
        delete _targets;
        _targets = new_head;
    }
    _last_target = NULL;
}

CentralBureaucracy::TargetList::TargetList(const std::string &name, TargetList *node)
        : _name(name)
        , next(node) {}
