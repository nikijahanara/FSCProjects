package Jahanara.bcs345.purchases.business;

import java.io.PrintStream;
import java.util.Scanner;
/**
 * The Address class contains it's member variables and the definitions for it's default constructor, 
 * constructor, Get/Set methods, Write method, Read method, GetJSON method and an overridden toString method.
 * 
 * @author Niki Jahanara
 * @version 1.0
 * @since 10/23/2016
 */
public class Address {
	
	// Declaring the private member variables.
	private String Number;
	private String Street;
	private String City;
	private String State;
	private String Zip;

	/**
	* This method is the default constructor for the Address class.
	*/
	public Address() 
	{
		// Assigning default values for each of the member variables.
		Number = "10";
		Street = "Broadway";
		City = "New York";
		State = "NY";
		Zip = "10001";
	}
	
	/**
	 * This method is a constructor for the Address class.
	 * The values passed into each parameter are assigned to the
	 * class's corresponding member variables.
	 * 
	 * @param number The new value for the member variable Number.
	 * @param street The new value for the member variable Street.
	 * @param city The new value for the member variable City.
	 * @param state The new value for the member variable State.
	 * @param zip The new value for the member variable Zip.
	 */
	public Address(String number, String street, String city, String state, String zip) 
	{
		//***********************************************************
		// Assigning the values in the constructor's parameters
		// to each of the class's corresponding member variables.
		//***********************************************************
		Number = number;
		Street = street;
		City = city;
		State = state;
		Zip = zip;
	}
	
	/**
	 * The getNumber method returns the value of the Number member variable.
	 * @return Number The value of the Number member variable.
	 */
	public String getNumber() { return Number; }
	/**
	 * The getStreet method returns the value of the Street member variable.
	 * @return Street The value of the Street member variable.
	 */
	public String getStreet() { return Street; }
	/**
	 * The getCity method returns the value of the City member variable.
	 * @return City The value of the City member variable.
	 */
	public String getCity() { return City; }
	/**
	 * The getState method returns the value of the State member variable.
	 * @return State The value of the State member variable.
	 */
	public String getState() { return State; }
	/**
	 * The getZip method returns the value of the Zip member variable.
	 * @return Zip The value of the Zip member variable.
	 */
	public String getZip() { return Zip; }
	
	/**
	 * The setNumber method assigns the value passed into it as the value for the Number member variable.
	 * @param newNumber The new value for the Number member variable.
	 */
	public void setNumber(String newNumber) { Number = newNumber; }
	/**
	 * The setStreet method assigns the value passed into it as the value for the Street member variable.
	 * @param newStreet The new value for the Street member variable.
	 */
	public void setStreet(String newStreet) { Street = newStreet; }
	/**
	 * The setCity method assigns the value passed into it as the value for the City member variable.
	 * @param newCity The new value for the City member variable.
	 */
	public void setCity(String newCity) { City = newCity; }
	/**
	 * The setState method assigns the value passed into it as the value for the State member variable.
	 * @param newState The new value for the State member variable.
	 */
	public void setState(String newState) { State = newState; }
	/**
	 * The setZip method assigns the value passed into it as the value for the Zip member variable.
	 * @param newZip The new value for the Zip member variable.
	 */
	public void setZip(String newZip) { Zip = newZip; }
	
	/**
	 * The Write method prints the values of the Address class's member variables to
	 * a file by passing an instance of PrintStream into the method's parameter.
	 * @param ps The instance of PrintStream.
	 */
	public void Write(PrintStream ps)
	{
		//***********************************************************
		// Each format specifier is followed by a newline sequence
		// so that each member variable's value is printed onto a new line
		// in the output file generated by the method.
		//***********************************************************
		ps.printf("%s\n%s\n%s\n%s\n%s\n", Number, Street, City, State, Zip);
	}
	
	/**
	 * The Read method is passed an instance of Scanner in order
	 * to assign the values it reads on each line of the file, that the
	 * Write method generated, to each of the Address class's member variables.
	 * @param s The instance of Scanner.
	 */
	public void Read(Scanner s) 
	{
		//*******************************************************
		// Scanner's nextLine() method reads an entire line, which is important
		// because the Read method will read values that have each
		// been printed onto a new line by the Write method.
		//*******************************************************
		Number = s.nextLine();
		Street = s.nextLine();
		City = s.nextLine();
		State = s.nextLine();
		Zip = s.nextLine();
	}
	
	/**
	 * The GetJSON method returns a concatenated string that
	 * formats the values of the member variables of Address into JSON format.
	 * @return s Which contains the concatenated JSON string.
	 */
	public String GetJSON() 
	{
		//*****************************************************************
		// Formatting each string before it is concatenated so that the method
		// returns each line stored in string s in the correct JSON format.
		//*****************************************************************
		String s = String.format("\t{\n\t\t\"%-6s\" %1s \"%s\", \n", "number", ":", Number);
		s = s + String.format("\t\t\"%-5s\" %s \"%s\", \n", "street", ":", Street);
		s = s + String.format("\t\t\"%-3s\" %3s \"%s\", \n", "city", ":", City);
		s = s + String.format("\t\t\"%-5s\" %2s \"%s\", \n", "state", ":",  State);
		s = s + String.format("\t\t\"%-3s\" %4s \"%4s\" \n\t}", "zip", ":", Zip);
		
		return s;
	}
	
	/**
	 * The overridden toString method returns the 
	 * Address member variable's values in a formatted string.
	 * @return s Which contains the values of the member variables in a formatted string.
	 */
	@Override
	public String toString()
	{
		//********************************************
		// Formatting string s so that it returns each
		// value of the address in the correct format.
		//********************************************
		String s = String.format("%s %s\n%s, %s %s\n", Number, Street, City, State, Zip);
		
		return s;
	}
}
