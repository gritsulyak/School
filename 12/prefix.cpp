#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prefix(string s)
{
  vector<int> ret(s.length(),0);
  for(int i=1;i<s.length();i++)
  {
     cout << endl << "i=" << i <<";ret=" ;
     for(auto a: ret) 
       cout << a << ",";
     
     int k = ret[i-1];
     cout << ";s[i]=" << s[i] << 
       "; k=" << k ;
     
     for(;k>0 && s[k]!=s[i];(k=ret[k-1], 
       (cout << ";k="<< k)));
     
     if(s[k] == s[i])
     {  
        k++;
        cout << ";s[k]==s[i] k=" << k;
     }
     ret[i] = k;
  }
  return ret;
}

int main(int argc, char **argv)
{
  string what; 

  cin >> what;
  auto pref = prefix(what);
  cout << endl;
  for(auto i:pref)
    cout << i;
  
  return 0;
}

