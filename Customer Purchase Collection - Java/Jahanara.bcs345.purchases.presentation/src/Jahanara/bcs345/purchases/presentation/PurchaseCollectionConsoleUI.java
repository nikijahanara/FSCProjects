package Jahanara.bcs345.purchases.presentation;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Scanner;

import Jahanara.bcs345.purchases.business.PurchaseCollection;

/**
 *  The PurchaseCollectionConsoleUI class contains the ShowUI method. The ShowUI() method
 *  outputs a menu that prompts the user to enter whether they want to read PurchaseCollection data from a file,
 *  write PurchaseCollection data to a file, show a purchase by index, show the maximum purchase, 
 *  show PurchaseCollection JSON on the console, show a purchase report on the console,
 *  or show the PurchaseCollection toString on the console from an instance of the imported PurchaseCollection class.
 *  
 * @author Niki Jahanara
 * @version 1.0
 * @since 11/10/2016
 */
public class PurchaseCollectionConsoleUI {	
	/**
	 * The ShowUI method displays a menu that prompts a user to enter whether they want to
	 * read PurchaseCollection data from a file, write PurchaseCollection data to a file,
	 * show a purchase by index, show the maximum purchase, show PurchaseCollection JSON on the console,
	 * show a purchase report on the console, or show the PurchaseCollection toString on the console.
	 * 
	 * @throws FileNotFoundException
	 */
	public void ShowUI() throws FileNotFoundException
	{
		// Declaring an instance of PurchaseCollection.
		PurchaseCollection pc = new PurchaseCollection();
		Scanner keyboard = new Scanner(System.in);
		String outputPurchaseCollectionFileName;
		String inputPurchaseCollectionFileName;
		int userChoice;
		
		//*****************************************************************
		// A do while loop is used because the menu must be displayed at least once and 
		// must be displayed again after every choice the user 
		// enters until the user chooses to exit from the program. 
		//*****************************************************************
		do
		{
			// Formatting for the menu that will be displayed for the user.
			System.out.printf("\n%s\n", "PurchaseCollection UI");
			System.out.println("--------------------");
			System.out.println("1 – Read PurchaseCollection from file.");
			System.out.println("2 – Write PurchaseCollection to file.");
			System.out.println("3 – Show purchase by index.");
			System.out.println("4 – Show maximum purchase.");
			System.out.println("5 – Show PurchaseCollection as JSON string on screen.");
			System.out.println("6 – Show PurchaseCollection report on screen");
			System.out.println("7 – Show PurchaseCollection toString on screen");
			System.out.println("8 – Exit.");
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
				// the name of the purchase collection input file that they want to read data in from.
				//****************************************************
				case 1:
					System.out.println("Please enter the PurchaseCollection input file:");
					// Reading in the name of the purchase collection input file from the user.
					inputPurchaseCollectionFileName = keyboard.next();
					//****************************************************
					// Declaring an instance of Scanner that will
					// read the data from the purchase collection input file that the user entered.
					// The file assigned to inputPurchaseCollectionFileName is also read through the use of FileReader.
					//****************************************************
					Scanner pcReader = new Scanner(new FileReader(inputPurchaseCollectionFileName));
					//**************************************************************
					// Calling and passing in an instance of Scanner into the Read
					// method of the PurchaseCollection class so that the data from the
					// input file that the user entered will be read and assigned to
					// the member variables of this instance of PurchaseCollection.
					//**************************************************************
					pc.Read(pcReader);
					break;
				//****************************************************
				// If the user enters 2 as their choice, they will be prompted to enter
				// the name of purchase collection output file that they want to write data to.
				//****************************************************
				case 2:
					System.out.println("Please enter the PurchaseCollection output file:");
					// Reading in the name of the purchase collection output file from the user.
					outputPurchaseCollectionFileName = keyboard.next();
					//****************************************************
					// Creating the file that the user entered for the purchase collection output file
					// so that the values of the member variables of the PurchaseCollection instance
					// can be written to the file by an instance of PrintStream.
					//****************************************************
					PrintStream purchaseCollectionPS = new PrintStream(outputPurchaseCollectionFileName);
					//**************************************************************
					// Calling and passing in an instance of PrintStream into the Write
					// method of the PurchaseCollection class so that the values of the member
					// variables of this instance of PurchaseCollection will be written to the
					// purchase collection output file that the user entered.
					//*************************************************************
					pc.Write(purchaseCollectionPS);
					break;
				//*************************************************************
				// If the user enters 3 as their choice, they will be prompted to enter
				// the index number of the purchase instance they want to be output to the console.
				//*************************************************************
				case 3:
					// Initializing the continueLoop condition for the do while loop as true.
					boolean continueLoop = true;
					int index;
					//***************************************************
					// A do while loop is used within this case in order to allow
					// the user to keep entering in index numbers until the user enters a valid index number.
					//***************************************************
					do
					{
						//*************************************************************
						// Because GetByIndex throws both ArrayIndexOutOfBoundsException
						// and NullPointerException, the call to the method is put inside 
						// a try block in order for either exception to be caught by the
						// catch blocks that follow the try block depending on if the
						// user enters an invalid array index, or if the array is null.
						//*************************************************************
						try
						{
							// Prompting the user to enter in an index number.
							System.out.println("Please enter an index: ");
							// Reading in the integer value that the user enters for the index.
							index = keyboard.nextInt();
							//***********************************************
							// Printing out the index of purchase that the user entered with a
							// call to PurchaseCollection's GetByIndex method.
							//***********************************************
							System.out.printf("%s %d %s\n%s", "Index", index, "Purchase:", pc.GetByIndex(index));
							//****************************************************
							// Setting the do while loop's condition as false when the user enters
							// a valid index so that the do while loop terminates.
							//****************************************************
							continueLoop = false;
						}
						//******************************************************
						// If GetByIndex throws an ArrayIndexOutOfBoundsException
						// this catch block will catch the exception, output an error message
						// and allow the user to enter in another value for the index due to
						// the do while loop's condition still remaining true.
						//******************************************************
						catch(ArrayIndexOutOfBoundsException e)
						{
							System.err.println("Index entered is out of bounds. Please enter another index.");
						}
						//******************************************************
						// If GetByIndex throws a NullPointerException
						// this catch block will catch the exception and
						// output an error message to the user that alerts them
						// to first choose the menu option to read data from a file
						// in order to populate the null array with purchases.
						//******************************************************
						catch(NullPointerException npe)
						{
							System.err.println("The array is null. PurchaseCollection data must be read from a file.");
							//****************************************************
							// Setting the do while loop's condition as false when the user
							// is alerted that the array is null so that the do while loop terminates
							// and so that the user is not able to enter anymore indexes.
							//****************************************************
							continueLoop = false;
						}
					// The do while loop iterates until continueLoop is assigned a false value.
					} while(continueLoop);
					break;
				//****************************************************
				// If the user enters 4 as their choice, the maximum purchase 
				// in PurchaseCollection will be output to the console.
				//****************************************************
				case 4:
					//****************************************************************
					// A call to PurchaseCollections GetMaxPurchase method is made and it will
					// either return null if there are no purchases in the array, or it will return the
					// the instance of purchase within the array that has the highest
					// cost value when it's product quantity and product price are multiplied together.
					//****************************************************************
					System.out.printf("%s\n%s", "Maximum Purchase:", pc.GetMaxPurchase());
					break;
				// If the user enters 5 as their choice, PurchaseCollection JSON will be output to the console.
				case 5:
					// Calling the GetJSON method to display PurchaseCollection JSON to the console.
					System.out.printf("%s\n%s\n", "PurchaseCollection JSON:", pc.GetJSON());
					break;
				// If the user enters 6 as their choice, a purchase report will be output to the console.
				case 6:
					//********************************************
					// Declaring an instance of PrintStream that will be passed
					// into PurchaseCollection's Report method in order to
					// print a purchase report onto the console.
					//********************************************
					PrintStream purchaseReport = new PrintStream(System.out);
					//************************************************************
					// Calling and passing in the instance of PrintStream into the
					// Report method in order for a purchase report to be output to the console.
					//************************************************************
					pc.Report(purchaseReport);
					break;
				// If the user enters 7 as their choice, PurchaseCollection's toString will be output to the console.
				case 7:
					System.out.printf("%s\n%s", "PurchaseCollection Information:", pc.toString());
					break;
				//**************************************************************
				// If the user enters 8 as their choice, a message stating that
				// the user has exited from the menu will be displayed before 
				// the do while loop is terminated.
				//**************************************************************
				case 8:
					System.out.println("You have exited from the PurchaseCollectionConsoleUI menu.\n");
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
			
		} while(userChoice != 8);
	}
}
