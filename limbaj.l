%{ 
#include <stdlib.h>
#include "y.tab.h"
#include <string.h>
%}
%option noyywrap
%option yylineno
%%
"int"|"string"|"char"|"bool"|"float" {yylval.strval=strdup(yytext);return TYPE;}
"const" {return CONST;}
"main" {return MAIN;}
"while" {return WHILE;}
"if" {return IF;}
"for" {return FOR;}
"class" {return CLASS;}
"public" {return PUBLIC;}
"private" {return PRIVATE;}
"return" {return RETURN;}
"cout<<" { return COUT;}
"==" {return EQUAL;}
"!=" {return NOT_EQUAL;}
"."  {return PCT;}
"&&" {return AND;}
"||" {return OR;}
\".*\" {yylval.strval=strdup(yytext); return STRING;}
[0-9]*"."[0-9]* {yylval.floatval=atof(yytext); return FLOAT;}
[1-9][0-9]*|0 {yylval.intval=atoi(yytext); return NR;}
[a-zA-Z][a-zA-Z0-9]* {yylval.strval=strdup(yytext); return ID;} 
[ \t] ;
"/*"(.|\n)+"*/" ;
\n {yylineno++;}
. {return yytext[0];}

%%
