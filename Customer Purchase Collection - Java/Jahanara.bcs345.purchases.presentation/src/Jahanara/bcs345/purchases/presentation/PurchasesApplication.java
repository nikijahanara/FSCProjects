package Jahanara.bcs345.purchases.presentation;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.NoSuchElementException;
import java.util.Scanner;

import Jahanara.bcs345.purchases.business.Purchase;
import Jahanara.bcs345.purchases.business.PurchaseCollection;
import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Orientation;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.SeparatorMenuItem;
import javafx.scene.control.Tab;
import javafx.scene.control.TabPane;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import javafx.stage.FileChooser;
/**
 * The PurchasesApplication class contains the definitions for the overridden start, CreateCustomerTab,
 * CreatePurchasesTab, PopulateCustomerTab and PopulatePurchasesTab methods. The PurchasesApplication class also
 * reuses code by inheriting from the Application class in order to override the Application class's start method.
 * The PurchasesApplication class displays the main window for the Purchases GUI by creating the Purchases window's
 * menu bar with a file menu that has "Open", "Save As", "Save Report" and "Exit" menu items and 
 * by also creating the window's Customer and Purchases tab.
 *  
 * @author Niki Jahanara
 * @version 1.0
 * @since 12/8/2016
 */
public class PurchasesApplication extends Application {
	
	// Declaring the private member variables of the PurchasesApplication class.
	private VBox vbox;
	private PurchaseCollection purchases;
	private TabPane tabPane;
	private TextField firstNameTextField;
	private TextField lastNameTextField;
	private TextField numberTextField;
	private TextField streetTextField;
	private TextField cityTextField;
	private TextField stateTextField;
	private TextField zipTextField;
	private ObservableList<Purchase> item;
	private ListView<Purchase> purchasesList;
	
	/**
	 * The overridden start method of the PurchasesApplication class creates the Purchases window
	 * that users can click on to interact with. The Purchases window has a menu bar with a file menu that
	 * allows users to open a file to read PurchaseCollection data, save PurchaseCollection data to a file,
	 * save a PurchaseCollection report to a file, or exit from the window and return to the main menu console window prompt.
	 * @throws Exception
	 */
	@Override
	public void start(Stage primaryStage) throws Exception {
	
		// Calling new on the instance of PurchaseCollection.
		purchases = new PurchaseCollection();
		// Setting the title of the window.
		primaryStage.setTitle("Purchases");
		
		// Calling new on VBox.
		vbox = new VBox();
		// Declaring an instance of MenuBar and calling new on it.
		MenuBar menuBar = new MenuBar();
		// Adding the MenuBar to the instance of VBox so it will be displayed in the window.
		vbox.getChildren().add(menuBar);
		
		//***************************************************
		// Declaring and calling new on two SeparatorMenuItem instances
		// because the MenuBar's file menu will needed to be divided into three sections.
		//***************************************************
		SeparatorMenuItem sep = new SeparatorMenuItem();
		SeparatorMenuItem sep2 = new SeparatorMenuItem();
		
		// Declaring and calling new on the menu titled "File".
		Menu fileMenu = new Menu("File");
		// Adding the "File" menu to the MenuBar.
		menuBar.getMenus().add(fileMenu);

		// Declaring and calling new on the first MenuItem, Open.
		MenuItem openMenuItem = new MenuItem("Open...");
		// Adding the "Open" MenuItem to the "File" menu.
		fileMenu.getItems().add(openMenuItem);
		
		//************************************************************
		// Calling setOnAction for the openMenuItem so that when the user
		// clicks on the File menu and then clicks on the "Open" menu item,
		// an open file dialog will be output to the user.
		//************************************************************
		openMenuItem.setOnAction(new EventHandler<ActionEvent>() {
			public void handle(ActionEvent t) 
			{
				// Declaring and calling new on an instance of FileChooser.
				FileChooser openFileChooser = new FileChooser();
				//***************************************************
				// Setting the title of the open file dialog so that the user
				// knows they must open a PurchaseCollection file.
				//***************************************************
		    	openFileChooser.setTitle("Open PurchaseCollection File");
		    	//***************************************************
		    	// Extracting the file from FileChooser.showOpenDialog()
		    	// after the user chooses a file in the open file dialog 
		    	// so that the file can be passed into the Read method 
		    	// called by an instance of PurchaseCollection.
		    	//***************************************************
		    	File openFile = openFileChooser.showOpenDialog(primaryStage);
		    	//***************************************************
		    	// The if statement makes it so that if the user clicks cancel instead
		    	// of choosing a file, the data contained in the instance of PurchaseCollection
		    	// will remain unchanged because the file's value is null.
		    	// If the user chooses a file, then the file is not null and
		    	// it will be passed into a call of the PurchaseCollection's Read method.
		    	//***************************************************
		    	if (openFile != null) 
		    	{
		    		//***************************************************
		    		// Because there is a possibility that the user could choose a file
		    		// that is empty or does not exist, the instance of FileReader
		    		// that reads the file before it is passed into the Read method of
		    		// an instance of PurchaseCollection is put in a try block so that
		    		// a FileNotFoundException or a NoSuchElementException can be caught.
		    		//***************************************************
		    		try 
		    		{
		    			//****************************************************
						// Declaring an instance of Scanner that will
						// read the data from the file that the user chose in the open file dialog.
						// The file the user chose is also read through the use of FileReader.
						//****************************************************
		    			Scanner openFileScanner = new Scanner(new FileReader(openFile));
		    			//****************************************************
		    			// Passing the instance of Scanner into a call of the Read method 
		    			// of the PurchaseCollection class so that the data in the file
		    			// will populate the Customer instance and the 
		    			// array of Purchase in PurchaseCollection.
		    			//***************************************************
		    			purchases.Read(openFileScanner);
		    			//***************************************************
		    			// Populating each of the Customer tab's TextFields with the
		    			// customer data that was read in from the PurchaseCollection 
		    			// file that the user opened through a call to PopulateCustomerInfo.
		    			//***************************************************
		    			PopulateCustomerInfo();
		    			//***************************************************
		    			// Populating the Purchase tab's ListView with the
		    			// purchase data that was read in from the PurchaseCollection 
		    			// file that the user opened through a call to PopulatePurchasesInfo.
		    			//***************************************************
		    			PopulatePurchasesInfo();
		    		}
		    		//******************************************************
					// If the file that the user chose in the open file dialog 
		    		// does not exist, then this catch block will catch the FileNotFoundException
					// and output a "File does not exist" error message to the user.
					//******************************************************
		    		catch (FileNotFoundException e) 
		    		{
		    			System.err.println("File does not exist.");
		    		}
		    		//******************************************************
					// If the file that the user chose in the open file dialog 
		    		// is empty then this catch block will catch the NoSuchElementException
					// and output a "The file selected is empty" error message to the user.
					//******************************************************
		    		catch (NoSuchElementException e)
		    		{
		    			System.err.println("The file selected is empty.");
		    		}
                }
		    }
		});

		// Adding the first instance of SeparatorMenuItem to the fileMenu after the "Open" menu item.
		fileMenu.getItems().add(sep);
		
		// Declaring and calling new on the second MenuItem, Save As.
		MenuItem saveAsMenuItem = new MenuItem("Save As...");
		// Adding the "Save As" menu item to the "File" menu.
		fileMenu.getItems().add(saveAsMenuItem);

		//************************************************************
		// Calling setOnAction for the saveAsMenuItem so that when the user
		// clicks on the "File" menu and then clicks on "Save As",
		// a save file dialog will be output to the user.
		//************************************************************
		saveAsMenuItem.setOnAction( new EventHandler<ActionEvent>() {
			public void handle(ActionEvent t) 
			{
				// Declaring and calling new on an instance of FileChooser.
				FileChooser saveAsFileChooser = new FileChooser();
				// Setting the title of the save as file dialog.
		    	saveAsFileChooser.setTitle("Save As PurchaseCollection");
		    	//***************************************************
		    	// Extracting the file from FileChooser.showSaveDialog()
		    	// after the user chooses a file in the save file dialog 
		    	// so that the file can be passed into the Write method 
		    	// called by an instance of PurchaseCollection.
		    	//***************************************************
		    	File saveAsFile = saveAsFileChooser.showSaveDialog(primaryStage);
		    	//***************************************************
		    	// The if statement makes it so that if the user clicks cancel instead
		    	// of choosing a file to save data to, the state of the application will remain unchanged.
		    	// If the user chooses a file, then the file is not null and it will be passed
		    	// into a call of the PurchaseCollection's Write method.
		    	//***************************************************
		    	if (saveAsFile != null) 
		    	{
		    		//***************************************************
		    		// Because there is a possibility that the user could choose a file to save to
		    		// that does not exist, the instance of PrintStream that opens the file 
		    		// before it is passed into the Write method of the PurchaseCollection class
		    		// is put in a try block so that a FileNotFoundException can be caught.
		    		//***************************************************
		    		try 
		    		{
		    			//****************************************************
						// Creating the file that the user chose as the save as file
						// so that the data contained in an instance of PurchaseCollection
						// can be written to the save as file by an instance of PrintStream.
						//****************************************************
		    			PrintStream saveAsPS = new PrintStream(saveAsFile);
		    			//***************************************************
		    			// Passing the instance of PrinStream into the Write method
		    			// called by an instance of PurchaseCollection so that the
		    			// data contained in the instance of PurchaseCollection
		    			// is written to and saved as the file that the user chose.
		    			//***************************************************
		    			purchases.Write(saveAsPS);
		    		}
		    		//******************************************************
					// If the file that the user chose in the save as file dialog 
		    		// does not exist, then this catch block will catch the FileNotFoundException
					// and output a "File does not exist" error message to the user.
					//******************************************************
		    		catch (FileNotFoundException e) 
		    		{
		    			System.err.println("File does not exist.");
		    		}
		    	}
		    }
		});
		
		// Declaring and calling new on the third MenuItem, Save Report.
		MenuItem saveReportMenuItem = new MenuItem("Save Report...");
		// Adding the "Save Report" menu item to the "File" menu.
		fileMenu.getItems().add(saveReportMenuItem);

		//************************************************************
		// Calling setOnAction for the saveReportMenuItem so that when the user
		// clicks on the "File" menu and then clicks on "Save Report",
		// a save report file dialog will be output to the user.
		//************************************************************
		saveReportMenuItem.setOnAction(new EventHandler<ActionEvent>() {
			public void handle(ActionEvent t) 
			{
				// Declaring and calling new on an instance of FileChooser.
				FileChooser saveReportFileChooser = new FileChooser();
				// Setting the title of the save report dialog.
		    	saveReportFileChooser.setTitle("Save PurchaseCollection Report");
		    	//***************************************************
		    	// Extracting the file from FileChooser.showSaveDialog()
		    	// after the user chooses a file in the save report file dialog 
		    	// so that the file can be passed into the Report method 
		    	// called by an instance of PurchaseCollection.
		    	//***************************************************
		    	File saveReportFile = saveReportFileChooser.showSaveDialog(primaryStage);
		    	//***************************************************
		    	// The if statement makes it so that if the user clicks cancel instead
		    	// of choosing a file to save the report to, the state of the application will remain unchanged.
		    	// If the user chooses a file, then the file is not null and it will be passed
		    	// into a call of the PurchaseCollection's Report method.
		    	//***************************************************
		    	if (saveReportFile != null) 
		    	{
		    		//***************************************************
		    		// Because there is a possibility that the user could choose a file to save 
		    		// the report to that does not exist, the instance of PrintStream that opens the file 
		    		// before it is passed into the Report method of the PurchaseCollection class
		    		// is put in a try block so that a FileNotFoundException can be caught.
		    		//***************************************************
		    		try 
		    		{
		    			//****************************************************
						// Creating the file that the user chose to save the report to
						// so that the data contained in an instance of PurchaseCollection
						// can be written as a report to the save report file by an instance of PrintStream.
						//****************************************************
		    			PrintStream saveReportPS = new PrintStream(saveReportFile);
		    			//***************************************************
		    			// Passing the instance of PrintStream into the Report method
		    			// called by an instance of PurchaseCollection so that the
		    			// data contained in the instance of PurchaseCollection
		    			// is written as a report to the file that the user chose.
		    			//***************************************************
		    			purchases.Report(saveReportPS);
		    		} 
		    		//******************************************************
					// If the file that the user chose in the save report file dialog 
		    		// does not exist, then this catch block will catch the FileNotFoundException
					// and output a "File does not exist" error message to the user.
					//******************************************************
		    		catch (FileNotFoundException e) 
		    		{
		    			System.err.println("File does not exist.");
		    		}
		    	}
			}
		});
		
		// Adding the second instance of SeparatorMenuItem to the fileMenu after the "Save Report" menu item.
		fileMenu.getItems().add(sep2);
		
		// Declaring and calling new on the fourth MenuItem, Exit.
		MenuItem exitMenuItem = new MenuItem("Exit");
		// Adding the "Exit" menu item to the "File" menu.
		fileMenu.getItems().add(exitMenuItem);

		//************************************************************
		// Calling setOnAction for the exitMenuItem so that when the user
		// clicks on the "File" menu and then clicks on "Exit",
		// the Purchases window closes and returns the user to the main menu console window prompt.
		//************************************************************
		exitMenuItem.setOnAction( new EventHandler<ActionEvent>() {
			public void handle(ActionEvent t) 
			{
				// A message will be output to the user that they have exited from the UI.
				System.out.println("You have exited from PurchasesGraphicalUI.");
				// Calling close on primaryStage so that the user is able to exit from the Purchases window.
				primaryStage.close();
			}
		});

		// Calling new on the instance of TabPane.
		tabPane = new TabPane();
		// Calling CreateCustomerTab so that the Customer tab is added to the TabPane.
		tabPane.getTabs().add(CreateCustomerTab());
		// Calling CreatePurchasesTab so that the Purchases tab is added to the TabPane.
		tabPane.getTabs().add(CreatePurchasesTab());
		// Adding the instance of TabPane to the instance of VBox.
		vbox.getChildren().add(tabPane);
	
		//******************************************************
		// Declaring and calling new on an instance of Scene
		// in order to pass in the instance of VBox as the root of the Scene.
		//******************************************************
		Scene scene = new Scene(vbox, 500, 500);
		// Passing the instance of Scene into the setScene method.
		primaryStage.setScene(scene);
		// Calling show on primaryStage so that the Purchases window will be displayed.
		primaryStage.show();
	}
	
	/**
	 * PopulateCustomerInfo is meant to be called after a user opens a file that
	 * contains PurchaseCollection data so that the text of each text field
	 * in the Customer tab can be populated with the customer's first name,
	 * last name, number, street, city, state and zip that was contained
	 * in the file that the user opened.
	 */
	private void PopulateCustomerInfo()
	{
		//************************************************************
		// Setting the text of the first name text field as the value 
		// returned by the getFirst method of the Customer instance 
		// member variable in PurchaseCollection.
		//************************************************************
		firstNameTextField.setText(purchases.GetCustomer().getFirst());
		//************************************************************
		// Setting the text of the last name text field as the value 
		// returned by the getLast method of the Customer instance 
		// member variable in PurchaseCollection.
		//************************************************************
		lastNameTextField.setText(purchases.GetCustomer().getLast());
		//************************************************************
		// Setting the text of the number text field as the value 
		// returned by the getNumber method of the Address member variable 
		// within the Customer instance member variable of PurchaseCollection.
		//************************************************************
		numberTextField.setText(purchases.GetCustomer().getAddress().getNumber());
		//************************************************************
		// Setting the text of the street text field as the value 
		// returned by the getStreet method of the Address member variable 
		// within the Customer instance member variable of PurchaseCollection.
		//************************************************************
		streetTextField.setText(purchases.GetCustomer().getAddress().getStreet());
		//************************************************************
		// Setting the text of the city text field as the value 
		// returned by the getCity method of the Address member variable 
		// within the Customer instance member variable of PurchaseCollection.
		//************************************************************
		cityTextField.setText(purchases.GetCustomer().getAddress().getCity());
		//************************************************************
		// Setting the text of the state text field as the value 
		// returned by the getState method of the Address member variable 
		// within the Customer instance member variable of PurchaseCollection.
		//************************************************************
		stateTextField.setText(purchases.GetCustomer().getAddress().getState());
		//************************************************************
		// Setting the text of the zip text field as the value 
		// returned by the getZip method of the Address member variable 
		// within the Customer instance member variable of PurchaseCollection.
		//************************************************************
		zipTextField.setText(purchases.GetCustomer().getAddress().getZip());
	}
	
	/**
	 * PopulatePurchasesInfo is meant to be called after a user opens a file that
	 * contains PurchaseCollection data so that every purchase that the customer 
	 * made, according to the file that was opened, is output in the Purchases tab in a ListView format.
	 * This is accomplished by a for loop within the PopulatePurchasesInfo method that adds each index
	 * of the Purchase array, which is populated by the file's purchase data, to the ObservableList instance
	 * and then adding the instance of ObservableList to the instance of ListView.
	 */
	private void PopulatePurchasesInfo()
	{
		//******************************************************
		// Declaring an array of Purchase and setting it
		// equal to the array that is returned from the getPurchases
		// method of the PurchaseCollection class so that the purchaseArray
		// is filled with the array returned by the getPurchases method.
		//******************************************************
		Purchase[] purchaseArray = purchases.getPurchases();
		
		//******************************************************
		// The for loop will loop through the purchaseArray and add
		// the Purchase data contained in each index of the purchaseArray
		// to the instance of ObservableList, item, until it reaches
		// the end of the purchaseArray.
		// The loop will not iterate past the true length of the purchaseArray
		// because the test expression must be less than purchaseArray.length.
		//******************************************************
		for(int index = 0; index < purchaseArray.length ; index++)
		{
			//******************************************************
			// Adding the Purchase data contained in each index of the purchaseArray
			// to the instance of ObservableList during each iteration of the loop.
			//******************************************************
			item.add(purchaseArray[index]);
		}
		
		// Setting the Purchase data array contained in item to the instance of ListView, purchasesList.
		purchasesList.setItems(item);
	}
	
	/**
	 * The CreateCustomerTab method creates the customer tab by declaring and calling
	 * new on an instance of Tab. The customer tab returned by this method also has
	 * an instance of VBox as the tab's root so that the Label and TextField instances
	 * created for each piece of a customer's information is aligned vertically.
	 * The customer tab returned by this method can be added to an instance of TabPane.
	 * @return customerTab The Customer tab.
	 */
	private Tab CreateCustomerTab()
	{
		//******************************************************
		// Declaring and calling new on the customerTab instance of Tab 
		// and setting the text of the tab as "Customer".
		//******************************************************
		Tab customerTab = new Tab("Customer");
		
		//******************************************************
		// Declaring and calling new on an instance of HBox for each
		// piece of a customer's information so that the instances of
		// Label and TextField for each piece of a customer's information
		// can be added to its respective HBox to be output next to each other.
		//******************************************************
		HBox firstNameHBox = new HBox(29);
		HBox lastNameHBox = new HBox(31);
		HBox numberHBox = new HBox(43);
		HBox streetHBox = new HBox(55);
		HBox cityHBox = new HBox(66);
		HBox stateHBox = new HBox(60);
		HBox zipHBox = new HBox(70);
		
		//******************************************************
		// Declaring and calling new on an instance of VBox
		// so that each HBox for each piece of a customer's information
		// can be added to it so that it is output in a vertical position.
		//******************************************************
		VBox customerVBox = new VBox(15);
		
		// Calling new on the first name instance of TextField.
		firstNameTextField = new TextField();
		// Declaring and calling new on the "First Name" label.
		Label firstNameLabel = new Label("First Name");
		
		// Calling new on the last name instance of TextField.
		lastNameTextField = new TextField();
		// Declaring and calling new on the "Last Name" label.
		Label lastNameLabel = new Label("Last Name");
		
		// Calling new on the number instance of TextField.
		numberTextField = new TextField();
		// Declaring and calling new on the "Number" label.
		Label numberLabel = new Label("Number");
		
		// Calling new on the street instance of TextField.
		streetTextField = new TextField();
		// Declaring and calling new on the "Street" label.
		Label streetLabel = new Label("Street");
		
		// Calling new on the city instance of TextField.
		cityTextField = new TextField();
		// Declaring and calling new on the "City" label.
		Label cityLabel = new Label("City");
		
		// Calling new on the state instance of TextField.
		stateTextField = new TextField();
		// Declaring and calling new on the "State" label.
		Label stateLabel = new Label("State");
		
		// Calling new on the zip instance of TextField.
		zipTextField = new TextField();
		// Declaring and calling new on the "Zip" label.
		Label zipLabel = new Label("Zip");
		
		// Adding the first name label to the first name HBox.
		firstNameHBox.getChildren().add(firstNameLabel);
		// Adding the first name text field to the first name HBox.
		firstNameHBox.getChildren().add(firstNameTextField);
		//******************************************************
		// Adding the first name HBox to the first name VBox so the horizontal label and text field will
		// vertically align with the Customer tab's other labels and text fields.
		//******************************************************
		customerVBox.getChildren().add(firstNameHBox);
		
		// Adding the last name label to the last name HBox.
		lastNameHBox.getChildren().add(lastNameLabel);
		// Adding the last name text field to the last name HBox.
		lastNameHBox.getChildren().add(lastNameTextField);
		//******************************************************
		// Adding the last name HBox to the last name VBox so the horizontal label and text field will
		// vertically align with the Customer tab's other labels and text fields.
		//******************************************************
		customerVBox.getChildren().add(lastNameHBox);
		
		// Adding the number label to the number HBox.
		numberHBox.getChildren().add(numberLabel);
		// Adding the number text field to the number HBox.
		numberHBox.getChildren().add(numberTextField);
		//******************************************************
		// Adding the number HBox to the number VBox so the horizontal label and text field will
		// vertically align with the Customer tab's other labels and text fields.
		//******************************************************
		customerVBox.getChildren().add(numberHBox);
		
		// Adding the street label to the street HBox.
		streetHBox.getChildren().add(streetLabel);
		// Adding the street text field to the street HBox.
		streetHBox.getChildren().add(streetTextField);
		//******************************************************
		// Adding the street HBox to the street VBox so the horizontal label and text field will
		// vertically align with the Customer tab's other labels and text fields.
		//******************************************************
		customerVBox.getChildren().add(streetHBox);
		
		// Adding the city label to the city HBox.
		cityHBox.getChildren().add(cityLabel);
		// Adding the city text field to the city HBox.
		cityHBox.getChildren().add(cityTextField);
		//******************************************************
		// Adding the city HBox to the city VBox so the horizontal label and text field will
		// vertically align with the Customer tab's other labels and text fields.
		//******************************************************
		customerVBox.getChildren().add(cityHBox);
		
		// Adding the state label to the state HBox.
		stateHBox.getChildren().add(stateLabel);
		// Adding the state text field to the state name HBox.
		stateHBox.getChildren().add(stateTextField);
		//******************************************************
		// Adding the state HBox to the state VBox so the horizontal label and text field will
		// vertically align with the Customer tab's other labels and text fields.
		//******************************************************
		customerVBox.getChildren().add(stateHBox);
		
		// Adding the zip label to the zip HBox.
		zipHBox.getChildren().add(zipLabel);
		// Adding the zip text field to the zip HBox.
		zipHBox.getChildren().add(zipTextField);
		//******************************************************
		// Adding the zip HBox to the zip VBox so the horizontal label and text field will
		// vertically align with the Customer tab's other labels and text fields.
		//******************************************************
		customerVBox.getChildren().add(zipHBox);
		
		// Passing customerVBox into setContent so that the customerVBox is the root of the customer tab.
		customerTab.setContent(customerVBox);
		// Setting the customer tab as not being able to be closed.
		customerTab.setClosable(false);
		
		// Returning the customer tab.
		return customerTab;
	}
	
	/**
	 * The CreatePurchasesTab method creates the purchases tab by declaring and calling
	 * new on an instance of Tab. The purchases tab returned by this method also has
	 * an instance of ListView as the tab's root so that when the tab is populated by
	 * the Purchase data contained in a file, each purchase will be displayed on an individual line.
	 * The purchases tab returned by this method can be added to an instance of TabPane.
	 * @return purchasesTab The Purchases tab.
	 */
	private Tab CreatePurchasesTab()
	{
		//******************************************************
		// Declaring and calling new on the purchasesTab instance of Tab 
		// and setting the text of the tab as "Purchases".
		//******************************************************
		Tab purchasesTab = new Tab("Purchases");
		
		// Setting the instance of ObservableList equal to an observableArrayList.
		item = FXCollections.observableArrayList();
		//******************************************************
		// Calling new on the instance of ListView and passing the instance of ObservableList
		// into it so that the items of ObervableList are added to the ListView.
		//******************************************************
		purchasesList = new ListView<>(item);
		// Clearing the items of purchasesList so that a white screen is initially output in the purchases tab.
		purchasesList.getItems().clear();
		
		// Passing purchasesList into setContent so that purchasesList is the root of the purchases tab.
		purchasesTab.setContent(purchasesList);
		// Setting the orientation of the purchasesList to vertical.
		purchasesList.setOrientation(Orientation.VERTICAL);
		// Setting the purchases tab as not being able to be closed.
		purchasesTab.setClosable(false);
		
		// Returning the purchases tab.
		return purchasesTab;
	}
}