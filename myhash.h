#ifndef MYHASH_H
#define MYHASH_H
#define TABLE_SIZE  10000
#include <vector>
template <typename K, typename V>
class HashNode {
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
};

template <typename K, typename V, typename HASH_FUN>
class HashMap {
public:
    HashMap() {
        // construct zero initialized hash table of size
        m_data = new HashNode<K, V> *[TABLE_SIZE]();
    }

    ~HashMap() {
        // destroy all buckets one by one
        for (auto i = 0; i < TABLE_SIZE; ++i) {
            HashNode<K, V> *entry = m_data[i];
            while (entry != nullptr) {
                HashNode<K, V> *prev = entry;
                entry = entry->getNext();
                delete prev;
            }
            m_data[i] = nullptr;
        }
        // destroy the hash table
        delete [] m_data;
    }

    bool get(const K &key, V &value) {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *entry = m_data[hashValue];

        while (entry != nullptr) {
            if (entry->getKey() == key) {
                value = entry->getValue();
                return true;
            }
            entry = entry->getNext();
        }
        return false;
    }

    void put(const K &key, const V &value) {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *prev = nullptr;
        HashNode<K, V> *entry = m_data[hashValue];

        while (entry != nullptr && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }

        if (entry == nullptr) {
            entry = new HashNode<K, V>(key, value);
            if (prev == nullptr) {
                // insert as first bucket
                m_data[hashValue] = entry;
            } else {
                prev->setNext(entry);
            }
        } else {
            // just update the value
            entry->setValue(value);
        }
    }

    void remove(const K &key) {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *prev = nullptr;
        HashNode<K, V> *entry = m_data[hashValue];

        while (entry != nullptr && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }

        if (entry == nullptr) {
            // key not found
            return;
        }
        else {
            if (prev == nullptr) {
                // remove first bucket of the list
                m_data[hashValue] = entry->getNext();
            } else {
                prev->setNext(entry->getNext());
            }
            delete entry;
        }
    }

private:
    // hash table
    HashNode<K, V> **m_data;

    HASH_FUN hashFunc;
};
#endif // MYHASH_H
