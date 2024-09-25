#include "/home/mason/code-shit/ProfaneC/headers/lexer.h"

#include <cstdlib>
#include <iostream>

void Lexer::nextPosition() {
    position++;

    if(position < stringInput.size()) {
        currentChar = stringInput[position];
        std::cout << "Advancing to: " << currentChar << " | at position: " << position << std::endl; 
    } else {
        currentChar = '\0';
        std::cout << "end of input\n";
    }
}

void Lexer::skipWhiteSpace() {
    if (currentChar != '\0' && std::isspace(currentChar)) {
        Lexer::nextPosition();
    }
}

Token Lexer::number() {
    std::string value;

    while (currentChar != '\0' && isdigit(currentChar)) {
        value += currentChar;
        nextPosition();
    }
    return Token(Keywords::integer, value);
}

Token Lexer::identifier() {
    std::string value;

    while (currentChar != '\0' && std::isalnum(currentChar)) {
        value += currentChar;
        nextPosition();
    }
    return Token(Keywords::identifier, value);
}

Lexer::Lexer(const std::string &input) {
    this->position = 0;
    this->stringInput = input;
    this->currentChar = stringInput[0];
}

Token Lexer::getNextToken() {
    while (currentChar != '\0') {
        //std::cout << currentChar << std::endl;

        if (std::isspace(currentChar)) {
            skipWhiteSpace();
            continue;
        }

        if (std::isdigit(currentChar)) {
            return number();
        }

        if (std::isalpha(currentChar)) {
            return identifier();
        }

        //this sure is ugly
        switch (currentChar) {
            case '+':
                nextPosition();
                return Token(Keywords::plus, "+");
            case '-':
                nextPosition();
                return Token(Keywords::minus, "-");
            case '*':
                nextPosition();
                return Token(Keywords::multiply, "*");
            case '/':
                nextPosition();
                return Token(Keywords::divide, "/");
            case '(':
                nextPosition();
                return Token(Keywords::l_Paren, "(");
            case ')':
                nextPosition();
                return Token(Keywords::r_Paren, ")");
            case '{':
                nextPosition();
                return Token(Keywords::l_Brace, "{");
            case '}':
                nextPosition();
                return Token(Keywords::r_Brace, "}");
            case '[':
                nextPosition();
                return Token(Keywords::l_Brack, "[");
            case ']':
                nextPosition();
                return Token(Keywords::r_Brack, "]");
            case ';':
                nextPosition();
                return Token(Keywords::semicolon, ";");
            default:
                nextPosition();
                return Token(Keywords::unknown, "");
        }
    }
    std::cout << "EOF" << std::endl;
    return Token(Keywords::end_of_file, "");

}