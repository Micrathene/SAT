#ifndef _SAT_HELPERS_HH_
#define _SAT_HELPERS_HH_

#include "SATBasics.hh"
#include <easylocal/easylocal.hh>

using namespace EasyLocal::Core;

class SATStateManager
  : public StateManager<SATInput,SATState,int>
{
public:
  SATStateManager(const SATInput& i)
    : StateManager<SATInput,SATState,int>(i,"SATStateManager") {}
  void RandomState(SATState &st);
  bool CheckConsistency(const SATState &st) const;
};

class SATOutputManager
  : public OutputManager<SATInput, SATOutput, SATState, int>
{
public:
  SATOutputManager(const SATInput& i)
    : OutputManager<SATInput,SATOutput,SATState,int>(i, "SATOutputManager") {}
  void OutputState(const SATState &st, SATOutput& out) const;
  void InputState(SATState &st, const SATOutput& out) const;
};

class FlipNeighborhoodExplorer
  :  public NeighborhoodExplorer<SATInput,SATState,FlipSAT,int>
{
public:
  FlipNeighborhoodExplorer(const SATInput& in,
                     StateManager<SATInput, SATState ,int>& satsm)
    : NeighborhoodExplorer<SATInput,SATState,FlipSAT,int>(in, satsm, "FlipNeighborhoodExplorer")
  {}
  void MakeMove(SATState &st, const FlipSAT& sw) const;
  void RandomMove(const SATState &st, FlipSAT& sw) const throw(EmptyNeighborhood);
  void FirstMove(const SATState &st, FlipSAT& sw) const throw(EmptyNeighborhood);
  bool NextMove(const SATState &st, FlipSAT& sw) const;
  bool FeasibleMove(const SATState &st, const FlipSAT& sw) const;
};

class DiagonalCostComponent : public CostComponent<SATInput, SATState,int>
{
public:
  DiagonalCostComponent(const SATInput& in) 
    : CostComponent<SATInput, SATState ,int>(in, 1, true, "Diagonal") {}
  int ComputeCost(const SATState& st) const;
  void PrintViolations(const SATState& st, ostream& os = cout) const;
};

class DiagonalDeltaCostComponent
  : public DeltaCostComponent<SATInput, SATState, FlipSAT,int>
{
public:
  DiagonalDeltaCostComponent(const SATInput& in, DiagonalCostComponent& cc)
    : DeltaCostComponent<SATInput, SATState, FlipSAT,int>(in, cc, "DiagonalDeltaCostComponent")  {}
  int ComputeDeltaCost(const SATState& st, const SwapSAT& sw) const;
};
#endif
