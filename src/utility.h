#include <utility>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cassert>
#include <fstream>

using namespace std;
string file_to_string(const string & filename);

//used to seperate lines
int SplitString(const string & str1, char sep, vector<string> &fields);

typedef vector<vector<string> > V2D; 

//simultaneously cleaning up products with id < size
V2D file_to_V2D(const string & filename, const int size);
