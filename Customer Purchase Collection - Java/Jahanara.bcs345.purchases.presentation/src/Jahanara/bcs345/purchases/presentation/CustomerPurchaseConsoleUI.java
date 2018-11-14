package Jahanara.bcs345.purchases.presentation;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Scanner;

import Jahanara.bcs345.purchases.business.Customer;
import Jahanara.bcs345.purchases.business.Purchase;

/**
 *  The CustomerPurchaseConsoleUI class contains the ShowUI method. The ShowUI() method
 *  outputs a menu that prompts the user to enter whether they want to read customer/purchase data from a file, 
 *  write customer/purchase data to a file, show customer/purchase information, show the customer/purchase JSON,  
 *  or show the customer/purchase information from an instance of the the imported Purchase or Customer class.
 *  
 * @author Niki Jahanara
 * @version 1.0
 * @since 10/23/2016
 */
public class CustomerPurchaseConsoleUI {
	
	/**
	 * The ShowUI method displays a menu that prompts a user to enter whether they want to
	 * read customer data from a file, read purchase data from a file, write customer data to a file,
	 * write purchase data to a file, output customer or purchase information to the console,
	 * or output customer or purchase JSON onto the console.
	 * 
	 * @throws FileNotFoundException
	 */
	public void ShowUI() throws FileNotFoundException
	{
		// Declaring an instance of Customer.
		Customer c = new Customer();
		// Declaring an instance of Purchase.
		Purchase p = new Purchase();
		Scanner keyboard = new Scanner(System.in);
		String outputCustomerFileName;
		String inputCustomerFileName;
		String outputPurchaseFileName;
		String inputPurchaseFileName;
		int userChoice;
		
		//*****************************************************************
		// A do while loop is used because the menu must be displayed at least once and 
		// must be displayed again after every choice the user 
		// enters until the user chooses to exit from the program. 
		//*****************************************************************
		do
		{
			// Formatting for the menu that will be displayed for the user.
			System.out.printf("\n%s\n", "Purchase/Customer UI");
			System.out.println("--------------------");
			System.out.println("1 – Read customer from file.");
			System.out.println("2 – Write customer to file.");
			System.out.println("3 – Show customer info on screen.");
			System.out.println("4 – Show customer JSON on screen");
			System.out.println("5 – Read purchase from file.");
			System.out.println("6 – Write purchase to file.");
			System.out.println("7 – Show purchase info on screen.");
			System.out.println("8 – Show purchase JSON on screen");
			System.out.println("9 – Exit.");
			System.out.println("Enter choice:");
			// Reading in the choice number that the user enters.
			userChoice = keyboard.nextInt();
			
			//******************************************************
			// The choice number that the user enters corresponds with 
			// which case within the switch will be executed.
			//******************************************************
			switch (userChoice)
			{
				//****************************************************
				// If the user enters 1 as their choice, they will be prompted to enter
				// the name of the customer input file that they want to read data in from.
				//****************************************************
				case 1:
					System.out.println("Please enter the name of the customer input file:");
					// Reading in the name of the customer input file from the user.
					inputCustomerFileName = keyboard.next();
					//****************************************************
					// Declaring an instance of Scanner that will
					// read the data from the customer input file that the user entered.
					// The file assigned to inputCustomerFileName is also read
					// through the use of FileReader.
					//****************************************************
					Scanner cReader = new Scanner(new FileReader(inputCustomerFileName));
					//**************************************************************
					// Calling and passing in an instance of Scanner into the Read
					// function of the Customer class so that the data from the customer
					// input file that the user entered will be read and assigned to
					// the member variables of this instance of Customer.
					//**************************************************************
					c.Read(cReader);
					break;
				//****************************************************
				// If the user enters 2 as their choice, they will be prompted to enter
				// the name of customer output file that they want to write data to.
				//****************************************************
				case 2:
					System.out.println("Please enter the name of the output file:");
					// Reading in the name of the customer output file from the user.
					outputCustomerFileName = keyboard.next();
					//****************************************************
					// Creating the file that the user entered for the customer output file
					// so that the values of the member variables
					// can be written to the file by an instance of PrintStream.
					//****************************************************
					PrintStream customerPS = new PrintStream(outputCustomerFileName);
					//**************************************************************
					// Calling and passing in an instance of PrintStream into the Write
					// method of the Customer class so that the values of the member
					// variables of this instance of Customer will be written to the
					// customer output file that the user entered.
					//**************************************************************
					c.Write(customerPS);
					break;
				// If the user enters 3 as their choice, customer information will be output to the console.
				case 3:
					System.out.println("Customer Information:");
					// Calling the overloaded toString method to display customer information to the console.
					System.out.printf(c.toString());
					break;
				
				// If the user enters 4 as their choice, customer JSON will be output to the console.
				case 4:
					System.out.println("Customer JSON:");
					// Calling the GetJSON method to display customer JSON to the console.
					System.out.printf(c.GetJSON());
					break;
				//****************************************************
				// If the user enters 5 as their choice, they will be prompted to enter
				// the name of the purchase input file that they want to read data in from.
				//****************************************************
				case 5:
					System.out.println("Please enter the name of the purchase input file:");
					// Reading in the name of the purchase input file from the user.
					inputPurchaseFileName = keyboard.next();
					//****************************************************
					// Declaring an instance of Scanner that will
					// read the data from the purchase input file that the user entered.
					// The file assigned to inputCustomerFileName is also read
					// through the use of FileReader.
					//****************************************************
					Scanner purchaseReader = new Scanner(new FileReader(inputPurchaseFileName));
					//**************************************************************
					// Calling and passing in an instance of Scanner into the Read
					// function of the Purchase class so that the data from the purchase
					// input file that the user entered will be read and assigned to
					// the member variables of this instance of Purchase.
					//**************************************************************
					p.Read(purchaseReader);
					break;
				//****************************************************
				// If the user enters 6 as their choice, they will be prompted to enter
				// the name of purchase output file that they want to write data to.
				//****************************************************
				case 6:
					System.out.println("Please enter the name of the purchase output file:");
					// Reading in the name of the purchase output file from the user.
					outputPurchaseFileName = keyboard.next();
					//****************************************************
					// Creating the file that the user entered for the purchase output file
					// so that the values of the member variables
					// can be written to the file by an instance of PrintStream.
					//****************************************************
					PrintStream purchasePS = new PrintStream(outputPurchaseFileName);
					//**************************************************************
					// Calling and passing in an instance of PrintStream into the Write
					// method of the Purchase class so that the values of the member
					// variables of this instance of Purchase will be written to the
					// purchase output file that the user entered.
					//**************************************************************
					p.Write(purchasePS);
					break;
				// If the user enters 7 as their choice, purchase information will be output to the console.
				case 7:
					System.out.println("Purchase Information:");
					// Calling the overloaded toString method to display purchase information to the console.
					System.out.printf(p.toString());
					break;
				// If the user enters 8 as their choice, purchase JSON will be output to the console.
				case 8:
					System.out.println("Purchase JSON");
					// Calling the GetJSON method to display purchase JSON to the console.
					System.out.printf(p.GetJSON());
					break;
				//**************************************************************
				// If the user enters 9 as their choice, a message stating that
				// the user has exited from the program will be displayed before 
				// the do while loop is terminated.
				//**************************************************************
				case 9:
					System.out.println("You have exited from the CustomerPurchaseConsoleUI menu.\n");
					break;
				//**************************************************************
				// If the user enters a value for the userChoice variable that
				// does not have a corresponding case, a message will be displayed
				// stating that their menu choice is invalid and also prompts
				// the user to enter in another valid choice.
				//**************************************************************
				default	:
					System.out.println("Invalid menu choice. Please try again.");
					break;
			}
			
		} while(userChoice != 9);
	}
}
