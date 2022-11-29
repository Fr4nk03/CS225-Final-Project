#include <iostream>
#include <typeinfo>
#include "utility.h"
#include "Graph.h"
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
    // string a = "10";
    // // cout << typeid(a).name() << endl; //print i
    // cout << to_string(a.empty()) << endl;

    // //small network
    // V2D networkSmall = file_to_V2D("../data/amazon-ungraph-small.txt", 10000);
    // // cout << "10" + "\t" + "20" << endl;
    // // cout << "10\t20"[2] << endl;

    // cout << "Number of Edges: " + to_string(networkSmall.size()) << endl;
    // for (size_t i = 0; i < networkSmall.size(); i++) {
    //     cout << "product from: " + networkSmall[i][0] + " " + "product to: " + networkSmall[i][1] << endl;
    // }
    
    // //mid network
    // V2D networkMid = file_to_V2D("../data/amazon-ungraph-middle.txt", 100000);

    // cout << "Number of Edges: " + to_string(networkMid.size()) << endl;
    // for (size_t i = 0; i < networkMid.size(); i++) {
    //     cout << "product from: " + networkMid[i][0] + " " + "product to: " + networkMid[i][1] << endl;
    // }

    // // mixed spacing network
    // V2D networkMixed = file_to_V2D("../data/amazon-ungraph-mixed.txt", 10000000);
   
    // cout << "Number of Edges: " + to_string(networkMixed.size()) << endl;
    // for (size_t i = 0; i < networkMixed.size(); i++) {
    //     cout << "product from: " + networkMixed[i][0] + " " + "product to: " + networkMixed[i][1] << endl;
    // }

    // whole network
    // V2D networkLarge = file_to_V2D("../data/amazon-ungraph.txt", 10000);

    // cout << "Number of Edges: " + to_string(networkLarge.size()) << endl;
    // for (size_t i = 0; i < networkLarge.size(); i++) {
    //     cout << "product from: " + networkLarge[i][0] + " " + "product to: " + networkLarge[i][1] << endl;
    // }

    //test for Graph
    Graph whole;
    // whole.convertV2D("../data/amazon-ungraph.txt", 10000);
    // map<Product, vector<Edge>> connections = whole.getGraph();
    // map<Product, vector<Edge>>::iterator itr = connections.begin();
    // cout << "product from: " + to_string(itr->first.id) + " with edges: ";
    // for (size_t i = 0; i < itr->second.size(); i++) {
    //     cout << to_string(itr->second[i].dest.id) + " " << endl;
    // }

}
