/*
https://www3.nd.edu/~dthain/compilerbook/chapter3.pdf
*/
#include "scanner_token.h"
#include <stdio.h>
#include <string_view>

extern FILE *yyin;
extern int yylex();
extern char *yytext;

std::string_view to_token_name(token_t t)
{
    switch(static_cast<int>(t))
    {
        case TOKEN_EOF              : return "\"EOF\"";                    break;
        case TOKEN_SEMICOLON        : return "\"semicolon\"";              break;
        case TOKEN_IF               : return "\"if\"";                     break;
        case TOKEN_WHILE            : return "\"while\"";                  break;
        case TOKEN_FUNC_SIG         : return "\"function signature\"";     break;
        case TOKEN_FUNC_CALL        : return "\"function call\"";          break;
        case TOKEN_PARAN_OPEN       : return "\"Paranthesis OPEN\"";       break;
        case TOKEN_PARAN_CLOSE      : return "\"Paranthesis CLOSE\"";      break;
        case TOKEN_BRACK_OPEN       : return "\"Bracket OPEN\"";           break;
        case TOKEN_BRACK_CLOSE      : return "\"Bracket CLOSE\"";          break;
        case TOKEN_LESSER_EQUALS    : return "\"Lesser Equals\"";          break;
        case TOKEN_GREATER_EQUALS   : return "\"Greater Equals\"";         break;
        case TOKEN_EQUALS           : return "\"Equals\"";                 break;
        case TOKEN_LESSER           : return "\"Lesser\"";                 break;
        case TOKEN_GREATER          : return "\"Greater\"";                break;
        case TOKEN_PRE_INCREMENT    : return "\"pre-increment\"";          break;
        case TOKEN_POST_INCREMENT   : return "\"post-increment\"";         break;
        case TOKEN_PRE_DECREMENT    : return "\"pre-decrement\"";          break;
        case TOKEN_POST_DECREMENT   : return "\"post-decrement\"";         break;
        case TOKEN_ADD              : return "\"add\"";                    break;
        case TOKEN_ASSIGNMENT       : return "\"Assignment\"";             break;
        case TOKEN_IDENT            : return "\"identifier\"";             break;
        case TOKEN_NUMBER           : return "\"number\"";                 break;
        case TOKEN_ERROR            : return "\"error\"";                  break;
        default                     : return "\"Not a valid token!\"";     break;
    }
}

int main()
{
    yyin = fopen("program.pls", "r");
    if (!yyin)    {
        printf("could not open program.c!\n");
        return 1;
    }
    while (1){
        token_t t = static_cast<token_t>(yylex());
        if (t == TOKEN_EOF)
            break;
        std::string_view token_name = to_token_name(t);
        printf("token: %s text: %s\n", token_name.data(), yytext);
    }
}