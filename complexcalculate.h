#ifndef COMPLEXCALCULATE_H
#define COMPLEXCALCULATE_H
#include "memories.h"
#include <map> // Used to map strings to arrays for our function pointers

typedef void (*function)(const std::string &arg, memories &me);

void introduction();
void getInput(std::istream &in, memories &me, std::map<std::string, function> &list, bool &save, bool execute, std::string &savefile);
void let(const std::string &arg, memories &me);
void print(const std::string &arg, memories &me);
void save(const std::string &arg, memories &me);
void load(const std::string &arg, memories &me);
void exit(const std::string &arg, memories &me);
void wexit(const std::string &arg, memories &me);
void add(const std::string &arg, memories &me);
void subtract(const std::string &arg, memories &me);
void multiply(const std::string &arg, memories &me);
void divide(const std::string &arg, memories &me);
void power(const std::string &arg, memories &me);
void orthogonal(const std::string &arg, memories &me);
void trig(const std::string &arg, memories &me);
void conjugate(const std::string &arg, memories &me);
void loadFunction(std::map<std::string, function> &list);
void magnitude(const std::string arg);
void display(const std::string &arg, memories &me);
bool validateCommand(const std::string &arg);
std::string cleanAndRead(const std::string &arg);
void recordFile(std::string filename, std::string userInput);

#endif //COMPLEXCALCULATE_H
