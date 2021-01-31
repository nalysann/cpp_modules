#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

struct Contact {
    bool is_empty() const;

    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string login;
    std::string postal_address;
    std::string email_address;
    std::string phone_number;
    std::string birthday_date;
    std::string favorite_meal;
    std::string underwear_color;
    std::string darkest_secret;
};

std::istream& operator>>(std::istream& is, Contact& contact);
std::ostream& operator<<(std::ostream& os, const Contact& contact);

#endif
