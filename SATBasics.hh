#ifndef _SAT_BASICS_HH_
#define _SAT_BASICS_HH_

#include "SATData.hh"

class SATState
{
  friend ostream& operator<<(ostream&, const SATState& sats);
  friend ostream& operator<<(ostream&, const SATState& sat);
  friend ostream& operator>>(ostream& os, const SATState& sat);
  friend bool operator==(const SATState& st1, const SATState& st2);
public:
  SATState(const SATInput& i);
  SATState& operator=(const SATState& st);
  void flipLiteral(unsigned l);

protected:
  const SATInput& in; 
  vector<bool> assignment;
  vector<bool> violations;



};

class FlipSAT
{
  friend ostream& operator<<(ostream&, const FlipSAT &);
  friend istream& operator>>(istream&, FlipSAT &);
  friend bool operator==(const FlipSAT& sw1, const FlipSAT& sw2);
  friend bool operator!=(const FlipSAT& sw1, const FlipSAT& sw2);
  friend bool operator<(const FlipSAT& sw1, const FlipSAT& sw2);
public:
  FlipSAT(bool l1 = false);
  bool l1;
};

#endif
