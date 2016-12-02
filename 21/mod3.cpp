#include <iostream>
#include <string>

using namespace std;
// mod 3 automata emulation 
// example - no additional vars used;
// just eat string;
int main(int argc, char **argv)
{
  string number;
  cin >> number;
 
  int current_mod = 0;
  for(int i=number.size()-1;i>=0;i--)
  {
    if(current_mod==0) // state 0
    {
      if(number[i]=='0')
         current_mod=0;
      else 
         current_mod=1;   
      continue;
    } 
    
    if(current_mod==1)
    {
      if(number[i]=='0')
        current_mod = 2; // *2 
      else
        current_mod = 0; // *2+1
      continue;  
    }

    if(current_mod==2)
    {
      if(number[i]=='0')
        current_mod = 1; // 2*2 mod 3 == 1
      else
        current_mod = 2; // 2*2+1 mod 3 = 2
      continue;
    }
  } 
  
  cout << current_mod << endl;

  return 0;
}

