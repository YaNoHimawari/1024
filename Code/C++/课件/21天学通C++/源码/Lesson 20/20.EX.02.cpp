#include <set>
#include <iostream>
#include <string>
using namespace std;
struct PAIR_WORD_MEANING
{
    string strWord;
    string strMeaning;
    PAIR_WORD_MEANING (const string& sWord, const string& sMeaning)
        : strWord (sWord), strMeaning (sMeaning) {}
    bool operator< (const PAIR_WORD_MEANING& pairAnotherWord) const
    {
        return (strWord < pairAnotherWord.strWord);
    }
};

int main ()
{
    multiset <PAIR_WORD_MEANING> msetDictionary;
    PAIR_WORD_MEANING word1 ("C++", "A programming language");
    PAIR_WORD_MEANING word2 ("Programmer", "A geek!");
    msetDictionary.insert (word1);
    msetDictionary.insert (word2);
    return 0;
}