#include <iostream>

#include "Contact.hpp"

bool Contact::is_empty() const {
    return first_name.empty() && last_name.empty() && nickname.empty();
}

std::istream& operator>>(std::istream& is, Contact& contact) {
    std::cout << "Enter first name: ";
    getline(std::cin, contact.first_name);

    std::cout << "Enter last name: ";
    getline(std::cin, contact.last_name);

    std::cout << "Enter nickname: ";
    getline(std::cin, contact.nickname);

    std::cout << "Enter login: ";
    getline(std::cin, contact.login);

    std::cout << "Enter postal address: ";
    getline(std::cin, contact.postal_address);

    std::cout << "Enter email address: ";
    getline(std::cin, contact.email_address);

    std::cout << "Enter phone number: ";
    getline(std::cin, contact.phone_number);

    std::cout << "Enter birthday date: ";
    getline(std::cin, contact.birthday_date);

    std::cout << "Enter favorite meal: ";
    getline(std::cin, contact.favorite_meal);

    std::cout << "Enter underwear color: ";
    getline(std::cin, contact.underwear_color);

    std::cout << "Enter darkest secret: ";
    getline(std::cin, contact.darkest_secret);

    return is;
}

std::ostream& operator<<(std::ostream& os, const Contact& contact) {
    return os << "First name: " << contact.first_name << std::endl
              << "Last name: " << contact.last_name << std::endl
              << "Nickname: " << contact.nickname << std::endl
              << "Login: " << contact.login << std::endl
              << "Postal address: " << contact.postal_address << std::endl
              << "Email address: " << contact.email_address << std::endl
              << "Phone number: " << contact.phone_number << std::endl
              << "Birthday date: " << contact.birthday_date << std::endl
              << "Favorite meal: " << contact.favorite_meal << std::endl
              << "Underwear color: " << contact.underwear_color << std::endl
              << "Darkest secret: " << contact.darkest_secret;
}
