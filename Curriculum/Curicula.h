#ifndef CURICULA_H
#define CURICULA_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Disciplina.h"
#include "Student.h"

using namespace std;

class Curicula
{
    int N;                  /*numarul total de discipline*/
    char den_specializ[50]; /*Specializare*/
    int  sem[20];           /*semestre: 1/2/3/4/5/6/7/8...*/
    int  id_disc[20];       /*id-uri discipline din curicula*/
    char tip_disc[20][15];  /*Obigatorie/Facultativa/Optionala ...*/
public:

    Curicula(char _spec[]) : N(0)
    {
        if( strcmp(_spec, "Calculatoare") !=0 && strcmp(_spec, "Automatica") !=0 )
            throw Exceptie("CURICULA", "Specializare incorecta");
        strcpy( den_specializ, _spec);
    }

    void Add( int _sem, Disciplina &d, char _tip[] )
    {
        if( strcmp(_tip, "Obligatorie") !=0 && strcmp(_tip, "Facultativa") !=0 && strcmp(_tip, "Optionala  ") !=0 )
            throw Exceptie("CURICULA", "Specializare incorecta");
        sem[N] = _sem;
        id_disc[N] = d.getIDDisc();
        strcpy( tip_disc[N], _tip );
        N++;
    }

    void PrintCuricula( Disciplina *d[], int nr )
    {
        cout<<"\n\tCuricula specializarea: "<<den_specializ<<endl;
        cout<<"\nSEM |  TIP          | DISCIPLINA "<<endl;
        for( int i = 0; i < N; i++ )
        {
            cout<<sem[i]<<"   |  "<<tip_disc[i]<<"  |  ";
            for( int j = 0; j < nr; j++)
                if( d[j]->getIDDisc() == id_disc[ i ] )
                {
                    cout<<d[j]->retNumeComplet()<<endl;
                    break;
                }
        }
    }

    void PrintCuriculaSem( Disciplina *d[], int nr, int _sem )
    {
        cout<<"\n\tCuricula specializarea: "<<den_specializ<<endl;
        cout<<"\nSEM |  TIP          | DISCIPLINA "<<endl;
        for( int i = 0; i < N; i++ )
        {
            if( sem[i] != _sem)
                continue;
            cout<<sem[i]<<"   |  "<<tip_disc[i]<<"  |  ";
            for( int j = 0; j < nr; j++)
                if( d[j]->getIDDisc() == id_disc[ i ] )
                {
                    cout<<d[j]->retNumeComplet()<<endl;
                    break;
                }
        }
    }

    static void PrintCuriculaStud( Curicula *c[], int nrC, Student s, Disciplina *d[], int nrD )
    {
        cout<<"\n\tCuricula student: "<<s.retNumeComplet()<<endl;
        for( int i = 0; i < nrC; i++ )
        {
            if( strcmp(c[i]->den_specializ, s.retSpec() ) == 0 )
                c[i]->PrintCuricula( d, nrD );
        }
    }

    static void AnalizaIdentic( Curicula c1, Curicula c2  )
    {
        int nrIdentic = 0;
        for( int i = 0; i < c1.N; i++)
            for( int j = 0; j < c2.N; j++)
                    if( c1.id_disc[i] == c2.id_disc[j] )
                        nrIdentic++;
        cout<<"Curicula de la specializarea ["<<c1.den_specializ<<"] are: \n\t- "<<
              nrIdentic<<" discipline identice cu specializarea ["<<c2.den_specializ<<"] "<<
              "\n\t- dintr-un numar de "<<c1.N<<" discipline"<<endl;
    }

    static void AnalizaDiferit( Curicula c1, Curicula c2 )
    {
        int nrIdentic = 0;
        for( int i = 0; i < c1.N; i++)
            for( int j = 0; j < c2.N; j++)
                    if( c1.id_disc[i] == c2.id_disc[j] )
                        nrIdentic++;
        cout<<"Curicula de la specializarea ["<<c1.den_specializ<<"] are: \n\t- "<<
              c1.N-nrIdentic<<" discipline diferite cu specializarea ["<<c2.den_specializ<<"] "<<
              "\n\t- dintr-un numar de "<<c1.N<<" discipline"<<endl;
    }
};

#endif // CURICULA_H
