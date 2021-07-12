#include "PRODUCT_BACKEND.h"
#include <string>

using namespace std;
using namespace Product;
using namespace User;

Book::Book(string book_name, int n_copies, float price)
{
	this->book_name = book_name;
	this->n_copies = n_copies;
	this->price = price;
}

bool Book::isBookAvailable()
{
	if (n_copies > 0)
	{
		return true;
	}
	return false;
}


void Book::addTaker(Student* taker_student)
{
	// THE STUDENT ALLREADY CHECK isBookAvailable method so that,
	// I can directly add my vector the taker_student
	this->taken_student.push_back(taker_student);
	this->n_copies--;
}

bool Book::increaseCopies(int new_n_copies)
{
	if (new_n_copies > 0)
	{
		this->n_copies += new_n_copies;
		return true;
	}
	return false;
}


Food::Food(string food_name, int amount, float price)
{
	this->food_name = food_name;
	this->amount = amount;
	this->price = price;
}

float Food::calculatePrice()
{
	return amount * price;
}

