#include"Point.h"
#include"Directions.h"

typedef unsigned char BYTE;
typedef unsigned long ULONG;

typedef char *STRING;
typedef char TOWN[30];

typedef void (*VoidFunc_NoArgs)();
typedef void (*VoidFunc_CharArr)(char*);

void basicTypes();
void arrayAndPointer();
void complexTypes();
void functionPointers();
void printHello();
void printMessage(char *message);