// Kursov Proekt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <exception>
#include <regex>
#include <fstream>
#include <limits>
#include "bookseller.h"
#include "studentsBook.h"
#include "verifiedStudentsBook.h"

class ErrorMessage : public std::exception {
private:
    std::string message;
public:
    ErrorMessage(const std::string& message) : message(message) {}

    const char* what() const noexcept override{
        return message.c_str();
    }
};


bool equalsIgnoreCase(const std::string& input,const std::string& canvas) {
    if (input.size() != canvas.size()) return false;
    for (int i = 0; i < input.size(); i++) {
        if (std::tolower(input[i]) != std::tolower(canvas[i])) return false;
    }
    return true;
}

bool fileExists(const std::string& name) {
    std::ifstream f(name.c_str());

    return f.good();
}

std::ostream& operator<<(std::ostream& os, const studentsBook& book) {
    book.printInfo(os);
    return os;
}

void enteringBooks(std::vector<studentsBook*>& books) {
    
    int currentCount = 0;
    while (true) {
        
        std::string book;
        std::string choice;
        std::cout << "Is the book verified (Yes/No): ";
        std::cin >> choice;
        bool isUnique = true;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        try {
            if (equalsIgnoreCase(choice, "no")) {
                std::cout << "Enter title, author, edition, isbn, date, circulation and price: ";
                std::getline(std::cin, book);
                std::vector<std::string> parts;
                std::string part;
                std::stringstream ss(book);
                

                while (ss >> part) {
                    parts.push_back(part);
                }

                if (parts.size() != 7) {
                    throw ErrorMessage("Error! Your book must have exactly 7 values! You have entered " + std::to_string(parts.size()) + ".");
                    continue;
                }

                std::string newISBN = parts[3];
                for (int i = 0; i < books.size(); i++) {
                    if (books[i]->getIsbn() == newISBN) {
                        std::cout << "\nBook is already in the list!\n";
                        isUnique = false;
                        break;
                    }
                }

                

                std::string title = parts[0];
                std::string author = parts[1];
                int edition;
                try {
                    edition = stoi(parts[2]);
                }
                catch (...) {
                    std::cout << "Error with edition! Try again\n";
                    continue;
                }
                std::string isbn = parts[3];
                std::string date = parts[4];
                int circulation;
                try {
                    circulation = stoi(parts[5]);
                }
                catch (...) {
                    std::cout << "Error with circulation! Try again\n";
                    continue;
                }
                double price;
                try {
                    price = stod(parts[6]);
                }
                catch (...) {
                    std::cout << "Error with price! Try again\n";
                    continue;
                }

                if (isUnique) {
                    books.push_back(new studentsBook(title, author, edition, isbn, date, circulation, price));
                    currentCount++;
                }

                isUnique = true;
                

            }
            else if (equalsIgnoreCase(choice, "yes")) {
                std::cout << "Enter title, author, edition, isbn, date, circulation, price and validation date: ";
                std::getline(std::cin, book);
                std::vector<std::string> parts;
                std::string part;
                std::stringstream ss(book);

                while (ss >> part) {
                    parts.push_back(part);
                }

                if (parts.size() != 8) {
                    throw ErrorMessage("Error! Your book must have exactly 8 values! You have entered " + std::to_string(parts.size()) + ".");
                    continue;
                }

                std::string newISBN = parts[3];
                for (int i = 0; i < books.size(); i++) {
                    if (books[i]->getIsbn() == newISBN) {
                        std::cout << "\nBook is already in the list!\n";
                        isUnique = false;
                        break;
                    }
                }

                std::string title = parts[0];
                std::string author = parts[1];
                int edition;
                try {
                    edition = stoi(parts[2]);
                }
                catch (...) {
                    std::cout << "Error with edition! Try again\n";
                    continue;
                }
                std::string isbn = parts[3];
                std::string date = parts[4];
                int circulation;
                try {
                    circulation = stoi(parts[5]);
                }
                catch (...) {
                    std::cout << "Error with circulation! Try again\n";
                    continue;
                }
                double price;
                try {
                    price = stod(parts[6]);
                }
                catch (...) {
                    std::cout << "Error with price! Try again\n";
                    continue;
                }

                std::string validationDate = parts[7];

                if (isUnique) {
                    books.push_back(new verifiedStudentsBook(title, author, edition, isbn, date, circulation, price, validationDate));
                    currentCount++;
                }

                isUnique = true;
                
            }
            else if (equalsIgnoreCase(choice, "exit")) {
                std::cout << "Exiting program.\n";
                break;
            }
            else {
                std::cout << "Invalid command, please try again or type exit.";
            }
        }
        catch (const ErrorMessage& e) {
            std::cout << e.what() << std::endl;
            continue;
        }
        
    }
    std::cout << currentCount << " new books added. Total books: " << books.size() << std::endl;

}

void enteringBookSellers(std::vector<bookseller*>& booksellers) {
    int currentCountOfBooksellers = 0;
    bool isUnique = true;
    while (true) {
        std::cout << "Enter the booksellers name, address and phone number (type exit to stop): ";
        std::string booksellerInfo;
        std::getline(std::cin, booksellerInfo);
        std::vector<std::string> booksellerParts;
        std::string sellerPart;
        std::stringstream ss(booksellerInfo);
        if (equalsIgnoreCase(booksellerInfo, "exit")) {
            std::cout << "Exiting program.\n";
            break;
        }
        while (ss >> sellerPart) {
            booksellerParts.push_back(sellerPart);
        }

        if (booksellerParts.size() != 3) {
            std::cout << "Error! The bookseller must have exactly 3 values! You have enterd " << booksellerParts.size() << ".";
            continue;
        }

        std::string name = booksellerParts[0];
        std::string address = booksellerParts[1];
        
        if (booksellers.size() != 0) {
            for (auto& seller : booksellers) {
                if (seller->getAddress() == address) {
                    std::cout << "Address already exists! Cannot add this seller.\n";
                    isUnique = false;
                    continue;
                }

            }
        }

        std::regex RegExNum("^(?:0\\d{9}|\\+359\\d{9})$");
        if (std::regex_match(booksellerParts[2], RegExNum)) {
            std::string phoneNum = booksellerParts[2];
            if (booksellers.size() != 0) {
                for (auto& seller : booksellers) {
                    if (seller->getPhoneNum() == phoneNum) {
                        std::cout << "Phone Number already exists! Cannot add this seller.\n";
                        isUnique = false;
                        continue;
                    }
                    
                }
            }
            if (isUnique) {
                booksellers.push_back(new bookseller(name, address, phoneNum));
                currentCountOfBooksellers++;
            }
            
        }
        else {
            std::string phoneNum;
            while (!std::regex_match(booksellerParts[2], RegExNum)) {
                std::cout << "Invalid phone number! Try again: ";
                
                std::cin >> phoneNum;
                booksellerParts[2] = phoneNum;
            }
            booksellers.push_back(new bookseller(name, address, phoneNum));
            currentCountOfBooksellers++;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        isUnique = true;

    }

    std::cout << currentCountOfBooksellers << " new booksellers added. Total booksellers: " << booksellers.size() << std::endl;

}

void calculateBooksPrice(std::vector<bookseller*> booksellers, std::vector<studentsBook*> studentsBooks) {

    if (studentsBooks.size() == 0) {
        std::cout << "You have 0 books to work with.\nReturning to main menu...\n";
        return;
    }

    if (booksellers.size() == 0) {
        std::cout << "You have 0 booksellers to work with.\nReturning to main menu...\n";
        return;
    }


    std::cout << "Enter one of the following booksellers, to work with: " << std::endl;

    for (bookseller* seller : booksellers) {
        std::cout << "\n----------------------------------------------------------------------------" << std::endl;
        seller->printInfo(std::cout);
        std::cout << "\n----------------------------------------------------------------------------" << std::endl;
    }

    std::string name;
    bookseller* chosenSeller = nullptr;
    
    while (true) {
        std::cin >> name;
        for (bookseller* seller : booksellers) {
            if (equalsIgnoreCase(seller->getName(), name)) {
                chosenSeller = seller;
                std::cout << "\nSeller found!" << std::endl;
            }
        }

        if (!chosenSeller) {
            std::cout << "\nSeller is not found! Please, try again: ";
        }
        else {
            break;
        }

    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter the belonging books to the bookseller: " << std::endl;
    
    for (studentsBook* book : studentsBooks) {
        std::cout << "\n----------------------------------------------------------------------------" << std::endl;
        std::cout << *book;
    }

    std::cout << "\n";
    std::string bookNumbers;
    std::vector<int> convertedNumParts;

    while (true) {
        std::getline(std::cin, bookNumbers);
        std::stringstream ss(bookNumbers);
        convertedNumParts.clear();
        int temp = 0;
        bool flag = true;

        while (ss >> temp) {
            convertedNumParts.push_back(temp);
        }

        if (convertedNumParts.size() == 0) {
            std::cout << "You must enter at least one book to continue!\n";
            continue;
        }

        for (int i = 0; i < convertedNumParts.size(); i++) {
            if (convertedNumParts[i] > studentsBooks.size()) {
                std::cout << ("Your numbers must be below the number of books! Try again.\n");
                flag = false;
                break;
            }
            if (convertedNumParts[i] <= 0) {
                std::cout << "Your numbers must be above 0! Try again.\n";
                flag = false;
                break;
            }
        }

        if (flag) {
            break;
        }
        else {
            std::cout << "\nAn error occured, please try again entering your books.\n";
        }

    }

    double price = 0;
    int index = 0;
    while(index<convertedNumParts.size()){
        
        studentsBook* book = studentsBooks.at(convertedNumParts[index]-1);
        int quantity = 0;
        
        while (true) {
            std::cout << "Enter the quantity for " << book->getTitle() << ": ";
            
            if (std::cin >> quantity) {
                if (quantity > 0) {
                    break;
                }
                else {
                    std::cout << "Quantity cannot be below or equal to 0! Try again.\n";
                }
            }
            else {
                std::cout << "Invalid input! You must enter a number above 0.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            }
        }
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        index++;
        price += book->getPrice() * quantity;
    }
    std::cout << "\nPrice is: " << price << std::endl;

}

void writeBooks(std::vector<studentsBook*> books) {
    

    std::string filename = "books.txt";
    if (books.size() == 0) {
        std::cout << "There are no books to be written in a file!";
        return;
    }

    if(fileExists(filename)){
        std::cout << "Adding books to existing file\n";
    }
    else {
        std::cout << "Creating file for books\n";
    }

    std::ofstream file(filename, std::ios::app);

    if (file.is_open()) {
        for (auto& book : books) {
            book->printInfo(file);
        }
        file.close();
        std::cout << "Data written successfully.\n";
        file.close();
        std::cout << "File closed.\n";
    }
    else {
        std::cerr << "Error opening file.\n";
    }

}

void writeSellers(std::vector<bookseller*> sellers) {
    std::string filename = "sellers.txt";

    if (sellers.size() == 0) {
        std::cout << "There are no sellers to be written in a file.\n";
        return;
    }
    if (fileExists(filename)) {
        std::cout << "Adding sellers to existing file\n";
    }
    else {
        std::cout << "Creating file for sellers\n";
    }

    std::ofstream file(filename, std::ios::app);

    if (file.is_open()) {
        for (auto& seller : sellers) {
            seller->printInfo(file);
        }
        std::cout << "Data written successfully.\n";
        file.close();
        std::cout << "File closed.\n";
    }
    else {
        std::cerr << "Error opening file.\n";
    }

}

void readBooks() {
    std::string line;
    std::string filename = "books.txt";
    if (!fileExists(filename)) {
        std::cerr << "File does not exist!";
        return;
    }
    std::ifstream file(filename);

    while (getline(file, line)) {
        std::cout << line << std::endl;
    }

    std::cout << "\nClosing file.\n";
    file.close();
}

void readSellers() {
    std::string line;
    std::string filename = "sellers.txt";
    if (!fileExists(filename)) {
        std::cerr << "File does not exist!";
        return;
    }

    std::ifstream file(filename);

    while (getline(file, line)) {
        std::cout << line << std::endl;
    }

    std::cout << "\nClosing file.\n";
    file.close();
}

void menu() {
    bool running = true;
    std::vector<studentsBook*> books;
    std::vector<bookseller*> booksellers;

    while (running) {
        std::cout << "\n------------------------------------------------MENU--------------------------------------------------\n";
        std::cout << "----------------------------Enter one of the following options to proceed:----------------------------\n";
        std::cout << "1. Exit program.\n";
        std::cout << "2. Enter books.\n";
        std::cout << "3. Enter booksellers.\n";
        std::cout << "4. Check price of books for current bookseller.\n";
        std::cout << "5. Print books info\n";
        std::cout << "6. Print booksellers info.\n";
        std::cout << "7. Write current books into a file.\n";
        std::cout << "8. Write current sellers into a file.\n";
        std::cout << "9. Read books from books file.\n";
        std::cout << "10. Read sellers from sellers file.\n";
        std::cout << "--------------------------------------------------------------------------------------------------------\n";

        std::string option;
        std::getline(std::cin, option);

        std::stringstream ss(option);
        int choice = -1;

        if(ss >> choice) {

            char additionalArguments;
            if (ss >> additionalArguments) {
                std::cout << "You should enter only one argument!\n";
                choice = -1;
            }
        }

        switch (choice) {
        case 1:
            std::cout << "\nExiting program...\n";
            std::cout << "Deleting books...\n";
            for (auto& book : books) {
                delete book;
            }
            books.clear();
            std::cout << "Books deleted successfully!\n";
            std::cout << "Deleting sellers...\n";
            for (auto& seller : booksellers) {
                delete seller;
            }
            booksellers.clear();
            std::cout << "Sellers deleted successully!\n";
            running = false;
            break;
        case 2:
            enteringBooks(books);
            break;
        case 3:
            enteringBookSellers(booksellers);
            break;
        case 4:
            calculateBooksPrice(booksellers, books);
            break;
        case 5:

            for (auto& book : books) {
                
                book->printInfo(std::cout);
            }
            break;
        case 6:
            for (auto& seller : booksellers) {
                seller->printInfo(std::cout);
            }
            break;
        case 7:
            writeBooks(books);
            break;
        case 8:
            writeSellers(booksellers);
            break;
        case 9:
            readBooks();
            break;
        case 10:
            readSellers();
            break;
        default:
            std::cout << "\nYou must enter a number between 1 and 10!\n";
            break;
        }

    }
}
int main()
{
    menu();
}