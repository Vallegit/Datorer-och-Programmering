#include <iostream>
using namespace std;

//***************************************************************************
//Funktion skrivInfo
//Syfte: Beskriver programmets funktionalitet
void skrivInfo(){
    cout << "<<<<<<<<<<<<<<<<<<<<< INFO >>>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << "Detta program later dig utfora de matematiska operationerna: " << endl;
    cout << "-Addition (a) \n-Multiplikation (m) \n-Kvadrering (k)" << endl;
    cout << "Pa alla tal inom ett intervall pa tva tal som anvandaren anger" << endl;
    cout << "Tex: om du anger talen 1 och 3 och operationen k returneras svaret 14" <<endl;
    cout << "Eftersom 1*1 + 2*2 + 3*3 = 14" << endl;
    cout << "<<<<<<<<<<<<<<<<<<<<< INFO >>>>>>>>>>>>>>>>>>>>>>>\n" << endl;
}
//***************************************************************************
//Funktion lasEttTal
//Syfte: Läser in ett tal från användaren.
int lasEttTal(){
  int tal;
  cout << "Ange ett tal: ";
  cin >> tal;
  return tal;
}

//***************************************************************************
//Funktion kostnad
//Syfte: Läser in en karaktär som representerar en matematisk operation.
char lasOp(){
  char op;
  cout << "Ange en operation: ";
  cin >> op;
  return op;
}

//***************************************************************************
//Funktion ordna
//Syfte: Ordnar om talen i storleksordning ifall användaren angett tal1 > tal2
//Inparametrar: tal1  - Undre gräns på intervallet. 
//              tal2  - Övre gräns på intervallet.
void ordna(int &tal1, int &tal2){
  int temp;
  if(tal1 > tal2){
    temp = tal1;
    tal1 = tal2;
    tal2 = temp;
  }
}

//***************************************************************************
//Funktion berakna
//Syfte: Läser in en karaktär som representerar en matematisk operation.
//Inparametrar: undre - Undre gräns på intervallet
//              ovre  - Övre grän på intervallet
//              op    - Matematisk operation att utföra.
int berakna(int undre, int ovre, char op){
  int summa = 0;
  int temp = undre;
  //Utför matematisk operation på alla tal inom det givna intervallet och summerar detta.
  for(int i = undre; undre<=ovre; undre++){
    switch(op){
      case 'a':
        summa += undre;
        break;
      case 'm':
        if(temp == undre){
          summa = undre;
        }
        else{
          summa = summa * undre;
        }
        break;
      case 'k':
        summa += undre * undre;
    }
  }

  return summa;
}

//***************************************************************************
//Funktion skrivResultat
//Syfte: Skriver ut resultatet utav beräkningen. 
void skrivResultat(int svar){
  cout << "Svaret blir: " << svar << endl;
}

int main()
{  
  int tal1;
  int tal2;
  char op;
  int svar;
  
  skrivInfo();

  tal1 = lasEttTal();

  tal2 = lasEttTal();

  op = lasOp();

  ordna(tal1, tal2);

  svar = berakna(tal1, tal2, op);

  skrivResultat(svar);

  return 0;
}