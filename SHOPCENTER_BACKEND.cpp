#include "SHOPCENTER_BACKEND.h"
#include "USER_BACKEND.h"
#include "PRODUCT_BACKEND.h"
#include <string>

using namespace std;

using namespace Product;


ShopCenter::SHOP_STATUS ShopCenter::SHOPPING_STATUS = ShopCenter::SHOP_STATUS::OFF_DAY;


vector<ShopCenter::BookSeller*> ShopCenter::ALL_BOOK_SELLERS;
vector<ShopCenter::FoodSeller*> ShopCenter::ALL_FOOD_SELLERS;

ShopCenter::BookSeller::BookSeller(string seller)
{
	SELLER_STATUS = ShopCenter::SHOP_STATUS::OFF_DAY;
	this->seller_name = seller;
	ShopCenter::ALL_BOOK_SELLERS.push_back(this);
}

void ShopCenter::BookSeller::SellBook(Product::Book* book, User::Student* buyer)
{
	int ct = 0;
	bool Founded = false;
	for (Product::Book* bookIter : AVAILABLE_BOOKS)
	{
		if (bookIter == book)
		{
			Founded = true; break;
		}
		else ct++;
	}
	if (Founded)
	{
		AVAILABLE_BOOKS.erase(AVAILABLE_BOOKS.begin() + ct);
	}
	buyer->takeBook(book); // Checks all conditions in terms of books available, user moneys and etc..
	SELLED_BOOKS.push_back(book);

}
	// Remove from AvailableBooks, add to SELLED_BOOKS.
void ShopCenter::BookSeller::AddStocks(Product::Book* book)
{
	this->AVAILABLE_BOOKS.push_back(book);
}



ShopCenter::FoodSeller::FoodSeller(string seller_name)
{
	this->seller_name = seller_name;
	ShopCenter::ALL_FOOD_SELLERS.push_back(this);
}

void ShopCenter::FoodSeller::AddStocks(Product::Food* food)
{
	AVAILABLE_FOODS.push_back(food);
}

void ShopCenter::FoodSeller::SellFood(Product::Food* selled_food, User::Student* buyer)
{
	int ct = 0;
	bool Founded = false;
	for (Product::Food* foodIter: AVAILABLE_FOODS)
	{
		if (foodIter == selled_food)
		{
			Founded = true; break;
		}
		else ct++;
	}
	if (Founded)
	{
		AVAILABLE_FOODS.erase(AVAILABLE_FOODS.begin() + ct);
	}
	buyer->orderFood(selled_food); // Checks all conditions in terms of books available, user moneys and etc..
	SELLED_FOODS.push_back(selled_food);
	
}


