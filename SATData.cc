#include <fstream>
#include <cmath>
#include <cassert>
#include <sstream>
#include "SATData.hh"


SATInput::SATInput(string file_name)
{
  ifstream is(file_name.c_str());
  //Not board size, but number of clauses and literals

  if (!is)
  {
    cerr << "Cannot open file " <<  file_name << endl;
	exit(1);
  }
  string line;
  istringstream iss;
  while(getline(is,line)){
	  if(line[0]!='c'){
		  break;
	  }
  }
  iss.str(line.substr(1,string::npos));
  string ch;
  iss >> ch >> nbvar >>  nbclauses;
  formula.resize(nbclauses);
  coverage.resize(nbvar+1);
  unsigned c = 0;

  do {
      getline(is, line);

      if (line[0] == '%' || line[0] == '0' || is.eof())
        break;
      iss.clear();
      iss.str(line);
      int lit;
      formula[c].clear();
      iss >> lit;
      while (lit != 0) {
        assert(lit <= static_cast<int>(nbvar) && lit >= -static_cast<int>(nbvar));
        formula[c].push_back(lit);
        coverage[(lit > 0 ? lit : -lit)-1].push_back(c); //Pos_coverage and neg_coverage?
        iss >> lit;
      }
      c++;
    } while (true);
  assert(c == nbclauses);

}

ostream& operator<<(ostream& os, const SATInput& pa) {
// Insert the code that write the input object (needed for debugging purposes)
    os << "Clauses\n";
  for (unsigned int c=0;c<pa.nbclauses;c++) {
    for (unsigned int l=0;l<pa.formula[c].size();l++)
      os<<pa.formula[c][l]<<" ";
    os<<endl;
  }
  
    os << "Literal coverage\n";
  for (unsigned int c=0;c<pa.nbvar;c++) {
      os << "lit" << c+1 <<": ";
    for (unsigned int l=0;l<pa.coverage[c].size();l++)
      os<<pa.coverage[c][l]<<" ";
    os<<endl;
  }
  return os;
}

//istream& operator>>(istream& is, SATInput& in)
//{
//  is >> in.board_size;
//  return is;
//}

//SATOutput::SATOutput(const SATInput& i)
//  : in(i), cb(in.BoardSize(), vector<char>(in.BoardSize(), '-'))
//{}
//
//ostream& operator<<(ostream& os, const SATOutput& board)
//{
//  unsigned i, j;
//  for (i = 0; i < board.in.BoardSize(); i++)
//    {
//      for (j = 0; j < board.in.BoardSize(); j++)
//	     os << board.cb[i][j];
//      os << endl;
//    }
//  return os;
//}
//
//istream& operator>>(istream& is, SATOutput& board)
//{
//  unsigned i, j;
//  for (i = 0; i < board.in.BoardSize(); i++)
//    for (j = 0; j < board.in.BoardSize(); j++)
//      is >> board.cb[i][j];
//  return is;
//}
