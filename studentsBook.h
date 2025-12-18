#pragma once

#include <iostream>
#include <string>

class studentsBook {
private:
    std::string title;
    std::string author;
    int edition;
    std::string isbn;
    std::string date;
    int circulation;
    double price;

public:

    studentsBook();
    studentsBook(std::string title, std::string author, int edition, std::string isbn, std::string date, int circulation, double price);

    void setTitle(std::string title);
    std::string getTitle();

    void setAuthor(std::string author);
    std::string getAuthor();

    void setEdition(int edition);
    int getEdition();

    void setIsbn(std::string isbn);
    std::string getIsbn();

    void setDate(std::string date);
    std::string getDate();

    void setCirculation(int circulation);
    int getCirculation();

    void setPrice(double price);
    double getPrice();

    virtual void printInfo(std::ostream& os) const;

    virtual ~studentsBook();

};