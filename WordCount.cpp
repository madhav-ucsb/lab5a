// WordCount.cpp

#include "WordCount.h"
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(const std::string & word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	// STUB.

  int count = 0;
  for(int i = 0; i<100;i++)
    {
      for(int j = 0; j<(int) table[i].size(); j++)
      {
        count = count + (int) table[i].at(j).second;
          
      }
    }
  return count;
  
}

int WordCount::getNumUniqueWords() const {
	// STUB
  int count = 0;

  for(int i = 0; i<100; i++)
    {
      count = count +(int) table[i].size();
    }
  

  return count;

  
}

int WordCount::getWordCount(const std::string & word) const {
	// STUB
	std::string s = makeValidWord(word);

  int h = (int) hash(s);

  int count = 0;
  bool inside = false;

  for(int i = 0; (i<(int) table[h].size()&&!inside); i++)
    {
      if(table[h].at(i).first==s)
      {
        count = table[h].at(i).second;
        inside = true;
      }
      
    }

  return count;
  
}
	
int WordCount::incrWordCount(const std::string & word) {
	// STUB
	std::string s = makeValidWord(word);


  if(s=="")
  {
    return 0;
  }
  int h = (int) hash(s);
  bool inside = false;

  for(int i = 0; (i<(int) table[h].size()&&!inside); i++)
    {
      if(table[h].at(i).first==s)
      {
        table[h].at(i).second = table[h].at(i).second + 1;
        
        return table[h].at(i).second;
      }
      
    }
  if(!inside)
  {
    std::pair <std::string, int> p(s, 1);
    table[h].push_back(p);

    return 1;
    
  }

  


  
	return -1;
}

int WordCount::decrWordCount(const std::string & word) {
	// STUB
	std::string s = makeValidWord(word);

  int h = (int) hash(s);
  bool inside = false;

  for(int i = 0; (i<(int) table[h].size()&&!inside); i++)
    {
      if(table[h].at(i).first==s)
      {
        table[h].at(i).second = table[h].at(i).second - 1;
        if(table[h].at(i).second==0)
        {
          table[h].erase(table[h].begin() + i);
          return 0;
        }
        
        return table[h].at(i).second;
      }
      
    }
  if(!inside)
  {

    return -1;
    
  }
}

bool WordCount::isWordChar(char c) {
	// STUB


	return isalpha(c);
}
std::string WordCount::makeValidWord(const std::string & word) {
	// STUB
  std::string s = "";

  std::string f = "-''";

  for(int i = 0; i<(int) word.size() ; i++)
    {
      char c = word.at(i);
      char hyphen = f.at(1);

      char apo = f.at(0);
      if((isWordChar(c))||(c==hyphen)||(c==apo))
      {
        s = s + (char) tolower(c);
      }
      
    }

  bool startsAlpha = false;

  int size = (int) s.size();
  if(size==0)
  {
    return "";
  }
  for(int i = 0; ((i< size) && (!startsAlpha)); i++)
  {
    if(isWordChar(s.at(i)))
    {
      startsAlpha = true;
    }
    else
    {
      s = s.substr(1);
      size = size - 1;
      i = i-1;
    }
  }
  bool endsAlpha = false;

  size = (int) s.size();

  if(size==0)
  {
    return "";
  }
  for(int i = size - 1; i>=0 && !endsAlpha; i--)
  {
    if(isWordChar(s.at(i)))
    {
      endsAlpha = true;
      return s;
    }
    else
    {
      if (s.size()==1)
      {
        return "";
      }
      s = s.substr(0 , i);
      size = size - 1;
    }
  }
  
}
