#ifndef PASS2_H
#define PASS2_H

#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>
#include <iomanip>
#include <string>
#include "optable.h"

void generateOpcode(std::vector<std::vector<std::string>>code, std::vector<std::string>&objectCode, std::map<std::string,std::string>opTable, int lines){

    for(int i=1;i<lines;i++){

        if(code[i].size()==2){
            objectCode.push_back(opTable.find(code[i][0])->second);

        }else if(code[i].size()==3){
            if(code[i][2]=="X" || code[i][2]=="x"){

                if(opTable.find(code[i][0])!= opTable.end())
                    objectCode.push_back(opTable.find(code[i][0])->second);
            }
            else if(opTable.find(code[i][1])!= opTable.end()){
                objectCode.push_back(opTable.find(code[i][1])->second);

            }else if(code[i][1]=="RESW" || code[i][1]=="RESB"){

                objectCode.push_back("-");

            }else{
                std::string temp, declaredValue;
                std::stringstream stream;

                if(code[i][2][0]=='X' || code[i][2][0]=='x'){

                    int stringLength = code[i][2].substr(2,code[i][2].size()-3).size();
                    declaredValue = code[i][2].substr(2,code[i][2].size()-3);

                    bool oddflag=false;

                    if(stringLength%2){

                        stringLength--;
                        oddflag=true;
                    }


                    for(int i=0;i<stringLength;i+=2){

                        stream<< std::hex << declaredValue.substr(i,2);
                        objectCode.push_back(stream.str());
                        stream.str(std::string());
                    }

                    if(oddflag){
                        stream<< std::hex << declaredValue.substr(declaredValue.size()-1,1);
                        objectCode.push_back(stream.str());
                        stream.str(std::string());
                    }


                }else if(code[i][2][0]=='C' || code[i][2][0]=='c'){

                        int stringLength = code[i][2].substr(2,code[i][2].size()-3).size();
                        declaredValue = code[i][2].substr(2,code[i][2].size()-3);

                        bool oddflag=false;
                        int offset=0;

                        if(stringLength%3){

                            offset = stringLength%3;
                            oddflag=true;
                        }


                        for(int i=0;i<stringLength - offset;i+=3){

                            stream<< (int)declaredValue.substr(i,3)[0]<<(int)declaredValue.substr(i,3)[1]<<(int)declaredValue.substr(i,3)[2];
                            objectCode.push_back(stream.str());
                            stream.str(std::string());
                        }

                        if(oddflag){
                            for(int i=stringLength-offset;i<stringLength;i++)
                                stream<< (int)declaredValue[i];

                            objectCode.push_back(stream.str());
                            stream.str(std::string());
                        }

                }else{

                    std::stringstream converter(code[i][2]);

                    int mediumValue;

                    converter >> mediumValue;

                    stream<< std::setfill('0') << std::setw(6) << std::hex << mediumValue;
                    temp=stream.str();

                    objectCode.push_back(temp);
                    stream.str(std::string());
                }
                //TODO check "c"


            }
        }
    }
}

void generateAddresses(std::vector<std::vector<std::string>>code, std::vector<std::string>&objectCode, std::map<std::string,int> symbolTable, int lines){

    for(int i=1;i<lines;i++){


        std::stringstream stream;

        if(code[i].size()==2){

            stream<<std::setfill('0') << std::setw(4) << std::hex<<symbolTable.find(code[i][1])->second;
            objectCode[i-1]+= stream.str();

        }else if(code[i].size()==3){

            if(code[i][2]=="x" || code[i][2]=="X"){

                int indirectAddress = 32768;
                int symbolAddress = symbolTable.find(code[i][1].substr(0,code[i][1].size()-1))->second;

                stream<<std::setfill('0') << std::setw(4) << std::hex<< (symbolAddress | indirectAddress);
                objectCode[i-1]+= stream.str();

            // 0 0 4 C
            // 0000 0000 0100 1100
            //0000000001001100
            //1000000000000000
            // (004C) | (32768)
            }else if(code[i][1]!= "WORD" && code[i][1]!= "BYTE" && code[i][1]!= "RESW" && code[i][1]!= "RESB"){

                stream<<std::setfill('0') << std::setw(4) << std::hex<<symbolTable.find(code[i][2])->second;
                objectCode[i-1]+= stream.str();

            }

        }

    }
}
#endif
