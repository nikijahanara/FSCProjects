//****************************************************
// File: Main.cpp
//
// Purpose: To perform unit tests on the Stock class's Get/Set and CalculateValue functions
//			and the Portfolio class's Get/Set, PriceRangeCount, MostShares, FindByName, and TotalValue functions.
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
// Description: Updated the unit tests in the main function to now include unit tests for Stock's copy constructor,
//				assignment operator overload, insertion operator overload, and extraction operator overload.
//				Updated the unit tests in the main function to now also include unit tests for Portfolio's one parameter constructor,
//				copy constructor, assignment operator overload, insertion operator overload, Clone function, and Resize function.
//				
//
//***************************************************

#include<iostream>
#include <fstream>
//***************************************************
// The header file of the Portfolio class must be included
// so that instances of Portfolio and Stock can be made inside main.
//***************************************************
#include "Portfolio.h"

using namespace std;

//****************************************************
// Function: main
//
// Purpose: To perform unit tests on the Stock class's Get/Set and CalculateValue functions and
//			the Portfolio class's Get/Set, PriceRangeCount, MostShares, FindByName, and TotalValue functions.
//
// Update Information
// ------------------
//
// Name: Niki Jahanara
// Date: 10/10/2017
// Description: Updated the unit tests in the main function to now include unit tests for Stock's copy constructor,
//				assignment operator overload, insertion operator overload, and extraction operator overload.
//				Updated the unit tests in the main function to now also include unit tests for Portfolio's one parameter constructor,
//				copy constructor, assignment operator overload, insertion operator overload, Clone function, and Resize function.
//
//****************************************************
int main()
{
	//****************************************************
	//
	//				STOCK CLASS UNIT TESTS
	//
	//****************************************************
	cout << "Stock Class Automated Unit Tests" << endl << "--------------------------------" << endl;

	//****************************************************
	//
	//	TEST # 1: Stock's setStockName & getStockName functions.
	// 
	//****************************************************

	// Declaring an instance of Stock that will be used for the get/setStockName function tests.
	Stock stockGetSetNameTest;
	// Declaring a string variable that contains the name that will be used for the test.
	string testStockName = "Get/Set Stock Test Name";

	//****************************************************
	// Setting the stockName member variable of the instance of Stock to 
	// testStockName's value through a call to the setStockName function.
	//****************************************************
	stockGetSetNameTest.setStockName(testStockName);

	//****************************************************
	// If the Stock instance's call to the getStockName function
	// returns the value that it was assigned from the setStockName function,
	// then a message is printed that indicates that the
	// setStockName and getStockName functions are working correctly.
	//****************************************************
	if (stockGetSetNameTest.getStockName() == testStockName)
	{
		cout << "Stock Get/Set Name Test: Pass." << endl;
	}
	//****************************************************
	// If the Stock instance's call to the getStockName function
	// does not return the value that it was assigned from the setStockName function,
	// then a message is printed that indicates that the functions are not working correctly.
	//****************************************************
	else
	{
		cout << "Stock Get/Set Name Test: FAIL!" << endl;
	}

	//****************************************************
	//
	//	TEST # 2: Stock's setStockPrice & getStockPrice functions.
	// 
	//****************************************************

	// Declaring an instance of Stock that will be used for the get/setStockPrice function tests.
	Stock stockGetSetPriceTest;
	// Declaring a double variable that contains the price that will be used for this test.
	double testStockPrice = 800.0;

	//****************************************************
	// Setting the stockPrice member variable of the instance of Stock to 
	// testStockPrice's value through a call to the setStockPrice function.
	//****************************************************
	stockGetSetPriceTest.setStockPrice(testStockPrice);

	//****************************************************
	// If the Stock instance's call to the getStockPrice function
	// returns the value that it was assigned from the setStockPrice function,
	// then a message is printed that indicates that the
	// setStockPrice and getStockPrice functions are working correctly.
	//****************************************************
	if (stockGetSetPriceTest.getStockPrice() == testStockPrice)
	{
		cout << "Stock Get/Set Price Test: Pass." << endl;
	}
	//****************************************************
	// If the Stock instance's call to the getStockPrice function
	// does not return the value that it was assigned from the setStockPrice function,
	// then a message is printed that indicates that the functions are not working correctly.
	//****************************************************
	else
	{
		cout << "Stock Get/Set Price Test: FAIL!" << endl;
	}

	//****************************************************
	//
	//	TEST # 3: Stock's setStockShares & getStockShares functions.
	// 
	//****************************************************

	// Declaring an instance of Stock that will be used for the get/setStockShares function tests.
	Stock stockGetSetSharesTest;

	// Declaring a double variable that contains the share amount that will be used for this test.
	double testStockShares = 40.0;

	//****************************************************
	// Setting the stockShares member variable of the instance of Stock to 
	// testStockShares's value through a call to the setStockShares function.
	//****************************************************
	stockGetSetSharesTest.setStockShares(testStockShares);

	//****************************************************
	// If the Stock instance's call to the getStockShares function
	// returns the value that it was assigned from the setStockShares function,
	// then a message is printed that indicates that the
	// setStockShares and getStockShares functions are working correctly.
	//****************************************************
	if (stockGetSetSharesTest.getStockShares() == testStockShares)
	{
		cout << "Stock Get/Set Shares Test: Pass." << endl;
	}
	//****************************************************
	// If the Stock instance's call to the getStockShares function
	// does not return the value that it was assigned from the setStockShares function,
	// then a message is printed that indicates that the functions are not working correctly.
	//****************************************************
	else
	{
		cout << "Stock Get/Set Shares Test: FAIL!" << endl;
	}

	//****************************************************
	//
	//	TEST # 4: Stock's CalculateValue function.
	// 
	//****************************************************

	//****************************************************
	// Declaring and initializing an instance of Stock that 
	// will be used for the CalculateValue function test.
	// This instance of Stock is initialized with a price of $50 and 2 shares,
	// this means that the value of the Stock is $100 ($50 x 2).
	//****************************************************
	Stock stockCalculateValueTest("CalculateValue Test", 50, 2);

	//****************************************************
	// If the Stock instance's call to the CalculateValue function
	// returns 100, then a message is printed that indicates that the
	// CalculateValue function is working correctly.
	//****************************************************
	if (stockCalculateValueTest.CalculateValue() == 100)
	{
		cout << "Stock CalculateValue Test: Pass." << endl;
	}
	//****************************************************
	// If the Stock instance's call to the CalculateValue function
	// does not return 100, then a message is printed that 
	// indicates that the function is not working correctly.
	//****************************************************
	else
	{
		cout << "Stock CalculateValue Test: FAIL!" << endl;
	}

	//****************************************************
	//
	//				PORTFOLIO CLASS UNIT TESTS
	//
	//****************************************************
	cout << endl << "Portfolio Class Automated Unit Tests" << endl << "------------------------------------" << endl;

	//****************************************************
	//
	//	TEST # 5: Portfolio's Get & Set functions.
	// 
	//****************************************************

	// Declaring an instance of Portfolio that will be used for the Get/Set function tests.
	Portfolio portfolioGetSetTest;

	// Declaring and initializing an instance of Stock that will be used for Get/Set function tests.
	Stock testStock("Portfolio Get/Set Test", 45, 250);

	//****************************************************
	// Setting index 1 of the array of Stock of the instance of
	// Portfolio to the test instance of Stock through a call to
	// Portfolio's Set function.
	//****************************************************
	portfolioGetSetTest.Set(1, testStock);

	//****************************************************
	// If the Portfolio instance's call to the Get function
	// returns the instance of Stock that it was assigned at index 1 
	// from the Set function, then a message is printed
	// that indicates that the Set and Get functions are working correctly.
	// It is also possible to compare instances of Stock to
	// each other through the overload of the equality operator.
	//****************************************************
	if (portfolioGetSetTest.Get(1) == testStock)
	{
		cout << "Portfolio Get/Set Test: Pass." << endl;
	}
	//****************************************************
	// If the Portfolio instance's call to the Get function
	// does not return the instance of Stock that it was assigned
	// at index 1 of the Stock array from the Set function, 
	// then a message is printed that indicates that the functions are not working correctly.
	//****************************************************
	else
	{
		cout << "Portfolio Get/Set Test: FAIL!" << endl;
	}

	//****************************************************
	//
	//	TEST # 6: Portfolio's PriceRangeCount function.
	// 
	//****************************************************

	// Declaring an instance of Portfolio that will be used for the PriceRangeCount function test.
	Portfolio portfolioPriceRangeCountTest;

	// Declaring and initializing six instances of Stock that will be used for the PriceRangeCount function test.
	Stock stockPrice1("Test Price 1", 10, 1);
	Stock stockPrice2("Test Price 2", 20, 2);
	Stock stockPrice3("Test Price 3", 15, 3);
	Stock stockPrice4("Test Price 4", 25, 4);
	Stock stockPrice5("Test Price 5", 30, 5);
	Stock stockPrice6("Test Price 6", 40, 6);

	// Setting the first 6 indexes of the Stock array to each of the instances of Stock declared above.
	portfolioPriceRangeCountTest.Set(0, stockPrice1);
	portfolioPriceRangeCountTest.Set(1, stockPrice2);
	portfolioPriceRangeCountTest.Set(2, stockPrice3);
	portfolioPriceRangeCountTest.Set(3, stockPrice4);
	portfolioPriceRangeCountTest.Set(4, stockPrice5);
	portfolioPriceRangeCountTest.Set(5, stockPrice6);

	// Declaring and initializing the double variable lowestPrice to 20.
	double lowestPrice = 20.0;
	// Declaring and initializing the double variable highestPrice to 30.
	double highestPrice = 30.0;

	//****************************************************
	// Because the lowestPrice was set to 20, and the highestPrice was set to 30,
	// a call to the PriceRangeCount function from the instance of Portfolio must return 3 
	// since there are only 3 Stocks within the Portfolio instance's Stock array that have
	// a price that is in the 20 to 30 inclusive range: stockPrice2(20), stockPrice4(25), and stockPrice5(30).
	//****************************************************
	if (portfolioPriceRangeCountTest.PriceRangeCount(lowestPrice, highestPrice) == 3)
	{
		cout << "Portfolio PriceRangeCount Test: Pass." << endl;
	}
	//****************************************************
	// If the call to the PriceRangeCount function does not return 3, 
	// then a message is printed that indicates that the function is not working correctly.
	//****************************************************
	else
	{
		cout << "Portfolio PriceRangeCount Test: FAIL!" << endl;
	}

	//****************************************************
	//
	//	TEST # 7: Portfolio's MostShares function.
	// 
	//****************************************************

	// Declaring an instance of Portfolio that will be used for the MostShares function test.
	Portfolio portfolioMostSharesTest;

	//****************************************************
	// Declaring and initializing two instances of Stock that will be used for the MostShares function test.
	// The stock instance with the most shares is indicated by its name: stockMostShares.
	//****************************************************
	Stock stockLeastShares("Shares Test 1", 10, 5);
	Stock stockMostShares("Shares Test 2", 20, 100);

	//****************************************************
	// Setting the first two indexes of the Portfolio instance's Stock array
	// to the two instances of Stock declared above through a call to the Set function.
	//****************************************************
	portfolioMostSharesTest.Set(0, stockLeastShares);
	portfolioMostSharesTest.Set(1, stockMostShares);

	//****************************************************
	// Because the stockMostShares instance of Stock has the most amount of shares,
	// if a call to the MostShares function returns the stockMostShares instance,
	// then a message is printed that indicates that the function is working correctly.
	//****************************************************
	if (portfolioMostSharesTest.MostShares() == stockMostShares)
	{
		cout << "Portfolio MostShares Test: Pass." << endl;
	}
	//****************************************************
	// If a call to the MostShares function does not return the stockMostShares instance,
	// then a message is printed that indicates that the function is not working correctly.
	//****************************************************
	else
	{
		cout << "Portfolio MostShares Test: FAIL!" << endl;
	}

	//****************************************************
	//
	//	TEST # 8: Portfolio's FindByName function.
	// 
	//****************************************************

	// Declaring an instance of Portfolio that will be used for the FindByName function test.
	Portfolio portfolioFindByNameTest;

	// Declaring and initializing an instance of Stock with a name that will be used for the FindByName function test.
	Stock stockNameTest("Find This Name", 10, 100);

	//****************************************************
	// Declaring an instance of Stock that will be used to test if the FindByName function copies
	// the member variables of the instance of Stock that has the given name into its Stock reference parameter.
	//****************************************************
	Stock stockCopyTest;

	//****************************************************
	// Setting the 0 index of the Portfolio instance's Stock array
	// equal to the member variable values of stockNameTest.
	//****************************************************
	portfolioFindByNameTest.Set(0, stockNameTest);

	//****************************************************
	// If the call to the FindByName function returns true, and
	// if stockCopyTest is equal to the instance of Stock in the array
	// that has the given Stock name (stockNameTest), then
	// a message is printed that indicates that the function is working correctly.
	//****************************************************
	if ((portfolioFindByNameTest.FindByName("Find This Name", stockCopyTest) == true) && (stockCopyTest == stockNameTest))
	{
		cout << "Portfolio FindByName Test: Pass." << endl;
	}
	//****************************************************
	// If the call to the FindByName function does not return true,
	// the above if statement fails. A message is printed that indicates
	// that the function is not working correctly.
	//****************************************************
	else
	{
		cout << "Portfolio FindByName Test: FAIL!" << endl;
	}

	//****************************************************
	//
	//	TEST # 9: Portfolio's TotalValue function.
	// 
	//****************************************************

	// Declaring an instance of Portfolio that will be used for the TotalValue function test.
	Portfolio portfolioTotalValueTest;

	//****************************************************
	// Declaring and initializing two instances of Stock that will be used for the TotalValue function test.
	// The value of the first Stock instance declared is 20 (10 * 2) and
	// the value of the second Stock instance declared is 40 (20 * 2).
	// Therefore, the total value of the Stocks in the instance of Portfolio will be 60 (20 + 40).
	//****************************************************
	Stock stockValue1("Value Test 1", 10, 2);
	Stock stockValue2("Value Test 2", 20, 2);

	//****************************************************
	// The total value of the instances of Stock declared above can be calculated
	// by calling the CalculateValue funtion for each instance of Stock and
	// then adding the two values returned by the CalculateValue function call for each instance of Stock.
	//****************************************************
	double stockTotalValue = stockValue1.CalculateValue() + stockValue2.CalculateValue();

	//****************************************************
	// Setting the first two indexes of the Portfolio instance's Stock array
	// to the two instances of Stock declared above through a call to the Set function.
	//****************************************************
	portfolioTotalValueTest.Set(0, stockValue1);
	portfolioTotalValueTest.Set(1, stockValue2);

	//****************************************************
	// If the call to the TotalValue function returns the value of the stockTotalValue variable,
	// then a message is printed that indicates that the function is working correctly.
	//****************************************************
	if (portfolioTotalValueTest.TotalValue() == stockTotalValue)
	{
		cout << "Portfolio TotalValue Test: Pass." << endl;
	}
	//****************************************************
	// If the call to the TotalValue function does not return the value fo the stockTotalValue variable,
	// then a message is printed that indicates that the function is not working correctly.
	//****************************************************
	else
	{
		cout << "Portfolio TotalValue Test: FAIL!" << endl;
	}

	//****************************************************
	//
	//		NJ 10/10/2017 - UPDATED STOCK CLASS AUTOMATED UNIT TESTS
	//
	//****************************************************
	cout << endl << "Updated Stock Class Automated Unit Tests" << endl << "----------------------------------------" << endl;

	//****************************************************
	//
	//	NJ 10/10/2017 - TEST # 10: Stock's Copy Constructor.
	// 
	//****************************************************

	// NJ 10/10/2017 - Declaring and initializing an instance of Stock that will be used for Stock's copy constructor test.
	Stock originalStock("Stock Copy Constructor Name", 900, 1000);
	//****************************************************
	// NJ 10/10/2017 - Declaring a second instance of Stock that is initialized by passing the originalStock instance of Stock 
	//				   into its copy constructor that performs a deep copy of originalStock's member variable values.
	//****************************************************
	Stock stockCopyConstructorTest(originalStock);

	//****************************************************
	// NJ 10/10/2017 - If the stockCopyConstructorTest instance of Stock has
	//				   member variable values that are equal to the member variable
	//				   values of the originalStock instance of Stock that was passed into
	//				   its copy constructor, then a message is printed that indicates that 
	//				   the copy constructor of Stock is working correctly.
	//****************************************************
	if (stockCopyConstructorTest == originalStock)
	{
		cout << "Stock Copy Constructor Test: Pass." << endl;
	}
	//****************************************************
	// NJ 10/10/2017 - If the stockCopyConstructorTest instance of Stock has member variable values
	//				   that are not equal to the member variable values of the originalStock instance of
	//				   Stock that was passed into its copy constructor, then a message is printed 
	//				   that indicates that Stock's copy constructor is not working correctly.
	//****************************************************
	else
	{
		cout << "Stock Copy Constructor Test: FAIL!" << endl;
	}

	//****************************************************
	//
	//	NJ 10/10/2017 - TEST # 11: Stock's Assignment(=) Operator Overload.
	// 
	//****************************************************

	// NJ 10/10/2017 - Declaring and initializing an instance of Stock that will be used for Stock's assignment operator overload test.
	Stock assignStock("Stock Assignment Operator Overload Test", 400, 3000);
	// NJ 10/10/2017 - Declaring a second instance of Stock that will be used for Stock's assignment operator overload test.
	Stock stockAssignmentOverloadTest;

	//****************************************************
	// NJ 10/10/2017 - Assigning the stockAssignmentOverloadTest instance of Stock's member variable
	//				   values to be equal to the member variable values of the assignStock
	//				   instance of Stock's member variable values via the overloaded assignment
	//				   operator that performs a deep copy of the member variable values.
	//****************************************************
	stockAssignmentOverloadTest = assignStock;

	//****************************************************
	// NJ 10/10/2017 - If the stockAssignmentOverloadTest instance of Stock has
	//				   member variable values that are equal to the member variable
	//				   values of the assignStock instance of Stock,
	//				   then a message is printed that indicates that 
	//				   the assignment operator overload of Stock is working correctly.
	//****************************************************
	if (stockAssignmentOverloadTest == assignStock)
	{
		cout << "Stock Assignment Operator Overload Test: Pass." << endl;
	}
	//****************************************************
	// NJ 10/10/2017 - If the stockAssignmentOverloadTest instance of Stock does not have
	//				   member variable values that are equal to the member variable
	//				   values of the assignStock instance of Stock,
	//				   then a message is printed that indicates that 
	//				   the assignment operator overload of Stock is not working correctly.
	//****************************************************
	else
	{
		cout << "Stock Assignment Operator Overload Test: FAIL!" << endl;
	}

	//****************************************************
	//
	//	NJ 10/10/2017 - TEST # 12: Stock's insertion(<<) & extraction(>>) operator overload.
	// 
	//****************************************************

	// NJ 10/10/2017 - Declaring and initializing an instance of Stock that will be used for Stock's insertion operator overload test.
	Stock stockInsertionOverloadTest("StockInsertionOverloadTestName", 333, 999);

	// NJ 10/10/2017 - Declaring an instance of ofstream that will be used to output the values of a Stock instance's member variables to a file.
	ofstream stockOutData;

	//****************************************************
	// NJ 10/10/2017 - Opening the StockInsertionOverloadTest.txt file so that the instance of ofstream can output
	//				   the member variable values of an instance of Stock to it.
	//****************************************************
	stockOutData.open("StockInsertionOverloadTest.txt");

	//****************************************************
	// NJ 10/10/2017 - Using the insertion operator overload to output the member variable values
	//				   of an instance of Stock to the file that the instance of ofstream opened.
	//****************************************************
	stockOutData << stockInsertionOverloadTest;

	// NJ 10/10/2017 - Closing the instance of ofstream that was opened.
	stockOutData.close();

	// NJ 10/10/2017 - Declaring an instance of Stock that will be used for Stock's extraction operator overload test.
	Stock stockExtractionOverloadTest;

	// NJ 10/10/2017 - Declaring an instance of ifstream that will be used to read the the values of a Stock instance's member variables from a file.
	ifstream stockInData;

	//****************************************************
	// NJ 10/10/2017 - Opening the StockInsertionOverloadTest.txt file so that the instance of ifstream can 
	//				   read in the the member variable values of the instance of Stock that was written to it.
	//****************************************************
	stockInData.open("StockInsertionOverloadTest.txt");

	//****************************************************
	// NJ 10/10/2017 - Using the extraction operator overload to read in the member variable values
	//				   of an instance of Stock in the file that the instance of ifstream opened and
	//				   assigning those values to the member variable values of the 
	//				   stockExtractionOverloadTest instance of Stock.
	//****************************************************
	stockInData >> stockExtractionOverloadTest;

	// NJ 10/10/2017 - Closing the instance of ifstream that was opened.
	stockInData.close();

	//****************************************************
	// NJ 10/10/2017 - If the member variable values that the overloaded extraction operator read in
	//				   from the file and assigned to the stockExtractionOverloadTest instance of 
	//				   Stock is equal to the stockInsertionOverloadTest instance of Stock's member variable values, 
	//				   then the extraction operator is working correctly. 
	//				   Because the overloaded insertion operator was used to write the values of stockInsertionOverloadTest
	//				   to the file that the the overloaded extraction operator read in Stock member variable values from, 
	//				   then the stockExtractionOverloadTest and stockInsertionOverloadTest should have
	//				   the same member variable values. If they do, a message is printed 
	//				   that indicates that the extraction operator overload is working correctly.
	//				   To check that the insertion operator overload output the correct values to
	//				   the file that it wrote to, the file itself must be checked.
	//****************************************************
	if (stockExtractionOverloadTest == stockInsertionOverloadTest)
	{
		cout << "Stock Extraction Operator Overload Test: Pass." << endl;
	}
	//****************************************************
	// NJ 10/10/2017 - If stockExtractionOverloadTest and stockInsertionOverloadTest do not have the same member variable
	//				   values, then the extraction operator is not working correctly and
	//				   a message is printed to the screen to indicate that it is not working correctly.
	//****************************************************
	else
	{
		cout << "Stock Extraction Operator Overload Test: FAIL!" << endl;
	}

	//****************************************************
	//
	//		NJ 10/10/2017 - UPDATED PORTFOLIO CLASS AUTOMATED UNIT TESTS
	//
	//****************************************************
	cout << endl << "Updated Portfolio Class Automated Unit Tests" << endl << "--------------------------------------------" << endl;

	//****************************************************
	//
	//	NJ 10/10/2017 - TEST # 13: Portfolio's One Parameter Constructor.
	// 
	//****************************************************

	//****************************************************
	// NJ 10/10/2017 - Declaring an instance of Portfolio and setting its Stock array size to
	//				   20 by passing 20 into the one paramater constructor of Portfolio
	//				   that is supposed to set the size of the Stock array to the
	//				   integer size that is passed into the constructor.
	//****************************************************
	Portfolio portfolioOneParameterTest(20);

	//****************************************************
	// NJ 10/10/2017 - If a call to the instance of Portfolio's Size function returns 20,
	//				   then a message is printed that indicates that Portfolio's 
	//				   one parameter constructor is working correctly.
	//****************************************************
	if (portfolioOneParameterTest.Size() == 20)
	{
		cout << "Portfolio One Parameter Constructor Test: Pass." << endl;
	}
	//****************************************************
	// NJ 10/10/2017 - If a call to the instance of Portfolio's Size function does
	//				   not return 20, then a message is printed that indicates
	//				   that Portfolio's one parameter constructor is not working correctly.
	//****************************************************
	else
	{
		cout << "Portfolio One Parameter Constructor Test: FAIL!" << endl;
	}

	//****************************************************
	//
	//	NJ 10/10/2017 - TEST # 14: Portfolio's Copy Constructor.
	// 
	//****************************************************

	//****************************************************
	// NJ 10/10/2017 - Declaring an instance of Portfolio that will be used for Portfolio's copy constructor test.
	//				   This instance of Portfolio's Stock array is also initialized to have an size of 2.
	//****************************************************
	Portfolio portfolioCopy(2);

	// NJ 10/10/2017 - Declaring and initializing two instances of Stock that will be used for Portfolio's copy constructor test.
	Stock stockCopy1("Stock Copy 1", 30, 600);
	Stock stockCopy2("Stock Copy 2", 70, 1000);

	//****************************************************
	// NJ 10/10/2017 - Setting the two indexes of the Portfolio instance's Stock array
	//				   to the two instances of Stock declared above through a call to the Set function.
	//****************************************************
	portfolioCopy.Set(0, stockCopy1);
	portfolioCopy.Set(1, stockCopy2);

	//****************************************************
	// NJ 10/10/2017 - Delcaring a second instance of Portfolio, portfolioCopyConstructorTest,
	//				   that passes the first instance of Portfolio into its copy constructor
	//				   so that a deep copy of the member variable values of the instance of
	//				   Portfolio passed into the constructor can be performed into
	//				   the member variable values of the portfolioCopyConstructorTest instance of Portfolio.
	//****************************************************
	Portfolio portfolioCopyConstructorTest(portfolioCopy);

	//****************************************************
	// NJ 10/10/2017 - If the portfolioCopyConstructorTest instance of Portfolio has
	//				   member variable values that are equal to the member variable
	//				   values of the portfolioCopy instance of Portfolio
	//				   that was passed into its copy constructor, then a message 
	//				   is printed that indicates that the copy constructor of Portfolio is working correctly.
	//****************************************************
	if (portfolioCopyConstructorTest == portfolioCopy)
	{
		cout << "Portfolio Copy Constructor Test: Pass." << endl;
	}
	//****************************************************
	// NJ 10/10/2017 - If the portfolioCopyConstructorTest instance of Portfolio has member variable values
	//				   that are not equal to the member variable values of the portfolioCopy
	//				   instance of Portfolio that was passed into its copy constructor, then a message is printed 
	//				   that indicates that Portfolio's copy constructor is not working correctly.
	//****************************************************
	else
	{
		cout << "Portfolio Copy Constructor Test: FAIL!" << endl;
	}

	//****************************************************
	//
	//	NJ 10/10/2017 - TEST # 15: Portfolio's Assignment(=) Operator Overload.
	// 
	//****************************************************

	//****************************************************
	// NJ 10/10/2017 - Declaring an instance of Portfolio that will be used for Portfolio's assignment operator overload test.
	//				   This instance of Portfolio's Stock array is also initialized to have an size of 3.
	//****************************************************
	Portfolio originalPortfolio(3);

	// NJ 10/10/2017 - Declaring and initializing three instances of Stock that will be used for Portfolio's assignment operator overload test.
	Stock assignmentStock1("Assigned Stock 1", 200, 700);
	Stock assignmentStock2("Assigned Stock 2", 800, 400);
	Stock assignmentStock3("Assigned Stock 3", 1000, 5000);

	//****************************************************
	// NJ 10/10/2017 - Setting the three indexes of the Portfolio instance's Stock array
	//				   to the three instances of Stock declared above through a call to the Set function.
	//****************************************************
	originalPortfolio.Set(0, assignmentStock1);
	originalPortfolio.Set(1, assignmentStock2);
	originalPortfolio.Set(2, assignmentStock3);

	// NJ 10/10/2017 - Declaring a second instance of Portfolio that will be used for Portfolio's assignment operator overload test.
	Portfolio portfolioAssignmentOverloadTest;

	//****************************************************
	// NJ 10/10/2017 - Assigning the portfolioAssignmentOverloadTest instance of Portfolio's member variable
	//				   values to be equal to the member variable values of the originalPortfolio
	//				   instance of Portfolio's member variable values via the overloaded assignment
	//				   operator that performs a deep copy of the member variable values.
	//****************************************************
	portfolioAssignmentOverloadTest = originalPortfolio;

	//****************************************************
	// NJ 10/10/2017 - If the portfolioAssignmentOverloadInstance instance of Portfolio has
	//				   member variable values that are equal to the member variable
	//				   values of the originalPortfolio instance of Portfolio,
	//				   then a message is printed that indicates that 
	//				   the assignment operator overload of Portfolio is working correctly.
	//****************************************************
	if (portfolioAssignmentOverloadTest == originalPortfolio)
	{
		cout << "Portfolio Assignment Operator Overload Test: Pass." << endl;
	}
	//****************************************************
	// NJ 10/10/2017 - If the portfolioAssignmentOverloadTest instance of Portfolio does not have
	//				   member variable values that are equal to the member variable
	//				   values of the originalPortfolio instance of Portfolio,
	//				   then a message is printed that indicates that 
	//				   the assignment operator overload of Portfolio is not working correctly.
	//****************************************************
	else
	{
		cout << "Portfolio Assignment Operator Overload Test: FAIL!" << endl;
	}

	//****************************************************
	//
	//	NJ 10/10/2017 - TEST # 16: Portfolio's Insertion(<<) Operator Overload.
	// 
	//****************************************************

	//****************************************************
	// NJ 10/10/2017 - Declaring an instance of Portfolio that will be used for Portfolio's insertion operator overload test.
	//				   This instance of Portfolio's Stock array is also initialized to have an size of 4.
	//****************************************************
	Portfolio portfolioInsertionTest(4);

	// NJ 10/10/2017 - Declaring and initializing four instances of Stock that will be used for Portfolio's insertion operator overload test.
	Stock insertionStock1("Portfolio Insertion Overload Test Stock 1", 100, 20);
	Stock insertionStock2("Portfolio Insertion Overload Test Stock 2", 400, 80);
	Stock insertionStock3("Portfolio Insertion Overload Test Stock 3", 300, 150);
	Stock insertionStock4("Portfolio Insertion Overload Test Stock 4", 900, 500);

	//****************************************************
	// NJ 10/10/2017 - Setting the four indexes of the Portfolio instance's Stock array
	//				   to the four instances of Stock declared above through a call to the Set function.
	//****************************************************
	portfolioInsertionTest.Set(0, insertionStock1);
	portfolioInsertionTest.Set(1, insertionStock2);
	portfolioInsertionTest.Set(2, insertionStock3);
	portfolioInsertionTest.Set(3, insertionStock4);

	// NJ 10/10/2017 - Declaring an instance of ofstream that will be used to output the values of an instance of Portfolio's Stock array to a file.
	ofstream portfolioOutData;

	//****************************************************
	// NJ 10/10/2017 - Opening the PortfolioInsertionOverloadTest.txt file so that the instance of ofstream can 
	//				   output the the member variable values of the instance of Portfolio to that file.
	//****************************************************
	portfolioOutData.open("PortfolioInsertionOverloadTest.txt");

	//****************************************************
	// NJ 10/10/2017 - Using the insertion operator overload to output the member variable values
	//				   of an instance of Portfolio to the file that the instance of ofstream opened.
	//****************************************************
	portfolioOutData << portfolioInsertionTest;

	// NJ 10/10/2017 - Closing the instance of ofstream that was opened.
	portfolioOutData.close();

	//****************************************************
	//
	//	NJ 10/10/2017 - TEST # 17: Portfolio's Clone function.
	// 
	//****************************************************

	//****************************************************
	// NJ 10/10/2017 - Declaring an instance of Portfolio that will be used for Portfolio's Clone function test.
	//				   This instance of Portfolio's Stock array is also initialized to have an size of 2.
	//****************************************************
	Portfolio portfolioCloneTest(2);

	// NJ 10/10/2017 - Declaring and initializing two instances of Stock that will be used for Portfolio's Clone function test.
	Stock cloneStock1("Clone Stock Name 1", 400, 500);
	Stock cloneStock2("Clone Stock Name 2", 600, 700);

	//****************************************************
	// NJ 10/10/2017 - Setting the two indexes of the Portfolio instance's Stock array
	//				   to the two instances of Stock declared above through a call to the Set function.
	//****************************************************
	portfolioCloneTest.Set(0, cloneStock1);
	portfolioCloneTest.Set(1, cloneStock2);

	//****************************************************
	// NJ 10/10/2017 - Assigning the address to the new dynamic instance of
	//				   the portfolioCloneTest instance of Portfolio that the Clone function creates to 
	//				   portfolioClone, which is a pointer to an instance of Portfolio.
	//****************************************************
	Portfolio* portfolioClone = portfolioCloneTest.Clone();

	//****************************************************
	// NJ 10/10/2017 - If the member variable values that the portfolioClone pointer is
	//				   pointing to is equal to the member variable values of portfolioCloneTest,
	//				   then portfolioCloneTest was successfully cloned through a call to the
	//				   Clone function and a message inidicating that the Clone function is working correctly is printed.
	//****************************************************
	if (*portfolioClone == portfolioCloneTest)
	{
		cout << "Portfolio Clone Test: Pass." << endl;
	}
	//****************************************************
	// NJ 10/10/2017 - If the member variable values that the portfolioClone pointer is
	//				   pointing to is not equal to the member variable values of portfolioCloneTest,
	//				   then portfolioCloneTest was not successfully cloned through a call to the
	//				   Clone function and a message inidicating that the Clone function is not working correctly is printed.
	//****************************************************
	else
	{
		cout << "Portfolio Clone Test: FAIL!" << endl;
	}

	//****************************************************
	// NJ 10/10/2017 - In order to prevent a memory leak, the dynamic memory that was
	//				   allocated in the Clone function must be deleted. Because the
	//				   address to the pointer of the new instance of Portfolio was stored inside
	//				   of the portfolioClone pointer, delete is called on the
	//				   portfolioClone pointer in order to deallocate that dynamic memory.
	//****************************************************
	delete portfolioClone;

	//****************************************************
	//
	//	NJ 10/10/2017 - TEST # 18: Portfolio's Resize Test.
	// 
	//****************************************************

	cout << endl << "Resize Test 1: Resizing The Stock Array's Size From 3 To 5" << endl << "----------------------------------------------------------" << endl;

	//****************************************************
	// NJ 10/10/2017 - Declaring an instance of Portfolio that will be used for Portfolio's first Resize function test.
	//				   This instance of Portfolio's Stock array is also initialized to have an size of 3.
	//****************************************************
	Portfolio portfolioResizeTest(3);

	// NJ 10/10/2017 - Declaring and initializing three instances of Stock that will be used for Portfolio's first Resize function test.
	Stock resizeStock1("Stock 1", 10, 20);
	Stock resizeStock2("Stock 2", 30, 40);
	Stock resizeStock3("Stock 3", 50, 60);

	//****************************************************
	// NJ 10/10/2017 - Setting the three indexes of the Portfolio instance's Stock array
	//				   to the three instances of Stock declared above through a call to the Set function.
	//****************************************************
	portfolioResizeTest.Set(0, resizeStock1);
	portfolioResizeTest.Set(1, resizeStock2);
	portfolioResizeTest.Set(2, resizeStock3);

	// NJ 10/10/2017 - Outputting the Stock array of the instance of Portfolio before the Resize function is called.
	cout << endl << "Before Resize to 5:" << endl << "-------------------" << endl << portfolioResizeTest;

	//****************************************************
	// NJ 10/10/2017 - Calling the Resize function from an instance of Portfolio 
	//				   in order to "resize" the Stock array of the Portfolio instance
	//				   to have a larger size of 5 instead of 3.
	//****************************************************
	portfolioResizeTest.Resize(5);

	// NJ 10/10/2017 - Outputting the Stock array of the instance of Portfolio after the Resize function is called.
	cout << endl << "After Resize to 5:" << endl << "------------------" << endl << portfolioResizeTest;

	cout << endl << "Resize Test 2: Resizing The Stock Array's Size From 5 To 2" << endl << "----------------------------------------------------------" << endl;

	// NJ 10/10/2017 - Outputting the Stock array of the instance of Portfolio before the Resize function is called again.
	cout << endl << "Before Resize to 2:" << endl << "-------------------" << endl << portfolioResizeTest;

	//****************************************************
	// NJ 10/10/2017 - Calling the Resize function from the instance of Portfolio 
	//				   again in order to "resize" the Stock array of the Portfolio instance
	//				   to have a smaller size of 2 instead of 5.
	//****************************************************
	portfolioResizeTest.Resize(2);

	// NJ 10/10/2017 - Outputting the Stock array of the instance of Portfolio after the Resize function is called again.
	cout << endl << "After Resize to 2:" << endl << "------------------" << endl << portfolioResizeTest;

	// Declaring an instance of Portfolio that will be used to output the author of the program's name.
	Portfolio getAuthorTest;
	// Printing the name of the author of this program through a call to the GetAuthor function.
	cout << endl << "BCS 370 - Homework #2 by " << getAuthorTest.GetAuthor() << "." << endl << endl;

	return 0;
}