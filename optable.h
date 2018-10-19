#ifndef OPTABLE_H
#define OPTABLE_H

void initOpTable(std::map<std::string,std::string>&opTable){

    opTable.insert(std::pair<std::string,std::string>("ADD","18"));
    opTable.insert(std::pair<std::string,std::string>("AND","40"));
    opTable.insert(std::pair<std::string,std::string>("COMP","28"));
    opTable.insert(std::pair<std::string,std::string>("DIV","24"));
    opTable.insert(std::pair<std::string,std::string>("J","3C"));
    opTable.insert(std::pair<std::string,std::string>("JEQ","30"));
    opTable.insert(std::pair<std::string,std::string>("JGT","34"));
    opTable.insert(std::pair<std::string,std::string>("JLT","38"));
    opTable.insert(std::pair<std::string,std::string>("JSUB","48"));
    opTable.insert(std::pair<std::string,std::string>("LDA","00"));
    opTable.insert(std::pair<std::string,std::string>("LDCH","50"));
    opTable.insert(std::pair<std::string,std::string>("LDL","08"));
    opTable.insert(std::pair<std::string,std::string>("LDX","04"));
    opTable.insert(std::pair<std::string,std::string>("MUL","20"));
    opTable.insert(std::pair<std::string,std::string>("OR","44"));
    opTable.insert(std::pair<std::string,std::string>("RD","D8"));
    opTable.insert(std::pair<std::string,std::string>("RSUB","4C"));
    opTable.insert(std::pair<std::string,std::string>("STA","0C"));
    opTable.insert(std::pair<std::string,std::string>("STCH","54"));
    opTable.insert(std::pair<std::string,std::string>("STL","14"));
    opTable.insert(std::pair<std::string,std::string>("STSW","E8"));
    opTable.insert(std::pair<std::string,std::string>("STX","10"));
    opTable.insert(std::pair<std::string,std::string>("SUB","1C"));
    opTable.insert(std::pair<std::string,std::string>("TD","E0"));
    opTable.insert(std::pair<std::string,std::string>("TIX","2C"));
    opTable.insert(std::pair<std::string,std::string>("WD","DC"));
}

#endif
