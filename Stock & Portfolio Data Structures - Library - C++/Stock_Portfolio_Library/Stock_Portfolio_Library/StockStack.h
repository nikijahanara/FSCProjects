//****************************************************
// File: StockStack.h
//
// Purpose: To store both the StockStack class's private member variables and the prototypes of StockStack's public functions.
//
// Written By: Niki Jahanara
//
// Compiler: Visual Studio Express 2013 (For Windows Desktop)
// 
//***************************************************

// Preprocessor guards are added to to the StockStack header file so that multiple #includes can be allowed.
#ifndef STOCKSTACK_H
#define STOCKSTACK_H

#include<iostream>
#include<string>

//***************************************************
// The Stock header file must be included so that an
// instance of Stock can be declared within the StockStack class.
//***************************************************
#include "Stock.h"

class StockStack {

	private:
		//***************************************************
		// Declaring a private integer member variable, maxStackSize, that 
		// will store the maximum size of the stack.
		//***************************************************
		int maxStackSize;
		//***************************************************
		// Declaring a private integer member variable, stackTop, that will be used 
		// to store the index of the element that is at the top of the stack.
		//***************************************************
		int stackTop;
		//***************************************************
		// Declaring a private pointer instance of Stock that will be initialized as a
		// dynamically allocated array in each of StockStack's constructors.
		//***************************************************
		Stock *stack;

	public:
		// Prototype for the default constructor of StockStack.
		StockStack();

		// Prototype for the one parameter constructor of StockStack that takes a maximum stack size.
		StockStack(int max);

		// Prototype for the copy constructor of StockStack.
		StockStack(const StockStack& rhs);

		// Prototype for the Clear function of StockStack.
		void Clear();

		// Prototype for the Size function of StockStack.
		int Size();

		// Prototype for the MaxStorage function of StockStack.
		int MaxStorage();

		// Prototype for the Push function of StockStack.
		bool Push(Stock s);

		// Prototype for the Pop function of StockStack.
		bool Pop();

		// Prototype for the Top function of StockStack.
		bool Top(Stock& returnedStock);

		// Prototype for the member overload of the assignment operator for StockStack.
		StockStack& operator=(const StockStack& rhs);

		//****************************************************
		// Prototype for the non-member overload of the insertion operator.
		// Because it is a non-member overload, the prototype must be "friended" 
		// so that it can have access to the member variables of the StockStack class.
		//****************************************************
		friend std::ostream& operator<<(std::ostream& os, StockStack& rhs);

		// Prototype for the destructor of StockStack.
		~StockStack();
};

#endif