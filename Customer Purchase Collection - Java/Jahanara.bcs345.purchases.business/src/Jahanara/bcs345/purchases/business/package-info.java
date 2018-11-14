/**
 * This package contains five classes: Address, Product, Customer, Purchase and PurchaseCollection.
 * Address, Product, Customer and Purchase all have a Write method 
 * that writes the values of each class's member variables to a file,
 * and each have a Read method that reads values from the file that Write generated in order to 
 * assign the values that it reads to each class's member variables.
 * Address, Product, Customer and Purchase also have an overridden toString method, 
 * as well as a GetJSON method that prints each class's member variable values in a JSON format.
 * All four classes have a default constructor, but only Address has an additional constructor with parameters.
 * Customer and Purchase also reuse code by calling the methods from Address and Product within their own methods respectively.
 * PurchaseCollection also has a Write and Read method that writes data to a file and reads data from a file, respectively.
 * PurchaseCollection also has an overridden toString method and a GetJSON that prints each class's member variables in JSON format.
 * Exclusive to PurchaseCollection is the GetMaxPurchase method that calculates and returns which index in the purchase array
 * has the highest cost, as well as the GetByIndex method that either returns the element at the index that is passed into it,
 * or throws a IndexOutOfBoundsException if the index passed into it is an invalid index value, or throws a NullPointerException if
 * the purchase array is null. Also exclusive to PurchaseCollection is the Report method, which prints the values of
 * the PurchaseCollection's customer instance and purchase array in a purchase report format.
 * All five classes within the package have Get/Set methods for their respective member variables, including
 * getPurchases in the PurchaseCollection class that returns the class's array of Purchase.
 *
 * @author Niki Jahanara
 */
package Jahanara.bcs345.purchases.business;