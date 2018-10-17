#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "pass1.h"

using namespace std;


int main(){

std::vector<vector<string>> code(1000);
std::vector<int> location;
    int lines = readFile(code);
    addressCounter(code,location,lines-1);
    for(int i=0 ; i<location.size(); i++)
        cout<<hex<<location[i]<<endl;


//        for(int c=0;c<code.size();c++)
//            for(int j=0;j<code[c].size();j++)
//                cout<<code[c][j]<<endl;


        return 0;
}

