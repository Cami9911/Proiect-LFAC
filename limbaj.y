%{
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "memory1/Controller.h"

extern int yylineno;
extern FILE* yyin;
extern char* yytext;
void yyerror(char* s);
int yylex(void);
Controller memory;
%}
%union { 
  char * strval;
  int intval;
  float floatval;
  class Data * dataval;
}
%token CONST MAIN WHILE IF FOR ARRAY CLASS PUBLIC PRIVATE RETURN EQUAL NOT_EQUAL COUT PCT AND OR 
%token <intval> NR
%token <strval> STRING
%token <strval> ID
%token <strval> TYPE
%token <floatval> FLOAT

%type <dataval> expression
%type <dataval> bool_expr
%type <dataval> bool_expr_big

%start s

%left '+' '-'
%left '*' '/' 

%%
s :progr {printf("Input acceptat!\n");}
  ;
progr: declarations main
     | main
     ;

declarations: eval_function class
            | eval_function function
            | declarations function
            | declarations class
            ;
eval_function: ID '(' param_list ')' ';'
             ;
main : MAIN '(' ')'{ memory.push_scope(); } function_body { memory.pop_scope(); }
     ;

class: CLASS ID '{' {if(memory.existsclass($2)) {std::cout<<"Exista o clasa cu acelasi nume \n";} memory.defineclass($2); memory.push_scope(); } class_contain '}'{ memory.pop_scope(); }
     | CLASS ID '{' '}'  {if(memory.existsclass($2)) {std::cout<<"Exista o clasa cu acelasi nume\n ";} memory.defineclass($2);}
     ;
class_contain: class_statement
             | class_contain class_statement
             ;

class_statement: modif_acces ':' TYPE ID ';' { memory.declare($3,$4); }
               | modif_acces TYPE ID ';' { memory.declare($2,$3); }
               | modif_acces ':' function 
               | modif_acces  function 
               ;  

modif_acces: PUBLIC
           | PRIVATE
           |
           ;
function_body: '{' statement_seq '}'
             | '{' '}'
             ;
function: TYPE  ID '(' ')' {if(memory.existsfunct($2)) {std::cout<<"Exista o functie cu acelasi nume \n";} memory.definefunct($2); memory.push_scope();} function_body {memory.pop_scope();}
        | TYPE  ID '('{if(memory.existsfunct($2)) {std::cout<<"Exista o functie cu acelasi nume.\n";} memory.definefunct($2); memory.push_scope();} param_seq ')' function_body {memory.pop_scope();}
        | TYPE CONST ID '(' ')' function_body 
        | TYPE CONST ID '(' param_seq ')' function_body 
        ;

param_seq: TYPE ID { memory.declare($1,$2); }
          | param_seq ',' TYPE ID { memory.declare($3,$4); }
          | ID
          | param_seq ','  ID
          ;

array: ID var
     | TYPE ID var  ';' { memory.declare($1,$2); }
     ;
var: '[' p ']' '[' p']'
   | '[' p ']'
   ;
p: NR
 | ID
 ;

statement: ID '=' expression ';'{if(memory.exists($1)){memory.assign($1,$3);} else std::cout<<"Variabila nu a fost declarata.\n";}
         | TYPE ID ';'  { memory.declare($1,$2); }
         | TYPE CONST ID ';'
         | function
         | array
         | ID '(' ')' ';' {if(!memory.existsfunct($1)) {std::cout<<"Functia nu este definita. \n";} }
         | ID '(' param_list ')' ';' {if(!memory.existsfunct($1)) {std::cout<<"Functia nu este definita.\n";} }
         | if_instr
         | while_instr
         | for_instr
         | RETURN expression ';'
         | COUT expression ';' { memory.tprint();}
         | ID ID ';'
         | '{' statement_seq '}'
         ;

statement_seq: statement
             | statement_seq statement
             ;
param_list: expression
          | param_list ',' expression
          ;

if_instr: IF '(' bool_expr_big ')' {memory.push_scope();} statement {memory.pop_scope();}
        | IF '(' bool_expr ')' statement
        ;
while_instr: WHILE '(' bool_expr_big ')' statement
           | WHILE '(' bool_expr ')' {memory.push_scope();} statement {memory.pop_scope();}
           ;
for_instr: FOR '(' ID '=' expression ';' bool_expr_big ';' ID '=' expression ')'  statement
         | FOR '(' ID '=' expression ';' bool_expr ';' ID '=' expression ')'  statement
         ;
bool_expr: expression EQUAL expression { Data &a=*($1); Data &b=*($3); $$=(a==b); }
         | expression NOT_EQUAL expression { Data &a=*($1); Data &b=*($3); $$=(a!=b); }
         | expression '<' expression { Data &a=*($1); Data &b=*($3); $$=(a<b); }
         | expression '>' expression { Data &a=*($1); Data &b=*($3); $$=(a>b); }
         | '(' bool_expr ')'  {Data &a=*($2); $$=&a;}
         ;
bool_expr_big: bool_expr AND bool_expr { Data &a=*($1); Data &b=*($3); $$=(a&&b); }
             | bool_expr OR bool_expr { Data &a=*($1); Data &b=*($3); $$=(a||b); }
             | bool_expr_big AND bool_expr { Data &a=*($1); Data &b=*($3); $$=(a&&b); }
             | bool_expr_big OR bool_expr { Data &a=*($1); Data &b=*($3); $$=(a||b); }
             | '(' bool_expr_big ')' {Data &a=*($2); $$=&a;}
             ;

expression: expression '+' expression { Data &a=*($1); Data &b=*($3); $$=a+b; }
          | expression '-' expression { Data &a=*($1); Data &b=*($3); $$=a-b; }
          | expression '*' expression { Data &a=*($1); Data &b=*($3); $$=a*b; }
          | expression '/' expression { Data &a=*($1); Data &b=*($3); $$=a/b; }
          | '('expression')' {Data &a=*($2); $$=&a;}
          | NR { $$=new Data($1);}
          | FLOAT { $$=new Data($1);}
          | ID { $$=memory.get($1);}
          | ID '(' ')'  {if(!memory.existsfunct($1)) {std::cout<<"Functia nu este definita.\n";} $$=new Data(0); }
          | ID '(' param_list ')'{if(!memory.existsfunct($1)) {std::cout<<"Functia nu este definita.\n";} $$=new Data(0); }
          | ID PCT ID { if(!memory.existsclass($3)) {std::cout<<"Nu exista o clasa cu acest nume. \n";}   $$=new Data(0);}
          | array {$$=new Data(0);}
          | STRING { $$=new Data($1);}
          ;
%%
void yyerror(char * s){
 printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
 yyin=fopen(argv[1],"r");
 yyparse();
} 

