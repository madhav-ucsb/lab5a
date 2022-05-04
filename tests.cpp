// WordCount.cpp

#include "WordCount.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;
int main()
{
  std::vector<std::pair<std::string, int>> table[100];
  std::string s = "be";

  const int d = 7;

  string type = typeid(table[0].at(0)).name();
  std::pair <std::string, int> p("John", 25);
  cout<<p.second<<endl;

  table[0].push_back(p);


  WordCount f = WordCount();

  f.incrWordCount("be");

  f.incrWordCount("be");

  int total = f.getTotalWords();

  int unique = f.getNumUniqueWords();

  cout<<"total:" << total<<endl;

  cout<<"unique:"<<unique<<endl;


  f.decrWordCount("BE-");
  f.decrWordCount("BE-");

  cout<<"total:" << f.getNumUniqueWords()<<endl;

  cout<<"unique"<<f.getTotalWords() <<endl;

  int jfi= f.decrWordCount("BE");

  cout<<jfi<<endl;


  f.incrWordCount("---------BE--------");

  cout<<f.getWordCount("be")<<endl;


  f.incrWordCount("eb");


  cout<<f.getWordCount("eb")<<endl;

  cout<<f.getNumUniqueWords()<<endl;

  jfi = f.decrWordCount("eb");


  cout<<jfi<<endl;





  
  
  return 0;
}
