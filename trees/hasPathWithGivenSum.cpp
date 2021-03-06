//
// Definition for binary tree:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
bool hasPathWithGivenSum(Tree<int> * t, int s) {
    // if we have reached the leaf and the two values cancel out
    // then we know that we have found a sum
    if(!t) {
        return !s;
    }
    if(!(t -> left) and !(t -> right)) {
        return s - (t -> value) == 0;
    }
    // otherwise we are at a fork, and should check if either the 
    // left or right nodes are available, and if so, we check
    // if paths exist respectively. 
    else { 
        // if the left node exists
        if(t -> left) {
            if(hasPathWithGivenSum(t -> left, s - (t -> value))) {    
                return true;
            }
        }  
        // if the right node exists
        if (t -> right) {
            return hasPathWithGivenSum(t -> right, s - (t -> value));
        }
    }
}
