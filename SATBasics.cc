#include "SATBasics.hh"

ostream& operator<<(ostream& os, const SATState& sats)
{
  //unsigned i;
  //for (i = 0; i < sats.in.BoardSize(); i++)
  //  os << sats[i] << " ";
  return os;
}

bool operator==(const SATState& st1, const SATState& st2)
{
  unsigned i;
  //for (i = 0; i < st1.in.BoardSize(); i++)
  //  if (st1[i] != st2[i])
  //    return false;
  return true;
}


SATState::SATState(const SATInput& i)
  : in(i), assignment(in.Literals(), 0) {}

SATState& SATState::operator=(const SATState& st)
{  
  assignment = st.assignment;
  return *this;
}

FlipSAT::FlipSAT(bool l1)
{
  l1 = not l1;
}

ostream& operator<<(ostream& os, const FlipSAT& sat)
{
  os << "<" << sat.l1 << ">";
  return os;
}

istream& operator>>(istream& is, FlipSAT& sat)
{
  char ch;
  //is >> ch >> sq.p1 >> ch >> sq.p2 >> ch;
  return is;
}

bool operator==(const FlipSAT& s1, const FlipSAT& s2)
{
  return s1.l1 == s2.l1;
}

bool operator!=(const FlipSAT& s1, const FlipSAT& s2)
{
  return s1.l1 != s2.l1;
}

bool operator<(const FlipSAT& s1, const FlipSAT& s2)
{
  return s1.l1 < s2.l1;
}

