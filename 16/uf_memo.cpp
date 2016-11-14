#include <iostream>
#include <cmath>

using namespace std;

int id[1000000];
int sz[1000000];
int cur_ht = 0;
int32_t N;

void init(int N)
{
  for (int i=0;i<N;i++)
  {
    id[i] = i;
    sz[i] = 1;
  }
}

int root(int i)
{
  int h = 0;
  while (i != id[i])
  { 
    h++;
    i = id[i];
  }
  return i;
}

bool connected(int p, int q)
{
  return root(p) == root(q);
}

void unite(int p, int q)
{
  int j = root(q);
  int i = root(p);
  // weighted version 
  int selector = (sz[i] - sz[j]);
  selector = (selector<0)?-1:(selector>0);
  // switch demo
  switch(selector){
    case 0:
    sz[j]++;
    case -1: 
    id[i] = j;
    break;
    case 1:
    id[j]=i;
    break;
  }

}

int main(){;
  cin >> N;
  init(N);
  for(int i=0;i<N;i++)
  {
    int cur;
    cin >> cur;
    unite(cur,i);
  }
/*
  for(int i=0;i<N;i++)
  {
    cout << id[i];
  }
*/
  while(1)
  {
    int a1,a2;
    cin >> a1 >> a2;
    if(a1==-1)
      return 0;
    cout << connected(a1,a2) << endl;
  }

  return 0;
}

