//****************************************************
// File: StockStack.cpp
//
// Purpose: To store the definitions of the functions and operator overloads of the StockStack class.
//
// Written By: Niki Jahanara
//
// Compiler: Visual Studio Express 2013 (For Windows Desktop)
// 
//***************************************************

//***************************************************
// The StockStack header file containing the StockStack class's function prototypes
// must be included so that each function of the StockStack class can be defined.
//***************************************************
#include"StockStack.h"

//****************************************************
// Function: StockStack
//
// Purpose: To be the default constructor of the StockStack class.
//			It creates an empty but dynamically allocated array (or stack)
//			of Stock that has a maximum size of 10.
//
// Runtime: O(1)
//
//****************************************************
StockStack::StockStack()
{
	//****************************************************
	// The stackTop member variable contains the index of the element that is at the top of the stack.
	// Because an empty stack does not have any elements, stackTop must be assigned the value -1
	// to indicate that the stack of the current instance of StockStack is empty and does not have a top element.
	//****************************************************
	stackTop = -1;

	// The maxStackSize member variable is assigned a value of 10.
	maxStackSize = 10;

	//****************************************************
	// New is called for the Stock pointer member variable in order to allocate dynamic memory for each of its elements.
	// The maxStackSize member variable is passed into the brackets of the Stock array's initialization
	// in order to determine the maximum size of the current instance of StockStack's stack.
	//****************************************************
	stack = new Stock[maxStackSize];
}

//****************************************************
// Function: StockStack(int max)
//
// Purpose: To be a one parameter constructor of the StockStack class that takes a maximum stack size.
//			It takes an integer number and dynamically allocates the Stock array of the current instance
//			of StockStack to have the given maximum Stock array (or stack) size.
//
// Runtime: O(n)
//
//****************************************************
StockStack::StockStack(int max)
{
	//****************************************************
	// The stackTop member variable contains the index of the element that is at the top of the stack.
	// Because an empty stack does not have any elements, stackTop must be assigned the value -1
	// to indicate that the stack of the current instance of StockStack is empty and does not have a top element.
	//****************************************************
	stackTop = -1;

	// Assigning maxStackSize the value of the integer passed into the constructor.
	maxStackSize = max;

	//****************************************************
	// New is called for the Stock pointer member variable in order to allocate dynamic memory for each of its elements.
	// The maxStackSize member variable is passed into the brackets of the Stock array's initialization
	// in order to determine the maximum size of the current instance of StockStack's stack.
	//****************************************************
	stack = new Stock[maxStackSize];
}

//****************************************************
// Function: StockStack(const StockStack& rhs)
//
// Purpose: To be the copy constructor of the StockStack class.
//			It assigns a deepy copy of the given instance of StockStack's Stock array/stack to the current
//			instance of StockStack's Stock array/stack through the use of the overloaded assignment operator.
//			The maxStackSize and stackTop member variables of the current instance of StockStack are
///			also assigned the given instance of StockStack's maxStackSize and stackTop 
//			member variable values through the use of the overloaded assignment operator.
//			
// Runtime: O(n)
//
//****************************************************
StockStack::StockStack(const StockStack& rhs)
{
	//****************************************************
	// The "this" pointer contains the address of the current instance.
	// By dereferencing the "this" pointer, the overloaded assignment operator
	// can be used to assign a deep copy of the given instance of StockStack's
	// stack to be the stack of the current instance of StockStack.
	// It also assigns the values of the maxStackSize and stackTop
	// member variables of the given instance of StockStack to the
	// current instance of StockStack's maxStackSize and stackTop member variables.
	//****************************************************
	*this = rhs;
}

//****************************************************
// Function: Clear
//
// Purpose: To logically empty the current instance of StockStack's Stock array/stack of all of its elements.
//			This function does not actually delete the Stock data located in the indexes 
//			of the current instance of StockStack's stack.
//			Instead, it sets the stackTop member variable back to -1 so that any data still located 
//			in the indexes of the stack cannot be accessed anymore after the function is called.
//
// Runtime: O(1)
//
//****************************************************
void StockStack::Clear()
{
	//****************************************************
	// Assigning a value of -1 to the stackTop member variable so that the
	// current instance of StockStack's stack can be logically cleared of all of its elements.
	// This will allow for the proceeding indexes of the stack
	// to be overwritten with new Stock data when the Push method is called.
	//****************************************************
	stackTop = -1;
}

//****************************************************
// Function: Size
//
// Purpose: To return the number of elements that are currently occupying the
//			indexes of the current instance of StockStack's Stock array/stack.
//			This function does not return the maximum size of the stack.
//			It returns the "logical" size of the stack, which is the number of
//			indexes in the stack that are currently occupied with a Stock object.
//			
// Runtime: O(1)
//
//****************************************************
int StockStack::Size()
{
	//****************************************************
	// Because an array's indexes are 0 based, 1 must be added to the
	// stackTop member variable before it is returned by the function so
	// that the logical size of the current instance of StockStack's stack
	// can be returned instead of the actual index of the top element of the stack.
	//****************************************************
	return stackTop + 1;
}

//****************************************************
// Function: MaxStorage
//
// Purpose: To return the maximum number of elements the current 
//			instance of StockStack's Stock array/stack can hold. 
//			The actual number of elements the stack can possibly hold is returned,
//			not the number of indexes in the stack that are currently occupied 
//			with a Stock object (which is the "logical" size of the stack).
//
// Runtime: O(1)
//
//****************************************************
int StockStack::MaxStorage()
{
	//****************************************************
	// Because the maxStackSize member variable stores the actual size
	// of the current instance of StockStack's stack, it is returned.
	//****************************************************
	return maxStackSize;
}

//****************************************************
// Function: Push
//
// Purpose: To add the given Stock object to the top of 
//			the current instance of StockStack's Stock array/stack. 
//			If it successfully adds the Stock object to the top of the stack, 
//			the value true is returned.
//			If the stack is full, the Stock object is not added in order to
//			prevent a stack overflow, and the value false is returned.
//
// Runtime: O(1)
//
//****************************************************
bool StockStack::Push(Stock s)
{
	//****************************************************
	// The stackTop member variable has reached the end of the 
	// current instance of StockStack's stack size when
	// it is one less than the maxStackSize member variable's value.
	// If this condition evaluates to true, then the stack is full
	// and the given Stock object is not added to the top of the
	// stack in order to prevent a stack overflow. 
	//****************************************************
	if (stackTop == (maxStackSize - 1))
	{
		//****************************************************
		// Returning false to indicate that the given Stock object was
		// not added to the top of the stack because the current
		// instance of StockStack's stack is full.
		//****************************************************
		return false;
	}
	//****************************************************
	// If the above condition evaluates to false, then the current instance of StockStack's stack
	// is not full and the given Stock object can be added to the top of the stack. 
	//****************************************************
	else
	{
		//****************************************************
		// Incrementing the stackTop member variable so that it can store the index of
		// the new top element of the current instance of StockStack's stack.
		//****************************************************
		stackTop++;

		//****************************************************
		// Assigning the given Stock object to the new top index of the
		// stack, which is stored in the stackTop member variable.
		//****************************************************
		stack[stackTop] = s;

		//****************************************************
		// Returning true to indicate that the given Stock object was successfully
		// added to the top of the current instance of StockStack's stack.
		//****************************************************
		return true;
	}
}

//****************************************************
// Function: Pop
//
// Purpose: To logically remove the top element of the current instance of StockStack's Stock array/stack. 
//			If it successfully removes the top element of the stack by decrementing the value of
//			the stackTop member variable (in order to make the index of the top element inaccessible), 
//			the value true is returned.
//			If the stack is empty, the value false is returned in order to prevent a stack underflow.
//
// Runtime: O(1)
//
//****************************************************
bool StockStack::Pop()
{
	//****************************************************
	// If the value contained in the stackTop member variable is -1, 
	// then the current instance of StockStack's stack is empty and the
	// stackTop member variable is not be decremented in order to prevent a stack underflow.
	//****************************************************
	if (stackTop == -1)
	{
		//****************************************************
		// Returning false to indicate that the top element of the 
		// the current instance of StockStack's stack could not 
		// be logically removed because the stack is empty.
		//****************************************************
		return false;
	}
	//****************************************************
	// If the above condition evaluates to false, then the current instance of StockStack's stack 
	// is not empty and the top element of stack can be logically removed by decrementing the stackTop
	// member variable so that the index of the top element is no longer accessible. 
	//****************************************************
	else
	{
		//****************************************************
		// Decrementing stackTop in order to logically remove the top element
		// from the the current instance of StockStack's stack.
		//****************************************************
		stackTop--;

		//****************************************************
		// Returning true to indicate that the top element of the 
		// the current instance of StockStack's stack was logically removed.
		//****************************************************
		return true;
	}
}

//****************************************************
// Function: Top
//
// Purpose: To return the top element of the current instance of StockStack's Stock array/stack without removing it. 
//			The returnedStock parameter will contain a copy of the top element of the stack after the function is called. 
//			The function will return true if it able to assign a copy of the top element to the returnedStock parameter.
//			It will return false if the stack is empty, because an empty stack does not have a top element
//			that can be assigned to the returnedStock parameter.
//
// Runtime: O(1)
//
//****************************************************
bool StockStack::Top(Stock& returnedStock)
{
	//****************************************************
	// If the value contained in the stackTop member variable is -1, 
	// then the current instance of StockStack's stack is empty and
	// there is no top element that can be assigned to the returnedStock parameter.
	//****************************************************
	if (stackTop == -1)
	{
		//****************************************************
		// Returning false to indicate that there is no top element to assign
		// to the returnedStock parameter because the current instance of StockStack's stack is empty.
		//****************************************************
		return false;
	}
	//****************************************************
	// If the above condition evaluates to false, then the current instance of StockStack's stack 
	// is not empty and the top element of stack can be assigned to the returnedStock parameter.
	//****************************************************
	else
	{
		//****************************************************
		// Assigning the top element of the current instance of StockStack's stack,
		// which is the Stock located at the index of the Stock array that the
		// stackTop member variable is storing, to the returnedStock parameter.
		//****************************************************
		returnedStock = stack[stackTop];

		//****************************************************
		// Returning true to indicate that the top element in the current instance
		// of StockStack's stack was successfully assigned to the returnedStock parameter.
		//****************************************************
		return true;
	}
}

//****************************************************
// Function: operator=
//
// Purpose: To overload the assignment operator for the StockStack class.
//			By overloading the assignment operator, a deep copy of the 
//			given instance of StockStack can be made so that the
//			maximumStackSize, stackTop, and Stock array/stack data of
//			the current instance of StockStack can be equal to the given instance 
//			of StockStack's maximumStackSize, stackTop, and Stock array/stack data.
//			Any data in the current instance of StockStack is also removed before 
//			the deep copy of the given instance of StockStack's Stock array/stack is performed.
//			
// Runtime: O(n)
//
//****************************************************
StockStack& StockStack::operator=(const StockStack& rhs)
{
	//****************************************************
	// Because the "this" pointer contains the address of the current instance,
	// if the address of the instance of StockStack on the right-hand side
	// of the assignment operator is equal to the address that the "this" pointer
	// is storing then the two instances of StockStack have the same address and
	// therefore already have the same values for their member variables.
	// This if statement therefore avoids an unecessary self-assignment.
	//****************************************************
	if (this == &rhs)
	{
		//****************************************************
		// Because a self-assignment is unnecessary,
		// the values of the current instance of StockStack
		// are returned without any additional assignments by 
		// dereferencing and returning the "this" pointer.
		//****************************************************
		return *this;
	}

	//****************************************************
	// In order to both prevent a memory leak and to clear the current
	// instance of StockStack of its stack data, delete is
	// called for the current instance of StockStack's Stock array.
	// This will deallocate the dynamic memory allocated for each element 
	// of the Stock array before a new array of Stock is created that has
	// the maxStackSize of the Stock array of the given instance of StockStack.
	//****************************************************
	delete [] stack;

	//****************************************************
	// Setting the Stock pointer to NULL after a call to delete in order to 
	// prevent the Stock pointer from being a dangling pointer.
	//****************************************************
	stack = NULL;

	//****************************************************
	// Assigning the value of the maxStackSize member variable of the
	// given instance of StockStack to the current instance of
	// StockStack's maxStackSize member variable.
	//****************************************************
	maxStackSize = rhs.maxStackSize;

	//****************************************************
	// Assigning the value of the stackTop member variable of the
	// given instance of StockStack to the current instance of
	// StockStack's stackTop member variable.
	//****************************************************
	stackTop = rhs.stackTop;

	//****************************************************
	// Creating a new array (or stack) of Stock with the size of the
	// Stock array/stack of the given instance of StockStack by calling new and 
	// passing the maxStackSize member variable into the brackets of the 
	// Stock array's initialization after the maxStockSize member variable 
	// was assigned the maxStackSize of the Stock array of the given instance of StockStack.
	//****************************************************
	stack = new Stock[maxStackSize];

	//****************************************************
	// A for loop is used to assign the stack data of the given instance
	// of StockStack to the current instance of StockStack's stack.
	// Only the data that is currently occupying the stack of the
	// given instance of StockStack is copied into the corresponding
	// indexes of the current instance of StockStack's stack however.
	// This is accomplished by having it only copy the values in the
	// indexes of the stack that are less than or equal to the value of stackTop,
	// which contains the index of the last element currently on the 
	// given instance of StockStack's stack.
	//****************************************************
	for (int i = 0; i <= stackTop; i++)
	{
		//****************************************************
		// Assigning the new Stock array's indexes (that are less than or equal to the value
		// of the stackTop member variable) to have the value of the corresponding index of
		// the Stock array that the instance of StockStack that was passed in has.
		//****************************************************
		stack[i] = rhs.stack[i];
	}

	//****************************************************
	// The "this" pointer contains the address of the current instance.
	// It is returned so that the current instance of StockStack's Stock array/stack
	// can have its values updated to the new values that it was assigned for its indexes.
	//****************************************************
	return *this;
}

//****************************************************
// Function: operator<<
//
// Purpose: To overload the insertion operator for the StockStack class.
//			By overloading the insertion operator, an instance
//			of StockStack can have the values in the indexes of
//			its Stock array/stack be printed on the given ostream.
//
// Runtime: O(n)
//
//****************************************************
std::ostream& operator<<(std::ostream& os, StockStack& rhs)
{
	//****************************************************
	// If the value contained in the stackTop member variable is -1, 
	// then the current instance of StockStack's stack is empty 
	// and there are no elements that can be printed onto the given ostream.
	//****************************************************
	if (rhs.stackTop == -1)
	{
		//****************************************************
		// A message indicating that the current instance of StockStack's
		// stack is empty is printed onto the given ostream.
		//****************************************************
		os << "The Stack is empty." << std::endl;
	}
	//****************************************************
	// If the above condition evaluates to false, then the current instance of StockStack's stack 
	// is not empty and the elements of the stack can be printed onto the given ostream.
	//****************************************************
	else
	{
		//****************************************************
		// A for loop is used to go through each index of the stack so that
		// each element logically occupying the stack can have its values printed.
		// Because the loop is initialized to begin with the index of the stackTop
		// member variable, the top element of the stack will always be printed first,
		// followed by the elements that precede its index in descending order.
		//****************************************************
		for (int i = rhs.stackTop; i >= 0; i--)
		{
			// Printing each element of the stack on a new line.
			os << rhs.stack[i] << std::endl;
		}
	}

	// Returning the given ostream so that StockStack's stack elements can be printed.
	return os;
}

//****************************************************
// Function: ~StockStack
//
// Purpose: To be the destructor of the StockStack class.
//			The destructor deallocates the dynamic memory of the 
//			current instance of StockStack's Stock array/stack
//			in order to prevent a memory leak.
//
// Runtime: O(n)
//
//****************************************************
StockStack::~StockStack()
{
	//****************************************************
	// Brackets must be included after the call to delete
	// so that each element of the Stock array/stack has its memory deallocated.
	//****************************************************
	delete [] stack;
}