#include <cstdio>
#include <iostream> 
#include <iterator> 
#include <string>
#include <fstream> 
#include <algorithm> 
#include <vector>
#include <unordered_map> 
#include <future>
// variant of scott mayers example
using WordCountMapType = std::unordered_map<std::string, std::size_t>;

WordCountMapType wordsInFile(const char * const fileName)
{
  std::ifstream file(fileName); 
  WordCountMapType wordCounts;
  
  for (std::string word; file >> word; ) {
    ++wordCounts[word]; 
  }
  
  return wordCounts; 
}

template<typename MapIt>
void showCommonWords(MapIt begin, MapIt end, const std::size_t n)
// print n most
// common words // in [begin, end)
{
//#typedef std::vector<MapIt> TempContainerType;
//#typedef typename TempContainerType::iterator IterType;
std::vector<MapIt> wordIters; wordIters.reserve(std::distance(begin, end));
for (auto i = begin; i != end; ++i) wordIters.push_back(i);
auto sortedRangeEnd = wordIters.begin() + n; 
std::partial_sort(wordIters.begin(), sortedRangeEnd, wordIters.end(),
[](MapIt it1, MapIt it2){ return it1->second > it2->second; });
for (auto it = wordIters.cbegin(); it != sortedRangeEnd; ++it) {
std::printf(" %-10s%10zu\n",(*it)->first.c_str(),(*it)->second); }
}

//Counting Words Across Files: C++11
int main(int argc, const char** argv) 
// take list of file names on command line,
{
// print 20 most common words within;
// process files concurrently 
std::vector<std::future<WordCountMapType>> futures;

for (int argNum = 1; argNum < argc; ++argNum) {
futures.push_back(std::async([=]{ return wordsInFile(argv[argNum]); }));
}

WordCountMapType wordCounts;

for (auto& f : futures) {
const auto wordCountInfoForFile = f.get(); // move map returned by wordsInFile

for (const auto& wordInfo : wordCountInfoForFile) {
wordCounts[wordInfo.first] += wordInfo.second; }
}
std::cout << wordCounts.size() << " words found. Most common:\n" ;

constexpr std::size_t maxWordsToShow = 20; 

showCommonWords( wordCounts.begin(), wordCounts.end(),
	std::min(wordCounts.size(), maxWordsToShow));

}

