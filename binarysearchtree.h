#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>

namespace yao{
    namespace tree{
        template <class T>
        class Node{
        public:
            Node(const T& e, Node<T>* parent, Node<T>* left, Node<T>* right)
                : m_elem(e)
                , parent(parent)
                , left(left)
                , right(right){

            }

        private:
            T m_elem;
            Node* parent;
            Node* left;
            Node* right;

            template <class TT>
            friend class BinarySearchTree;
        };

        template <class T>
        class BinarySearchTree
        {
        public:
            BinarySearchTree()
                : root(nullptr){
            }

            ~BinarySearchTree(){
                clear(root);
            }

            void insert(const T& e){
                if(root){
                    std::cout << "root is not null" << std::endl;
                    insert (e, root);
                }else{
                    root = new Node<T>(e, nullptr, nullptr, nullptr);
                    std::cout << "root is set:" << root->m_elem << std::endl;
                }
            }

            void insert(const T& e, Node<T>* node){
                if(e < node->m_elem){
                    if(node->left){
                        insert(e, node->left);
                    }else{
                        node->left = new Node<T>(e, node, nullptr, nullptr);
                    }
                }else{
                    if(node->right){
                        insert(e, node->right);
                    }else{
                        node->right = new Node<T>(e, node, nullptr, nullptr);
                    }
                }
            }

            void remove(const T& e){

            }

            bool find(const T& e){
                return find(e, root);
            }

            void print() const{
                print(root);
            }

        private:
            bool find(const T& e, Node<T>* node) {
                if(node){
                    if(node->m_elem == e){
                        return true;
                    }

                    if(node->m_elem < e){
                        return find(e, node->right);
                    }

                    if(node->m_elem > e){
                        return find(e, node->left);
                    }
                }
                return false;
            }

            void print(const Node<T> * pNode) const{
                if(pNode){
                    std::cout << pNode->m_elem << std::endl;
                    print(pNode->left);
                    print(pNode->right);
                }
            }

            void clear(Node<T>* node){
                if(node){
                    if(node->left){
                        clear(node->left);
                    }

                    if(node->right){
                        clear(node->right);
                    }

                    delete node;
                }
            }

            Node<T>* root;
        };
    }
}

#endif // BINARYSEARCHTREE_H
