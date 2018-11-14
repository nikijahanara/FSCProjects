package Jahanara.bcs345.purchases.business;

import java.io.PrintStream;
import java.util.Scanner;
/**
 *  The PurchaseCollection class contains the definitions for its default constructor, GetCustomer/SetCustomer methods,
 *  getPurchases, GetMaxPurchase, GetByIndex, Report, Write, Read, GetJSON, and overridden toString methods.
 *	The PurchaseCollection class also reuses code by calling the Read, Write, GetJSON and toString methods 
 * 	of the Purchase and Customer classes within it's own Read, Write, GetJSON and overridden toString methods. 
 * 	The Purchase class's Get methods are also called in PurchaseCollection's GetMaxPurchase and Report methods.
 *  
 * @author Niki Jahanara
 * @version 1.0
 * @since 12/8/2016
 */
public class PurchaseCollection {
	
	// Declaring the private member variables of PurchaseCollection.
	private Customer customer;
	private Purchase[] purchase;
	
	/**
	 * This method is the default constructor for the PurchaseCollection class.
	 */
	public PurchaseCollection()
	{
		// Calling new for the instance of Customer.
		customer = new Customer();
		//********************************************************************
		// Calling new for the instance of the Purchase array.
		// The size of Purchase's array is initialized as any integer value due to how
		// the array's true size is read in and the purchase array is reassigned in the Read method of this class.
		//********************************************************************
		purchase = new Purchase[2];
		for(int i = 0; i < purchase.length; i++)
		{
			purchase[i] = new Purchase();
		}
	}
	
	/**
	 * The SetCustomer method assigns the values of the member variables of 
	 * the instance of Customer passed into it as the value for the member variables of the Customer instance customer.
	 * @param newCustomer The new values for the Customer member variables.
	 */
	public void SetCustomer(Customer newCustomer) { customer = newCustomer; }
	/**
	 * The GetCustomer method returns the values of Customer's member variables.
	 * @return customer The instance of Customer containing the values of Customer's member variables.
	 */
	public Customer GetCustomer() { return customer; }
	
	/**
	 * The GetMaxPurchase method multiplies each index of the purchase array's product quantity by it's product price
	 * and determines which index in the purchase array has the highest calculated cost in order to
	 * return that instance of product. If the purchase array is empty, however, GetMaxPurchase returns null.
	 * @return null if the purchase array is empty, or the instance of purchase with
	 * the highest calculated cost if the array is not empty.
	 */
	public Purchase GetMaxPurchase()
	{	
		// Initializing index to 0.
		int index = 0;
		
		//*************************************************************************
		// If the value of the purchase array's first index, 0, is equal to null
		// the the purchase array is empty. Therefore, the method will return null.
		//*************************************************************************
		if(purchase[index] == null)
		{ 
			return null;
		}
		//****************************************************************
		// If the first index of purchase array is not equal to null, then the
		// purchase array is not empty and the index with the highest cost can be calculated.
		//****************************************************************
		else
		{
			//*****************************************************************************
			// Initializing the max variable equal to the calculated cost of the array's first index
			// so that the if condition within the for loop can compare the calculated cost of the other indexes
			// of purchase to it in order to determine which index has the highest calculated cost.
			//*****************************************************************************
			double max = purchase[index].getQuantity() * purchase[index].getProduct().getPrice();
		
			// A for loop is used so that the cost of every index of purchase can be evaluated.
			for(int i = 0; i < purchase.length; ++i)
			{
				//********************************************************************
				// If the calculated cost of purchase[i] is greater than max, then max and index
				// are assigned the higher cost and the value of i, respectively. This check iterates
				// until every cost of purchase array's indexes are calculated and compared to max.
				//********************************************************************
				if (purchase[i].getQuantity() * purchase[i].getProduct().getPrice() > max)
				{
					// Max is assigned the calculated cost of purchase[i] if it is greater than max's previous value.
					max = purchase[i].getQuantity() * purchase[i].getProduct().getPrice();
					// Index is set to the value of the i in purchase[i] if the index's cost is calculated to be higher than max.
					index = i;
				}
			}
			// Returns the instance in the array that has the highest calculated cost.
			return purchase[index];
		}	
	}
	
	/**
	 * The GetByIndex method returns the purchase at the given index, which is the index that is passed
	 * into the method's parameter. If the index passed in is a value that either exceeds or is less than
	 * the valid indexes of the purchase array, then an ArrayIndexOutOfBoundsException is generated and thrown.
	 * If the purchase array index is null, however, then the purchase array is empty and a
	 * NullPointerException is generated and thrown by the method in order to alert the user
	 * to the fact that the purchase array is empty.
	 * @param index The value of the array index that is passed into the method.
	 * @return The purchase at the given index.
	 * @throws ArrayIndexOutOfBoundsException if the index passed into the method either exceeds or
	 * is less than the valid indexes of the purchase array.
	 * @throws NullPointerException if the array is null.
	 */
	public Purchase GetByIndex(int index) throws ArrayIndexOutOfBoundsException, NullPointerException
	{
		//**************************************************************
		// The if statement checks if the index passed into the method's parameter
		// is greater than or equal to 0, which is always the first index of any array, and if
		// it is less than purchase.length, which is necessary since purchase.length
		// is one number higher than the actual range of the purchase indexes.
		//**************************************************************
		if ((0 <= index) && (index < purchase.length))
		{
			//*******************************************************************
			// If the index's value is null within the purchase array, then the purchase array is empty and
			// a NullPointerException will be thrown to alert the user that the purchase array is null.
			//*******************************************************************
			if (purchase[index] == null)
			{
				// Creating a new instance of NullPointerException and throwing it.
				throw new NullPointerException();
			}
			// If the value of the index is not null, then the method returns the purchase at the given index.
			else
			{
				// Returning the purchase at the given index.
				return purchase[index];
			}
		}
		//*********************************************************
		// If the first if statement fails, then the index passed into the method
		// is an invalid index. Therefore, an ArrayIndexOutOfBounds exception must be thrown.
		//*********************************************************
		else
		{
			// Creating a new instance of ArrayIndexOutOfBoundsException and throwing it.
			throw new ArrayIndexOutOfBoundsException();
		}
	}
	
	/**
	 * The Read method is passed an instance of Scanner in order to assign the values 
	 * it reads on each line of the file to the instance of customer and the purchase array.
	 * The instance of Scanner is first passed into the Read method of the Customer class in order for
	 * the customer values to be read in and assigned to it's member variables.
	 * Before the instance of scanner is passed into the Read method of  the Purchase class, however, 
	 * the PurchaseCount is read in and is used to reassign the purchase array to a new array of the size given in the file.
	 * The instance of Scanner is then passed into Purchase's Read method inside of a for loop in order to assign 
	 * the purchase data in the file to the member variables of each index within the reassigned purchase array.
	 * @param s The instance of Scanner.
	 */
	public void Read(Scanner s)
	{
		//*******************************************************
		// Because the PurchaseCollection input file has customer data listed first,
		// the instance of Scanner is first passed into the the instance of Customer
		// in order to assign values to the Customer member variables.
		//*******************************************************
		customer.Read(s);
		// Reading in the value of PurchaseCount in the file.
		int PurchaseCount = s.nextInt();
		s.nextLine();
		//************************************************************
		// Reassigning the purchase array so that it's size is equal to
		// the value of PurchaseCount that was read in from the file.
		//************************************************************
		purchase = new Purchase[PurchaseCount];
		
		// The for loop iterates until every index of the purchase array's member variables are assigned values.
		for(int i = 0; i < purchase.length; i++)
		{
			// Calling new on every index of the purchase array because it is an array of objects.
			purchase[i] = new Purchase();
			//*****************************************************
			// Calling Purchase's Read method and passing in the instance of Scanner into it in order
			// to assign purchase data in the file to each index of the purchase array's member variables.
			//*****************************************************
			purchase[i].Read(s);
		}
	}
	
	/**
	 * The Write method prints the values of the PurchaseCollection class's member variables to
	 * a file by passing an instance of PrintStream into the method's parameter.
	 * The method prints the values of the instance of the Customer class's member variables to the
	 * file by passing the instance of PrintStream into a call of Customer's Write method.
	 * Next, the method prints the length of the purchase array to the file.
	 * After that, a for loop is used to pass the instance of PrintStream into a call of
	 * Write for every index of the purchase array so that 
	 * the purchase array's member variable values are also printed to the file.
	 * @param ps The instance of PrintStream.
	 */
	public void Write(PrintStream ps)
	{
		//******************************************************************
		// Passing in the instance of PrintStream to a call of Customer's Write method so that the values
		// assigned to the member variables of the instance of customer are printed to the file.
		//******************************************************************
		customer.Write(ps);
		// Printing the length of the purchase array to the file.
		ps.println(purchase.length);
		
		// The for loop iterates until every index of the purchase array's member variable values are printed to the file.
		for(int i = 0; i < purchase.length; ++i)
		{
			//***************************************************************************
			// Calling Purchase's Write method for each index of the purchase array so that
			// the values of the member variables for each element in the array is printed to the file.
			//***************************************************************************
			purchase[i].Write(ps);
		}
	}
	
	/**
	 * The Report method outputs a formatted purchase report to the console.
	 * The Report method prints each product's description, price and quantity by
	 * calling the Get Methods of the Purchase class. The Report method also prints each
	 * purchase's total cost by multiplying the price and the quantity of each product together.
	 * A count of the total quantity of items in the report is also kept and printed to the console.
	 * The total cost of the entire purchase is also calculated and output in the report as well.
	 * @param ps The instance of PrintStream.
	 */
	public void Report(PrintStream ps)
	{
				// Formatting the first two lines of the report that will be written to the console.
				ps.printf("Purchase Report\n");
				ps.printf("---------------\n");
				
				//*********************************************************
				// The first three lines of information about the customer's
				// name and address must be written to the console before the for loop.
				// This is done through a call to the Customer instance's toString method.
				//*********************************************************
				ps.print(customer.toString());
				
				//*****************************************************************
				// Formatting for the column names of the report.
				// The "-" in front of the first format specifier justifies the column to the left.
				//*****************************************************************
				ps.printf("\n%-30s %12s %10s %12s\n", "Description", "Price", "Quantity", "Cost");
				ps.printf("%-30s %12s %10s %12s\n", "-----------", "-----", "--------", "----");
				
				// Initializing totalQuantity and totalCost to 0.
				int totalQuantity = 0;
				double totalCost = 0;
				
				// The for loop will have iterations until all elements of the purchase array are output.
				for(int i = 0; i < purchase.length; ++i)
				{
					//***************************************************************
					// Prints the product's description, price, quantity and cost
					// in that order to the console. Price and cost are rounded to two
					// decimal points because of the .2 in their format specifier.
					//***************************************************************
					ps.printf("%-30s %12.2f %10d %12.2f\n", purchase[i].getProduct().getDescription(), 
															purchase[i].getProduct().getPrice(), 
															purchase[i].getQuantity(), 
															purchase[i].getProduct().getPrice() * purchase[i].getQuantity());
					
					//**************************************************
					// Every iteration that the loop gets a quantity,
					// the value is added to the totalQuantity.
					//**************************************************
					totalQuantity = purchase[i].getQuantity() + totalQuantity;
					
					//************************************************
					// Every iteration that the loop calculates a cost, 
					// the value calculated is added to the totalCost.
					//************************************************
					totalCost = (purchase[i].getProduct().getPrice() * purchase[i].getQuantity()) + totalCost;
				}
				
				// Formatting for the bottom row of the report.
				ps.printf("%-30s %12s %10s %12s\n", "-----------", "-----", "--------", "----");
				//**********************************************************
				// Formats the totalQuantity and totalCost of the items to be
				// displayed at the bottom of the Quantity and Cost columns, respectively.
				//**********************************************************
				ps.printf("%-30s %23d %12.2f\n", "Total", totalQuantity, totalCost);	
	}
	
	/**
	 * The GetJSON method returns a concatenated string that
	 * formats the values of the member variables of PurchaseCollection into JSON format.
	 * Customer and Purchase's GetJSON methods are called in order to include the Customer
	 * and Purchase class's JSON within the PurchaseCollection class's JSON method.
	 * @return Which contains the concatenated JSON string.
	 */
	public String GetJSON()
	{
		String s;
		
		//*******************************************************
		// Calling the GetJSON of the Customer instance first since
		// customer JSON must be output before the purchase array's JSON.
		//*******************************************************
		s = String.format("{\n \"%s\" : \n%s,\n", "customer", customer.GetJSON());
		s = s + String.format("\"%s\" : \n[\n", "purchases");
		
		// A for loop is used so that the JSON of every index of the purchase array is output.
		for(int i = 0; i < purchase.length; i++)
		{
			//*****************************************************
			// If the index of the purchase array is equal to the value of the last index
			// of the purchase array then it's JSON should not be printed with a comma
			// at the end of it's closing curly brace.
			//*****************************************************
			if( i == (purchase.length - 1))
			{
				s = s + String.format("%s\n" , purchase[i].GetJSON());
			}
			//*****************************************************
			// Else if the index of the purchase array is not equal to the last index
			// of the purchase array then it's JSON should be printed with a comma
			// at the end of it's closing curly brace.
			//*****************************************************
			else
			{
				s = s + String.format("%s,\n", purchase[i].GetJSON());
			}
		}
		s = s + String.format("]\n}");
		
		// Returns the concatenated JSON string.
		return s;
	}
	
	/**
	 * The overridden toString method returns the 
	 * PurchaseCollction member variable values in a concatenated string.
	 * The Customer class's toString method is called and assigned to the string first
	 * before each index of the purchase array's call to toString is added to the string
	 * in order for the complete PurchaseCollection information to be returned by the method.
	 * return s Which contains the values of the member variables in a concatenated string.
	 */
	@Override
	public String toString()
	{
		String s;
		// Assigning s the value of customer's toString first.
		s = customer.toString();
		
		// A for loop is used so that every index of the purchase array's toString is output.
		for(int i = 0; i < purchase.length; i++)
		{
			// Concatenating the string to add the toString value of every index in the purchase array to it.
			s = s + purchase[i].toString();
		}
		
		// Returns the concatenated string.
		return s;
	}
	
	/**
	 * The getPurchases method returns the array of Purchase contained in PurchaseCollection's member variable purchase.
	 * @return purchase The array of Purchase.
	 */
	public Purchase[] getPurchases()
	{
		// Returns the array of Purchase contained in PurchaseCollection's member variable purchase.
		return purchase;
	}
}
