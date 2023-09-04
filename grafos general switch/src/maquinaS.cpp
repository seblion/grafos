    #include <iostream>
    #include <fstream>
    #include <iomanip>
    #include <unistd.h>
    // #include <windows.h>
    #include <cctype> 
    #include <vector>
    #include "..\lib\jlUtilities.h"
    #include "..\lib\patColor.h"
    #include "..\lib\patString.h"
    #include "..\lib\patSerie.h"
    #include "..\lib\patUtility.h"
    #include "..\lib\utilitario.h"
    using namespace std;

    
    string money;

    //tokens

    int const   Q = 13,
                L = 4,
                TK_ER  = -10,
                TK_GL  = -20,
                TK_GS  = -30,
                TK_DO  = -40,
                TK_HM  = -50;
    string const ALFA = "abcd"; //a = 10 b = 25 c = 50 

  int const mt[Q][L]=
    {//  a      b      c      d             
        {5,     1,     2,     TK_ER},   // qo   
        {TK_ER, 2,     TK_ER, TK_GL},   // q1    
        {9,     3,     4,     TK_GS},   // q2   
        {TK_ER, 4,     TK_ER, TK_DO},   // q3    
        {TK_ER, TK_ER, TK_ER, TK_HM},   // q4    
        {6,     TK_ER, TK_ER, TK_ER},   // q5    
        {7,     TK_ER, TK_ER, TK_ER},   // q6   
        {8,     TK_ER, TK_ER, TK_ER},   // q7    
        {2,     TK_ER, TK_ER, TK_ER},   // q8   
        {10,    TK_ER, TK_ER, TK_ER},   // q9    
        {11,    TK_ER, TK_ER, TK_ER},   // q10    
        {12,    TK_ER, TK_ER, TK_ER},   // q11    
        {4,     TK_ER, TK_ER, TK_ER},   // q12   
    };      

     

    int getIndiceALFA(char c)
    {
        int index = ALFA.find(c);
        if(index>=0)
            return index;
        return TK_ER;
    }

    void validarW(string w)
    {
        int q=0, l=0;
        for (auto &&c : w )
        {
            l = getIndiceALFA(c);
            q = mt[q][l];

            switch (q)
            {
            case TK_GL: cout<< "retire su galleta";
                break;
            case TK_GS: cout<< "retire su gaseosa";               
                break;
            case TK_DO: cout<< "retire su dorito";
                break;
            case TK_HM: cout<< "retire su Helado Magnum";
                break;  
            case TK_ER: cout<< "Se devuelve tu dinero. Por favor, ingrese la cantidad exacta la proxima vez.";
                break;
            }

        }
    }

    void menu()
    {
        cout << "---------------Maquina expendedora (Suiza)-----------------" <<endl;
        cout << "\tGalleta.........25 ctvs." <<endl;
        cout << "\tGaseosa.........50 ctvs." <<endl;
        cout << "\tDorito..........75 ctvs." <<endl;
        cout << "\tMagnum..........1  dolar" <<endl;
        cout << "(SOLO SE ACEPTAN MONEDAS DE 10, 25, 50 CTVS.)" <<endl;

    }

    void ingresarDinero(string &money)
    {
        int m;
        do
        {
            cout<< "Ingrese una moneda:   ";

                cin >> m;

            cout <<"Escriba -1 para contar las monedas" <<endl;
            switch (m)
            {
            case 10:    money +='a';
                break;
            case 25:    money +='b';
                break;
            case 50:    money +='c';
                break;
            default:
                break;
            }
        } while (m!=-1);
        money +='d';
    }

    int main()
    {
        menu();
        ingresarDinero(money);
        cout<<endl<<"\t";        
        validarW(money);
        cout<<endl;        
        return 0;
    }