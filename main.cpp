#include <functional>
#include <utility>
#include "streamlogger.h"
#include "variadicparameters.h"
#include "templatetest1.h"
#include "templatetest2.h"
#include "functionpointer.h"
#include "definetest.h"
#include "version.h"
#include "singleton.h"
#include "graphic.h"
#include <iostream>
#include <string>
#include <hashtest.h>
#include <map>
#include "maptest.h"
#include "functortest.h"
#include "threadtest.h"
#include "algorithmtest.h"
#include "ctortest.h"
#include "chronotest.h"
#include <unistd.h>
#include "malicious.h"
#include "lambdatest.h"

#include <stltest.h>
#include "foo.h"
#include "bar.h"
#include "fileio.h"
#include <functional>
#include <functionaltest.h>
#include <functional>
#include <initializer_list_test.h>
#include "signaltest.h"
#include "timertest.h"
#include <typeindex>
#include <typeinfo>
#include <algorithm>
#include "randomtest.h"
#include "sort_test.h"

void somefun(int& v){
    v+= 10;
}

//int main(/*int argc, char** argv*/){
//    yao::thread_ex::testSimpleThreadWithPara ();
//    std::cout << "Finished" << std::endl;
//    return 0;
//}



struct S {
    int m = 1;
};        // C++11: S is non-aggregate // C++14: S is AGGREGATE





struct X {
    operator int(){
        std::cout << "--->int" << std::endl;
        return 3;
    }
    operator double(){
        std::cout << "---> double" << std::endl;
        return 3.14159;
    }

    operator S(){
        std::cout << "---> S" << std::endl;
        return S{3};
    }

    operator std::string(){
        return "ahahahah";
    }
};






//int main() {
//	int A[10]{18,12,9,4,1,77,2,4,3,25};
//	yao::heapsort(A, 10);
//	for(auto i = 0; i < 10; i++){
//		std::cout << A[i] << std::endl;
//	}

//    X a;
//    double x = a;
//    std::cout << x << std::endl;
//    std::cout << (int)a << std::endl;
//    std::cout << (std::string)a << std::endl;
//    //S b{a};  // C++11: valid, copy constr S(a.operator S()) is called here
//    // C++14: valid, aggregate initialization { a.operator int() }

//    //    printf("%d\n", b.m);
//}

#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>

#include <chrono>


namespace yao{
    class Tire {
    public:
        Tire(bool end = false) :m_size(0), m_isEnd(end) {}
        ~Tire() {
            for (auto &it : m_children) {
                delete it.second;
            }
        }

        void addWord(const std::string& word) {
            if (word.length()>0) {
                ++m_size;
                std::string subword = word.substr(1, word.size()-1);
                if (m_children[word[0]]) {
                    m_children[word[0]]->addWord(subword);
                } else {
                    Tire *tmp = new Tire(word.size()==1);
                    tmp->addWord(subword);
                    m_children[word[0]] = tmp;
                }
            }
        }

        bool isPrefix(const std::string& pref) const {
            if (pref.length()== 0) {
                return true;
            }
            if (m_children.find(pref[0]) != m_children.end()) {
                return m_children.find(pref[0])->second->isPrefix(pref.substr(1, pref.size()-1));
            }
            return false;
        }

        bool isWord(const std::string word) const {
            if (word.length() == 0) {
                return m_isEnd;
            }
            std::string cursub;
            Tire const *tmp = this;
            cursub = word;

            while (cursub.length() > 0) {
                if (tmp->m_children.find(cursub[0]) != tmp->m_children.end()) {
                    tmp = tmp->m_children.find(cursub[0])->second;
                    cursub = cursub.substr(1, cursub.size()-1);
                } else {
                    return false;
                }
            }
            return tmp->m_isEnd;
        }


        void getWords(std::set<std::string> &words, std::string wordSoFar="") const {
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

        void getWordsStartingWith(std::string prefix, std::set<std::string> &words, std::string wordSoFar="") const {
            if (prefix.size() == 0) {
                getWords(words, wordSoFar);
                return;
            }
            std::string subword = prefix.substr(1, prefix.size()-1);
            if (m_children.find(prefix[0]) != m_children.end()) {
                Tire *tmp = m_children.find(prefix[0])->second;
                std::string nwsf = wordSoFar + std::string(1, prefix[0]);
                tmp->getWordsStartingWith(subword, words, nwsf);
            }
        }

    private:
        std::map<char, Tire*> m_children;
        size_t m_size;
        bool m_isEnd;
    };
}


int main() {
    yao::Tire trie;
    std::string s;
    for(auto i = 0; i < 10; i++){
        std::cin >> s;
        trie.addWord (s);
    }

    std::set<std::string> wset;
    trie.getWords(wset);
    std::cout << "The word set has " << wset.size() << " words.\n";
    for(const auto& w: wset){
        std::cout << w << std::endl;
    }


    std::string prefix;
    while (std::cin >> prefix) {

        bool isp = trie.isPrefix(prefix);
        std::cout << "find that \"" << prefix << "\" " << (isp?"is":"is not") << " a prefix\n";
        wset.clear();
        if (isp) {
            trie.getWordsStartingWith(prefix, wset);
            std::cout << "find " << wset.size() << " words starting with \"" << prefix << "\":\n";

            for (const auto &wrd : wset) {
                std::cout << "\t" << wrd << " is a word" << std::endl;
            }
        }
    }
    return 0;
}
