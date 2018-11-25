#ifndef MEMORIES_H
#define MEMORIES_H
#include "complexnumber.h"
#include <map>

class memories
{
//    enum commands {LET, LOAD, SAVE, PRINT, EXIT, WEXIT};

//    std::map<std::string, memories::commands> commandMap;
//    void initializeMap();

    public:
        memories();
        ~memories();
        void clearLibrary();
        void display();

        void print(const std::string &arg);
        void save(std::string arg);

        friend
        std::ostream& operator<<(std::ostream& out, const memories &other);

        friend
        std::istream& operator>>(std::istream& in, memories &other);

    private:
        complexNumber library[26];
        void let(const std::string &arg);
        void exit(const std::string &arg);
//        void print(const std::string &arg);
        void load(const std::string &arg);
//        void save(std::string arg);
        void wexit(const std::string &arg);


};

#endif // MEMORIES_H
