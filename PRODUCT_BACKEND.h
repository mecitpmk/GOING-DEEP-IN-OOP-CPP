#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "USER_BACKEND.h"

using namespace std;

//namespace User
//{
//    class Student;
//}

namespace Product
{
    class Book
    {
    public:
        string book_name;
        int n_copies;
        float price;
        vector<User::Student*> taken_student;
        Book(string book_name, int n_copies, float price);

        void addTaker(User::Student* taker_student); // Add student object to taken_student vector.
        //void deleteTaker(User::Student* taker_student); // Delete student form taken_student vector.

        bool increaseCopies(int new_n_copies); // Example : increaseCopies(5) seller bring 5 new book so that n_copies + new_n_copies
        bool isBookAvailable();

    };
    /*vector <Book*> ALL_BOOKS;
    int GET_CREATED_BOOKS_NUM(void)
    {
        return ALL_BOOKS.size();
    }*/
    ///BOOK

    ///FOOD
    class Food
    {
    public:
        string food_name;
        int amount;
        float price;
        Food(string food_name, int amount, float price);
        float calculatePrice(void);
    };
   /* vector <Food*> ALL_FOODS;
    int GET_CREATED_FOODS_NUM(void)
    {
        return ALL_FOODS.size();
    }*/
    ///FOOD
}
