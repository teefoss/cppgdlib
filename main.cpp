//
//  main.cpp
//  ccgdlib
//
//  Created by Thomas Foster on 5/4/23.
//

#include "List.h"
#include "Vector.h"
#include "Array.h"
#include "Storage.h"
#include "Dictionary.h"
#include "Random.h"

#include <stdio.h>
#include <time.h>

void PrintIntList(List<int>& list)
{
    printf("\nlist count: %d\n", list.count());
    for ( int i = 0; i < list.count(); i++ ) {
        printf("list element %d: %d\n", i, list.get(i));
    }
    printf("\n");
}

void TestList()
{
    List<int> list;

    puts("test append:");
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);
    PrintIntList(list);

    puts("test remove index 0");
    list.remove(0);
    PrintIntList(list);

    puts("test remove index 2");
    list.remove(2);
    PrintIntList(list);

    puts("test remove index 3");
    list.remove(3);
    PrintIntList(list);
}

char globalString[9]; // 8 letters + null terminator

char* generateRandomString() {
    static const char alphabet[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    int i;

    for (i = 0; i < 8; ++i) {
        globalString[i] = alphabet[rand() % (sizeof(alphabet) - 1)];
    }
    globalString[8] = '\0';
    return globalString;
}

void TestDictionary() {
    srand(0);

    Dictionary<int> dict;

    for ( int i = 0; i < 200; i++ ) {
        char * key = generateRandomString();
        dict.insert(key, rand() % 10000);
    }

//    dict.debugPrint();

//    int data;
//    if ( dict.get("three", &data) ) {
//        printf("%d\n", data);
//    }
}

int main(int argc, const char * argv[])
{
    Random random;

    for ( int i = 0 ; i < 10; i++ ) {
        u32 r = random.Int() % 10000;
        printf("%d\n", r);
    }

    return 0;
}
