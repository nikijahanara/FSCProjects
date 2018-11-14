//******************************************************
// File: MainWindow.xaml.cs
//
// Purpose: To contain the business logic for the MainWindow class.
//          Within this MainWindow partial class are the definitions for the default constructor, event handlers
//          for the Star Wars DB GUI's "Planets" and "Add New Planet" tabs, and methods.
//          The default constructor initializes the class's private member variables and defines the connection string
//          to the Star Wars database that this program relies on to retrieve data from.
//          The definitions for the event handlers of the "Planets" tab establishs an open connection to the Star Wars database
//          when the Star Wars DB GUI's window loads, allows the user to import PlanetCollection data from either a XML file or a JSON file, 
//          retrieves PlanetCollection data and populates the Star Wars DB GUI's TextBoxes and ListBoxes with data that is dependent
//          on the user's Planet name selection from the Planet Names ListBox, opens a MessageBox with details about the name, 
//          version, and author of the program, and allow the user to exit from the Star Wars DB GUI.
//          The definitions for the event handlers of the "Add New Planet" tab allow the user add a new Planet to the
//          Star Wars database after filling out the Planet textboxes and entering values into the Films and Residents ListBoxes,
//          and also refresh the Planet Names ListBox on the "Planets" tab after a new Planet has been added to the Star Wars database.
//          The definitions for the methods clear the Planets, Films, and Residents tables in the the Star Wars database of data, insert data into each
//          of the three aforementioned tables in the Star Wars database from the data contained in an instance of PlanetCollection, and refresh the
//          Planet Names ListBox on the "Planets" tab in order for the Planet Names ListBox Items to accurately represent all of Planets in the Star Wars database.
//
// Written By: Niki Jahanara
//
// Compiler: Visual Studio 2015
//
//******************************************************

//******************************************************
// By using the Microsoft.Win32 namespace, 
// instances of the OpenFileDialog class can be created in this class.
//******************************************************
using Microsoft.Win32;
//******************************************************
// By using the StarWarsNamespace, an instance of PlanetCollection can be created and
// methods from the imported StarWarsLibrary can be called from within this class.
//******************************************************
using StarWarsNamespace;
using System;
using System.Collections.Generic;
//******************************************************
// By using the System.Data.SqlClient namespace, instances
// of SqlCommand can be created so that SQL commands can be executed.
//******************************************************
using System.Data.SqlClient;
//******************************************************
// By using the System.IO namespace, the GetCurrentDirectory
// method can be called from the Directory class in this class.
//******************************************************
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

//****************************************************
// The MainWindow class is inside the StarWarsDBGUI namespace because
// it helps prevent naming collisions and it provides
// a way to organize the classes within StarWarsDBGUI.
//****************************************************
namespace StarWarsDBGUI
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        #region Private Member Variables
        // Declaring an instance of PlanetCollection.
        private PlanetCollection pc;
        // Declaring an instance of SqlConnection.
        private SqlConnection sqlConn;
        private string connString;
        #endregion

        #region Default Constructor
        //****************************************************
        // Method: MainWindow
        //
        // Purpose: To be the default constructor, to initialize the StarWarsDB GUI objects,
        //          and to initialize the MainWindow partial class's private member variables.
        //****************************************************
        public MainWindow()
        {
            //****************************************************
            // Calling the InitializeComponent method within the
            // default constructor of the MainWindow partial class
            // so that the objects of the StarWarsDB GUI are initialized.
            //****************************************************
            InitializeComponent();

            // Initializing the instance of PlanetCollection.
            pc = new PlanetCollection();

            //****************************************************
            // Assigning the connString private member variable the
            // connection string to the Star Wars database so that
            // it can be used to open a connection.
            // MultipleActiveResultSets is also set to "True" within the connection
            // string so that multiple SQL statements can be executed within the program
            // after opening the connection to the database one time.
            //****************************************************
            connString = @"server = (localdb)\MSSQLLocalDB;" +
            "integrated security = SSPI;" + "database = StarWars;" + "MultipleActiveResultSets=True";

            //****************************************************
            // Initilizing the instance of SqlConnection by calling new and
            // passing connString into it in order to open the connection
            // to the Star Wars database specified in the connString.
            //****************************************************
            sqlConn = new SqlConnection(connString);
        }
        #endregion

        #region Planets Tab Event Handlers
        //****************************************************
        // Method: Window_Loaded
        //
        // Purpose: To be the event handler for the Window_Loaded event. 
        //          As soon as the window for the StarWarsDB GUI loads, the connection
        //          to the Star Wars database is opened so that the SQL commands
        //          in other event handlers and methods for the StarWarsDB GUI can be executed.
        //****************************************************
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            //****************************************************
            // Opening the connection to the Star Wars database through
            // a call to Open from sqlConn, which is an instance of SqlConnection.
            //****************************************************
            sqlConn.Open();
        }

        //****************************************************
        // Method: ImportFromXMLFile_Click
        //
        // Purpose: To be the event handler for the ImportFromXMLFile MenuItem on the StarWarsDB GUI.
        //          This event handler opens an open file dialog so that the user can select only a
        //          XML file containing PlanetCollection data.
        //          If the user sucessfully selects a XML file containing PlanetCollection data,
        //          the Star Wars database will be cleared first before its three tables (Planets, Films, Residents)
        //          are populated with the data from the PlanetCollection XML file.
        //          Next, a call to the RefreshListBoxMethod is made so that the names of the Planets that are in
        //          the Planets table, after opening a XML file, populate the planetNamesListBox in the "Planets" tab.
        //****************************************************
        private void ImportFromXMLFile_Click(object sender, RoutedEventArgs e)
        {
            //****************************************************
            // Declaring and initializing an instance of OpenFileDialog
            // for the "Import From XML File..." MenuItem that users 
            // will click in order to open a dialog to select a XML file from.
            //****************************************************
            OpenFileDialog openFileDialogXML = new OpenFileDialog();

            //****************************************************
            // Setting the inital directory of the OpenFileDialog instance
            // to the current working directory by calling the 
            // GetCurrentDirectory method from the Directory class.
            //****************************************************
            openFileDialogXML.InitialDirectory = Directory.GetCurrentDirectory();

            // Setting the title of the OpenFileDialog instance to reflect its purpose: to open a PlanetCollection XML file.
            openFileDialogXML.Title = "Open Star Wars PlanetCollection XML File";

            // Filtering the OpenFileDialog to only show files that have a .xml extension.
            openFileDialogXML.Filter = "XML Files (*.xml)|*.xml";

            //****************************************************
            // If the ShowDialog method returns true, then it means that the 
            // OpenFileDialog instance has successfully opened a XML file.
            // The xmlFileName variable is then set equal to the 
            // file name that the OpenFileDialog instance opened.
            //****************************************************
            if (openFileDialogXML.ShowDialog() == true)
            {
                // Setting xmlFileName equal to the FileName of the instance of OpenFileDialog.
                string xmlFileName = openFileDialogXML.FileName;

                //****************************************************
                // Passing an instance of PlanetCollection and the xmlFileName variable
                // into a call to PlanetCollectionXMLDeserialization method so that the
                // PlanetCollection values in the XML file can be deserialized into
                // the member variable values of the instance of PlanetCollection.
                //****************************************************
                pc.PlanetCollectionXMLDeserialization(ref pc, xmlFileName);

                //****************************************************
                // A call to the ClearOutStarWarsDB method is made so that all the data
                // in each of the Star Wars database's tables (Planets, Films, Residents)
                // is deleted and cleared out before the PlanetCollection data from the XML
                // file is inserted into each table in the Star Wars database.
                //****************************************************
                ClearOutStarWarsDB();

                //****************************************************
                // A call to the InsertIntoPlanetsTable method is made so that the
                // data for the Planet attributes in the XML file are inserted
                // into the Planets table in the Star Wars database.
                //****************************************************
                InsertIntoPlanetsTable();

                //****************************************************
                // A call to the InsertIntoFilmsTable method is made so that the
                // data for the Film attributes in the XML file are inserted
                // into the Films table in the Star Wars database.
                //****************************************************
                InsertIntoFilmsTable();

                //****************************************************
                // A call to the InsertIntoResidentsTable method is made so that the
                // data for the Resident attributes in the XML file are inserted
                // into the Residents table in the Star Wars database.
                //****************************************************
                InsertIntoResidentsTable();

                //****************************************************
                // A call to the RefreshPlanetNamesListBox method is made so that the
                // planetNamesListBox can be populated with all the Planet names
                // that are in the Planets table from the XML file in the Star Wars database.
                //****************************************************
                RefreshPlanetNamesListBox();

                //****************************************************
                // Updating the title of the window after the user opens a PlanetCollection XML file so that
                // they know the data being displayed on the Star Wars DB GUI is from a XML file.
                //****************************************************
                this.Title = "Star Wars Planets DB - Written By Niki Jahanara - Data From XML File";
            }
        }

        //****************************************************
        // Method: ImportFromJSONFile_Click
        //
        // Purpose: To be the event handler for the ImportFromJSONFile MenuItem on the StarWarsDB GUI.
        //          This event handler opens an open file dialog so that the user can select only a
        //          JSON file containing PlanetCollection data.
        //          If the user sucessfully selects a JSON file containing PlanetCollection data,
        //          the Star Wars database will be cleared first before its three tables (Planets, Films, Residents)
        //          are populated with the data from the PlanetCollection JSON file.
        //          Next, a call to the RefreshListBoxMethod is made so that the names of the Planets that are in
        //          the Planets table, after opening a JSON file, populate the planetNamesListBox in the "Planets" tab.
        //****************************************************
        private void ImportFromJSONFile_Click(object sender, RoutedEventArgs e)
        {
            //****************************************************
            // Declaring and initializing an instance of OpenFileDialog
            // for the "Import From JSON File..." MenuItem that users 
            // will click in order to open a dialog to select a JSON file from.
            //****************************************************
            OpenFileDialog openFileDialogJSON = new OpenFileDialog();

            //****************************************************
            // Setting the inital directory of the OpenFileDialog instance
            // to the current working directory by calling the 
            // GetCurrentDirectory method from the Directory class.
            //****************************************************
            openFileDialogJSON.InitialDirectory = Directory.GetCurrentDirectory();

            // Setting the title of the OpenFileDialog instance to reflect its purpose: to open a PlanetCollection JSON file.
            openFileDialogJSON.Title = "Open Star Wars PlanetCollection JSON File";

            // Filtering the OpenFileDialog to only show files that have a .json extension.
            openFileDialogJSON.Filter = "JSON Files (*.json)|*.json";

            //****************************************************
            // If the ShowDialog method returns true, then it means that the 
            // OpenFileDialog instance has successfully opened a JSON file.
            // The jsonFileName variable is then set equal to the 
            // file name that the OpenFileDialog instance opened.
            //****************************************************
            if (openFileDialogJSON.ShowDialog() == true)
            {
                // Setting jsonFileName equal to the FileName of the instance of OpenFileDialog.
                string jsonFileName = openFileDialogJSON.FileName;

                //****************************************************
                // Passing an instance of PlanetCollection and the jsonFileName variable
                // into a call to PlanetCollectionJSONDeserialization method so that the
                // PlanetCollection values in the JSON file can be deserialized into
                // the member variable values of the instance of PlanetCollection.
                //****************************************************
                pc.PlanetCollectionJSONDeserialization(ref pc, jsonFileName);

                //****************************************************
                // A call to the ClearOutStarWarsDB method is made so that all the data
                // in each of the Star Wars database's tables (Planets, Films, Residents)
                // is deleted and cleared out before the PlanetCollection data from the JSON
                // file is inserted into each table in the Star Wars database.
                //****************************************************
                ClearOutStarWarsDB();

                //****************************************************
                // A call to the InsertIntoPlanetsTable method is made so that the
                // data for the Planet attributes in the JSON file are inserted
                // into the Planets table in the Star Wars database.
                //****************************************************
                InsertIntoPlanetsTable();

                //****************************************************
                // A call to the InsertIntoFilmsTable method is made so that the
                // data for the Film attributes in the JSON file are inserted
                // into the Films table in the Star Wars database.
                //****************************************************
                InsertIntoFilmsTable();

                //****************************************************
                // A call to the InsertIntoResidentsTable method is made so that the
                // data for the Resident attributes in the JSON file are inserted
                // into the Residents table in the Star Wars database.
                //****************************************************
                InsertIntoResidentsTable();

                //****************************************************
                // A call to the RefreshPlanetNamesListBox method is made so that the
                // planetNamesListBox can be populated with all the Planet names
                // that are in the Planets table from the JSON file in the Star Wars database.
                //****************************************************
                RefreshPlanetNamesListBox();

                //****************************************************
                // Updating the title of the window after the user opens a PlanetCollection JSON file so that
                // they know the data being displayed on the StarWarsDB GUI is from a JSON file.
                //****************************************************
                this.Title = "Star Wars Planets DB - Written By Niki Jahanara - Data From JSON File";
            }
        }

        //****************************************************
        // Method: planetNamesListBox_SelectionChanged
        //
        // Purpose: To be the event handler for the SelectionChanged event for the planetNamesListBox.
        //          Every time the user clicks on a Planet Name that is displayed in the planetNamesListBox,
        //          this event handler makes it so that every Planet, Film, and Resident attribute relating
        //          to the Planet that the user clicked is selected from the Planets, Films, and Residents
        //          tables in the Star Wars database and is displayed either in the appropriate
        //          textbox or listbox on the "Planets" tab for every Planet Name the user clicks on.
        //****************************************************
        private void planetNamesListBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            //****************************************************
            // If the SelectedValue property of the planetNamesListBox is null, then nothing is returned.
            // This prevents the program from crashing when switching between
            // importing PlanetCollection data from a JSON or XML file.
            //****************************************************
            if (planetNamesListBox.SelectedValue == null)
            {
                return;
            }

            //****************************************************
            // The selectAllPlanetAttributes string is assigned a SQL command that selects every attribute
            // from the Planets table where the Name field is equal to the
            // SelectedValue property of the planetNamesListBox,
            // which is the Planet name that the user clicked on in the planetNamesListBox.
            //****************************************************
            string selectAllPlanetAttributes = "SELECT * FROM Planets WHERE Name = '" + planetNamesListBox.SelectedValue.ToString() + "'";

            //****************************************************
            // An instance of SqlCommand is declared and initialized by
            // passing in the selectAllPlanetAttributes string, which holds a SQL SELECT command, 
            // and the instance of SqlConnection, sqlConn.
            //****************************************************
            SqlCommand selectAllPlanetAttributesCommand = new SqlCommand(selectAllPlanetAttributes, sqlConn);

            //****************************************************
            // An instance of SqlDataReader is declared and is assigned
            // the data that is returned after the instance of SqlCommand,
            // selectAllPlanetAttributesCommand, is executed through a call to the ExecuteReader method.
            //****************************************************
            SqlDataReader planetDataReader = selectAllPlanetAttributesCommand.ExecuteReader();

            //****************************************************
            // While the instance of SqlDataReader, planetDataReader, iterates through
            // all the records contained within it, the nested for loop within the while loop
            // iterates through all fields of the current record and assigns the data
            // within each column of the Planets table to its respective TextBox 
            // through a call to each column's ToString. The data is then displayed 
            // on each Planet TextBox on the StarWarsDB GUI.
            //****************************************************
            while (planetDataReader.Read())
            {
                //****************************************************
                // The for loop iterates through each field in the current record
                // of planetDataReader's records and assigns the data contained in each Planet column to its
                // respective TextBox on the StarWarsDB GUI through a call to ToString.
                //****************************************************
                for (int i = 0; i < planetDataReader.FieldCount; i++)
                {
                    //****************************************************
                    // Assigning the Text of the nameTextBox to the ToString string representation
                    // of the data in the Name column of the planetDataReader's record.
                    //****************************************************
                    nameTextBox.Text = planetDataReader["Name"].ToString();
                    //****************************************************
                    // Assigning the Text of the rotationPeriodTextBox to the ToString string representation
                    // of the data in the RotationPeriod column of the planetDataReader's record.
                    //****************************************************
                    rotationPeriodTextBox.Text = planetDataReader["RotationPeriod"].ToString();
                    //****************************************************
                    // Assigning the Text of the orbitalPeriodTextBox to the ToString string representation
                    // of the data in the OrbitalPeriod column of the planetDataReader's record.
                    //****************************************************
                    orbitalPeriodTextBox.Text = planetDataReader["OrbitalPeriod"].ToString();
                    //****************************************************
                    // Assigning the Text of the diameterTextBox to the ToString string representation
                    // of the data in the Diameter column of the planetDataReader's record.
                    //****************************************************
                    diameterTextBox.Text = planetDataReader["Diameter"].ToString();
                    //****************************************************
                    // Assigning the Text of the climateTextBox to the ToString string representation
                    // of the data in the Climate column of the planetDataReader's record.
                    //****************************************************
                    climateTextBox.Text = planetDataReader["Climate"].ToString();
                    //****************************************************
                    // Assigning the Text of the gravityTextBox to the ToString string representation
                    // of the data in the Gravity column of the planetDataReader's record.
                    //****************************************************
                    gravityTextBox.Text = planetDataReader["Gravity"].ToString();
                    //****************************************************
                    // Assigning the Text of the terrainTextBox to the ToString string representation
                    // of the data in the Terrain column of the planetDataReader's record.
                    //****************************************************
                    terrainTextBox.Text = planetDataReader["Terrain"].ToString();
                    //****************************************************
                    // Assigning the Text of the surfaceWaterTextBox to the ToString string representation
                    // of the data in the SurfaceWater column of the planetDataReader's record.
                    //****************************************************
                    surfaceWaterTextBox.Text = planetDataReader["SurfaceWater"].ToString();
                    //****************************************************
                    // Assigning the Text of the populationTextBox to the ToString string representation
                    // of the data in the Population column of the planetDataReader's record.
                    //****************************************************
                    populationTextBox.Text = planetDataReader["Population"].ToString();
                    //****************************************************
                    // Assigning the Text of the createdTextBox to the ToString string representation
                    // of the data in the Created column of the planetDataReader's record.
                    //****************************************************
                    createdTextBox.Text = planetDataReader["Created"].ToString();
                    //****************************************************
                    // Assigning the Text of the editedTextBox to the ToString string representation
                    // of the data in the Edited column of the planetDataReader's record.
                    //****************************************************
                    editedTextBox.Text = planetDataReader["Edited"].ToString();
                    //****************************************************
                    // Assigning the Text of the urlTextBox to the ToString string representation
                    // of the data in the Url column of the planetDataReader's record.
                    //****************************************************
                    urlTextBox.Text = planetDataReader["URL"].ToString();
                }
            }

            //****************************************************
            // The selectFilmLink string is assigned a SQL command that selects
            // the FilmLink attribute from the Films table 
            // where the Name field is equal to the
            // SelectedValue property of the planetNamesListBox,
            // which is the Planet name that the user clicked on the planetNamesListBox.
            //****************************************************
            string selectFilmLink = "SELECT FilmLink FROM Films WHERE Name = '" + planetNamesListBox.SelectedValue.ToString() + "'";

            //****************************************************
            // An instance of SqlCommand is declared and initialized by
            // passing in the selectFilmLink string, which holds a SQL SELECT command, 
            // and the instance of SqlConnection, sqlConn.
            //****************************************************
            SqlCommand selectFilmLinkCommand = new SqlCommand(selectFilmLink, sqlConn);

            //****************************************************
            // An instance of SqlDataReader is declared and is assigned
            // the data that is returned after the instance of SqlCommand,
            // selectFilmLinkCommand, is executed through a call to the ExecuteReader method.
            //****************************************************
            SqlDataReader filmReader = selectFilmLinkCommand.ExecuteReader();

            //****************************************************
            // Setting the ItemSource property of the filmsListBox
            // on the "Planets" tab of the StarWarsDB GUI equal to
            // filmReader, so that the filmsListBox can retrieve
            // data to display from the filmReader.
            //****************************************************
            filmsListBox.ItemsSource = filmReader;

            //****************************************************
            // Setting the DisplayMemberPath property of the
            // filmsListBox on the "Planets" tab of the StarWarsDB GUI
            // equal to the FilmLink column so that the data
            // contained in the FilmLink column will be displayed
            // in the filmsListBox for each Planet that the user selects 
            // from the planetNamesListBox.
            //****************************************************
            filmsListBox.DisplayMemberPath = "FilmLink";

            //****************************************************
            // The selectResidentLink string is assigned a SQL command that selects
            // the ResidentLink attribute from the Residents
            // table where the Name field is equal to the
            // SelectedValue property of the planetNamesListBox,
            // which is the Planet name that the user clicked on the planetNamesListBox.
            //****************************************************
            string selectResidentLink = "SELECT ResidentLink FROM Residents WHERE Name = '" + planetNamesListBox.SelectedValue.ToString() + "'";

            //****************************************************
            // An instance of SqlCommand is declared and initialized by
            // passing in the selectResidentLink string, which holds a SQL SELECT command, 
            // and the instance of SqlConnection, sqlConn.
            //****************************************************
            SqlCommand selectResidentLinkCommand = new SqlCommand(selectResidentLink, sqlConn);

            //****************************************************
            // An instance of SqlDataReader is declared and is assigned
            // the data that is returned after the instance of SqlCommand,
            // selectResidentLinkCommand, is executed through a call to the ExecuteReader method.
            //****************************************************
            SqlDataReader residentReader = selectResidentLinkCommand.ExecuteReader();

            //****************************************************
            // Setting the ItemSource property of the residentsListBox
            // on the "Planets" tab of the StarWarsDB GUI equal to
            // residentReader, so that the residentsListBox can retrieve
            // data to display from the residentReader.
            //****************************************************
            residentsListBox.ItemsSource = residentReader;

            //****************************************************
            // Setting the DisplayMemberPath property of the
            // residentsListBox on the "Planets" tab of the StarWarsDB GUI
            // equal to the ResidentLink column so that the data
            // contained in the ResidentLink column will be displayed
            // in the residentsListBox for each Planet that the user selects
            // from the planetNamesListBox.
            //****************************************************
            residentsListBox.DisplayMemberPath = "ResidentLink"; 
        }

        //****************************************************
        // Method: About_Click
        //
        // Purpose: To be the event handler for the About MenuItem.
        //          When the user clicks on "About...", this event handler
        //          will make it so that a MessageBox with information
        //          about the Star Wars Planets DB program will be output.
        //****************************************************
        private void About_Click(object sender, RoutedEventArgs e)
        {
            // The MessageBox contains information on the name, version, and author of the Star Wars Planets DB program.
            MessageBox.Show("Star Wars Planets DB\nVersion 1.0\nWritten by Niki Jahanara", "About Star Wars Planets DB");
        }

        //****************************************************
        // Method: Exit_Click
        //
        // Purpose: To be the event handler for the Exit MenuItem.
        //          When the user clicks on "Exit.", this event handler
        //          will make it so that the window closes.
        //****************************************************
        private void Exit_Click(object sender, RoutedEventArgs e)
        {
            // Closes the window through a call to the Close method.
            Close();
        }
        #endregion

        #region Add New Planet Tab Event Handlers
        //****************************************************
        // Method: addFilmButton_click
        //
        // Purpose: To be the event handler for the addFilmButton.
        //          When the user clicks on the addFilmButton in the "Add New Planet" tab, 
        //          this event handler will make it so that text in the addNewFilmTextBox
        //          is added to the addNewFilmListBox before clearing the addNewFilmTextBox's text.
        //****************************************************
        private void addFilmButton_click(object sender, RoutedEventArgs e)
        {
            //****************************************************
            // The text in the addNewFilmTextBox is added to the addNewFilmListBox
            // by passing addNewFilmTextBox.Text into a call to the instance of ListBox's Add method.
            //****************************************************
            addNewFilmListBox.Items.Add(addNewFilmTextBox.Text);
            // Clearing the addNewFilmTextBox after the addFilmButton is pressed.
            addNewFilmTextBox.Clear();
        }

        //****************************************************
        // Method: addResidentButton_click
        //
        // Purpose: To be the event handler for the addResidentButton.
        //          When the user clicks on the addResidentButton in the "Add New Planet" tab, 
        //          this event handler will make it so that text in the addNewResidentTextBox
        //          is added to the addNewResidentListBox before clearing the addNewResidentTextBox's text.
        //****************************************************
        private void addResidentButton_click(object sender, RoutedEventArgs e)
        {
            //****************************************************
            // The text in the addNewResidentTextBox is added to the addNewResidentListBox
            // by passing addNewResidentTextBox.Text into a call to the instance of ListBox's Add method.
            //****************************************************
            addNewResidentListBox.Items.Add(addNewResidentTextBox.Text);
            // Clearing the addNewResidentTextBox after the addFilmButton is pressed.
            addNewResidentTextBox.Clear();
        }

        //****************************************************
        // Method: insertPlanetButton_click
        //
        // Purpose: To be the event handler for the insertPlanetButton.
        //          When the user clicks on the insertPlanetButton in the "Add New Planet" tab, 
        //          this event handler will make it so that three separate INSERT statements
        //          that each add the data that the user entered into the Planet attribute TextBoxes,
        //          addNewFilmListBox, and addNewResidentListBox, are executed so that
        //          the data that the user entered is placed into the Planets, Films,
        //          and Residents tables in the Star Wars database.
        //****************************************************
        private void insertPlanetButton_click(object sender, RoutedEventArgs e)
        {
            //****************************************************
            // The insertNewPlanet string is assigned a SQL command that INSERTs
            // the Text property of all the 12 Planet attribute TextBoxes
            // into the Planets table in the Star Wars database.
            //****************************************************
            string insertNewPlanet = string.Format(
                "INSERT INTO Planets" +
                "(Name, RotationPeriod, OrbitalPeriod, Diameter, Climate, Gravity, Terrain, SurfaceWater, Population, Created, Edited, Url) Values" +
                "('{0}', '{1}', '{2}', '{3}', '{4}', '{5}', '{6}', '{7}', '{8}', '{9}', '{10}', '{11}')",
                addNameTextBox.Text, addRotationPeriodTextBox.Text, addOrbitalPeriodTextBox.Text, addDiameterTextBox.Text, addClimateTextBox.Text, addGravityTextBox.Text,
                addTerrainTextBox.Text, addSurfaceWaterTextBox.Text, addPopulationTextBox.Text, addCreatedTextBox.Text, addEditedTextBox.Text, addUrlTextBox.Text);

            //****************************************************
            // An instance of SqlCommand is declared and initialized by
            // passing in the insertNewPlanet string, which holds a SQL INSERT command, 
            // and the instance of SqlConnection, sqlConn.
            //****************************************************
            SqlCommand insertNewPlanetCommand = new SqlCommand(insertNewPlanet, sqlConn);

            //****************************************************
            // By calling ExecuteNonQuery from insertNewPlanetCommand,
            // which is an instance of SqlCommand, the command
            // is executed and the Planet data is added to
            // the Planet table in the Star Wars database.
            //****************************************************
            insertNewPlanetCommand.ExecuteNonQuery();

            //****************************************************
            // A for loop is needed to add the Items in the addNewFilmListBox
            // to the Star Wars database because multiple Items in the 
            // addNewFilmListBox may need to be added to the Star Wars database 
            // depending on the Film data that the user entered.
            // A for loop can therefore add each Item in the addNewFilmListBox
            // as a seperate record into the Films table in the Star Wars database.
            //****************************************************
            for (int i = 0; i < addNewFilmListBox.Items.Count; i++)
            {
                //****************************************************
                // The insertNewFilm string is assigned a SQL command that INSERTs
                // the Text property of the addNameTextBox, representing the new Planet's name,
                // and the ToString representation of each Item in the addNewFilmListBox
                // into the Films table in the Star Wars database.
                //****************************************************
                string insertNewFilm = string.Format(
                        "INSERT INTO Films" +
                        "(Name, FilmLink) Values" +
                        "('{0}', '{1}')", addNameTextBox.Text, addNewFilmListBox.Items[i].ToString());

                //****************************************************
                // An instance of SqlCommand is declared and initialized by
                // passing in the insertNewFilm string, which holds a SQL INSERT command, 
                // and the instance of SqlConnection, sqlConn.
                //****************************************************
                SqlCommand insertNewFilmCommand = new SqlCommand(insertNewFilm, sqlConn);

                //****************************************************
                // By calling ExecuteNonQuery from insertNewFilmCommand,
                // which is an instance of SqlCommand, the command
                // is executed and the Film data is added to
                // the Films table in the Star Wars database.
                //****************************************************
                insertNewFilmCommand.ExecuteNonQuery();
            }

            //****************************************************
            // A for loop is needed to add the Items in the addNewResidentListBox
            // to the Star Wars database because multiple Items in the addNewResidentListBox
            // may need to be added to the Star Wars database depending on 
            // the Resident data that the user entered.
            // A for loop can therefore add each Item in the addNewResidentListBox
            // as a seperate record into the Residents table in the Star Wars database.
            //****************************************************
            for (int i = 0; i < addNewResidentListBox.Items.Count; i++)
            {
                //****************************************************
                // The insertNewResident string is assigned a SQL command that INSERTs
                // the Text property of the addNameTextBox, representing the new Planet's name,
                // and the ToString representation of each Item in the addNewResidentListBox
                // into the Residents table in the Star Wars database.
                //****************************************************
                string insertNewResident = string.Format(
                        "INSERT INTO Residents" +
                        "(Name, ResidentLink) Values" +
                        "('{0}', '{1}')", addNameTextBox.Text, addNewResidentListBox.Items[i].ToString());

                //****************************************************
                // An instance of SqlCommand is declared and initialized by
                // passing in the insertNewResident string, which holds a SQL INSERT command, 
                // and the instance of SqlConnection, sqlConn.
                //****************************************************
                SqlCommand insertNewResidentCommand = new SqlCommand(insertNewResident, sqlConn);

                //****************************************************
                // By calling ExecuteNonQuery from insertNewResidentCommand,
                // which is an instance of SqlCommand, the command
                // is executed and the Resident data is added to
                // the Residents table in the Star Wars database.
                //****************************************************
                insertNewResidentCommand.ExecuteNonQuery();
            }

            //****************************************************
            // Clearing the text from each TextBox on the
            // "Add New Planet" tab after the user clicks the insertPlanetButton.
            //****************************************************
            addNameTextBox.Clear();
            addRotationPeriodTextBox.Clear();
            addOrbitalPeriodTextBox.Clear();
            addDiameterTextBox.Clear();
            addClimateTextBox.Clear();
            addGravityTextBox.Clear();
            addTerrainTextBox.Clear();
            addSurfaceWaterTextBox.Clear();
            addPopulationTextBox.Clear();
            addCreatedTextBox.Clear();
            addEditedTextBox.Clear();
            addUrlTextBox.Clear();

            //****************************************************
            // Clearing the Items from the addNewFilmListBox on the
            // "Add New Planet" tab after the user clicks the insertPlanetButton.
            //****************************************************
            addNewFilmListBox.Items.Clear();

            //****************************************************
            // Clearing the Items from the addNewResidentListBox on the
            // "Add New Planet" tab after the user clicks the insertPlanetButton.
            //****************************************************
            addNewResidentListBox.Items.Clear();

            //****************************************************
            // After adding a new Planet to the Star Wars database,
            // a call to RefreshPlanetNamesListBox must be made so that
            // the planetNamesListBox in the "Planet"s tab is refreshed
            // and updated to show the new Planet that was added to
            // the Star Wars database by the user.
            //****************************************************
            RefreshPlanetNamesListBox();
        }
        #endregion

        #region Methods
        //****************************************************
        // Method: ClearOutStarWarsDB
        //
        // Purpose: To clear the Planets, Films, and Residents table of data
        //          through the execution of three separate DELETE statements for each table.
        //****************************************************
        private void ClearOutStarWarsDB()
        {
            //****************************************************
            // The sqlDeletePlanets string is assigned a SQL command that DELETEs
            // all records and data from the Planets table in the Star Wars database.
            //****************************************************
            string sqlDeletePlanets = "DELETE FROM Planets";

            //****************************************************
            // An instance of SqlCommand is declared and initialized by
            // passing in the sqlDeletePlanets string, which holds a SQL DELETE command, 
            // and the instance of SqlConnection, sqlConn.
            //****************************************************
            SqlCommand deletePlanetsCommand = new SqlCommand(sqlDeletePlanets, sqlConn);

            //****************************************************
            // By calling ExecuteNonQuery from deletePlanetsCommand,
            // which is an instance of SqlCommand, the command
            // is executed and all Planets data is deleted from the Planets table.
            //****************************************************
            deletePlanetsCommand.ExecuteNonQuery();

            //****************************************************
            // The sqlDeleteFilms string is assigned a SQL command that DELETEs
            // all records and data from the Films table in the Star Wars database.
            //****************************************************
            string sqlDeleteFilms = "DELETE FROM Films";

            //****************************************************
            // An instance of SqlCommand is declared and initialized by
            // passing in the sqlDeleteFilms string, which holds a SQL DELETE command, 
            // and the instance of SqlConnection, sqlConn.
            //****************************************************
            SqlCommand deleteFilmsCommand = new SqlCommand(sqlDeleteFilms, sqlConn);

            //****************************************************
            // By calling ExecuteNonQuery from deleteFilmsCommand,
            // which is an instance of SqlCommand, the command
            // is executed and all Films data is deleted from the Films table.
            //****************************************************
            deleteFilmsCommand.ExecuteNonQuery();

            //****************************************************
            // The sqlDeleteResidents string is assigned a SQL command that DELETEs
            // all records and data from the Residents table in the Star Wars database.
            //****************************************************
            string sqlDeleteResidents = "DELETE FROM Residents";

            //****************************************************
            // An instance of SqlCommand is declared and initialized by
            // passing in the sqlDeleteResidents string, which holds a SQL DELETE command, 
            // and the instance of SqlConnection, sqlConn.
            //****************************************************
            SqlCommand deleteResidentsCommand = new SqlCommand(sqlDeleteResidents, sqlConn);

            //****************************************************
            // By calling ExecuteNonQuery from deleteResidentsCommand,
            // which is an instance of SqlCommand, the command
            // is executed and all Residents data is deleted from the Residents table.
            //****************************************************
            deleteResidentsCommand.ExecuteNonQuery();
        }

        //****************************************************
        // Method: InsertIntoPlanetsTable
        //
        // Purpose: To insert the Planets data that was deserialized into
        //          the instance of PlanetCollection into the
        //          Planets table in the Star Wars database.
        //****************************************************
        private void InsertIntoPlanetsTable()
        {
            //****************************************************
            // A for loop is used to loop through the Planet array within the instance of PlanetCollection
            // in order to INSERT each individual record of Planet data contained in the 
            // instance of PlanetCollection into the Planets table in the Star Wars database.
            //****************************************************
            for (int i = 0; i < pc.Results.Length; i++)
            {
                //****************************************************
                // The insertPlanets string is assigned a SQL command that INSERTs
                // each property of Planet within the instance of PlanetCollection
                // into the Planets table in the Star Wars database.
                //****************************************************
                string insertPlanets = string.Format(
                "INSERT INTO Planets" +
                "(Name, RotationPeriod, OrbitalPeriod, Diameter, Climate, Gravity, Terrain, SurfaceWater, Population, Created, Edited, Url) Values" +
                "('{0}', '{1}', '{2}', '{3}', '{4}', '{5}', '{6}', '{7}', '{8}', '{9}', '{10}', '{11}')",
                pc[i].Name, pc[i].RotationPeriod, pc[i].OrbitalPeriod, pc[i].Diameter, pc[i].Climate, pc[i].Gravity,
                pc[i].Terrain, pc[i].SurfaceWater, pc[i].Population, pc[i].Created, pc[i].Edited, pc[i].Url);

                //****************************************************
                // An instance of SqlCommand is declared and initialized by
                // passing in the insertPlanets string, which holds a SQL INSERT command, 
                // and the instance of SqlConnection, sqlConn.
                //****************************************************
                SqlCommand insertPlanetsCommand = new SqlCommand(insertPlanets, sqlConn);

                //****************************************************
                // By calling ExecuteNonQuery from insertPlanetsCommand,
                // which is an instance of SqlCommand, the command
                // is executed and the Planet data within the instance
                // of PlanetCollection is added to the Planets table in the Star Wars database.
                //****************************************************
                insertPlanetsCommand.ExecuteNonQuery();
            }
        }

        //****************************************************
        // Method: InsertIntoFilmsTable
        //
        // Purpose: To insert the Films data that was deserialized into
        //          the instance of PlanetCollection into the
        //          Films table in the Star Wars database.
        //****************************************************
        private void InsertIntoFilmsTable()
        {
            //****************************************************
            // A nested for loop must be used to add the Films data contained in the instance
            // of PlanetCollection because the Films data is contained inside of an array within PlanetCollection. 
            // Because it is an array within another array, a nested for loop must be used in order to be able to access Films data.
            //****************************************************
            for (int i = 0; i < pc.Results.Length; i++)
            {
                //****************************************************
                // The nested loop uses i, the int declared in the outside for loop,
                // to represent the index of PlanetCollection that the Films array is being accessed from.
                //****************************************************
                for (int j = 0; j < pc[i].Films.Length; j++)
                {
                    //****************************************************
                    // The insertFilms string is assigned a SQL command that INSERTs
                    // the name of the Planet and the Films the Planet appeared in, that is within the 
                    // instance of PlanetCollection, into the Films table in the Star Wars database.
                    //****************************************************
                    string insertFilms = string.Format(
                    "INSERT INTO Films" +
                    "(Name, FilmLink) Values" +
                    "('{0}', '{1}')",
                    pc[i].Name, pc[i].Films[j]);

                    //****************************************************
                    // An instance of SqlCommand is declared and initialized by
                    // passing in the insertFilms string, which holds a SQL INSERT command, 
                    // and the instance of SqlConnection, sqlConn.
                    //****************************************************
                    SqlCommand insertFilmsCommand = new SqlCommand(insertFilms, sqlConn);

                    //****************************************************
                    // By calling ExecuteNonQuery from insertFilmsCommand,
                    // which is an instance of SqlCommand, the command
                    // is executed and the Film data within the instance
                    // of PlanetCollection is added to the Films table in the Star Wars database.
                    //****************************************************
                    insertFilmsCommand.ExecuteNonQuery();
                }
            }
        }

        //****************************************************
        // Method: InsertIntoResidentsTable
        //
        // Purpose: To insert the Residents data that was deserialized into
        //          the instance of PlanetCollection into the
        //          Residents table in the Star Wars database.
        //****************************************************
        private void InsertIntoResidentsTable()
        {
            //****************************************************
            // A nested for loop must be used to add the Residents data contained in the instance
            // of PlanetCollection because the Residents data is contained inside of an array within PlanetCollection. 
            // Because it is an array within another array, a nested for loop must be used in order to be able to access the Residents data.
            //****************************************************
            for (int i = 0; i < pc.Results.Length; i++)
            {
                //****************************************************
                // The nested loop uses i, the int declared in the outside for loop,
                // to represent the index of PlanetCollection that the Residents array is being accessed from.
                //****************************************************
                for (int j = 0; j < pc[i].Residents.Length; j++)
                {
                    //****************************************************
                    // The insertResidents string is assigned a SQL command that INSERTs
                    // the name of the Planet and the Residents of the Planet, that is within the 
                    // instance of PlanetCollection, into the Residents table in the Star Wars database.
                    //****************************************************
                    string insertResidents = string.Format(
                    "INSERT INTO Residents" +
                    "(Name, ResidentLink) Values" +
                    "('{0}', '{1}')",
                    pc[i].Name, pc[i].Residents[j]);

                    //****************************************************
                    // An instance of SqlCommand is declared and initialized by
                    // passing in the insertResidents string, which holds a SQL INSERT command, 
                    // and the instance of SqlConnection, sqlConn.
                    //****************************************************
                    SqlCommand insertResidentsCommand = new SqlCommand(insertResidents, sqlConn);

                    //****************************************************
                    // By calling ExecuteNonQuery from insertResidentsCommand,
                    // which is an instance of SqlCommand, the command
                    // is executed and the Resident data within the instance
                    // of PlanetCollection is added to the Residents table in the Star Wars database.
                    //****************************************************
                    insertResidentsCommand.ExecuteNonQuery();
                }
            }
        }

        //****************************************************
        // Method: RefreshPlanetNamesListBox
        //
        // Purpose: To assign an instance of SqlDataReader that contains 
        //          the "Name" column from the Planets table in the Star Wars database
        //          as the ItemSource of planetNamesListBox so that the name for
        //          each Planet in the Planet table is displayed on the planetNamesListBox.
        //          An additional purpose of this method is to refresh the planetNamesListBox
        //          when it is called after a new Planet has been added to the Star Wars database.
        //****************************************************
        private void RefreshPlanetNamesListBox()
        {
            //****************************************************
            // The selectNameFromPlanets string is assigned a SQL command that SELECTs
            // the Name attribute from the Planets table.
            //****************************************************
            string selectNameFromPlanets = "SELECT Name FROM Planets";

            //****************************************************
            // An instance of SqlCommand is declared and initialized by
            // passing in the selectNameFromPlanets string, which holds a SQL SELECT command, 
            // and the instance of SqlConnection, sqlConn.
            //****************************************************
            SqlCommand selectPlanetNameCommand = new SqlCommand(selectNameFromPlanets, sqlConn);

            //****************************************************
            // An instance of SqlDataReader is declared and is assigned
            // the data that is returned after the instance of SqlCommand,
            // selectPlanetNameCommand, is executed through a call to the ExecuteReader method.
            //****************************************************
            SqlDataReader planetNameReader = selectPlanetNameCommand.ExecuteReader();

            //****************************************************
            // Setting the ItemSource property of the planetNamesListBox
            // on the Planets tab of the StarWarsDB GUI equal to
            // planetNameReader, so that the planetNamesListBox can retrieve
            // data to display from the planetNameReader.
            //****************************************************
            planetNamesListBox.ItemsSource = planetNameReader;

            //****************************************************
            // Setting the DisplayMemberPath property of the
            // planetNamesListBox on the "Planets" tab of the StarWarsDB GUI
            // equal to the Name attribute of the Planets table so that the data
            // contained in the Name column will be displayed in the planetNamesListBox.
            //****************************************************
            planetNamesListBox.DisplayMemberPath = "Name";

            //****************************************************
            // Setting the SelectedValuePath property of the
            // planetNamesListBox on the "Planets" tab of the StarWarsDB GUI
            // equal to the Name attribute of the Planets table so that
            // the planetNamesListBox know to retrieve the value of
            // the Planet's Name when an item is selected.
            //****************************************************
            planetNamesListBox.SelectedValuePath = "Name";
        }
        #endregion
    }
}
