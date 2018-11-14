//****************************************************
// File: Portfolio.cpp
//
// Purpose: To store the definitions of the functions of the Portfolio class.
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
// Description: Updated every constructor of Portfolio to allocate dynamic memory for its Stock array.
//				Updated every function definition with a for loop to use the new stockSize variable
//				as an ending condtion in order to change the ending condition of for loops from being hard-coded.
//				Added definitions for the Portfolio class's new destructor, copy constructor,
//				one parameter constructor, member overload of the assignment operator, 
//				non-member insertion operator overload, non-member equality operator overload, Resize, and Clone function.
// 
//***************************************************

//***************************************************
// The Portfolio header file containing the Portfolio class's function prototypes
// must be included so that each function of the Portfolio class can be defined.
//***************************************************
#include"Portfolio.h"

//****************************************************
// Function: Portfolio()
//
// Purpose: To be the default constructor of the Portfolio class.
//			It initilialzes Portfolio's Stock array with default values.
//
// Runtime: O(n)
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 10/10/2017
// Description: Because the Stock member variable is now a pointer, new is called
//				for the Stock pointer member variable to allocate dynamic memory for
//				each of the Stock array's elements. The number of elements the Stock
//				array will be initialized to have is determined by the default value
//				assigned to the stockSize member variable within the default constructor.
//
//****************************************************
Portfolio::Portfolio()
{
	// NJ 10/10/2017 - The stockSize member variable is now given a default value of 10 in the default constructor.
	stockSize = 10;
	//****************************************************
	// NJ 10/10/2017 - The Stock member variable is now a pointer. 
	//				   New is called for it in order to allocate dynamic memory for each of its elements.
	//				   The stockSize member variable is passed into the brackets of the Stock array's
	//				   initialization in order to determine the size of the Stock array.
	//****************************************************
	stock = new Stock[stockSize];

	//****************************************************
	// The Initialize function is called within the default
	// constructor of the Portfolio class in order to 
	// assign defaut values to Portfolio's Stock array.
	//****************************************************
	Initialize();
}

//****************************************************
// Function: Portfolio(int newArraySize)
//
// Purpose: To be a one parameter constructor of the Portfolio class.
//			It takes an integer that represents the size of the Stock array
//			that the instance of Portfolio being declared with this constructor will have
//			and then dynamically allocates the Stock array of that instance of Portfolio
//			by calling new in the Stock array's initialization with the given array size.
//			The stockSize member variable is also assigned the value passed into this constructor.
//
// Runtime: O(n)
//
//****************************************************
Portfolio::Portfolio(int newArraySize)
{
	// Assigning stockSize the value of the integer passed into the constructor.
	stockSize = newArraySize;

	//****************************************************
	// Calling new for the Stock pointer in order to dyanmically allocate an array
	// that has the size of the integer passed into the constructor. Because stockSize
	// was assigned the value of the given size, stockSize is passed into the Stock array's
	// brackets during its initialization in order to determine the size of the Stock array.
	//****************************************************
	stock = new Stock[stockSize];

	//****************************************************
	// The Initialize function is called within the one parameter
	// constructor of the Portfolio class in order to 
	// assign defaut values to Portfolio's Stock array.
	//****************************************************
	Initialize();
}

//****************************************************
// Function: Portfolio(const Portfolio& otherPortfolio)
//
// Purpose: To be a copy constructor for the Portfolio class.
//			It performs a deep copy of the member variable values of the instance of
//			Portfolio passed into the constructor in order to copy those values into the member
//			variable values of the instance of Portfolio that is being initialized with this constructor.
//			It must perform a deep copy of the passed in instance of
//			Portfolio's member variable values in order to prevent a memory leak.
//
// Runtime: O(n)
//
//****************************************************
Portfolio::Portfolio(const Portfolio& otherPortfolio)
{
	// Assigning stockSize the value of the stockSize of the instance of Portfolio passed into this constructor.
	stockSize = otherPortfolio.stockSize;

	//****************************************************
	// Calling new for the Stock pointer in order 
	// to allocate dynamic memory for the array of Stock.
	// stockSize is passed into the brackets of the Stock array
	// since it was assigned the size of the Stock array that the
	// instance of Portfolio passed into this constructor has.
	//****************************************************
	stock = new Stock[stockSize];

	//****************************************************
	// A for loop is used to go through each index of each Stock array 
	// and assign the value at each index of the Stock array of instance of Portfolio 
	// that was passed into the constructor into the corresponding index of 
	// the Stock array of the instance of Portfolio that is being initialized with this constructor.
	//****************************************************
	for (int i = 0; i < stockSize; i++)
	{
		//****************************************************
		// Assigning the value of each index of the Stock array
		// to be the value that the instance of Portfolio that
		// was passed into the constructor has at the
		// corresponding index of its Stock array.
		//****************************************************
		stock[i] = otherPortfolio.stock[i];
	}
}

//****************************************************
// Function: Set
//
// Purpose: To set the given instance of Stock at the index of the 
//			Stock array that is also passed into the function.		
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 10/10/2017
// Description: The stockSize member variable, which contains the size of the Stock array,
//				was updated to be in the condition of the if statement to represent the size
//				of the Stock array instead of having the size of the Stock array be hard-coded in.
//
//****************************************************
void Portfolio::Set(int index, Stock s)
{
	//****************************************************
	// Before the instance of Stock is set into the given index
	// of the Stock array, the given index is checked in order to
	// make sure that it is a valid index and that is not out of the Stock array's bounds. 
	// This is done by checking that the index is less than the stockSize of the array,
	// and that the index is greater than or equal to 0.
	// If the index is not valid, the Stock instance will not be set into the Stock array.
	//
	// NJ 10/10/2017 - Updated the condition of the if statement to use the stockSize
	//				   member variable to represent the size of the Stock array instead of
	//				   having the Stock array's size be hard-coded into the if statement's condition.
	//****************************************************
	if ((index < stockSize) && (index >= 0))
	{
		//****************************************************
		// After checking that the index is valid, the instance of Stock that 
		// is passed into the function is set at the given index of the Stock array.
		//****************************************************
		stock[index] = s;
	}
}

//****************************************************
// Function: Get
//
// Purpose: To return the Stock at the index of the Stock array
//			that is passed into the function.
//
// Runtime: O(1)
//
//****************************************************
Stock Portfolio::Get(int index)
{
	// Returning the Stock in the Stock array at the given index.
	return stock[index];
}

//****************************************************
// Function: PriceRangeCount
//
// Purpose: To return the number of Stocks in the Stock array
//			that have a price that falls between the inclusive range
//			that is passed into the function.
//
// Runtime: O(n)
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 10/10/2017
// Description: The stockSize member variable, which contains the size of the Stock array,
//				was updated to be the ending condition of the for loop inside this function
//				instead of having the ending condition of the for loop be a hard-coded array size.
//				This is important because the Stock array's size is no longer a static value
//				and this change allows for every element of the Stock array to be visited by the for loop.
//
//****************************************************
int Portfolio::PriceRangeCount(double lowerBound, double upperBound)
{
	// Declaring and initializing the local int priceCount variable to 0.
	int priceCount = 0;

	//****************************************************
	// The for loop goes through the Stock array and
	// adds 1 to the priceCount each time a Stock in the
	// Stock array has a price that falls between the
	// inclusive range that was passed into the function.
	//
	// NJ 10/10/2017 - Updated the ending condition of the for loop to be the
	//				   stockSize member variable instead of a hard-coded array size.
	//****************************************************
	for (int i = 0; i < stockSize; i++)
	{
		//****************************************************
		// If the amount returned by getStockPrice() for an index of the Stock array
		// is greater than or equal to the lowerBound,
		// and is less than or equal to the upperBound,
		// then 1 is added to the priceCount.
		//****************************************************
		if ((stock[i].getStockPrice() >= lowerBound) && (stock[i].getStockPrice() <= upperBound))
		{
			//****************************************************
			// 1 is added to the value of priceCount each time a
			// Stock's price falls between the inclusive range
			// that was passed into the function's parameters.
			//****************************************************
			priceCount += 1;
		}
	}

	//****************************************************
	// Returns the count of Stocks that have a price in the given inclusive range,
	// a count that is represented by the priceCount variable.
	//****************************************************
	return priceCount;
}

//****************************************************
// Function: MostShares
//
// Purpose: To return the Stock in an instance of
//			Portfolio's Stock array that has the most amount of shares.
//
// Runtime: O(n)
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 10/10/2017
// Description: The stockSize member variable, which contains the size of the Stock array,
//				was updated to be the ending condition of the for loop inside this function
//				instead of having the ending condition of the for loop be a hard-coded array size.
//				This is important because the Stock array's size is no longer a static value
//				and this change allows for every element of the Stock array to be visited by the for loop.
//
//****************************************************
Stock Portfolio::MostShares()
{
	// Declaring and initializing local int variable largestShareIndex to 0.
	int largestShareIndex = 0;

	// Declaring and initializing local double variable largestShare to 0.
	double largestShare = 0.0;

	//****************************************************
	// This for loop is used to go through each index of the Stock array
	// in order to find which index of the Stock array has the most amount of shares.
	//
	// NJ 10/10/2017 - Updated the ending condition of the for loop to be the
	//				   stockSize member variable instead of a hard-coded array size.
	//****************************************************
	for (int i = 0; i < stockSize; i++)
	{
		//****************************************************
		// If the getStockShares function returns a value higher than the value
		// of largestShare for an index of the Stock array, then that index
		// is assigned to the largestShareIndex variable and largestShare is
		// assigned the larger share value of that Stock array index.
		// Each index of the Stock array has its share amount checked against the value
		// of largestShare in order to find which index has the highest share value.
		//****************************************************
		if (stock[i].getStockShares() > largestShare)
		{
			//****************************************************
			// Assigning largestShare to the value returned by the getStockShares function
			// that was called for the index of the Stock array that has the larger share value.
			//****************************************************
			largestShare = stock[i].getStockShares();

			// Assigning largestShareIndex to the index of the Stock array that has the larger share value.
			largestShareIndex = i;
		}
	}

	// Returning the Stock at the index of the Stock array that contains the most amount of shares.
	return stock[largestShareIndex];
}

//****************************************************
// Function: FindByName
//
// Purpose: To return true if the given name of a Stock exists within
//			the array of Stock of a Portfolio instance, and false if it does not.
//			If the given name exists within the array of Stock,
//			the Stock reference parameter is assigned the
//			member variable values of the Stock instance that has the given name.
//
// Runtime: O(n)
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 10/10/2017
// Description: The stockSize member variable, which contains the size of the Stock array,
//				was updated to be the ending condition of the for loop inside this function
//				instead of having the ending condition of the for loop be a hard-coded array size.
//				This is important because the Stock array's size is no longer a static value
//				and this change allows for every element of the Stock array to be visited by the for loop.
//
//****************************************************
bool Portfolio::FindByName(std::string name, Stock &v)
{
	//****************************************************
	// Declaring a local bool variable, findByNameAnswer, to
	// represent the answer as to whether or not
	// the Stock with the given name exists within the Stock array.
	// The bool variable findByNameAnswer is false by default.
	//****************************************************
	bool findByNameAnswer = false;

	//****************************************************
	// The for loop is used to go through each element of the
	// Stock array in order find whether or not the Stock
	// with the given name exists within the Stock array.
	//
	// NJ 10/10/2017 - Updated the ending condition of the for loop to be the
	//				   stockSize member variable instead of a hard-coded array size.
	//****************************************************
	for (int i = 0; i < stockSize; i++)
	{
		//****************************************************
		// If the string returned by the call to the getStockName function
		// for an index of the Stock array is equal to the name that was
		// passed into the function's parameters, then findByNameAnswer
		// is set to true and instance of Stock that was passed by reference
		// into the function has the member variables values of
		// the Stock that contains the given name copied into it.
		//****************************************************
		if (stock[i].getStockName() == name)
		{
			//****************************************************
			// Copying the member variable values of the
			// the Stock that contains the given name
			// into the Stock reference parameter.
			//****************************************************
			v = stock[i];
			//****************************************************
			// Setting findByNameAnswer to true since the Stock
			// with the given name exists within the Stock array.
			//****************************************************
			findByNameAnswer = true;
		}
	}

	// Returning the true or false value contained in the findByNameAnswer variable.
	return findByNameAnswer;
}

//****************************************************
// Function: TotalValue
//
// Purpose: To return the sum of all the Stock values 
//			of the instance of Portfolio's Stock array.
//
// Runtime: O(n)
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 10/10/2017
// Description: The stockSize member variable, which contains the size of the Stock array,
//				was updated to be the ending condition of the for loop inside this function
//				instead of having the ending condition of the for loop be a hard-coded array size.
//				This is important because the Stock array's size is no longer a static value
//				and this change allows for every element of the Stock array to be visited by the for loop.
//
//****************************************************
double Portfolio::TotalValue()
{
	// Declaring and initializing the local double variable totalValue to 0.
	double totalValue = 0.0;

	//****************************************************
	// The for loop is used to go through each element of
	// the Stock array and add the value of each Stock
	// in the array to the value of the totalValue variable.
	//
	// NJ 10/10/2017 - Updated the ending condition of the for loop to be the
	//				   stockSize member variable instead of a hard-coded array size.
	//****************************************************
	for (int i = 0; i < stockSize; i++)
	{
		//****************************************************
		// Each index of the Stock array has a call to
		// the CalculateValue function so that the value it returns,
		// which represents the value of each Stock in the array,
		// can be added to the value of the totalValue variable.
		//****************************************************
		totalValue += stock[i].CalculateValue();
	}

	//****************************************************
	// Returning the sum of all the Stocks in the array, 
	// which is represented by the totalValue variable.
	//****************************************************
	return totalValue;
}

//****************************************************
// Function: Size
//
// Purpose: To return size of the array of Stock within an instance of Portfolio.
//
// Runtime: O(1)
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 10/10/2017
// Description: The stockSize member variable, which contains the size of the Stock array,
//				was updated to be returned by this function instead of a hard-coded array size.
//
//****************************************************
int Portfolio::Size()
{
	//****************************************************
	// NJ 10/10/2017 - Updated the return statement of the Size function to
	//				   return the stockSize member variable, which contains 
	//				   the size of the Stock array, instead of a hard-coded array size.
	//****************************************************
	return stockSize;
}

//****************************************************
// Function: Initialize
//
// Purpose: To initialize each index of the Stock array
//			within an instance of Portfolio to default values.
//
// Runtime: O(n)
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 10/10/2017
// Description: The stockSize member variable, which contains the size of the Stock array,
//				was updated to be the ending condition of the for loop inside this function
//				instead of having the ending condition of the for loop be a hard-coded array size.
//				This is important because the Stock array's size is no longer a static value
//				and this change allows for every element of the Stock array to be visited by the for loop.
//
//****************************************************
void Portfolio::Initialize()
{
	// Declaring an instance of Stock that contains default member variable values.
	Stock defaultStock("DEFAULT INITIALIZE STOCK NAME", 0, 0);

	//****************************************************
	// A for loop is used to go through the array of Stock and set
	// each index equal to the member variable values that defaultStock has.
	//
	// NJ 10/10/2017 - Updated the ending condition of the for loop to be the
	//				   stockSize member variable instead of a hard-coded array size.
	//****************************************************
	for (int i = 0; i < stockSize; i++)
	{
		//****************************************************
		// The Set function is called to initialize and 
		// set the member variable values of each Stock 
		// in the Stock array equal to the member variable 
		// values that defaultStock has.
		//****************************************************
		Set(i, defaultStock);
	}
}

//****************************************************
// Function: Resize
//
// Purpose: To "resize" the Stock array by creating a new array of Stock. 
//			If the Stock array being "resized" to a size that is larger than the original array of Stock's size,
//			then the new larger Stock array retains all of the original Stock array's values.
//			If the Stock array is being "resized" to a size that is smaller than the original array of Stock's size,
//			then the new Stock array retains as many values from the original Stock array that can fit into its new smaller size.
//			A memory leak is prevented during the "resizing" of the Stock array by deallocating the dynamic memory of the
//			original array of Stock before the current instance of Portfolio's Stock pointer 
//			is assigned the address of the new "resized" Stock array to point to.
//
// Runtime: O(n)
//
//****************************************************
void Portfolio::Resize(int newSize)
{
	// Declaring a local pointer to a Stock instance.
	Stock *temporaryStock;
	//****************************************************
	// Allocating dynamic memory for the local Stock pointer's array with a call to new.
	// The size of this local Stock pointer's array is the integer size that was passed into the function.
	//****************************************************
	temporaryStock = new Stock[newSize];

	//****************************************************
	// If the size that was passed into the function is greater than the
	// size of the current instance of Portfolio's Stock array size,
	// then a for loop that has an ending condition that is less than the
	// size of the current instance of Portfolio's Stock array must be used when assigning the
	// values of the current instance of Portfolio's Stock array to the local Stock pointer's array
	// in order to prevent the current instance's smaller Stock array from going out of bounds.
	//****************************************************
	if (newSize > stockSize)
	{
		//****************************************************
		// A for loop is used to go through each index of the local Stock pointer's
		// array and the current instance of Portfolio's Stock array so that all the values of the
		// current instance of Portfolio's Stock array can be assigned to the local Stock pointer's array.
		// Because the local Stock pointer's array size is larger than 
		// the current instance of Portfolio's Stock array size, the ending condition of the for loop must
		// be set to be less than the size of the current instance of Portfolio's Stock array or else
		// the current instance of Portfolio's Stock array will go out of bounds.
		//****************************************************
		for (int i = 0; i < stockSize; i++)
		{
			//****************************************************
			// Assigning every value at every index of the current 
			// instance of Portfolio's smaller Stock array
			// to the local Stock pointer's larger Stock array.
			//****************************************************
			temporaryStock[i] = stock[i];
		}

		//****************************************************
		// After assigning all the values of the current instance of Portfolio's Stock array to the
		// local Stock pointer's larger Stock array, the current instance of Portfolio's
		// Stock array must be deallocated with a call to delete before the
		// current instance of Portfolio's Stock pointer can be set to point to the
		// address stored in the local Stock pointer (which is the address of the "resized" Stock array).
		// If delete is not called on the current instance of Portfolio's Stock array, a memory leak will occur.
		//****************************************************
		delete [] stock;

		//****************************************************
		// The Stock pointer of the current instance of Portfolio is assigned the address that the
		// local Stock pointer is storing so that it can point to the "resized" Stock
		// array that has retained all the values it previously had before delete was called on it.
		//****************************************************
		stock = temporaryStock;

		//****************************************************
		// The stockSize member variable is assigned the size that was passed into the function
		// in order to accurately contain the number of elements that the "resized" Stock array has.
		//****************************************************
		stockSize = newSize;
	}
	//****************************************************
	// If the size that was passed into the function is smaller than the
	// size of the current instance of Portfolio's Stock array size,
	// then a for loop that has an ending condition that is less than the
	// given size must be used when assigning the values of the current
	// instance of Portfolio's Stock array to the local Stock pointer's array
	// in order to prevent the local Stock pointer's array from going out of bounds.
	//****************************************************
	else
	{
		//****************************************************
		// A for loop is used to go through each index of the local Stock pointer's
		// array and the current instance of Portfolio's Stock array so that as many values of the
		// current instance of Portfolio's Stock array that can fit can be assigned into 
		// the local Stock pointer's smaller array.
		// Because the local Stock pointer's array size is smaller than 
		// the current instance of Portfolio's Stock array size, the ending condition 
		// of the for loop must be set to be less than the given size of the local Stock pointer's
		// array or else the local Stock pointer's array will go out of bounds.
		//****************************************************
		for (int i = 0; i < newSize; i++)
		{
			//****************************************************
			// Assigning as many elements from the current instance of Portfolio's
			// Stock array that can fit to the local Stock pointer's smaller Stock array.
			//****************************************************
			temporaryStock[i] = stock[i];
		}

		//****************************************************
		// After assigning as many values that can fit of the current instance of 
		// Portfolio's Stock array to the local Stock pointer's smaller Stock array,
		// the current instance of Portfolio's Stock array must be deallocated with a call to delete
		// before the address the current instance of Portfolio's Stock pointer can be set equal to the
		// address stored in local Stock pointer (which is the address of the "resized" Stock array).
		// If delete is not called on the current instance of Portfolio's Stock array, a memory leak will occur.
		//****************************************************
		delete [] stock;

		//****************************************************
		// The Stock pointer of the current instance is assigned the address that the
		// local Stock pointer is storing so that it can point to the "resized" Stock
		// array that has retained as many elements from the previous Stock array that can fit.
		//****************************************************
		stock = temporaryStock;

		//****************************************************
		// The stockSize member variable is assigned the size that was passed into the function
		// in order to accurately contain the number of elements that the "resized" Stock array has.
		//****************************************************
		stockSize = newSize;
	}
}

//****************************************************
// Function: Clone
//
// Purpose: To allocate a new dynamic instance of Portfolio 
//			that is a deep copy of the current instance of Portfolio.
//
// Runtime: O(n)
//
//****************************************************
Portfolio* Portfolio::Clone()
{
	// Declaring a pointer to an instance of Portfolio.
	Portfolio *p;
	//****************************************************
	// Calling new on the Portfolio pointer and passing
	// the current instance of Portfolio into a copy
	// constructor in order to allocate dynamic memory
	// for the deep copy of the current instance.
	//****************************************************
	p = new Portfolio(*this);

	// Returning a pointer to the new instance of Portfolio.
	return p;
}

//****************************************************
// Function: operator=
//
// Purpose: To overload the assignment operator for the Portfolio class.
//			By overloading the assignment operator, a deep copy of the 
//			passed in instance of Portfolio can be performed so that
//			the size and the data of the current instance of Portfolio's Stock
//			array can be the same as the size and have the same data as the 
//			passed in instance of Portfolio's Stock array.
//
// Runtime: O(n)
//
//****************************************************
Portfolio& Portfolio::operator=(const Portfolio& rhs)
{
	//****************************************************
	// Because the "this" pointer contains the address of the current instance,
	// if the address of the instance of Portfolio on the right-hand side
	// of the assignment operator is equal to the address that the "this" pointer
	// is storing then the two instances of Portfolio have the same address and
	// therefore already have the same values for their member variables.
	// This if statement therefore avoids an unecessary self-assignment.
	//****************************************************
	if (this == &rhs)
	{
		//****************************************************
		// Because a self-assignment is unnecessary,
		// the values of the current instance are returned
		// without any additional assignments by 
		// dereferencing and returning the "this" pointer.
		//****************************************************
		return *this;
	}

	//****************************************************
	// In order to prevent a memory leak, delete is called for
	// the current instance of Portfolio's Stock array to 
	// deallocate the dynamic memory allocated for each element 
	// of the Stock array before a new array of Stock is created that
	// has size of the Stock array of the instance of 
	// Portfolio that was passed in/is on the right-hand side of the assignment operator.
	//****************************************************
	delete [] stock;
	
	//****************************************************
	// Setting the Stock pointer to NULL after a call to delete in order to 
	// prevent the Stock pointer from being a dangling pointer.
	//****************************************************
	stock = NULL;

	//****************************************************
	// Assigning stockSize the value of the size of the Stock array
	// of the instance of Portfolio that was passed in.
	//****************************************************
	stockSize = rhs.stockSize;

	//****************************************************
	// Creating a new array of Stock with the size of the Stock array 
	// of the instance of Portfolio that was passed in by calling
	// new for the Stock array and passing the stockSize member variable
	// into the brackets of the Stock array's initialization. This is possible
	// since the stockSize member variable was assigned the size of the
	// Stock array of the instance of Portfolio that was passed in.
	//****************************************************
	stock = new Stock[stockSize];

	//****************************************************
	// A for loop is used to assign the value of each index
	// of the new Stock array equal to the corresponding index of
	// the Stock array of instance of Portfolio that was passed in.
	//****************************************************
	for (int i = 0; i < stockSize; i++)
	{
		//****************************************************
		// Assigning each index of the new array of Stock
		// to have the value that the corresponding index of
		// the array of Stock that the instance of Portfolio
		// that was passed in has.
		//****************************************************
		stock[i] = rhs.stock[i];
	}

	//****************************************************
	// The "this pointer" contains the address of the current instance.
	// It is returned so that the current instance's Stock array can have
	// its values updated to the new values that it was assigned for each of its indexes.
	//****************************************************
	return *this;
}

//****************************************************
// Function: operator<<
//
// Purpose: To overload the insertion operator for the Portfolio class.
//			By overloading the insertion operator, an instance
//			of Portfolio can have the values of the elements of
//			its Stock array be printed on the given ostream.
//
// Runtime: O(n)
//
//****************************************************
std::ostream& operator<<(std::ostream& out, const Portfolio& rhs)
{
	//****************************************************
	// A for loop is used to go through each index
	// of the Stock array so that every element
	// of the Stock array can have its values printed.
	//****************************************************
	for (int i = 0; i < rhs.stockSize; i++)
	{
		// Printing each element of the Stock array on a new line.
		out << rhs.stock[i] << std::endl;
	}

	// Returning the given ostream so that Portfolio's Stock array values can be printed.
	return out;
}

//****************************************************
// Function: operator==
//
// Purpose: To overload the equality operator for the Portfolio class.
//			By overloading the equality operator, two instances
//			of Portfolio can have the values and size of their
//			Stock array compared to see if the two 
//			instances of Portfolio are equal or not.
//
// Runtime: O(n)
//
//****************************************************
bool operator==(const Portfolio& lhs, const Portfolio& rhs)
{
	// Declaring and initializing local bool variable equalityAnswer to false.
	bool equalityAnswer = false;
	// Declaring and initializing local integer variable equalStockCount to 0.
	int equalStockCount = 0;

	//****************************************************
	// If the stockSize for each instance of Portfolio
	// is equal, then the for loop that compares the equality
	// of each Stock in Portfolio's array should run.
	// If the stockSize of each instance of Portfolio is not equal,
	// then the instances of Portfolio are automatically not equal
	// and equalAnswer's value will remain false.
	//****************************************************
	if (lhs.stockSize == rhs.stockSize)
	{
		//****************************************************
		// A for loop is used to go through each index of the Stock
		// array so that the Stock instance at each index of the
		// Stock array can be compared for equality.
		//****************************************************
		for (int i = 0; i < lhs.stockSize; i++)
		{
			//****************************************************
			// If the Stock instance at each index of both Stock arrays
			// are equal, then 1 is added to the equalStockCount.
			//****************************************************
			if (lhs.stock[i] == rhs.stock[i])
			{
				++equalStockCount;
			}
		}

		//****************************************************
		// After the for loop terminates, if equalStockCount is
		// equal to size of the Stock array of either instance of Portfolio,
		// then each index of each Stock array had an equal values
		// for the instances of Stock at each index of the Stock array.
		// Therefore, equalityAnswer is set to true to reflect the equality
		// of the two instances of Portfolio.
		//****************************************************
		if (equalStockCount == lhs.stockSize)
		{
			equalityAnswer = true;
		}
	}

	// Returning the true or false value contained in the equalityAnswer variable.
	return equalityAnswer;
}

//****************************************************
// Function: ~Portfolio()
//
// Purpose: To be the destructor for Portfolio.
//			It deallocates the dynamic memory that was allocated
//			for each element of the Stock array in order to prevent a memory leak.
//
// Runtime: O(n)
//
//****************************************************
Portfolio::~Portfolio()
{
	//****************************************************
	// Brackets must be included after the call to delete
	// so that each element of the Stock array has its memory deallocated.
	//****************************************************
	delete [] stock;
}

//****************************************************
// Function: GetAuthor
//
// Purpose: To return the name of the author of this assignment.
//
// Runtime: O(1)
//
//****************************************************
std::string Portfolio::GetAuthor()
{
	return "Niki Jahanara";
}