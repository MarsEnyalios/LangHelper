/*****************************************************************************
 * Program: Root Generator v 0.3.2 - GNU 2.0 License (or later) @author
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
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <set>

#include "alpha.h"

using std::vector; using std::map; using std::set; using std::string; 
using std::cout; using std::cin; using std::endl;
using std::ofstream; using std::ifstream; 

// prototypes
Alpha loadProject();
void saveProject(Alpha alpha);
void generateRoots(Alpha alpha, string counter);
void saveRoots(); 

int main()
{
   int menuChoice = 0;
   char save = ' ';
   Alpha alpha;
   int count = 0; // increments based on how many times/sessions 
                  // this program has been run in this folder
   string counter = ""; // for filenames
   // TODO: make a secondary counter that increases each time the alphabet changes 
   // (not sylls tho), like "root_session_0-0, root_session_0-1"

   ifstream fin;
   ofstream fout;
   
   fin.open("counter.txt");
   
   if (fin.fail())
   {
      fout.open("counter.txt"); 
      fout << count; 
      fout.close(); 
   }
   else
   {
      fin >> count; 
      fin.close();
   }

   counter = std::to_string(count);

   cout << "Welcome to the Root Generator version 0.3.2!\n" << endl
        << "\t1. Load Project\n"
        << "\t2. Default Values\n" << endl;

   do {
      cout << "Your choice: ";

      cin >> menuChoice;
      cin.clear();
      cin.ignore(100, '\n');

      if (menuChoice < 1 || menuChoice > 2)
         cout << "\nNot an option! Try again.\n" << endl;
   } while (menuChoice < 1 || menuChoice > 2);

   if (menuChoice == 1)
   {
      Alpha temp(loadProject()); // i want to use my copy constructor gdi
      alpha = temp; 
   }

   do {

     cout << "\nMAIN MENU\n" << endl
          << "\t1. Generate Roots\n"
          << "\t2. View Alphabet & Syllables\n"
          << "\t3. Change A Category\n"
          << "\t4. Add Category\n"
          << "\t5. Delete a Category\n"
          << "\t6. Save Project\n"
          << "\t7. Exit\n" << endl

          << "Your choice: "; 

     cin >> menuChoice; 
     cin.clear(); 
     cin.ignore(100, '\n'); 

      if (menuChoice < 1 || menuChoice > 7)
         cout << "Not an option! Try again.\n" << endl; 
      else if (menuChoice == 1)
         generateRoots(alpha, counter); 
      else if (menuChoice == 2)
         alpha.display(); 
      else if (menuChoice == 3)
         alpha.changeCategory();
      else if (menuChoice == 4)
         alpha.addCategory();
      else if(menuChoice == 5)
         alpha.deleteCategory();
      else if (menuChoice == 6)
         saveProject(alpha);
      else if (menuChoice == 7)
      {
         cout << "Any unsaved progress will be lost. Would you like to save (y/n)? ";

         cin >> save;
         cin.clear(); 
         cin.ignore(100, '\n');

         if (save == 'y' || save == 'Y')
         {
            cout << "\nOkay! Saving!"; 
            saveProject(alpha);
         }
         else
            cout << "A'ight, bye now!"; 
      }
   } while (menuChoice != 7);

   ++count;

   fout.open("counter.txt", std::ios::out); 
   fout << count; 
   fout.close(); 

   return 0;
}

/* GENERATE ROOTS ************************************************************
 * Purpose:
 */
void generateRoots(Alpha alpha, string counter)
{

   set<string> roots; // save roots to this
   set<string> fileRoots; // use this to eliminate duplicates in a session
   int index = 0; 
   char key = ' ';
   string letter = "";
   string root = ""; // individual roots
   int size = 0;
   vector<string> sylls = alpha.getCategory('s');
   string temp2 = ""; 
   int plays = 0;
   string filename = "root_session_"; 

   ifstream fin; 
   ofstream fout;

   cout << "\nHow many times to run? Up to 50: "; 
   cin >> plays;
   cin.clear(); 
   cin.ignore(100, '\n');
   
   cout << "\nGenerating roots...\n" << endl;

   for (int k = 0; k < plays; ++k)
   {
      for (int i = 0; i < sylls.size(); ++i)
      {
         root = "";
         // iterate through individual letters in syllable values
         temp2 = sylls[i];
         for (int j = 0; j < temp2.size(); ++j)
         {
            key = temp2[j]; // assign category
            size = alpha.getCategory(key).size(); // rand limit
            index = rand() % size; // the random selection from the category
            letter = alpha(key, index); 
            root += letter;

            cout << letter;
         }
         cout << " ";
         roots.insert(root);
      }
      cout << endl;
   }

   filename += counter; 
   filename += ".txt";
   
   fin.open(filename.c_str());

   if (fin.is_open())
   {
      while (fin >> root)
      {
         cout << root << " "; 
         fileRoots.insert(root); 
      }
      fin.close();
   }

   fileRoots.insert(roots.begin(), roots.end());

   fout.open(filename.c_str());

   for(set<string>::const_iterator i = fileRoots.begin(); i != fileRoots.end(); ++i)
      fout << *i << '\n';

   fout.close();
}

/* SAVE ROOTS ****************************************************************
 * Purpose: save roots to a file
 */
void saveRoots()
{

}

/* LOAD PROJECT **************************************************************
 * Purpose: load a project from text files
 */
Alpha loadProject()
{
   
}

/* SAVE PROJECT **************************************************************
 * Purpose: save Alphabet and roots to separate files
 */
void saveProject(Alpha alpha)
{
   // TODO: boolean verification of save working
}
