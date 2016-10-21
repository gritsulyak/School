#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
int main(int argc, char **argv)
{
  char *a = "123\0\0G";

  char *b = (char *)malloc(30);

  for(int i=0;i<9;i++)
    std::cout << a+i << endl;

  strcpy(b,"ura!");
  std::cout << b << endl;

  strcpy(b,a);
  std::cout << b << endl;

//   strcpy(a,b);
  a[1] = '5';
  std::cout << a << endl;

  char * endi;
  char *figur = (char *)malloc(30);
  strcpy(figur,"12346.4554");
  double li = strtod(figur, &endi);
  std::cout << "errno:" << errno << "; li=" << li << endl;
  strcpy(figur,"d123xf46");
  li = strtod(figur, &endi);
  std::cout << "errno:" << errno << "; li=" << li << endl;

  return 0;
}
