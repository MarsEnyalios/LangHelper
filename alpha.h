/*****************************************************************************
 * File: alpha.h
 * @author MarsEnyalios
 */

#ifndef ALPHA_H
#define ALPHA_H

#include <vector>
#include <map>
#include <iostream>

using std::string; using std::vector; using std::map;
using std::ostream; using std::istream;

/**== CLASS ALPHA ============================================================
 * 
 * "categories" refers to how phenomes are sorted (e.g. consonants, vowels).
 */
class Alpha 
{
private: 
   map<char, vector<string> > categories;
public:
   Alpha(); 
      Alpha(map<char, vector<string> > cat);

   map<char, vector<string> > getCategories(); // return entire map
   map<char, vector<string> >::iterator getCategory(char key); // returns one category

   bool addCategory(char name, vector<string> category); // use map insert

   /* instead of having a separate member function for syllables, just use this &
    * pass S. Use map [] operator.*/
   void changeCategory(char key, vector<string> category);

   void deleteCategory(char key); // use map erase

   void display(); // always use this to display to user, never cout

   friend ostream& operator<<(ostream& os, Alpha& alpha); // only use to write!
};

#endif // ALPHA_H
