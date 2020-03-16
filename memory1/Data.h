#include <iostream>
#include <cstring>
#include <string.h>

class Data { //stocheaza tipul si valoarea variabilei
public:


    int ivalue;
    float fvalue;
    char* svalue;
    char type[10];
    char* to_string();   
    char* int_type="int";
    char* float_type="float";
    char* string_type="string";
    char* char_type="char";
    char* bool_type="bool";
    char* to_string_type();

    Data(char* x) {
       svalue=x;
       strcpy(type,"string");
    }
    Data(int x){
        ivalue=x;
        strcpy(type,"int");
    }
    Data (float x){
        fvalue=x;
        strcpy(type,"float");
    }

   friend Data* operator+(Data &a,Data &b) {
        if(strcmp(a.type,"string")==0 || strcmp(b.type,"string")==0)
        {
            std::cout<<"String nu este un operand valid la adunare."<<'\n';
            return new Data("string");
        }
        if(strcmp(a.type,"int")==0 && strcmp(b.type,"int")==0)
        {
            return new Data(int(a.ivalue+b.ivalue));
        }
          if(strcmp(a.type,"float")==0 && strcmp(b.type,"int")==0)
        {
            return new Data(float(a.fvalue+b.ivalue));
        }
         if(strcmp(a.type,"int")==0 && strcmp(b.type,"float")==0)
        {
            return new Data(float(a.ivalue+b.fvalue));
        }
        if(strcmp(a.type,"float")==0 && strcmp(b.type,"float")==0)
        {
            return new Data(float(a.fvalue+b.fvalue));
        }
    }

    friend Data* operator-(Data &a,Data &b) {
        if(strcmp(a.type,"string")==0 || strcmp(b.type,"string")==0)
        {
            std::cout<<"String nu este un operand valid la scadere. "<<'\n';
            return new Data("string");
        }
        if(strcmp(a.type,"int")==0 && strcmp(b.type,"int")==0)
        {
            return new Data(int(a.ivalue-b.ivalue));
        }
          if(strcmp(a.type,"float")==0 && strcmp(b.type,"int")==0)
        {
            return new Data(float(a.fvalue-b.ivalue));
        }
         if(strcmp(a.type,"int")==0 && strcmp(b.type,"float")==0)
        {
            return new Data(float(a.ivalue-b.fvalue));
        }
        if(strcmp(a.type,"float")==0 && strcmp(b.type,"float")==0)
        {
            return new Data(float(a.fvalue-b.fvalue));
        }
    }
    friend Data* operator*(Data &a,Data &b) {
        if(strcmp(a.type,"string")==0 || strcmp(b.type,"string")==0)
        {
            std::cout<<"String nu este un operand valid la inmultire. "<<'\n';
            return new Data("string");
        }
        if(strcmp(a.type,"int")==0 && strcmp(b.type,"int")==0)
        {
            return new Data(int(a.ivalue*b.ivalue));
        }
          if(strcmp(a.type,"float")==0 && strcmp(b.type,"int")==0)
        {
            return new Data(float(a.fvalue*b.ivalue));
        }
         if(strcmp(a.type,"int")==0 && strcmp(b.type,"float")==0)
        {
            return new Data(float(a.ivalue*b.fvalue));
        }
        if(strcmp(a.type,"float")==0 && strcmp(b.type,"float")==0)
        {
            return new Data(float(a.fvalue*b.fvalue));
        }
    }
     friend Data* operator/(Data &a,Data &b) {
        if(strcmp(a.type,"string")==0 || strcmp(b.type,"string")==0)
        {
            std::cout<<"String nu este un operand valid la impartire! "<<'\n';
            return new Data("string");
        }
        if(strcmp(a.type,"int")==0 && strcmp(b.type,"int")==0)
        {   
            if(b.ivalue==0)
            {
                std::cout<<"Impartirea la 0 nu este posibila."<<'\n';
                return new Data("string");
            }
            return new Data(int(a.ivalue/b.ivalue));
        }
          if(strcmp(a.type,"float")==0 && strcmp(b.type,"int")==0)
        {
            if(b.ivalue==0)
            {
                std::cout<<"Impartirea la 0 nu este posibila."<<'\n';
                return new Data("string");
            }
            return new Data(a.fvalue/b.ivalue);
        }
         if(strcmp(a.type,"int")==0 && strcmp(b.type,"float")==0)
        {
            if(b.fvalue==0)
            {
                std::cout<<"Impartirea la 0 nu este posibila."<<'\n';
                return new Data("string");
            }
            return new Data(float(a.ivalue/b.fvalue));
        }
        if(strcmp(a.type,"float")==0 && strcmp(b.type,"float")==0)
        {
            if(b.fvalue==0)
            {
                std::cout<<"Impartirea la 0 nu este posibila."<<'\n';
                return new Data("string");
            }
            return new Data(float(a.fvalue/b.fvalue));
        }
    }

    friend Data* operator==(Data &a,Data &b) {
         if(strcmp(a.type,"string")==0 && strcmp(b.type,"string")==0)
        {   
            if(strcmp(a.svalue,b.svalue)==0)
            return new Data(1);
            else
            return new Data(0);
        }
        if(strcmp(a.type,"string")==0 || strcmp(b.type,"string")==0)
        {
            std::cout<<"String nu este un operand valid la comparare. "<<'\n';
            return new Data("string");
        }
        if(strcmp(a.type,"int")==0 && strcmp(b.type,"int")==0)
        {
            return new Data(int(a.ivalue==b.ivalue));
        }
          if(strcmp(a.type,"float")==0 && strcmp(b.type,"int")==0)
        {
            return new Data(float(a.fvalue==b.ivalue));
        }
         if(strcmp(a.type,"int")==0 && strcmp(b.type,"float")==0)
        {
            return new Data(float(a.ivalue==b.fvalue));
        }
        if(strcmp(a.type,"float")==0 && strcmp(b.type,"float")==0)
        {
            return new Data(float(a.fvalue==b.fvalue));
        }
    }
     friend Data* operator!=(Data &a,Data &b) {
         if(strcmp(a.type,"string")==0 && strcmp(b.type,"string")==0)
        {   
            if(strcmp(a.svalue,b.svalue)!=0)
            return new Data(1);
            else
            return new Data(0);
        }
        if(strcmp(a.type,"string")==0 || strcmp(b.type,"string")==0)
        {
            std::cout<<"String nu este un operand valid la comparare. "<<'\n';
            return new Data("string");
        }
        if(strcmp(a.type,"int")==0 && strcmp(b.type,"int")==0)
        {
            return new Data(int(a.ivalue!=b.ivalue));
        }
          if(strcmp(a.type,"float")==0 && strcmp(b.type,"int")==0)
        {
            return new Data(float(a.fvalue!=b.ivalue));
        }
         if(strcmp(a.type,"int")==0 && strcmp(b.type,"float")==0)
        {
            return new Data(a.ivalue!=b.fvalue);
        }
        if(strcmp(a.type,"float")==0 && strcmp(b.type,"float")==0)
        {
            return new Data(a.fvalue!=b.fvalue);
        }
    }
    friend Data* operator>(Data &a,Data &b) {
         if(strcmp(a.type,"string")==0 && strcmp(b.type,"string")==0)
        {   
            if(strcmp(a.svalue,b.svalue)>0)
            return new Data(1);
            else
            return new Data(0);
        }
        if(strcmp(a.type,"string")==0 || strcmp(b.type,"string")==0)
        {
            std::cout<<"String nu este un operand valid la comparare. "<<'\n';
            return new Data("string");
        }
        if(strcmp(a.type,"int")==0 && strcmp(b.type,"int")==0)
        {
            return new Data(a.ivalue>b.ivalue);
        }
          if(strcmp(a.type,"float")==0 && strcmp(b.type,"int")==0)
        {
            return new Data(a.fvalue>b.ivalue);
        }
         if(strcmp(a.type,"int")==0 && strcmp(b.type,"float")==0)
        {
            return new Data(a.ivalue>b.fvalue);
        }
        if(strcmp(a.type,"float")==0 && strcmp(b.type,"float")==0)
        {
            return new Data(a.fvalue>b.fvalue);
        }
    }
    friend Data* operator<(Data &a,Data &b) {
         if(strcmp(a.type,"string")==0 && strcmp(b.type,"string")==0)
        {   
            if(strcmp(a.svalue,b.svalue)<0)
            return new Data(1);
            else
            return new Data(0);
        }
        if(strcmp(a.type,"string")==0 || strcmp(b.type,"string")==0)
        {
            std::cout<<"String nu este un operand valid la comparare. "<<'\n';
            return new Data("string");
        }
        if(strcmp(a.type,"int")==0 && strcmp(b.type,"int")==0)
        {
            return new Data(a.ivalue<b.ivalue);
        }
          if(strcmp(a.type,"float")==0 && strcmp(b.type,"int")==0)
        {
            return new Data(a.fvalue<b.ivalue);
        }
         if(strcmp(a.type,"int")==0 && strcmp(b.type,"float")==0)
        {
            return new Data(a.ivalue<b.fvalue);
        }
        if(strcmp(a.type,"float")==0 && strcmp(b.type,"float")==0)
        {
            return new Data(a.fvalue<b.fvalue);
        }
    }
        friend Data* operator&&(Data &a,Data &b) {
       if(strcmp(a.type,"string")==0 || strcmp(b.type,"string")==0)
        {
            std::cout<<"String nu este un operand valid la operatii logice. "<<'\n';
            return new Data("string");
        }
        if(strcmp(a.type,"int")==0 && strcmp(b.type,"int")==0)
        {
            return new Data(a.ivalue&&b.ivalue);
        }
          if(strcmp(a.type,"float")==0 && strcmp(b.type,"int")==0)
        {
            return new Data(a.fvalue&&b.ivalue);
        }
         if(strcmp(a.type,"int")==0 && strcmp(b.type,"float")==0)
        {
            return new Data(a.ivalue&&b.fvalue);
        }
        if(strcmp(a.type,"float")==0 && strcmp(b.type,"float")==0)
        {
            return new Data(a.fvalue&&b.fvalue);
        }
    }
      friend Data* operator||(Data &a,Data &b) {
       if(strcmp(a.type,"string")==0 || strcmp(b.type,"string")==0)
        {
            std::cout<<"String nu este un operand valid la operatii logice. "<<'\n';
            return new Data("string");
        }
        if(strcmp(a.type,"string")==0 || strcmp(b.type,"string")==0)
        {
            std::cout<<"String nu este un operand valid la operatii logice. "<<'\n';
            return new Data("string");
        }
        if(strcmp(a.type,"int")==0 && strcmp(b.type,"int")==0)
        {
            return new Data(a.ivalue||b.ivalue);
        }
          if(strcmp(a.type,"float")==0 && strcmp(b.type,"int")==0)
        {
            return new Data(a.fvalue||b.ivalue);
        }
         if(strcmp(a.type,"int")==0 && strcmp(b.type,"float")==0)
        {
            return new Data(a.ivalue||b.fvalue);
        }
        if(strcmp(a.type,"float")==0 && strcmp(b.type,"float")==0)
        {
            return new Data(a.fvalue||b.fvalue);
        }
    }
    
};

