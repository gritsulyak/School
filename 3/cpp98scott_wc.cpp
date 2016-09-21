#include <cstdio> 
#include <iostream> 
#include <iterator> 
#include <string> 
#include <fstream> 
#include <algorithm> 
#include <vector> 
#include <map>
// easier than iostream for formatted output
// Scott Mayers example variant
typedef std::map<std::string, std::size_t> WordCountMapType;

WordCountMapType wordsInFile(const char * const fileName)
{
  std::ifstream file(fileName); 
  WordCountMapType wordCounts;

  for (std::string word; file >> word; ) {
	++wordCounts[word]; 
  }
  
  return wordCounts; 
}

struct Ptr2Pair2ndGT { template<typename It>
bool operator()(It it1, It it2) const { return it1->second > it2->second; }
// compare 2nd
// components of // pointed-to pairs
// print n most
// common words // in [begin, end)
} ;

template<typename MapIt>
void showCommonWords(MapIt begin, MapIt end, const std::size_t n)
{
  typedef std::vector<MapIt> TempContainerType;
  typedef typename TempContainerType::iterator IterType;
  TempContainerType wordIters; 
  wordIters.reserve(std::distance(begin, end));

  for (MapIt i = begin; i != end; ++i) 
    wordIters.push_back(i);
  
  IterType sortedRangeEnd = wordIters.begin() + n;

  std::partial_sort(wordIters.begin(), 
    sortedRangeEnd, wordIters.end(), Ptr2Pair2ndGT());

  for (IterType it = wordIters.begin(); it != sortedRangeEnd;
       ++it) {
    std::printf(" %-10s%10u\n",(*it)->first.c_str(),(*it)->second); 
  }
}

int main(int argc, const char** argv) 
// take list of file names on command line,
{
  WordCountMapType wordCounts;
// print 20 most common words within
  for (int argNum = 1; argNum < argc; ++argNum) {
    const WordCountMapType wordCountInfoForFile = // copy map returned by
    wordsInFile(argv[argNum]); // wordsInFile (modulo // compiler optimization)

    for ( WordCountMapType::const_iterator 
          i = wordCountInfoForFile.begin(); 
          i != wordCountInfoForFile.end();
          ++i) 
    {
      wordCounts[i->first] += i->second; 
    }
  }

  std::cout << wordCounts.size() << " words found. Most common:\n" ;
  
  const std::size_t maxWordsToShow = 20; 
  showCommonWords( wordCounts.begin(), wordCounts.end(),
                  std::min(wordCounts.size(), maxWordsToShow));
}
  
