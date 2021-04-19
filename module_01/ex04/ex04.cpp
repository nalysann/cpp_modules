#include <iostream>
#include <string>

int main() {
    std::string s("HI THIS IS BRAIN");
    std::string* s_ptr = &s;
    std::string& s_ref = s;

    std::cout << "Access via the pointer: " << *s_ptr << std::endl
              << "Access via the reference: " << s_ref << std::endl;
}
