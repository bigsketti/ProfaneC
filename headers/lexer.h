#ifndef LEXER_H
#define LEXER_H

#include <string>

//list of keywords 
enum class Keywords {
    identifier,
    integer,
    floatpnt,
    string,
    character,
    boolean,
    plus,
    minus,
    multiply,
    divide,
    l_Paren,
    r_Paren,
    l_Brace,
    r_Brace,
    l_Brack,
    r_Brack,
    semicolon,
    end_of_file,
    unknown
};

struct Token {
    Keywords type;
    std::string value;
    

    Token(Keywords type, std::string value) : type(type), value(value) {}
};

class Lexer {
    private:

        std::string stringInput;
        int position;
        char currentChar;

        //advances position in the input string
        void nextPosition();

        void skipWhiteSpace();

        //handles integer literals
        Token number();

        //handles identifiers
        Token identifier();

    public:
        
        Lexer(const std::string &input);
        
        Token getNextToken();

};

#endif