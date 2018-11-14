//******************************************************
// File: Person.cs
//
// Purpose: To contain the definition for the Person class.
//          Within the Person class is a default constructor that assigns default values to
//          Person's private member variables, C# properties for each of Person's member variables,
//          an overridden ToString method that outputs descriptive text and the values for each Person member variable,
//          a PersonSerialization method that serializes the values of Person's member variables into JSON format in a file,
//          and a PersonDeserialization method that assigns an instance of Person the member variable values that it reads
//          from a Person JSON formatted file.
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
// and System.Runtime.Serialization.json the Person
// class JSON serialization would not work.
//****************************************************
using System.Runtime.Serialization;
using System.Runtime.Serialization.Json;
using System.Text;
using System.Threading.Tasks;

//****************************************************
// The Person class is inside the StarWarsNamespace because
// it helps prevent naming collisions and it provides
// a way to organize the classes within the StarWarsLibrary.
//****************************************************
namespace StarWarsNamespace
{
    //************************************************
    // Placing [DataContract] above the Person class definition
    // in order for the class's member variables to be serialized
    // when the PersonSerialization method is called.
    //************************************************
    [DataContract]
    public class Person
    {
        #region Private Member Variables
        //************************************************
        // Declaring the private member variables of the Person class.
        // Each [DataMember] specifies the name of the member variable to serialize.
        // For the Person class, all of its member variables will be serialized.
        //************************************************
        [DataMember(Name = "name")]
        private string name;
        [DataMember(Name = "height")]
        private string height;
        [DataMember(Name = "mass")]
        private string mass;
        [DataMember(Name = "hair_color")]
        private string hairColor;
        [DataMember(Name = "skin_color")]
        private string skinColor;
        [DataMember(Name = "eye_color")]
        private string eyeColor;
        [DataMember(Name = "birth_year")]
        private string birthYear;
        [DataMember(Name = "gender")]
        private string gender;
        [DataMember(Name = "homeworld")]
        private string homeWorld;
        [DataMember(Name = "created")]
        private string created;
        [DataMember(Name = "edited")]
        private string edited;
        [DataMember(Name = "url")]
        private string url;
        [DataMember(Name = "films")]
        private string[] films;
        [DataMember(Name = "species")]
        private string[] species;
        [DataMember(Name = "vehicles")]
        private string[] vehicles;
        [DataMember(Name = "starships")]
        private string[] starships;
        #endregion

        #region Properties
        //****************************************************
        // Property: Name
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Person's name member variable.
        //****************************************************
        public string Name
        {
            // Get returns the value of name.
            get
            {
                return name;
            }
            // Set sets the value of name to the value it is assigned to.
            set
            {
                name = value;
            }
        }
        //****************************************************
        // Property: Height
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Person's height member variable.
        //****************************************************
        public string Height
        {
            // Get returns the value of height.
            get
            {
                return height;
            }
            // Set sets the value of height to the value it is assigned to.
            set
            {
                height = value;
            }
        }
        //****************************************************
        // Property: Mass
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Person's mass member variable.
        //****************************************************
        public string Mass
        {
            // Get returns the value of mass.
            get
            {
                return mass;
            }
            // Set sets the value of mass to the value it is assigned to.
            set
            {
                mass = value;
            }
        }
        //****************************************************
        // Property: HairColor
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Person's hairColor member variable.
        //****************************************************
        public string HairColor
        {
            // Get returns the value of hairColor.
            get
            {
                return hairColor;
            }
            // Set sets the value of hairColor to the value it is assigned to.
            set
            {
                hairColor = value;
            }
        }
        //****************************************************
        // Property: SkinColor
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Person's skinColor member variable.
        //****************************************************
        public string SkinColor
        {
            // Get returns the value of skinColor.
            get
            {
                return skinColor;
            }
            // Set sets the value of skinColor to the value it is assigned to.
            set
            {
                skinColor = value;
            }
        }
        //****************************************************
        // Property: EyeColor
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Person's eyeColor member variable.
        //****************************************************
        public string EyeColor
        {
            // Get returns the value of eyeColor.
            get
            {
                return eyeColor;
            }
            // Set sets the value of eyeColor to the value it is assigned to.
            set
            {
                eyeColor = value;
            }
        }
        //****************************************************
        // Property: BirthYear
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Person's birthYear member variable.
        //****************************************************
        public string BirthYear
        {
            // Get returns the value of birthYear.
            get
            {
                return birthYear;
            }
            // Set sets the value of birthYear to the value it is assigned to.
            set
            {
                birthYear = value;
            }
        }
        //****************************************************
        // Property: Gender
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Person's gender member variable.
        //****************************************************
        public string Gender
        {
            // Get returns the value of gender.
            get
            {
                return gender;
            }
            // Set sets the value of gender to the value it is assigned to.
            set
            {
                gender = value;
            }
        }
        //****************************************************
        // Property: HomeWorld
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Person's homeWorld member variable.
        //****************************************************
        public string HomeWorld
        {
            // Get returns the value of homeWorld.
            get
            {
                return homeWorld;
            }
            // Set sets the value of homeWorld to the value it is assigned to.
            set
            {
                homeWorld = value;
            }
        }
        //****************************************************
        // Property: Created
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Person's created member variable.
        //****************************************************
        public string Created
        {
            // Get returns the value of created.
            get
            {
                return created;
            }
            // Set sets the value of created to the value it is assigned to.
            set
            {
                created = value;
            }
        }
        //****************************************************
        // Property: Edited
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Person's edited member variable.
        //****************************************************
        public string Edited
        {
            // Get returns the value of edited.
            get
            {
                return edited;
            }
            // Set sets the value of edited to the value it is assigned to.
            set
            {
                edited = value;
            }
        }
        //****************************************************
        // Property: Url
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Person's url member variable.
        //****************************************************
        public string Url
        {
            // Get returns the value of url.
            get
            {
                return url;
            }
            // Set sets the value of url to the value it is assigned to.
            set
            {
                url = value;
            }
        }
        //****************************************************
        // Property: Films
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Person's films array member variable.
        //****************************************************
        public string[] Films
        {
            // Get returns the value of films.
            get
            {
                return films;
            }
            // Set sets the value of films to the value it is assigned to.
            set
            {
                films = value;
            }
        }
        //****************************************************
        // Property: Species
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Person's species array member variable.
        //****************************************************
        public string[] Species
        {
            // Get returns the value of species.
            get
            {
                return species;
            }
            // Set sets the value of species to the value it is assigned to.
            set
            {
                species = value;
            }
        }
        //****************************************************
        // Property: Vehicles
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Person's vehicles array member variable.
        //****************************************************
        public string[] Vehicles
        {
            // Get returns the value of vehicles.
            get
            {
                return vehicles;
            }
            // Set sets the value of vehicles to the value it is assigned to.
            set
            {
                vehicles = value;
            }
        }
        //****************************************************
        // Property: Starships
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Person's starships array member variable.
        //****************************************************
        public string[] Starships
        {
            // Get returns the value of starships.
            get
            {
                return starships;
            }
            // Set sets the value of starships to the value it is assigned to.
            set
            {
                starships = value;
            }
        }
        #endregion

        #region Methods
        //****************************************************
        // Method: Person
        //
        // Purpose: To be the default constructor and to assign
        //          default values to the Person class's member variables.
        //****************************************************
        public Person()
        {
            name = "NAME";
            height = "HEIGHT";
            mass = "MASS";
            hairColor = "HAIR COLOR";
            skinColor = "SKIN COLOR";
            eyeColor = "EYE COLOR";
            birthYear = "BIRTH YEAR";
            gender = "GENDER";
            homeWorld = "HOME WORLD";
            created = "CREATED";
            edited = "EDITED";
            url = "URL";

            //****************************************************
            // Because a string array implicitly calls new for 
            // each of its elements, a loop is not required to
            // initialize each element of the films, species,
            // vehicles and starships array.
            //****************************************************
            films = new string[5];
            species = new string[5];
            vehicles = new string[5];
            starships = new string[5];
        }

        //****************************************************
        // Method: ToString
        //
        // Purpose: To be overridden to show descriptive text and
        //          data for all of the Person class's member variables.
        //****************************************************
        public override string ToString()
        {
            //****************************************************
            // Formatting the string to print descriptive text and
            // the value of each Person member variable on a new line.
            //****************************************************
            string s = String.Format("\nName: {0}\nHeight: {1}\nMass: {2}\nHair Color: {3}\nSkin Color: {4}\nEye Color: {5}\nBirth Year: {6}\nGender: {7}\nHome World: {8}\nCreated: {9}\nEdited: {10}\nUrl: {11}\n", 
                                    name, height, mass, hairColor, skinColor, eyeColor, birthYear, gender, homeWorld, created, edited, url);

            s += "Films:\n";
            //****************************************************
            // Formatting the string to print descriptive text and
            // the values of each films array element on a new line by
            // using a for loop to add each films element to the concatenated string.
            //****************************************************
            for (int i = 0; i < films.Length; i++)
            {
                //****************************************************
                // Adding the values of each element of the films array 
                // to the concatenated string and separating each element by a new line.
                //****************************************************
                s += films[i] + "\n";
            }

            s += "Species:\n";
            //****************************************************
            // Formatting the string to print descriptive text and
            // the values of each species array element on a new line by
            // using a for loop to add each species element to the concatenated string.
            //****************************************************
            for (int i = 0; i < species.Length; i++)
            {
                //****************************************************
                // Adding the values of each element of the species array 
                // to the concatenated string and separating each element by a new line.
                //****************************************************
                s += species[i] + "\n";
            }

            s += "Vehicles:\n";
            //****************************************************
            // Formatting the string to print descriptive text and
            // the values of each vehicles array element on a new line by
            // using a for loop to add each vehicles element to the concatenated string.
            //****************************************************
            for (int i = 0; i < vehicles.Length; i++)
            {
                //****************************************************
                // Adding the values of each element of the vehicles array 
                // to the concatenated string and separating each element by a new line.
                //****************************************************
                s += vehicles[i] + "\n";
            }

            s += "Starships:\n";
            //****************************************************
            // Formatting the string to print descriptive text and
            // the values of each starships array element on a new line by
            // using a for loop to add each starships element to the concatenated string.
            //****************************************************
            for (int i = 0; i < starships.Length; i++)
            {
                //****************************************************
                // Adding the values of each element of the starships array 
                // to the concatenated string and separating each element by a new line.
                //****************************************************
                s += starships[i] + "\n";
            }

            // Returning the concatenated string.
            return s;
        }

        //****************************************************
        // Method: PersonSerialization
        //
        // Purpose: To serialize all the member variable values of the instance
        //          of Person, that is passed into the method, into the file that
        //          is also passed into the method in a JSON format.
        //****************************************************
        public void PersonSerialization(Person pe, string file)
        {
            //****************************************************
            // Declaring an instance of FileStream so that the file passed into the method
            // can be passed into the instance of FileStream in order to be created and written onto.
            //****************************************************
            FileStream writer = new FileStream(file, FileMode.Create, FileAccess.Write);

            // Declaring an instance of DataContractJsonSerializer and setting its type to Person.
            DataContractJsonSerializer ser = new DataContractJsonSerializer(typeof(Person));

            //****************************************************
            // Calling WriteObject from the instance of DataContractJsonSerializer
            // so that the instance of FileStream passed into WriteObject can write
            // the member variable values of the instance of Person 
            // passed into the method onto the file in a JSON format.
            //****************************************************
            ser.WriteObject(writer, pe);
            // Closing the instance of FileStream.
            writer.Close();
        }

        //****************************************************
        // Method: PersonDeserialization
        //
        // Purpose: To take Person JSON from the file passed into the method and
        //          assign the instance of Person, also passed into the method, the
        //          Person member variable values stored in the Person JSON file.
        //****************************************************
        public void PersonDeserialization(ref Person pe, string file)
        {
            //****************************************************
            // Declaring an instance of FileStream so that the file passed into the method
            // can be passed into the instance of FileStream in order to be opened and read from.
            //****************************************************
            FileStream reader = new FileStream(file, FileMode.Open, FileAccess.Read);

            // Declaring an instance of DataContractJsonSerializer and setting its type to Person.
            DataContractJsonSerializer inputSerializer = new DataContractJsonSerializer(typeof(Person));

            //****************************************************
            // Assigning the Person member variable values, that the ReadObject method
            // read from the Person JSON file, to the member variable values of the 
            // instance of Person that was passed into the method after
            // casting inputSerializer's data type to that of Person.
            //****************************************************
            pe = (Person)inputSerializer.ReadObject(reader);
            // Closing the instance of FileStream.
            reader.Close();
        }
        #endregion
    }
}
