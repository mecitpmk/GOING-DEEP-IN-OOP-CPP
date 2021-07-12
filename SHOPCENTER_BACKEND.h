#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "PRODUCT_BACKEND.h"
using namespace std;

//namespace Product
//{
//    class Book;
//    class Food;
//}
//namespace User
//{
//    class Student;
//}

namespace ShopCenter
{
    ///BOOK

    typedef enum
    {
        ON_DAY,
        OFF_DAY
    }SHOP_STATUS;
    extern SHOP_STATUS SHOPPING_STATUS;

    class BookSeller
    {
    public:
        string seller_name;
        SHOP_STATUS SELLER_STATUS = ON_DAY;
        vector<Product::Book*> AVAILABLE_BOOKS; // Not selled yet books.
        vector<Product::Book*> SELLED_BOOKS; // When book sells from this shopcenter , append this vector.
        BookSeller(string seller);

        void SellBook(Product::Book* book, User::Student* buyer); // Remove from AvailableBooks, add to SELLED_BOOKS.
        void AddStocks(Product::Book* book);

    };
    extern vector<ShopCenter::BookSeller*> ALL_BOOK_SELLERS; // NORMALLY I CAN ADD THIS VECTOR
                                                                // INTO CLASS AS A STATIC BUT TO IMPROVE CODING SKILLS
                                                                    // I PREFER THAT WAY

    class FoodSeller
    {
    public:
        string seller_name;
        SHOP_STATUS SELLER_STATUS = ON_DAY;
        vector<Product::Food*> AVAILABLE_FOODS;
        vector<Product::Food*> SELLED_FOODS;
        FoodSeller(string seller);
        void SellFood(Product::Food* selled_food, User::Student* buyer);
        void AddStocks(Product::Food* food);
    };
    extern vector<FoodSeller*> ALL_FOOD_SELLERS; // NORMALLY I CAN ADD THIS VECTOR 
                                                                // INTO CLASS AS A STATIC BUT TO IMPROVE CODING SKILLS
                                                                    // I PREFER THAT WAY

}
