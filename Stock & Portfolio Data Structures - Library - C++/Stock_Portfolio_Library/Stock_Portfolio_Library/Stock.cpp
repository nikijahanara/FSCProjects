//****************************************************
// File: Stock.cpp
//
// Purpose: To store the definitions of the functions and operator overloads of the Stock class.
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
// Description: Updated the default constructor, three parameter constructor, and copy constructor 
//				of Stock to allocate dynamic memory for each of Stock's pointer member variables.
//				Dereferenced all of Stock's pointer member variables in every function and operator overload
//				definition where the the pointer member variables were used in order for the value that they are pointing to 
//				to be returned, assigned, printed, read in, or compared instead of the addresses that each pointer member variable is storing.
//				Added a definition for the non-member overload of the extraction operator so that values for Stock's pointer member variables
//				can be read in from a given istream. Also added a definition for the destructor of Stock so that the dynamic memory of its
//				pointer member variables can be deallocated in order to prevent a memory leak.
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 11/14/2017
// Description: Added definition for the non-member overload of the equality operator for the Stock class
//				so that the stockName member variable value for two instances of Stock can be compared for equality.
//				It will return true if the stockName member variable values of two instances of Stock are equal,
//				and false if the stockName member variable values are not equal.
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 12/8/2017
// Description: Added the definitions for the non-member overloads of the less-than and greater-than operators for the Stock class
//				so that the stockName member variable value for two instances of Stock can be compared to see
//				which instance of Stock's stockName is greater or less than the other one.
//
//***************************************************

//***************************************************
// The Stock header file containing the Stock class's function prototypes
// must be included so that each function of the Stock class can be defined.
//***************************************************
#include "Stock.h"

//****************************************************
// Function: Stock()
//
// Purpose: To be the default constructor of the Stock class.
//			It assigns default values to each of Stock's member variables.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 10/10/2017
// Description: Because the member variables of Stock are now pointers,
//				the default constructor was updated to call new for each
//				member variable so that dynamic memory is allocated for each member variable.
//				Each member variable is also now dereferenced so that they can be assigned default values.
//
//****************************************************
Stock::Stock()
{
	//****************************************************
	// NJ 10/10/2017 - Calling new to allocate dynamic memory 
	//				   for each of the Stock class's pointer member variables.
	//****************************************************
	stockName = new std::string;
	stockPrice = new double;
	stockShares = new double;

	//****************************************************
	// NJ 10/10/2017 - Dereferenced each of the Stock class's pointer
	//				   member variables so that they can be assigned default values.
	//****************************************************
	*stockName = "DEFAULT STOCK NAME";
	*stockPrice = 0.0;
	*stockShares = 0.0;
}

//****************************************************
// Function: Stock(string, double, double)
//
// Purpose: To be a constructor that takes values for 
//			all of Stock's member variables as parameters.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 10/10/2017
// Description: Because the member variables of Stock are now pointers,
//				this three parameter constructor was updated to call new for each
//				member variable so that dynamic memory is allocated for each member variable.
//				Each member variable is also now dereferenced so that they can be assgined the
//				values that were passed into the constructor's parameters.
//
//****************************************************
Stock::Stock(std::string constructorName, double constructorPrice, double constructorShares)
{
	//****************************************************
	// NJ 10/10/2017 - Calling new to allocate dynamic memory 
	//				   for each of the Stock class's pointer member variables.
	//****************************************************
	stockName = new std::string;
	stockPrice = new double;
	stockShares = new double;

	//****************************************************
	// Assigning each of the member variable values that were passed into
	// the constructor to the corresponding member variable of Stock.
	//
	// NJ 10/10/2017 - Dereferenced each of the Stock class's pointer
	//				   member variables so that they can be assigned the
	//				   values passed into the parameters of this constructor.
	//****************************************************
	*stockName = constructorName;
	*stockPrice = constructorPrice;
	*stockShares = constructorShares;
}

//****************************************************
// Function: Stock(const Stock& otherStock)
//
// Purpose: To be a copy constructor for the Stock class
//			and copy the member variable values of an 
//			instance of Stock into the member variable
//			values of another instance of Stock.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 10/10/2017
// Description: Because the member variables of Stock are now pointers,
//				this copy constructor was updated to call new for each
//				member variable so that dynamic memory is allocated for each member variable.
//				The member variables of both instances of Stock are also now dereferenced so that
//				the current instance of Stock's member variables can be assigned the values that the
//				pointer member variables of the instance of Stock passed into the copy constructor are
//				pointing to instead of the addresses that the pointer member variables are storing. 
//				This results in a deep copy of the values of the member variables of the instance of Stock
//				passed into the constructor that prevents a memory leak.
//
//****************************************************
Stock::Stock(const Stock& otherStock)
{
	//****************************************************
	// NJ 10/10/2017 - Calling new to allocate dynamic memory 
	//				   for each of the Stock class's pointer member variables.
	//****************************************************
	stockName = new std::string;
	stockPrice = new double;
	stockShares = new double;

	//****************************************************
	// NJ 10/10/2017 - Dereferenced each instance of Stock's pointer
	//				   member variables during assignment to prevent a memory leak.
	//				   By dereferencing each instance of Stock's pointer member variables,
	//				   a deep copy of the values that the pointer member variables are pointing to
	//				   of the instance of Stock passed into the constructor will be performed. 
	//				   This prevents the addresses that its pointer member variables are storing from being assigned to the 
	//				   current instance of Stock's member variable values, thus preventing a memory leak.
	//****************************************************
	*stockName = *otherStock.stockName;
	*stockPrice = *otherStock.stockPrice;
	*stockShares = *otherStock.stockShares;
}

//****************************************************
// Function: getStockName
//
// Purpose: To return the string contained in the stockName
//			member variable of an instance of Stock.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 10/10/2017
// Description: Because stockName was changed to be a pointer,
//				it is now dereferenced in order for the string value that it
//				is pointing to to be returned instead of the address that it is storing.
//
//****************************************************
std::string Stock::getStockName()
{
	// NJ 10/10/2017 - In order to prevent an address from being returned, the stockName pointer is now dereferenced.
	return *stockName;
}

//****************************************************
// Function: getStockPrice
//
// Purpose: To return the double value contained in the stockPrice
//			member variable of an instance of Stock.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 10/10/2017
// Description: Because stockPrice was changed to be a pointer,
//				it is now dereferenced in order for the double value that it
//				is pointing to to be returned instead of the address that it is storing.
//
//****************************************************
double Stock::getStockPrice()
{
	// NJ 10/10/2017 - In order to prevent an address from being returned, the stockPrice pointer is now dereferenced.
	return *stockPrice;
}

//****************************************************
// Function: getStockShares
//
// Purpose: To return the double value contained in the stockShares
//			member variable of an instance of Stock.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 10/10/2017
// Description: Because stockShares was changed to be a pointer,
//				it is now dereferenced in order for the double value that it
//				is pointing to to be returned instead of the address that it is storing.
//
//****************************************************
double Stock::getStockShares()
{
	// NJ 10/10/2017 - In order to prevent an address from being returned, the stockShares pointer is now dereferenced.
	return *stockShares;
}

//****************************************************
// Function: setStockName
//
// Purpose: To assign the string passed into the function's parameter
//			to the stockName member variable of an instance of Stock.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 10/10/2017
// Description: Because stockName was changed to be a pointer,
//				it is now dereferenced so that it can be assigned the given name.
//
//****************************************************
void Stock::setStockName(std::string newStockName)
{
	// NJ 10/10/2017 - The stockName pointer is now dereferenced so that it can be assigned the given name.
	*stockName = newStockName;
}

//****************************************************
// Function: setStockPrice
//
// Purpose: To assign the double value passed into the function's parameter
//			to the stockPrice member variable of an instance of Stock.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 10/10/2017
// Description: Because stockPrice was changed to be a pointer,
//				it is now dereferenced so that it can be assigned the given price.
//
//****************************************************
void Stock::setStockPrice(double newStockPrice)
{
	// NJ 10/10/2017 - The stockPrice pointer is now dereferenced so that it can be assigned the given price.
	*stockPrice = newStockPrice;
}

//****************************************************
// Function: setStockShares
//
// Purpose: To assign the double value passed into the function's parameter
//			to the stockShares member variable of an instance of Stock.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 10/10/2017
// Description: Because stockShares was changed to be a pointer,
//				it is now dereferenced so that it can be assigned the given shares.
//
//****************************************************
void Stock::setStockShares(double newStockShares)
{
	// NJ 10/10/2017 - The stockShares pointer is now dereferenced so that it can be assigned the given shares.
	*stockShares = newStockShares;
}

//****************************************************
// Function: CalculateValue
//
// Purpose: To calculate the value of an instance of Stock by returning
//			the product of its stockPrice mulitplied by its stockShares.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 10/10/2017
// Description: Because stockPrice and stockShares are now pointers,
//				each one is dereferenced so that the double value each pointer is pointing
//				to can be mutliplied so that the product of their values can be returned by the function.
//
//****************************************************
double Stock::CalculateValue()
{
	//****************************************************
	// Returning the product of stockPrice multiplied by stockShares,
	// which is the calculation that determines the value of a single Stock.
	//
	// NJ 10/10/2017 - The stockPrice and stockShares pointer member variables are now 
	//			       dereferenced so that the double value each pointer is pointing
	//			       to can be multiplied instead of the addresses that each pointer is storing.
	//****************************************************
	return ((*stockPrice) * (*stockShares));
}

//****************************************************
// Function: operator=
//
// Purpose: To overload the assignment operator for the Stock class.
//			By overloading the assignment operator, one instance
//			of Stock's member variable values can be assigned
//			to the values of another instance of Stock's member variables.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 10/10/2017
// Description: Because Stock's member variables are now pointers,
//				both instances of Stock on each side of the assignment 
//				operator have their pointer member variables dereferenced. 
//				This allows for a deep copy of the member variable values of the instance of Stock 
//				on the right-hand side of the assignment operator to be assigned to the current instance
//				of Stock's member variable values instead of a shallow copy of the addresses that each pointer member
//				variable is storing to occur. This deep copy will therefore prevent memory leaks.
//
//****************************************************
Stock& Stock::operator=(const Stock& rhs)
{
	//****************************************************
	// NJ 10/10/2017 - Because the "this" pointer contains the address of the current instance,
	//				   if the address of the instance of Stock on the right-hand side
	//				   of the assignment operator is equal to the address that the "this" pointer
	//				   is storing then the two instances of Stock have the same address and
	//				   therefore already have the same values for their member variables.
	//				   This if statement therefore avoids an unecessary self-assignment.
	//****************************************************
	if (this == &rhs)
	{
		//****************************************************
		// NJ 10/10/2017 - Because a self-assignment is unnecessary,
		//				   the values of the current instance of Stock are returned
		//				   without any additional assignments by 
		//				   returning a dereferenced "this" pointer.
		//****************************************************
		return *this;
	}

	//****************************************************
	// The current instance of Stock's member variables are each
	// being assigned the member variable values of the instance of
	// Stock on the right hand side (rhs) of the assignment operator.
	//
	// NJ 10/10/2017 - Both instances of Stock now have their member variables dereferenced
	//				   in order for a deep copy of the values that the pointer member variables
	//				   are pointing to to be performed into the current instance of
	//				   Stock's member variable values. It is important to perform a 
	//				   deep copy in order to prevent a memory leak.
	//****************************************************
	*stockName = *rhs.stockName;
	*stockPrice = *rhs.stockPrice;
	*stockShares = *rhs.stockShares;

	//****************************************************
	// The "this pointer" contains the address of the current instance.
	// It is returned so that the current instance of Stock's member variables
	// can have their values updated to the new values they were assigned.
	//****************************************************
	return *this;
}

//****************************************************
// Function: operator<<
//
// Purpose: To overload the insertion operator for the Stock class.
//			By overloading the insertion operator, an instance
//			of Stock can have each of its member variable values 
//			be printed on the given ostream.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 10/10/2017
// Description: Because Stock's member variables are now pointers,
//				each of Stock's pointer member variables are now dereferenced so
//				that the values each pointer member variable is pointing to will be printed to 
//				the given ostream instead of printing the addresses that each pointer member variable is storing.
//
//****************************************************
std::ostream& operator<<(std::ostream& out, const Stock& rhs)
{
	//****************************************************
	// Printing each of the instance of Stock's member variable values on separate lines.
	//
	// NJ 10/10/2017 - Dereferenced each of Stock's pointer member variables so that the
	//				   values they are ponting to can be printed to the given ostream.
	//****************************************************
	out << *rhs.stockName << std::endl;
	out << *rhs.stockPrice << std::endl;
	out << *rhs.stockShares << std::endl;

	// Returning the given ostream so that Stock's member variable values can be printed.
	return out;
}

//****************************************************
// Function: operator==
//
// Purpose: To overload the equality operator for the Stock class.
//			By overloading the equality operator, two instances
//			of Stock can have their stockName member variable values
//			compared to see if the two instances of Stock are equal or not.
//
// Runtime: O(1)
//
//****************************************************
bool operator==(const Stock& lhs, const Stock& rhs)
{
	//****************************************************
	// The value true will be returned only if the two
	// instances of Stock have the same value for their stockName member variables. 
	// The stockName member variable of each instance of Stock 
	// is dereferenced so that the data the stockName member variables 
	// are pointing to is compared instead of the addresses 
	// that each stockName member variable is storing.
	//****************************************************
	if (*lhs.stockName == *rhs.stockName)
	{
		//****************************************************
		// Returning true to indicate the two instances of Stock
		// are equal if their stockName member variable values are equal.
		//****************************************************
		return true;
	}

	//****************************************************
	// If the comparison between the stockName value for the two
	// instances of Stock fails, then the value false must be
	// returned because the two instances of Stock are not equal.
	//****************************************************
	return false;
}

//****************************************************
// Function: operator>>
//
// Purpose: To overload the extraction operator for the Stock class.
//			The given istream is now defined to read in three values
//			and assign those values to the values of the three pointer member variables of Stock.
//			Because the extraction operator only reads until the first whitespace,
//			it is also assumed that one word string will be read in for the stockName member variable.
//
// Runtime: O(1)
//
//****************************************************
std::istream& operator>>(std::istream& in, const Stock& rhs)
{
	//****************************************************
	// Reading in three consecutive values from the given istream that represent the
	// values that will be assigned to each of Stock's pointer member variables.
	//****************************************************
	in >> *rhs.stockName;
	in >> *rhs.stockPrice;
	in >> *rhs.stockShares;

	//****************************************************
	// Returning the given istream so that the values that were read in
	// can be assigned to the corresponding pointer member variables of Stock.
	//****************************************************
	return in;
}

//****************************************************
// Function: ~Stock()
//
// Purpose: To be the Stock class's destructor.
//			The destructor deallocates the dynamic memory that was allocated 
//			for each pointer member variable of Stock in order to prevent a memory leak.
//
// Runtime: O(1)
//
//****************************************************
Stock::~Stock()
{
	//****************************************************
	// Calling delete for each of Stock's pointer member variables.
	// The call to delete deallocates the dynamic memory that was allocated
	// for each pointer member variable of Stock in order to prevent a memory leak.
	//****************************************************
	delete stockName;
	delete stockPrice;
	delete stockShares;
}

//****************************************************
// Function: operator<
//
// Purpose: To overload the less-than operator for the Stock class.
//			It will return true if the value of the left-hand-side
//			Stock's stockName member variable is less than the right-hand-side
//			Stock's stockName member variable value, and false if otherwise.
//
// Runtime: O(1)
//
//****************************************************
bool operator<(Stock &lhs, Stock& rhs)
{
	//****************************************************
	// If the instance of Stock on the left-hand-side has a stockName value
	// that is less than the instance of Stock on the right-hand-side's
	// stockName value, then the value true is returned.
	//****************************************************
	if (*lhs.stockName < *rhs.stockName)
	{
		return true;
	}

	//****************************************************
	// If the above if statement fails, then the Stock on the left-hand-side does not
	// have a stockName value that is less than the instance of Stock
	// on the right-hand-side's stockName value, so the value false is returned.
	//****************************************************
	return false;
}

//****************************************************
// Function: operator>
//
// Purpose: To overload the greater-than operator for the Stock class.
//			It will return true if the value of the left-hand-side
//			Stock's stockName member variable is greater than the right-hand-side
//			Stock's stockName member variable value, and false if otherwise.
//
// Runtime: O(1)
//
//****************************************************
bool operator>(Stock &lhs, Stock& rhs)
{
	//****************************************************
	// If the instance of Stock on the left-hand-side has a stockName value
	// that is greater than the instance of Stock on the right-hand-side's
	// stockName value, then the value true is returned.
	//****************************************************
	if (*lhs.stockName > *rhs.stockName)
	{
		return true;
	}

	//****************************************************
	// If the above if statement fails, then the Stock on the left-hand-side does not
	// have a stockName value that is greater than the instance of Stock
	// on the right-hand-side's stockName value, so the value false is returned.
	//****************************************************
	return false;
}