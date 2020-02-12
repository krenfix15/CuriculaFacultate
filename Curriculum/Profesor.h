#ifndef PROFESOR_H
#define PROFESOR_H

#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "Persoana.h"

using namespace std;

class Profesor : public Persoana
{
    static int nextID;
    int id_prof;
    char titlu[20]; /* profesor / conferentiar / s.l. / asistent */
    char _buff[50]; /* utilizat pentru constructii de siruri returnate */
public:
    Profesor( Persoana &p, char _titlu[]) : Persoana(p), id_prof( ++nextID )
    {
        if( strcmp(_titlu, "profesor") != 0 && strcmp(_titlu, "conferentiar") != 0
                && strcmp(_titlu, "s.l." ) && strcmp(_titlu, "asistent" ) != 0 )
            throw Exceptie("PROFESOR", "Titlu incorect"); //Exceptie: titlu incorect

        strcpy(titlu, _titlu);
    }
    int getIDProf(void)
    {
        return id_prof;
    }
    char* retNumeComplet(void)
    {
        return strcat( strcat( strcat( strcat( strcpy(_buff, titlu)," "), nume), " "), prenume);
    }
    static void PrintProfesori( Profesor *p[], int nr, char numePart[] )
    {
        cout<<"\tProfesori ce contin '"<<numePart<<"' in nume : "<<endl;
        for( int i = 0; i < 3/*nr*/; i++ )
        {
            if( strstr( p[i]->retNumeComplet(), numePart) != NULL )
                cout<<"\t\t"<<p[i]->retNumeComplet()<<endl;
        }
    }
};

#endif // PROFESOR_H
