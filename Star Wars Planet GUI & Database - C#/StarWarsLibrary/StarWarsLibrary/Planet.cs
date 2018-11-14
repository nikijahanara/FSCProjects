//******************************************************
// File: Planet.cs
//
// Purpose: To contain the definition for the Planet class.
//          Within the Planet class is a default constructor that assigns default values to
//          Planet's private member variables, C# properties for each of Planet's member variables,
//          an overridden ToString method that outputs descriptive text and the values for each Planet member variable,
//          a PlanetSerialization method that serializes the values of Planet's member variables into JSON format in a file,
//          and a PlanetDeserialization method that assigns an instance of Planet the member variable values that it reads
//          from a Planet JSON formatted file.
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
// and System.Runtime.Serialization.json the Planet
// class JSON serialization would not work.
//****************************************************
using System.Runtime.Serialization;
using System.Runtime.Serialization.Json;
using System.Text;
using System.Threading.Tasks;

//****************************************************
// The Planet class is inside the StarWarsNamespace because
// it helps prevent naming collisions and it provides
// a way to organize the classes within the StarWarsLibrary.
//****************************************************
namespace StarWarsNamespace
{
    //************************************************
    // Placing [DataContract] above the Planet class definition
    // in order for the class's member variables to be serialized
    // when the PlanetSerialization method is called.
    //************************************************
    [DataContract]
    public class Planet
    {
        #region Private Member Variables
        //************************************************
        // Declaring the private member variables of the Planet class.
        // Each [DataMember] specifies the name of the member variable to serialize.
        // For the Planet class, all of its member variables will be serialized.
        //************************************************
        [DataMember(Name = "name")]
        private string name;
        [DataMember(Name = "rotation_period")]
        private string rotationPeriod;
        [DataMember(Name = "orbital_period")]
        private string orbitalPeriod;
        [DataMember(Name = "diameter")]
        private string diameter;
        [DataMember(Name = "climate")]
        private string climate;
        [DataMember(Name = "gravity")]
        private string gravity;
        [DataMember(Name = "terrain")]
        private string terrain;
        [DataMember(Name = "surface_water")]
        private string surfaceWater;
        [DataMember(Name = "population")]
        private string population;
        [DataMember(Name = "created")]
        private string created;
        [DataMember(Name = "edited")]
        private string edited;
        [DataMember(Name = "url")]
        private string url;
        [DataMember(Name = "films")]
        private string[] films;
        [DataMember(Name = "residents")]
        private string[] residents;
        #endregion

        #region Properties
        //****************************************************
        // Property: Name
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Planet's name member variable.
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
        // Property: RotationPeriod
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Planet's rotationPeriod member variable.
        //****************************************************
        public string RotationPeriod
        {
            // Get returns the value of rotationPeriod.
            get
            {
                return rotationPeriod;
            }
            // Set sets the value of rotationPeriod to the value it is assigned to.
            set
            {
                rotationPeriod = value;
            }
        }
        //****************************************************
        // Property: OrbitalPeriod
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Planet's orbitalPeriod member variable.
        //****************************************************
        public string OrbitalPeriod
        {
            // Get returns the value of orbitalPeriod.
            get
            {
                return orbitalPeriod;
            }
            // Set sets the value of orbitalPeriod to the value it is assigned to.
            set
            {
                orbitalPeriod = value;
            }
        }
        //****************************************************
        // Property: Diameter
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Planet's diameter member variable.
        //****************************************************
        public string Diameter
        {
            // Get returns the value of diameter.
            get
            {
                return diameter;
            }
            // Set sets the value of diameter to the value it is assigned to.
            set
            {
                diameter = value;
            }
        }
        //****************************************************
        // Property: Climate
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Planet's climate member variable.
        //****************************************************
        public string Climate
        {
            // Get returns the value of climate.
            get
            {
                return climate;
            }
            // Set sets the value of climate to the value it is assigned to.
            set
            {
                climate = value;
            }
        }
        //****************************************************
        // Property: Gravity
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Planet's gravity member variable.
        //****************************************************
        public string Gravity
        {
            // Get returns the value of gravity.
            get
            {
                return gravity;
            }
            // Set sets the value of gravity to the value it is assigned to.
            set
            {
                gravity = value;
            }
        }
        //****************************************************
        // Property: Terrain
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Planet's terrain member variable.
        //****************************************************
        public string Terrain
        {
            // Get returns the value of terrain.
            get
            {
                return terrain;
            }
            // Set sets the value of terrain to the value it is assigned to.
            set
            {
                terrain = value;
            }
        }
        //****************************************************
        // Property: SurfaceWater
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Planet's surfaceWater member variable.
        //****************************************************
        public string SurfaceWater
        {
            // Get returns the value of surfaceWater.
            get
            {
                return surfaceWater;
            }
            // Set sets the value of surfaceWater to the value it is assigned to.
            set
            {
                surfaceWater = value;
            }
        }
        //****************************************************
        // Property: Population
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Planet's population member variable.
        //****************************************************
        public string Population
        {
            // Get returns the value of population.
            get
            {
                return population;
            }
            // Set sets the value of population to the value it is assigned to.
            set
            {
                population = value;
            }
        }
        //****************************************************
        // Property: Created
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Planet's created member variable.
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
        //          implicitly called for Planet's edited member variable.
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
        //          implicitly called for Planet's url member variable.
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
        //          implicitly called for Planet's films array member variable.
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
        // Property: Residents
        //
        // Purpose: To create get and set methods that will be
        //          implicitly called for Planet's residents array member variable.
        //****************************************************
        public string[] Residents
        {
            // Get returns the value of residents.
            get
            {
                return residents;
            }
            // Set sets the value of residents to the value it is assigned to.
            set
            {
                residents = value;
            }
        }
        #endregion

        #region Methods
        //****************************************************
        // Method: Planet
        //
        // Purpose: To be the default constructor and to assign
        //          default values to the Planet class's member variables.
        //****************************************************
        public Planet()
        {
            name = "PLANET NAME";
            rotationPeriod = "ROTATION PERIOD";
            orbitalPeriod = "ORBITAL PERIOD";
            diameter = "DIAMETER";
            climate = "CLIMATE";
            gravity = "GRAVITY";
            terrain = "TERRAIN";
            surfaceWater = "SURFACE WATER";
            population = "POPULATION";
            created = "CREATED";
            edited = "EDITED";
            url = "URL";

            //****************************************************
            // Because a string array implicitly calls new for 
            // each of its elements, a loop is not required to
            // initialize each element of the films and residents array.
            //****************************************************
            films = new string[5];
            residents = new string[5];
        }

        //****************************************************
        // Method: ToString
        //
        // Purpose: To be overridden to show descriptive text and
        //          data for all of the Planet class's member variables.
        //****************************************************
        public override string ToString()
        {
            //****************************************************
            // Formatting the string to print descriptive text and
            // the value of each Planet member variable on a new line.
            //****************************************************
            string s = String.Format("\nPlanet Name: {0}\nRotation Period: {1}\nOrbital Period: {2}\nDiameter: {3}\nClimate: {4}\nGravity: {5}\nTerrain: {6}\nSurface Water: {7}\nPopulation: {8}\nCreated: {9}\nEdited: {10}\nUrl: {11}\n",
                                        name, rotationPeriod, orbitalPeriod, diameter, climate, gravity, terrain, surfaceWater, population, created, edited, url);

            s += "Residents:\n";
            //****************************************************
            // Formatting the string to print descriptive text and
            // the values of each residents array element on a new line by
            // using a for loop to add each residents element to the concatenated string.
            //****************************************************
            for (int i = 0; i < residents.Length; i++)
            {
                //****************************************************
                // Adding the values of each element of the residents array 
                // to the concatenated string and separating each element by a new line.
                //****************************************************
                s += residents[i] + "\n";
            }

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

            // Returning the concatenated string.
            return s;
        }

        //****************************************************
        // Method: PlanetSerialization
        //
        // Purpose: To serialize all the member variable values of the instance
        //          of Planet, that is passed into the method, into the file that
        //          is also passed into the method in a JSON format.
        //****************************************************
        public void PlanetSerialization(Planet pl, string file)
        {
            //****************************************************
            // Declaring an instance of FileStream so that the file passed into the method
            // can be passed into the instance of FileStream in order to be created and written onto.
            //****************************************************
            FileStream writer = new FileStream(file, FileMode.Create, FileAccess.Write);

            // Declaring an instance of DataContractJsonSerializer and setting its type to Planet.
            DataContractJsonSerializer ser = new DataContractJsonSerializer(typeof(Planet));

            //****************************************************
            // Calling WriteObject from the instance of DataContractJsonSerializer
            // so that the instance of FileStream passed into WriteObject can write
            // the member variable values of the instance of Planet
            // passed into the method onto the file in a JSON format.
            //****************************************************
            ser.WriteObject(writer, pl);
            // Closing the instance of FileStream.
            writer.Close();
        }

        //****************************************************
        // Method: PlanetDeserialization
        //
        // Purpose: To take Planet JSON from the file passed into the method and
        //          assign the instance of Planet, also passed into the method, the
        //          Planet member variable values stored in the Planet JSON file.
        //****************************************************
        public void PlanetDeserialization(ref Planet pl, string file)
        {
            //****************************************************
            // Declaring an instance of FileStream so that the file passed into the method
            // can be passed into the instance of FileStream in order to be opened and read from.
            //****************************************************
            FileStream reader = new FileStream(file, FileMode.Open, FileAccess.Read);

            // Declaring an instance of DataContractJsonSerializer and setting its type to Planet.
            DataContractJsonSerializer inputSerializer = new DataContractJsonSerializer(typeof(Planet));

            //****************************************************
            // Assigning the Planet member variable values, that the ReadObject method
            // read from the Planet JSON file, to the member variable values of the 
            // instance of Planet that was passed into the method after
            // casting inputSerializer's data type to that of Planet.
            //****************************************************
            pl = (Planet)inputSerializer.ReadObject(reader);
            // Closing the instance of FileStream.
            reader.Close();
        }
        #endregion 
    }
}
