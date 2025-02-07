/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CONST = 258,
    MAIN = 259,
    WHILE = 260,
    IF = 261,
    FOR = 262,
    ARRAY = 263,
    CLASS = 264,
    PUBLIC = 265,
    PRIVATE = 266,
    RETURN = 267,
    EQUAL = 268,
    NOT_EQUAL = 269,
    COUT = 270,
    PCT = 271,
    AND = 272,
    OR = 273,
    NR = 274,
    STRING = 275,
    ID = 276,
    TYPE = 277,
    FLOAT = 278
  };
#endif
/* Tokens.  */
#define CONST 258
#define MAIN 259
#define WHILE 260
#define IF 261
#define FOR 262
#define ARRAY 263
#define CLASS 264
#define PUBLIC 265
#define PRIVATE 266
#define RETURN 267
#define EQUAL 268
#define NOT_EQUAL 269
#define COUT 270
#define PCT 271
#define AND 272
#define OR 273
#define NR 274
#define STRING 275
#define ID 276
#define TYPE 277
#define FLOAT 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "limbaj.y" /* yacc.c:1909  */
 
  char * strval;
  int intval;
  float floatval;
  class Data * dataval;

#line 107 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
