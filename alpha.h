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
   Alpha(map<char, vector<string> > categories);

   map<char, vector<string> > getCategories(); // return entire map
   vector<string> getCategory(char key); // returns one category

   void changeCategory(int& count2); // use vector insert and erase functions
   void addCategory(); // use map insert

   void loadCategory(char key, vector<string> letters); 

   void deleteCategory(); // use map erase

   void display(); // always use this to display to user, never cout

   // OPERATORS

   friend ostream& operator<<(ostream& os, Alpha& alpha); // only use to write!
   
   string& operator()(int key, int index); // returns a string from vector
   string& operator()(char key, int index);

   vector<string>& operator()(char key);
   vector<string>& operator()(int key); 
};

#endif // ALPHA_H
