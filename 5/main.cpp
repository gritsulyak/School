#include <vector>
#include <iostream> 
#include <string>
#include <bitset>

using namespace std;
// пример функции которую макимизируем
int32_t f(vector<string> &element){
  int32_t current=0;
  for(int i=0;i<element.size();i++)
    for(int j=0;j<element[i].size();j++)
      {
        current+=element[i][j]%77;  
        current%=77;     
      }
  return current;
}

int main(int argc,char** argv)
{
  int n;
  vector<string> words;  
  cin >> n;
// создание битсет == {0,0,0,..0} == 0x000..00 = 0
  bitset<64> bits(0);   
// считаем входные слова
  for(int i=0;i<n;i++) {
     string word;
     cin >> word;
  // формируем основное множество слов
  // push_back добавляетв в вектор
     words.push_back(word);
  }
  // сюда складываем текущий максимум 
  int last_max=-1;
  // bits.count - количество 1ничек в bits; j=5 bits.count=2
  for(int j=0;j<(1<<(n));j++) 
  {
    // создание элемента типа bitset проинициализированого значение j
    // т.е
    // если j = 5 то битсет = 0x00000..0101 = 5 в десятичной
    // или как {0,0,...0,1,0,1}

    bitset<64> bitelem(j);
    vector<string> element;
    // формируем подмножество 
    for(int k=0;k<n;k++){
      if(bitelem.test(k)) // проверка установлен ли бит k
        element.push_back(words[k]); 
    }
    int cur_max = f(element);
    if(cur_max>last_max)
      last_max=cur_max;
  }

  std::cout << last_max << "\n";
  std::cout << (1<<n) << "\n"; 
}

