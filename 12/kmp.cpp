include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prefix(string in)
{
  vector<int> ret(in.length(),0);
  for(int i=1;i<in.length();i++)
  {
     int k = ret[i-1];
     for(;k>0 && in[k]!=in[i];k=ret[k-1]);
     if(in[k] == in[i])
       k++;
     ret[i] = k;
  }
  return ret;
}

int kmp(string what, string where)
{
  int idx = -1;
  vector<int> f = prefix(what);
  int k = 0;

  for(int i=0;i<where.length();i++)
  {
    for(; 0 < k && (what[k] != where[i]); k = f[k-1])
      ;
    if(what[k] == where[i])
      k++;
    if(k==what.length())
    {
        idx = i - what.length() + 1;
        break;
    }
  }

  return idx;
}

int main(int argc, char **argv)
{
  string what; // needle
  string where; // haystack

  cin >> what >> where;

  auto idx = kmp(what, where);

  cout << idx;
  return 0;
}
