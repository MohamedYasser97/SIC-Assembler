#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "pass1.h"

using namespace std;


int main(){
    bool battleRoyale = false;
    std::vector<vector<string>> code(1000);
    std::vector<int> location;
    std::map<string,int> symbolTable;

    int lines = readFile(code);
    addressCounter(code,location,lines-1);
    createSymbolTable(code,location,symbolTable,lines-1);
    printSymbolTable(symbolTable);

//    for(int i=0 ; i<location.size(); i++)
//        cout<<hex<<location[i]<<endl;
//

//    for( std::map<string,int>::const_iterator it = symbolTable.begin(); it != symbolTable.end(); ++it )
//    {
//      std::string value = it->first;
//      int key = it->second;
//      cout<<value<<"\t"<<key<<endl;
//
//    }


//        for(int c=0;c<code.size();c++)
//            for(int j=0;j<code[c].size();j++)
//                cout<<code[c][j]<<endl;


        return 0;
}

