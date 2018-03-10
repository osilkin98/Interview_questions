//
// Definition for binary tree:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
// 

// stack nodes
template <typename data_t>
struct stack_node {
    stack_node<data_t>* next;
    data_t value;
    // constructor without next pointer
    stack_node(const data_t& new_value) : 
        next(nullptr), value(new_value) { }
    // constructor with next pointer
    stack_node(const data_t& new_value, stack_node<data_t>* next_node) :
        next(next_node), value(new_value) { }
    // destructor not needed otherwise it'll break the stack.
    
};

// a stack so we can place things in order and then remove them 
template <typename data_t>
struct stack {
    stack_node<data_t>* top;
    size_t size;
    bool is_empty(void) { return !top; }
    
    void push(const data_t& value) {
        // sets new_nodes next to top, so it gets pushed back
        stack_node<data_t>* new_node = new stack_node<data_t>(value, top);
        top = new_node;
        ++size;
    }
    data_t pop(void) {
        data_t saved_value = top -> value;
        stack_node<data_t>* trash = top;
        top = top -> next;
        delete trash;
        --size;
        return saved_value;
    }
    void delete_stack(void) {
        while(!is_empty()) {
            pop();
        }
    }
};

// this method will create and return a stack of stack_node elements
// by traversing the stack in a pre-order routine, from left to right
// with the calling argument being the left node of the root node
template <typename data_t>
void inorder_stack_left(Tree<data_t>* tree_root, stack<data_t>* left_stack) {
    if(!tree_root) {
        return;
    }
    inorder_stack_left(tree_root -> left, left_stack);
    left_stack -> push(tree_root -> value);
    inorder_stack_left(tree_root -> right, left_stack);
}

template <typename data_t>
void inorder_stack_right(Tree<data_t>* tree_root, stack<data_t>* right_stack) {
    if(!tree_root) {
        return;
    }
    inorder_stack_right(tree_root -> right, right_stack);
    right_stack -> push(tree_root -> value);
    inorder_stack_right(tree_root -> left, right_stack);

}

bool isTreeSymmetric(Tree<int> * t) {
    if(!t) {
        return true;
    } else if(!(t -> left) && !(t -> right)) {
        return true;
    }
    stack<int>* left_stack;
    stack<int>* right_stack;
    left_stack = new stack<int>;
    right_stack = new stack<int>;
    inorder_stack_left(t -> left, left_stack);
    inorder_stack_right(t -> right, right_stack);
    if(left_stack -> size != right_stack -> size) {
        left_stack -> delete_stack();
        right_stack -> delete_stack();
        return false;
    } else {
        while(0 < left_stack -> size) {
            if(left_stack -> pop() != right_stack -> pop()) {
                return false;
            }
        }
        return true;
    }   
}
