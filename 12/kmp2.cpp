#include <iostream>
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

vector<int> kmp2(string what, string where)
{
  vector<int> result;
  vector<int> pref= prefix(what + "#" + where);
  for(int i=0;i<where.size();i++)
  {
    int idx = what.size()+i+1;
    if(pref[idx]==what.size())
      result.push_back(i-what.size()+1);
  } 
  return result;
}

int main(int argc, char **argv)
{
  string what; // needle
  string where; // haystack

  cin >> what >> where;

  auto idxs = kmp2(what, where);

  for(auto r:idxs)  cout << r << endl;
  return 0;
}
