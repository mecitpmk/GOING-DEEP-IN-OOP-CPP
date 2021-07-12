#include "USER_BACKEND.h"
#include "PRODUCT_BACKEND.h"
#include <string>

using namespace std;

vector<User::Student*> User::Student::ALL_CREATED_USER;


User::Student::Student(string student_name, int Age)
{
	this->student_name = student_name;
	this->Age = Age;
	User::Student::ALL_CREATED_USER.push_back(this);
}

User::Student::Student(string student_name, int Age, float totalPrice = 0.0, int MAX_ALLOWED_BOOK = 2) // OVERRIDING.
{
	this->student_name = student_name;
	this->Age = Age;
	this->totalPrice = totalPrice;
	this->MAX_ALLOWED_BOOKS = MAX_ALLOWED_BOOK;
	User::Student::ALL_CREATED_USER.push_back(this);
}

void User::Student::addMoney(float money)
{
	this->totalPrice += money;
}

bool User::Student::canTakeBook(Product::Book* choosen_book)
{
	if (choosen_book->isBookAvailable() && choosen_book->price <= this->totalPrice)
	{
		return true;
	}
	return false;
}

bool User::Student::canFoodOrder(Product::Food* ordered_food)
{
	if (ordered_food->calculatePrice() <= this->totalPrice)
	{
		return true;
	}
	return false;
}

void User::Student::orderFood(Product::Food* ordered_food)
{
	if (canFoodOrder(ordered_food))
	{
		this->ordered_foods.push_back(ordered_food);
		totalPrice -= ordered_food->calculatePrice();
	}
}

void User::Student::takeBook(Product::Book* choosen_book)
{
	if (canTakeBook(choosen_book))
	{
		this->taken_books.push_back(choosen_book);
		totalPrice -= choosen_book->price;
		choosen_book->addTaker(this);
	}
}