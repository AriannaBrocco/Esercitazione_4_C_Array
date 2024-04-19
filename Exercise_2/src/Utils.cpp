#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"

#include <vector>
#include <string>
#include <iomanip>


using namespace std;

double string_to_double(const string& stringa) {
    istringstream stringtodouble(stringa);
    double result;
    stringtodouble >> result;
    return result;
}


bool ImportaValori(const string& fileName,
                   size_t& n,
                   double& S,
                   double*& w,
                   double*& r)
{
    // Apre il file
    ifstream file;
    file.open(fileName);

    if (file.fail())
    {
        cerr << "Il file: " << fileName << "non esiste" << endl;
        return false;
    }

    // Ottiene i vari valori, cerca nella riga il ; e converte la parte di stringa dopo di esso in un double
    string riga;
    getline(file, riga);
    istringstream convertElemento(riga);
    char a, b;
    convertElemento >> a >> b >> S;

    getline(file, riga);
    istringstream convertElemento2(riga);
    convertElemento2 >> a >> b >> n;


    // Ciclo che si ripete per tutti gli 8 elementi degli arrays saltando la riga che contiene 'w;r' e prendendo il primo elemento dalla parte prima del ; e il secondo dopo.
    w = new double[n];
    r = new double[n];
    for (unsigned int i = 0; i<n; i++){
        while (!file.eof())
        {
            getline(file, riga);
            if(riga[0] != 'w')
                break;
        }
        istringstream convertElemento3(riga);
        char b;
        convertElemento3 >> w[i] >> b >> r[i];

    }


    file.close();

    return true;
}


double finalValue(double& S,
                    const size_t& n,
                    const double* const& w,
                    const double* const& r)
{
    double operazione = 0.0;
    for (unsigned int i = 0; i < n; i++)
        operazione += (1 + r[i])*(w[i]*S);

    return operazione;
}
double rateOfReturn(double& S,
                    const size_t& n,
                    const double* const& w,
                    const double* const& r)
{
    double operazione = 0.0;
    for (unsigned int i = 0; i < n; i++)
        operazione += (r[i])*(w[i]);

    return operazione;
}


bool EsportaRisultati(const string& outputFileName,
                      size_t& n,
                      const double* const& r,
                      const double* const& w,
                      double& final_Value,
                      double& rate_Of_Return,
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

    file<< "w = [ ";
    for (unsigned int i = 0; i<n; i++){
        file<< w[i]<< " ";}
    file << "]" << endl;


    file<< "w = [ ";
    for (unsigned int i = 0; i<n; i++){
        file<< r[i]<< " ";}
    file << "]" << endl;


    file<< "Rate of return of the portfolio: " << fixed << setprecision(4) << rate_Of_Return << endl;

    file<< "V: "  << fixed << setprecision(2) << final_Value << endl;


    // Close File
    file.close();

    return true;
}


