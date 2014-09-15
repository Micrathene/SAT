#ifndef _SAT_DATA_HH_
#define _SAT_DATA_HH_

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class SATInput
{
  friend ostream& operator<<(ostream&, const SATInput &);
  friend istream& operator>>(istream&, SATInput &);
public:
  SATInput(string file_name);
  unsigned Literals() const { return nbvar; }
  unsigned Clauses() const { return nbclauses; }
  vector<unsigned> getCoveredClauses(int index) const {return coverage[index]}
protected:
  unsigned nbvar;
  unsigned nbclauses;
  vector< vector<int> > formula;
  vector<vector<unsigned> > coverage;

};

class SATOutput
{
  friend ostream& operator<<(ostream&, const SATOutput &);
  friend istream& operator>>(istream&, SATOutput &);
public:
  SATOutput(const SATInput& in);
  char operator()(int i, int j) const { return cb[i][j]; }
  char& operator()(int i, int j) { return cb[i][j]; }
protected:
  const SATInput& in; 
  vector<vector<int> > cb;
};
#endif
