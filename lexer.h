#ifndef LEXER_H
#define LEXER_H
#include <stdio.h>
#include <string.h>
#prama once 
typedef enum {
     // Keywords of UniS
     TOKEN_WHILE,
     TOKEN_IF,  
     TOKEN_ELSE,
     TOKEN_SAY, 
     TOKEN_SCANS,
     TOKEN_ELEF,
     TOKEN_FOR,
     TOKEN_PROMISE,
     TOKEN_REQUEST,
     TOKEN_RETURN, 
     TOKEN_VAR, 
     //Literals & Identifiers 
     TOKEN_IDENTIFIER,
     TOKEN_NUMBER, 
     TOKEN_STRING,
     TOKEN_FLOATING_NUMBER,
     TOKEN_CHARACTER,
     TOKEN_BOOLEAN,
     TOKEN_DOUBLE_NUMBER,
     //Oparators & Symbols 
     TOKEN_ASSIGN, 
     TOKEN_PLUS, 
     TOKEN_MINUS, 
     TOKEN_DIV, // division /
     TOKEN_MULT, // multiplication *
     TOKEN_MODU, // Modulo % 
     TOKEN_LBRA, // [ 
     TOKEN_RBRA, // ] 
     TOKEN_LBRACE, // { 
     TOKEN_RBRACE, // } 
     TOKEN_LPANTH, // ) 
     TOKEN_RPANTH, // ( 
}TOKENS;

typedef struct { 
     TOKENS token;
     char *value;
}token;

#endif
