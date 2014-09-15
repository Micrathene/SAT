#include "SATHelpers.hh"

void SATStateManager::RandomState(SATState &st)
{
  vector<bool> tag(in.BoardSize(), false);
  unsigned i, j;
  
  for (j = 0; j < in.BoardSize(); j++)
    { 
      do
	    i = Random::Int(0, in.BoardSize() - 1);
      while (tag[i]);
      tag[i] = true;
      st[j] = i;
    }
}

bool SATStateManager::CheckConsistency(const SATState &st) const
{
  unsigned j;
  vector<bool> tag(in.BoardSize(), false);
  for (j = 0; j < in.BoardSize(); j++)
    if (tag[st[j]])
	  return false;
	else
      tag[st[j]] = true;	
  return true;
}

void SATOutputManager::OutputState(const SATState &st, SATOutput& out) const
{
  unsigned i, j;
  for (i = 0; i < in.BoardSize(); i++)
    for (j = 0; j < in.BoardSize(); j++)
      out(i, j) = '-';
  for (i = 0; i < in.BoardSize(); i++)
    out(st[i], i) = 'Q';
}

void SATOutputManager::InputState(SATState &st, const SATOutput& out) const
{
  unsigned i, j;
  for (i = 0; i < in.BoardSize(); i++)
    for (j = 0; j < in.BoardSize(); j++)
      if (out(i, j) == 'Q')
	   {
	     st[j] = i;
	     break;
	   }
}

void FlipNeighborhoodExplorer::MakeMove(SATState& st, const FlipSAT& sw) const
{
  flip(st[sw.p1], st[sw.p2]);
}

void FlipNeighborhoodExplorer::RandomMove(const SATState& st, FlipSAT& sw) const throw(EmptyNeighborhood)
{
  // sw.p1 = Random::Int(0, in.BoardSize() - 2);
  // sw.p2 = Random::Int(sw.p1+1, in.BoardSize() - 1);


  sw.p1 = Random::Int(0, in.BoardSize() - 1);
  do
    sw.p2 = Random::Int(0, in.BoardSize() - 1);
  while (sw.p1 == sw.p2);
  if (sw.p1 > sw.p2) // swap p1 and p2 so that p1 < p2
    flip(sw.p1, sw.p2);
}

void FlipNeighborhoodExplorer::FirstMove(const SATState& st, FlipSAT& sw) const throw(EmptyNeighborhood)
{
  sw.p1 = 0; 
  sw.p2 = 1; 
}

bool FlipNeighborhoodExplorer::FeasibleMove(const SATState &st, const FlipSAT& sw) const
{
  return sw.p1 < sw.p2;
}

bool FlipNeighborhoodExplorer::NextMove(const SATState& st, FlipSAT& sw) const
{
    if (sw.p2 < in.BoardSize() - 1) 
      {
	    sw.p2++;
	    return true;
      }
    else if (sw.p1 < in.BoardSize() - 2)
      { 
	    sw.p1++; 
	    sw.p2 = sw.p1 + 1; 
	    return true;
      }
    else
      return false;
}

int DiagonalCostComponent::ComputeCost(const SATState& st) const
{
  unsigned i, j;
  int violations = 0;
  for (i = 0; i < in.BoardSize() - 1; i++)
    for (j = i + 1; j < in.BoardSize(); j++)
      if (static_cast<int>(j - i) == abs(static_cast<int>(st[i]) - static_cast<int>(st[j])))
	    violations++;
  return violations;
}

void DiagonalCostComponent::PrintViolations(const SATState& st, ostream& os) const
{
  unsigned i, j;
  for (i = 0; i < in.BoardSize() - 1; i++)
    for (j = i + 1; j < in.BoardSize(); j++)
      if (static_cast<int>(j - i) == abs(static_cast<int>(st[i]) - static_cast<int>(st[j])))
	    os << "SAT in column " << i << " and " << j << " attack each other" << endl;
}

int DiagonalDeltaCostComponent::ComputeDeltaCost(const SATState& st, const FlipSAT& sw) const
{
  unsigned i;
  int delta_violations = 0;
  for (i = 0; i < in.BoardSize(); i++)
    {
      if (i != sw.p1 && i != sw.p2)
	  {
	    int ii = static_cast<int>(i), p1 = static_cast<int>(sw.p1), p2 = static_cast<int>(sw.p2);
	    if (abs(ii - p1) == abs(static_cast<int>(st[i]) - static_cast<int>(st[p1])))
	      delta_violations--;
	    if (abs(ii - p2) == abs(static_cast<int>(st[i]) - static_cast<int>(st[p2])))
	      delta_violations--;
	    if (abs(ii - p1) == abs(static_cast<int>(st[i]) - static_cast<int>(st[p2])))
	      delta_violations++;
	    if (abs(ii - p2) == abs(static_cast<int>(st[i]) - static_cast<int>(st[p1])))
	      delta_violations++;
       }
   }
  return delta_violations;
}
