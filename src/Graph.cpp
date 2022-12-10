#include "Graph.h"
#include "tarjan.h"
#include "utility.h"
// #include <iterator>

Graph::Graph() {}

bool Graph::addProduct(Product v) {
    if (vertices.find(v) == vertices.end()) {
        product_.push_back(v);
        vertices[v] = vector<Edge>();
        return true;
    }
    // std::cout << "Product already exists" << std::endl;
    return false;
}

bool Graph::addProduct(string str) {
    return addProduct(Product(str));
}

bool Graph::addEdge(Product& from, Product& to, int label) {
    if (std::find(vertices[from].begin(), vertices[from].end(), Edge(from, to, label)) == vertices[from].end()) {
        vertices[from].push_back(Edge(from, to, label));
        // from.links_.push_back(to); //used in pageRank
        // cout << "ln 25 " + from.links_[0].label << endl;
        return true;
    }
    // std::cout << "Edge from " << from.label << " to " << to.label << " already exists" << std::endl;
    return false;
}

// void Graph::convertV2D(const string & filename, const int size) {
//     V2D network = file_to_V2D(filename, size);
//     for (size_t i = 0; i < network.size(); i++) {
//         cout << "ln: " + to_string(i) << endl;
//         Product from(stoi(network[i][0])); Product to(stoi(network[i][1]));
//         // cout << "REACH ln21 " + to_string(from.label) + " " + to_string(to.label) << endl;
//         // cout << to_string(vertices.find(from) == vertices.end()) << endl;
//         cout << to_string(from == to) << endl;
//         if (vertices.find(from) == vertices.end()) {
//             addProduct(from);
//             cout << "ln24: " + to_string(from.label) << endl;
//         }
//         // if (vertices.find(to) == vertices.end()) {
//         //     addProduct(to);
//         // }
//         cout << "REACH ln33 " + to_string(from.label) << endl;
//         addEdge(from, to, from.label);
//     }
// }

map<Product, vector<Edge>>& Graph::getGraph() {
    return vertices;
}

map<int, vector<Product>> Graph::getSCCs() {
    vector<int> lowLink = findSCCs(*this);
    map<int, vector<Product>> map;
    auto it = vertices.begin();
    for (unsigned int i = 0; i < lowLink.size(); i++) {
        map[lowLink[i]].push_back(it->first);
        it++;
    }
    return map;
}

void Graph::printSCCs() {
    for (auto i: getSCCs()) {
        cout << "[ ";
        for (auto j: i.second) {
            cout << j.label << " ";
        }
        cout << "]" << endl;
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
        addProduct(from);
        addProduct(to);
        Product f = Product(from);
        Product t = Product(to);
        // f.links_.push_back(t);
        // addEdge(Product(from), Product(to), 0);
        addEdge(f, t, 0);
    }
}

void Graph::setID() {
    int num = 0;
    for (auto i: vertices) {
        setID(i.first, num);
        num++;
    }
    for (auto& i: vertices) {
        for (auto& j: i.second) {
            if (j.to.id == -1) {
                Product p = vertices.find(j.to)->first;
                j.to.id = p.id;
            }
        }
    }
}

void Graph::setID(Product p, int id) {
    auto it = vertices.find(p);
    Product newP = it->first;
    vector<Edge> vec = it->second;
    newP.id = id;
    vertices.erase(it);
    vertices.insert(make_pair(newP, vec));
}

void Graph::print() {
    for (auto i: vertices) {
        // cout << i.first.label << "'s id: " << i.first.id << ". Connected to: ";
        cout << i.first.label << " is connected to: ";
        for (auto j: i.second) {
            // cout << j.to.label << "(" << j.to.id << ")" << " ";
            cout << j.to.label << " ";
        }
        cout << endl;
    }
}


// Method to compute the PageRank values for all pages in the web
void Graph::ComputePageRanks(double damping_factor, int num_iterations) {
  // Initialize the PageRank values to 1 / N
  
    // for (pair<Product, vector<Edge>>& product : vertices) {
    //     Product p = product.first;
    //     p.set_PageRank(1 / (double) vertices.size());
    //     cout << "Pagerank value for Product " + p.label + ": " + to_string(p.PageRank()) << endl;
    // }

    // for (int i = 0; i < num_iterations; ++i) {
    // // For each page in the web, compute its new PageRank value
    //     for (const auto& product : vertices) {
    //         Product p = product.first;
    //         double sum = 0.0;
    //     //   for (Product link : p.links_) {
    //     //     sum += link.PageRank() / link.links_.size();
    //     //   }
    //         for (Edge e : product.second) {
    //             auto linkNum = vertices[e.to].size();
    //             if (linkNum != 0) {
    //                 sum += e.to.PageRank() / linkNum;
    //             } else {
    //                 sum += e.to.PageRank() / vertices.size();
    //             }
    //         }
    //         p.set_PageRank((1.0 - damping_factor) + damping_factor * sum);
    //         cout << "Pagerank value for Product " + p.label + ": " + to_string(p.pageRank) << endl;
    //     }
    // for (int i = 0; i < num_iterations; ++i) {
    //     double N = (double) vertices.size();
    // // For each page in the web, compute its new PageRank value
    //     for (auto product : vertices) {
    //         Product p = product.first;
    //         cout << to_string(p.PageRank()) << endl;
    //         cout << "Product link size: " + to_string(product.second.size()) << endl;
    //         for (Edge e : product.second) {
    //             double linkNum = (double) vertices[e.to].size();
    //             cout << "Number of links for Product " + e.to.label + ": " + to_string(linkNum) << endl;
    //             cout << "PR value: " + to_string(e.to.pageRank) << endl;
    //             if (linkNum != 0) {
    //                 e.to.newPR += damping_factor * (e.to.PageRank() / linkNum);
    //                 cout << "New PR value: " + to_string(e.to.pageRank) << endl;
    //             } else {
    //                 e.to.newPR += damping_factor * (e.to.PageRank() / N);
    //             }
    //         }
    //         p.set_PageRank((1.0 - damping_factor) / N + newPR);
    //         // cout << "Pagerank value for Product " + p.label + ": " + to_string(p.pageRank) << endl;
    //     }
    //     for (const auto& product : vertices) {
    //         auto p = product.first;
    //         p.set_PageRank((1.0 - damping_factor) / N + p.newPR);
    //         p.newPR = 0;
    //     }
    // // For each page in the web, compute its new PageRank value
    // }
    for (Product& p : product_) {
        double n = (double) product_.size();
        p.set_PageRank(1 / n);
        cout << "Pagerank value for Product " + p.label + ": " + to_string(p.PageRank()) << endl;
    }

    for (int i = 0; i < num_iterations; ++i) {
        double N = (double) product_.size();
    // For each page in the web, compute its new PageRank value
        for (Product& p : product_) {
            cout << to_string(p.PageRank()) << endl;
            cout << "Product link size: " + to_string(p.links_.size()) << endl;
            for (Product& to : p.links_) {
                double linkNum = (double) p.links_.size();
                cout << "Number of links for Product " + to.label + ": " + to_string(linkNum) << endl;
                cout << "PR value: " + to_string(to.pageRank) << endl;
                if (linkNum != 0) {
                    to.newPR += damping_factor * (to.PageRank() / linkNum);
                    cout << "New PR value: " + to_string(to.pageRank) << endl;
                } else {
                    to.newPR += damping_factor * (to.PageRank() / N);
                }
            }
            // p.set_PageRank((1.0 - damping_factor) / N + newPR);
            // cout << "Pagerank value for Product " + p.label + ": " + to_string(p.pageRank) << endl;
        }
        for (Product& p : product_) {
            p.set_PageRank((1.0 - damping_factor) / N + p.newPR);
            p.newPR = 0;
        }
    }
}

