#pragma once

class bookseller {
private:
    std::string name;
    std::string address;
    std::string phoneNum;

public:

    bookseller();
    bookseller(std::string name, std::string address, std::string phoneNum);

    void setName(std::string name);
    std::string getName();

    void setAddress(std::string address);
    std::string getAddress();

    void setPhoneNum(std::string phoneNum);
    std::string getPhoneNum();

    void printInfo(std::ostream& os) const;

    ~bookseller();
};