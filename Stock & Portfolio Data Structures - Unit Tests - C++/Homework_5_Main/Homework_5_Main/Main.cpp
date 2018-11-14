//***************************************************
// File: Main.cpp
//
// Purpose: To perform tests on:
//			The Stock class's less-than and greater-than operator overloads.
//			The StockBST class's default constructor, copy constructor,
//			Clear function, Size function, Add function, Preorder function, Inorder function,
//			Postorder function, GetShares function, assignment operator overload, and insertion operator overload.
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
#include "Portfolio.h"
//***************************************************
// The header file of the StockBST class must be included
// so that instances of StockBST can be made inside main.
//***************************************************
#include "StockBST.h"

using namespace std;

//***************************************************
// Function: main
//
// Purpose: To perform tests on:
//			The Stock class's less-than and greater-than operator overloads.
//			The StockBST class's default constructor, copy constructor,
//			Clear function, Size function, Add function, Preorder function, Inorder function,
//			Postorder function, GetShares function, assignment operator overload, and insertion operator overload.
//
//***************************************************
int main() 
{
	//****************************************************
	//
	//			UPDATED STOCK CLASS UNIT TESTS
	// 
	//****************************************************

	cout << setw(49) << "Updated Stock Class Tests" << endl << setw(49) << "-------------------------" << endl << endl;

	//****************************************************
	//
	//	TEST # 1: Stock's Less-Than & Greater-Than Operator Overload.
	// 
	//****************************************************

	cout << "*------ TEST # 1: Stock Less-Than & Greater-Than Operator Overload Test ------*" << endl << endl;
	
	//****************************************************
	// Declaring and initializing two instances of Stock that will be used for  
	// Stock's less-than and greater-than operator overload tests.
	//****************************************************
	Stock p("P", 101, 102);
	Stock q("Q", 101, 102);

	//****************************************************
	// Because the letter "P" comes before "Q" in the English alphabet, "P" is less-than "Q". 
	// If Stock p being less than Stock q evaluates to true, then a message that indicates that the 
	// less-than operator overload of the Stock class is working correctly is output to the console.
	//****************************************************
	if (p < q)
	{
		cout << "Stock Less-Than Operator Overload Test: Pass." << endl;
	}
	//****************************************************
	// If the above condition evaluates to false, then a message indicating that the less-than
	// operator overload of the Stock class is not working correctly is output to the console.
	//****************************************************
	else
	{
		cout << "Stock Less-Than Operator Overload Test: FAIL!" << endl;
	}

	//****************************************************
	// Because the letter "Q" comes after "P" in the English alphabet, "Q" is greater-than "P". 
	// If Stock q being greater than Stock p evaluates to true, then a message that indicates that the 
	// greater-than operator overload of the Stock class is working correctly is output to the console.
	//****************************************************
	if (q > p)
	{
		cout << "Stock Greater-Than Operator Overload Test: Pass." << endl;
	}
	//****************************************************
	// If the above condition evaluates to false, then a message indicating that the greater-than
	// operator overload of the Stock class is not working correctly is output to the console.
	//****************************************************
	else
	{
		cout << "Stock Greater-Than Operator Overload Test: FAIL!" << endl;
	}

	//****************************************************
	//
	//			STOCKBST CLASS UNIT TESTS
	// 
	//****************************************************

	cout << endl << setw(47) << "StockBST Class Tests" << endl << setw(47) << "--------------------" << endl << endl;

	// Declaring an instance of StockBST that will be used for each of StockBST's function tests.
	StockBST stockBST;

	// Declaring and initializing five instances of Stock that will be used for each of StockBST's function tests.
	Stock j("J", 50, 100);
	Stock e("E", 150, 200);
	Stock f("F", 250, 300);
	Stock t("T", 350, 400);
	Stock a("A", 450, 500);

	//****************************************************
	//
	//	TEST # 2: StockBST's Default Constructor.
	// 
	//****************************************************

	cout << "*---------------- TEST # 2: StockBST Default Constructor Test ----------------*" << endl << endl;

	//****************************************************
	// Because StockBST's overloaded insertion operator is defined to output a
	// "The StockBST is empty." message when it is empty, it can be used to test
	// whether or not StockBST's default constructor created an empty binary search tree
	// since the instance of StockBST has not yet had any elements added to it's binary search tree.
	// The call to the Size function of the StockBST instance should also output 0
	// to indicate that the instance of StockBST has no elements after it is declared.
	//****************************************************
	cout << stockBST << "The length of the StockBST is " << stockBST.Size() << "." << endl;

	//****************************************************
	//
	//	TEST # 3: StockBST's Add & Size Function.
	// 
	//****************************************************

	cout << endl << "*---------------- TEST # 3: StockBST Add & Size Function Test ----------------*" << endl << endl;

	// Printing the empty instance of StockBST and its size to the console before the Add function is called.
	cout << "The StockBST Instance Before Calling Add" << endl << "----------------------------------------" << endl
		 << stockBST << "The length of the StockBST is " << stockBST.Size() << "." << endl << endl;

	//****************************************************
	// Adding each of the five instances of Stock to the instance of stockBST's binary search tree
	// by passing each instance of Stock into a call to the instance of StockBST's Add function.
	//****************************************************
	stockBST.Add(j);
	stockBST.Add(e);
	stockBST.Add(f);
	stockBST.Add(t);
	stockBST.Add(a);

	//****************************************************
	// Printing the elements and size of the instance of StockBST to the console after the Add function has been called five times.
	// The operator overload of the StockBST class is defined to output the values of all elements in the binary search tree on 
	// the given ostream using an inorder traversal of the tree that is keyed on a Stock's stockName field, 
	// meaning that the instance of StockBST's Stock elements will be printed in alphabetical order.
	// The call to the Size function from the instance of StockBST should also return 5.
	//****************************************************
	cout << "The StockBST Instance After Calling Add (5 Times)" << endl << "-------------------------------------------------" << endl
		 << stockBST << "The length of the StockBST is " << stockBST.Size() << "." << endl;

	//****************************************************
	//
	//	TEST # 4: StockBST's Copy Constructor Test.
	// 
	//****************************************************

	cout << endl << "*----------------- TEST # 4: StockBST Copy Constructor Test ------------------*" << endl << endl;

	// Printing the elements and size of the instance of StockBST that is going to be copied the console.
	cout << "The Instance of StockBST Being Copied" << endl << "-------------------------------------" << endl << stockBST
		 << "The length of the StockBST is " << stockBST.Size() << "." << endl << endl;

	//****************************************************
	// Declaring the second instance of StockBST that will be used to test StockBST's copy constructor and
	// initializing it by passing the first instance of StockBST into its copy constructor.
	//****************************************************
	StockBST copiedStockBST(stockBST);

	//****************************************************
	// Printing the elements of the instance of StockBST initialized with
	// the copy constructor to the console to show that it has the same elements
	// and the same size as the instance of StockBST that was passed into its copy constructor.
	//****************************************************
	cout << "The Instance of StockBST Initialized With The Copy Constructor" << endl << "--------------------------------------------------------------" << endl
		 << copiedStockBST << "The length of the StockBST is " << copiedStockBST.Size() << "." << endl << endl;

	//****************************************************
	//
	//	TEST # 5: StockBST's Preorder Function.
	// 
	//****************************************************

	cout << endl << "*----------------- TEST # 5: StockBST Preorder Function Test -----------------*" << endl << endl;

	cout << "The Instance of StockBST In Preorder Format" << endl << "-------------------------------------------" << endl;
	//****************************************************
	// Printing the only the name of each Stock element
	// in the instance of StockBST's binary search tree to
	// the console in a preorder format by calling the Preorder function.
	//****************************************************
	stockBST.Preorder();

	//****************************************************
	//
	//	TEST # 6: StockBST's Inorder Function.
	// 
	//****************************************************

	cout << endl << endl << "*------------------ TEST # 6: StockBST Inorder Function Test -----------------*" << endl << endl;

	cout << "The Instance of StockBST In Inorder Format" << endl << "------------------------------------------" << endl;
	//****************************************************
	// Printing the only the name of each Stock element
	// in the instance of StockBST's binary search tree to
	// the console in an inorder format by calling the Inorder function.
	//****************************************************
	stockBST.Inorder();

	//****************************************************
	//
	//	TEST # 7: StockBST's Postorder Function.
	// 
	//****************************************************

	cout << endl << endl << "*----------------- TEST # 7: StockBST Postorder Function Test ----------------*" << endl << endl;

	cout << "The Instance of StockBST In Postorder Format" << endl << "--------------------------------------------" << endl;
	//****************************************************
	// Printing the only the name of each Stock element
	// in the instance of StockBST's binary search tree to
	// the console in an postorder format by calling the Postorder function.
	//****************************************************
	stockBST.Postorder();

	//****************************************************
	//
	//	TEST # 8: StockBST's GetShares Function.
	// 
	//****************************************************

	cout << endl << endl << "*----------------- TEST # 8: StockBST GetShares Function Test ----------------*" << endl << endl;

	//****************************************************
	// Declaring a double variable that will be used to store the shares value
	// of the Stock that is being searched for in StockBST's GetShares function tests.
	//****************************************************
	double testShares;

	//****************************************************
	// Outputting the name of the first Stock that will have its name and shares
	// value be searched for within the instance of StockBST's binary search tree.
	//****************************************************
	cout << "Searching for Stock " << j.getStockName() << "'s shares..." << endl << "---------------------------------" << endl;

	//****************************************************
	// If the call to the GetShares function returns true, and if testShares is 
	// equal to the value returned by the getStockShares function call from the 
	// Stock instance that is being searched for by the GetShares function ("J"), 
	// then a message that indicates that the function is working correctly,
	// and the value of testShares, which is storing the shares value
	// of the Stock that was being searched for, are both printed to the console.
	//****************************************************
	if ((stockBST.GetShares("J", testShares)) && (testShares == j.getStockShares()))
	{
		cout << "The stock was found!" << endl << "Stock " << j.getStockName() << "'s shares = " << testShares << endl << endl;
	}
	//****************************************************
	// If the call to the GetShares function does not return true,
	// the above if statement fails. A message is printed that
	// indicates that the function is not working correctly.
	//****************************************************
	else
	{
		cout << "GetShares Function Test: FAIL!" << endl << endl;
	}

	//****************************************************
	// Outputting the name of the second Stock that will have its name and shares
	// value be searched for within the instance of StockBST's binary search tree.
	//****************************************************
	cout << "Searching for Stock " << f.getStockName() << "'s shares..." << endl << "---------------------------------" << endl;

	//****************************************************
	// If the call to the GetShares function returns true, and if testShares is 
	// equal to the value returned by the getStockShares function call from the 
	// Stock instance that is being searched for by the GetShares function ("F"), 
	// then a message that indicates that the function is working correctly,
	// and the value of testShares, which is storing the shares value
	// of the Stock that was being searched for, are both printed to the console.
	//****************************************************
	if ((stockBST.GetShares("F", testShares)) && (testShares == f.getStockShares()))
	{
		cout << "The stock was found!" << endl << "Stock " << f.getStockName() << "'s shares = " << testShares << endl << endl;
	}
	//****************************************************
	// If the call to the GetShares function does not return true,
	// the above if statement fails. A message is printed that
	// indicates that the function is not working correctly.
	//****************************************************
	else
	{
		cout << "GetShares Function Test: FAIL!" << endl << endl;
	}

	//****************************************************
	// Outputting the name of the third Stock that will have its name and shares
	// value be searched for within the instance of StockBST's binary search tree.
	//****************************************************
	cout << "Searching for Stock " << t.getStockName() << "'s shares..." << endl << "---------------------------------" << endl;

	//****************************************************
	// If the call to the GetShares function returns true, and if testShares is 
	// equal to the value returned by the getStockShares function call from the 
	// Stock instance that is being searched for by the GetShares function ("T"), 
	// then a message that indicates that the function is working correctly,
	// and the value of testShares, which is storing the shares value
	// of the Stock that was being searched for, are both printed to the console.
	//****************************************************
	if ((stockBST.GetShares("T", testShares)) && (testShares == t.getStockShares()))
	{
		cout << "The stock was found!" << endl << "Stock " << t.getStockName() << "'s shares = " << testShares << endl;
	}
	//****************************************************
	// If the call to the GetShares function does not return true,
	// the above if statement fails. A message is printed that
	// indicates that the function is not working correctly.
	//****************************************************
	else
	{
		cout << "GetShares Function Test: FAIL!" << endl << endl;
	}

	//****************************************************
	//
	//	TEST # 9: StockBST's Assignment Operator Overload.
	// 
	//****************************************************

	cout << endl << endl << "*------------ TEST # 9: StockBST Assignment Operator Overload Test -----------*" << endl << endl;

	// Declaring a third instance of StockBST that will be used for StockBST's assignment operator overload test.
	StockBST assignedStockBST;

	// Declaring and initializing three instances of Stock that will be used for StockBST's assignment operator overload test.
	Stock x("X", 8000, 7000);
	Stock y("Y", 6000, 5000);
	Stock z("Z", 4000, 3000);

	//****************************************************
	// Adding each of the three instances of Stock to the instance of assignedStockBST's binary search tree
	// by passing each instance of Stock into a call to the instance of StockBST's Add function.
	//****************************************************
	assignedStockBST.Add(y);
	assignedStockBST.Add(z);
	assignedStockBST.Add(x);

	//****************************************************
	// Printing the elements and size of the stockBST instance of StockBST's binary search tree
	// that will be assigned to the assignedStockBST instance of StockBST to the console.
	//****************************************************
	cout << "The Instance Of StockBST Being Assigned" << endl << "---------------------------------------" << endl << stockBST
		 << "The length of the StockBST is " << stockBST.Size() << "." << endl << endl;

	//****************************************************
	// Printing the elements and size of the assignedStockBST instance of StockBST
	// before the assignment operator overload is used to clear its binary search tree
	// and assign it a deep copy of the binary search tree of the stockBST instance of StockBST.
	//****************************************************
	cout << "The Instance Of StockBST Before Assignment" << endl << "------------------------------------------" << endl << assignedStockBST
		 << "The length of the StockBST is " << assignedStockBST.Size() << "." << endl << endl;

	//****************************************************
	// Assigning the binary search tree elements of the stockBST instance of StockBST
	// to be the binary search tree of the assignedStockBST instance of StockBST via the overloaded assignment operator.
	// Before a deep copy of the binary search tree elements is performed, the overloaded assignment operator 
	// is defined to clear the current instance StockBST of its binary search tree elements.
	// This means that the assignedStockBST instance of StockBST should not have any
	// of its original elements after the overloaded assignment operator is called.
	//****************************************************
	assignedStockBST = stockBST;

	//****************************************************
	// Outputting the elements of the assignedStockBST instance of StockBST after
	// the assignment operator overload is used to clear its binary search tree
	// and assign it a deep copy of the stockBST instance of StockBST's binary search tree.
	// The elements and size of the assignedStockBST instance of StockBST's binary search tree
	// should be the same as the the elements and size of the stockBST instance of StockBST's binary search tree.
	//****************************************************
	cout << "The Instance Of StockBST After Assignment" << endl << "-----------------------------------------" << endl << assignedStockBST
		 << "The length of the StockBST is " << assignedStockBST.Size() << "." << endl;

	//****************************************************
	//
	//	TEST # 10: StockBST's Insertion Operator Overload.
	// 
	//****************************************************

	cout << endl << endl << "*----------- TEST # 10: StockBST Insertion Operator Overload Test ------------*" << endl << endl;

	// Declaring a string variable that stores the name of the file that the StockBST data will be printed to.
	string bstFileName("bstInsertionOverloadTest.txt");

	//****************************************************
	// Declaring an instance of ofstream that will be used to output 
	// the instance of StockBST's binary search tree elements to a file. 
	// The file it will open and print StockBST data to is the file stored in 
	// the stockBSTFileName variable passed into the ofstream instance's parameter.
	//****************************************************
	ofstream bstInsertionOverloadOutFile(bstFileName);

	//****************************************************
	// Using the insertion operator overload to output the binary search tree of the
	// instance of StockBST to the file that the instance of ofstream opened.
	//****************************************************
	bstInsertionOverloadOutFile << stockBST;

	//****************************************************
	// Printing the instance of StockBST's elements to the
	// console to show the StockBST data that was written to the file.
	//****************************************************
	cout << "The Instance Of StockBST Written To " << bstFileName << endl
		 << "----------------------------------------------------------------" << endl << stockBST;

	//****************************************************
	//
	//	TEST # 11: StockBST's Clear Function.
	// 
	//****************************************************

	cout << "*------------------ TEST # 11: StockBST Clear Function Test ------------------*" << endl << endl;

	// Printing the elements and size of the instance of StockBST to the console before the Clear function is called.
	cout << "The Instance of StockBST Before Calling Clear" << endl << "---------------------------------------------" << endl << stockBST
		 << "The length of the StockBST is " << stockBST.Size() << "." << endl << endl;

	//****************************************************
	// Calling the Clear function from the instance of StockBST in order to
	// clear its binary search tree of all its elements and deallocate the dynamic
	// member that was allocated for each node in its binary search tree.
	//****************************************************
	stockBST.Clear();

	//****************************************************
	// Printing the elements and size of the instance of StockBST to the console after a call to the Clear function.
	// The insertion operator of the StockBST class is overloaded to output a message indicating 
	// when an instance of StockBST has an empty binary search tree, which is what should be output after Clear is called.
	//****************************************************
	cout << "The Instance of StockBST After Calling Clear" << endl << "--------------------------------------------" << endl << stockBST
		 << "The length of the StockBST is " << stockBST.Size() << "." << endl << endl;

	//****************************************************
	// StockBST's Preorder, Inorder, and Postorder functions also each return a message indicating 
	// when an instance of StockBST has an empty binary search tree, which is what each function call
	// should output to the console after the Clear function is called.
	//****************************************************
	cout << "The (Cleared) Instance of StockBST In Preorder, Inorder, & Postorder Format" << endl << "---------------------------------------------------------------------------" << endl;
	stockBST.Preorder();
	stockBST.Inorder();
	stockBST.Postorder();

	// Declaring an instance of Portfolio that will be used to output the author of the program's name.
	Portfolio getAuthorTest;
	// Printing the name of the author of this program through a call to the GetAuthor function.
	cout << endl << "BCS 370 - Homework #5 by " << getAuthorTest.GetAuthor() << "." << endl << endl;

	return 0;
}