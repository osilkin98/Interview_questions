// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
struct stack {
    ListNode<int>* top;
    void push(int k) {
        ListNode<int>* new_node = new ListNode<int>(k);
        new_node -> next = top;
        top = new_node;
    }
    int pop() {
        ListNode<int>* temp = top -> next;
        int k = top -> value;
        delete top;
        top = temp;
        return k;
    }
    
};

bool isListPalindrome(ListNode<int> * l) {
    //struct stack data_stack;
    size_t length = 0;
    ListNode<int>* trav = l;
    while(trav != NULL) {
        trav = trav -> next;
        ++length;
    }
    if(length <= 1) {
        return true;
    }
    struct stack data_stack;
    trav = l;
    for(size_t i = 0; i < length/2; ++i) {
        data_stack.push(trav -> value);
        trav = trav -> next;
    }
    if(length % 2 != 0) {
        trav = trav -> next;
    }
    while(trav != NULL) {
        if(trav -> value != data_stack.pop()) {
            return false;
        } 
        trav = trav -> next;
    }
    return true;
}
