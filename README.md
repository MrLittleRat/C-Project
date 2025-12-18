# C-Project
A C++ project about students books, verified students books by Ministry of education and booksellers, who sell those students books. The user must choose between various of options in the starting menu (for instance: add new students books, add new booksellers etc.).

There are three main classes:
1. Class studentsBook - a class for the students books
2. Class verifiedStudentsBook - a class for the verified students books
3. Class booksellers - a class for booksellers

The objects are being contained dynamically via vectors (we use vector of pointers of type booksellers and vector of pointers of type studentsBook for the regular students books and the verified ones). To contain both the verified students books and the non-verified ones, we use polymorphism. 

Main menu:
By starting the program, the user is send to the main menu, via function. That function contain every option in the program. The user must choose between those options. If the user enters something wrong (for example: a string of words or a number below/above the range of options), a text message pops up for the specific error. The two vectors, holding the different object are also being held in that function. If the user chooses to exit from the program, the objects in the vectors are being deleted and the vectors themselves are cleared. 

Saving information for the objects:
The information for every object of students books and booksellers are being stored in a text files, using functions to write into two different text files: "books.txt" and "sellers.txt". 

Handling errors:
To keep the program in the best possible condition, we use different types of exceptions. For instance: in the function menu, we use stringstream to check if the user enters more than one option or if he enters an option at all. Other example we can use is the function enteringBooks. Here, the user is asked to enter a whole number (integer) for the edition of the specified book. If the user enters anything besides an integer, the program handles upcomming error by using a try-catch block. Within that block, is used a built-in function called stoi (string to int). If that function failes, the program knows it has to go to the catch part and display the given message.
