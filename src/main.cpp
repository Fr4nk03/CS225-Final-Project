#include <iostream>
#include "utility.h"

using namespace std;

int main() {
    //test split string by space
    // string a = "10 20\n30 40\n50 60";
    // // vector<string> b;
    // // SplitString(a, ' ', b);
    // // cout << b[0] << endl;
    // // cout << b[1] << endl;
    // cout << a << endl;
    // vector<string> field;
    // SplitString(a, '\n', field);
    // for (auto i = 0; i < 2; i++) {
    //     cout << field[i] << endl;
    // }
    

    //small network
    V2D networkSmall = file_to_V2D("../amazon-ungraph-small.txt");
    // cout << "10" + "\t" + "20" << endl;
    // cout << "10\t20"[2] << endl;

    cout << "Number of Products: " + to_string(networkSmall.size()) << endl;
    for (size_t i = 0; i < networkSmall.size(); i++) {
        cout << "product from: " + networkSmall[i][0] + " " + "product to: " + networkSmall[i][1] << endl;
    }
    
    //mid network
    V2D networkMid = file_to_V2D("../amazon-ungraph-middle.txt");

    cout << "Number of Products: " + to_string(networkMid.size()) << endl;
    for (size_t i = 0; i < networkMid.size(); i++) {
        cout << "product from: " + networkMid[i][0] + " " + "product to: " + networkMid[i][1] << endl;
    }
}
