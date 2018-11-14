//****************************************************
// File: Stock.h
//
// Purpose: To store both the Stock class's private member variables and the prototypes of Stock's public functions.
//
// Written By: Niki Jahanara
//
// Compiler: Visual Studio Express 2013 (For Windows Desktop)
// 
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 10/10/2017
// Description: The three private member variables of Stock (stockName, stockPrice, stockShares) were changed to pointers.
//				The prototypes for a non-member extraction operator overload and destructor were also added for the Stock class.
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 11/14/2017
// Description: The prototype for a non-member equality operator overload was added to the Stock class.
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 12/8/2017
// Description: The prototypes for the non-member less-than and greater-than operator overloads was added to the Stock class.
// 
//***************************************************

// Preprocessor guards are added to to the Stock header file so that multiple #includes can be allowed.
#ifndef STOCK_H
#define STOCK_H

#include<iostream>
// Must include the string header in order to be able to create variables with the string data type.
#include<string>

class Stock
{
	private:
		//***************************************************
		// Declaring the private member variables of Stock.
		//
		// NJ 10/10/2017 - Each of Stock's member variables (stockName, stockPrice, stockShares)
		//				   were changed to pointers.
		//***************************************************
		std::string *stockName;
		double *stockPrice;
		double *stockShares;

	public:
		// Prototype for Stock's default constructor.
		Stock();
		// Prototype for Stock's constructor that takes values for all of Stock's member variables as parameters.
		Stock(std::string constructorStock, double constructorPrice, double constructorShares);
		// Prototype for Stock's copy constructor.
		Stock(const Stock& otherStock);

		// Prototypes for Stock's Get functions for all of its member variables.
		std::string getStockName();
		double getStockPrice();
		double getStockShares();

		// Prototypes for Stock's Set functions for all of its member variables.
		void setStockName(std::string newStockName);
		void setStockPrice(double newStockPrice);
		void setStockShares(double newStockShares);

		// Prototype for Stock's CalculateValue function.
		double CalculateValue();

		// Prototype for the member overload of the assignment operator.
		Stock& operator=(const Stock& rhs);

		//****************************************************
		// Prototypes for the non-member overloads of the insertion and equality operator.
		// Because they are non-member overloads, the prototypes must be "friended" so that
		// they can have access to the member variables of the Stock class.
		//****************************************************
		friend std::ostream& operator<<(std::ostream& out, const Stock& rhs);

		// NJ 10/10/2017 - Added the prototype for a non-member extraction operator overload for the Stock class.
		friend std::istream& operator>>(std::istream& in, const Stock& rhs);

		// NJ 11/14/2017 - Added a prototype for Stock's non-member overload of the equality operator.
		friend bool operator==(const Stock& lhs, const Stock& rhs);

		// NJ 10/10/2017 - Added a prototype for Stock's destructor.
		~Stock();

		// NJ 12/8/2017 - Added the prototype for a non-member less-than operator overload for the Stock class.
		friend bool operator<(Stock& lhs, Stock& rhs);

		// NJ 12/8/2017 - Added the prototype for a non-member greater-than operator overload for the Stock class.
		friend bool operator>(Stock& lhs, Stock& rhs);
};

#endif