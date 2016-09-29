#include <iostream>
#include <limits>
#include <iomanip>
#include <bitset>
/*(c) Roman T Gritsulyak 2016 
 Dolgoprudny FIMLI 5 school lesson example */

using namespace std;

int main()
{
    std::bitset<32> bin(0);
    for(uint32_t i=0;i<numeric_limits<uint32_t>::max();i++)
    {
        bitset<32> out;
        out = i ^ (i >> 1); // i xor (i shr 1) - pascal
        bin=i;    
        cout << "gray(" << i << "="<< bin << ")=" << out << endl;
    }
    
  return 0;
}


