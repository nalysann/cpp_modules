#include <iostream>

#include "Contact.hpp"

const std::string& Contact::get_first_name() const {
    return _first_name;
}

const std::string& Contact::get_last_name() const {
    return _last_name;
}

const std::string& Contact::get_nickname() const {
    return _nickname;
}

const std::string& Contact::get_login() const {
    return _login;
}

const std::string& Contact::get_postal_address() const {
    return _postal_address;
}

const std::string& Contact::get_email_address() const {
    return _email_address;
}

const std::string& Contact::get_phone_number() const {
    return _phone_number;
}

const std::string& Contact::get_birthday_date() const {
    return _birthday_date;
}

const std::string& Contact::get_favorite_meal() const {
    return _favorite_meal;
}

const std::string& Contact::get_underwear_color() const {
    return _underwear_color;
}

const std::string& Contact::get_darkest_secret() const {
    return _darkest_secret;
}

void Contact::set_first_name(const std::string& first_name) {
    _first_name = first_name;
}

void Contact::set_last_name(const std::string& last_name) {
    _last_name = last_name;
}

void Contact::set_nickname(const std::string& nickname) {
    _nickname = nickname;
}

void Contact::set_login(const std::string& login) {
    _login = login;
}

void Contact::set_postal_address(const std::string& postal_address) {
    _postal_address = postal_address;
}

void Contact::set_email_address(const std::string& email_address) {
    _email_address = email_address;
}

void Contact::set_phone_number(const std::string& phone_number) {
    _phone_number = phone_number;
}

void Contact::set_birthday_date(const std::string& birthday_date) {
    _birthday_date = birthday_date;
}

void Contact::set_favorite_meal(const std::string& favorite_meal) {
    _favorite_meal = favorite_meal;
}

void Contact::set_underwear_color(const std::string& underwear_color) {
    _underwear_color = underwear_color;
}

void Contact::set_darkest_secret(const std::string& darkest_secret) {
    _darkest_secret = darkest_secret;
}

bool Contact::is_empty() const {
    return _first_name.empty() && _last_name.empty() && _nickname.empty();
}

std::istream& operator>>(std::istream& is, Contact& contact) {
    std::string input;

    std::cout << "Enter first name: ";
    getline(is, input);
    contact.set_first_name(input);

    std::cout << "Enter last name: ";
    getline(is, input);
    contact.set_last_name(input);

    std::cout << "Enter nickname: ";
    getline(is, input);
    contact.set_nickname(input);

    std::cout << "Enter login: ";
    getline(is, input);
    contact.set_login(input);

    std::cout << "Enter postal address: ";
    getline(is, input);
    contact.set_postal_address(input);

    std::cout << "Enter email address: ";
    getline(is, input);
    contact.set_email_address(input);

    std::cout << "Enter phone number: ";
    getline(is, input);
    contact.set_phone_number(input);

    std::cout << "Enter birthday date: ";
    getline(is, input);
    contact.set_birthday_date(input);

    std::cout << "Enter favorite meal: ";
    getline(is, input);
    contact.set_favorite_meal(input);

    std::cout << "Enter underwear color: ";
    getline(is, input);
    contact.set_underwear_color(input);

    std::cout << "Enter darkest secret: ";
    getline(is, input);
    contact.set_darkest_secret(input);

    return is;
}

std::ostream& operator<<(std::ostream& os, const Contact& contact) {
    return os << "First name: " << contact.get_first_name() << std::endl
              << "Last name: " << contact.get_last_name() << std::endl
              << "Nickname: " << contact.get_nickname() << std::endl
              << "Login: " << contact.get_login() << std::endl
              << "Postal address: " << contact.get_postal_address() << std::endl
              << "Email address: " << contact.get_email_address() << std::endl
              << "Phone number: " << contact.get_phone_number() << std::endl
              << "Birthday date: " << contact.get_birthday_date() << std::endl
              << "Favorite meal: " << contact.get_favorite_meal() << std::endl
              << "Underwear color: " << contact.get_underwear_color() << std::endl
              << "Darkest secret: " << contact.get_darkest_secret();
}
