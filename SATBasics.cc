#include "SATsBasics.hh"

ostream& operator<<(ostream& os, const SATState& sats)
{
  unsigned i;
  for (i = 0; i < sats.in.BoardSize(); i++)
    os << sats[i] << " ";
  return os;
}

bool operator==(const SATState& st1, const SATState& st2)
{
  unsigned i;
  for (i = 0; i < st1.in.BoardSize(); i++)
    if (st1[i] != st2[i])
      return false;
  return true;
}


SATState::SATState(const SATInput& i)
  : in(i), positions(in.BoardSize(), 0) {}

SATState& SATState::operator=(const SATState& st)
{  
  positions = st.positions;
  return *this;
}

SwapSAT::SwapSAT(unsigned pos1, unsigned pos2)
{
  p1 = pos1;
  p2 = pos2;
}

ostream& operator<<(ostream& os, const SwapSAT& satq)
{
  os << "<" << sq.p1 << "," << sq.p2 << ">";
  return os;
}

istream& operator>>(istream& is, SwapSAT& sq)
{
  char ch;
  is >> ch >> sq.p1 >> ch >> sq.p2 >> ch;
  return is;
}

bool operator==(const SwapSAT& sq1, const SwapSAT& sq2)
{
  return sq1.p1 == sq2.p1 && sq1.p2 == sq2.p2;
}

bool operator!=(const SwapSAT& sq1, const SwapSAT& sq2)
{
  return sq1.p1 != sq2.p1 || sq1.p2 != sq2.p2;
}

bool operator<(const SwapSAT& sq1, const SwapSAT& sq2)
{
  return sq1.p1 < sq2.p1 || (sq1.p1 == sq2.p1 && sq1.p2 < sq2.p2);
}

