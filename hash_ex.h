#ifndef MYHASH2_H
#define MYHASH2_H
#define TABLE_SIZE2  10000
#include <vector>
#include <string>
#include <exception>
#include <iostream>
namespace yao{
    namespace hash{
        class Exception : public std::exception{
        protected:
            std::string _what;
        public:
            Exception(std::string _what) : _what(_what){}
            const char* what() const noexcept {return _what.c_str();}
            ~Exception() throw(){}
        };


        template <typename K, typename V>
        class  HashNode{
        public:
            HashNode(const K &key, const V &value) :
                key(key), value(value), next(nullptr) {
            }

            K getKey() const {
                return key;
            }

            V getValue() const {
                return value;
            }

            void setValue(V value) {
                HashNode::value = value;
            }

            HashNode *getNext() const {
                return next;
            }

            void setNext(HashNode *next) {
                HashNode::next = next;
            }

        private:
            // key-value pair
            K key;
            V value;
            // next bucket with the same key
            HashNode *next;

            template <typename T1, typename T2, typename HASH_FUN>
            friend class HashMap;
        };

        template <typename K, typename V, typename HASH_FUN>
        class HashMap {
        public:
            HashMap(HASH_FUN hashFunc)
                : hashFunc(hashFunc){
                m_data.resize(TABLE_SIZE2);
            }

            ~HashMap() {
                for(auto& vec: m_data){
                    for(auto & v: vec){
                        delete v;
                    }
                }
            }

            const V& get(const K& key){
                unsigned long hashValue = hashFunc(key);
                const auto& vec = m_data[hashValue];
                for(const auto& e: vec){
                    if(e->key == key){
                        return e->value;
                    }
                }
                throw Exception("Elem not found");
            }

            void put(const K& key, const V& v){
                std::cout << "key :" << key << std::endl;
                auto hashValue = hashFunc(key);
                auto& vec = m_data[hashValue];
                for(auto& e: vec){
                    if(e->key == key){
                        e->value = v;
                        return;
                    }
                }
                vec.push_back(new HashNode<K, V>(key, v));
            }

            void remove(const K& key){
                auto hashValue = hashFunc(key);
                auto& vec = m_data[hashValue];
                for(auto iter = vec.begin(); iter != vec.end(); ++iter){
                    if((*iter)->key == key){
                        delete (*iter);
                        vec.erase(iter);
                        return;
                    }
                }
                throw Exception("Elem not found");
            }
        private:
            // hash table
            std::vector<std::vector<HashNode<K, V>*>> m_data;
            HASH_FUN hashFunc;
        };

        void test();
        unsigned long hashFunc(int key);
    }
}
#endif // MYHASH2_H
