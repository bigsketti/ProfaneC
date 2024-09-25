#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "/home/mason/code-shit/ProfaneC/headers/lexer.h"

//overloads the << operator to output token type as an integer
//followed by the token value
//the integers corrispond to the order defined in the Keywords enum class
//reference lexer.h for map of token types to indecies
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

    std::ofstream file_out("/home/mason/code-shit/ProfaneC/lexerOutput.txt");

    if (file_out.is_open()) {
        for (int i = 0; i < tokenVec.size(); i++) {
            file_out << tokenVec.at(i) << std::endl;
        }
    }

    return 0;
}