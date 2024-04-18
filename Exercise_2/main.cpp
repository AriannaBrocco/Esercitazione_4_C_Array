#include <iostream>
#include <fstream>
#include <sstream>

#include "Utils.hpp"

using namespace std;




int main()
{
    string fileName = "data.csv";
    size_t n = 0;
    double S = 0;
    double* w = nullptr;
    double* r = nullptr;

    if (!ImportaValori(fileName, n, S, w, r))
    {
        cerr << "Qualcosa è andato storto nell'operazione di importo" << endl;
        return -1;
    }
    else
        cout<< "L'importo ha avuto successo: n= "<< n<< " w = "<< w << " r = "<< r << endl;

    double rate = rateOfReturn(S, n, w, r);
    cout << "Rate of Return: "<< rate << endl;

    string outputFileName = "result.txt";
    if (!EsportaRisultati(outputFileName,n, r, w, rate, S))
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

