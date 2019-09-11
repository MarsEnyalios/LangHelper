/* File: alpha.cpp
 * @author MarsEnyalios
 * Contains alpha.h method bodies */

#include <string>
#include <vector>
#include <iostream>
#include <map>

#include "alpha.h"

using std::string; using std::vector; using std::map; 
using std::cout; using std::cin; using std::endl;

/** INITIALIZERS **/

Alpha :: Alpha()
{
   categories['S'].push_back("cvc");
   categories['S'].push_back("vcv");
   categories['S'].push_back("cvcc");
   categories['S'].push_back("vvc");
   categories['S'].push_back("ccv");

   categories['C'].push_back("k");
   categories['C'].push_back("m");
   categories['C'].push_back("n");
   categories['C'].push_back("p");
   categories['C'].push_back("q");
   categories['C'].push_back("t");

   categories['V'].push_back("a");
   categories['V'].push_back("e");
   categories['V'].push_back("i");
   categories['V'].push_back("o");
   categories['V'].push_back("u");
}

Alpha :: Alpha(map<char, vector<string> > categories)
{
   this->categories = categories; 
   
   this->categories['S'].push_back("cvc");
   this->categories['S'].push_back("vcv");
   this->categories['S'].push_back("cvcc");
   this->categories['S'].push_back("vvc");
   this->categories['S'].push_back("ccv");
}

map<char, vector<string> > Alpha :: getCategories()
{
   return categories; 
}

map<char, vector<string> >::iterator Alpha :: getCategory(char key)
{
   map<char, vector<string> >::iterator it = categories.find(key); 

   return it;
}

void Alpha :: addCategory()
{
   char key = 'X';
   vector<string> letters;

   // TODO: prompt for key
   // TODO: check if key already exists
   // TODO: prompt for vector
   categories.insert(std::pair<char, vector<string> >(key, letters));
}

void Alpha :: changeCategory()
{
   char key; 
   string letter; 

   display(); 

   cout << "Which category would you like to change? (0 to backup): "; 
   cin >> key;
   cin.clear();
   cin.ignore(100, '\n'); 

   // TODO: verify that key exists

   do {
      cout << "\nType a combination to remove or add (0 to backup): "; 
      cin >> letter;
      cin.clear(); 
      cin.ignore(100, '\n'); 

      // TODO: if key-letter does not exist, add it
      // TODO: if key-letter does exist, remove it

   } while (letter != "0");

   // TODO: prompt to play again
}

void Alpha :: deleteCategory()
{
   char key;
   char decision;

   cout << "Please enter the name of the category you wish to delete (0 to backup): "; 
   cin >> key; 
   cin.clear(); 
   cin.ignore(100, '\n');

   // TODO: verify that key exists
   // TODO: verify that key is not S. Syllables is not a removeable category!

   cout << "\nYou want to delete " << key << " (y/n)? ";
   cin >> decision;
   cin.clear(); 
   cin.ignore(100, '\n');

   if (decision == 'n' || decision == 'N')
      return; 

   categories.erase(key);
}

void Alpha :: display()
{
   map<char, vector<string> >::iterator mapIt;
   vector<string>::iterator vecIt;

   for (mapIt = categories.begin(); mapIt != categories.end(); ++mapIt)
   {
      cout << mapIt->first << ':' << ' ';

      for (vecIt = mapIt->second.begin(); vecIt != mapIt->second.end(); ++vecIt)
         cout << *vecIt << ' ';

      cout << endl; 
   }
}

ostream& operator<<(ostream& os, Alpha& alpha)
{
   map<char, vector<string> > categories = alpha.getCategories(); 

   map<char, vector<string> >::iterator mapIt;
   vector<string>::iterator vecIt;

   for (mapIt = categories.begin(); mapIt != categories.end(); ++mapIt)
   {
      os << mapIt->first << endl; 
      
      for (vecIt = mapIt->second.begin(); vecIt != mapIt->second.end(); ++vecIt)
         os << *vecIt << ' ';

      os << endl; 
   }

   return os; 
}
