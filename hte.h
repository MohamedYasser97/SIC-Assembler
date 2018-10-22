#ifndef HTE_H
#define HTE_H

#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>

void createHead(std::vector<std::vector<std::string>> code, std::vector<int> location, std::vector<std::string> &hteRecord){

    std::stringstream stream;
    int progLength = location[location.size()-1] - location[0];

    std::string temp="H ";
    temp+=code[0][0]+" "; // program name
    stream<<std::setfill('0') << std::setw(6) << std::hex << code[0][2];
    temp+=stream.str()+" "; // starting address

    stream.str(std::string());

    stream<<std::setfill('0') << std::setw(6) << std::hex << progLength ;
    temp+= stream.str();

    hteRecord.push_back(temp);

}

void createText(std::vector<std::vector<std::string>> code, std::vector<int> location, std::vector<std::string> &hteRecord, std::vector<std::string>objectCode,int lines){

    std::stringstream stream;
    std::string temp = "T ";
    int startLocation = location[0];

    for(int i=0;i<objectCode.size();i++){

        if(objectCode[i]=="-"){
            continue;
        }

        if(temp == "T "){
            stream<<std::setfill('0') << std::setw(6) << std::hex << startLocation ;
            temp+=stream.str() + " ";

            stream.str(std::string());
        }

        temp+=objectCode[i] + " ";

        if(((i+1)%10==0 && i!=0) || objectCode[i+1]=="-"){

            int length = location[i+1] - startLocation;

            startLocation = location[i+1];

            stream<<std::setfill('0') << std::setw(2) << std::hex << length ;
            temp.insert(9,stream.str()+" ");

            stream.str(std::string());

            hteRecord.push_back(temp);

            temp="T ";
        }
    }
}

void createEnd(std::vector<int> location, std::vector<std::string> &hteRecord){

    std::stringstream stream;
    std::string temp = "E ";
    stream<<std::setfill('0') << std::setw(6) << std::hex << location[0] ;
    temp+=stream.str();
    hteRecord.push_back(temp);
}

void generateHTEFile(std::vector<std::string> hteRecord){

        std::ofstream file;

        file.open("HTE.txt");

        for( int i = 0 ; i < hteRecord.size() ; i++)
          file<<hteRecord[i]<<std::endl;

        file.close();
}

#endif // HTE_H
