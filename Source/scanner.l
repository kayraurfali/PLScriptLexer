/*https://www3.nd.edu/~dthain/compilerbook/chapter3.pdf*/
%{
#include "scanner_token.h"
%}
DIGIT [0-9]
LETTER [a-zA-Z]
IDENTIFIER [a-zA-Z][a-zA-Z0-9]*
WHITESPACE (" "|\t|\n)
%%
\/\/.*       /* skip comments */
{WHITESPACE} /* skip whitespace */
\;                                                             { return TOKEN_SEMICOLON; }
if                                                             { return TOKEN_IF; }
while                                                          { return TOKEN_WHILE; }
fun{WHITESPACE}*{IDENTIFIER}\({WHITESPACE}*\){WHITESPACE}*\-\>{WHITESPACE}*{IDENTIFIER} { return TOKEN_FUNC_SIG; }
fun{WHITESPACE}*\(\){WHITESPACE}*                              { return TOKEN_FUNC_CALL; }
\(                                                             { return TOKEN_PARAN_OPEN; }
\)                                                             { return TOKEN_PARAN_CLOSE; }
\{                                                             { return TOKEN_BRACK_OPEN; }
\}                                                             { return TOKEN_BRACK_CLOSE; }
\<\=                                                           { return TOKEN_LESSER_EQUALS; }
\>\=                                                           { return TOKEN_GREATER_EQUALS; }
\=\=                                                           { return TOKEN_EQUALS; }
\<                                                             { return TOKEN_LESSER; }
\>                                                             { return TOKEN_GREATER; }
{IDENTIFIER}\+\+                                               { return TOKEN_POST_INCREMENT; }
\+\+{IDENTIFIER}                                               { return TOKEN_PRE_INCREMENT;  }
{IDENTIFIER}\-\-                                               { return TOKEN_POST_DECREMENT; }
\-\-{IDENTIFIER}                                               { return TOKEN_PRE_DECREMENT;  }
\+                                                             { return TOKEN_ADD; }
\=                                                             { return TOKEN_ASSIGNMENT; }
{IDENTIFIER}                                                   { return TOKEN_IDENT; }
{DIGIT}+                                                       { return TOKEN_NUMBER; }
.                                                              { return TOKEN_ERROR; }
%%
int yywrap() { return 1; }