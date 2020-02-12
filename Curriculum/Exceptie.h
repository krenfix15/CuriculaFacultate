#ifndef ECEPTIE_H
#define EXCEPTIE_H

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Exceptie
{
    char catEx[50], tipEx[50];
public:
    Exceptie(char _catEx[], char _tipEx[])
    {
        strcpy(catEx, _catEx );
        strcpy(tipEx, _tipEx );
    }
    void Print(void)
    {
        cerr<<"Exceptie ["<<catEx<<"] - "<<tipEx<<endl;
    }
};

#endif // EXCEPTIE_H
