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
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <cctype>

#include "alpha.h"

using std::vector; using std::map; using std::set; using std::string; 
using std::cout; using std::cin; using std::endl;
using std::ofstream; using std::ifstream; 
using std::stringstream;

// prototypes
Alpha loadProject();
void saveProject(Alpha alpha);
void generateRoots(Alpha alpha, int sessionCounter, int alphabetCounter);
string getFilename();

int main()
{
   int menuChoice = 0;
   char save = ' ';
   Alpha alpha;   // object to hold alphabet and syllable structures
   int sessionCounter = 0;  // increments per session (stores in counter.txt)
   int alphabetCounter = 0; // (optionally) increments each alphabet change
                            // Does NOT need storing as the value would always be 0

   ifstream fin;
   ofstream fout;
   
   fin.open("counter.txt");
   
   if (fin.fail()) // if counter.txt does not exist, create a new one & fill
   {               // with the default value 0
      fout.open("counter.txt"); 
      fout << sessionCounter;
      fout.close();
   }
   else            // otherwise, import the last saved session counter
   {
      fin >> sessionCounter;
      fin.close();
   }

   // Run the main options
   cout << "Welcome to the Root Generator version 0.3.3!\n" << endl
        << "\t1. Load alphabet\n"
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
         generateRoots(alpha, sessionCounter, alphabetCounter);
      else if (menuChoice == 2)
         alpha.display();
      else if (menuChoice == 3)
         alpha.changeCategory(alphabetCounter);
      else if (menuChoice == 4)
      {
         alpha.addCategory();
         cout << "\nDon't forget to update syllables if needed" << endl;
      }
      else if(menuChoice == 5)
      {
         alpha.deleteCategory();
         cout << "\nBe sure to update syllables if needed or else things will break" << endl;
      }
      else if (menuChoice == 6)
         saveProject(alpha);
      else if (menuChoice == 7)
      {
         cout << "Any unsaved alphabet will be lost. Would you like to save (y/n)? ";

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

   ++sessionCounter;

   fout.open("counter.txt", std::ios::out); 
   fout << sessionCounter << endl;
   fout.close(); 

   return 0;
}

/* GENERATE ROOTS ************************************************************
 * Purpose:
 */
void generateRoots(Alpha alpha, int sessionCounter, int alphabetCounter)
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

   // saves roots in file named "root_session_(sessionCounter)_(alphabetCounter)"
   filename += std::to_string(sessionCounter);
   filename += "-";
   filename += std::to_string(alphabetCounter);
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

/* LOAD PROJECT **************************************************************
 * Purpose: load a project from text file
 */
Alpha loadProject()
{
   Alpha alpha; // save input here 
   char key = 'X';
   string longTemp = "";
   string temp = ""; 
   vector<string> letters; 
   bool repeat = true; // for the do-while
   char retry = 'n'; // for if the file can't be found

   ifstream fin;

   do 
   {
      string filename = getFilename();

      fin.open(filename.c_str());
      if (fin.is_open())
      {
         while (isalnum(fin.peek()))
         { 
            fin >> key;
            cout << key << endl; 
               
            getline(fin, longTemp); 
            cout << longTemp << endl << endl;

            stringstream ss(longTemp);

            while (ss >> temp)
               letters.push_back(temp);

            alpha.loadCategory(key, letters);

            letters.clear(); 
         }

         repeat = false;
         fin.close();
      }
      else
      {
         cout << "Can't open that file. Try a different file y/n? ";
         cin >> retry;
         cin.clear(); 
         cin.ignore(100, '\n');

         if (retry == 'n' || retry == 'N')
         {
            repeat = false;
            cout << "Default values will be loaded.\n" << endl;
         }
      }
   } while (repeat);

   return alpha;
}

/* SAVE PROJECT **************************************************************
 * Purpose: save Alphabet to a file
 */
void saveProject(Alpha alpha)
{
   ofstream fout; 

   string filename = getFilename();

   fout.open(filename.c_str());

   if (fout.is_open())
   {
      fout << alpha;
   }
   else
      cout << "Something went wrong opening the file for writing." << endl;

   fout.close();
}

/* GET FILENAME **************************************************************
 * Purpose: prompts user for a filename
 */
string getFilename()
{
   string filename = "";

   cout << "Filename (do not include '.txt'): "; 
   getline(cin, filename);

   filename += ".txt";
   
   return filename; 
}
