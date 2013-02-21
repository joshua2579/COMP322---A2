//Author: Joshua Liben

#ifndef PARSER_H_
#define PARSER_H_
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string.h>

//Object Definitions
struct Variable
{
  std::string name;
  double value;
};

struct Memory
{
  std::vector<std::string> instructions;
  int position;
  std::vector<Variable> variables;
};

//Function Headers
int main(int argc, char ** argv);

#endif /*PARSER_H_*/