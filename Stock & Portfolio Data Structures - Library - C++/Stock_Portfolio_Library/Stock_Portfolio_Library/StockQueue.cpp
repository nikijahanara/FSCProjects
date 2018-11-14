//****************************************************
// File: StockQueue.cpp
//
// Purpose: To store the definitions of the functions and operator overloads of the StockQueue class.
//
// Written By: Niki Jahanara
//
// Compiler: Visual Studio Express 2013 (For Windows Desktop)
// 
//***************************************************

//***************************************************
// The StockQueue header file containing the StockQueue class's function prototypes
// must be included so that each function of the StockQueue class can be defined.
//***************************************************
#include "StockQueue.h"

//****************************************************
// Function: StockQueue
//
// Purpose: To be the default constructor of the StockQueue class.
//			It creates an empty queue by setting the length member variable to 0,
//			and setting front and rear, which are both StockQueueNode pointers, to NULL.
//
// Runtime: O(1)
//
//****************************************************
StockQueue::StockQueue()
{
	// An empty queue does not have any elements so the length member variable is set to 0.
	length = 0;

	//****************************************************
	// The front pointer must be set to NULL because an empty queue
	// does not have a first element for front to point to.
	//****************************************************
	front = NULL; 

	//****************************************************
	// The rear pointer must be set to NULL because an empty queue
	// does not have a last element for rear to point to.
	//****************************************************
	rear = NULL;
}

//****************************************************
// Function: StockQueue(const StockQueue& rhs)
//
// Purpose: To be the copy constructor of the StockQueue class.
//			A deep copy of the given instance of StockQueue's linked queue elements is done
//			in order to create a queue for the current instance of StockQueue.
//			The deep copy is performed through the use of the overloaded assignment operator.
//
// Runtime: O(n)
//
//****************************************************
StockQueue::StockQueue(const StockQueue& rhs)
{
	//****************************************************
	// The "this" pointer contains the address of the current instance.
	// By dereferencing the "this" pointer, the overloaded assignment operator can be used
	// to assign a deep copy of the given instance of StockQueue's queue elements
	// to be the queue elements of the current instance of StockQueue.
	//****************************************************
	*this = rhs;
}

//****************************************************
// Function: Clear
//
// Purpose: To empty the current instance of StockQueue's 
//			queue of all of its linked StockQueueNode elements.
//			It also deallocates the dynamic memory of every 
//			StockQueueNode element that is deleted in order to prevent a memory leak.
//
// Runtime: O(n)
//
//****************************************************
void StockQueue::Clear()
{
	//****************************************************
	// Declaring a local pointer instance of StockQueueNode that will
	// be used to deallocate the dynamic memory of every StockQueueNode
	// element in the current instance of StockQueue's queue.
	//****************************************************
	StockQueueNode *temp;

	//****************************************************
	// A while loop is used to visit each element of 
	// the current instance of StockQueue's queue.
	// The while loop terminates when front is equal to NULL because 
	// when front is equal to NULL, then there are no more elements 
	// in the current instance of StockQueue's queue to delete.
	//****************************************************
	while (front != NULL)
	{
		//****************************************************
		// The temp StockQueueNode pointer is assigned the 
		// address of the StockQueueNode that front is pointing to.
		//****************************************************
		temp = front;

		//****************************************************
		// The front pointer is assigned the address of the
		// next StockQueueNode in the queue to point to
		// so that during the loop's next iteration, 
		// the temp StockQueueNode pointer can be assigned the address
		// of the next StockQueueNode in the queue that must be deleted.
		//****************************************************
		front = front->next;

		//****************************************************
		// Calling delete on the temp StockQueueNode pointer so
		// that the StockQueueNode element that temp is pointing
		// to can have its dynamic memory deallocated and removed from the queue.
		//****************************************************
		delete temp;
	}

	//****************************************************
	// The rear pointer must be set to NULL after the queue is emptied
	// in order to prevent the rear pointer from becoming a dangling pointer.
	//****************************************************
	rear = NULL;

	//****************************************************
	// The length member variable of the current instance of StockQueue must 
	// be assigned the value 0 to reflect that there are no elements in the
	// current instance of StockQueue's queue after this method runs.
	//****************************************************
	length = 0;
}

//****************************************************
// Function: Size
//
// Purpose: To return the number of items in the current instance of StockQueue's queue.
//
// Runtime: O(1)
//
//****************************************************
int StockQueue::Size()
{
	//****************************************************
	// The length member variable is returned because it stores the number of 
	// elements that the current instance of StockQueue's queue has.
	//****************************************************
	return length;
}

//****************************************************
// Function: Enqueue
//
// Purpose: To add the given instance of Stock to the end of
//			the current instance of StockQueue's queue.
//			New queue elements must be added to the end of a queue 
//			because queues have a "first in, first out" (FIFO) structure.
//
// Runtime: O(1)
//
//****************************************************
void StockQueue::Enqueue(Stock s)
{
	//****************************************************
	// Declaring a local pointer instance of StockQueueNode
	// that will be used to add the given instance of Stock 
	// to the end of the current instance StockQueue's queue.
	//****************************************************
	StockQueueNode *temp;

	//****************************************************
	// Allocating dynamic memory for the new StockQueueNode that will be
	// added to the current instance of StockQueue's queue because the queue's
	// linked list implementation allocates dynamic memory for all of its elements.
	//****************************************************
	temp = new StockQueueNode;

	//****************************************************
	// Setting the stockData of the new StockQueueNode to
	// be the instance of Stock that was passed into the function.
	//****************************************************
	temp->stockData = s;

	//****************************************************
	// Because the new StockQueueNode is being added to the end
	// of the current instance of StockQueue's queue, 
	// its next pointer must be assigned the value NULL to
	// indiciate that it is the last element in the queue.
	//****************************************************
	temp->next = NULL;

	//****************************************************
	// If the rear pointer is equal to NULL, then the current instance of
	// StockQueue's queue is empty. The front pointer is assigned the 
	// address of the new StockQueueNode pointer to point to because
	// the new StockQueueNode is technically both the first and last element
	// of the queue until another Stock object is added to the queue.
	//****************************************************
	if (rear == NULL)
	{
		//****************************************************
		// Assigning front the address of the new StockQueueNode
		// that the local temp pointer is storing to point to
		// in order to make the new StockQueueNode the first element
		// of the current instance of StockQueue's queue.
		//****************************************************
		front = temp;
	}
	//****************************************************
	// If the rear pointer is not equal to NULL, then the current instance of
	// StockQueue's queue is not empty and the StockQueueNode the rear pointer is
	// pointing to can have its next pointer be updated to point to the
	// new StockQueueNode in order to make it the last element in the queue.
	//****************************************************
	else
	{
		//****************************************************
		// Because the new StockQueueNode is being added to the end
		// of the current instance of StockQueue's queue, 
		// the next pointer of the StockQueueNode that the 
		// rear pointer is currently pointing to is assigned
		// the address of the new StockQueueNode to point to so
		// that the new StockQueueNode can become the last element in the queue.
		//****************************************************
		rear->next = temp;
	}

	//****************************************************
	// Assigning rear the address of the new StockQueueNode
	// that the local temp pointer is storing to point to in order
	// to make the newly added StockQueueNode the last element
	// of the current instance of StockQueue's queue.
	//****************************************************
	rear = temp;

	//****************************************************
	// Incrementing the length member variable because a new element 
	// was added to the current instance of StockQueue's queue.
	//****************************************************
	length++;
}

//****************************************************
// Function: Dequeue
//
// Purpose: To remove the first element from the current instance of StockQueue's queue.
//			The instance of Stock that is removed from the front of the queue is 
//			also assigned to the returnedStock parameter of the function.
//			If it is able to assign the first element of the queue to the returnedStock parameter,
//			the value true is returned.
//			If it is unable to assign the first element of the queue to the returnedStock parameter,
//			it is because the queue is empty and the value false is returned.
//
// Runtime: O(1)
//
//****************************************************
bool StockQueue::Dequeue(Stock& returnedStock)
{
	// If front is equal to NULL, then the given instance of StockQueue has no elements and is empty.
	if (front == NULL)
	{
		// The value false is returned because it is not possible to remove an element from an empty queue.
		return false;
	}
	//****************************************************
	// If front is not equal to NULL, then the given instance of StockQueue's queue is not empty
	// and the first element in the queue can be removed and assigned to the returnedStock parameter.
	//****************************************************
	else
	{
		//****************************************************
		// Declaring a local pointer instance of StockQueueNode that is 
		// assigned the address that the front pointer member variable 
		// is storing so it can point to the first element of the queue.
		//****************************************************
		StockQueueNode *temp = front;

		//****************************************************
		// Assigning the stockData of the first element of the queue
		// (that the front pointer is pointing to) to the returnedStock parameter
		// so that it can become populated with data from the first element
		// of the queue before the first element is removed from the queue.
		//****************************************************
		returnedStock = front->stockData;

		//****************************************************
		// Because the first StockQueueNode element of the current
		// instance of StockQueue's queue is going to be deleted, front is assigned
		// the address of the next StockQueueNode in the queue to point to so that 
		// the next StockQueueNode in the queue becomes the first element 
		// of the queue when delete is called on the temp pointer.
		//****************************************************
		front = front->next;

		//****************************************************
		// If the front pointer is now equal to NULL, 
		// then the queue of the current instance of StockQueue is empty.
		//****************************************************
		if (front == NULL)
		{
			//****************************************************
			// The rear pointer must be set to NULL in order to 
			// prevent the rear pointer from becoming a dangling pointer.
			//****************************************************
			rear = NULL;
		}

		//****************************************************
		// Calling delete on the temp pointer because it is storing the address of the first
		// StockQueueNode in the current instance of StockQueue's queue that must be deleted.
		//****************************************************
		delete temp;

		//****************************************************
		// Decrementing the length member variable because the first element 
		// was removed from the current instance of StockQueue's queue.
		//****************************************************
		length--;

		//****************************************************
		// The value true is returned because the function was able
		// to successfully remove the first element of the queue.
		//****************************************************
		return true;
	}
}

//****************************************************
// Function: operator=
//
// Purpose: To overload the assignment operator for the StockQueue class.
//			By overloading the assignment operator, the given instance
//			of StockQueue's queue can be assigned as the queue of the 
//			current instance of StockQueue through a deep copy of the 
//			given instance of StockQueue's queue.
//			All data in the current instance of StockQueue's queue is also removed before
//			the deep copy of the given instance of StockQueue's queue is performed.
//
// Runtime: O(n)
//
//****************************************************
StockQueue& StockQueue::operator=(const StockQueue& rhs)
{
	//****************************************************
	// A call to the Clear function is made first because all data in the current 
	// instance of StockQueue's queue must first be removed, and the Clear function
	// is already defined to delete and deallocate the dynamic memory of all the
	// elements in the current instance of StockQueue's queue.
	//****************************************************
	Clear();

	//****************************************************
	// Declaring a local pointer instance of StockQueueNode that will be used
	// to visit each element of the given instance of StockQueue's queue.
	// The temp pointer is assigned the address the given instance of StockQueue's 
	// front pointer member variable is storing so it can initially point to
	// the first element of the given instance of StockQueue's queue.
	//****************************************************
	StockQueueNode *temp = rhs.front;

	//****************************************************
	// The while loop terminates when temp is equal to NULL
	// because the value NULL indicates that temp has reached
	// the end of the given instance of StockQueue's queue.
	//****************************************************
	while (temp != NULL)
	{
		//****************************************************
		// The stockData of every StockQueueNode that the temp pointer visits in
		// each iteration of the while loop is passed into a call to the Enqueue function.
		// This is because the Enqueue function is already defined to add an instance of
		// Stock to the end of the current instance of StockQueue's queue.
		// The Enqueue function can therefore add the stockData of every element in the 
		// given instance of StockQueue's queue to the current instance of StockQueue's queue via a deep copy.
		//****************************************************
		Enqueue(temp->stockData);

		//****************************************************
		// The temp pointer is assigned the address of the next StockQueueNode 
		// in the given instance of StockQueue's queue to point to so
		// that the stockData of the next StockQueueNode in the queue
		// can be passed into the Enqueue function during the next iteration of the loop.
		// This is repeated until temp is equal to NULL so that every element
		// of the given instance of StockQueue's queue can be added
		// to the end of the current instance of StockQueue's queue.
		//****************************************************
		temp = temp->next;
	}

	//****************************************************
	// The "this pointer" contains the address of the current instance.
	// It is returned so that the current instance of StockQueue can have
	// its queue updated to be the deep copy of the queue of the given instance of StockQueue.
	//****************************************************
	return *this;
}

//****************************************************
// Function: operator<<
//
// Purpose: To overload the insertion operator for the StockQueue class.
//			By overloading the insertion operator, the given instance
//			of StockQueue can have the stockData values of each StockQueueNode
//			element in its queue be printed to the given ostream.
//
// Runtime: O(n)
//
//****************************************************
std::ostream& operator<<(std::ostream& os, StockQueue& rhs)
{
	//****************************************************
	// Declaring a local pointer instance of StockQueueNode that will be used
	// to visit each element of the given instance of StockQueue's queue.
	// The temp pointer is assigned the address the given instance of StockQueue's 
	// front pointer member variable is storing so it can initially point to
	// the first element of the given instance of StockQueue's queue.
	//****************************************************
	StockQueue::StockQueueNode *temp = rhs.front;

	// If temp is equal to NULL, then the given instance of StockQueue has no elements and is empty.
	if (temp == NULL)
	{
		//****************************************************
		// A message is printed to given ostream to indicate that 
		// the given instance of StockQueue has no elements and is empty.
		//****************************************************
		os << "The Queue is empty." << std::endl;
	}
	//****************************************************
	// If temp is not equal to NULL, then the given instance of StockQueue
	// is not empty and can have the stockData values of each of the elements
	// in its queue be printed to the given ostream.
	//**************************************************** 
	else 
	{
		//****************************************************
		// The while loop terminates when temp is equal to NULL
		// because the value NULL indicates that temp has reached
		// the end of the given instance of StockQueue's queue.
		//****************************************************
		while (temp != NULL)
		{
			//****************************************************
			// The stockData values of the instance of StockQueueNode that
			// temp is pointing to is printed to the given ostream
			// because the insertion operator is also overloaded to
			// print each of the member variable values of an instance of Stock.
			//****************************************************
			os << temp->stockData << std::endl;

			//****************************************************
			// The temp pointer is assigned the address of the next StockQueueNode 
			// in the queue to point to so that the next StockQueueNode's 
			// stockData can have its member variable values be printed to the 
			// given ostream during the next iteration of the loop.
			//****************************************************
			temp = temp->next;
		}
	}

	// Returning the given ostream so that the given StockQueue's queue elements can be printed.
	return os;
}

//****************************************************
// Function: ~StockQueue
//
// Purpose: To be the destructor of the StockQueue class.
//			The destructor deletes and deallocates the dynamic memory of every 
//			StockQueueNode element in the current instance of StockQueue's queue 
//			in order to prevent a memory leak.
//
// Runtime: O(n)
//
//****************************************************
StockQueue::~StockQueue()
{
	//****************************************************
	// The Clear function is called in the destructor because
	// the Clear function is already defined to delete and
	// deallocate the dynamic memory of each StockQueueNode in the 
	// current instance of StockQueue's queue.
	//****************************************************
	Clear();
}