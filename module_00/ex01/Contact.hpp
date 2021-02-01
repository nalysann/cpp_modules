#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
  public:
    const std::string& get_first_name() const;
    const std::string& get_last_name() const;
    const std::string& get_nickname() const;
    const std::string& get_login() const;
    const std::string& get_postal_address() const;
    const std::string& get_email_address() const;
    const std::string& get_phone_number() const;
    const std::string& get_birthday_date() const;
    const std::string& get_favorite_meal() const;
    const std::string& get_underwear_color() const;
    const std::string& get_darkest_secret() const;

    void set_first_name(const std::string& first_name);
    void set_last_name(const std::string& last_name);
    void set_nickname(const std::string& nickname);
    void set_login(const std::string& login);
    void set_postal_address(const std::string& postal_address);
    void set_email_address(const std::string& email_address);
    void set_phone_number(const std::string& phone_number);
    void set_birthday_date(const std::string& birthday_date);
    void set_favorite_meal(const std::string& favorite_meal);
    void set_underwear_color(const std::string& underwear_color);
    void set_darkest_secret(const std::string& darkest_secret);

    bool is_empty() const;

  private:
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _login;
    std::string _postal_address;
    std::string _email_address;
    std::string _phone_number;
    std::string _birthday_date;
    std::string _favorite_meal;
    std::string _underwear_color;
    std::string _darkest_secret;
};

std::istream& operator>>(std::istream& is, Contact& contact);
std::ostream& operator<<(std::ostream& os, const Contact& contact);

#endif
