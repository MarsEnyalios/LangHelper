/*****************************************************************************
 * Program: Language Helper v 0.3.1 - GNU 2.0 License (or later) @author
 * MarsEnyalios (M. Burkett)
 *
 * Purpose: This tool aids in constructing languages. The default values are
 *          the most used sounds across world languages, separated into two
 *          categories (consonants and vowels). The user can change, add, and
 *          remove categories at will, including syllable structures.
 *
 *          From these basic language  blocks, the program can generate roots,
 *          from which a conlanger can make the lexicon of a constructed
 *          language.
 *
 *****************************************************************************/
#include <vector>
#include <map>
#include <string>
#include <iostream>

#include "alpha.h"

using std::vector; using std::map; using std::string; 
using std::cout; using std::cin;

int main()
{
   // test copy constructor

   char playAgain = ' '; 
   char key = ' ';
   string letter; 
   vector<string> values;

   do
   {
      cout << "Enter a key for the new category: "; 

      cin >> key;
      cin.clear(); 
      cin.ignore(100, '\n'); 

      do {

         cout << "Enter new sound: "; 

         cin >> letter; 
         cin.clear(); 
         cin.ignore(100, '\n');

         values.push_back(letter);

      } while (letter != "x123");


      playAgain = 'y';

   } while(playAgain != 'y');

   map<char, vector<string> > testM;

   testM.insert(std::make_pair(key, values));

   Alpha alpha(testM); 

   alpha.display(); 

   // test delete function
   // TODO: do not let S be removed

   alpha.deleteCategory(key);

   alpha.display();

}
