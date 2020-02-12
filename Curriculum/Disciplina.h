#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Profesor.h"

using namespace std;

class Disciplina : public Profesor /* profesorului titular*/
{
    static int nextID;
    int id_disc;
    char denumire[40];
    char _buff[50];

public:
    Disciplina( char _den[], Profesor &p) : Profesor( p )
    {
        id_disc = ++nextID;
        strcpy(denumire, _den);
    }

    int getIDDisc(void)
    {
        return id_disc;
    }

    char* retNumeComplet(void)
    {
        strcpy( _buff, denumire );
        strcat( _buff, " - " );
        strcat( _buff, Profesor::retNumeComplet());
        return _buff;
    }

    char*retProfesor(void)
    {
        return Profesor::retNumeComplet();
    }
};

#endif // DISCIPLINA_H
