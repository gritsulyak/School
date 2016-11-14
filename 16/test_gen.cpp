#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
  int N;
  int a[2000000];
  cin >> N;

  cout << N << endl;
  for(int i=0;i<N;i++)
  {
     a[i]=rand()%N;
     cout << a[i] << " ";
  } 

  cout << endl;
  for(int i=0;i<N;i++)
  {
     cout << rand()%N << " " << rand()%N << endl;
  }

  cout << "-1" << endl;
  
  return 0;
}

