#include "lexer.h"
#include <ctype.h>
#include <string.h>

typedef struct {
   const char* source; 
   int cursor; 
   int line;
}LexerState; 

TOKENS check_Keyword(const char* word) { 
   if (strcmp(word,"while") == 0) return TOKEN_WHILE; 
   if (strcmp(word,"if") == 0) return TOKEN_IF; 
   if (strcmp(word,"scanS") == 0) return TOKEN_SCANS; 
   if (strcmp(word,"say") == 0) return TOKEN_SAY;
   if (strcmp(word,"var") == 0) return TOKEN_VAR; 
   if (strcmp(word,"for") == 0) return TOKEN_FOR; 
   if (strcmp(word,"elef") == 0) return TOKEN_ELEF;
   if (strcmp(word,"promise->") == 0) return TOKEN_PROMISE; 
   if (strcmp(word,"else") == 0) return TOKEN_ELSE; 
   if (strcmp(word,"request")==0) return TOKEN_REQUEST;
   return TOKEN_IDENTIFIER; 
}LexerState;

Token getNextToken(LexerState* state) { 
    while (state->source[state->cursor] != '\0') { 
        char current = state->source[state->cursor]; 

        if (current == ' ' || current == '\t'){
          state->cursor++; 
          continue;
        }
        if (current == '\n') { 
          state->line++; 
          state->cursor++;
          continue; 
        }
        
        if (strncmp(&state->source[state->cursor], "while", 5) == 0) {
            state->cursor += 5;
            Token t = {TOKEN_WHILE, "while"};
            return t;
        }
        if (strncmp(&state->source[state->cursor], "var",3) == 0) { 
            state->cursor += 3; 
            Token t = {TOKEN_VAR,"var"};
            return t; 
        }
        if (strncmp(&state->source[state->cursor],"say",3) == 0) { 
            state->cursor += 3;
            Token t = {TOKEN_VAR, "say"};
            return t;
        }
        if (strncmp(&state->source[state->cursor],"if",2) == 0) { 
            state->cursor += 2; 
            Token t = {TOKEN_IF,"if"}; 
            return t; 
        }
        if (strncmp(&state->source[state->cursor],"elef",4) == 0) { 
            state->cursor += 4; 
            Token t = {TOKEN_ELEF,"elef"};
            return t;
        }
        if (current == '=') { state->cursor++; Token t = {TOKEN_ASSIGN, "="}; return t; }
        if (current == '+') { state->cursor++; Token t = {TOKEN_PLUS, "+"}; return t; }
        if (current == '-') { state->cursor++; Token t = {TOKEN_MINUS, "-"}; return t; }
        if (current == '/') { state->cursor++; Token t = {TOKEN_DIV, "/"}; return t; }
        if (current == '*') { state->cursor++; Token t = {TOKEN_MULT, "*"}; return t; }
        if (current == '%') { state->cursor++; Token t = {TOKEN_MODU, "%"}; return t; }
        
        if (current == '[') { state->cursor++; Token t = {TOKEN_LBRA, "["}; return t; }
        if (current == ']') { state->cursor++; Token t = {TOKEN_RBRA, "]"}; return t; }
        if (current == '{') { state->cursor++; Token t = {TOKEN_LBRACE, "{"}; return t; }
        if (current == '}') { state->cursor++; Token t = {TOKEN_RBRACE, "}"}; return t; }
        if (current == '(') { state->cursor++; Token t = {TOKEN_LPANTH, "("}; return t; }
        if (current == ')') { state->cursor++; Token t = {TOKEN_RPANTH, ")"}; return t; }
         
        if (current == "while") { 
            for (int i = 0; i < 6; i++) { state->cursor++;}
            check_Keyword("while");
        }
    }
Token EOF = {TOKEN_EOF,"EOF"};  
return EOF;
}

