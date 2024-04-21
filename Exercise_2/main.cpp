#include <iostream>
#include <fstream>
#include <sstream>

#include <iomanip>

#include "Utils.hpp"

using namespace std;


int main()
{
    // Inizializza le variabile a cui sarà assegnato il valore tramite ImportaValori
    string fileName = "data.csv";
    size_t n = 0;
    double S = 0.0;
    double* w = nullptr;
    double* r = nullptr;

    if (!ImportaValori(fileName, n, S, w, r))
    {
        cerr << "Qualcosa è andato storto nell'operazione di importo" << endl;
        return -1;
    }
    else
        cout<< "L'importo ha avuto successo"<< endl;

    // Stampa i valori
    double rate = rateOfReturn(n, w, r);
    double val = finalValue(S, n, w, r);
    cout << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    cout << "w = [ ";

    for (unsigned int i = 0; i<n; i++){
        cout<< w[i]<< " ";}
    cout << "]" << endl;

    cout << "r = [ ";
    for (unsigned int i = 0; i<n; i++){
        cout<< r[i]<< " ";}
    cout << "]" << endl;


    cout << "Rate of return of the portfolio: " << fixed << setprecision(4) << rate << endl;

    cout << "V: "  << fixed << setprecision(2) << val << endl;

    // Esporta i risultati sul file results
    string outputFileName = "result.txt";
    if (!EsportaRisultati(outputFileName,n, r, w, val, rate, S))
    {
        cerr << "Qualcosa è andato storto nell'operazione di esportazione"<< endl;
        return -1;
    }
    else
        cout<< "L'esportazione ha avuto successo"<< endl;

    delete[] w;
    delete[] r;

    return 0;
}

