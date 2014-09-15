#ifndef _SAT_BASICS_HH_
#define _SAT_BASICS_HH_

#include "SATData.hh"

class SATState
{
  friend ostream& operator<<(ostream&, const SATState& sats);
  friend bool operator==(const SATState& st1, const SATState& st2);
public:
  SATState(const SATInput& i);
  SATState& operator=(const SATState& st);


protected:
  const SATInput& in; 
  vector<bool> assignment;
  vector<bool> violations;



};

class SwapSAT
{
  friend ostream& operator<<(ostream&, const SwapSAT &);
  friend istream& operator>>(istream&, SwapSAT &);
  friend bool operator==(const SwapSAT& sw1, const SwapSAT& sw2);
  friend bool operator!=(const SwapSAT& sw1, const SwapSAT& sw2);
  friend bool operator<(const SwapSAT& sw1, const SwapSAT& sw2);
public:
  SwapSAT(unsigned pos1 = 0, unsigned pos2 = 0);
  unsigned p1, p2;
};

#endif
