#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Exceptie.h"
#include "Persoana.h"
#include "Profesor.h"
#include "Student.h"
#include "Disciplina.h"
#include "Curicula.h"

using namespace std;

const int NrCuricule = 2;
const int NrStudenti = 20;
const int NrProfesori = 18;
const int NrDiscipline = 18;

int Profesor::nextID = 0;/*init membru static*/
int Disciplina::nextID = 0;

int main()
{
    cout << "[CURICULA-FACULTATEA DE INGINERIE ELECTRICA SI STIINTA CALCULATOARELOR]" << endl;
    cout << "\n------------------------INTRODUCERE DATE-----------------------------------\n" << endl;
    try
    {
        Persoana p1("PASCAL", "Marian", "20.03.1992");
        Persoana p2("POPESCU", "Vasile", "10.04.1993");
        Persoana p3;

        cin>>p3;

        Student  *st[NrStudenti];
        st[0] = new Student( p1, "01/C", "Calculatoare" );
        st[1] = new Student( p2, "02/A", "Automatica" );
        st[2] = new Student( p3, "03/C", "Calculatoare" );

        Persoana pp1("MARINESCU", "Vasile", "23.09.1972");
        Persoana pp2("CORBU", "Stefan", "11.02.1973");
        Persoana pp4("POTORAC", "Alexandru", "11.05.1970");
        Persoana pp5("PRELIPCEANU", "Ionut", "06.10.1980");
        Persoana pp6("Turcu", "Toader", "07.07.1977");
        Persoana pp3;

        cin>>pp3;

        Profesor *pr[NrProfesori];
        pr[0] = new Profesor( pp1, "s.l.");
        pr[1] = new Profesor( pp2, "profesor");
        pr[2] = new Profesor( pp3, "conferentiar" );
        pr[3] = new Profesor( pp4, "profesor");
        pr[4] = new Profesor( pp5, "s.l.");
        pr[5] = new Profesor( pp6, "conferentiar");

        Disciplina *disc[ NrDiscipline ];
        disc[0] = new Disciplina("Programare Orientata pe Obiecte", *pr[0]);
        disc[1] = new Disciplina("Fizica I", *pr[1]);
        disc[2] = new Disciplina("Analiza matematica", *pr[2]);
        disc[3] = new Disciplina("Electronica Digitala", *pr[3]);
        disc[4] = new Disciplina("Proiectare Logica", *pr[4]);
        disc[5] = new Disciplina("Teoria Sistemelor", *pr[5]);

        cout<<"\n------------------------Teste POLIMORFISM-----------------------------------\n"<<endl;

        Persoana *pers[4];
        pers[0] = &p3;
        pers[1] = st[2];
        pers[2] = pr[2];
        pers[3] = disc[0];

        cout<<"\tPersoana  : "<<pers[0]->retNumeComplet()<<endl;
        cout<<"\tStudentul : "<<pers[1]->retNumeComplet()<<endl;
        cout<<"\tProfesorul: "<<pers[2]->retNumeComplet()<<endl;
        cout<<"\tDisciplina: "<<pers[3]->retNumeComplet()<<endl;

        cout<<"\n------------------------SFARSIT Teste POLIMORFISM---------------------------"<<endl;


        Curicula *curicula[ NrCuricule ];
        curicula[0] = new Curicula( "Calculatoare" );
        curicula[0]->Add(1, *disc[0], "Obligatorie");
        curicula[0]->Add(1, *disc[1], "Obligatorie");
        curicula[0]->Add(1, *disc[2], "Optionala  ");
        curicula[0]->Add(1, *disc[3], "Obligatorie");


        curicula[1] = new Curicula( "Automatica" );
        curicula[1]->Add(1, *disc[1], "Obligatorie");
        curicula[1]->Add(1, *disc[2], "Obligatorie");
        curicula[1]->Add(1, *disc[4], "Obligatorie");
        curicula[1]->Add(1, *disc[5], "Optionala  ");

        cout << "\nAFISARE CURICULA" << endl;
        cout<<"----------------------------------------------------------------------------";
        curicula[0]->PrintCuricula( disc, NrDiscipline );
        cout<<"----------------------------------------------------------------------------";

        cout<<endl;
        cout<<endl;

        cout<<"----------------------------------------------------------------------------";
        curicula[1]->PrintCuricula( disc, NrDiscipline );
        cout<<"----------------------------------------------------------------------------";

        cout<<endl;
        cout<<endl;

        cout <<"\n\tCauta toti profesorii ce contin subsirul 'MARI' in NUME"<<endl;
        Profesor::PrintProfesori( pr, NrProfesori, "MARI" );
        cout <<"\n\tCauta toti studentii ce contin subsirul 'ESCU' in NUME"<<endl;
        Student::PrintStudenti(st,NrStudenti, "ESCU");

        cout<<"----------------------------------------------------------------------------";
        cout <<"\n\tAfisare curicula pe semestrul 1"<<endl;
        curicula[0]->PrintCuriculaSem( disc, NrDiscipline, 1);
        cout<<"----------------------------------------------------------------------------";
        cout<<endl;

        cout<<"\n------------------------CURICULA PENTRU UN STUDENT--------------------------"<<endl;
        Curicula::PrintCuriculaStud( curicula, NrCuricule, *st[2], disc, NrDiscipline );
        cout<<"\n------------------------SFARSIT CURICULA PENTRU STUDENT---------------------"<<endl;


        cout <<"\n\tANALIZA CURICULE"<<endl;
        Curicula::AnalizaIdentic( *curicula[0], *curicula[1] );
        cout<<endl;
        Curicula::AnalizaDiferit( *curicula[0], *curicula[1] );

        cout <<"\n[SFARSIT CURICULA-FACULTATEA DE INGINERIE ELECTRICA SI STIINTA CALCULATOARELOR]"<<endl;
 }
    catch(Exceptie ex)
    {
        ex.Print();
        exit( -2 );
    }
    catch(...)
    {
        cout<<"Exceptie nedefinita!"<<endl;
        exit( -1 );
    }
    return 0;
}
