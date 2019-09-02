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
}
