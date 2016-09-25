#include <vector>
#include <iostream> 
#include <string>
#include <bitset>

using namespace std;

int32_t f(vector<string> &element){
  int32_t current=0;
  for(int i=0;i<element.size();i++)
    for(int j=0;j<element[i].size();j++)
      {
        current+=element[i][j]%77;  
        current%=77;     
      }
  return current;
}

int main(int argc,char** argv)
{
  int n;
  vector<string> words;  
  cin >> n;
  bitset<64> bits(0);

  for(int i=0;i<n;i++) {
     string word;
     cin >> word;
     words.push_back(word);
  }
  
  int last_max=-1;
  for(int j=0;bits.count()<n;j++)
  { 
    bitset<64> bitelem(j);
    bits=bitelem;
    vector<string> element;
    for(int k=0;k<n;k++){
      if(bitelem.test(k))
        element.push_back(words[k]); 
    }
    int cur_max = f(element);
    if(cur_max>last_max)
      last_max=cur_max;
  }

  std::cout << last_max << "\n";
 
}

