#include "Scope.h"
#include <iostream>
#include <fstream>

using namespace std;
void Scope::declare(char* type,char* name) {
    Data* data;
     if(strcmp(type,"int")==0)          //pt fiecare tip se creeaza un nou obiect de tip Data
    {
        data=new Data(0);
    }
    if(strcmp(type,"float")==0)
    {
        data=new Data(1.0f);
    }
    if(strcmp(type,"string")==0)
    {
       data=new Data("empty_string");
    }
    if(strcmp(type,"char")==0)
    {
       data=new Data("empty_char");
    }
     if(strcmp(type,"bool")==0)
    {
       data=new Data("false/true");
    }

    if(exists(name))
    {
        std::cout<<"Variabila "<<name<<" a fost deja declarata anterior\n";
    }else
    {
        mem[string(name)]=data;   //ID-ului i se asigneaza tipul si valoarea
    }
}

bool Scope::exists(char* name) {  
  
    if(mem.find(string(name))!=mem.end())
    {   
        return true;
    }
    return false;
}
int Scope::tableprint() {
    ofstream myfile;
    myfile.open("symbol_table.txt");
    for(auto i : mem)
    {
        myfile<<i.second->to_string_type()<<' '<<i.first<<' '<<i.second->to_string()<<'\n';
    }
    myfile.close();
}

void Scope::assign(char* name,Data* data) {
    if(strcmp(mem[name]->type,data->type)==0)
    mem[name]=data;
    else
    std::cout<<"Eroare la asignare: tipuri diferite! \n";
    
}

Data* Scope::get(char* name) {
    return mem[string(name)];
}
