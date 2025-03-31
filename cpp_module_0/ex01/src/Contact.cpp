#include "../include/Contact.hpp"

// Constructor
Contact::Contact()
{
};

// Getters

std::string	Contact::getFirstName() const{
	return (firstName);
};

std::string	Contact::getLastName() const{
	return (lastName);
};

std::string	Contact::getNickName() const{
	return (nickName);
};

std::string	Contact::getPhoneNumber() const{
	return (phoneNumber);
};

std::string	Contact::getDarkestSecret() const{
	return (darkestSecret);
};

// Setter

void	Contact::setFirstName(std::string firstName){
	this->firstName = firstName;
};

void	Contact::setLastName(std::string lastName){
	this->lastName = lastName;
};

void	Contact::setNickname(std::string nickName){
	this->nickName = nickName;
};

void	Contact::setPhoneNumber(std::string phoneNumber){
	this->phoneNumber = phoneNumber;
};

void	Contact::setDarkestSecret(std::string darkestSecret){
	this->darkestSecret = darkestSecret;
};
