#include "studentsBook.h"


studentsBook::studentsBook() {};
studentsBook::studentsBook(std::string title, std::string author, int edition, std::string isbn, std::string date, int circulation, double price) {
    this->title = title;
    this->author = author;
    this->edition = edition;
    this->isbn = isbn;
    this->date = date;
    this->circulation = circulation;
    this->price = price;
}

void studentsBook::setTitle(std::string title) { this->title = title; }
std::string studentsBook::getTitle() { return this->title; }

void studentsBook::setAuthor(std::string author) { this->author = author; }
std::string studentsBook::getAuthor() { return this->author; }

void studentsBook::setEdition(int edition) { this->edition = edition; }
int studentsBook::getEdition() { return this->edition; }

void studentsBook::setIsbn(std::string isbn) { this->isbn = isbn; }
std::string studentsBook::getIsbn() { return this->isbn; }

void studentsBook::setDate(std::string date) { this->date = date; }
std::string studentsBook::getDate() { return this->date; }

void studentsBook::setCirculation(int circulation) { this->circulation = circulation; }
int studentsBook::getCirculation() { return this->circulation; }

void studentsBook::setPrice(double price) { this->price = price; }
double studentsBook::getPrice() { return this->price; }

void studentsBook::printInfo(std::ostream& os) const {
    os << "----------------------------------------------------";
    os << "\n" << "Title: " << title << "\n" << "Author: " << author << "\n" << "Edition: " << edition << "\n" << "ISBN: " << isbn << "\n" << "Date: " << date << "\n" << "Circulation: " << circulation << "\n" << "Price: " << price << "\n";
}

studentsBook::~studentsBook() { std::cout << "\nDestructing students book object."; }
