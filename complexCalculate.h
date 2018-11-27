#ifndef COMPLEXCALCULATE_H
#define COMPLEXCALCULATE_H
#include "memories.h"
#include <map> // Used to map strings to arrays for our function pointers

typedef void (*function)();

void introduction();
void getInput(std::istream &in, memories &me, std::map<std::string, function> &list);
void let();
void print();
void save();
void load();
void exit();
void wexit();
void add();
void subtract();
void multiply();
void divide();
void power();
void orthogonal();
void trig();
void conjugate();
void loadFunction(std::map<std::string, function> &list);
bool validateCommand(const std::string &arg);

#endif //COMPLEXCALCULATE_H
