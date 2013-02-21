//Author: Joshua Liben

#ifndef PARSER_H_
#define PARSER_H_

//Object Definitions
struct Variable
{
  string name;
  double value;
};

struct Memory
{
  vector<string> instructions;
  int position;
  vector<Variable> variables;
};

//Function Headers


#endif /*PARSER_H_*/