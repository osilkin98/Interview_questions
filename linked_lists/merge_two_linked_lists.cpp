// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
struct moving_pointer {
    ListNode<int>* node_a;
    ListNode<int>* node_b;
    bool cont(void) {
       /* if(node_a != NULL && node_b != NULL) {
            return node_a  != NULL || node_b  != NULL;
        } else if(node_a == NULL && node_b != NULL) {
            return node_b -> next != NULL;
        } else if(node_a != NULL && node_b == NULL) {
            return node_a -> next != NULL;
        } */
        return node_a != NULL || node_b != NULL;
    }
    int next_lowest(void) {
        int k;
        if(node_a != NULL && node_b != NULL) {
            if(node_a -> value < node_b -> value) {
                k = node_a -> value;
                node_a = node_a -> next; 
            } else {
                k = node_b -> value;
                node_b = node_b -> next;
            }
        } else if(node_a == NULL && node_b != NULL) {
            k = node_b -> value;
            node_b = node_b -> next;
        } else {
            k = node_a -> value;
            node_a = node_a -> next;
        }
        return k;
    }
};


ListNode<int> * mergeTwoLinkedLists(ListNode<int> * l1, ListNode<int> * l2) {
    if(l1 == NULL && l2 == NULL) {
        return NULL;
    }
    ListNode<int>* new_head = new ListNode<int>;
    ListNode<int>* traverse = new_head;
    struct moving_pointer ptr;
    ptr.node_a = l1;
    ptr.node_b = l2;
    std::cerr << "makes it to the loop\n";
    // while we still have values to place
    while(ptr.cont()) {
        std::cerr << "settting the value...\n";
        traverse -> value = ptr.next_lowest();
        std::cerr << "done\n";
        if(ptr.cont()) {
            std::cerr << "updating the next node\n";
            traverse -> next = new ListNode<int>;
            traverse = traverse -> next;
            std::cerr << "updates done\n";
        }
    }
    return new_head;
    
}
