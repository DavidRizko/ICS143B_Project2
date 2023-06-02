// #include <iostream>
// #include <string>
// #include <cmath>
// #include <fstream>

#include <fstream>

#include "initFileParser.cpp"

bool isTextFile(std::string filename){
    size_t dotPosition = filename.find(".") + 1;
    std::string extension = filename.substr(dotPosition);

    if(extension == "txt")
        return true;
    return false;
}

int main(int argc, char* argv[]){

    if(argc > 3 || argc < 3){
        std::cout<<"ERROR: Expected 2 arguments.\n";
    }

    for(int i = 1; i < 3; i++){
        if(isTextFile(argv[i]) == false)
            std::cout<<"ERROR: Expected text files.\n";
    }

    std::ifstream initFile;
    std::ifstream virtualAdrs;
    initFile.open(argv[1]);
    virtualAdrs.open(argv[2]);

    initFileParser(initFile);
}
