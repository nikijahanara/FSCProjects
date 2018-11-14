package Jahanara.bcs345.purchases.presentation;

import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * The Main class contains the main method. Within the main method is a menu
 * that prompts the user to enter which sub-menu they want to enter,
 * CustomerPurchaseConsoleUI, PurchaseCollectionConsoleUI, PurchasesGraphicalUI,
 * or if they want to exit from the program.
 * 
 * @author Niki Jahanara
 * @version 1.0
 * @since 12/8/2016
 */
public class Main {
	/**
	 * The main method contains a menu that prompts the user to enter the number of the sub-menu
	 * they want to enter or if they want to exit the program. The ShowUI() method is called
	 * for either PurchaseCollectionConsoleUI, CustomerPurchaseConsoleUI or
	 * PurchasesGraphicalUI depending on which choice the user enters.
	 * @param args
	 * @throws FileNotFoundException
	 */
	public static void main(String[] args) throws FileNotFoundException{
		
		// Declaring an instance of CustomerPurchaseConsoleUI.
		CustomerPurchaseConsoleUI c = new CustomerPurchaseConsoleUI();
		// Declaring an instance of PurchaseCollectionConsoleUI.
		PurchaseCollectionConsoleUI pc = new PurchaseCollectionConsoleUI();
		// Declaring an instance of PurchaseGraphicalUI.
		PurchasesGraphicalUI pg = new PurchasesGraphicalUI();
		Scanner keyboard = new Scanner(System.in);
		int userChoice;

		//*****************************************************************
		// A do while loop is used because the menu must be displayed at least once and 
		// must be displayed again after every choice the user enters until the user chooses to exit from the program. 
		//*****************************************************************
		do
		{
			// Formatting for the menu that will be displayed for the user.
			System.out.printf("%s\n", "Choose UI");
			System.out.println("--------------------");
			System.out.println("1 – CustomerPurchaseConsoleUI.");
			System.out.println("2 – PurchaseCollectionConsoleUI.");
			System.out.println("3 – PurchasesGraphicalUI.");
			System.out.println("4 – Exit.");
			System.out.println("Enter choice:");
			// Reading in the choice number that the user enters.
			userChoice = keyboard.nextInt();
			
			//******************************************************
			// The choice number that the user enters corresponds with 
			// which case within the switch will be executed.
			//******************************************************
			switch(userChoice)
			{
				//****************************************************************
				// If the user enters in 1, a call to ShowUI method from the CustomerPurchaseConsoleUI class
				// is made so that a sub-menu of options is displayed to the user.
				//****************************************************************
				case 1:
					c.ShowUI();
					break;
				//****************************************************************
				// If the user enters in 2, a call to ShowUI method from the PurchaseCollectionConsoleUI class
				// is made so that a sub-menu of options is displayed to the user.
				//****************************************************************
				case 2:
					pc.ShowUI();
					break;
				//****************************************************************
				// If the user enters in 3, a call to ShowUI method from the PurchasesGraphicalUI class
				// is made so that a Purchase GUI is displayed to the user.
				//****************************************************************
				case 3:
					pg.ShowUI();
					break;
				//**************************************************************
				// If the user enters 4 as their choice, a message stating that
				// the user has exited from the program will be displayed before 
				// the do while loop is terminated.
				//**************************************************************
				case 4:
					System.out.println("You have exited from the Choose UI menu.");
					break;
				//**************************************************************
				// If the user enters a value for the userChoice variable that
				// does not have a corresponding case, a message will be displayed
				// stating that their menu choice is invalid and also prompts
				// the user to enter in another valid choice.
				//**************************************************************
				default:
					System.out.println("Invalid choice. Please try again.\n");
			}
		} while (userChoice != 4);
	}
}
