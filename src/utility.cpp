#include "utility.h"
#include <sstream>
#include <fenv.h>
#include <signal.h>
#include <vector>

std::string file_to_string(const std::string& filename){
  std::ifstream text(filename);

  std::stringstream strStream;
  if (text.is_open()) {
    strStream << text.rdbuf();
  }
  return strStream.str();
}

int SplitString(const std::string & str1, char sep, std::vector<std::string> &fields) {
    std::string str = str1;
    std::string::size_type pos;
    while((pos=str.find(sep)) != std::string::npos) {
        fields.push_back(str.substr(0,pos));
        str.erase(0,pos+1);  
    }
    fields.push_back(str);
    return fields.size();
}

//convert to V2D while cleaning the data
V2D file_to_V2D(const string & filename, const int size) {
    string fileStr = file_to_string(filename);
    // string b = to_string(fileStr[1] == '\t'); // tab
    // cout << b << endl;
    V2D toReturn;
    vector<string> field;
    int row = SplitString(fileStr, '\n', field);

    for (auto i = 0; i < row; i++) {
        vector<string> row;
        SplitString(field[i], '\t', row);
        if (stoi(row[0]) > 0 && stoi(row[1]) > 0) { //positive id required
            if (stoi(row[0]) + stoi(row[1]) < size) { //limit the size of the dataset
                toReturn.push_back(row);
            }
        }
        
    }
    
    // test for output:
    // cout << "size: " + to_string(toReturn.size()) << endl;
    // for (size_t i = 0; i < 10; i++) {
    //     cout << "product from: " + toReturn[i][0] + " " + "product to: " + toReturn[i][1] << endl;
    // }
    return toReturn;
}
