#include <iostream>
#include <typeinfo>
#include <fstream>
#include "utility.h"
#include "Graph.h"

using namespace std;

int main() {
<<<<<<< HEAD
    Graph g;
    ifstream infile("/workspaces/cs225/release-f22/CS225-Final-Project/data/amazon-ungraph-small.txt");
    string line;
    while (getline(infile, line))
    {
        string from;
        string to;
        for (unsigned int i = 0; i < line.size(); i++) {
            if (line[i] == '\t') {
                from = line.substr(0, i);
                to = line.substr(i + 1);
                break;
=======
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
    // V2D networkMid = file_to_V2D("../data/amazon-ungraph-middle.txt", 10000);

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
    // V2D networkLarge = file_to_V2D("../data/amazon-ungraph.txt", 1000);

    // cout << "Number of Edges: " + to_string(networkLarge.size()) << endl;
    // for (size_t i = 0; i < networkLarge.size(); i++) {
    //     cout << "product from: " + networkLarge[i][0] + " " + "product to: " + networkLarge[i][1] << endl;
    // }

    //test for Graph
    Graph whole;
    whole.convertV2D("../data/amazon-ungraph-middle.txt", 10000);
    map<int, vector<Edge>> connections = whole.getGraph();
    map<int, vector<Edge>>::iterator itr;
    //  = connections.begin();
    for (itr = connections.begin(); itr != connections.end(); itr++) {
        cout << "product from: " + to_string(itr->first) + " with edges: ";
        for (size_t i = 0; i < itr->second.size(); i++) {
            cout << to_string((itr->second)[i].dest.label) + " ";
            if (i == itr->second.size() - 1) {
                cout << " end" << endl;
>>>>>>> 4d2905cac319353873d990521a17c7b5ae377bc9
            }
        }
        g.addProduct(from);
        g.addProduct(to);
        g.addEdge(Product(from), Product(to), 0);
    }
<<<<<<< HEAD
    vector<Edge> vec = g.getGraph()[Product("1")];
    for (Edge i: vec) {
        cout << i.dest.label << " ";
    }
    cout << endl;
=======
    // ifstream file("../data/amazon-ungraph-middle.txt");
    // string str; 
    // while (getline(file, str))
    // {
    //     cout << str << endl;
    // }
>>>>>>> 4d2905cac319353873d990521a17c7b5ae377bc9
}
