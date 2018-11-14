//****************************************************
// File: StockList.cpp
//
// Purpose: To store the definitions of the functions and operator overloads of the StockList class.
//
// Written By: Niki Jahanara
//
// Compiler: Visual Studio Express 2013 (For Windows Desktop)
// 
//***************************************************

//***************************************************
// The StockList header file containing the StockList class's function prototypes
// must be included so that each function of the StockList class can be defined.
//***************************************************
#include"StockList.h"

//****************************************************
// Function: StockList()
//
// Purpose: To be the default constructor of the StockList class.
//			It creates an empty list by setting the length member variable to 0, 
//			and setting listData, which is a StockListNode pointer, to NULL
//			because listData cannot point to a first element in an empty list.
//
// Runtime: O(1)
//
//****************************************************
StockList::StockList()
{
	// An empty list does not have any elements so the length member variable is set to 0.
	length = 0;

	//****************************************************
	// The listData pointer must be set to NULL because an empty list 
	// does not have a first element for listData to point to.
	//****************************************************
	listData = NULL;
}

//****************************************************
// Function: StockList(const StockList& otherList)
//
// Purpose: To be the copy constructor of the StockList class.
//			A deep copy of the given instance of StockList's unsorted linked list is done
//			in order to create an unsorted linked list for the current instance of StockList.
//			The deep copy is performed through the use of the overloaded assignment operator.
//
// Runtime: O(n)
//
//****************************************************
StockList::StockList(const StockList& otherList)
{
	//****************************************************
	// The "this" pointer contains the address of the current instance.
	// By dereferencing the "this" pointer, the overloaded assignment operator can be used
	// to assign a deep copy of the given instance of StockList's unsorted linked list
	// to be the unsorted linked list of the current instance of StockList.
	//****************************************************
	*this = otherList;
}

//****************************************************
// Function: Clear
//
// Purpose: To empty the current instance of StockList's 
//			unsorted linked list of all of its StockListNode elements.
//			It also deallocates the dynamic memory of every 
//			StockListNode element that is deleted in order to prevent a memory leak.
//
// Runtime: O(n)
//
//****************************************************
void StockList::Clear()
{
	//****************************************************
	// Declaring a local pointer instance of StockListNode that will
	// be used to deallocate the dynamic memory of every StockListNode
	// element in the current instance of StockList's unsorted linked list.
	//****************************************************
	StockListNode *tempPtr;

	//****************************************************
	// A while loop is used to visit each element of 
	// the current instance of StockList's unsorted linked list.
	// The while loop terminates when listData is equal to NULL because 
	// when listData is equal to NULL, then there are no more elements 
	// in the current instance of StockList's unsorted linked list to delete.
	//****************************************************
	while (listData != NULL)
	{
		//****************************************************
		// The tempPtr StockListNode pointer is assigned the 
		// address of the StockListNode that listData is pointing to.
		//****************************************************
		tempPtr = listData;

		//****************************************************
		// The listData pointer is assigned the address of the
		// next StockListNode in the unsorted linked list to 
		// point to so that during the loop's next iteration, 
		// the tempPtr StockListNode pointer can be assigned
		// the address of the next StockListNode in the
		// unsorted linked list that must be deleted.
		//****************************************************
		listData = listData->next;

		//****************************************************
		// Calling delete on the tempPtr StockListNode pointer so
		// that the StockListNode element that tempPtr is pointing
		// to can have its dynamic memory be deallocated 
		// and removed from the unsorted linked list.
		//****************************************************
		delete tempPtr;
	}

	//****************************************************
	// The length member variable of the current instance of StockList must 
	// be assigned the value 0 to reflect that there are no elements in the
	// current instance of StockList's unsorted linked list after this method runs.
	//****************************************************
	length = 0;
}

//****************************************************
// Function: Length
//
// Purpose: To return the number of items in the current instance of StockList's unsorted linked list.
//
// Runtime: O(1)
//
//****************************************************
int StockList::Length() const
{
	//****************************************************
	// The length member variable is returned because it stores the number of 
	// elements that the current instance of StockList's unsorted linked list has.
	//****************************************************
	return length;
}

//****************************************************
// Function: Add(const Stock s)
//
// Purpose: To add the given instance of Stock to the
//			current instance of StockList's unsorted linked list.
//			The given instance of Stock is added to the front of 
//			the current instance of StockList's unsorted linked list.
//
// Runtime: O(1)
//
//****************************************************
void StockList::Add(const Stock s)
{
	//****************************************************
	// Declaring a local pointer instance of StockListNode
	// that will be used to add the given instance of Stock to the 
	// front of the current instance StockList's unsorted linked list.
	//****************************************************
	StockListNode *tempPtr;

	//****************************************************
	// Allocating dynamic memory for the new StockListNode that will be
	// added to the current instance of StockList's unsorted linked list
	// because a linked list allocates dynamic memory for all of its elements.
	//****************************************************
	tempPtr = new StockListNode;

	//****************************************************
	// Setting the the stockData of the new StockListNode to
	// be the instance of Stock that was passed into the function.
	//****************************************************
	tempPtr->stockData = s;

	//****************************************************
	// Because the new StockListNode is being added to the front
	// of the current instance of StockList's unsorted linked list, 
	// its next pointer is assigned the address listData is pointing 
	// to so that it can precede the StockListNode that is currently
	// the first element of the unsorted linked list.
	//****************************************************
	tempPtr->next = listData;

	//****************************************************
	// Assigning listData the address of the new StockListNode
	// that tempPtr is storing so that it points to it in order
	// to make the newly added StockListNode the first element
	// of the current instance of StockList's unsorted linked list.
	//****************************************************
	listData = tempPtr;

	//****************************************************
	// Incrementing the length member variable because a new element 
	// was added to the current instance of StockList's unsorted linked list.
	//****************************************************
	length++;
}

//****************************************************
// Function: Add(const StockList& otherList)
//
// Purpose: To overload the Add function to append all elements from the unsorted linked list of
//			the given instance of StockList to the front of the current instance of StockList's unsorted linked list.
//			The elements that exist in current instance of StockList before this function is called
//			are still in the current instance of StockList's unsorted linked list after the function call completes.
//			The unsorted linked list of the given instance of StockList also does not change after this method is run.
//			The appending of all elements of the given instance of StockList is done through a deep copy.
//
// Runtime: O(n)
//
//****************************************************
void StockList::Add(const StockList& otherList)
{
	//****************************************************
	// Declaring a local pointer instance of StockListNode that will be used
	// to visit each element of the given instance of StockList's unsorted linked list.
	// The location pointer is assigned the address the given instance of StockList's 
	// listData pointer member variable is storing so it can initially point to
	// the first element of the given instance of StockList's the unsorted linked list.
	//****************************************************
	StockListNode *location = otherList.listData;

	//****************************************************
	// The while loop terminates when location is equal to NULL
	// because the value NULL indicates that location has reached
	// the end of the given instance of StockList's unsorted linked list.
	//****************************************************
	while (location != NULL)
	{
		//****************************************************
		// The stockData of every StockListNode that the location pointer visits in
		// each iteration of the while loop is passed into a call to the Add function.
		// This is because the Add function is already defined to add an instance of
		// Stock to the front of the current instance of StockList's unsorted linked list.
		// The Add function can therefore add the stockData of every element in the 
		// given instance of StockList's unsorted linked list to the current instance 
		// of StockList's unsorted linked list via a deep copy.
		//****************************************************
		Add(location->stockData);

		//****************************************************
		// The location pointer is assigned the address of the next StockListNode 
		// in the given instance of StockList's unsorted linked list to point to so
		// that the stockData of the next StockListNode in the unsorted linked list
		// can be passed into the Add function during the next iteration of the loop.
		// This is repeated until location is equal to NULL so that every element
		// of the given instance of StockList's unsorted linked list can be added
		// to the front of the current instance of StockList's unsorted linked list.
		//****************************************************
		location = location->next;
	}
}

//****************************************************
// Function: FindByName
//
// Purpose: To find the Stock with the given name within the 
//			unsorted linked list of the current instance of StockList. 
//			If the Stock is found, then the result parameter will become populated
//			with data from the target Stock and the function will return the value true. 
//			If the target Stock is not found, the function will return the value false.
//
// Runtime: O(n)
//
//****************************************************
bool StockList::FindByName(std::string name, Stock &result) const
{
	//****************************************************
	// Declaring a local pointer instance of StockListNode that will be used
	// to visit each element of the current instance of StockList's unsorted linked list.
	// The location pointer is assigned the address the listData pointer member variable is
	// storing so it can initially point to the first element of the unsorted linked list.
	//****************************************************
	StockListNode *location = listData;

	//****************************************************
	// The while loop terminates when location is equal to NULL
	// because the value NULL indicates that location has reached
	// the end of the current instance of StockList's unsorted linked list.
	//****************************************************
	while (location != NULL)
	{
		//****************************************************
		// If a call to the getStockName function from the stockData of the StockListNode 
		// that location is pointing to returns a string that is equal to the given name, 
		// then the target Stock has been found. The result parameter is assigned 
		// the values of the target Stock and the value of true is returned 
		// to indicate that the target Stock has been found.
		//****************************************************
		if (location->stockData.getStockName() == name)
		{
			//****************************************************
			// Assigning the target Stock to the result parameter so 
			// that it can become populated with data from the target Stock.
			//****************************************************
			result = location->stockData;
			// Returning true to indicate that the target Stock has been found.
			return true;
		}

		//****************************************************
		// If a call to the getStockName function from the stockData of the StockListNode 
		// that location is pointing to does not return a string that is equal to the given name, 
		// then the target Stock has not been found yet. The location pointer is assigned the address of
		// the next StockListNode in the unsorted linked list to point to so that the next StockListNode's 
		// stockData can have its name member variable be checked during the next iteration of the loop.
		//****************************************************
		location = location->next;
	}

	//****************************************************
	// If the while loop terminates when location is equal to NULL, 
	// then the name member variable of every StockListNode's stockData in 
	// the unsorted linked list has been checked but the target Stock has not been found.
	// The value false is returned to indicate that the target 
	// Stock with the given name has not been found.
	//****************************************************
	return false;
}

//****************************************************
// Function: Delete
//
// Purpose: To delete the StockListNode containing the Stock that 
//			has the given name as the value of its name member variable
//			from the current instance of StockList's unsorted linked list.
//			The dynamic memory of the StockListNode that is deleted is
//			also deallocated in order to prevent a memory leak.
//
// Runtime: O(n)
//
//****************************************************
void StockList::Delete(std::string name)
{
	//****************************************************
	// Declaring a local pointer instance of StockListNode that will be used
	// to visit each element of the current instance of StockList's unsorted linked list.
	// The location pointer is assigned the address the listData pointer member variable 
	// is storing so it can initially point to the first element of the unsorted linked list.
	//****************************************************
	StockListNode *location = listData;
	//****************************************************
	// Declaring a second local pointer instance of StockListNode
	// that will be used to store the address of the StockListNode
	// that has the Stock with the given name and must be deleted.
	//****************************************************
	StockListNode *tempLocation;

	//****************************************************
	// If a call to the getStockName function from the stockData of the StockListNode 
	// that location is initially pointing to returns a string that is equal to the given name, 
	// then the target Stock to be deleted is the first element of the unsorted linked list.
	//****************************************************
	if (location->stockData.getStockName() == name)
	{
		//****************************************************
		// The tempLocation pointer is assigned the address that location is pointing to so that
		// the StockListNode with the target Stock is deleted when delete is called for tempLocation.
		//****************************************************
		tempLocation = location;
		//****************************************************
		// Because the first StockListNode element of the current instance of StockList's
		// unsorted linked list contains the target Stock and is going to be deleted,
		// listData is assigned the address of the next StockListNode in the unsorted 
		// linked list to point to so that the next StockListNode becomes the first elemenet 
		// of the unsorted linked list when delete is called on the tempLocation pointer.
		//****************************************************
		listData = listData->next;
	}
	//****************************************************
	// If a call to the getStockName function from the stockData of the StockListNode 
	// that location is initially pointing to does not return a string that is equal to the given name, 
	// then the target Stock to be deleted is not the first element of the unsorted linked list
	// and location must now visit all the other elements of the unsorted linked list in order
	// to find which element contains the target Stock that is to be deleted.
	//****************************************************
	else
	{
		//****************************************************
		// Because the address that the location pointer stores must be the address of the
		// StockListNode that precedes the StockListNode with the target Stock that is to be deleted,
		// the loop will only iterate while the the next pointer of the StockListNode 
		// that location is pointing to is not equal to NULL, 
		// and while a call to the getStockName function from the stockData of the 
		// next StockListNode returns a string that is not equal to the target name.
		//****************************************************
		while ((location->next != NULL) && ((location->next)->stockData.getStockName() != name))
		{
			//****************************************************
			// The location pointer is assigned the address of the next StockListNode 
			// in the unsorted linked list to point to so that the StockListNode that proceeds
			// the next StockListNode in the unsorted linked list can have its stockData's
			// name member variable checked during the next iteration of the loop and so that it
			// can be checked if location has reached the end of the unsorted linked list.
			//****************************************************
			location = location->next;
		}

		//****************************************************
		// If the next pointer of the StockListNode that location 
		// is pointing to is equal to NULL, then the location pointer
		// has reached the end of the unsorted linked list without
		// find a Stock that has the target name. 
		//****************************************************
		if (location->next == NULL)
		{
			//****************************************************
			// Nothing is returned in order to break out of the function
			// and to indicate that the Stock with the target name does not
			// exist in the current instance of StockList's unsorted linked list.
			//****************************************************
			return;
		}

		//****************************************************
		// Because location contains the address of the the StockListNode that 
		// precedes the StockListNode with the target Stock that is to be deleted,
		// tempLocation is assigned the address of the StockListNode that 
		// proceeds the StockListNode that location is pointing to so 
		// that it can be deleted when delete is called for tempLocation.
		//****************************************************
		tempLocation = location->next;

		//****************************************************
		// The next pointer of the StockListNode that location is pointing to is
		// updated to point to the StockListNode that proceeds the StockListNode
		// that is going to be deleted so that the linked structure of the
		// unsorted linked list can remain intact after the StockListNode
		// that tempLocation is pointing to is deleted.
		//****************************************************
		location->next = (location->next)->next;
	}

	//****************************************************
	// Calling delete on the tempLocation pointer because it is storing the address 
	// of the StockListNode that has the Stock with the target name that must be deleted.
	//****************************************************
	delete tempLocation;
	//****************************************************
	// The length member variable is decremented because a StockListNode was
	// deleted from the current instance of StockList's unsorted linked list.
	//****************************************************
	length--;
}

//****************************************************
// Function: operator<<
//
// Purpose: To overload the insertion operator for the StockList class.
//			By overloading the insertion operator, the given instance
//			of StockList can have the stockData values of each StockListNode
//			element in its unsorted linked list be printed to the given ostream.
//
// Runtime: O(n)
//
//****************************************************
std::ostream& operator<<(std::ostream& os, StockList& rhs)
{
	//****************************************************
	// Declaring a local pointer instance of StockListNode that will be used
	// to visit each element of the given instance of StockList's unsorted linked list.
	// The location pointer is assigned the address the given instance of StockList's 
	// listData pointer member variable is storing so it can initially point to
	// the first element of the given instance of StockList's the unsorted linked list.
	//****************************************************
	StockList::StockListNode *location = rhs.listData;

	// If location is equal to NULL, then the given instance of StockList has no elements and is empty.
	if (location == NULL)
	{
		//****************************************************
		// A message is printed to given ostream to indicate that 
		// the given instance of StockList has no elements and is empty.
		//****************************************************
		os << "The StockList is empty." << std::endl;
	}
	//****************************************************
	// If location is not equal to NULL, then the given instance of StockList 
	// is not empty and can have the stockData values of each of the elements
	// in its unsorted linked list be printed to the given ostream.
	//**************************************************** 
	else
	{
		//****************************************************
		// The while loop terminates when location is equal to NULL
		// because the value NULL indicates that location has reached
		// the end of the given instance of StockList's unsorted linked list.
		//****************************************************
		while (location != NULL)
		{
			//****************************************************
			// The stockData values of the instance of StockListNode that
			// location is pointing to is printed to the given ostream
			// because the insertion operator is also overloaded to
			// print each of the member variable values of an instance of Stock.
			//****************************************************
			os << location->stockData << std::endl;

			//****************************************************
			// The location pointer is assigned the address of the next StockListNode 
			// in the unsorted linked list to point to so that the next StockListNode's 
			// stockData can have its member variable values be printed to the 
			// given ostream during the next iteration of the loop.
			//****************************************************
			location = location->next;
		}
	}

	// Returning the given ostream so that the given StockList's unsorted linked list elements can be printed.
	return os;
}

//****************************************************
// Function: operator>>
//
// Purpose: To overload the extraction operator for the StockList class.
//			It is now defined to read in the member variable values for
//			an instance of Stock from the given istream, assign those values to a local
//			instance of Stock, and then add that local instance of Stock to the front of 
//			the current instance of StockList's unsorted linked list.
//			This is repeated within a loop that is used to read in the member variable values
//			for an instance of Stock that terminates when it reaches a whitespace.
//
// Runtime: O(n)
//
//****************************************************
std::istream& operator>>(std::istream& is, StockList& rhs)
{
	// Declaring a local instance of Stock.
	Stock extractStock;

	//****************************************************
	// The loop will iterate while the given istream can extract
	// member variable values to assign to the local instance of Stock.
	// The loop will terminate when the given istream cannot extract anymore
	// member variable values to assign to the local instance Stock,
	// such as when it reads in a whitespace.
	//****************************************************
	while (is >> extractStock)
	{
		//****************************************************
		// The Add function is called by the given instance of StockList
		// so that the local instance of Stock that just had member variable values
		// be read in and assigned to it by the given istream can be added to the 
		// given instance of StockList's unsorted linked list by passing
		// the local instance of Stock into the Add function's parameter.
		//****************************************************
		rhs.Add(extractStock);
	}

	//****************************************************
	// Returning the given istream so that the Stock instances that were read in
	// can be added to the unsorted linked list of the given instance of StockList.
	//****************************************************
	return is;
}

//****************************************************
// Function: operator=
//
// Purpose: To overload the assignment operator for the StockList class.
//			By overloading the assignment operator, the given instance
//			of StockList's unsorted linked list can be assigned
//			as the unsorted linked list of the current instance of StockList
//			through a deep copy of the given StockList's unsorted linked list.
//			All data in the current instance of StockList is also removed before
//			the deep copy of the given StockList's unsorted linked list is
//			added to the current instance of StockList's unsorted linked list.
//
// Runtime: O(n)
//
//****************************************************
StockList& StockList::operator=(const StockList& rhs)
{
	//****************************************************
	// A call to the Clear function is made first because all data in the current 
	// instance of StockList must first be removed, and the Clear function is already
	// defined to delete and deallocate the dynamic memory of all the elements in 
	// the current instance of StockList's unsorted linked list.
	//****************************************************
	Clear();

	//****************************************************
	// A call to the overloaded Add function is made next because all the elements of the
	// given instance of StockList must be added to the current instance of StockList's unsorted linked list,
	// and overloaded Add function is already defined to append all the elements of a given
	// instance of StockList to the front of the unsorted linked list of the current instance of StockList.
	//****************************************************
	Add(rhs);

	//****************************************************
	// The "this pointer" contains the address of the current instance.
	// It is returned so that the current instance of StockList can have
	// its unsorted linked list updated to be the deep copy of the
	// unsorted linked list of the given instance of StockList.
	//****************************************************
	return *this;
}

//****************************************************
// Function: ~StockList
//
// Purpose: To be the StockList class's destructor.
//			The destructor deletes and deallocates the dynamic memory of every StockListNode element in
//			the current instance of StockList's unsorted linked list in order to prevent a memory leak.
//
// Runtime: O(n)
//
//****************************************************
StockList::~StockList()
{
	//****************************************************
	// The Clear function is called in the destructor because
	// the Clear function is already defined to delete and
	// deallocate the dynamic memory of each StockListNode in the 
	// current instance of StockList's unsorted linked list.
	//****************************************************
	Clear();
}