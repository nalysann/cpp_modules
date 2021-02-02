#include <iostream>

#include "Contact.hpp"

const std::string& Contact::getFirstName() const {
    return _firstName;
}

const std::string& Contact::getLastName() const {
    return _lastName;
}

const std::string& Contact::getNickname() const {
    return _nickname;
}

const std::string& Contact::getLogin() const {
    return _login;
}

const std::string& Contact::getPostalAddress() const {
    return _postalAddress;
}

const std::string& Contact::getEmailAddress() const {
    return _emailAddress;
}

const std::string& Contact::getPhoneNumber() const {
    return _phoneNumber;
}

const std::string& Contact::getBirthdayDate() const {
    return _birthdayDate;
}

const std::string& Contact::getFavoriteMeal() const {
    return _favoriteMeal;
}

const std::string& Contact::getUnderwearColor() const {
    return _underwearColor;
}

const std::string& Contact::getDarkestSecret() const {
    return _darkestSecret;
}

void Contact::setFirstName(const std::string& first_name) {
    _firstName = first_name;
}

void Contact::setLastName(const std::string& last_name) {
    _lastName = last_name;
}

void Contact::setNickname(const std::string& nickname) {
    _nickname = nickname;
}

void Contact::setLogin(const std::string& login) {
    _login = login;
}

void Contact::setPostalAddress(const std::string& postal_address) {
    _postalAddress = postal_address;
}

void Contact::setEmailAddress(const std::string& email_address) {
    _emailAddress = email_address;
}

void Contact::setPhoneNumber(const std::string& phone_number) {
    _phoneNumber = phone_number;
}

void Contact::setBirthdayDate(const std::string& birthday_date) {
    _birthdayDate = birthday_date;
}

void Contact::setFavoriteMeal(const std::string& favorite_meal) {
    _favoriteMeal = favorite_meal;
}

void Contact::setUnderwearColor(const std::string& underwear_color) {
    _underwearColor = underwear_color;
}

void Contact::setDarkestSecret(const std::string& darkest_secret) {
    _darkestSecret = darkest_secret;
}

bool Contact::isEmpty() const {
    return _firstName.empty() && _lastName.empty() && _nickname.empty();
}

std::istream& operator>>(std::istream& is, Contact& contact) {
    std::string input;

    std::cout << "Enter first name: ";
    getline(is, input);
    contact.setFirstName(input);

    std::cout << "Enter last name: ";
    getline(is, input);
    contact.setLastName(input);

    std::cout << "Enter nickname: ";
    getline(is, input);
    contact.setNickname(input);

    std::cout << "Enter login: ";
    getline(is, input);
    contact.setLogin(input);

    std::cout << "Enter postal address: ";
    getline(is, input);
    contact.setPostalAddress(input);

    std::cout << "Enter email address: ";
    getline(is, input);
    contact.setEmailAddress(input);

    std::cout << "Enter phone number: ";
    getline(is, input);
    contact.setPhoneNumber(input);

    std::cout << "Enter birthday date: ";
    getline(is, input);
    contact.setBirthdayDate(input);

    std::cout << "Enter favorite meal: ";
    getline(is, input);
    contact.setFavoriteMeal(input);

    std::cout << "Enter underwear color: ";
    getline(is, input);
    contact.setUnderwearColor(input);

    std::cout << "Enter darkest secret: ";
    getline(is, input);
    contact.setDarkestSecret(input);

    return is;
}

std::ostream& operator<<(std::ostream& os, const Contact& contact) {
    return os << "First name: " << contact.getFirstName() << std::endl
              << "Last name: " << contact.getLastName() << std::endl
              << "Nickname: " << contact.getNickname() << std::endl
              << "Login: " << contact.getLogin() << std::endl
              << "Postal address: " << contact.getPostalAddress() << std::endl
              << "Email address: " << contact.getEmailAddress() << std::endl
              << "Phone number: " << contact.getPhoneNumber() << std::endl
              << "Birthday date: " << contact.getBirthdayDate() << std::endl
              << "Favorite meal: " << contact.getFavoriteMeal() << std::endl
              << "Underwear color: " << contact.getUnderwearColor() << std::endl
              << "Darkest secret: " << contact.getDarkestSecret();
}
