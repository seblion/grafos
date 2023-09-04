#include <iostream>
using namespace std;
 
//tokens
int const   Q = 5,
            L = 5,
            TK_ER = -10,
            TK_SI = -20,
            TK_NO = -30;
string const ALFA = "sino ";
int const mt[Q][L]=
{//  s      i      n      o      ' '           s    i    n    o   ' '
    {1,     TK_ER, 2,     TK_ER, TK_ER},   // qo   1    -    2    -    -
    {TK_ER, 3,     TK_ER, TK_ER, TK_ER},   // q1   -    3    -    -    -  
    {TK_ER, TK_ER, TK_ER, 4,     TK_ER},   // q2   -    -    -    4    -
    {TK_ER, 3,     TK_ER, TK_ER, TK_SI},   // q3   -    3    -    -    ok
    {TK_ER, TK_ER, TK_ER, 4,     TK_NO}    // q4   -    -    -    4    ok
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
        if(q == TK_NO)
            cout<< "ok, se valido no";
        if(q == TK_ER)
        {
            cout<< "palabra (w) : NO ES VALIDA" <<endl;
            exit(0);
        }
    }
}
 
int main()
{
    validarW("siii ");  //ok
    cout <<endl;
   
    validarW("no ");             //ok
    cout <<endl;
   
    validarW("sinoooooo ");      //error
    cout <<endl;
 
    // for (int i = 0; i < Q; i++)
    // {
    //     for (int j = 0; j < L; j++)
    //         cout << mt[i][j] <<"\t";
    //     cout<<endl;
    // }
    return 0;
}
            // try
            // {
            //     if(m == 10 || m == 25 || m == 50 )
            //         break;
            //     throw;
            // }
            // catch(...)
            // {
            //     cout << "valor invalido";
            // }