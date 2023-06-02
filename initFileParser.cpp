#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "globalVars.h"

int line1Parser(std::string line){
    std::string::iterator strIt;

    int tripleIndex = 0;
    std::string memString = "";
    int s = 0;
    int z = 0;
    int f = 0;

    for(strIt = line.begin(); strIt != line.end(); strIt++){
        if(*strIt != spaceChar){
            memString += *strIt;
        }
        else if(*strIt == spaceChar){
            if(tripleIndex == 0){
                s = std::stoi(memString);
                tripleIndex++;
                memString = "";
            }
            else if(tripleIndex == 1){
                z = std::stoi(memString);
                tripleIndex++;
                memString = "";
            }
            else if(tripleIndex == 2){
                f = std::stoi(memString);
                tripleIndex = 0;
                memString = "";

                std::cout<<"S value: "<<s<<std::endl;
                std::cout<<"Z value: "<<z<<std::endl;
                std::cout<<"F value: "<<f<<std::endl;

                //Data manipulations occur here
            }
            else{
                std::cout<<"ERROR: Triples index exceeded maximum number for Line 1 of init file.\n";
            }


        }
    }

    return 0;
}

int line2Parser(std::string line){

    return 0;
}

int initFileParser(std::ifstream initFile){
    std::string line1;
    std::getline(initFile, line1);
    int success = line1Parser(line1);

    if(success != 0){
        std::cout<<"ERROR: Failed to parse text file correctly at line 1.\n";
        return -1;
    }

    std::string line2;
    std::getline(initFile, line2);
    success = line2Parser(line2);

    if(success != 0){
        std::cout<<"ERROR: Failed to parse text file correctly at line 2.\n";
    }


    return 0;
}