#include <iostream>

using namespace std;

int id[1000000];
int32_t N;

void init(int N)
{
  for (int i = 0; i < N; i++)
    id[i] = i;
}

int root(int i)
{
  while (i != id[i])
    i = id[i];
  return i;
}

bool connected(int p, int q)
{
  return root(p) == root(q);
}

void unite(int p, int q)
{
  int i = root(p);
  int j = root(q);
  id[i] = j;
}

int main(){
  cin >> N;
  init(N);
  for(int i=0;i<N;i++)
  {
    int cur;
    cin >> cur;
    unite(cur,i);
  }

  for(int i=0;i<N;i++)
  {
    cout << id[i];
  }

  while(1)
  {
    int a1,a2;
    cin >> a1 >> a2;
    if(a1==-1)
      return 0;
    cout << connected(a1,a2);
  }

  return 0;
}

