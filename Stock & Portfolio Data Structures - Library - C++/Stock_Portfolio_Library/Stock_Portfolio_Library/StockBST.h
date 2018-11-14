//****************************************************
// File: StockBST.h
//
// Purpose: To store the StockBST class's private member variables and private helper functions, 
//			the private StockBSTNode struct definition, and the prototypes of StockBST's public functions.
//
// Written By: Niki Jahanara
//
// Compiler: Visual Studio Express 2013 (For Windows Desktop)
// 
//***************************************************

// Preprocessor guards are added to to the StockBST header file so that multiple #includes can be allowed.
#ifndef STOCKBST_H
#define STOCKBST_H

#include<iostream>
// Must include the string header in order to be able to create variables with the string data type.
#include<string>

//***************************************************
// The Stock header file must be included so that an
// instance of Stock can be declared within the StockBST class.
//***************************************************
#include"Stock.h"

class StockBST {

	private:
		// The definition of the StockBSTNode struct is private within the definition of the StockBST class.
		struct StockBSTNode {

			//***************************************************
			// The data each StockBSTNode contains is an instance of Stock.
			// An instance of Stock must therefore be declared as a
			// member variable within the definition of the StockBSTNode struct.
			//***************************************************
			Stock stockData;

			//***************************************************
			// Declaring a pointer instance of StockBSTNode 
			// within the definition of the StockBSTNode struct
			// that will be used to point to the left StockBSTNode subtree
			// in the binary search tree of an instance of StockBST.
			//***************************************************
			StockBSTNode *left;

			//***************************************************
			// Declaring a pointer instance of StockBSTNode 
			// within the definition of the StockBSTNode struct
			// that will be used to point to the right StockBSTNode subtree
			// in the binary search tree of an instance of StockBST.
			//***************************************************
			StockBSTNode *right;
		};

		//***************************************************
		// Declaring a member variable that is a pointer instance of StockBSTNode 
		// that will be used to point to the first StockBSTNode element
		// in an instance of StockBST's binary search tree,
		// which is the root of the binary search tree.
		//***************************************************
		StockBSTNode *root;

		//***************************************************
		// Declaring an integer member variable that will be used to keep a count
		// of how many StockBSTNode elements are in an instance of StockBST's binary search tree.
		//***************************************************
		int length;

		// Prototype for the private helper overload of StockBST's Clear function.
		void Clear(StockBSTNode* &tree);

		// Prototype for the private helper overload of StockBST's Add function.
		void Add(StockBSTNode* &tree, Stock s);

		// Prototype for the private helper overload of StockBST's Preorder function.
		void Preorder(StockBSTNode *tree);
		// Prototype for the private helper overload of StockBST's Inorder function.
		void Inorder(StockBSTNode *tree);
		// Prototype for the private helper overload of StockBST's Postorder function.
		void Postorder(StockBSTNode *tree);

		// Prototype for the private helper overload of StockBST's GetShares function.
		bool GetShares(StockBSTNode *tree, std::string name, double& shares);

		// Prototype for the private helper Copy function for StockBST's assignment operator overload.
		void Copy(StockBSTNode* tree);

		// Prototype for the private helper Print function for StockBST's insertion operator overload.
		void Print(StockBSTNode* tree, std::ostream& os);

	public:
		// Prototype for the default constructor of StockBST.
		StockBST();

		// Prototype for the copy constructor of StockBST.
		StockBST(const StockBST& rhs);

		// Prototype for the Clear function of StockBST.
		void Clear();

		// Prototype for the Size function of StockBST.
		int Size();

		// Prototype for the Add function of StockBST.
		void Add(Stock s);

		// Prototype for the Preorder function of StockBST.
		void Preorder();
		// Prototype for the Inorder function of StockBST.
		void Inorder();
		// Prototype for the Postorder function of StockBST.
		void Postorder();

		// Prototype for the GetShares function of StockBST.
		bool GetShares(std::string name, double& shares);

		// Prototype for the member overload of the assignment operator for StockBST.
		StockBST& operator=(const StockBST& rhs);

		//****************************************************
		// Prototype for the non-member overload of the insertion operator.
		// Because it is a non-member overload, the prototype must be "friended" 
		// so that it can have access to the member variables of the StockBST class.
		//****************************************************
		friend std::ostream& operator<<(std::ostream& os, StockBST& rhs);

		// Prototype for the destructor of StockBST.
		~StockBST();
};

#endif