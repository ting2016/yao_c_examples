#include "radixtree.h"
#include <algorithm>

yao::radix_tree::Trie::~Trie() {
    for (auto &it : m_children) {
        delete it.second;
    }
}

void yao::radix_tree::Trie::addWord(const std::string& word) {
    if (word.length()>0) {
        std::string subword = word.substr(1, word.size()-1);
        if (m_children[word[0]]) {
            m_children[word[0]]->addWord(subword);
            ++m_size;
        } else {
            Trie *tmp = new Trie(word.size()==1);
            tmp->addWord(subword);
            m_children[word[0]] = tmp;
        }
    }
}

bool yao::radix_tree::Trie::isPrefix(const std::string& pref) const {
    if (pref.length()== 0) {
        return true;
    }
    if (m_children.find(pref[0]) != m_children.end()) {
        return m_children.find(pref[0])->second->isPrefix(pref.substr(1, pref.size()-1));
    }
    return false;
}

size_t yao::radix_tree::Trie::size() {
    return m_size;
}

void yao::radix_tree::Trie::getWords(std::unordered_set<std::string> &words, std::string wordSoFar) const {
    if (m_isEnd) {
        words.insert(wordSoFar);
    }
    for (const auto &it : m_children) {
        std::string tmp = wordSoFar + std::string(1, it.first);
        if (it.second && it.second->m_isEnd) {
            words.insert(tmp);
        }
        it.second->getWords(words, tmp);
    }
}

void yao::radix_tree::Trie::getWordsStartingWith(const std::string &prefix, std::unordered_set<std::string> &words, std::string wordSoFar) const {
    if (prefix.size() == 0) {
        getWords(words, wordSoFar);
        return;
    }
    std::string subword = prefix.substr(1, prefix.size()-1);
    if (m_children.find(prefix[0]) != m_children.end()) {
        Trie *tmp = m_children.find(prefix[0])->second;
        std::string nwsf = wordSoFar + std::string(1, prefix[0]);
        tmp->getWordsStartingWith(subword, words, nwsf);
    }
}

void yao::radix_tree::test (){
    Trie theTrie;
    std::cout << "Building trie...\n";

    std::string inputWord;
    while(true){
        std::cout << "Input words(begin with letters, X for finish inputing):";
        std::cin >> inputWord;
        if(inputWord == "X"){
            break;
        }
        std::transform(inputWord.begin(), inputWord.end(), inputWord.begin(), ::tolower);
        if (inputWord.find_first_not_of("abcdefghijklmnopqrstuvwxyz") == std::string::npos) {
            theTrie.addWord(inputWord);
        }
    }

    std::unordered_set<std::string> wset;
    theTrie.getWords(wset);
    std::cout << "The word set has " << wset.size() << " words.\n";
    for(const auto& e: wset){
        std::cout << "\t" << e << std::endl;
    }

    std::string prefix;
    do{
        std::cout << "input prefix to search(X for finish):";
        std::cin >> prefix;
        if(prefix == "X"){
            break;
        }
        wset.clear();
        theTrie.getWordsStartingWith(prefix, wset);
        std::cout << "find " << wset.size() << " words starting with \"" << prefix << "\":\n";
        for (const auto &wrd : wset) {
            std::cout << "\t" << wrd << std::endl;
        }
    }while(true);
}
