#include <iostream>
#include <string>
#include "studentsBook.h"
#include "verifiedStudentsBook.h"

verifiedStudentsBook::verifiedStudentsBook() {};
verifiedStudentsBook::verifiedStudentsBook(std::string title, std::string author, int edition, std::string isbn, std::string date, int circulation, double price, std::string validationDate) :
    studentsBook(title, author, edition, isbn, date, circulation, price), validationDate(validationDate) {
}

void verifiedStudentsBook::setValidationDate(std::string validationDate) {
    this->validationDate = validationDate;
}
std::string verifiedStudentsBook::getValidationDate() {
    return this->validationDate;
}

void verifiedStudentsBook::printInfo(std::ostream& os) const {
    studentsBook::printInfo(os);
    os << "Validation Date: " << validationDate << "\n";
    os << "----------------------------------------------------";
}

verifiedStudentsBook::~verifiedStudentsBook() { std::cout << "\nDestructing verified students book object."; }
