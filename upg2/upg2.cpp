#include <iostream>
using namespace std;

int main(){

    int startNmr, vinnare;
    int startTimme, startMinut, startSekund;
    int slutTimme, slutMinut, slutSekund;
    int startTot, slutTot, diff;
    int bestTimme, bestMinut, bestSekund;
    int antal = 0;
    int bestTot = 99*60*60;

    // Loop l„ser in data, r„knar ut sluttid och j„mf”r mot b„sta tiden.
    while(true){
        cout << "Startnummer? ";
        cin >> startNmr;
        if(startNmr <= 0){
          break;
        }
        cout << "Starttid? ";
        cin >> startTimme >> startMinut >> startSekund;
        cout << "Sluttid? ";
        cin >> slutTimme >> slutMinut >> slutSekund;

        // G”r om HH:MM:SS format till endast sekunder.
        startTot = startTimme*60*60 + startMinut*60 + startSekund;
        slutTot = slutTimme*60*60 + slutMinut*60 + slutSekund;

        // Tar h„nsyn till fall med tids”verg†ng vid midnatt.
        if(startTot > slutTot){
          diff = slutTot - (startTot - 24*60*60);
        }
        else{
          diff = slutTot - startTot;
        }

        // J„mf”r om nuvarande startnummer har den b„sta tiden.
        if(bestTot > diff){
          vinnare = startNmr;
          bestTot = diff;
        }

        antal++;
    }

    // G”r om sekunder till HH:MM:SS format.
    bestTimme = bestTot/3600;
    bestMinut = (bestTot%3600)/60;
    bestSekund = bestTot % 60;

    // Skriver ut Vinnare, tiden samt antalet t„vlande om det fanns t„vlande.
    if(antal <= 0) {
      cout << "Inga T„vlande";
    }
    else {
    cout << "Vinnare „r startnr: " << vinnare;
    cout << "\nTim: " << bestTimme << " Min: " << bestMinut << " Sek: " << bestSekund;
    cout << "\nAntal T„vlande: " << antal;
    }

  return 0;
}