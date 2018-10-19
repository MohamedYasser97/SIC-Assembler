#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "pass1.h"
#include "pass2.h"
#include "optable.h"

using namespace std;


int main(){
    bool battleRoyale = false;
    std::vector<vector<string>> code(1000);
    std::vector<int> location;
    std::map<string,int> symbolTable;
    std::map<std::string,std::string>opTable;
    std::vector<std::string>objectCode;

    int lines = readFile(code);
    addressCounter(code,location,lines-1);
    createSymbolTable(code,location,symbolTable,lines-1);
    printSymbolTable(symbolTable);
    initOpTable(opTable);
    generateOpcode(code,objectCode,opTable,lines-1);
    generateAddresses(code,objectCode,symbolTable,lines-1);

//    for(int i=0 ; i<location.size(); i++)
//        cout<<hex<<location[i]<<endl;
//

//    for( std::map<string,string>::const_iterator it = opTable.begin(); it != opTable.end(); ++it )
//    {
//      string value = it->first;
//      string key = it->second;
//      cout<<value<<"\t"<<key<<endl;
//
//    }

    for(int i=0;i<objectCode.size();i++)
        cout<<objectCode[i]<<endl;

//        for(int c=0;c<code.size();c++)
//            for(int j=0;j<code[c].size();j++)
//                cout<<code[c][j]<<endl;


        return 0;
}

