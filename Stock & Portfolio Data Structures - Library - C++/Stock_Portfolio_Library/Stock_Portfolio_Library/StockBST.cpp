//****************************************************
// File: StockBST.cpp
//
// Purpose: To store the definitions of the functions and operator overloads of the StockBST class.
//
// Written By: Niki Jahanara
//
// Compiler: Visual Studio Express 2013 (For Windows Desktop)
// 
//***************************************************

//***************************************************
// The StockBST header file containing the StockBST class's function prototypes
// must be included so that each function of the StockBST class can be defined.
//***************************************************
#include "StockBST.h"

//****************************************************
// Function: StockBST
//
// Purpose: To be the default constructor of the StockBST class.
//			It creates an empty binary search tree by setting the length member variable to 0,
//			and setting root, which is a StockBSTNode pointer to the first element of the
//			current instance of StockBST's binary search tree, to NULL.
//
// Runtime: O(1)
//
//****************************************************
StockBST::StockBST()
{
	//****************************************************
	// The root pointer must be set to NULL because an empty binary search tree
	// does not have a first element for root to point to.
	//****************************************************
	root = NULL;

	// An empty binary search tree does not have any elements so the length member variable is set to 0.
	length = 0;
}

//****************************************************
// Function: StockBST(const StockBST& rhs)
//
// Purpose: To be the copy constructor of the StockBST class.
//			A deep copy of the given instance of StockBST's binary search tree is done
//			in order to create a binary search tree for the current instance of StockBST
//			that has the same structure as the original binary search tree.
//			The deep copy is performed through the use of the overloaded assignment operator.
//
// Runtime: O(n)
//
//****************************************************
StockBST::StockBST(const StockBST& rhs)
{
	//****************************************************
	// The "this" pointer contains the address of the current instance.
	// By dereferencing the "this" pointer, the overloaded assignment operator can be used
	// to assign a deep copy of the given instance of StockBST's binary search tree elements
	// to be the binary search tree elements of the current instance of StockBST.
	//****************************************************
	*this = rhs;
}

//****************************************************
// Function: Clear
//
// Purpose: To empty the current instance of StockBST's 
//			binary search tree of all of its linked StockBSTNode elements.
//			It also deallocates the dynamic memory of every 
//			StockBSTNode element that is deleted in order to prevent a memory leak.
//			It also sets the root pointer member variable equal to NULL after
//			all the StockBSTNodes are deleted so that root does not become a dangling pointer.
//
// Runtime: O(n)
//
//****************************************************
void StockBST::Clear()
{
	//****************************************************
	// Passing the address stored in the root pointer member variable of the current
	// instance of StockBST into a private helper overload of the Clear function
	// so that it can delete and deallocate the dynamic memory of every 
	// StockBSTNode in the current instance of StockBST's binary search tree.
	//****************************************************
	Clear(root);

	//****************************************************
	// Setting the root pointer equal to NULL after the call to the
	// private helper overload of the Clear function ends so that root does not
	// become a dangling pointer after the binary search tree is cleared.
	//****************************************************
	root = NULL;
}

//****************************************************
// Function: Clear(StockBSTNode* &tree)
//
// Purpose: To be the private helper overload of the Clear function
//			that recursively empties the current instance of StockBST's 
//			binary search tree of all of its linked StockBSTNode elements.
//
// Runtime: O(n)
//
//****************************************************
void StockBST::Clear(StockBSTNode* &tree)
{
	//****************************************************
	// If tree, or the StockBSTNode pointer that was passed into the function's parameter,
	// is not NULL then the current instance of StockBST's binary search tree is not empty 
	// and can recursively have its binary search tree be cleared of all of its StockBSTNode elements.
	//****************************************************
	if (tree != NULL)
	{
		//****************************************************
		// A recursive call to the private helper overload of the Clear function
		// is made so that the left subtree of the current instance of StockBST's
		// binary search tree can have its StockBSTNode elements visited and then deleted.
		//****************************************************
		Clear(tree->left);

		//****************************************************
		// A recursive call to the private helper overload of the Clear function
		// is made so that the right subtree of the current instance of StockBST's
		// binary search tree can have its StockBSTNode elements visited and then deleted.
		//****************************************************
		Clear(tree->right);

		//****************************************************
		// Deleting and deallocating the dynamic memory of the current 
		// StockBSTNode that the private helper overload of the Clear function is visiting.
		//****************************************************
		delete tree;
	}

	//****************************************************
	// The length member variable of the current instance of StockBST must 
	// be assigned the value 0 to reflect that there are no elements in the
	// current instance of StockBST's binary search tree after this method runs.
	//****************************************************
	length = 0;
}

//****************************************************
// Function: Size
//
// Purpose: To return the number of elements in the current instance of StockBST's binary search tree.
//
// Runtime: O(1)
//
//****************************************************
int StockBST::Size()
{
	//****************************************************
	// The length member variable is returned because it stores the number of 
	// elements that the current instance of StockBST's binary search tree has.
	//****************************************************
	return length;
}

//****************************************************
// Function: Add(Stock s)
//
// Purpose: To add a Stock object to the current instance of StockBST's binary search tree. 
//			The Stock object is added to the binary search tree according to
//			the binary search tree's search key (which is Stock's stockName member variable).
//
// Runtime: O(log n)
//
//****************************************************
void StockBST::Add(Stock s)
{
	//****************************************************
	// Passing the address stored in the root pointer member variable of the current instance
	// of StockBST and the given Stock object that is to be added to the binary search tree
	// into a private helper overload of the Add function that recursively
	// searches for the appropriate place to add to the given Stock object to
	// the current instance of StockBST's binary search tree.
	//****************************************************
	Add(root, s);
}

//****************************************************
// Function: Add(StockBSTNode* &tree, Stock s)
//
// Purpose: To be the private helper overload of the Add function
//			that recursively searches for the appropriate place to add the
//			given Stock object to the current instance of StockBST's binary search tree
//			before adding the given Stock object to current instance of StockBST's binary search tree.
//
// Runtime: O(log n)
//
//****************************************************
void StockBST::Add(StockBSTNode* &tree, Stock s)
{
	//****************************************************
	// If the tree StockBSTNode pointer is equal to NULL,
	// then the insertion place for the given Stock object has been found.
	//****************************************************
	if (tree == NULL)
	{
		//****************************************************
		// Allocating dynamic memory for the Stock object that is to be added to the current
		// instance of StockBST's binary search tree by calling new to create a new StockBSTNode.
		//****************************************************
		tree = new StockBSTNode;

		//****************************************************
		// Because the Stock object that is being added to to the current instance of StockBST's binary search tree
		// is a leaf node and therefore has no child nodes to point to, the right pointer of the new StockBSTNode is set to NULL.
		//****************************************************
		tree->right = NULL;

		//****************************************************
		// Because the Stock object that is being added to to the current instance of StockBST's binary search tree
		// is a leaf node and therefore has no chil nodes to point to, the left pointer of the new StockBSTNode is set to NULL.
		//****************************************************
		tree->left = NULL;

		//****************************************************
		// Setting the stockData of the new StockBSTNode to
		// be the instance of Stock that was passed into the function.
		//****************************************************
		tree->stockData = s;

		//****************************************************
		// Incrementing the length member variable because a new element 
		// was added to the current instance of StockBST's binary search tree.
		//****************************************************
		length++;
	}
	//****************************************************
	// If the given Stock object's name value is less-than the name value of the
	// Stock object that the tree StockBSTNode pointer is currently pointing to, 
	// then the private helper overload of the Add function is recursively called 
	// so that the left subtree of the binary search tree can be checked for the
	// appropriate insertion place of the given Stock object.
	//****************************************************
	else if (s < tree->stockData)
	{
		//****************************************************
		// Passing the left StockBSTNode child of the StockBSTNode that the tree pointer 
		// is currently pointing to and the given Stock object into a recursive call to the 
		// private helper overload of the Add function so that the left subtree of the current 
		// instance of StockBST can be recursively searched for the
		// correct insertion place of the given Stock object.
		//****************************************************
		Add(tree->left, s);
	}
	//****************************************************
	// If the given Stock object's name value is not less-than the name value of the
	// Stock object that the tree StockBSTNode pointer is currently pointing to, 
	// then the private helper overload of the Add function is recursively called 
	// so that the right subtree of the binary search tree can be checked for the
	// appropriate insertion place of the given Stock object.
	//****************************************************
	else
	{
		//****************************************************
		// Passing the right StockBSTNode child of the StockBSTNode that the tree pointer 
		// is currently pointing to and the given Stock object into a recursive call to the 
		// private helper overload of the Add function so that the right subtree of the current 
		// instance of StockBST can be recursively searched for the
		// correct insertion place of the given Stock object.
		//****************************************************
		Add(tree->right, s);
	}
}

//****************************************************
// Function: Preorder
//
// Purpose: To print only the name of all the Stock objects in 
//			the current instance of StockBST's binary search tree
//			on the console through a preorder traversal of the binary search tree. 
//
// Runtime: O(n)
//
//****************************************************
void StockBST::Preorder()
{
	//****************************************************
	// If root is equal to NULL, then the current instance of StockBST's binary search tree
	// is empty and therefore cannot have the name of its Stock objects printed to the console.
	// A message indicating that the StockBST's binary search tree is empty is printed instead.
	//****************************************************
	if (root == NULL)
	{
		std::cout << "The StockBST is empty." << std::endl;
	}
	//****************************************************
	// If the above condition fails, then the current instance of StockBST's binary search tree
	// is not empty and can have the name of its Stock objects printed to the console.
	//****************************************************
	else
	{
		//****************************************************
		// Passing the address stored in the root pointer member variable of the current
		// instance of StockBST into a private helper overload of the Preorder function
		// that recursively does a preorder traversal of the binary search tree.
		//****************************************************
		Preorder(root);
	}
}

//****************************************************
// Function: Preorder(StockBSTNode *tree)
//
// Purpose: To be the private helper overload of the Preorder function
//			that prints only the name of all the Stock objects in 
//			the current instance of StockBST's binary search tree on the console
//			by using a recursive preorder traversal of the binary search tree. 
//
// Runtime: O(n)
//
//****************************************************
void StockBST::Preorder(StockBSTNode *tree)
{
	//****************************************************
	// If tree, or the StockBSTNode pointer that was passed into the function's parameter,
	// is not NULL then the current instance of StockBST's binary search tree is not empty
	// and can have the names of its Stock elements be printed onto the console.
	//****************************************************
	if (tree != NULL)
	{
		//****************************************************
		// Because a preorder traversal of a binary search tree processes
		// the current node before the left and then right subtrees of a binary search tree,
		// the name of the Stock object that the tree StockBSTNode pointer is visiting is printed to the console
		// before the recursive calls to the private helper overloads of the Preorder function are made.
		//****************************************************
		std::cout << tree->stockData.getStockName() << " ";

		//****************************************************
		// Passing the left StockBSTNode child of the StockBSTNode that the tree pointer is currently pointing to
		// into a recursive call to the private helper overload of the Preorder function so that the 
		// left subtree of the current instance of StockBST can be recursively traversed in a preorder format.
		//****************************************************
		Preorder(tree->left);

		//****************************************************
		// Passing the right StockBSTNode child of the StockBSTNode that the tree pointer is currently pointing to
		// into a recursive call to the private helper overload of the Preorder function so that the 
		// right subtree of the current instance of StockBST can be recursively traversed in a preorder format.
		//****************************************************
		Preorder(tree->right);
	}
}

//****************************************************
// Function: Inorder
//
// Purpose: To print only the name of all the Stock objects in 
//			the current instance of StockBST's binary search tree
//			on the console through an inorder traversal of the binary search tree. 
//
// Runtime: O(n)
//
//****************************************************
void StockBST::Inorder()
{
	//****************************************************
	// If root is equal to NULL, then the current instance of StockBST's binary search tree
	// is empty and therefore cannot have the name of its Stock objects printed to the console.
	// A message indicating that the StockBST's binary search tree is empty is printed instead.
	//****************************************************
	if (root == NULL)
	{
		std::cout << "The StockBST is empty." << std::endl;
	}
	//****************************************************
	// If the above condition fails, then the current instance of StockBST's binary search tree
	// is not empty and can have the name of its Stock objects printed to the console.
	//****************************************************
	else
	{
		//****************************************************
		// Passing the address stored in the root pointer member variable of the current
		// instance of StockBST into a private helper overload of the Inorder function
		// that recursively does an inorder traversal of the binary search tree.
		//****************************************************
		Inorder(root);
	}
}

//****************************************************
// Function: Inorder(StockBSTNode *tree)
//
// Purpose: To be the private helper overload of the Inorder function
//			that prints only the name of all the Stock objects in 
//			the current instance of StockBST's binary search tree on the console
//			by using a recursive inorder traversal of the binary search tree. 
//
// Runtime: O(n)
//
//****************************************************
void StockBST::Inorder(StockBSTNode *tree)
{
	//****************************************************
	// If tree, or the StockBSTNode pointer that was passed into the function's parameter,
	// is not NULL then the current instance of StockBST's binary search tree is not empty
	// and can have the names of its Stock elements be printed onto the console.
	//****************************************************
	if (tree != NULL)
	{
		//****************************************************
		// Passing the left StockBSTNode child of the StockBSTNode that the tree pointer is currently pointing to
		// into a recursive call to the private helper overload of the Inorder function so that the 
		// left subtree of the current instance of StockBST can be recursively traversed in an inorder format.
		//****************************************************
		Inorder(tree->left);

		//****************************************************
		// Because an inorder traversal of a binary search tree processees the current node
		// after the left subtree but before the right subtree, the name of the Stock object that 
		// the tree pointer is visiting is printed to the console inbetween the 
		// two recursive Inorder calls that traverse the left and right subtrees.
		//****************************************************
		std::cout << tree->stockData.getStockName() << " ";

		//****************************************************
		// Passing the right StockBSTNode child of the StockBSTNode that the tree pointer is currently pointing to
		// into a recursive call to the private helper overload of the Inorder function so that the 
		// right subtree of the current instance of StockBST can be recursively traversed in an inorder format.
		//****************************************************
		Inorder(tree->right);
	}
}

//****************************************************
// Function: Postorder
//
// Purpose: To print only the name of all the Stock objects in 
//			the current instance of StockBST's binary search tree
//			on the console through a postorder traversal of the binary search tree. 
//
// Runtime: O(n)
//
//****************************************************
void StockBST::Postorder()
{
	//****************************************************
	// If root is equal to NULL, then the current instance of StockBST's binary search tree
	// is empty and therefore cannot have the name of its Stock objects printed to the console.
	// A message indicating that the StockBST's binary search tree is empty is printed instead.
	//****************************************************
	if (root == NULL)
	{
		std::cout << "The StockBST is empty." << std::endl;
	}
	//****************************************************
	// If the above condition fails, then the current instance of StockBST's binary search tree
	// is not empty and can have the name of its Stock objects printed to the console.
	//****************************************************
	else
	{
		//****************************************************
		// Passing the address stored in the root pointer member variable of the current
		// instance of StockBST into a private helper overload of the Postorder function
		// that recursively does an postorder traversal of the binary search tree.
		//****************************************************
		Postorder(root);
	}
}

//****************************************************
// Function: Postorder(StockBSTNode *tree)
//
// Purpose: To be the private helper overload of the Postorder function
//			that prints only the name of all the Stock objects in 
//			the current instance of StockBST's binary search tree on the console
//			by using a recursive postorder traversal of the binary search tree. 
//
// Runtime: O(n)
//
//****************************************************
void StockBST::Postorder(StockBSTNode *tree)
{
	//****************************************************
	// If tree, or the StockBSTNode pointer that was passed into the function's parameter,
	// is not NULL then the current instance of StockBST's binary search tree is not empty
	// and can have the names of its Stock elements be printed onto the console.
	//****************************************************
	if (tree != NULL)
	{
		//****************************************************
		// Passing the left StockBSTNode child of the StockBSTNode that the tree pointer is currently pointing to
		// into a recursive call to the private helper overload of the Postorder function so that the 
		// left subtree of the current instance of StockBST can be recursively traversed in a postorder format.
		//****************************************************
		Postorder(tree->left);

		//****************************************************
		// Passing the right StockBSTNode child of the StockBSTNode that the tree pointer is currently pointing to
		// into a recursive call to the private helper overload of the Postorder function so that the 
		// right subtree of the current instance of StockBST can be recursively traversed in a postorder format.
		//****************************************************
		Postorder(tree->right);

		//****************************************************
		// Because a postorder traversal of a binary search tree
		// processees the current node after the left and the right subtrees,
		// the name of the Stock object that the tree pointer is visiting is printed to the
		// console after the two recursive Postorder function calls that traverse the left and right subtrees.
		//****************************************************
		std::cout << tree->stockData.getStockName() << " ";
	}
}

//****************************************************
// Function: GetShares(string name, double& shares)
//
// Purpose: To return the shares of the Stock object with the given name 
//			through the shares reference parameter.
//			If the Stock object with the given name is found within the 
//			current instance of StockBST's binary search tree, 
//			then the value true is returned. Otherwise, the value false is returned.
//
// Runtime: O(log n)
//
//****************************************************
bool StockBST::GetShares(std::string name, double& shares)
{
	//****************************************************
	// Passing the address stored in the root pointer member variable of the current
	// instance of StockBST, the given name, and the shares reference parameter
	// into the private helper overload of the GetShares function
	// that recursively traverses the binary search tree to find 
	// if a Stock object with the given name exists in the binary search tree.
	// The true or false value returned by the private helper overload of
	// the GetShares function is also returned by the GetShares function.
	//****************************************************
	return GetShares(root, name, shares);
}

//****************************************************
// Function: GetShares(StockBSTNode *tree, string name, double& shares)
//
// Purpose: To be the private helper overload of the GetShares function
//			that recursively searches the current instance of StockBST's
//			binary search tree for the Stock object that has the given name.
//			If the Stock object with the given name is found, the value true 
//			is returned and the shares reference parameter is assigned the 
//			shares value of the Stock object that was found.
//			Otherwise, the value false is returned.
//
// Runtime: O(log n)
//
//****************************************************
bool StockBST::GetShares(StockBSTNode *tree, std::string name, double& shares)
{
	//****************************************************
	// If tree is equal to NULL, then either the current instance of StockBST's 
	// binary search tree is empty or the bottom of the binary search tree has been
	// reached without finding the Stock object with the given name, so the value false is returned.
	//****************************************************
	if (tree == NULL)
	{
		//****************************************************
		// Returning the value false to indicate that a Stock object with the given name
		// was not found within the current instance of StockBST's binary search tree.
		//****************************************************
		return false;
	}
	//****************************************************
	// If the given name's value is less-than the name value of the
	// Stock object that the tree StockBSTNode pointer is currently pointing to, 
	// then the private helper overload of the GetShares function is recursively
	// called so that the left subtree of the binary search tree can be checked for the
	// for the existence of a Stock object with the given name.
	//****************************************************
	else if (name < tree->stockData.getStockName())
	{
		//****************************************************
		// Passing the left StockBSTNode child of the StockBSTNode that the tree StockBSTNode pointer is currently pointing to
		// (as well as the given name and shares reference parameter) into a recursive call to 
		// the private helper overload of the GetShares function so that the left subtree of
		// the current instance of StockBST can be recursively searched for a Stock object with the given name.
		//****************************************************
		GetShares(tree->left, name, shares);
	}
	//****************************************************
	// If the given name's value is greater-than the name value of the
	// Stock object that the tree StockBSTNode pointer is currently pointing to, 
	// then the private helper overload of the GetShares function is recursively called
	// so that the right subtree of the binary search tree can be checked for the
	// for the existence of a Stock object with the given name.
	//****************************************************
	else if (name > tree->stockData.getStockName())
	{
		//****************************************************
		// Passing the right StockBSTNode child of the StockBSTNode that the tree StockBSTNode pointer is currently pointing to
		// (as well as the given name and shares reference parameter) into a recursive call to 
		// the private helper overload of the GetShares function so that the right subtree of
		// the current instance of StockBST can be recursively searched for a Stock object with the given name.
		//****************************************************
		GetShares(tree->right, name, shares);
	}
	//****************************************************
	// If the given name is neither less-than nor greater than the name value of the
	// Stock object that the tree StockBSTNode pointer is currently pointing to, then the target Stock has been found. 
	//****************************************************
	else
	{
		// Setting the shares reference parameter equal to the shares value of the target Stock object.
		shares = tree->stockData.getStockShares();

		//****************************************************
		// Returning true to indicate that a Stock object with the given name
		// has been found within the current instance of StockBST's binary search tree.
		//****************************************************
		return true;
	} 
}

//****************************************************
// Function: operator=
//
// Purpose: To overload the assignment operator for the StockBST class.
//			By overloading the assignment operator, the given instance
//			of StockBST's binary search tree can be assigned as the 
//			binary search tree of the current instance of StockBST through
//			a deep copy of the given instance of StockBST's binary search tree.
//			All data in the current instance of StockBST's binary search tree is also
//			removed before the deep copy of the given instance of StockBST's elements is performed.
//
// Runtime: O(n)
//
//****************************************************
StockBST& StockBST::operator=(const StockBST& rhs)
{
	//****************************************************
	// A call to the Clear function is made first because all data in the current 
	// instance of StockBST's binary search tree must first be removed, and the Clear function
	// is already defined to delete and deallocate the dynamic memory of all the
	// elements in the current instance of StockBST's binary search tree.
	//****************************************************
	Clear();

	//****************************************************
	// Passing the address stored in the root pointer member variable
	// of the given instance of StockBST into a private helper Copy function
	// that recursively performs a deep copy on the StockBSTNodes in 
	// the given instance of StockBST's binary search tree.
	//****************************************************
	Copy(rhs.root);

	//****************************************************
	// The "this pointer" contains the address of the current instance.
	// It is returned so that the current instance of StockBST can have
	// its binary search tree updated to be the deep copy of the
	// binary search tree of the given instance of StockBST.
	//****************************************************
	return *this;
}

//****************************************************
// Function: Copy(StockBSTNode* tree)
//
// Purpose: To be a private helper function that recursively 
//			performs a deep copy on the StockBSTNodes in the
//			given instance of StockBST's binary search tree.
//			The deep copy that is performed also has the same
//			structure of the binary search tree that was copied.
//
// Runtime: O(n)
//
//****************************************************
void StockBST::Copy(StockBSTNode* tree)
{
	//****************************************************
	// If tree, or the StockBSTNode pointer that was passed into the function's parameter,
	// is not NULL then the given instance of StockBST's binary search tree is not empty
	// and can have a deep copy of its binary search tree elements be performed.
	//****************************************************
	if (tree != NULL)
	{
		//****************************************************
		// The stockData of every StockBSTNode that is visited is passed into a call to the Add function.
		// This is because the Add function is already defined to add an instance of
		// Stock to its appropriate place within an instance of StockBST's binary search tree.
		// The Add function can therefore add the stockData of every element in the 
		// given instance of StockBST's binary search tree to the current instance 
		// of StockBST's binary search tree via a deep copy.
		// The Add function is also called before the recursive Copy function calls that traverse the
		// left and then right subtrees because each Stock object is added in a preorder format
		// so that the structure of the copy is exactly the same as the original binary search tree.
		//****************************************************
		Add(tree->stockData);

		//****************************************************
		// Passing the left StockBSTNode child of the StockBSTNode that the tree pointer is currently pointing to
		// into a recursive call to the private helper Copy function so that the StockBSTNodes of the 
		// left subtree of the given instance of StockBST can be added to the binary search tree of the current instance of StockBST.
		//****************************************************
		Copy(tree->left);

		//****************************************************
		// Passing the right StockBSTNode child of the StockBSTNode that the tree pointer is currently pointing to
		// into a recursive call to the private helper Copy function so that the StockBSTNodes of the 
		// right subtree of the given instance of StockBST can be added to the binary search tree of the current instance of StockBST.
		//****************************************************
		Copy(tree->right);
	}
}

//****************************************************
// Function: operator<<
//
// Purpose: To overload the insertion operator for the StockBST class.
//			By overloading the insertion operator, the given instance
//			of StockBST can have the stockData values of each StockBSTNode
//			element in its binary search tree be printed to the given ostream.
//			The elements of the given instance of StockBST will also be printed
//			to the given ostream in an Inorder format.
//
// Runtime: O(n)
//
//****************************************************
std::ostream& operator<<(std::ostream& os, StockBST& rhs)
{
	//****************************************************
	// If root is equal to NULL, then the given instance of StockBST's binary search tree
	// is empty and therefore cannot have its Stock objects printed to the console.
	// A message indicating that the StockBST's binary search tree is empty is printed instead.
	//****************************************************
	if (rhs.root == NULL)
	{
		os << "The StockBST is empty." << std::endl;
	}
	//****************************************************
	// If the above condition fails, then the given instance of StockBST's binary search tree
	// is not empty and can have the name of its Stock objects printed to the console.
	//****************************************************
	else
	{
		//****************************************************
		// Passing the address stored in the root pointer member variable of the given
		// instance of StockBST into a private helper Print function call that will
		// recursively print the values of each Stock object in the binary search tree in an Inorder format.
		//****************************************************
		rhs.Print(rhs.root, os);
	}

	// Returning the given ostream so that the given StockBST's binary search tree elements can be printed.
	return os;
}

//****************************************************
// Function: Print(StockBSTNode* tree, ostream& os)
//
// Purpose: To be a private helper function that recursively prints 
//			each Stock object's values in the given instance of StockBST's 
//			binary search tree in an Inorder format.
//
// Runtime: O(n)
//
//****************************************************
void StockBST::Print(StockBSTNode* tree, std::ostream& os)
{
	//****************************************************
	// If tree, or the StockBSTNode pointer that was passed into the function's parameter,
	// is not NULL then the given instance of StockBST's binary search tree is not empty
	// and can have the values of its Stock objects be printed onto the console.
	//****************************************************
	if (tree != NULL)
	{
		//****************************************************
		// Passing the left StockBSTNode child of the StockBSTNode that the tree pointer is currently pointing
		// and the given ostream into a recursive call to the private helper Print function so that the 
		// left subtree of the current instance of StockBST can be traversed in an inorder format.
		//****************************************************
		Print(tree->left, os);

		//****************************************************
		// Because an inorder traversal of a binary search tree processees the current node
		// after the left subtree but before the right subtree, the Stock object that 
		// the tree pointer is visiting is printed to the console inbetween the 
		// two recursive Print calls that traverse the left and right subtrees.
		//****************************************************
		os << tree->stockData << std::endl;

		//****************************************************
		// Passing the right StockBSTNode child of the StockBSTNode that the tree pointer is currently pointing
		// and the given ostream into a recursive call to the private helper Print function so that the 
		// right subtree of the current instance of StockBST can be traversed in an inorder format.
		//****************************************************
		Print(tree->right, os);
	}
}

//****************************************************
// Function: ~StockBST()
//
// Purpose: To be the destructor of the StockBST class.
//			The destructor deletes and deallocates the dynamic memory of every 
//			StockBSTNode element in the current instance of StockBST's
//			binary search tree in order to prevent a memory leak.
//
// Runtime: O(n)
//
//****************************************************
StockBST::~StockBST()
{
	//****************************************************
	// The Clear function is called in the destructor because
	// the Clear function is already defined to recursively delete
	// and deallocate the dynamic memory of each StockBSTNode in 
	// the current instance of StockBST's binary search tree.
	//****************************************************
	Clear();
}