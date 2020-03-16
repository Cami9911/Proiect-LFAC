#include "Data.h"
#include <cstring>
#include <cstdio>
#include <stdlib.h>


char* Data::to_string()
{
    char* data=(char*) malloc(20);
    if(strcmp(type,"string")==0)
    {
        return svalue;
    }
     if(strcmp(type,"int")==0)
    {
        sprintf(data,"%d",ivalue);
        return data;
    }
     if(strcmp(type,"float")==0)
    {
        sprintf(data,"%f",fvalue);
        return data;
    }
    return "string";
}

char* Data::to_string_type()
{
    if(strcmp(type,"string")==0)
    {
       return string_type;
       
    }
     if(strcmp(type,"int")==0)
    {
        return int_type;
        
    }
     if(strcmp(type,"float")==0)
    {
        return float_type;
        
    }
      if(strcmp(type,"char")==0)
    {
        return char_type;
        
    }
      if(strcmp(type,"bool")==0)
    {
        return bool_type;
        
    }
      
}