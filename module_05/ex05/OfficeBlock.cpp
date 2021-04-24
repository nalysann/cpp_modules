#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock()
        : _intern(NULL)
        , _signer(NULL)
        , _executor(NULL) {
}

OfficeBlock::OfficeBlock(const Intern* intern,
                         const Bureaucrat* signer,
                         const Bureaucrat* executor)
        : _intern(intern)
        , _signer(signer)
        , _executor(executor) {}

OfficeBlock::~OfficeBlock() {}

const Intern* OfficeBlock::getIntern() const {
    return _intern;
}

const Bureaucrat* OfficeBlock::getSigner() const {
    return _signer;
}

const Bureaucrat* OfficeBlock::getExecutor() const {
    return _executor;
}

void OfficeBlock::setIntern(const Intern* intern) {
    _intern = intern;
}

void OfficeBlock::setSigner(const Bureaucrat* signer) {
    _signer = signer;
}

void OfficeBlock::setExecutor(const Bureaucrat* executor) {
    _executor = executor;
}

void OfficeBlock::doBureaucracy(const std::string& name, const std::string& target) const {
    if (!_intern) {
        throw MissingInternException();
    } else if (!_signer) {
        throw MissingSignerException();
    } else if (!_executor) {
        throw MissingExecutorException();
    }

    Form* some_form = NULL;

    try {
        some_form = _intern->makeForm(name, target);
    } catch (Intern::FormNotFoundException&) {
        delete some_form;
        throw InternJobException();
    }

    try {
        _signer->signForm(*some_form);
    } catch (Bureaucrat::SigningException&) {
        delete some_form;
        throw SignerJobException();
    }

    try {
        _executor->executeForm(*some_form);
    } catch (Bureaucrat::ExecutionException&) {
        delete some_form;
        throw ExecutorJobException();
    }

    delete some_form;
}
