#include <iostream>
#include <cmath>
#include <ctime>
#include <map>
#include <string>

using namespace std;

int main(int argc,char **argv)
{
  cout << "map uint8, uint8 \n";
  {  
  int64_t c1,c2;
  c1=clock();
  map<uint8_t,uint8_t> mymap;
  for(int i=0;i<10000000;i++)
    {
       mymap[i%77]= i%77;
    }
  string s;
  c2=clock();
  cout << c2 << "-" << c1 << "=" << c2-c1; 
  cin >> s;
  }
  
  {
  cout << "map uint16_t, uint8_t \n";
   int64_t c1,c2;
  c1=clock();
   
  map<uint16_t,uint8_t> mymap;
  for(int64_t i=0;i<10000000;i++)
    {
       mymap[i%7777]= i%77;
    }
  string s;
  c2=clock();
  cout << c2 << "-" << c1 << "=" << c2-c1; 
  cin >> s;
  }
   
  {
  cout << "map uint16_t, uint8_t \n";
  int64_t c1,c2;
  c1=clock();
    
  map<uint16_t,uint8_t> mymap;
  for(int64_t i=0;i<10000000;i++)
    {
       mymap[i%7777]= i%77;
    }
  string s;
  c2=clock();
  cout << c2 << "-" << c1 << "=" << c2-c1; 
  cin >> s;
  }
  
  {
  cout << "map uint32_t, uint8_t \n";
  int64_t c1,c2;
  c1=clock();
     
  map<uint32_t,uint8_t> mymap;
  for(int64_t i=0;i<10000000;i++)
    {
       mymap[i]= i%77;
    }
  string s;
  c2=clock();
  cout << c2 << "-" << c1 << "=" << c2-c1; 
  cin >> s;
  }
   
  {
  cout << "\nmap uint32_t, uint64_t \n";
  int64_t c1,c2;
  c1=clock();
  
  map<uint32_t,uint64_t> mymap;
  for(int64_t i=0;i<10000000;i++)
    {
       mymap[i]= i%7777;
    }
  string s;
  c2=clock();
  cout << c2 << "-" << c1 << "=" << c2-c1; 
  cin >> s;
  }
 
    
  {
  cout << "map uint64_t, uint64_t \n";
  int64_t c1,c2;
  c1=clock();
  
  map<uint64_t,uint64_t> mymap;
  for(int64_t i=0;i<10000000;i++)
    {
       mymap[i]= i%777777;
    }
  string s;
  c2=clock();
  cout << c2 << "-" << c1 << "=" << c2-c1; 
  cin >> s;
  }
 
{
  cout << "map uint_fast32_t, uint_fast8_t \n";
  int64_t c1,c2;
  c1=clock();
     
  map<uint_fast32_t,uint_fast8_t> mymap;
  for(int64_t i=0;i<10000000;i++)
    {
       mymap[i]= i%77;
    }
  string s;
  c2=clock();
  cout << c2 << "-" << c1 << "=" << c2-c1; 
  cin >> s;
  }
   
  {
  cout << "\nmap uint_fast32_t, uint_fast64_t \n";
  int64_t c1,c2;
  c1=clock();
  
  map<uint_fast32_t,uint_fast64_t> mymap;
  for(int64_t i=0;i<10000000;i++)
    {
       mymap[i]= i%7777;
    }
  string s;
  c2=clock();
  cout << c2 << "-" << c1 << "=" << c2-c1; 
  cin >> s;
  }
 
    
  {
  cout << "map uint_fast64_t, uint_fast64_t \n";
  int64_t c1,c2;
  c1=clock();
  
  map<uint_fast64_t,uint_fast64_t> mymap;
  for(int64_t i=0;i<10000000;i++)
    {
       mymap[i]= i%777777;
    }
  string s;
  c2=clock();
  cout << c2 << "-" << c1 << "=" << c2-c1; 
  cin >> s;
  }
  
    
  {
  cout << "map str, uint_fast64_t \n";
  int64_t c1,c2;
  c1=clock();
  string a; 
  map<string,uint_fast64_t> mymap;
  for(int64_t i=0;i<10000000;i++)
    { 
       a=string("str")+to_string(i);
       mymap[a]= i%777777;
    }
  string s;
  c2=clock();
  cout << c2 << "-" << c1 << "=" << c2-c1; 
  cin >> s;
  }
  
 
  std::cout <<"  8:" << sizeof(uint8_t) << "\n";
    
  std::cout <<"  16:" << sizeof(uint16_t) << "\n";
 
  std::cout <<"  32:" << sizeof(uint32_t) << "\n";
 
  std::cout <<"  64:" << sizeof(uint64_t) << "\n";
  

  std::cout <<" fast 8:" << sizeof(uint_fast8_t) << "\n";
    
  std::cout <<" fast 16:" << sizeof(uint_fast16_t) << "\n";
 
  std::cout <<" fast 32:" << sizeof(uint_fast32_t) << "\n";
 
  std::cout <<" fast 64:" << sizeof(uint_fast64_t) << "\n";
  
  
}

