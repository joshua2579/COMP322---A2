//Author: Joshua Liben
//Compile: g++ -Wall -o Parser.exe Parser.cc
//Run:  ./Parser testfile.txt


#include "Parser.h"
using namespace std;

Memory* m = new Memory();

//int parseFile(ifstream in)

int main(int argc, char ** argv) {
  if (argc < 2)
  {
    cerr << "Error: No input file specified. Usage Parser <filename>" << endl;
    return 1;
  }

  ifstream in_file;
  in_file.open(argv[1]);
  if (!in_file)
  {
    cerr << "Error: File not able to be opened" << endl;
    return 1;
  }

  //parse the file and execute the instructions here!



  return 0;
}
