#include "scanner_token.h"
#include <cstdio>
#include <string_view>
#include <iostream>
#include <vector>

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

int main(int argc, char** argv)
{
    std::vector<std::string> plscript_files;
    plscript_files.reserve(argc);

    for (std::size_t i{1}; i < argc; i++)
    {
        std::cout << "File Name: " << argv[i];
        plscript_files.emplace_back(argv[i]);
    }

    for(auto const& file_name: plscript_files)
    {
        yyin = std::fopen(file_name.c_str(), "r");
         if (!yyin)    {
            std::cout << "Could not open the script " << file_name << std::endl;
            continue;
        }

        std::cout << "Scanning file: " << file_name << '\n';

        token_t t{TOKEN_ERROR}; // start of with error
        while(t != TOKEN_EOF)
        {
            std::string token_name(to_token_name(t));
            std::cout << "Token: " << token_name << " Text: " << yytext << '\n';
            printf("token: %s text: %s\n", token_name.c_str(), yytext);
            t = static_cast<token_t>(yylex());
        }
    }

    std::cout << std::endl;
}