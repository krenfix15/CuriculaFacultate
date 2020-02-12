#ifndef PERSOANA_H
#define PERSOANA_H

#include <iostream>
#include <stdlib.h>
#include <string.h>


using namespace std;

class Persoana
{
protected:
    char nume[20], prenume[20], data_n[20]; /*dd.mm.yyyy*/
    char _buff[50]= {0}; /* utilizat pentru constructii de siruri returnate */

public:
    Persoana( char _nume[]="", char _prenume[]="", char _data_n[]="")
    {
        int nr,d,m,y;
        strcpy(nume,_nume);
        strcpy(prenume,_prenume);
        nr = sscanf(_data_n, "%2d.%2d.%4d", &d, &m, &y);
        if( ( nr != 3 || m > 12 || d > 31 ) &&  strlen(nume) > 0 )
            throw Exceptie("PERSOANA", "Data nastere incorecta");
        strcpy(data_n,_data_n);
    }

    char* retDataNastere(void)
    {
        return data_n;
    }

    virtual char* retNumeComplet(void)
    {
        strcat(_buff,prenume);
        strcat(_buff," ");
        strcat(_buff,nume);
        return _buff;
    }

    friend istream& operator>>(istream &c, Persoana &p)
    {
        cout<<"Dati numele persoanei : ";
        cin.getline(p.nume,20);

        cout<<"Dati prenumele persoanei : ";
        cin.getline(p.prenume,20);

        cout<<"Dati data de nastere (dd.mm.yyyy) : ";
        cin.getline(p.data_n,20);

        cout<<endl;
    }
};

#endif // PERSOANA_H
