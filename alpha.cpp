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
/*
   map<char, vector<string> > const temp {
      { 'S', { "cvc", "vcv", "cvcc", "vvc", "ccv"} },
      { 'C', { "k", "m", "n", "p", "q", "t" } },
      { 'V', { "a", "e", "i", "o", "u"} }
   };*/
}
