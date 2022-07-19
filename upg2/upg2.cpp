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

    // Loop läser in data, räknar ut sluttid och jämför mot bästa tiden.
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

        // Gör om HH:MM:SS format till endast sekunder.
        startTot = startTimme*60*60 + startMinut*60 + startSekund;
        slutTot = slutTimme*60*60 + slutMinut*60 + slutSekund;

        // Tar hänsyn till fall med tidsövergång vid midnatt.
        if(startTot > slutTot){
          diff = slutTot - (startTot - 24*60*60);
        }
        else{
          diff = slutTot - startTot;
        }

        // Jämför om nuvarande startnummer har den bästa tiden.
        if(bestTot > diff){
          vinnare = startNmr;
          bestTot = diff;
        }

        antal++;
    }

    // Gör om sekunder till HH:MM:SS format.
    bestTimme = bestTot/3600;
    bestMinut = (bestTot%3600)/60;
    bestSekund = bestTot % 60;

    // Skriver ut Vinnare, tiden samt antalet tävlande om det fanns tävlande.
    if(antal <= 0) {
      cout << "Inga Tävlande";
    }
    else {
    cout << "Vinnare är startnr: " << vinnare;
    cout << "\nTim: " << bestTimme << " Min: " << bestMinut << " Sek: " << bestSekund;
    cout << "\nAntal Tävlande: " << antal;
    }

  return 0;
}