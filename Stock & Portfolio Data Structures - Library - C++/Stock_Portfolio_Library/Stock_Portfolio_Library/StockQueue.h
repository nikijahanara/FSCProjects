//****************************************************
// File: StockQueue.h
//
// Purpose: To store the StockQueue class's private member variables, the private StockQueueNode struct definition,
//			and the prototypes of StockQueue's public functions.
//
// Written By: Niki Jahanara
//
// Compiler: Visual Studio Express 2013 (For Windows Desktop)
// 
//***************************************************

// Preprocessor guards are added to to the StockQueue header file so that multiple #includes can be allowed.
#ifndef STOCKQUEUE_H
#define STOCKQUEUE_H

#include<iostream>
#include<string>

//***************************************************
// The Stock header file must be included so that an
// instance of Stock can be declared within the StockQueue class.
//***************************************************
#include "Stock.h"

class StockQueue {

	private:
		// The definition of the StockQueueNode struct is private within the definition of the StockQueue class.
		struct StockQueueNode
		{
			//***************************************************
			// The data each StockQueueNode contains is an instance of Stock.
			// An instance of Stock must therefore be declared as a
			// member variable within the definition of the StockQueueNode struct.
			//***************************************************
			Stock stockData;
			//***************************************************
			// Declaring a pointer instance of StockQueueNode 
			// within the definition of the StockQueueNode struct
			// that will be used to point to the next StockQueueNode
			// in an instance of StockQueue's queue.
			//***************************************************
			StockQueueNode *next;
		};

		//***************************************************
		// Declaring a member variable that is a pointer instance of StockQueueNode 
		// that will be used to point to the first StockQueueNode element in an instance of StockQueue's queue.
		//***************************************************
		StockQueueNode *front;

		//***************************************************
		// Declaring a member variable that is a pointer instance of StockQueueNode 
		// that will be used to point to the last StockQueueNode element in an instance of StockQueue's queue.
		//***************************************************
		StockQueueNode *rear;

		//***************************************************
		// Declaring an integer member variable that will be used to keep a count
		// of how many StockQueueNode elements are in an instance of StockQueue's queue.
		//***************************************************
		int length;

	public:
		// Prototype for the default constructor of StockQueue.
		StockQueue();

		// Prototype for the copy constructor of StockQueue.
		StockQueue(const StockQueue& rhs);

		// Prototype for the Clear function of StockQueue.
		void Clear();

		// Prototype for the Size function of StockQueue.
		int Size();

		// Prototype for the Enqueue function of StockQueue.
		void Enqueue(Stock s);

		// Prototype for the Dequeue function of StockQueue.
		bool Dequeue(Stock& returnedStock);

		// Prototype for the member overload of the assignment operator for StockQueue.
		StockQueue& operator=(const StockQueue& rhs);

		//****************************************************
		// Prototype for the non-member overload of the insertion operator.
		// Because it is a non-member overload, the prototype must be "friended" 
		// so that it can have access to the member variables of the StockQueue class.
		//****************************************************
		friend std::ostream& operator<<(std::ostream& os, StockQueue& rhs);

		// Prototype for the destructor of StockQueue.
		~StockQueue();
};

#endif