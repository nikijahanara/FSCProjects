//****************************************************
// File: StockList.h
//
// Purpose: To store the StockList class's private member variables, the private StockListNode struct definition,
//			and the prototypes of StockList's public functions.
//
// Written By: Niki Jahanara
//
// Compiler: Visual Studio Express 2013 (For Windows Desktop)
// 
//***************************************************

// Preprocessor guards are added to to the StockList header file so that multiple #includes can be allowed.
#ifndef STOCKLIST_H
#define STOCKLIST_H

#include<iostream>
#include<string>

//***************************************************
// The Stock header file must be included so that an
// instance of Stock can be declared within the StockList class.
//***************************************************
#include "Stock.h"

class StockList {

	private:
		// The definition of the StockListNode struct is private within the definition of the StockList class.
		struct StockListNode 
		{
			//***************************************************
			// The data each StockListNode contains is an instance of Stock.
			// An instance of Stock must therefore be declared as a
			// member variable within the definition of the StockListNode struct.
			//***************************************************
			Stock stockData;
			//***************************************************
			// Declaring a pointer instance of StockListNode 
			// within the definition of the StockListNode struct that
			// will be used to point to the next StockListNode in
			// an instance of StockList's unsorted linked list.
			//***************************************************
			StockListNode *next;
		};

		//***************************************************
		// Declaring an integer member variable that will be used to keep a count of how many
		// StockListNode elements are in an instance of StockList's unsorted linked list.
		//***************************************************
		int length;
		//***************************************************
		// Declaring a member variable that is a pointer instance of StockListNode 
		// that will be used to point to the first StockListNode element in
		// an instance of StockList's unsorted linked list.
		//***************************************************
		StockListNode *listData;

	public:
		// Prototype for StockList's default constructor.
		StockList();
		// Prototype for StockList's copy constructor.
		StockList(const StockList& otherList);

		// Prototype for the Clear function of StockList.
		void Clear();

		// Prototype for the Length function of StockList.
		int Length() const;

		// Prototype for the Add function of StockList.
		void Add(const Stock s);

		//***************************************************
		// Prototype for the overloaded Add function of StockList that 
		// appends all elements from otherList on to the current list.
		//***************************************************
		void Add(const StockList& otherList);

		// Prototype for the FindByName function of StockList.
		bool FindByName(std::string name, Stock& result) const;

		// Prototype for the Delete function of StockList.
		void Delete(std::string name);

		//****************************************************
		// Prototypes for the non-member overloads of the insertion and extraction operator.
		// Because they are non-member overloads, the prototypes must be "friended" so that
		// they can have access to the member variables of the StockList class.
		//****************************************************
		friend std::ostream& operator<<(std::ostream& os, StockList& rhs);
		friend std::istream& operator>>(std::istream& is, StockList& rhs);

		// Prototype for member overload of the assignment operator for StockList.
		StockList& operator=(const StockList& rhs);

		// Prototype for StockList's destructor.
		~StockList();
};

#endif