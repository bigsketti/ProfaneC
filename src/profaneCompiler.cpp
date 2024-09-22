#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "/home/mason/code-shit/ProfaneC/headers/lexer.h"

std::ostream& operator<<(std::ostream& os, const Token& token) {
    os << "Type: " << static_cast<int>(token.type) << ", Value: " << token.value;
    return os;
}

int main() {

    std::vector<Token> tokenVec;
    std::ifstream file_in("/home/mason/code-shit/ProfaneC/testInput.txt");
    
    if (file_in.is_open()) {
        std::cout << "file open\n";
        std::string line;

        while (getline(file_in, line)) {
            std::cout << "Reading line: " << line << std::endl;

            Lexer Lexer(line);
            Token token = Lexer.getNextToken();

            while (token.type != Keywords::end_of_file) {
                std::cout << "Token " << static_cast<int>(token.type) << " | Value: " << token.value << std::endl;
                tokenVec.push_back(token);
                token = Lexer.getNextToken();
            }
        }

    } else if (file_in.fail()) {
        std::cerr << "File read error" << std::endl;
    }
    
    file_in.close();

    std::cout << "printing all tokens : \n";

    for (int i = 0; i < tokenVec.size(); i++) {
        std::cout << tokenVec.at(i) << std::endl;
    }

    return 0;
}