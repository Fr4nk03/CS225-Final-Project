#include <iostream>
#include <typeinfo>
#include <fstream>
#include "utility.h"
#include "Graph.h"
#include "tarjan.h"

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
 // cout << field[i] << endl; 
 // } 
 // string a = "10"; 
 // // cout << typeid(a).name() << endl; //print i 
 // cout << to_string(a.empty()) << endl; 
   // //small network 
//  V2D networkSmall = file_to_V2D("/workspaces/cs225/release-f22/CS225-Final-Project/data/test.txt", 10000); 
//  // cout << "10" + "\t" + "20" << endl; 
//  // cout << "10\t20"[2] << endl; 
//    cout << "Number of Edges: " + to_string(networkSmall.size()) << endl; 
//  for (size_t i = 0; i < networkSmall.size(); i++) { 
//  cout << "product from: " + networkSmall[i][0] + " " + "product to: " + networkSmall[i][1] << endl; 
//  } 
   // //mid network 
 // V2D networkMid = file_to_V2D("../amazon-ungraph-middle.txt", 100000); 
   // cout << "Number of Edges: " + to_string(networkMid.size()) << endl; 
 // for (size_t i = 0; i < networkMid.size(); i++) { 
 // cout << "product from: " + networkMid[i][0] + " " + "product to: " + networkMid[i][1] << endl; 
 // } 
   // // mixed spacing network 
 // V2D networkMixed = file_to_V2D("../amazon-ungraph-mixed.txt", 10000000); 
   // cout << "Number of Edges: " + to_string(networkMixed.size()) << endl; 
 // for (size_t i = 0; i < networkMixed.size(); i++) { 
 // cout << "product from: " + networkMixed[i][0] + " " + "product to: " + networkMixed[i][1] << endl; 
 // } 
   // whole network 
//  V2D networkLarge = file_to_V2D("../amazon-ungraph.txt", 10000); 
//    cout << "Number of Edges: " + to_string(networkLarge.size()) << endl; 
//  for (size_t i = 0; i < networkLarge.size(); i++) { 
//  cout << "product from: " + networkLarge[i][0] + " " + "product to: " + networkLarge[i][1] << endl; 
//  } 
Graph g;
    g.fileToGraph("/workspaces/CS225-Final-Project/data/amazon-ungraph-mixed.txt");
    g.print();
    // See this example at https://www.youtube.com/watch?v=wUgWX0nc4NY
    // g.printSCCs();
    g.ComputePageRanks(0.85, 100);
    // for (auto p: g.getGraph()) {
    //     cout << p.first.PageRank() << endl;
    // }
    // for (auto i : g.getGraph()) {
    //     // cout << "from " + i.first.label << endl;
    //     // cout << to_string(i.first.links_.size()) << endl;
    //     for (auto p : i.first.links_) {
    //         cout << "hello" << endl;
    //         cout << p.label << endl;
    //     }
    // }
}
