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
#include <iostream>

#include "alpha.h"

using std::vector; using std::map; using std::string; 
using std::cout; using std::cin; using std::endl;

// prototypes
Alpha loadProject();
void saveProject(Alpha alpha);
void generateRoots(Alpha alpha);

int main()
{
   int menuChoice = 0;
   char save = ' ';
   Alpha alpha;

   cout << "Welcome to the Root Generator version 0.3.2!\n" << endl
        << "\t1. Load Project\n"
        << "\t2. Default Values\n" << endl; 

   do {
      cout << "Your choice: ";

      cin >> menuChoice;
      cin.clear(); 
      cin.ignore(100, '\n'); 

      if (menuChoice < 1 || menuChoice > 2 || !isdigit(menuChoice))
         cout << "Not an option! Try again.\n" << endl; 
   } while (menuChoice < 1 || menuChoice > 2); 



   if (menuChoice == 1)
   {
      Alpha temp(loadProject());
      alpha = temp; 
   }

   do {

     cout << "MAIN MENU" << endl
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

      if (menuChoice < 1 || menuChoice > 7 || !isdigit(menuChoice))
         cout << "Not an option! Try again.\n" << endl; 
      else if (menuChoice == 1)
         generateRoots(alpha); 
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

   return 0; 
}

void generateRoots(Alpha alpha)
{

}

Alpha loadProject()
{
   
}

void saveProject(Alpha alpha)
{


   // TODO: boolean verification of save working
}
