//Author: Joshua Liben
//Compile: g++ -Wall -o Parser.exe Parser.cc
//Run:  ./Parser testfile.txt


#include "Parser.h"
#define STREAMSIZE 200
using namespace std;

Memory memory;

int parseFile(ifstream& f, Memory& m) {
  char toBePushed[200];
  f.getline(toBePushed, 200);
  m.instructions.push_back((string)toBePushed);
  cout << m.instructions.front() << '\n';
  return 0;
}

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
  parseFile(in_file, memory);


  return 0;
}
