#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace Product
{
    class Book;
    class Food;
}

namespace User
{
    class Student // Student = Person
    {
    public:
        static vector<Student*> ALL_CREATED_USER;
        string student_name; // USER SHOULD SPECIFY.
        int Age; // USER SHOULD SPECIFY.
        float totalPrice = 0.0; // Firstly We have to 
        int MAX_ALLOWED_BOOKS = 2; // MAX_ALLOWED_BOOKS defaultly is 2
        vector<Product::Book*> taken_books; // Holds Book object in vector.
        vector<Product::Food*> ordered_foods; // Holds Food object in vector.

        
        Student(string student_name, int Age); // OVERRIDING.
        Student(string student_name, int Age , float totalPrice ,  int MAX_ALLOWED_BOOK); // OVERRIDING.

        void takeBook(Product::Book* choosen_book);
        void orderFood(Product::Food* ordered_food);

        bool canTakeBook(Product::Book* choosen_book); // Checks MAX_ALLOWED_BOOKS, or Allready taked. and books Price.(enough money)
        bool canFoodOrder(Product::Food* ordered_food); // Checks User Has enough money to order something. 

        void addMoney(float money);
    };
}
