#ifndef SIMPLETREE_H
#define SIMPLETREE_H
#include <iostream>
#include <vector>
namespace yao{
    namespace tree_ex{
        template< typename T >
        class Tree
        {
        public:
            Tree(){}
            void addNode(const T& t){
                this->t = t;
            }

            void walk_depth_first() const
            {
                std::cout << t;
                for (auto & n: children ) {
                    n.walk_depth_first();
                }
            }
        protected:
            T t;
            std::vector<Tree> children;
        };
    }
}
#endif // SIMPLETREE_H
