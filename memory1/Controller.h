#include <vector>
#include "Scope.h"
#include <iostream>
#include <set>
#include <string>

class Controller {
public:
   std::vector<Scope*> stack;  
   std::set<std::string> functions;
   std::set<std::string> classes;
   void definefunct(char* name);  
   bool existsfunct(char* name);  
   void defineclass(char* name);  //daca clasa nu a fost declarata anterior, o adaugam set-ului
   bool existsclass(char* name);  //verificam daca clasa a fost declarata deja
   void push_scope();   //adaugam scope
   void pop_scope();    //la terminarea instructiunii scope ul este eliminat din stack
   void declare(char* type,char* name);
   void tprint();  // cout in fisierul symbol_table.txt
   bool exists(char* name); //verifica existenta unei var definita in scopul curent
   void assign(char* name,Data* data);
   Data* get(char* name);
};