#pragma once
#include "iostream"

using namespace std;

bool ImportaValori(const string& fileName,
                   size_t& n,
                   double& S,
                   double*& w,
                   double*& r);

double finalValue(double& S,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r);

double rateOfReturn(const size_t& n,
                    const double* const& w,
                    const double* const& r);

bool EsportaRisultati(const string& outputFileName,
                      size_t& n,
                      const double* const& r,
                      const double* const& w,
                      double& final_Value,
                      double& rate_Of_Return,
                      double& S);
