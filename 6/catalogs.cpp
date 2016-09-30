#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct book;

struct book{
  string book_name;
  string book_id;
  vector <string> references;
  // конструктор, принимает параметры и инициализирует члены
  // структуры параметрами 
  book(string name,string id, vector<string> ref):
  book_name(name),book_id(id),references(ref)
  {}
  // вспомогательный метод для вывода 
  string to_string() {
   auto ret = book_name + ";" + book_id + ";";
   for(auto val:references) ret+=val+";";
   return ret;
   }
};
  
int main(int argc, char ** argv)
{
  // создаем библиотеку
  vector <book> library;
  
  {
    vector<string> references;
    // создаем книгу, не каталог
    book book1("book1","ISDN-book1",references);
    library.push_back(book1);  
    references.push_back("ISDN-book1");
    references.push_back("ISDN-catalog"); 
    book catalog1("catalog1","ISDN-catalog",references);
    library.push_back(catalog1);
  }   
  
  for(auto a:library){
    cout << a.to_string(); 
  }

}

