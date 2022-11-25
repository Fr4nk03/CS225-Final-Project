#include <iostream>
#include "utility.h"

using namespace std;

int main() {

    V2D network = file_to_V2D("../amazon-ungraph.txt");

    for (int i = 0; i < (int) network.size(); ++i){
        std::cout << "{ ";
        for(int j = 0; j < (int) network[i].size()-1; ++j){
        std::cout << network[i][j] << ", ";
        }
        std::cout << network[i][network[i].size()-1] << "}, \\" << std::endl;
    }
    

}
