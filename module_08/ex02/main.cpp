#include <iostream>
#include <list>
#include <stack>

#include "mutantstack.hpp"

int main() {
    {
        std::list<int> list;

        list.push_back(5);
        list.push_back(17);

        std::cout << list.back() << std::endl;

        list.pop_back();

        std::cout << list.size() << std::endl;

        list.push_back(3);
        list.push_back(5);
        list.push_back(737);
        list.push_back(42);
        list.push_back(0);

        std::list<int>::iterator it = list.begin();
        std::list<int>::iterator ite = list.end();

        ++it;
        --it;

        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }

        std::list<int> s(list);
    }

    std::cout << std::endl;

    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << std::endl;

        mstack.pop();

        std::cout << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(42);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;

        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }

        std::stack<int> s(mstack);

        std::cout << std::endl;

        MutantStack<int>::const_iterator cit = mstack.cbegin();
        MutantStack<int>::const_iterator cite = mstack.cend();

        ++cit;
        --cit;

        while (cit != cite) {
            std::cout << *cit << std::endl;
            ++cit;
        }

        std::cout << std::endl;

        MutantStack<int>::reverse_iterator rit = mstack.rbegin();
        MutantStack<int>::reverse_iterator rite = mstack.rend();

        ++rit;
        --rit;

        while (rit != rite) {
            std::cout << *rit << std::endl;
            ++rit;
        }

        std::cout << std::endl;

        MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
        MutantStack<int>::const_reverse_iterator crite = mstack.rend();

        ++crit;
        --crit;

        while (crit != crite) {
            std::cout << *crit << std::endl;
            ++crit;
        }
    }
}
