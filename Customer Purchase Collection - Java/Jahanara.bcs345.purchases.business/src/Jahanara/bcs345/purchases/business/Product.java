package Jahanara.bcs345.purchases.business;

import java.io.PrintStream;
import java.util.Scanner;
/**
 * The Product class contains it's member variables and the definitions for it's default constructor, 
 * Get/Set methods, Write method, Read method, GetJSON method and an overridden toString method.
 * 
 * @author Niki Jahanara
 * @version 1.0
 * @since 10/23/2016
 */
public class Product {
	
	// Declaring the private member variables.
	private String Description;
	private double Price;
	
	/**
	* This method is the default constructor for the Product class.
	*/
	public Product()
	{
		// Assigning default values for each of the member variables.
		Description = "Samsung Galaxy s7";
		Price = 199.99;
	}
	
	/**
	 * The getDescription method returns the value of the Description member variable.
	 * @return Description The value of the Description member variable.
	 */
	public String getDescription() { return Description; }
	/**
	 * The getPrice method returns the value of the Price member variable.
	 * @return Price The value of the Price member variable.
	 */
	public double getPrice() { return Price; }
	
	/**
	 * The setDescription method assigns the value passed into 
	 * it as the value for the Description member variable.
	 * @param newDescription The new value for the Description member variable.
	 */
	public void setDescription(String newDescription) {Description = newDescription;}
	/**
	 * The setPrice method assigns the value passed into it as the value for the Price member variable.
	 * @param newPrice The new value for the Price member variable.
	 */
	public void setPrice(double newPrice) {Price = newPrice;}
	/**
	 * The Write method prints the values of the Product class's member variables
	 * to a file by passing an instance of PrintStream into the method's parameter.
	 * @param ps An instance of PrintStream.
	 */
	public void Write(PrintStream ps) 
	{
		//***********************************************************
		// Each format specifier is followed by a newline sequence
		// so that each member variable's value is printed onto a new line
		// in the output file generated by the Write method.
		//***********************************************************
		ps.printf("%s\n%s\n", Description, Price);
	}
	/**
	 * The Read method is passed an instance of Scanner in order
	 * to assign the values it reads on each line of the file, that the
	 * Write method generated, to each of the Product class's member variables.
	 * @param s An instance of Scanner.
	 */
	public void Read(Scanner s)
	{
		//*******************************************************
		// Scanner's nextLine() method reads an entire line, which is important
		// because the Read method will read values that have each
		// been printed onto a new line by the Write method.
		//*******************************************************
		Description = s.nextLine();
		Price = s.nextDouble();
	}
	
	/**
	 * The GetJSON method returns a concatenated string that
	 * formats the values of the member variables of Product into JSON format.
	 * @return s Which contains the concatenated JSON string.
	 */
	public String GetJSON()
	{
		//*****************************************************************
		// Formatting each string before it is concatenated so that the method
		// returns each line stored in string s in the correct JSON format.
		//*****************************************************************
		String s = String.format("\t{\n\t\t\"%-11s\" %s \"%s\", \n", "description", ":", Description);
		s = s + String.format("\t\t\"%-5s\" %7s %.2f \n\t}", "price", ":", Price);
		
		return s;
	}
	
	/**
	 * The overridden toString method returns the 
	 * Product member variable's values in a formatted string.
	 * @return s Which contains the values of the member variables in a formatted string.
	 */
	@Override
	public String toString()
	{
		//********************************************
		// Formatting string s so that it returns the
		// product's description and price in the correct format.
		//********************************************
		String s = String.format("%s, $%.2f\n", Description, Price);
		
		return s;
	}
}