#pragma once
#include "iostream"

using namespace std;

bool ImportaValori(const string& fileName,
                   size_t& n,
                   double& S,
                   double*& w,
                   double*& r);

double rateOfReturn(double& S,
                    const size_t& n,
                    const double* const& w,
                    const double* const& r);

bool EsportaRisultati(const string& outputFileName,
                      size_t& n,
                      const double* const& r,
                      const double* const& w,
                      double& operazione,
                      double& S);
