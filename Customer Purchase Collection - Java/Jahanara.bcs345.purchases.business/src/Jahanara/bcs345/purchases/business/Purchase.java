package Jahanara.bcs345.purchases.business;

import java.io.PrintStream;
import java.util.Scanner;
/**
 * The Purchase class contains it's member variables and the definitions for it's default constructor, 
 * Get/Set methods, Write method, Read method, GetJSON method and an overridden toString method.
 * The Purchase class also reuses code by calling the Read, Write, GetJSON and toString methods 
 * of the Product class within it's own Read, Write, GetJSON and toString methods.
 * 
 * @author Niki Jahanara
 * @version 1.0
 * @since 10/23/2016
 */
public class Purchase {

	// Declaring the private member variables.
	private Product product;
	private int Quantity;
	
	/**
	* This method is the default constructor for the Purchase class.
	*/
	public Purchase()
	{
		Quantity = 2;
		// Calling new on the instance of Product
		product = new Product();
	}
	
	/**
	 * The getProduct method returns the values of Product's member variables.
	 * @return product The instance of Product containing the values of Product's member variables.
	 */
	public Product getProduct() { return product; }
	/**
	 * The getQuantity method returns the value of the Quantity member variable.
	 * @return Quantity The value of the Quantity member variable.
	 */
	public int getQuantity() { return Quantity; }
	
	/**
	 * The setProduct method assigns the values of the member variables of 
	 * the instance of Product passed into it as the value for the member variables of Product instance product.
	 * @param newProduct The new values for the Product members variables.
	 */
	public void setProduct(Product newProduct) { product = newProduct; }
	/**
	 * The setQuantity method assigns the value passed into it as the value for the Quantity member variable.
	 * @param newQuantity The new value for the Quantity member variable.
	 */
	public void setQuantity(int newQuantity) { Quantity = newQuantity; }
	
	/**
	 * The Write method prints the values of the Purchase class's member variables to
	 * a file by passing an instance of PrintStream into the method's parameter.
	 * The class also prints the values of the Product class's member variables to the
	 * same file by passing the instance of PrintStream to a call of Product's Write method.
	 * @param ps The instance of PrintStream.
	 */
	public void Write(PrintStream ps)
	{
		//***********************************************************
		// Each format specifier is followed by a newline sequence
		// so that each member variable's value is printed onto a new line
		// in the output file generated by the method.
		// This is true for the format specifiers in the Write method of
		// the Product class that is called as well.
		//***********************************************************
		product.Write(ps);
		ps.printf("%s\n", Quantity);
	}
	
	/**
	 * The Read method is passed an instance of Scanner in order
	 * to assign the values it reads on each line of the file, that the
	 * Write method generated, to each of the Purchase class's member variables.
	 * The instance of Scanner is also passed into Product's Read method in
	 * order to assign the product data in the file to it's member variables.
	 * @param s The instance of Scanner.
	 */
	public void Read(Scanner s) 
	{
		//*******************************************************
		// Because the purchase file has product data listed first,
		// there is a call to the Product class's Read before
		// the remaining quantity data is read and assigned
		// to the Quantity member variable.
		//*******************************************************
		product.Read(s);
		Quantity = s.nextInt();
		s.nextLine();
	}
	
	/**
	 * The GetJSON method returns a concatenated string that
	 * formats the values of the member variables of Purchase into JSON format.
	 * Product's GetJSON method is called in order to include the Product class's JSON
	 * within the Purchase class's JSON.
	 * @return s Which contains the concatenated JSON string.
	 */
	public String GetJSON() 
	{
		//*****************************************************************
		// Formatting each string before it is concatenated so that the method
		// returns each line stored in string s in the correct JSON format.
		//*****************************************************************
		String s = String.format("{\n\t\"%s\" %s\n", "product", ":");
		s = s + String.format("%s,", product.GetJSON());
		s = s + String.format("\n\t\"%s\" %s %d\n}", "quantity",":", Quantity);
		
		return s;
	}
	
	/**
	 * The overridden toString method returns the 
	 * Purchase member variable's values in a formatted string.
	 * The Product class's toString method is also called in order for the 
	 * complete product and purchase information to be returned by the method.
	 * @return s Which contains the values of the member variables in a formatted string.
	 */
	@Override
	public String toString()
	{
		//********************************************
		// Formatting string s so that it returns each
		// value of the purchase and product information in the correct format.
		//********************************************
		String s = String.format("%s, ", Quantity);
		s = s + product.toString();
		
		return s;
	}
}
