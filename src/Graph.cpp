//version 3
#include "Graph.h"
#include "tarjan.h"
#include "utility.h"

using namespace std;

Graph::Graph() {}

void Graph::addPair(string str1, string str2) {
    if (vertices.find(str1) == vertices.end()) {
        pair<Product*, vector<Edge>> newPair1 = make_pair(new Product(str1), vector<Edge>());
        vertices[str1] = newPair1;
    }
    if (vertices.find(str2) == vertices.end()) {
        pair<Product*, vector<Edge>> newPair2 = make_pair(new Product(str2), vector<Edge>());
        vertices[str2] = newPair2;
    }
    vertices[str1].second.push_back(Edge(vertices[str1].first, vertices[str2].first));
}

map<string, pair<Product*, vector<Edge>>>& Graph::getGraph() {
    return vertices;

}

map<int, vector<Product*>> Graph::getSCCs() {
    vector<int> lowLink = findSCCs(*this);
    map<int, vector<Product*>> map;
    auto it = vertices.begin();
    for (unsigned int i = 0; i < lowLink.size(); i++) {
        map[lowLink[i]].push_back(it->second.first);
        it++;
    }
    return map;
}

pair<string, double> Graph::getMostPopular(vector<Product*> scc) {
    size_t ind = 0;
    double cur = -9999;
    for (size_t i = 0; i < scc.size(); i++) {
        auto pr = scc.at(i)->PageRank();
        if (pr >= cur) {
            cur = pr;
            ind = i;
        }
    }
    auto toReturn = make_pair(scc.at(ind)->label, scc.at(ind)->PageRank());
    return toReturn;
}

void Graph::printSCCs() {
    for (auto i: getSCCs()) {
        cout << "[ ";
        for (auto j: i.second) {
            cout << (*j).label << " ";
        }
        cout << "]" << endl;
        cout << "The most Popular Product in this SCC is Product " + getMostPopular(i.second).first + 
            " with the PageRank value to be " + to_string(getMostPopular(i.second).second) << endl;
    }
}

void Graph::fileToGraph(string filename) {
    ifstream infile(filename);
    string line;
    while (getline(infile, line))
    {
        string from;
        string to;
        for (unsigned int i = 0; i < line.size(); i++) {
            if (line[i] == '\t' || line[i] == ' ') {
                from = line.substr(0, i);
                to = line.substr(i + 1);
                break;
            }
        }
        // cout << from << "->" << to << endl;
        addPair(from, to);
    }
}


void Graph::setID() {
    int num = 0;
    for (auto i: vertices) {
        (i.second.first)->id = num;
        num++;
    }
}

void Graph::print() {
    for (auto i: vertices) {
        // cout << i.first.label << "'s id: " << i.first.id << ". Connected to: ";
        cout << (*i.second.first).label << " is connected to: ";
        if (i.second.second.size() == 0) {
            cout << "N/A" << endl;
        } else {
            for (auto j: i.second.second) {
                // cout << j.to.label << "(" << j.to.id << ")" << " ";
                cout << (*j.to).label << " ";
            }
            cout << endl;
        }
    }
}


// Method to compute the PageRank values for all pages in the web
void Graph::ComputePageRanks(double damping_factor, int num_iterations) {
    double n = (double) vertices.size(); //total number of products

    for (auto it = vertices.begin(); it != vertices.end(); it++) {
        Product* p = it->second.first;
        p->set_PageRank(1 / n);
        // cout << "Pagerank value for Product " + p->label + ": " + to_string(p->PageRank()) << endl;
    }


    for (int i = 0; i < num_iterations; ++i) {
    // For each page in the web, compute its new PageRank value
        for (auto it = vertices.begin(); it != vertices.end(); it++) {
            auto pair = it->second;
            Product* from = pair.first;
            for (Edge e : pair.second) {
                double linkNum = (double) pair.second.size();
                Product* to = e.to;
                if (linkNum != 0) {
                    to->newPR += damping_factor * (from->PageRank() / linkNum);
                } else {
                    to->newPR += damping_factor * (from->PageRank() / n);
                }
            }
        }
        for (auto it = vertices.begin(); it != vertices.end(); it++) {
            Product* p = it->second.first;
            p->set_PageRank((1.0 - damping_factor) / n + p->newPR);
            p->newPR = 0;
        }
    }
}



