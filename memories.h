#ifndef MEMORIES_H
#define MEMORIES_H
#include "complexnumber.h"
#include <map>

enum memories_ERRORS {INVALID_INPUT};
class memories
{
    enum commands {LET, LOAD, SAVE, PRINT, EXIT, WEXIT, MAGNITUDE, TRIG, DISPLAY, CLEAR};

    std::map<std::string, memories::commands> commandMap;
    void initializeMap();

    public:
        memories();
        ~memories();
        void choice(const std::string &input, const std::string &argument="");
        void clearLibrary();
        void display();

        void add(const int index, const int arg1, const int arg2);
        void subtract(const int index, const int arg1, const int arg2);
        void multiply(const int index, const int arg1, const int arg2);
        void divide(const int index, const int arg1, const int arg2);
        void power(const int index, const int arg1, const int arg2);
        void conjugate(const int index, const int arg1);

        friend
        std::ostream& operator<<(std::ostream& out, memories &m);

        friend
        std::istream& operator>>(std::istream& in, memories &m);

    private:
        complexNumber library[26];
        void let(const std::string &arg);
        void Exit(const std::string &arg);
        void print(const std::string &arg);
        void load(const std::string &arg);
        void save(const std::string arg);
        void wexit(const std::string &arg);
        void magnitude(const std::string &arg);

};

#endif // MEMORIES_H
