#include <iostream>
#include <string>
#include "bookseller.h"


bookseller::bookseller() {};
bookseller::bookseller(std::string name, std::string address, std::string phoneNum) {
    this->name = name;
    this->address = address;
    this->phoneNum = phoneNum;
}

void bookseller::setName(std::string name) { this->name = name; }
std::string bookseller::getName() { return this->name; }

void bookseller::setAddress(std::string address) { this->address = address; }
std::string bookseller::getAddress() { return this->address; }

void bookseller::setPhoneNum(std::string phoneNum) { this->phoneNum = phoneNum; }
std::string bookseller::getPhoneNum() { return this->phoneNum; }

void bookseller::printInfo(std::ostream& os) const {
    os << "----------------------------------------------------";
    os << "\n" << "Name: " << name << "\nAddress: " << address << "\nPhone Number: " << phoneNum;
}

bookseller::~bookseller() { std::cout << "Destructing book seller object."; }
