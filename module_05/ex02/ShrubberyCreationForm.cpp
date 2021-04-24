#include <fstream>
#include <string>

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
        : Form("Shrubbery Creation Form",
               145,
               137,
               target)
        , _filename(getTarget() + "_shrubbery") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
        : Form(other.getName(),
               other.getSignGrade(),
               other.getExecuteGrade(),
               other.getTarget())
        , _filename(getTarget() + "_shrubbery") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::_action() const {
    std::ofstream ofs(_filename, std::ios::app);

    if (!ofs) {
        throw ShrubberyCreationException();
    }

    ofs << _ascii_tree;
}

const std::string ShrubberyCreationForm::_ascii_tree =
        "                                                           \n"
        "                 ----         -====-                       \n"
        "      --==--   -@@@@=-         ==@@@@-    -=====-          \n"
        "     --===@@@=-@@======-         -==@@= -@@@@@@@@@=-       \n"
        "         -===@@@@@@=@=====    --=====@@=@====-=---  -      \n"
        "     -=@@@@@-=@====@@@=-   -@@@@@@@=@@@@@==-=@@@@@=-       \n"
        "    @@@@@-  -@@@-==---@@= -@@@@==  -@-@@-=@@-  =@@@@@-     \n"
        "   === -    -@@@- -@- --= =@@- -  -@  @@@ =@@@-  --=-@=    \n"
        "            -@@@-   @=     @--   -@- -@@@- =@@@-      @-   \n"
        "             @@@-    =@    -    -@-  -=@@- ==@@=       -   \n"
        "             -==-     =@        @=   -@@=   -@@            \n"
        "                       @=      -@    -@-    ==             \n"
        "                       -@-     @=                          \n"
        "                        @@    -@                           \n"
        "                        =@    @=                           \n"
        "                        =@-  =@                            \n"
        "                        -@= -@-                            \n"
        "                        -@@-@@                             \n"
        "                      --=====--                            \n"
        "                                                           \n";
