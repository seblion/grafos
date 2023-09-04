#include <iostream>
#include <fstream>
#include <iomanip>
#include <unistd.h>
#include <windows.h>
#include <cctype> 
#include <vector>
#include "..\lib\jlUtilities.h"
#include "..\lib\patColor.h"
#include "..\lib\patString.h"
#include "..\lib\patSerie.h"
#include "..\lib\patUtility.h"
#include "..\lib\utilitario.h"
using namespace std;
const string pathPalabra = "../../data/palabra.txt";

 
vector <string> palabra;

//tokens

int const   Q = 11,
            L = 13,
            TK_ER  = -10,
            TK_SI  = -20,
            TK_SN  = -30,
            TK_SL  = -40;
string const ALFA = "sialtrno (;\n{";

int const mt[Q][L]=
{//  s      i      a      l      t      r      n      o     ' '     (      ;     \n      {         
    {1,     TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER},   // qo 
    {TK_ER, 2,     3,     TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER},   // q1  
    {TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, 8,     TK_ER, TK_SI, TK_SI, TK_ER, TK_ER, TK_ER},   // q2 
    {TK_ER, TK_ER, TK_ER, 4,     TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER},   // q3  
    {TK_ER, TK_ER, TK_ER, TK_ER, 5,     TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER},   // q4  
    {TK_ER, TK_ER, 6,     TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER},   // q5  
    {TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, 7,     TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER},   // q6 
    {TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_SL, TK_ER, TK_SL, TK_ER, TK_ER},   // q7  
    {TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, 9,     TK_ER, TK_ER, TK_ER, TK_ER, TK_ER},   // q8 
    {TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_ER, TK_SN, TK_SN},   // q9  
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
 
        if(q == TK_SI)
            cout<< "ok, se valido si";
        if(q == TK_SN)
            cout<< "ok, se valido sino";        
        if(q == TK_SL)
            cout<< "ok, se valido saltar";
        if(q == TK_ER)
        {
            cout<< "palabra ("<< w <<") : NO ES VALIDA";
            break;
        }
    }
}

 
bool readArchivo()
{
    fstream f;
    string line;

    cout << "readArchivo:" << pathPalabra << endl;
    f.open(pathPalabra, ios_base::in);
    if (!f.is_open())
        cout << "Error al abrir el archivo:" << pathPalabra << endl;
        else 
        {
            while(!f.eof())
            {
                string c;
                vector<string> vDato;
                getline(f, line);
                vDato = SplitToVector(line, '\n');
                c = vDato.at(0);
                palabra.push_back(c);
            }
            return true;
        }
        f.close();
        return false;

}

int main()
{
    readArchivo();

    for (auto &&c : palabra)
    {
        if(c.length() < 8)
        {
        validarW(c);
        cout <<endl;
        } 
        else 
        {
            cout << "palabra ("<< c <<") : NO ES VALIDA" <<endl;
        }
    }
    return 0;
}