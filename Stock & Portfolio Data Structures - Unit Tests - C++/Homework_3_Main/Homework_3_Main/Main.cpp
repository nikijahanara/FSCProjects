//****************************************************
// File: Main.cpp
//
// Purpose: To perform tests on the StockList class's default constructor, copy constructor, assignment operator overload, Clear function,
//			Length function, Add function, overloaded Add function, FindByName function, Delete function, 
//			insertion operator overload, and extraction operator overload.
//
// Written By: Niki Jahanara
//
// Compiler: Visual Studio Express 2013 (For Windows Desktop)
//
//***************************************************

#include<fstream>
#include<iostream>
//***************************************************
// The header file of the Portfolio class must be included
// so that instances of Portfolio can be made inside main.
//***************************************************
#include"Portfolio.h"
//***************************************************
// The header file of the StockList class must be included
// so that instances of StockList can be made inside main.
//***************************************************
#include "StockList.h"

using namespace std;

//****************************************************
// Function: main
//
// Purpose: To perform tests on the StockList class's default constructor, copy constructor, assignment operator overload, Clear function,
//			Length function, Add function, overloaded Add function, FindByName function, Delete function, 
//			insertion operator overload, and extraction operator overload.
//
//****************************************************
int main()
{
	cout << "StockList Class Tests" << endl << "---------------------" << endl;
	
	//****************************************************
	//
	//	TEST # 1: StockList's Default Constructor.
	// 
	//****************************************************

	cout << endl << "*---------------- TEST # 1: StockList Default Constructor Test ---------------*" << endl  << endl;

	// Declaring an instance of StockList that will be used for StockList's default constructor test.
	StockList defaultConstructorTest;

	//****************************************************
	// Because StockList's overloaded insertion operator is defined to output a
	// "The StockList is empty." message when the listData member variable
	// of an instance of StockList is equal to NULL, it can be used to test whether or
	// not the instance of StockList's default constructor created an empty list.
	// The call to the Length function of the StockList instance should also output 0
	// to indicate that the instance of StockList has no elements after it is declared.
	//****************************************************
	cout << defaultConstructorTest << "The length of the StockList is " << defaultConstructorTest.Length() << "." << endl;
	
	//****************************************************
	//
	//	TEST # 2: StockList's Copy Constructor.
	// 
	//****************************************************

	cout << endl << "*----------------- TEST # 2: StockList Copy Constructor Test -----------------*" << endl << endl << endl;

	// Declaring the first instance of StockList that will be used for StockList's copy constructor test.
	StockList stockListCopy;

	// Declaring and initializing three instances of Stock that will be used for StockList's copy constructor test.
	Stock copyStock1("Copy Stock 1", 100, 200);
	Stock copyStock2("Copy Stock 2", 300, 400);
	Stock copyStock3("Copy Stock 3", 500, 600);

	//****************************************************
	// Adding each of the three instances of Stock to the first instance of StockList's unsorted linked list
	// by passing each instance of Stock into a call to the first instance of StockList's Add function.
	//****************************************************
	stockListCopy.Add(copyStock1);
	stockListCopy.Add(copyStock2);
	stockListCopy.Add(copyStock3);

	//****************************************************
	// Declaring and initializing the second instance of StockList that will be used for StockList's copy constructor test
	// by passing the first instance of StockList into the copy constructor of the second instance of StockList.
	// The copyConstructorTest instance of StockList should now have all the elements that 
	// the stockListCopy instance of StockList's unsorted linked list has because of the deep copy of
	// the stockListCopy instance of StockList's unsorted linked list that the copy constructor performs.
	//****************************************************
	StockList copyConstructorTest(stockListCopy);

	// Outputting the unsorted linked list elements of the instance of StockList being copied to the console.
	cout << "The Instance Of StockList Being Copied" << endl << "--------------------------------------" << endl << stockListCopy;

	//****************************************************
	// Outputting the unsorted linked list elements of the instance of StockList 
	// that was initialized with the copy consuctor to the console.
	// The unsorted linked list elements of copyConstructorTest instance of StockList should be the same as the
	// the unsorted linked list elements of the stockListCopy instance of StockList, but in reverse order.
	//****************************************************
	cout << "The Instance Of StockList Initialized With The Copy Constructor" << endl << "---------------------------------------------------------------" << endl << copyConstructorTest;

	//****************************************************
	//
	//	TEST # 3: StockList's Assignment Operator Overload.
	// 
	//****************************************************

	cout << "*----------- TEST # 3: StockList Assignment Operator Overload Test -----------*" << endl << endl << endl;

	// Declaring the first instance of StockList that will be used for StockList's assignment overload test.
	StockList assignmentOverloadTest;

	// Declaring and initializing three instances of Stock that will be used for StockList's assignment operator overload test.
	Stock originalStock1("Original Stock 1", 700, 800);
	Stock originalStock2("Original Stock 2", 900, 1000);
	Stock originalStock3("Original Stock 3", 1100, 1200);

	//****************************************************
	// Adding each of the three instances of Stock to the first instance of StockList's unsorted linked list
	// by passing each instance of Stock into a call to the first instance of StockList's Add function.
	//****************************************************
	assignmentOverloadTest.Add(originalStock1);
	assignmentOverloadTest.Add(originalStock2);
	assignmentOverloadTest.Add(originalStock3);

	// Declaring the second instance of StockList that will be used for StockList's assignment operator overload test.
	StockList assignedStockList;

	// Declaring and initializing four additional instances of Stock that will be used for StockList's assignment operator overload test.
	Stock assignedStock1("Assigned Stock 1", 9000, 10000);
	Stock assignedStock2("Assigned Stock 2", 20000, 30000);
	Stock assignedStock3("Assigned Stock 3", 40000, 50000);
	Stock assignedStock4("Assigned Stock 4", 60000, 70000);

	//****************************************************
	// Adding each of the four instances of Stock to the second instance of StockList's unsorted linked list
	// by passing each instance of Stock into a call to the second instance of StockList's Add function.
	//****************************************************
	assignedStockList.Add(assignedStock1);
	assignedStockList.Add(assignedStock2);
	assignedStockList.Add(assignedStock3);
	assignedStockList.Add(assignedStock4);

	//****************************************************
	// Outputting the unsorted linked list elements of the assignedStockList instance of StockList
	// that will be assigned to the assignmentOverloadTest instance of StockList.
	//****************************************************
	cout << "The StockList Instance Being Assigned" << endl << "-------------------------------------" << endl << assignedStockList;

	//****************************************************
	// Outputting the unsorted linked list elements of the assignmentOverloadTest instance of StockList before
	// the assignment operator overload is used to clear its unsorted linked list and
	// assign it a deep copy of the unsorted linked list of the assignedStockList instance of StockList.
	//****************************************************
	cout << "The Instance Of StockList Before Assignment" << endl << "-------------------------------------------" << endl << assignmentOverloadTest;

	//****************************************************
	// Assigning the unsorted linked list of the assignedStockList instance of StockList
	// to be the unsorted linked list of the assignmentOverloadTest
	// instance of StockList via the overloaded assignment operator.
	// Before a deep copy of the unsorted linked list's elements is performed,
	// the overloaded assignment operator is defined to clear
	// the current instance StockList of its unsorted linked list elements.
	// This means the assignmentOverloadTest instance of StockList should not have any of its
	// original elements in its unsorted linked list after the overloaded assignment operator is called.
	//****************************************************
	assignmentOverloadTest = assignedStockList;

	//****************************************************
	// Outputting the unsorted linked list elements of the assignmentOverloadTest instance of StockList after
	// the assignment operator overload is used to clear its unsorted linked list and
	// assign it to have a deep copy of the unsorted linked list of the assignedStockList instance of StockList.
	// The unsorted linked list elements of the assignmentOverloadTest instance of StockList should be the same as the
	// the unsorted linked list elements of the assignedStockList instance of StockList, but in reverse order.
	//****************************************************
	cout << "The Instance Of StockList After Assignment" << endl << "------------------------------------------" << endl << assignmentOverloadTest;

	//****************************************************
	//
	//	TEST # 4: StockList's Clear & Length Function.
	// 
	//****************************************************

	cout << "*------------- TEST # 4: StockList Clear & Length Function Test --------------*" << endl << endl << endl;

	// Declaring an instance of StockList that will be used for StockList's Clear function test.
	StockList clearTest;

	// Declaring and initializing four instances of Stock that will be used for StockList's Clear function test.
	Stock clearStock1("Clear Stock 1", 35, 40);
	Stock clearStock2("Clear Stock 2", 45, 50);
	Stock clearStock3("Clear Stock 3", 55, 60);
	Stock clearStock4("Clear Stock 4", 65, 70);

	//****************************************************
	// Adding each of the four instances of Stock to the instance of StockList's unsorted linked list
	// by passing each instance of Stock into a call to the instance of StockList's Add function.
	//****************************************************
	clearTest.Add(clearStock1);
	clearTest.Add(clearStock2);
	clearTest.Add(clearStock3);
	clearTest.Add(clearStock4);

	//****************************************************
	// Outputting the elements of the instance of StockList's unsorted linked list 
	// to the console before the Clear function is called on the instance of StockList.
	//****************************************************
	cout << "The Instance Of StockList Before Calling Clear" << endl << "----------------------------------------------" << endl << clearTest;

	//****************************************************
	// Outputting the number of elements the instance of StockList has in
	// its unsorted linked list by calling the Length function.
	// Because four instances of Stock were added to the instance of StockList's
	// unsorted linked list, the Length function should return 4.
	//****************************************************
	cout << "This instance of StockList has " << clearTest.Length() << " elements." << endl;

	//****************************************************
	// Emptying the instance of StockList of its unsorted linked list elements
	// by calling the Clear function. The Clear function also deallocates the dynamic memory
	// of each element of the unsorted linked list in order to prevent a memory leak.
	//****************************************************
	clearTest.Clear();

	//****************************************************
	// Outputting the elements of the instance of StockList's unsorted linked list 
	// to the console after the Clear function is called from the instance of StockList.
	// StockList's overloaded insertion operator is defined to output a message
	// indicating the StockList instance is empty when the listData member variable
	// of an instance of StockList is equal to NULL. This message should be output
	// to the console after the Clear function was called from the instance of StockList because the
	// listData member variable of the instance of StockList should be NULL after the Clear function is called.
	//****************************************************
	cout << endl << "The Instance Of StockList After Calling Clear" << endl << "---------------------------------------------" << endl << clearTest;

	//****************************************************
	// Outputting the number of elements the instance of StockList has in
	// its unsorted linked list by calling the Length function.
	// Because a call to the Clear function empties an instance of StockList of
	// its unsorted linked list elements, the Length function should return 0.
	//****************************************************
	cout << endl << "This instance of StockList has " << clearTest.Length() << " elements." << endl;

	//****************************************************
	//
	//	TEST # 5: StockList's Add Function.
	// 
	//****************************************************

	cout << endl << "*------------------ TEST # 5: StockList Add Function Test --------------------*" << endl << endl << endl;

	// Declaring an instance of StockList that will be used for StockList's Add function test.
	StockList addTest;

	// Declaring and initializing two instances of Stock that will be used for StockList's Add function test.
	Stock addStock1("Add Stock 1", 850, 950);
	Stock addStock2("Add Stock 2", 105, 110);

	//****************************************************
	// Adding the two instances of Stock to the instance of StockList's unsorted linked list
	// by passing each instance of Stock into a call to the instance of StockList's Add function.
	//****************************************************
	addTest.Add(addStock1);
	addTest.Add(addStock2);

	//****************************************************
	// Outputting the elements of the instance of StockList's unsorted linked list 
	// to the console after calling the Add function to add two instances of
	// Stock to the instance of StockList's unsorted linked list.
	//****************************************************
	cout << "The Instance Of StockList After Calling Add Twice" << endl << "-------------------------------------------------" << endl << addTest;

	//****************************************************
	// Outputting the number of elements the instance of StockList has in
	// its unsorted linked list by calling the Length function.
	// Because the Add function was called twice, the Length function should return 2.
	//****************************************************
	cout << "This instance of StockList has " << addTest.Length() << " elements." << endl;

	//****************************************************
	//
	//	TEST # 6: StockList's Overloaded Add Function.
	// 
	//****************************************************
	
	cout << endl << "*------------ TEST # 6: StockList (Overloaded) Add Function Test -------------*" << endl << endl;

	// Declaring the first instance of StockList that will be used for StockList's overloaded Add function test.
	StockList addOverloadTest;

	// Declaring and initializing two instances of Stock that will be used for StockList's overloaded Add function test.
	Stock addOverloadStock1("Stock 1", 73000, 11500);
	Stock addOverloadStock2("Stock 2", 8650, 2145);

	//****************************************************
	// Adding the two instances of Stock to the first instance of StockList's unsorted linked list
	// by passing each instance of Stock into a call to the first instance of StockList's Add function.
	//****************************************************
	addOverloadTest.Add(addOverloadStock1);
	addOverloadTest.Add(addOverloadStock2);

	// Declaring the second instance of StockList that will be used for StockList's overloaded Add function test.
	StockList addedStockList;

	// Declaring and initializing two additional instances of Stock that will be used for StockList's overloaded Add function test.
	Stock addedStock1("Added Stock 1", 7300, 1150);
	Stock addedStock2("Added Stock 2", 8650, 2145);

	//****************************************************
	// Adding the additional two instances of Stock to the second instance of StockList's unsorted linked list
	// by passing each instance of Stock into a call to the second instance of StockList's Add function.
	//****************************************************
	addedStockList.Add(addedStock1);
	addedStockList.Add(addedStock2);

	//****************************************************
	// Outputting the unsorted linked list elements of the addedStockList instance of StockList
	// that will be appended to the unsorted linked list of the addOverloadTest instance of StockList.
	//****************************************************
	cout << endl << "The StockList Elements Being Added" << endl << "----------------------------------" << endl << addedStockList;

	//****************************************************
	// Outputting the unsorted linked list elements of the addOverloadTest instance of StockList
	// before the overloaded Add function is called to append the unsorted linked list
	// elements of the addedStockList instance of StockList to its unsorted linked list.
	//****************************************************
	cout << "The Instance Of StockList Before Calling Add (Overloaded)" << endl << "---------------------------------------------------------" << endl << addOverloadTest;

	//****************************************************
	// Calling the overloaded Add function by passing the addedStockList instance of StockList
	// into the Add function's parameter so that the elements of the addedStockList instance of StockList's
	// unsorted linked list can be appended to the front of the addOverloadTest instance of StockList's unsorted linked list.
	//****************************************************
	addOverloadTest.Add(addedStockList);

	//****************************************************
	// Outputting the unsorted linked list elements of the addOverloadTest instance of StockList
	// after the overloaded Add function was called to append the unsorted linked list
	// elements of the addedStockList instance of StockList to its unsorted linked list.
	// The appended elements are added to the front of the addOverloadTest instance of StockList's unsorted linked list.
	//****************************************************
	cout << "The Instance Of StockList After Calling Add (Overloaded)" << endl << "--------------------------------------------------------" << endl << addOverloadTest;

	//****************************************************
	//
	//	TEST # 7: StockList's FindByName Function.
	// 
	//****************************************************

	cout << endl << "*--------------- TEST # 7: StockList FindByName Function Test ----------------*" << endl << endl << endl;

	// Declaring an instance of StockList that will be used for StockList's FindByName function test.
	StockList findByNameTest;
	// Declaring an instance of Stock that will be used to store the values of the Stock found in StockList's FindByName function test.
	Stock stockFound;

	// Declaring and initializing two instances of Stock that will be used for StockList's FindByName function test.
	Stock microsoftStock("Microsoft", 100, 150);
	Stock appleStock("Apple", 200, 250);

	//****************************************************
	// Adding the two instances of Stock to the instance of StockList's unsorted linked list
	// by passing each instance of Stock into a call to the instance of StockList's Add function.
	//****************************************************
	findByNameTest.Add(microsoftStock);
	findByNameTest.Add(appleStock);

	// Outputting the name of the first Stock that is being searched for within the instance of StockList's unsorted linked list.
	cout << "Searching For " << microsoftStock.getStockName() << "'s Stock..." << endl << endl;

	//****************************************************
	// If the call to the FindByName function returns true, and
	// if stockFound is equal to the Stock instance that has the 
	// the name being searched for by the FindByName function (Microsoft),
	// then a message, which indicates that the function is working correctly,
	// and the values of stockFound, which is storing the member variable values
	// of the Stock that was being searched for, are both printed to the console.
	//****************************************************
	if ((findByNameTest.FindByName("Microsoft", stockFound) == true) && (stockFound == microsoftStock))
	{
		cout << "The Stock Was Found: " << endl << stockFound << endl;
	}
	//****************************************************
	// If the call to the FindByName function does not return true,
	// the above if statement fails. A message is printed that indicates
	// that the function is not working correctly.
	//****************************************************
	else
	{
		cout << "StockList FindByName Function Test: FAIL!" << endl;
	}

	// Outputting the name of the second Stock that is being searched for within the instance of StockList's unsorted linked list.
	cout << "Searching For " << appleStock.getStockName() << "'s Stock..." << endl << endl;

	//****************************************************
	// If the call to the FindByName function returns true, and
	// if stockFound is equal to the Stock instance that has the 
	// the name being searched for by the FindByName function (Apple),
	// then a message, which indicates that the function is working correctly,
	// and the values of stockFound, which is storing the member variable values
	// of the Stock that was being searched for, are both printed to the console.
	//****************************************************
	if ((findByNameTest.FindByName("Apple", stockFound) == true) && (stockFound == appleStock))
	{
		cout << "The Stock Was Found: " << endl << stockFound << endl;
	}
	//****************************************************
	// If the call to the FindByName function does not return true,
	// the above if statement fails. A message is printed that indicates
	// that the function is not working correctly.
	//****************************************************
	else
	{
		cout << "StockList FindByName Function Test: FAIL!" << endl;
	}

	//****************************************************
	//
	//	TEST # 8: StockList's Delete Function.
	// 
	//****************************************************

	cout << endl << "*----------------- TEST # 8: StockList Delete Function Test ------------------*" << endl << endl << endl;

	// Declaring an instance of StockList that will be used for StockList's Delete function test.
	StockList deleteTest;

	// Declaring and initializing three instances of Stock that will be used for StockList's Delete function test.
	Stock deleteStock1("Stock 1", 10, 40);
	Stock deleteStock2("Stock 2", 50, 80);
	Stock deleteStock3("Stock 3", 100, 130);

	//****************************************************
	// Adding the three instances of Stock to the instance of StockList's unsorted linked list
	// by passing each instance of Stock into a call to the instance of StockList's Add function.
	//****************************************************
	deleteTest.Add(deleteStock1);
	deleteTest.Add(deleteStock2);
	deleteTest.Add(deleteStock3);

	//****************************************************
	// Outputting the elements of the instance of StockList's unsorted linked list 
	// to the console before the Delete function is called.
	//****************************************************
	cout << "The Instance Of StockList Before Calling Delete" << endl << "-----------------------------------------------" << endl << deleteTest;

	//****************************************************
	// Deleting the instance of Stock that has the value "Stock 1" for
	// its name member variable from the instance of StockList's unsorted linked list
	// by calling the Delete function and passing the string "Stock 1" into it.
	//****************************************************
	deleteTest.Delete("Stock 1");

	//****************************************************
	// Outputting the elements of the instance of StockList's unsorted linked list 
	// to the console after the Delete function is called to delete the
	// instance of Stock that has the value "Stock 1" for its name member variable.
	//****************************************************
	cout << "The Instance Of StockList After Calling Delete (For Stock 1)" << endl << "------------------------------------------------------------" << endl << deleteTest;

	//****************************************************
	// Deleting the instance of Stock that has the value "Stock 2" for
	// its name member variable from the instance of StockList's unsorted linked list
	// by calling the Delete function and passing the string "Stock 2" into it.
	//****************************************************
	deleteTest.Delete("Stock 2");

	//****************************************************
	// Outputting the elements of the instance of StockList's unsorted linked list 
	// to the console after the Delete function is called to delete the
	// instance of Stock that has the value "Stock 2" for its name member variable.
	//****************************************************
	cout << "The Instance Of StockList After Calling Delete (For Stock 2)" << endl << "------------------------------------------------------------" << endl << deleteTest;

	//****************************************************
	// Deleting the instance of Stock that has the value "Stock 3" for
	// its name member variable from the instance of StockList's unsorted linked list
	// by calling the Delete function and passing the string "Stock 3" into it.
	//****************************************************
	deleteTest.Delete("Stock 3");

	//****************************************************
	// Outputting the elements of the instance of StockList's unsorted linked list 
	// to the console after the Delete function is called to delete the
	// instance of Stock that has the value "Stock 3" for its name member variable.
	// Because the element that had the instance of Stock with "Stock 3" as its name member variable value
	// was the last remaining element in the unsorted linked list, the unsorted linked list should now be empty.
	//****************************************************
	cout << "The Instance Of StockList After Calling Delete (For Stock 3)" << endl << "------------------------------------------------------------" << endl << deleteTest;

	//****************************************************
	//
	//	TEST # 9: StockList's Insertion and Extraction Operator Overload.
	// 
	//****************************************************

	cout << endl << "*--------- TEST # 9: Insertion & Extraction Operator Overload Test -----------*" << endl << endl << endl;

	// Declaring an instance of StockList that will be used for StockList's insertion operator overload test.
	StockList insertionOverloadTest;
	
	// Declaring and initializing four instances of Stock that will be used for StockList's insertion operator overload test.
	Stock insertStock1("Ebay", 405, 600);
	Stock insertStock2("Amazon", 800, 100);
	Stock insertStock3("Walmart", 200, 300);
	Stock insertStock4("Staples", 10, 30);

	//****************************************************
	// Adding each of the four instances of Stock to the instance of StockList's unsorted linked list
	// by passing each instance of Stock into a call to the instance of StockList's Add function.
	//****************************************************
	insertionOverloadTest.Add(insertStock1);
	insertionOverloadTest.Add(insertStock2);
	insertionOverloadTest.Add(insertStock3);
	insertionOverloadTest.Add(insertStock4);

	// Declaring a string variable that stores the name of the file that the StockList data will be printed to.
	string fileName("InsertionOverloadTest.txt");

	//****************************************************
	// Declaring an instance of ofstream that will be used to output 
	// the unsorted linked list elements of a StockList instance to a file. 
	// The file it will open and print StockList data to is the file stored in 
	// the fileName variable passed into the ofstream instance's parameter.
	//****************************************************
	ofstream outFile(fileName);

	//****************************************************
	// Using the insertion operator overload to output the unsorted linked list elements
	// of the instance of StockList to the file that the instance of ofstream opened.
	//****************************************************
	outFile << insertionOverloadTest;

	// Declaring an instance of StockList that will be used for StockList's extraction operator overload test.
	StockList extractionOverloadTest;

	//****************************************************
	// Declaring an instance of ifstream that will be used to 
	// extract StockList data that is contained in a file. 
	// The file it will open and extract StockList data from is the file stored 
	// in the fileName variable passed into the instance of ifstream's parameter.
	//****************************************************
	ifstream inFile(fileName);

	//****************************************************
	// Using the extraction operator overload to extract instances of Stock that are in
	// the file that the instance of ifstream opened and then add each instance of Stock
	// that is extracted from the file to the unsorted linked list of the instance of StockList.
	//****************************************************
	inFile >> extractionOverloadTest;

	//****************************************************
	// Outputting extractionOverloadTest instance of StockList's unsorted linked list 
	// elements to the console to show the StockList data that was extract from the file.
	//****************************************************
	cout << "The Instance Of StockList Extracted From " << fileName << endl << "------------------------------------------------------------------" << endl << extractionOverloadTest;

	// Declaring an instance of Portfolio that will be used to output the author of the program's name.
	Portfolio getAuthorTest;
	// Printing the name of the author of this program through a call to the GetAuthor function.
	cout << endl << "BCS 370 - Homework #3 by " << getAuthorTest.GetAuthor() << "." << endl << endl;

	return 0;
}