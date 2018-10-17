#ifndef PASS1_H
#define PASS1_H

#include <fstream>
#include <vector>
#include <sstream>

    void readFile(std::vector<std::vector<std::string>> &code){

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

        return;
    }

    int toDec(std::string str){

        int address;

        std::stringstream stream;
        stream << str;
        stream >> std::hex >> address;

        return address;
    }

    int getStartAddress(std::vector<std::vector<std::string>> code){

        return toDec(code[0][2]);
    }

    unsigned int locUpdate(){

    }

#endif
