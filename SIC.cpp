#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "pass1.h"
using namespace std;


int main(){

std::vector<vector<string>> code(1000);
    readFile(code);
//        for(int c=0;c<code.size();c++)
//            for(int j=0;j<code[c].size();j++)
//                cout<<code[c][j]<<endl;

cout<<getStartAddress(code);


        return 0;
}
