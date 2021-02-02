#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
  public:
    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const std::string& getNickname() const;
    const std::string& getLogin() const;
    const std::string& getPostalAddress() const;
    const std::string& getEmailAddress() const;
    const std::string& getPhoneNumber() const;
    const std::string& getBirthdayDate() const;
    const std::string& getFavoriteMeal() const;
    const std::string& getUnderwearColor() const;
    const std::string& getDarkestSecret() const;

    void setFirstName(const std::string& first_name);
    void setLastName(const std::string& last_name);
    void setNickname(const std::string& nickname);
    void setLogin(const std::string& login);
    void setPostalAddress(const std::string& postal_address);
    void setEmailAddress(const std::string& email_address);
    void setPhoneNumber(const std::string& phone_number);
    void setBirthdayDate(const std::string& birthday_date);
    void setFavoriteMeal(const std::string& favorite_meal);
    void setUnderwearColor(const std::string& underwear_color);
    void setDarkestSecret(const std::string& darkest_secret);

    bool isEmpty() const;

  private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _login;
    std::string _postalAddress;
    std::string _emailAddress;
    std::string _phoneNumber;
    std::string _birthdayDate;
    std::string _favoriteMeal;
    std::string _underwearColor;
    std::string _darkestSecret;
};

std::istream& operator>>(std::istream& is, Contact& contact);
std::ostream& operator<<(std::ostream& os, const Contact& contact);

#endif
