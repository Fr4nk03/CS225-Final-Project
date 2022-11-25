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

std::string TrimRight(const std::string & str) {
    std::string tmp = str;
    return tmp.erase(tmp.find_last_not_of(" ") + 1);
}

std::string TrimLeft(const std::string & str) {
    std::string tmp = str;
    return tmp.erase(0, tmp.find_first_not_of(" "));
}

std::string Trim(const std::string & str) {
    std::string tmp = str;
    return TrimLeft(TrimRight(str));
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

V2D file_to_V2D(const string & filename) {
    string fileStr = file_to_string(filename);
    V2D toReturn;
    vector<string> field;
    int row = SplitString(fileStr, '\n', field);
    cout << fileStr << endl;

    for (auto i = 0; i < row; i++) {
        vector<string> row;
        int n = SplitString(field[i], ' ', row);
        vector<string> newRow;
        for (auto j = 0; j < n; j++) {
            newRow.push_back(Trim(row[j]));
        }
        toReturn.push_back(newRow);
    }

    //test for output:
    // for (size_t i = 0; i < toReturn.size(); i++) {
    //     for (size_t j = 0; j < toReturn[i].size(); j++) {
    //         cout << toReturn[i][j] << endl;
    //         cout << "item " + to_string(i) + " " + to_string(j) << endl;
    //     }
    // }
    return toReturn;
}
