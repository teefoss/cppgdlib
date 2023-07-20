//
//  String.cpp
//  ccgdlib
//
//  Created by Thomas Foster on 5/5/23.
//

#include "String.h"
#include <string.h>

unsigned String::hash(const char * key)
{
    // djb2 string hash function:
    unsigned result = 5381;
    const char * p = key;

    while ( *p != '\0' ) {
        result = (result << 5) + result + *p;
        ++p;
    }

    return result;
}

bool String::compare(const char *a, const char *b)
{
    return strcmp(a, b) == 0;
}
