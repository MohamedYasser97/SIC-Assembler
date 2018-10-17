#ifndef PASS1_H
#define PASS1_H

#include <fstream>
#include <vector>
#include <sstream>
#include <map>
    int readFile(std::vector<std::vector<std::string>> &code){

        std::ifstream inFile("in.txt");
        std::string temp;
        std::string tempNoSpace="";
        int i=0;

        while (std::getline(inFile, temp)){

            for(int j=0;j<temp.size();j++){

                if(temp[j] != ' ' && temp[j] != '\t' && temp[j] != '\n' && temp[j] != '\0'){
                    tempNoSpace+=temp[j];

                }else{
                    code[i].push_back(tempNoSpace);
                    tempNoSpace.clear();
                }

            }

            code[i++].push_back(tempNoSpace);
            tempNoSpace.clear();
        }

        return i;
    }


    int hexToDec(std::string str){

        int address;

        std::stringstream stream;
        stream << str;
        stream >> std::hex >> address;

        return address;
    }

    int stringToDec(std::string str){

        int output;

        std::stringstream stream;
        stream << str;
        stream >> output;

        return output;
    }

    int getStartAddress(std::vector<std::vector<std::string>> code){

        return hexToDec(code[0][2]);
    }

    void addressCounter(std::vector<std::vector<std::string>> code, std::vector<int> &location, int lines){
        location.push_back(getStartAddress(code));
        int address=getStartAddress(code);
        for(int i=1 ; i<lines ; i++){
            if(code[i][1] == "RESW"){
                address+=stringToDec(code[i][2]) * 3;
            }else if(code[i][1] == "RESB"){
                address+=stringToDec(code[i][2]);
            }else if(code[i][1] == "WORD"){
                address+=3;
            }else if(code[i][1] == "BYTE"){
                if(code[i][2][0]=='X' || code[i][2][0]=='x'){
                    address += 1;
                }
                else if(code[i][2][0]=='C' || code[i][2][0]=='c'){
                    address += hexToDec(code[i][2].substr(2,code[i][2].size()-3));
                    }
            }else{
                address+=3;
            }

            location.push_back(address);
        }
        return;
}
//    void createSymbolTable(std::vector<std::vector<std::string>> code, std::vector<int> location, std::map<std::string,int> &symbolTable,int lines){
//        for(int i=1; i<lines-1 ; i++){
//            if(code[i].size() == 3){
//                symbolTable.insert((code[i][0]), location[i-1]);
//            }
//        }
//    }

#endif
