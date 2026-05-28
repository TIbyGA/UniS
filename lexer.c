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
    }
Token EOF = {TOKEN_EOF,"EOF"};  
return EOF;
}

