
#include <iostream>
#include "SHOPCENTER_BACKEND.h"
//#include "USER_BACKEND.h"
//#include "PRODUCT_BACKEND.h"
using namespace std;

int main()
{
	// LEARNED NAMESPACE LOGIC TOTALLY.
	// WHEN YOU DECLARE GLOBALLY A VARIABLE IN NAMESPACE YOU HAVE TO DECLARE IT AS EXTERN
		// AND YOU HAVE TO REDEFINE(externed variable) IT IN CPP FILE
			// ShopCenter::ALL_BOOK_SELLERS , ShopCenter::ALL_FOOD_SELLERS  ,  ShopCenter::SHOPPING_STATUS
				// are example of externed variable..


	User::Student *mecit = new User::Student("mecit",15);
	ShopCenter::BookSeller bookSellerfirst("kazimKitapcilik");
	cout << "Student name is " << mecit->student_name << endl;
	cout << User::Student::ALL_CREATED_USER.size() << endl;
	cout << ShopCenter::ALL_BOOK_SELLERS.size() << endl;

	if (ShopCenter::SHOPPING_STATUS == ShopCenter::SHOP_STATUS::OFF_DAY)
	{
		cout << "SHOPCENTER IS IN OFF DAY .." << endl;
	}
	if (bookSellerfirst.SELLER_STATUS == ShopCenter::SHOP_STATUS::OFF_DAY)
	{
		cout << "is ofline" << endl;
	}
	return 0;
}