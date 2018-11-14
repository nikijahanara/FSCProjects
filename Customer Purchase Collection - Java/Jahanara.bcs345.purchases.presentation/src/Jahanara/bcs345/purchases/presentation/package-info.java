/**
 * This package contains five classes: Main, CustomerPurchaseConsoleUI, PurchaseCollectionConsoleUI,
 * PurchasesGraphicalUI and PurchasesApplication.
 * CustomerPurchaseConsoleUI has the ShowUI method, which displays a menu that prompts the user to
 * enter a number choice corresponding to reading data from a customer/purchase file, 
 * writing customer/purchase data to a file, showing customer/purchase information on the console, 
 * or showing customer/purchase JSON to the console from the imported Purchase and Customer class.
 * PurchaseCollectionConsoleUI also has a ShowUI method, which displays a menu that prompts the user
 * to enter a number choice corresponding to reading data from a purchase collection file, 
 * writing data to a purchase collection file, show a purchase by an index, show the maximum purchase,
 * show PurchaseCollection JSON to the console, show a PurchaseCollection report to the console, or
 * show the overridden PurchaseCollection toString to the console from the imported PurchaseCollection class.
 * PurchasesGraphicalUI also has a ShowUI method that launches the PurchaseApplication class's Purchases window when it is called.
 * PurchasesApplication extends from Application in order to override the start method that displays 
 * the Purchases GUI for the application. The Purchases GUI has two tabs, Customer and Purchases, as well as a menu bar
 * with a "File" menu that allows the user to open a file to populate the Customer and Purchases tab with data, 
 * save the PurchaseCollectiondata to a file, save a PurchaseCollection report to a file, 
 * or exit from the Purchases GUI and return to the menu console window prompt.
 * Within the Main class is the main method. The main method's purpose is to create an instance
 * of the CustomerPurchaseConsoleUI class, PurchaseCollectionConsoleUI, and the PurchasesGraphicalUI class in order to 
 * allow the user to choose in a menu that is output from main which sub-menu the user want to access: 
 * PurchaseCollectionConsoleUI ShowUI()'s menu, CustomerPurchaseConsoleUI ShowUI()'s menu, or 
 * PurchasesGraphicalUI's ShowUI() that launches the Purchases window created in the PurchasesApplication class.
 * 
 * @author Niki Jahanara
 */
package Jahanara.bcs345.purchases.presentation;