//
//  String.hpp
//  ccgdlib
//
//  Created by Thomas Foster on 5/5/23.
//

#ifndef String_h
#define String_h

#include <string.h>

class String {
public:
    static unsigned Hash(const char * key);
    static bool Compare(const char * a, const char * b);
    static int Length(const char * string) { return (int)strlen(string); }

    String() { };
    String(const char * cString) {
        length = (int)strlen(cString);
        text = new char[length + 1];
        text[length - 1] = '\0';
    }

    ~String() { if ( text ) delete[] text; }

private:
    char * text = nullptr;
    int length = 0;
};

#endif /* String_h */
