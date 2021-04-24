#ifndef OFFICE_BLOCK_HPP
#define OFFICE_BLOCK_HPP

#include <iostream>
#include <stdexcept>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

class OfficeBlock {
  public:
    class MissingMemberException : public std::exception {};
    class MissingInternException : public MissingMemberException {};
    class MissingSignerException : public MissingMemberException {};
    class MissingExecutorException : public MissingMemberException {};

    class MemberJobException : public std::exception {};
    class InternJobException : public MemberJobException {};
    class SignerJobException : public MemberJobException {};
    class ExecutorJobException : public MemberJobException {};

    OfficeBlock();
    OfficeBlock(const Intern* intern,
                const Bureaucrat* signer,
                const Bureaucrat* executor);
    OfficeBlock(const OfficeBlock& other);
    OfficeBlock& operator=(const OfficeBlock& other);
    ~OfficeBlock();

    void setIntern(const Intern* intern);
    void setSigner(const Bureaucrat* signer);
    void setExecutor(const Bureaucrat* executor);

    void doBureaucracy(const std::string& name, const std::string& target) const;

  private:
    const Intern* _intern;
    const Bureaucrat* _signer;
    const Bureaucrat* _executor;
};

#endif
