#include "SATBasics.hh"

ostream& operator<<(ostream& os, const SATState& sats)
{
  unsigned i;
  for (i = 0; i < sats.in.Clauses(); i++)
    os << "lit" << i+1 << ":" << sats.assignment[i] << endl;
  return os;
}

bool operator==(const SATState& st1, const SATState& st2)
{
  unsigned i;
  for (i = 0; i < st1.in.Clauses; i++){
    if (st1.assignment[i] != st2.assignment[i])
      return false;
  }
  return true;
}


SATState::SATState(const SATInput& i)
  : in(i), assignment(in.Literals(), false), violations(in.Clauses(), false) {}

SATState& SATState::operator=(const SATState& st)
{  
  assignment = st.assignment;
  violations = st.violations;
  return *this;
}

SATState::flipLiteral(unsigned l){
    assignment[l] = !assigment[l];
    vector<int> clauses = getCoveredClauses(l);
    for(int i; i<in.clauses.size(); i++){
        vector<int> literals = in.getLiteralsInClause(clauses[i]);
        violations[clauses[i] = false;
        for(int j; j<literals.size(); j++){
            if ((literals[j] > 0 && assignment[literals[j]) || (literals[j] < 0 && !assignment[-literals[j])){
                violations[clauses[i] = true;
                break;                
            }
        }
    }
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

