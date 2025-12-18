#pragma once
#include <iostream>
#include <string>
#include "studentsBook.h"


class verifiedStudentsBook : public studentsBook {
private:
    std::string validationDate;
public:

    verifiedStudentsBook();
    verifiedStudentsBook(std::string title, std::string author, int edition, std::string isbn, std::string date, int circulation, double price, std::string validationDate);

    void setValidationDate(std::string validationDate);
    std::string getValidationDate();

    virtual void printInfo(std::ostream& os) const  override;

    ~verifiedStudentsBook();
};