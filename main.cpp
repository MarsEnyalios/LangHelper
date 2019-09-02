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

#include "alpha.h"

using std::vector; using std::map;

int main()
{
   // test default values and display
   Alpha alphabet; // create the object, this should use the auto initializer

   alphabet.display(); // test display method body

   vector<string> category;
   
}
