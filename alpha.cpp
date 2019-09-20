/* File: alpha.cpp
 * @author MarsEnyalios
 * Contains alpha.h method bodies */

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

#include "alpha.h"

using std::string; using std::vector; using std::map; 
using std::cout; using std::cin; using std::endl;

/** INITIALIZERS **/

Alpha :: Alpha()
{
   categories['s'].push_back("cvc");
   categories['s'].push_back("vcv");
   categories['s'].push_back("cvcc");
   categories['s'].push_back("vvc");
   categories['s'].push_back("ccv");

   categories['c'].push_back("k");
   categories['c'].push_back("m");
   categories['c'].push_back("n");
   categories['c'].push_back("p");
   categories['c'].push_back("q");
   categories['c'].push_back("t");

   categories['v'].push_back("a");
   categories['v'].push_back("e");
   categories['v'].push_back("i");
   categories['v'].push_back("o");
   categories['v'].push_back("u");
}

Alpha :: Alpha(map<char, vector<string> > categories)
{
   this->categories = categories; 
   
   this->categories['s'].push_back("cvc");
   this->categories['s'].push_back("vcv");
   this->categories['s'].push_back("cvcc");
   this->categories['s'].push_back("vvc");
   this->categories['s'].push_back("ccv");
}

/* GETTERS */

// Return all categories
map<char, vector<string> > Alpha :: getCategories()
{
   return categories; 
}

// Return a single category iterator?
vector<string> Alpha :: getCategory(char key)
{
   return categories[key];
}

/* ADD CATEGORY **************************************************************
 * Purpose: add a new category
 */
void Alpha :: addCategory()
{
   char key = 'X';
   string temp = "yikes";
   vector<string> letters;

   cout << "Enter key for new category (0 to backup): "; 
   cin >> key; 
   cin.clear(); 
   cin.ignore(100, '\n'); 

   if (key == '0')
   {
      cout << "\nReturning to main menu..." << endl; 
      return;
   }
   else if (key == 'S')
   {
      cout << "\nS is for syllable structures and cannot be added because it cannot be removed! "
           << "Please choose something different." << endl;
   }
   else if (categories.count(key))
      cout << "\nThat category already exists! Please choose something else." << endl;
   else
   {
      do {
         cout << "\nStart entering your letters! (0 to end)" << endl; 
         cin >> temp; 

         if (temp != "0")
            letters.push_back(temp);

      } while (temp != "0");
   }

   categories.insert(std::pair<char, vector<string> >(key, letters));

   if (categories.count(key))
   {
      cout << "\nCategory added! New alphabet:" << endl; 
      display(); 
   }
   else
   {
      cout << "\nWhoops, looks like something went wrong in addCategory()! "
           << "Somebody should look into that." << endl;
   }
}

/* CHANGE CATEGORY ***********************************************************
 * Purpose: alter a pre-existing category. User selects a category, then
 *          enters letters to add or remove.
 */
void Alpha :: changeCategory()
{
   char key;
   string letter;

   display();

   cout << "\nCategory to change (0 to backup): "; 
   cin >> key;
   cin.clear();
   cin.ignore(100, '\n');

   if (key == '0')
   {
      cout << "\nReturning to main menu...\n" << endl;
      return;
   }
   else if (!categories.count(key))
   {
      cout << "\nYou can't change a category that doesn't exist! Returning to main menu..." << endl;
      return;
   }

   do {
      cout << "\nCombination to remove or add (0 to end): "; 
      cin >> letter;
      cin.clear(); 
      cin.ignore(100, '\n');

      if (find(categories[key].begin(), categories[key].end(), letter) != categories[key].end())
      {
         categories[key].erase(remove(categories[key].begin(), categories[key].end(), letter), categories[key].end()); 
      }
      else if (letter != "0")
         categories[key].push_back(letter);

      cout << "\nChanged alphabet: " << endl;
      display(); 

   } while (letter != "0");
}

/* DELETE CATEGORY ***********************************************************
 * Purpose: Deletes an entire category
 */
void Alpha :: deleteCategory()
{
   char key;
   char decision;

   cout << "Please enter the name of the category you wish to delete (0 to backup): "; 
   cin >> key; 
   cin.clear(); 
   cin.ignore(100, '\n');

   if (key == '0')
   {
      cout << "\nNothing deleted. Returning to main menu..." << endl;
      return; 
   }
   else if (key == 'S' || key == 's')
   {
      cout << "\nCannot delete the syllables category. Returning to main menu..." << endl;
      return; 
   }
   else if (!categories.count(key))
   {
      cout << "\nThat category does not exist! Returning to main menu..." << endl; 
   }
   else 
   {
      cout << "\nYou want to delete " << key << " (y/n)? ";
      cin >> decision;
      cin.clear(); 
      cin.ignore(100, '\n');

      if (decision == 'n' || decision == 'N')
      {
         cout << "\nNothing deleted. Returning to main menu..." << endl; 
         return;
      }
   }
   categories.erase(key);
}


/* DISPLAY *******************************************************************
 * Purpose: display the current alphabet and syllable structures
 */
void Alpha :: display()
{
   map<char, vector<string> >::iterator mapIt;
   vector<string>::iterator vecIt;

   cout << endl; 

   for (mapIt = categories.begin(); mapIt != categories.end(); ++mapIt)
   {
      cout << mapIt->first << ':' << ' ';

      for (vecIt = mapIt->second.begin(); vecIt != mapIt->second.end(); ++vecIt)
         cout << *vecIt << ' ';

      cout << endl; 
   }
}

// OPERATORS

/* WRITING OPERATOR **********************************************************
 * Purpose: a writing ofstream operator
 */

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

string& Alpha::operator()(int key, int index)
{
   //if (key > categories.size() || key < 1 || index > categories[key].size() || index < 0)

   return categories[key][index];
}

string& Alpha::operator()(char key, int index)
{
  // if (!categories.count(key) || index > categories[key].size() || index < 0)

   return categories[key][index];
}

vector<string>& Alpha::operator()(char key)
{
  // if (!categories.count(key))
      
   return categories[key];
}

vector<string>& Alpha::operator()(int key)
{
  // if (key > categories.size() || key < 0)

   return categories[key];
}
