#include <map>
#include "Data.h"
#include <string>
#include <cstring>

class Scope {
public:
   std::map<std::string,Data*> mem;  //fiecare element din map contine ID-ul variabilei si Data(tip si valoare)
   void declare(char* type,char* name); //declarare si initializare variabile
   bool exists(char* name);   //exista variabila *name deja definita
   int tableprint();  //printeaza tipul,id-ul si valoarea simbolurilor in symbol_table.txt
   void assign(char* name,Data* data);  //asignare intre tipuri 
   Data* get(char* name);  //returneaza obiectul de tip scope cu ID-ul "name"
};
