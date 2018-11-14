//***************************************************
// File: Main.cpp
//
// Purpose: To perform tests on the:
//			Stock class's equality operator overload.
//			StockStack class's default constructor, one parameter constructor, 
//			copy constructor, assignment operator overload, insertion operator overload,
//			Clear, Size, MaxStorage, Push, Pop, and Top function.
//			StockQueue class's default constructor, copy constructor, 
//			assignment operator overload, insertion operator overload,
//			Clear, Size, Enqueue, and Dequeue function.
//
// Written By: Niki Jahanara
//
// Compiler: Visual Studio Express 2013 (For Windows Desktop)
//
//***************************************************

#include<iomanip>
#include<fstream>
#include<iostream>
//***************************************************
// The header file of the Portfolio class must be included
// so that instances of Portfolio can be made inside main.
//***************************************************
#include"Portfolio.h"
//***************************************************
// The header file of the StockStack class must be included
// so that instances of StockStack can be made inside main.
//***************************************************
#include "StockStack.h"
//***************************************************
// The header file of the StockQueue class must be included
// so that instances of StockQueue can be made inside main.
//***************************************************
#include "StockQueue.h"

using namespace std;

//****************************************************
// Function: main
//
// Purpose: To perform tests on the:
//			Stock class's equality operator overload.
//			StockStack class's default constructor, one parameter constructor, 
//			copy constructor, assignment operator overload, insertion operator overload,
//			Clear, Size, MaxStorage, Push, Pop, and Top function.
//			StockQueue class's default constructor, copy constructor, 
//			assignment operator overload, insertion operator overload,
//			Clear, Size, Enqueue, and Dequeue function.
//
//****************************************************
int main()
{
	//****************************************************
	//
	//			STOCK CLASS AUTOMATED UNIT TEST
	// 
	//****************************************************

	//****************************************************
	//
	//	TEST # 1: Stock's Equality Operator Overload.
	// 
	//****************************************************

	cout << setw(46) << "Stock Class Test" << endl << setw(46) << "----------------" << endl << endl
		 << "*-------------- TEST # 1: Stock Equality Operator Overload Test --------------*" << endl << endl;

	// Delcaring and initializing a string variable that will be used to test Stock's equality operator overload.
	string testName = "Amazon";

	//****************************************************
	// Delcaring and initializing an instance of Stock that will be used to test Stock's equality operator overload.
	// The testName variable is used to assign a value to this instance of Stock's stockName member variable.
	//****************************************************
	Stock equalityStockTest1(testName, 100, 200);

	//****************************************************
	// Delcaring and initializing a second instance of Stock that will be used to test Stock's equality operator overload.
	// The testName variable is also used to assign a value to this instance of Stock's stockName member variable.
	// This second instance of Stock also has different values for its stockPrice and stockShare member variables.
	//****************************************************
	Stock equalityStockTest2(testName, 500, 800);

	cout << "Testing The Equality Of Two Stock Instances" << endl << "-------------------------------------------" << endl;

	//****************************************************
	// The overloaded equality operator for Stock only checks for the equality of each Stock's stockName member variable value.
	// If the expression evaluates to true, then Stock's overloaded equality operator is working correctly because
	// the two instances of Stock used in the expression have the same value for their stockName member variable.
	// A message is printed to the console to indicate that Stock's overloaded equality operator is working correctly.
	//****************************************************
	if (equalityStockTest1 == equalityStockTest2)
	{
		cout << "Stock Equality Operator Overload: Pass." << endl << endl;
	}
	//****************************************************
	// If the expression evaluates to false, a message is printed to the console
	// to indicate that Stock's overloaded equality operator is not working correctly.
	//****************************************************
	else
	{
		cout << "Stock Equality Operator Overload: FAIL!" << endl << endl;
	}

	cout << "Testing The Inequality Of Two Stock Instances" << endl << "---------------------------------------------" << endl;

	//****************************************************
	// Changing the stockName member variable value of the second instance of Stock through a call to the
	// setStockName function to test if the overloaded equality operator returns false
	// correctly when two instances of Stock do not have an equal stockName member variable value.
	//****************************************************
	equalityStockTest2.setStockName("Different Name");

	//****************************************************
	// If the expression evaluates to true, then Stock's overloaded equality operator not is working correctly because
	// the two instances of Stock used in the expression do not have the same value for their stockName member variable anymore.
	// A message is printed to the console to indicate that Stock's overloaded equality operator is not working correctly.
	//****************************************************
	if (equalityStockTest1 == equalityStockTest2)
	{
		cout << "Stock Equality Operator Overload: FAIL!" << endl << endl;
	}
	//****************************************************
	// If the expression evaluates to false, a message is printed to the console
	// to indicate that Stock's overloaded equality operator is working correctly.
	//****************************************************
	else
	{
		cout << "Stock Equality Operator Overload: Pass." << endl << endl;
	}

	//****************************************************
	//
	//			STOCKSTACK CLASS UNIT TESTS
	// 
	//****************************************************
	
	cout << setw(50) << "StockStack Class Tests" << endl << setw(50) << "----------------------" << endl;

	//****************************************************
	//
	//	TEST # 2: StockStack's Default Constructor.
	// 
	//****************************************************

	cout << endl << "*--------------- TEST # 2: StockStack Default Constructor Test ---------------*" << endl << endl;

	// Declaring an instance of StockStack that will be used to test StockStack's default constructor.
	StockStack ssDefaultConstructorTest;

	// Declaring an instance of Stock that will be used in the test of StockStack's default constructor.
	Stock stackDefaultTest;

	//****************************************************
	// If a call to the Top function from the ssDefaultConstructorTest instance of StockStack returns false,
	// then the default constructor of StockStack correctly created an empty stack that does not have a top element.
	// If a call to the MaxStorage function from the ssDefaultConstructorTest instance of StockStack also returns 10,
	// then the default constructor of StockStack also correctly created a stack with a maximum size of 10.
	//****************************************************
	if ((ssDefaultConstructorTest.Top(stackDefaultTest) == false) && (ssDefaultConstructorTest.MaxStorage() == 10))
	{
		//****************************************************
		// The insertion operator of the StockStack class is overloaded to output a message indicating 
		// when an instance of StockStack has an empty stack. The value returned by the MaxStorage function 
		// is also printed to the console to show what the maximum size of a stack is 
		// when it is created with the default constructor of StockStack.
		//****************************************************
		cout << ssDefaultConstructorTest << "The default maxiumum stack size is " << ssDefaultConstructorTest.MaxStorage() << "." << endl;
	}
	//****************************************************
	// If the above expression evaluates to false, a message indicating that 
	// StockStack's default constructor did not correctly create an
	// empty stack with a maximum size of 10 is output to the console.
	//****************************************************
	else
	{
		cout << "StockStack Default Constructor Test: FAIL!" << endl;
	}

	//****************************************************
	//
	//	TEST # 3: StockStack's One Parameter Constructor.
	// 
	//****************************************************

	cout << endl << "*------------ TEST # 3: StockStack One Parameter Constructor Test ------------*" << endl << endl;

	//****************************************************
	// Declaring an instance of StockStack that will be used to test StockStack's one parameter constructor.
	// The number 20 is passed into the StockStack instance's one parameter constructor to create a stack with a maximum size of 20.
	//****************************************************
	StockStack ssOneParameterConstructorTest(20);

	// Declaring an instance of Stock that will be used in the test of StockStack's one parameter constructor.
	Stock oneParameterTest;

	//****************************************************
	// If a call to the Top function from the ssOneParameterConstructorTest instance of StockStack returns false,
	// then the one parameter constructor of StockStack correctly created an empty stack that does not have a top element.
	// If a call to the MaxStorage function from the ssOneParameterConstructorTest instance of StockStack also returns 20,
	// then the one parameter constructor of StockStack correctly created a stack with the given size of 20.
	//****************************************************
	if ((ssOneParameterConstructorTest.Top(oneParameterTest) == false) && (ssOneParameterConstructorTest.MaxStorage() == 20))
	{
		//****************************************************
		// The insertion operator of the StockStack class is overloaded to output a message indicating 
		// when an instance of StockStack has an empty stack. The value returned by the MaxStorage function 
		// is also printed to the console to show what the maximum size of a stack is 
		// when it is created with the one parameter constructor of StockStack.
		//****************************************************
		cout << ssOneParameterConstructorTest << "The maxiumum stack size is " << ssOneParameterConstructorTest.MaxStorage() << "." << endl;
	}
	//****************************************************
	// If the above expression evaluates to false, a message indicating that 
	// StockStack's default constructor did not correctly create an
	// empty stack with the given size of 20 is output to the console.
	//****************************************************
	else
	{
		cout << "StockStack One Parameter Constructor Test: FAIL!" << endl;
	}

	//****************************************************
	//
	//	TEST # 4: StockStack's Copy Constructor.
	// 
	//****************************************************

	cout << endl << "*----------------- TEST # 4: StockStack Copy Constructor Test ----------------*" << endl << endl;

	//****************************************************
	// Declaring the first instance of StockStack that will be used to test StockStack's copy constructor.
	// The number 5 is passed into the StockStack instance's one parameter constructor to create a stack with a maximum size of 5.
	//****************************************************
	StockStack copiedStockStack(5);

	// Declaring and initializing three instances of Stock that will be used for StockStack's copy constructor test.
	Stock copiedStock1("Copied Stack Stock 1", 200, 400);
	Stock copiedStock2("Copied Stack Stock 2", 500, 300);
	Stock copiedStock3("Copied Stack Stock 3", 700, 100);

	//****************************************************
	// Adding each of the three instances of Stock to the first instance of StockStack's stack
	// by passing each instance of Stock into a call to the first instance of StockStack's Push function.
	//****************************************************
	copiedStockStack.Push(copiedStock1);
	copiedStockStack.Push(copiedStock2);
	copiedStockStack.Push(copiedStock3);

	//****************************************************
	// Printing the elements of the first instance of StockStack's stack and 
	// the maximum size of the first instance of StockStack's stack to the console.
	//****************************************************
	cout << "The Instance of StockStack Being Copied" << endl << "---------------------------------------" << endl << copiedStockStack
		 << "The maximum stack size is " << copiedStockStack.MaxStorage() << "." << endl << endl;

	//****************************************************
	// Declaring the second instance of StockStack that will be used to test StockStack's copy constructor and
	// initializing it by passing the first instance of StockStack into its copy constructor.
	//****************************************************
	StockStack ssCopyConstructorTest(copiedStockStack);

	//****************************************************
	// Printing the stack elements of the instance of StockStack initialized with
	// the copy constructor to the console to show that it has the same elements
	// and the same maximum stack size as the instance of StockStack that was passed into its copy constructor.
	//****************************************************
	cout << "The Instance of StockStack Initialized With The Copy Constructor" << endl << "----------------------------------------------------------------" << endl 
		 << ssCopyConstructorTest << "The maximum stack size is " << ssCopyConstructorTest.MaxStorage() << "." << endl << endl;

	//****************************************************
	//
	//	TEST # 5: StockStack's Clear Function.
	// 
	//****************************************************

	cout << endl << "*----------------- TEST # 5: StockStack Clear Function Test -----------------*" << endl << endl;

	// Declaring an instance of StockStack that will be used to test StockStack's Clear function.
	StockStack ssClearTest;

	// Declaring and initializing two instances of Stock that will be used for StockStack's Clear function test.
	Stock clearStock1("Clear Stock 1", 400, 500);
	Stock clearStock2("Clear Stock 2", 300, 200);

	//****************************************************
	// Adding each of the two instances of Stock to the instance of StockStack's stack
	// by passing each instance of Stock into a call to the instance of StockStack's Push function.
	//****************************************************
	ssClearTest.Push(clearStock1);
	ssClearTest.Push(clearStock2);

	// Printing the elements and size of the instance of StockStack to the console before the Clear function is called.
	cout << "The Instance of StockStack Before Calling Clear" << endl << "-----------------------------------------------" << endl << ssClearTest
		 << "The stack has " << ssClearTest.Size() << " elements." << endl << endl;

	// Calling the Clear function from the instance of StockStack to logically clear its stack.
	ssClearTest.Clear();

	//****************************************************
	// Printing the elements and size of the instance of StockStack to the console after a call to the Clear function.
	// The insertion operator of the StockStack class is overloaded to output a message indicating 
	// when an instance of StockStack has an empty stack, which is what should be output after Clear is called.
	//****************************************************
	cout << "The Instance of StockStack After Calling Clear" << endl << "----------------------------------------------" << endl << ssClearTest
		 << "The stack has " << ssClearTest.Size() << " elements." << endl << endl;

	//****************************************************
	//
	//	TEST # 6: StockStack's Size & MaxStorage Function
	// 
	//****************************************************

	cout << endl << "*----------- TEST # 6: StockStack Size & MaxStorage Function Test -----------*" << endl << endl;

	//****************************************************
	// Declaring an instance of StockStack that will be used to test StockStack's Size and MaxStorage function.
	// The number 15 is passed into the StockStack instance's one parameter constructor to create a stack with a maximum size of 15.
	//****************************************************
	StockStack ssSizeTest(15);

	// Declaring and initializing three instances of Stock that will be used for StockStack's Size and MaxStorage function test.
	Stock stockElement1("Stock 1", 10, 20);
	Stock stockElement2("Stock 2", 30, 40);
	Stock stockElement3("Stock 3", 50, 60);

	//****************************************************
	// Adding each of the three instances of Stock to the instance of StockStack's stack
	// by passing each instance of Stock into a call to the instance of StockStack's Push function.
	//****************************************************
	ssSizeTest.Push(stockElement1);
	ssSizeTest.Push(stockElement2);
	ssSizeTest.Push(stockElement3);

	//****************************************************
	// Printing the elements of the instance of StockStack to the console.
	// Because three Stock objects were pushed onto the Stack, the call to
	// the Size function from the instance of StockStack should return 3.
	// The call to the MaxStorage function from the instance of StockStack should return 15.
	//****************************************************
	cout << "The Instance of StockStack" << endl << "--------------------------" << endl << ssSizeTest
		 << "The stack has " << ssSizeTest.Size() << " elements." << endl
		 << "The maximum stack size is " << ssSizeTest.MaxStorage() << "." << endl;

	//****************************************************
	//
	//	TEST # 7: StockStack's Push Function.
	// 
	//****************************************************

	cout << endl << "*------------------ TEST # 7: StockStack Push Function Test ------------------*" << endl << endl;

	//****************************************************
	// Declaring the instance of StockStack that will be used to test StockStack's Push function.
	// The number 2 is passed into the StockStack instance's one parameter constructor to create a stack with a maximum size of 2.
	//****************************************************
	StockStack ssPushTest(2);

	// Declaring and initializing three instances of Stock that will be used for StockStack's Push function test.
	Stock pushedStock1("Stock 1", 120, 100);
	Stock pushedStock2("Stock 2", 110, 200);
	Stock pushedStock3("Stock 3", 130, 300);

	// Printing the first Stock object that is going to be added to the instance of StockStack's stack to the console.
	cout << "Adding... " << endl << endl << pushedStock1 << endl;

	//****************************************************
	// If the first call to Push is able to add the first instance of Stock to the instance of StockStack's stack,
	// the value true will be returned by the function. A message indicating that the first instance of
	// Stock was successfully added to the stack will also be output to the console.
	//****************************************************
	if (ssPushTest.Push(pushedStock1))
	{
		cout << "The Stock has successfully been pushed onto to the stack!" << endl << endl;
	}
	//****************************************************
	// If the above expression evaluates to false, then the instance of StockStack's stack
	// is full and the Stock object was not added to the stack in order to prevent a stack overflow.
	//****************************************************
	else
	{
		//****************************************************
		// A message indicating that the stack is full will be output to the console,
		// as well as the maximum size of the stack returned by the MaxStorage function.
		//****************************************************
		cout << "The stack is full. The Stock cannot be pushed onto the stack." << endl
			 << "The maximum stack size is " << ssPushTest.MaxStorage() << "." << endl << endl;
	}
	
	// Printing the second Stock object that is going to be added to the instance of StockStack's stack to the console.
	cout << "Adding... " << endl << endl << pushedStock2 << endl;

	//****************************************************
	// If a second call to Push is able to add the second instance of Stock to the instance of StockStack's stack,
	// the value true will be returned by the function. A message indicating that the second instance of
	// Stock was successfully added to the stack will also be output to the console.
	//****************************************************
	if (ssPushTest.Push(pushedStock2))
	{
		cout << "The Stock has successfully been pushed onto to the stack!" << endl << endl;
	}
	//****************************************************
	// If the above expression evaluates to false, then the instance of StockStack's stack
	// is full and the Stock object was not added to the stack in order to prevent a stack overflow.
	//****************************************************
	else
	{
		//****************************************************
		// A message indicating that the stack is full will be output to the console,
		// as well as the maximum size of the stack returned by the MaxStorage function.
		//****************************************************
		cout << "The stack is full. The Stock cannot be pushed onto the stack." << endl 
			 << "The maximum stack size is " << ssPushTest.MaxStorage() << "." << endl << endl;
	}
	
	// Printing the third Stock object that is going to be added to the instance of StockStack's stack to the console.
	cout << "Adding... " << endl << endl << pushedStock3 << endl;

	//****************************************************
	// If a third call to Push is able to add the third instance of Stock to the instance of StockStack's stack,
	// the value true will be returned by the function. A message indicating that the third instance of
	// Stock was successfully added to the stack will also be output to the console.
	//****************************************************
	if (ssPushTest.Push(pushedStock3))
	{
		cout << "The Stock has successfully been pushed onto to the stack!" << endl << endl;
	}
	//****************************************************
	// If the above expression evaluates to false, then the instance of StockStack's stack
	// is full and the Stock object was not added to the stack in order to prevent a stack overflow.
	//****************************************************
	else
	{
		//****************************************************
		// A message indicating that the stack is full will be output to the console,
		// as well as the maximum size of the stack returned by the MaxStorage function.
		//****************************************************
		cout << "The stack is full. The Stock cannot be pushed onto the stack." << endl
			 << "The maximum stack size is " << ssPushTest.MaxStorage() << "." << endl << endl;
	}

	//****************************************************
	// Because the instance of StockStack was initialized with a maximum size of 2 for its stack,
	// there should only be 2 elements in the instance of StockStack's stack even if the Push
	// function was called 3 times. The call to the Size and MaxStorage functions should return
	// the same integer number because the logical size of the stack is currently equal
	// to the maximum size of the stack since the stack is full.
	//****************************************************
	cout << "The Instance of StockStack After Calling Push 3 Times" << endl << "-----------------------------------------------------" << endl << ssPushTest
		 << "There are only " << ssPushTest.Size() << " elements in the stack because the maximum stack size is " << ssPushTest.MaxStorage() << "." << endl;

	//****************************************************
	//
	//	TEST # 8: StockStack's Pop Function.
	// 
	//****************************************************

	cout << endl << "*------------------- TEST # 8: StockStack Pop Function Test ------------------*" << endl << endl;

	//****************************************************
	// Declaring the instance of StockStack that will be used to test StockStack's Pop function.
	// The number 2 is passed into the StockStack instance's one parameter constructor to create a stack with a maximum size of 2.
	//****************************************************
	StockStack ssPopTest(2);

	// Declaring and initializing two instances of Stock that will be used for StockStack's Pop function test.
	Stock poppedStock1("Popped Stock 1", 700, 800);
	Stock poppedStock2("Popped Stock 2", 600, 500);

	//****************************************************
	// Adding each of the two instances of Stock to the instance of StockStack's stack
	// by passing each instance of Stock into a call to the instance of StockStack's Push function.
	//****************************************************
	ssPopTest.Push(poppedStock1);
	ssPopTest.Push(poppedStock2);

	// Printing the elements and length of the instance of StockStack to the console before the Pop function is called.
	cout << "The Instance of StockStack Before Calling Pop" << endl << "---------------------------------------------" << endl << ssPopTest
		 << "The length of the stack is " << ssPopTest.Size() << "." << endl << endl;

	cout << "The Instance of StockStack After Calling Pop (1st Time)" << endl << "-------------------------------------------------------" << endl;

	//****************************************************
	// If the first call to the Pop function from the instance of StockStack returns true,
	// then the top element of the instance of StockStack's stack was successfully removed.
	//****************************************************
	if (ssPopTest.Pop())
	{
		//****************************************************
		// Printing the remaining elements and length of the instance of StockStack to the console 
		// if the Pop function returns true after its first call.
		//****************************************************
		cout << ssPopTest << "The length of the stack is " << ssPopTest.Size() << "." << endl << endl;
	}
	//****************************************************
	// If the first call to the Pop function from the instance of StockStack returns false,
	// then the top element of the instance of StockStack's stack was unable to be removed from the stack
	// because the stack is empty, and removing an element from an empty stack would result in a stack underflow.
	//****************************************************
	else
	{
		//****************************************************
		// The insertion operator of the StockStack class is overloaded to output a message indicating 
		// when an instance of StockStack has an empty stack. A message indicating that an
		// element could not be popped off the stack will also be printed to the console.
		//****************************************************
		cout << ssPopTest << "An element could not be popped off of the stack. " << endl << endl;
	}

	cout << "The Instance of StockStack After Calling Pop (2nd Time)" << endl << "-------------------------------------------------------" << endl;

	//****************************************************
	// If the second call to the Pop function from the instance of StockStack returns true,
	// then the top element of the instance of StockStack's stack was successfully removed.
	//****************************************************
	if (ssPopTest.Pop())
	{
		//****************************************************
		// Printing the remaining elements and length of the instance of StockStack to the console 
		// if the Pop function returns true after its second call.
		//****************************************************
		cout << ssPopTest << "The length of the stack is " << ssPopTest.Size() << "." << endl << endl;
	}
	//****************************************************
	// If the second call to the Pop function from the instance of StockStack returns false,
	// then the top element of the instance of StockStack's stack was unable to be removed from the stack
	// because the stack is empty, and removing an element from an empty stack would result in a stack underflow.
	//****************************************************
	else
	{
		//****************************************************
		// The insertion operator of the StockStack class is overloaded to output a message indicating 
		// when an instance of StockStack has an empty stack. A message indicating that an
		// element could not be popped off the stack will also be printed to the console.
		//****************************************************
		cout << ssPopTest << "An element could not be popped off of the stack. " << endl << endl;
	}

	cout << "The Instance of StockStack After Calling Pop (3rd Time)" << endl << "-------------------------------------------------------" << endl;

	//****************************************************
	// If the third call to the Pop function from the instance of StockStack returns true,
	// then the top element of the instance of StockStack's stack was successfully removed.
	//****************************************************
	if (ssPopTest.Pop())
	{
		//****************************************************
		// Printing the remaining elements and length of the instance of StockStack to the console 
		// if the Pop function returns true after its third call.
		//****************************************************
		cout << ssPopTest << "The length of the stack is " << ssPopTest.Size() << "." << endl << endl;
	}
	//****************************************************
	// If the third call to the Pop function from the instance of StockStack returns false,
	// then the top element of the instance of StockStack's stack was unable to be removed from the stack
	// because the stack is empty, and removing an element from an empty stack would result in a stack underflow.
	//****************************************************
	else
	{
		//****************************************************
		// The insertion operator of the StockStack class is overloaded to output a message indicating 
		// when an instance of StockStack has an empty stack. A message indicating that an
		// element could not be popped off the stack will also be printed to the console.
		//****************************************************
		cout << ssPopTest << "An element could not be popped off of the stack. " << endl << endl;
	}

	//****************************************************
	//
	//	TEST # 9: StockStack's Top Function.
	// 
	//****************************************************

	cout << endl << "*------------------- TEST # 9: StockStack Top Function Test ------------------*" << endl << endl;

	//****************************************************
	// Declaring the instance of StockStack that will be used to test StockStack's Top function.
	// The number 2 is passed into the StockStack instance's one parameter constructor to create a stack with a maximum size of 2.
	//****************************************************
	StockStack ssTopTest(2);

	// Declaring an instance of Stock that will be used to store the top Stock element of the instance of StockStack's stack.
	Stock topStock;

	// Declaring and initializing two instances of Stock that will be used for StockStack's Top function test.
	Stock testStackStock1("Test Stack Stock 1", 40, 60);
	Stock testStackStock2("Test Stack Stock 2", 80, 100);

	// Printing the elements of the instance of StockStack before the Push function is called.
	cout << "The Instance of StockStack Before Calling Push" << endl << "-----------------------------------------------" << endl;

	//****************************************************
	// If a call to the Top function from the instance of StockStack returns true,
	// then the stack is not empty and the Stock object passed into 
	// its parameter will contain the values of the top element in the stack.
	//****************************************************
	if (ssTopTest.Top(topStock))
	{
		//****************************************************
		// Printing the instance of Stock that was passed into the Top function
		// on the console so the values of the top element of the stack can be viewed.
		//****************************************************
		cout << "The top of the stack is currently..." << endl << endl << topStock << endl;
	}
	//****************************************************
	// If a call to the Top function from the instance of StockStack returns false,
	// then the stack is empty and there is no top element to assign to
	// the instance of Stock that was passed into its parameter.
	//****************************************************
	else
	{
		//****************************************************
		// The insertion operator of the StockStack class is overloaded to output a message indicating 
		// when an instance of StockStack has an empty stack. A message indicating that there is
		// no top element in the stack will also be printed to the console.
		//****************************************************
		cout << ssTopTest << "There is no top element." << endl << endl;
	}

	//****************************************************
	// Adding an instance of Stock to the instance of StockStack's stack
	// by passing an instance of Stock into a call to the instance of StockStack's Push function.
	//****************************************************
	ssTopTest.Push(testStackStock1);

	// Printing the elements of the instance of StockStack after the Push function is called for the first time.
	cout << "The Instance of StockStack After Calling Push (1st Time)" << endl << "-------------------------------------------------------" << endl << ssTopTest;

	//****************************************************
	// If a call to the Top function from the instance of StockStack returns true,
	// then the stack is not empty and the Stock object passed into 
	// its parameter will contain the values of the top element in the Stack.
	//****************************************************
	if (ssTopTest.Top(topStock))
	{
		//****************************************************
		// Printing the instance of Stock that was passed into the Top function
		// on the console so the values of the top element of the stack can be viewed.
		//****************************************************
		cout << "The top of the stack is currently..." << endl << endl << topStock << endl;
	}
	//****************************************************
	// If a call to the Top function from the instance of StockStack returns false,
	// then the stack is empty and there is no top element to assign to
	// the instance of Stock that was passed into its parameter.
	//****************************************************
	else
	{
		//****************************************************
		// The insertion operator of the StockStack class is overloaded to output a message indicating 
		// when an instance of StockStack has an empty stack. A message indicating that there is
		// no top element in the stack will also be printed to the console.
		//****************************************************
		cout << ssTopTest << "There is no top element." << endl;
	}

	//****************************************************
	// Adding a second instance of Stock to the instance of StockStack's stack
	// by passing an instance of Stock into a call to the instance of StockStack's Push function.
	//****************************************************
	ssTopTest.Push(testStackStock2);

	//****************************************************
	// Printing the elements of the instance of StockStack after the Push function is called for the second time.
	// Printing the elements of the instance of StockStack after the Top function was called will also
	// show that the Top function retrieves the top element of an instance of StockStack's stack without removing it.
	//****************************************************
	cout << "The Instance of StockStack After Calling Push (2nd Time)" << endl << "-------------------------------------------------------" << endl << ssTopTest;

	//****************************************************
	// If a call to the Top function from the instance of StockStack returns true,
	// then the stack is not empty and the Stock object passed into 
	// its parameter will contain the values of the top element in the Stack.
	//****************************************************
	if (ssTopTest.Top(topStock))
	{
		//****************************************************
		// Printing the instance of Stock that was passed into the Top function
		// on the console so the values of the top element of the stack can be viewed.
		//****************************************************
		cout << "The top of the stack is currently..." << endl << endl << topStock << endl;
	}
	//****************************************************
	// If a call to the Top function from the instance of StockStack returns false,
	// then the stack is empty and there is no top element to assign to
	// the instance of Stock that was passed into its parameter.
	//****************************************************
	else
	{
		//****************************************************
		// The insertion operator of the StockStack class is overloaded to output a message indicating 
		// when an instance of StockStack has an empty stack. A message indicating that there is
		// no top element in the stack will also be printed to the console.
		//****************************************************
		cout << ssTopTest << "There is no top element." << endl;
	}

	//****************************************************
	//
	//	TEST # 10: StockStack's Assignment Operator Overload.
	// 
	//****************************************************

	cout << endl << "*---------- TEST # 10: StockStack Assignment Operator Overload Test ----------*" << endl << endl;

	//****************************************************
	// Declaring the first instance of StockStack that will be used to test StockStack's assignment operator overload.
	// The number 3 is passed into the StockStack instance's one parameter constructor to create a stack with a maximum size of 3.
	//****************************************************
	StockStack ssAssignmentOverloadTest(3);

	// Declaring and initializing two instances of Stock that will be used for StockStack's assignment operator overload test.
	Stock originalStackStock1("Original Stack Stock 1", 600, 700);
	Stock originalStackStock2("Original Stack Stock 2", 800, 900);

	//****************************************************
	// Adding each of the two instances of Stock to the first instance of StockStack's stack
	// by passing each instance of Stock into a call to the first instance of StockStack's Push function.
	//****************************************************
	ssAssignmentOverloadTest.Push(originalStackStock1);
	ssAssignmentOverloadTest.Push(originalStackStock2);

	//****************************************************
	// Declaring the second instance of StockStack that will be used to test StockStack's assignment operator overload.
	// The number 15 is passed into the StockStack instance's one parameter constructor to create a stack with a maximum size of 15.
	//****************************************************
	StockStack assignedStockStack(15);

	// Declaring and initializing four additional instances of Stock that will be used for StockStack's assignment operator overload test.
	Stock assignedStock1("Assigned Stock 1", 100, 200);
	Stock assignedStock2("Assigned Stock 2", 300, 400);
	Stock assignedStock3("Assigned Stock 3", 600, 700);
	Stock assignedStock4("Assigned Stock 4", 800, 900);

	//****************************************************
	// Adding each of the four additional instances of Stock to the second instance of StockStack's stack
	// by passing each instance of Stock into a call to the second instance of StockStack's Push function.
	//****************************************************
	assignedStockStack.Push(assignedStock1);
	assignedStockStack.Push(assignedStock2);
	assignedStockStack.Push(assignedStock3);
	assignedStockStack.Push(assignedStock4);

	//****************************************************
	// Printing the stack elements and the maximum stack size of the assignedStockStack instance of StockStack
	// that will be assigned to the ssAssignmentOverloadTest instance of StockStack to the console.
	//****************************************************
	cout << "The Instance Of StockStack Being Assigned" << endl << "-----------------------------------------" << endl << assignedStockStack
		 << "The maximum stack size is " << assignedStockStack.MaxStorage() << "." << endl << endl;

	//****************************************************
	// Printing the stack elements and maximum stack size of the ssAssignmentOverloadTest instance of StockStack before
	// the assignment operator overload is used to logically clear its stack and assign it a
	// deep copy of the stack elements and maximum stack size of the assignedStockStack instance of StockStack.
	//****************************************************
	cout << "The Instance Of StockStack Before Assignment" << endl << "--------------------------------------------" << endl << ssAssignmentOverloadTest
		 << "The maximum stack size is " << ssAssignmentOverloadTest.MaxStorage() << "." << endl << endl;

	//****************************************************
	// Assigning the stack of the assignedStockStack instance of StockStack
	// to be the stack of the ssAssignmentOverloadTest instance of StockStack
	// via the overloaded assignment operator.
	// Before a deep copy of the stack is performed, the overloaded assignment operator 
	// is defined to clear the current instance StockStack of its stack elements.
	// This means the ssAssignmentOverloadTest instance of StockStack should not have any
	// of its original elements in its stack after the overloaded assignment operator is called.
	//****************************************************
	ssAssignmentOverloadTest = assignedStockStack;

	//****************************************************
	// Outputting the stack elements of the ssAssignmentOverloadTest instance of StockStack 
	// after the assignment operator overload is used to clear its stack and assign it
	// a deep copy of the stack of the assignedStockStack instance of StockStack.
	// The stack elements and maximum stack size of the ssAssignmentOverloadTest
	// instance of StockStack should be the same as the the stack elements and
	// maximum stack size of the assignedStockStack instance of StockStack now.
	//****************************************************
	cout << "The Instance Of StockStack After Assignment" << endl << "-------------------------------------------" << endl << ssAssignmentOverloadTest
		<< "The maximum stack size is " << ssAssignmentOverloadTest.MaxStorage() << "." << endl << endl;

	//****************************************************
	//
	//	TEST # 11: StockStack's Insertion Operator Overload.
	// 
	//****************************************************

	cout << endl << "*----------- TEST # 11: StockStack Insertion Operator Overload Test ----------*" << endl << endl;

	//****************************************************
	// Declaring the first instance of StockStack that will be used to test StockStack's insertion operator overload.
	// The number 5 is passed into the StockStack instance's one parameter constructor to create a stack with a maximum size of 5.
	//****************************************************
	StockStack ssInsertionOverloadTest(5);

	// Declaring a string variable that stores the name of the file that the StockStack data will be printed to.
	string stackFileName("StackInsertionOverloadTest.txt");

	// Declaring and initializing four instances of Stock that will be used for StockStack's insertion operator overload test.
	Stock insertStackStock1("Insert Stack Stock 1", 300, 400);
	Stock insertStackStock2("Insert Stack Stock 2", 500, 600);
	Stock insertStackStock3("Insert Stack Stock 3", 700, 800);
	Stock insertStackStock4("Insert Stack Stock 4", 1200, 1800);

	//****************************************************
	// Adding each of the four instances of Stock to the instance of StockStack's stack
	// by passing each instance of Stock into a call to the instance of StockStack's Push function.
	//****************************************************
	ssInsertionOverloadTest.Push(insertStackStock1);
	ssInsertionOverloadTest.Push(insertStackStock2);
	ssInsertionOverloadTest.Push(insertStackStock3);
	ssInsertionOverloadTest.Push(insertStackStock4);

	//****************************************************
	// Declaring an instance of ofstream that will be used to output 
	// the stack elements of a StockStack instance to a file. 
	// The file it will open and print StockStack data to is the file stored in 
	// the stackFileName variable passed into the ofstream instance's parameter.
	//****************************************************
	ofstream ssInsertionOverloadOutFile(stackFileName);

	//****************************************************
	// Using the insertion operator overload to output the stack elements
	// of the instance of StockStack to the file that the instance of ofstream opened.
	//****************************************************
	ssInsertionOverloadOutFile << ssInsertionOverloadTest;

	//****************************************************
	// Printing the instance of StockStack's stack elements to
	// the console to show the StockStack data that was written to the file.
	//****************************************************
	cout << "The Instance Of StockStack Written To " << stackFileName << endl
		 << "--------------------------------------------------------------------" << endl << ssInsertionOverloadTest;

	//****************************************************
	//
	//			STOCKQUEUE CLASS UNIT TESTS
	// 
	//****************************************************

	cout << setw(50) << "StockQueue Class Tests" << endl << setw(50) << "----------------------" << endl;

	//****************************************************
	//
	//	TEST # 12: StockQueue's Default Constructor.
	// 
	//****************************************************

	cout << endl << "*-------------- TEST # 12: StockQueue Default Constructor Test ---------------*" << endl << endl;

	// Declaring an instance of StockQueue that will be used to test StockQueue's default constructor.
	StockQueue sqDefaultConstructorTest;

	// Declaring an instance of Stock that will be used in StockQueue's default constructor test.
	Stock queueDefaultTest;

	//****************************************************
	// If a call to the Dequeue function from the sqDefaultConstructorTest instance of StockQueue returns false,
	// then the default constructor of StockQueue correctly created an empty stack that does not have any elements that can be removed.
	// If a call to the Size function from the sqDefaultConstructorTest instance of StockQueue also returns 0,
	// then the default constructor of StockQueue correctly created a queue with a length of 0.
	//****************************************************
	if ((sqDefaultConstructorTest.Dequeue(queueDefaultTest) == false) && (sqDefaultConstructorTest.Size() == 0))
	{
		//****************************************************
		// The insertion operator of the StockQueue class is overloaded to output a message indicating 
		// when an instance of StockQueue has an empty queue. The value returned by the 
		// Size function is also printed to the console to show what the length of a queue is 
		// when it is created with the default constructor of StockQueue.
		//****************************************************
		cout << sqDefaultConstructorTest << "The length of the queue is " << sqDefaultConstructorTest.Size() << "." << endl;
	}
	//****************************************************
	// If the above expression evaluates to false, a message indicating that 
	// StockQueue's default constructor did not correctly create
	// an empty queue with a length of 0 is output to the console.
	//****************************************************
	else
	{
		cout << "StockQueue Default Constructor Test: FAIL!" << endl;
	}

	//****************************************************
	//
	//	TEST # 13: StockQueue's Copy Constructor.
	// 
	//****************************************************

	cout << endl << "*---------------- TEST # 13: StockQueue Copy Constructor Test ----------------*" << endl << endl;

	// Declaring the first instance of StockQueue that will be used to test StockQueue's copy constructor.
	StockQueue copiedStockQueue;

	// Declaring and initializing three instances of Stock that will be used for StockQueue's copy constructor test.
	Stock copiedQueueStock1("Copied Queue Stock 1", 350, 480);
	Stock copiedQueueStock2("Copied Queue Stock 2", 670, 890);
	Stock copiedQueueStock3("Copied Queue Stock 3", 230, 120);

	//****************************************************
	// Adding each of the three instances of Stock to the first instance of StockQueue's queue
	// by passing each instance of Stock into a call to the first instance of StockQueue's Enqueue function.
	//****************************************************
	copiedStockQueue.Enqueue(copiedQueueStock1);
	copiedStockQueue.Enqueue(copiedQueueStock2);
	copiedStockQueue.Enqueue(copiedQueueStock3);

	// Printing the elements and length of the first instance of StockQueue's queue to the console.
	cout << "The Instance of StockQueue Being Copied" << endl << "---------------------------------------" << endl << copiedStockQueue
		 << "The length of the queue is " << copiedStockQueue.Size() << "." << endl << endl;

	//****************************************************
	// Declaring the second instance of StockQueue that will be used to test StockQueue's copy constructor and
	// initializing it by passing the first instance of StockQueue into its copy constructor.
	//****************************************************
	StockQueue sqCopyConstructorTest(copiedStockQueue);

	//****************************************************
	// Printing the elements of the instance of StockQueue's queue initialized with
	// the copy constructor to the console to show that it has the same elements
	// and length as the instance of StockQueue that was passed into its copy constructor.
	//****************************************************
	cout << "The Instance of StockQueue Initialized With The Copy Constructor" << endl << "----------------------------------------------------------------" << endl
		 << sqCopyConstructorTest << "The length of the queue is " << sqCopyConstructorTest.Size() << "." << endl << endl;

	//****************************************************
	//
	//	TEST # 14: StockQueue's Clear & Size Function.
	// 
	//****************************************************

	cout << endl << "*-------------- TEST # 14: StockQueue Clear & Size Function Test -------------*" << endl << endl;

	// Declaring an instance of StockQueue that will be used to test StockQueue's Clear and Size function.
	StockQueue sqClearTest;

	// Declaring and initializing two instances of Stock that will be used for StockQueue's Clear and Size function test.
	Stock clearQueueStock1("Clear Queue Stock 1", 400, 700);
	Stock clearQueueStock2("Clear Queue Stock 2", 100, 500);

	//****************************************************
	// Adding each of the two instances of Stock to the instance of StockQueue's queue
	// by passing each instance of Stock into a call to the instance of StockQueue's Enqueue function.
	//****************************************************
	sqClearTest.Enqueue(clearQueueStock1);
	sqClearTest.Enqueue(clearQueueStock2);

	// Printing the elements and length of the instance of StockQueue to the console before a call to the Clear function.
	cout << "The Instance of StockQueue Before Calling Clear" << endl << "-----------------------------------------------" << endl << sqClearTest
		 << "The length of the queue is " << sqClearTest.Size() << "." << endl << endl;

	// Calling the Clear function from the instance of StockQueue to clear its queue.
	sqClearTest.Clear();

	//****************************************************
	// Printing the elements of the instance of StockQueue to the console after a call to the Clear function.
	// The insertion operator of the StockQueue class is overloaded to output a message indicating 
	// when an instance of StockQueue has an empty queue, and that message should be printed
	// onto the console after the call to the Clear function.
	//****************************************************
	cout << "The Instance of StockQueue After Calling Clear" << endl << "----------------------------------------------" << endl << sqClearTest
		 << "The length of the queue is " << sqClearTest.Size() << "." << endl << endl;

	//****************************************************
	//
	//	TEST # 15: StockQueue's Enqueue Function.
	// 
	//****************************************************

	cout << endl << "*---------------- TEST # 15: StockQueue Enqueue Function Test ----------------*" << endl << endl;

	// Declaring an instance of StockQueue that will be used to test StockQueue's Enqueue function.
	StockQueue sqEnqueueTest;

	// Declaring and initializing two instances of Stock that will be used for StockQueue's Enqueue function test.
	Stock enqueueStock1("Enqueue Stock 1", 400, 700);
	Stock enqueueStock2("Enqueue Stock 2", 100, 500);

	//****************************************************
	// Adding the first instance of Stock to the instance of StockQueue's queue
	// by passing it into a call to the instance of StockQueue's Enqueue function.
	//****************************************************
	sqEnqueueTest.Enqueue(enqueueStock1);

	//****************************************************
	// Printing the elements of the instance of StockQueue to the console.
	// Because one Stock object was added to the queue, the call to the
	// Size function from the instance of StockQueue should return 1.
	//****************************************************
	cout << "The Instance of StockQueue After Calling Enqueue (1st Time)" << endl << "-----------------------------------------------------------" << endl << sqEnqueueTest
		 << "The length of the queue is " << sqEnqueueTest.Size() << "." << endl << endl;

	//****************************************************
	// Adding the second instance of Stock to the end of the instance of StockQueue's queue
	// by passing it into a call to the instance of StockQueue's Enqueue function.
	//****************************************************
	sqEnqueueTest.Enqueue(enqueueStock2);

	//****************************************************
	// Printing the elements of the instance of StockQueue to the console to
	// show that the second instance of Stock was added to the end of the queue.
	// Because two Stock objects were added to the queue, the call to the
	// Size function from the instance of StockQueue should return 2.
	//****************************************************
	cout << "The Instance of StockQueue After Calling Enqueue (2nd Time)" << endl << "-----------------------------------------------------------" << endl << sqEnqueueTest
		 << "The length of the queue is " << sqEnqueueTest.Size() << "." << endl;

	//****************************************************
	//
	//	TEST # 16: StockQueue's Dequeue Function.
	// 
	//****************************************************

	cout << endl << "*---------------- TEST # 16: StockQueue Dequeue Function Test ----------------*" << endl << endl;

	// Declaring an instance of StockQueue that will be used to test StockQueue's Dequeue function.
	StockQueue sqDequeueTest;

	// Declaring an instance of Stock that will be used to store the values of the Stock object removed from the front of the queue.
	Stock removedStock;

	// Declaring and initializing two instances of Stock that will be used for StockQueue's Dequeue function test.
	Stock dequeueStock1("Dequeue Stock 1", 400, 700);
	Stock dequeueStock2("Dequeue Stock 2", 100, 500);

	//****************************************************
	// Adding each of the two instances of Stock to the instance of StockQueue's queue
	// by passing each instance of Stock into a call to the instance of StockQueue's Enqueue function.
	//****************************************************
	sqDequeueTest.Enqueue(dequeueStock1);
	sqDequeueTest.Enqueue(dequeueStock2);

	// Printing the elements and length of the instance of StockQueue's queue to the console before the Dequeue function is called.
	cout << "The Instance of StockQueue Before Calling Dequeue" << endl << "-------------------------------------------------" << endl << sqDequeueTest
		 << "The length of the queue is " << sqDequeueTest.Size() << "." << endl << endl;

	cout << "The Instance of StockQueue After Calling Dequeue (1st Time)" << endl << "-----------------------------------------------------------" << endl;

	//****************************************************
	// If the first call to the Dequeue function from the instance of StockQueue returns true,
	// then the queue is not empty and the Stock object passed into the function's
	// parameter will contain the values of the first element that the
	// Dequeue function removed from the instance of StockQueue's queue.
	//****************************************************
	if (sqDequeueTest.Dequeue(removedStock))
	{
		//****************************************************
		// Printing the elements and length of the instance of StockQueue's queue
		// to the console if the first call to the Dequeue function returned true.
		// The instance of Stock passed into the Dequeue function is also printed to the
		// console to view the Stock object that was removed from the instance of StockQueue's queue.
		//****************************************************
		cout << sqDequeueTest << "The element removed from the queue was..." << endl << endl << removedStock << endl
			 << "The length of the queue is " << sqDequeueTest.Size() << "." << endl << endl;
	}
	//****************************************************
	// If the above expression evaluates to false, a message is ouput to the console
	// to indicate that the instance of StockQueue's queue has no first element and is empty.
	//****************************************************
	else
	{
		//****************************************************
		// The insertion operator of the StockQueue class is overloaded to output a message indicating 
		// when an instance of StockQueue has an empty queue. A message indicating that there are
		// no elements that can be removed from the empty queue will also be printed to the console.
		//****************************************************
		cout << sqDequeueTest << "There is no first element to remove from the queue." << endl;
	}

	cout << "The Instance of StockQueue After Calling Dequeue (2nd Time)" << endl << "-----------------------------------------------------------" << endl;

	//****************************************************
	// If the second call to the Dequeue function from the instance of StockQueue returns true,
	// then the queue is not empty and the Stock object passed into the function's
	// parameter will contain the values of the first element that the
	// Dequeue function removed from the instance of StockQueue's queue.
	//****************************************************
	if (sqDequeueTest.Dequeue(removedStock))
	{
		//****************************************************
		// Printing the elements and length of the instance of StockQueue's queue
		// to the console if the second call to the Dequeue function returned true.
		// The instance of Stock passed into the Dequeue function is also printed to the
		// console to view the Stock object that was removed from the instance of StockQueue's queue.
		//****************************************************
		cout << sqDequeueTest << endl << "The element removed from the queue was..." << endl << endl << removedStock << endl
			 << "The length of the queue is " << sqDequeueTest.Size() << "." << endl << endl;
	}
	//****************************************************
	// If the above expression evaluates to false, a message is ouput to the console
	// to indicate that the instance of StockQueue's queue has no first element and is empty.
	//****************************************************
	else
	{
		//****************************************************
		// The insertion operator of the StockQueue class is overloaded to output a message indicating 
		// when an instance of StockQueue has an empty queue. A message indicating that there are
		// no elements that can be removed from the empty queue will also be printed to the console.
		//****************************************************
		cout << sqDequeueTest << "There is no first element to remove from the queue." << endl;
	}

	cout << "The Instance of StockQueue After Calling Dequeue (3rd Time)" << endl << "-----------------------------------------------------------" << endl;

	//****************************************************
	// If the third call to the Dequeue function from the instance of StockQueue returns true,
	// then the queue is not empty and the Stock object passed into the function's
	// parameter will contain the values of the first element that the
	// Dequeue function removed from the instance of StockQueue's queue.
	//****************************************************
	if (sqDequeueTest.Dequeue(removedStock))
	{
		//****************************************************
		// Printing the elements and length of the instance of StockQueue's queue
		// to the console if the third call to the Dequeue function returned true.
		// The instance of Stock passed into the Dequeue function is also printed to the
		// console to view the Stock object that was removed from the instance of StockQueue's queue.
		//****************************************************
		cout << sqDequeueTest << "The element removed from the queue was..." << endl << endl << removedStock << endl
			 << "The length of the queue is  " << sqDequeueTest.Size() << "." << endl << endl;
	}
	//****************************************************
	// If the above expression evaluates to false, a message is ouput to the console
	// to indicate that the instance of StockQueue's queue has no first element and is empty.
	//****************************************************
	else
	{
		//****************************************************
		// The insertion operator of the StockQueue class is overloaded to output a message indicating 
		// when an instance of StockQueue has an empty queue. A message indicating that there are
		// no elements that can be removed from the empty queue will also be printed to the console.
		//****************************************************
		cout << sqDequeueTest << "There is no first element to remove from the queue." << endl;
	}

	//****************************************************
	//
	//	TEST # 17: StockQueue's Assignment Operator Overload.
	// 
	//****************************************************

	cout << endl << "*---------- TEST # 17: StockQueue Assignment Operator Overload Test ----------*" << endl << endl;

	// Declaring the first instance of StockQueue that will be used to test StockQueue's assignment operator overload.
	StockQueue sqAssignmentOverloadTest;

	// Declaring and initializing two instances of Stock that will be used for StockQueue's assignment operator overload test.
	Stock originalQueueStock1("Original Queue Stock 1", 600, 700);
	Stock originalQueueStock2("Original Queue Stock 2", 800, 900);

	//****************************************************
	// Adding each of the two instances of Stock to the first instance of StockQueue's queue
	// by passing each instance of Stock into a call to the first instance of StockQueue's Enqueue function.
	//****************************************************
	sqAssignmentOverloadTest.Enqueue(originalQueueStock1);
	sqAssignmentOverloadTest.Enqueue(originalQueueStock2);

	// Declaring the second instance of StockQueue that will be used to test StockQueue's assignment operator overload.
	StockQueue assignedStockQueue;

	// Declaring and initializing four additional instances of Stock that will be used for StockQueue's assignment operator overload test.
	Stock assignedQueueStock1("Assigned Stock Queue 1", 100, 200);
	Stock assignedQueueStock2("Assigned Stock Queue 2", 300, 400);
	Stock assignedQueueStock3("Assigned Stock Queue 3", 5500, 4800);
	Stock assignedQueueStock4("Assigned Stock Queue 4", 10, 30);

	//****************************************************
	// Adding each of the four additional instances of Stock to the second instance of StockQueue's queue
	// by passing each instance of Stock into a call to the second instance of StockQueue's Enqueue function.
	//****************************************************
	assignedStockQueue.Enqueue(assignedQueueStock1);
	assignedStockQueue.Enqueue(assignedQueueStock2);
	assignedStockQueue.Enqueue(assignedQueueStock3);
	assignedStockQueue.Enqueue(assignedQueueStock4);

	//****************************************************
	// Printing the elements and length of the assignedStockQueue instance of StockQueue's queue
	// that will be assigned to the sqAssignmentOverloadTest instance of StockQueue to the console.
	//****************************************************
	cout << "The Instance Of StockQueue Being Assigned" << endl << "-----------------------------------------" << endl << assignedStockQueue
		 << "The length of the queue is " << assignedStockQueue.Size() << "." << endl << endl;

	//****************************************************
	// Printing the elements and length of the sqAssignmentOverloadTest instance of StockQueue's queue
	// before the assignment operator overload is used to clear its queue and assign it a
	// deep copy of the queue of the assignedStockQueue instance of StockQueue.
	//****************************************************
	cout << "The Instance Of StockQueue Before Assignment" << endl << "--------------------------------------------" << endl << sqAssignmentOverloadTest
		 << "The length of the queue is " << sqAssignmentOverloadTest.Size() << "." << endl << endl;

	//****************************************************
	// Assigning the queue of the assignedStockQueue instance of StockQueue
	// to be the queue of the sqAssignmentOverloadTest instance of StockQueue 
	// via the overloaded assignment operator.
	// Before a deep copy of the queue elements is performed, the overloaded assignment operator 
	// is defined to clear the current instance StockQueue of its queue elements.
	// This means the sqAssignmentOverloadTest instance of StockQueue should not have any
	// of its original elements in its queue after the overloaded assignment operator is called.
	//****************************************************
	sqAssignmentOverloadTest = assignedStockQueue;

	//****************************************************
	// Outputting the queue of the sqAssignmentOverloadTest instance of StockQueue after
	// the assignment operator overload is used to clear its queue and assign it
	// a deep copy of the assignedStockQueue instance of StockQueue's queue.
	// The elements and length of the sqAssignmentOverloadTest instance of StockQueue's queue
	// should be the same as the the elements and length of the assignedStockQueue instance of StockQueue's queue.
	//****************************************************
	cout << "The Instance Of StockQueue After Assignment" << endl << "-------------------------------------------" << endl << sqAssignmentOverloadTest
		 << "The length of the queue is " << sqAssignmentOverloadTest.Size() << "." << endl << endl;

	//****************************************************
	//
	//	TEST # 18: StockQueue's Insertion Operator Overload.
	// 
	//****************************************************

	cout << endl << "*----------- TEST # 18: StockQueue Insertion Operator Overload Test ----------*" << endl << endl;

	// Declaring an instance of StockQueue that will be used to test StockQueue's insertion operator overload.
	StockQueue sqInsertionOverloadTest;

	// Declaring a string variable that stores the name of the file that the StockQueue data will be printed to.
	string queueFileName("QueueInsertionOverloadTest.txt");

	// Declaring and initializing three instances of Stock that will be used for StockQueue's insertion operator overload test.
	Stock insertQueueStock1("Insert Queue Stock 1", 430, 890);
	Stock insertQueueStock2("Insert Queue Stock 2", 1550, 2500);
	Stock insertQueueStock3("Insert Queue Stock 3", 10000, 3800);

	//****************************************************
	// Adding each of the three instances of Stock to the instance of StockQueue's queue
	// by passing each instance of Stock into a call to the instance of StockQueue's Enqueue function.
	//****************************************************
	sqInsertionOverloadTest.Enqueue(insertQueueStock1);
	sqInsertionOverloadTest.Enqueue(insertQueueStock2);
	sqInsertionOverloadTest.Enqueue(insertQueueStock3);

	//****************************************************
	// Declaring an instance of ofstream that will be used to output 
	// the instance of StockQueue's queue to a file. 
	// The file it will open and print StockQueue data to is the file stored in 
	// the queueFileName variable passed into the ofstream instance's parameter.
	//****************************************************
	ofstream sqInsertionOverloadOutFile(queueFileName);

	//****************************************************
	// Using the insertion operator overload to output the queue of the
	// instance of StockQueue to the file that the instance of ofstream opened.
	//****************************************************
	sqInsertionOverloadOutFile << sqInsertionOverloadTest;

	//****************************************************
	// Printing the instance of StockQueue's queue to the
	// console to show the StockQueue data that was written to the file.
	//****************************************************
	cout << "The Instance Of StockQueue Written To " << queueFileName << endl
		 << "--------------------------------------------------------------------" << endl << sqInsertionOverloadTest;

	// Declaring an instance of Portfolio that will be used to output the author of the program's name.
	Portfolio getAuthorTest;
	// Printing the name of the author of this program through a call to the GetAuthor function.
	cout << endl << "BCS 370 - Homework #4 by " << getAuthorTest.GetAuthor() << "." << endl << endl;

	return 0;
}