//Author: Joshua Liben
//Compile: g++ -Wall -o Parser.exe Parser.cc
//Run:  ./Parser testfile.txt


#include "Parser.h"
#define STREAMSIZE 200
#define TEST true //Toggle this value to view test print cases.
using namespace std;

Memory memory;

int parseFile(ifstream& f, Memory& m) {
  char toBePushed[200];
  while (!f.eof()) {
    f.getline(toBePushed, 200);
    m.instructions.push_back((string)toBePushed);
    if (TEST)
      cout << m.instructions.at(m.instructions.size()-1) << '\n';
  }
  if (TEST)
    cout << "File parsing completed succesfully." << endl;
  return 0;
}



vector<string> tokenizer(int lineNum, Memory& m) {
  istringstream iss(m.instructions.at(lineNum));
  vector<string> words;
  do {
    string sub;
    iss >> sub;
    words.push_back(sub);
  } while (iss);
  return words;
}

int set (int lineNum, Memory& m) {
  if (TEST)
    cout << "Begin set command:" << endl;
  vector<string> words = tokenizer(lineNum, m);
  return 0;
}

int print (int lineNum, Memory& m) {
  if (TEST)
    cout << "Begin print command:" << endl;
  return 0;
}

int execute (ifstream& f, Memory& m) {
  int cur;
  for (cur = 0; cur < (int)m.instructions.size(); cur++) {
    if (TEST)
      cout << "First char of line " << cur+1 << " is " << m.instructions.at(cur)[0] << endl;
    if (m.instructions.at(cur)[0] == '!') {
      if (TEST)
        cout << "This is a comment." << endl;
    } else if (m.instructions.at(cur)[0] == 'S'
      && m.instructions.at(cur)[1] == 'E'
      && m.instructions.at(cur)[2] == 'T'
      && m.instructions.at(cur)[3] == ' ') {
      if (TEST)
        cout << "This is a set instruction." << endl;
      set(cur, memory);
    } else if (m.instructions.at(cur)[0] == 'P'
      && m.instructions.at(cur)[1] == 'R'
      && m.instructions.at(cur)[2] == 'I'
      && m.instructions.at(cur)[3] == 'N'
      && m.instructions.at(cur)[4] == 'T'
      && m.instructions.at(cur)[5] == ' ') {
      if (TEST)
        cout << "This is a print instruction." << endl;
      print(cur, memory);
    } else {
      cout << "Invalid instruction found. Terminate." << endl;
      return 1;
    }
  }

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
  execute(in_file, memory);

  return 0;
}
