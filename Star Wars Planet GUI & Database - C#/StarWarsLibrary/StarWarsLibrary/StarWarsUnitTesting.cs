//******************************************************
// File: StarWarsUnitTesting.cs
//
// Purpose: To contain the definition for the StarWarsUnitTesting class. 
//          Within the StarWarsUnitTesting class is two methods: UnitTestPerson and UnitTestPlanet.
//          The UnitTestPerson method declares an instance of Person inside of it in order to perform
//          a unit test on all of Person's properties to see if its properties are working correctly or not.
//          The UnitTestPlanet method declares an instance of Planet inside of it in order to perform
//          a unit test on all of Planet's properties to see if its properties are working correctly or not.
//
// Written By: Niki Jahanara
//
// Compiler: Visual Studio 2015
//
//******************************************************

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//****************************************************
// The StarWarsUnitTesting class is inside the StarWarsNamespace because
// it helps prevent naming collisions and it provides
// a way to organize the classes within the StarWarsLibrary.
//****************************************************
namespace StarWarsNamespace
{
    public class StarWarsUnitTesting
    {
        #region Methods
        //****************************************************
        // Method: UnitTestPerson
        //
        // Purpose: To perform a unit test on an instance of Person's member variables
        //          to see if the C# properties for the Person class's member variables
        //          are properly implemented and working correctly.
        //****************************************************
        public void UnitTestPerson()
        {
            // Declaring an instance of Person.
            Person p = new Person();
            //****************************************************
            // Declaring a string variable and assigning to it a 
            // test value that will be used in each unit test to see
            // if Person's C# properties are working correctly or not.
            //****************************************************
            string testString = "TEST VALUE";

            // Setting the instance of Person's name member variable value to the testString value.
            p.Name = testString;

            //****************************************************
            // If the Name property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (p.Name == testString)
            {
                Console.WriteLine("Person Name Property: Pass.");
            }
            //****************************************************
            // If the Name property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Person Name Property: FAIL!");
            }

            // Setting the instance of Person's height member variable value to the testString value.
            p.Height = testString;

            //****************************************************
            // If the Height property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (p.Height == testString)
            {
                Console.WriteLine("Person Height Property: Pass.");
            }
            //****************************************************
            // If the Height property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Person Height Property: FAIL!");
            }

            // Setting the instance of Person's mass member variable value to the testString value.
            p.Mass = testString;

            //****************************************************
            // If the Mass property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (p.Mass == testString)
            {
                Console.WriteLine("Person Mass Property: Pass.");
            }
            //****************************************************
            // If the Mass property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Person Mass Property: FAIL!");
            }

            // Setting the instance of Person's hairColor member variable value to the testString value.
            p.HairColor = testString;

            //****************************************************
            // If the HairColor property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (p.HairColor == testString)
            {
                Console.WriteLine("Person HairColor Property: Pass.");
            }
            //****************************************************
            // If the HairColor property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Person HairColor Property: FAIL!");
            }

            // Setting the instance of Person's skinColor member variable value to the testString value.
            p.SkinColor = testString;

            //****************************************************
            // If the SkinColor property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (p.SkinColor == testString)
            {
                Console.WriteLine("Person SkinColor Property: Pass.");
            }
            //****************************************************
            // If the SkinColor property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Person SkinColor Property: FAIL!");
            }

            // Setting the instance of Person's eyeColor member variable value to the testString value.
            p.EyeColor = testString;

            //****************************************************
            // If the EyeColor property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (p.EyeColor == testString)
            {
                Console.WriteLine("Person EyeColor Property: Pass.");
            }
            //****************************************************
            // If the EyeColor property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Person EyeColor Property: FAIL!");
            }

            // Setting the instance of Person's birthYear member variable value to the testString value.
            p.BirthYear = testString;

            //****************************************************
            // If the BirthYear property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (p.BirthYear == testString)
            {
                Console.WriteLine("Person BirthYear Property: Pass.");
            }
            //****************************************************
            // If the BirthYear property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Person BirthYear Property: FAIL!");
            }

            // Setting the instance of Person's gender member variable value to the testString value.
            p.Gender = testString;

            //****************************************************
            // If the Gender property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (p.Gender == testString)
            {
                Console.WriteLine("Person Gender Property: Pass.");
            }
            //****************************************************
            // If the Gender property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Person Gender Property: FAIL!");
            }

            // Setting the instance of Person's homeWorld member variable value to the testString value.
            p.HomeWorld = testString;

            //****************************************************
            // If the HomeWorld property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (p.HomeWorld == testString)
            {
                Console.WriteLine("Person HomeWorld Property: Pass.");
            }
            //****************************************************
            // If the HomeWorld property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Person HomeWorld Property: FAIL!");
            }

            // Setting the instance of Person's created member variable value to the testString value.
            p.Created = testString;

            //****************************************************
            // If the Created property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (p.Created == testString)
            {
                Console.WriteLine("Person Created Property: Pass.");
            }
            //****************************************************
            // If the Created property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Person Created Property: FAIL!");
            }

            // Setting the instance of Person's edited member variable value to the testString value.
            p.Edited = testString;

            //****************************************************
            // If the Edited property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (p.Edited == testString)
            {
                Console.WriteLine("Person Edited Property: Pass.");
            }
            //****************************************************
            // If the Edited property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Person Edited Property: FAIL!");
            }

            // Setting the instance of Person's url member variable value to the testString value.
            p.Url = testString;

            //****************************************************
            // If the Url property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (p.Url == testString)
            {
                Console.WriteLine("Person Url Property: Pass.\n");
            }
            //****************************************************
            // If the Url property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Person Url Property: FAIL!");
            }
        }

        //****************************************************
        // Method: UnitTestPlanet
        //
        // Purpose: To perform a unit test on an instance of Planet's member variables
        //          to see if the C# properties for the Planet class's member variables
        //          are properly implemented and working correctly.
        //****************************************************
        public void UnitTestPlanet()
        {
            // Declaring an instance of Planet.
            Planet pl = new Planet();
            //****************************************************
            // Declaring a string variable and assigning to it a 
            // test value that will be used in each unit test to see
            // if Planet's C# properties are working correctly or not.
            //****************************************************
            string testString = "TEST VALUE";

            // Setting the instance of Planet's name member variable value to the testString value.
            pl.Name = testString;

            //****************************************************
            // If the Name property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (pl.Name == testString)
            {
                Console.WriteLine("Planet Name Property: Pass.");
            }
            //****************************************************
            // If the Name property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Planet Name Property: FAIL!");
            }

            // Setting the instance of Planet's rotationPeriod member variable value to the testString value.
            pl.RotationPeriod = testString;

            //****************************************************
            // If the RotationPeriod property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (pl.RotationPeriod == testString)
            {
                Console.WriteLine("Planet RotationPeriod Property: Pass.");
            }
            //****************************************************
            // If the RotationPeriod property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Planet RotationPeriod Property: FAIL!");
            }

            // Setting the instance of Planet's orbitalPeriod member variable value to the testString value.
            pl.OrbitalPeriod = testString;

            //****************************************************
            // If the OrbitalPeriod property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (pl.OrbitalPeriod == testString)
            {
                Console.WriteLine("Planet OrbitalPeriod Property: Pass.");
            }
            //****************************************************
            // If the OrbitalPeriod property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Planet OrbitalPeriod Property: FAIL!");
            }

            // Setting the instance of Planet's diameter member variable value to the testString value.
            pl.Diameter = testString;

            //****************************************************
            // If the Diameter property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (pl.Diameter == testString)
            {
                Console.WriteLine("Planet Diameter Property: Pass.");
            }
            //****************************************************
            // If the Diameter property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Planet Diameter Property: FAIL!");
            }

            // Setting the instance of Planet's climate member variable value to the testString value.
            pl.Climate = testString;

            //****************************************************
            // If the Climate property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (pl.Climate == testString)
            {
                Console.WriteLine("Planet Climate Property: Pass.");
            }
            //****************************************************
            // If the Climate property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Planet Climate Property: FAIL!");
            }

            // Setting the instance of Planet's gravity member variable value to the testString value.
            pl.Gravity = testString;

            //****************************************************
            // If the Gravity property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (pl.Gravity == testString)
            {
                Console.WriteLine("Planet Gravity Property: Pass.");
            }
            //****************************************************
            // If the Gravity property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Planet Gravity Property: FAIL!");
            }

            // Setting the instance of Planet's terrain member variable value to the testString value.
            pl.Terrain = testString;

            //****************************************************
            // If the Terrain property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (pl.Terrain == testString)
            {
                Console.WriteLine("Planet Terrain Property: Pass.");
            }
            //****************************************************
            // If the Terrain property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Planet Terrain Property: FAIL!");
            }

            // Setting the instance of Planet's surfaceWater member variable value to the testString value.
            pl.SurfaceWater = testString;

            //****************************************************
            // If the SurfaceWater property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (pl.SurfaceWater == testString)
            {
                Console.WriteLine("Planet SurfaceWater Property: Pass.");
            }
            //****************************************************
            // If the SurfaceWater property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Planet SurfaceWater Property: FAIL!");
            }

            // Setting the instance of Planet's population member variable value to the testString value.
            pl.Population = testString;

            //****************************************************
            // If the Population property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (pl.Population == testString)
            {
                Console.WriteLine("Planet Population Property: Pass.");
            }
            //****************************************************
            // If the Population property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Planet Population Property: FAIL!");
            }

            // Setting the instance of Planet's created member variable value to the testString value.
            pl.Created = testString;

            //****************************************************
            // If the Created property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (pl.Created == testString)
            {
                Console.WriteLine("Planet Created Property: Pass.");
            }
            //****************************************************
            // If the Created property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Planet Created Property: FAIL!");
            }

            // Setting the instance of Planet's edited member variable value to the testString value.
            pl.Edited = testString;

            //****************************************************
            // If the Edited property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (pl.Edited == testString)
            {
                Console.WriteLine("Planet Edited Property: Pass.");
            }
            //****************************************************
            // If the Edited property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Planet Edited Property: FAIL!");
            }

            // Setting the instance of Planet's url member variable value to the testString value.
            pl.Url = testString;

            //****************************************************
            // If the Url property returns the testString value, then it is working correctly
            // and a passing message will be output to the console.
            //****************************************************
            if (pl.Url == testString)
            {
                Console.WriteLine("Planet Url Property: Pass.\n");
            }
            //****************************************************
            // If the Url property does not return the testString value, a failing message
            // will be output to the console because the property is not working correctly.
            //****************************************************
            else
            {
                Console.WriteLine("Planet Url Property: FAIL!");
            }
        }
        #endregion 
    }
}