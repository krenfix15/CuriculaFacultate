#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Persoana.h"


using namespace std;

class Student : public Persoana
{
    char nr_mat[20];    /*numar matricol*/
    char specializ[20]; /*Specializare*/
    float note[100];
    int   sem[100], nrNote;
    char _buff[50]; /* utilizat pentru constructii de siruri returnate */

public:
    Student(Persoana &_pers, char _nr_mat[], char _spec[]) : Persoana(_pers ), nrNote( 0 )
    {
        strcpy( nr_mat, _nr_mat );
        strcpy( specializ, _spec );
    }

    char* retNumeComplet(void)
    {
        return strcat( strcat( strcat( strcat( strcpy(_buff, nr_mat)," - "), nume), " "), prenume);
    }

    char* retNrMat(void)
    {
        return nr_mat;
    }

    char* retSpec(void)
    {
        return specializ;
    }

    static void PrintStudenti( Student *p[], int nr, char numePart[] )
    {
        cout<<"\tStudenti ce contin '"<<numePart<<"' in nume : "<<endl;
        for( int i = 0; i < 3/*nr*/; i++ )
        {
            if( strstr( p[i]->retNumeComplet(), numePart  ) != NULL )
                cout<<"\t\t"<<p[i]->retNumeComplet()<<endl;
        }
    }
};

#endif // STUDENT_H

