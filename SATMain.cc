//#include "SATHelpers.hh"
#include "SATData.hh"
//using namespace EasyLocal::Debug;

int main(int argc, const char* argv[])
{
  //ParameterBox main_parameters("main", "Main Program options");
    
    SATInput in("in_file"); //Hardcoded, bad
    
    cout << in;
    
    

    

    return 0;
    /*
  // The set of arguments added are the following:
  Parameter<string> instance("instance", "Input instance", main_parameters); 
  Parameter<int> seed("seed", "Random seed", main_parameters);
  Parameter<string> method("method", "Solution method (empty for tester)", main_parameters);   
  Parameter<string> init_state("init_state", "Initial state (to be read from file)", main_parameters);
  Parameter<unsigned> observer("observer", "Attach the observers", main_parameters);
  Parameter<string> output_file("output_file", "Write the output to a file (filename required)", main_parameters);
 
  CommandLineParameters::Parse(argc, argv, false, true);  

  // data classes
  QueensInput in(instance);

  if (seed.IsSet())
    Random::Seed(seed);
  
  // helpers
  SATStateManager satsm(in);
  SwapNeighborhoodExplorer sathe(in, qsm);
  SATOutputManager satom(in);
  
  // cost components
  //DiagonalCostComponent cc1(in);
  //DiagonalDeltaCostComponent dcc1(in, cc1);
  
  satsm.AddCostComponent(cc1);
  sathe.AddDeltaCostComponent(dcc1);

  // runners
  HillClimbing<SATInput, SATState, FlipSAT,int> sathc(in, satsm, sathe, "SwapHillClimbing");
  SteepestDescent<SATInput, SATState, FlipSAT,int> satsd(in, satsm, sathe, "SwapSteepestDescent");
  //  TabuSearch<QueensInput, QueensState, SwapQueens,int> qts(in, qsm, qnhe, qtlm, "SwapTabuSearch");
  SimulatedAnnealing<SATInput, SATState, FlipSAT,int> satsa(in, satsm, sathe, "SwapSimulatedAnnealing");

  if (!CommandLineParameters::Parse(argc, argv, true, false))
    return 1;

  if (!instance.IsSet())
    {
      cout << "Error: --main::instance=filename option must always be set" << endl;
      return 1;
    }

  // tester
  Tester<SATInput, SATOutput, SATState,int> tester(in,satsm,satom);
  MoveTester<SATInput, SATOutput, SATState, FlipSAT,int> swap_move_test(in,satsm,satom,sathe, "Flip move", tester);


  tester.RunMainMenu();
  return 0;*/
}
