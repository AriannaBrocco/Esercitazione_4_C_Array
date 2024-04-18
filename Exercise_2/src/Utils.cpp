#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"

#include <vector>
#include <string>


using namespace std;

bool ImportaValori(const string& fileName,
                   size_t& n,
                   double& S,
                   double*& w,
                   double*& r)
{
    // Aprire il file
    ifstream file;
    file.open(fileName);

    if (file.fail())
    {
        cerr << "Il file: " << fileName << "non esiste" << endl;
        return false;
    }

    // Ottenere i vari valori
    string riga;

    while (!file.eof())
    {
        getline(file, riga);
    }
    istringstream convertElemento;
    convertElemento.str(riga);
    size_t posizione = riga.find(';');
    string dopo_pev = riga.substr(posizione+1);
    double valore = stod(dopo_pev);
    S = valore;

    while (!file.eof())
    {
        getline(file, riga);
    }
    istringstream convertElemento2;
    convertElemento2.str(riga);
    size_t posizione2 = riga.find(';');
    string dopo_pev2 = riga.substr(posizione2+1);
    unsigned int valore2 = stod(dopo_pev2);
    n = valore2;

    w = new double[n];
    r = new double[n];
    for (unsigned int i = 0; i<n; i++)
        while (!file.eof())
        {
            getline(file, riga);
            if(riga[0] != 'w')
                break;
            istringstream convertElemento3;
            convertElemento3.str(riga);
            size_t posizione3 = riga.find(';');
            string prima_pev3 = riga.substr(0,posizione3);
            double valore3 = stod(prima_pev3);
            string dopo_pev3 = riga.substr(posizione3+1);
            double valore4 = stod(dopo_pev3);
            w[i] = valore3;
            r[i] = valore4;
        }


    file.close();

    return true;
}


double rateOfReturn(double& S,
                    const size_t& n,
                    const double* const& w,
                    const double* const& r)
{
    double operazione = 0;
    for (unsigned int i = 0; i < n; i++)
        operazione += (1 + r[i])*(w[i]*(S));

    return operazione;
}


bool EsportaRisultati(const string& outputFileName,
                      size_t& n,
                      const double* const& r,
                      const double* const& w,
                      double& operazione,
                      double& S)
{
    // Aprire il file
    ofstream file;
    file.open(outputFileName);
    if (file.fail())
    {
        cerr << "Il file: " << outputFileName << "non esiste" << endl;
        return false;
    }

    file << "S = " << S << ", n = " << n << endl;

    file<< "w = "<< w << endl;
    file<< "r = "<< r << endl;

    file<< "Rate of return of the portfolio: "<< operazione/S << endl;
    file<< "V: " << operazione << endl;


    // Close File
    file.close();

    return true;
}


