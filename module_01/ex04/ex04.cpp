#include <iostream>
#include <string>

int main() {
    std::string s("HI THIS IS BRAIN");
    std::string* s_ptr = &s;
    std::string& s_ref = s;

    std::cout << "Direct access: " << s << std::endl
              << "Access via pointer: " << *s_ptr << std::endl
              << "Access via reference: " << s_ref << std::endl;
}
