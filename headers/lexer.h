#ifndef LEXER_H
#define LEXER_H

#include <string>

//list of keywords 

//types denoted by the index within the enum class
//this is so its easy to pass this info to the parser
enum class Keywords {
    identifier,     //type 0
    integer,        //type 1
    floatpnt,       //type 2
    string,         //type 3 
    character,      //type 4
    boolean,        //type 5
    plus,           //type 6
    minus,          //type 7 
    multiply,       //type 8
    divide,         //type 9
    l_Paren,        //type 10
    r_Paren,        //type 11
    l_Brace,        //type 12
    r_Brace,        //type 13
    l_Brack,        //type 14
    r_Brack,        //type 15
    semicolon,      //type 16
    end_of_file,    //type 17
    unknown         //type 18
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