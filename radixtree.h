#ifndef RADIXTREE_H
#define RADIXTREE_H

#include <unordered_set>
#include <unordered_map>
#include <iostream>
namespace yao{
    namespace radix_tree{
        class Trie {
        public:
            Trie(bool end = false) :m_size(0), m_isEnd(end) {}
            ~Trie();
            void addWord(const std::string& word);
            bool isPrefix(const std::string& pref) const;
            size_t size();
            void getWords(std::unordered_set<std::string> &words, std::string wordSoFar="") const ;
            void getWordsStartingWith(const std::string &prefix, std::unordered_set<std::string> &words, std::string wordSoFar="") const;
        private:
            std::unordered_map<char, Trie*> m_children;
            size_t m_size;
            bool m_isEnd;
        };

        void test();
    }
}


#endif // RADIXTREE_H
