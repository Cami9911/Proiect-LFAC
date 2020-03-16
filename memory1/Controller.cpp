
#include "Controller.h"

void Controller::push_scope() {
    Scope* scope = new Scope();
    stack.push_back(scope);
}

void Controller::pop_scope() {
    stack.pop_back();
}

void Controller::declare(char* type,char* name) {
    Scope* scope = stack.back(); 
    scope->declare(type,name);
}

void Controller::tprint() {
    for(int i=stack.size()-1;i>=0;i--)
    {
        Scope* scope = stack[i];
        scope->tableprint();
    }

}

bool Controller::exists(char* name) {
     for(int i=stack.size()-1;i>=0;i--)
    {
        Scope* scope = stack[i];
        if(scope->exists(name))
        {
            return true;
        }
    }
    return false;
}


void Controller::assign(char* name,Data* data) {
     for(int i=stack.size()-1;i>=0;i--)
    {
        Scope* scope = stack[i];
        if(scope->exists(name))
        {
          scope->assign(name,data);
          break;
        }
    }
}

Data* Controller::get(char* name) {
    for(int i=stack.size()-1;i>=0;i--)
    {
        Scope* scope = stack[i];
        if(scope->exists(name))
        {
            return scope->get(name);
        }
    }
    std::cout<<"Variabila "<<name<<" nu a fost declarata. \n";
    return new Data("0");
}

void Controller::definefunct(char* name) {
    functions.insert(std::string(name));
}

bool Controller::existsfunct(char* name) {
    if(functions.find(std::string(name))==functions.end())
    {
        return false;
    }
    return true;
}
void Controller::defineclass(char* name){
     classes.insert(std::string(name));
}
   
   
bool Controller::existsclass(char* name){
    if(classes.find(std::string(name))==classes.end())
    {
        return false;
    }
    return true;

}