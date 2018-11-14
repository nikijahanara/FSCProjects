//****************************************************
// File: Portfolio.h
//
// Purpose: To store both the Portfolio class's private member variables and the prototypes of Portfolio's public functions.
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
// Description: The private Stock member variable of Portfolio was changed to a pointer.
//				A private integer member variable (stockSize) that keeps track of the Stock array's integer size was also added.
//				The prototypes for a member assignment operator overload, non-member insertion operator overload, 
//				non-member equality operator overload, one parameter constructor, copy constructor, Resize function, Clone function, 
//				and destructor were also added to the Portfolio class.
// 
//***************************************************

// Preprocessor guards are added to to the Portfolio header file so multiple #includes can be allowed.
#ifndef PORTFOLIO_H
#define PORTFOLIO_H

//***************************************************
// The Stock header file must be included so that an
// instance of Stock can be declared within the Portfolio class.
//***************************************************
#include "Stock.h"

class Portfolio
{
	private:
		//***************************************************
		// NJ 10/10/2017 - The Stock member variable was changed to a pointer.
		//				   The Stock pointer member variable will be initialized as a
		//				   dyanmically allocated array in each of Portfolio's constrcutors.
		//***************************************************
		Stock *stock;
		// NJ 10/10/2017 - An integer member variable that will always keep track of the Stock array's size was added.
		int stockSize;

	public:
		// Prototype for the default constructor of Portfolio.
		Portfolio();
		// NJ 10/10/2017 - Added a prototype for a one parameter constructor of Portfolio that takes a size for the Stock array.
		Portfolio(int newArraySize);
		// NJ 10/10/2017 - Added a prototype for the copy constructor of Portfolio.
		Portfolio(const Portfolio& otherPortfolio);

		// Prototype for the Set function of Portfolio.
		void Set(int index, Stock s);

		// Prototype for the Get function of Portfolio.
		Stock Get(int index);

		// Prototype for the PriceRangeCount function of Portfolio.
		int PriceRangeCount(double lowerBound, double upperBound);

		// Prototype for the MostShares function of Portfolio.
		Stock MostShares();

		// Prototype for the FindByName function of Portfolio.
		bool FindByName(std::string name, Stock &v);

		// Prototype for the TotalValue function of Portfolio.
		double TotalValue();

		// Prototype for the Size function of Portfolio.
		int Size();

		// Prototype for the Initialize function of Portfolio.
		void Initialize();

		// Prototype for the GetAuthor function of Portfolio.
		std::string GetAuthor();

		// NJ 10/10/2017 - Added a prototype for the Resize function of Portfolio.
		void Resize(int newSize);

		// NJ 10/10/2017 - Added a prototype for the Clone function of Portfolio.
		Portfolio* Clone();

		// NJ 10/10/2017 - Added a prototype for the member overload of the assignment operator.
		Portfolio& operator=(const Portfolio& rhs);

		//****************************************************
		// NJ 10/10/2017 - Added prototypes for the non-member overloads of the insertion and equality operator.
		//				   Because they are non-member overloads, the prototypes must be "friended" so that
		//				   they can have access to the member variables of the Portfolio class.
		//****************************************************
		friend std::ostream& operator<<(std::ostream& out, const Portfolio& rhs);
		friend bool operator==(const Portfolio& lhs, const Portfolio& rhs);

		// NJ 10/10/2017 - Added a prototype for the destructor of Portfolio.
		~Portfolio();
};

#endif