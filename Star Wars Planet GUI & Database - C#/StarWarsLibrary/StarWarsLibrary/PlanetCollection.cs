//******************************************************
// File: PlanetCollection.cs
//
// Purpose: To contain the definition for the PlanetCollection class.
//          Within the PlanetCollection class is a default constructor that assigns default values to
//          PlanetCollection's private member variables, C# properties for each of PlanetCollection's member variables,
//          an overridden ToString method that outputs descriptive text and the values for each PlanetCollection member variable,
//          a PlanetCollectionJSONSerialization method that serializes the values of PlanetCollection's member variables into JSON format in a file,
//          and a PlanetCollectionJSONDeserialization method that assigns an instance of PlanetCollection
//          the member variable values that it reads from a PlanetCollection JSON formatted file.
//          There is also the PlanetCollectionXMLSerialization method that serializes the values for each PlanetCollection memeber variable
//          into a XML format in a file, and a PlanetCollectionXMLDeserialization method that assigns an instance of PlanetCollection
//          the member variable values that it reads from a PlanetCollection XML formatted file.
//          PlanetCollection also overrides the index operator [] so that it can get or set the element at the at the given index of the results array.
//
// Written By: Niki Jahanara
//
// Compiler: Visual Studio 2015
//
//******************************************************

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
//****************************************************
// Without a reference to System.Runtime.Serialization
// and System.Runtime.Serialization.json the PlanetCollection
// class JSON or XML serialization would not work.
//****************************************************
using System.Runtime.Serialization;
using System.Runtime.Serialization.Json;
using System.Text;
using System.Threading.Tasks;

//****************************************************
// The PlanetCollection class is inside the StarWarsNamespace because
// it helps prevent naming collisions and it provides
// a way to organize the classes within the StarWarsLibrary.
//****************************************************
namespace StarWarsNamespace
{
    //************************************************
    // Placing [DataContract] above the PlanetCollection class definition
    // in order for the class's member variables to be serialized or deserialized
    // when the PlanetCollection serialization or deserialization methods are called.
    //************************************************
    [DataContract]
    public class PlanetCollection
    {
        #region Private Member Variables
        //************************************************
        // Declaring the private member variables of the PlanetCollection class.
        // Each [DataMember] specifies the name of the member variable to serialize.
        // For the PlanetCollection class, all of its member variables will be serialized.
        //************************************************
        [DataMember(Name = "count")]
        private int count;
        [DataMember(Name = "next")]
        private string next;
        [DataMember(Name = "previous")]
        private string previous;
        [DataMember(Name = "results")]
        private Planet[] results;
        #endregion

        #region Properties
        //****************************************************
        // Property: Count
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for PlanetCollection's count member variable.
        //****************************************************
        public int Count
        {
            // Get returns the value of count.
            get
            {
                return count;
            }
            // Set sets the value of count to the value it is assigned to.
            set
            {
                count = value;
            }
        }
        //****************************************************
        // Property: Next
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for PlanetCollection's next member variable.
        //****************************************************
        public string Next
        {
            // Get returns the value of next.
            get
            {
                return next;
            }
            // Set sets the value of next to the value it is assigned to.
            set
            {
                next = value;
            }
        }
        //****************************************************
        // Property: Previous
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for PlanetCollection's previous member variable.
        //****************************************************
        public string Previous
        {
            // Get returns the value of previous.
            get
            {
                return previous;
            }
            // Set sets the value of previous to the value it is assigned to.
            set
            {
                previous = value;
            }
        }
        //****************************************************
        // Property: Results
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for PlanetCollection's results array member variable.
        //****************************************************
        public Planet[] Results
        {
            // Get returns the value of results.
            get
            {
                return results;
            }
            // Set sets the value of results to the value it is assigned to.
            set
            {
                results = value;
            }
        }
        #endregion

        #region Methods
        //****************************************************
        // Method: PlanetCollection
        //
        // Purpose: To be the default constructor and to assign
        //          default values to the PlanetCollection class's member variables.
        //****************************************************
        public PlanetCollection()
        {
            count = 0;
            next = "NEXT VALUE";
            previous = "PREVIOUS VALUE";

            // Initializing the array of Planet.
            results = new Planet[4];

            //****************************************************
            // Allocating memory for each element of the results array
            // by using a for loop to call new on each element of the results array.
            //****************************************************
            for (int i = 0; i < results.Length; i++)
            {
                results[i] = new Planet();
            }
        }

        //****************************************************
        // Method: ToString
        //
        // Purpose: To be overridden to show descriptive text and
        //          data for all of the PlanetCollection class's member variables.
        //****************************************************
        public override string ToString()
        {
            //****************************************************
            // Formatting the string to print descriptive text and
            // the value of each PlanetCollection member variable on a new line.
            //****************************************************
            string s = String.Format("Count: {0}\nNext: {1}\nPrevious: {2}\n", count, next, previous);

            //****************************************************
            // Using a loop to call ToString on each element of the results array
            // so that descriptive text and the values of each Planet element
            // in the results array is added to the ToString of PlanetCollection.
            //****************************************************
            for (int i = 0; i < results.Length; i++)
            {
                //****************************************************
                // Adding the values of each element of the results array 
                // to the concatenated string by calling ToString for 
                // each Planet element in the results array.
                //****************************************************
                s += results[i].ToString();
            }

            // Returning the concatenated string.
            return s;
        }

        //****************************************************
        // Method: PlanetCollectionJSONSerialization
        //
        // Purpose: To serialize all the member variable values of the instance
        //          of PlanetCollection, that is passed into the method, into the file that
        //          is also passed into the method in a JSON format.
        //****************************************************
        public void PlanetCollectionJSONSerialization(PlanetCollection plc, string file)
        {
            //****************************************************
            // Declaring an instance of FileStream so that the file passed into the method
            // can be passed into the instance of FileStream in order to be created and written onto.
            //****************************************************
            FileStream writer = new FileStream(file, FileMode.Create, FileAccess.Write);

            // Declaring an instance of DataContractJsonSerializer and setting its type to PlanetCollection.
            DataContractJsonSerializer ser = new DataContractJsonSerializer(typeof(PlanetCollection));

            //****************************************************
            // Calling WriteObject from the instance of DataContractJsonSerializer
            // so that the instance of FileStream passed into WriteObject can write
            // the member variable values of the instance of PlanetCollection
            // passed into the method onto the file in a JSON format.
            //****************************************************
            ser.WriteObject(writer, plc);

            // Closing the instance of FileStream.
            writer.Close();
        }

        //****************************************************
        // Method: PlanetCollectionJSONDeserialization
        //
        // Purpose: To take PlanetCollection JSON from the file passed into the method and
        //          assign the instance of PlanetCollection, also passed into the method, the
        //          PlanetCollection member variable values stored in the PlanetCollection JSON file.
        //****************************************************
        public void PlanetCollectionJSONDeserialization(ref PlanetCollection plc, string file)
        {
            //****************************************************
            // Declaring an instance of FileStream so that the file passed into the method
            // can be passed into the instance of FileStream in order to be opened and read from.
            //****************************************************
            FileStream reader = new FileStream(file, FileMode.Open, FileAccess.Read);

            // Declaring an instance of DataContractJsonSerializer and setting its type to PlanetCollection.
            DataContractJsonSerializer inputSerializer = new DataContractJsonSerializer(typeof(PlanetCollection));

            //****************************************************
            // Assigning the PlanetCollection member variable values, that the ReadObject method
            // read from the PlanetCollection JSON file, to the member variable values of the 
            // instance of PlanetCollection that was passed into the method after
            // casting inputSerializer's data type to that of PlanetCollection.
            //****************************************************
            plc = (PlanetCollection)inputSerializer.ReadObject(reader);

            // Closing the instance of FileStream.
            reader.Close();
        }

        //****************************************************
        // Method: PlanetCollectionXMLSerialization
        //
        // Purpose: To serialize all the member variable values of the instance
        //          of PlanetCollection, that is passed into the method, into the file that
        //          is also passed into the method in a XML format.
        //****************************************************
        public void PlanetCollectionXMLSerialization(PlanetCollection plc, string file)
        {
            //****************************************************
            // Declaring an instance of FileStream so that the file passed into the method
            // can be passed into the instance of FileStream in order to be created and written onto.
            //****************************************************
            FileStream writer = new FileStream(file, FileMode.Create, FileAccess.Write);

            // Declaring an instance of DataContractSerializer and setting its type to PlanetCollection.
            DataContractSerializer ser = new DataContractSerializer(typeof(PlanetCollection));

            //****************************************************
            // Calling WriteObject from the instance of DataContractSerializer
            // so that the instance of FileStream passed into WriteObject can write
            // the member variable values of the instance of PlanetCollection
            // passed into the method onto the file in a XML format.
            //****************************************************
            ser.WriteObject(writer, plc);

            // Closing the instance of FileStream.
            writer.Close();
        }

        //****************************************************
        // Method: PlanetCollectionXMLDeserialization
        //
        // Purpose: To take PlanetCollection XML from the file passed into the method and
        //          assign the instance of PlanetCollection, also passed into the method, the
        //          PlanetCollection member variable values stored in the PlanetCollection XML file.
        //****************************************************
        public void PlanetCollectionXMLDeserialization(ref PlanetCollection plc, string file)
        {
            //****************************************************
            // Declaring an instance of FileStream so that the file passed into the method
            // can be passed into the instance of FileStream in order to be opened and read from.
            //****************************************************
            FileStream reader = new FileStream(file, FileMode.Open, FileAccess.Read);

            // Declaring an instance of DataContractSerializer and setting its type to PlanetCollection.
            DataContractSerializer inputSerializer = new DataContractSerializer(typeof(PlanetCollection));

            //****************************************************
            // Assigning the PlanetCollection member variable values, that the ReadObject method
            // read from the PlanetCollection XML file, to the member variable values of the 
            // instance of PlanetCollection that was passed into the method after
            // casting inputSerializer's data type to that of PlanetCollection.
            //****************************************************
            plc = (PlanetCollection)inputSerializer.ReadObject(reader);

            // Closing the instance of FileStream.
            reader.Close();
        }
        #endregion

        #region Operator Overloads
        //****************************************************
        // Operator Overload: []
        //
        // Purpose: To have the index operator work for an instance
        //          of PlanetCollection like it works for an array
        //          where it is able to get and set the element
        //          at the given index of PlanetCollection's results array.
        //****************************************************
        public Planet this[int i]
        {
            // Returns an element at the given index of the results array.
            get
            {
                return Results[i];
            }
            // Sets an element at the given index of the results array.
            set
            {
                Results[i] = value;
            }
        } 
        #endregion
    }
}
