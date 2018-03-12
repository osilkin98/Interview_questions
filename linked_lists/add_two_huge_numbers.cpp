// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };



struct number_queue {
    // add to tail
    // remove from head
    ListNode<int>* head = NULL; 
    ListNode<int>* tail = NULL;
    void add(int num) {
        //std::cerr << "adding " << num << " internally\n";
        ListNode<int>* new_node = new ListNode<int>(num);
        //std::cerr << "testing nullity of tail\n";
        if(tail != NULL) {
           // std::cerr << "it breaks here\n";
            tail -> next = new_node;
        }
        //std::cerr << "done.\n";
        tail = new_node;
        if(head == NULL) {
            //std::cerr << "program breaks here\n";
            head = tail;
            //std::cerr << "yep it broke\n";
        }
    }
    int remove(void) {
        int data = head -> value;
        ListNode<int>* temp_ptr = head -> next;
        delete head;
        head = temp_ptr;
        if(head == NULL) {
            tail = NULL;
        }
        return data;
    }
    bool is_empty(void) {
        return head == NULL;
    }
    
    void reverse(void) {
        ListNode<int>* prev = NULL;
        ListNode<int>* curr = head;
        ListNode<int>* place = curr;
        ListNode<int>* next = NULL;
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        //std::cout << "the tail is: " << place -> value << "\n";
        tail = place;
        head = prev;
        print();
    }
    
    void fix() {
        reverse();
        ListNode<int>* t = head;
        while(t != NULL) {
            if(t -> value >= 10000) {
                t -> value %= 10000;
                if(t -> next != NULL) {
                //t -> value %= 10000;
                    ++(t -> next) -> value;
                } else {
                    t -> next = new ListNode<int>(1);
                    tail = t -> next;
                }
            }
            t = t -> next;
        }
        reverse();
    }
    
    void print(void) {
        ListNode<int>* t = head;
        while(t != NULL) {
          //  std::cout << "[" << t -> value << "] ->";
            t = t -> next;
        }
        //std::cout << "0\n";
    }
};

ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b) {
    ListNode<int>* trav_1 = a;
    ListNode<int>* trav_2 = b;
    //std::cerr << "works";
    size_t length_a = 0, length_b = 0;
    while(trav_1 != NULL) {
        ++length_a;
        trav_1 = trav_1 -> next;
        
    } while(trav_2 != NULL) {
        ++length_b;
        trav_2 = trav_2 -> next;
    }
    struct number_queue new_dollar;
    size_t count = length_a >= length_b ? length_a : length_b;
    int part_sum = 0;
    trav_1 = a;
    trav_2 = b;
    //std::cerr << "startup works\n";
    //std::cerr << "length_a: " << length_a << "\nlength_b: " << length_b << "\n";
    while(count != 0) {
        //part_sum = 0;
        if(count <= length_a) {
            part_sum += trav_1 -> value;
            trav_1 = trav_1 -> next;
        }
        if(count <= length_b) {
            part_sum += trav_2 -> value;
            trav_2 = trav_2 -> next;
        }
      //  std::cerr << "adding " << part_sum << " to new_dollar\n";
        new_dollar.add(part_sum);
        part_sum = 0;
        --count;
        //std::cerr << "reset part_sum & count\n";
    }
    //std::cerr << "it's making it to the print function\n";
    new_dollar.print();
    new_dollar.fix();
    ListNode<int>* new_head = NULL;
    if(!new_dollar.is_empty()) {
        ListNode<int>* traverse = new ListNode<int>(new_dollar.remove());
        new_head = traverse;
        while(!new_dollar.is_empty()) { 
            int i = new_dollar.remove();
            traverse -> next = new ListNode<int>(i);
            traverse = traverse -> next;
        }
    }
    return new_head;
}
/*
struct number_stack {
    ListNode<int>* head;
    void push(int num) {
        ListNode<int>* new_node = ListNode<int>(num);
        new_node -> next = head;
        head = new_node;
    }
    bool is_empty(void) {
        return head == NULL;
    }
    int pop(void) {
        ListNode<int>* temp = head -> next;
        int k = head -> value;
        delete head;
        head = temp;
        return k;
    }
    void correct() {
        ListNode<int>* trav = head;
        while(trav != NULL) {
            if(trav -> value >= 10000) {
                trav -> value %= 10000;
                if(trav -> next != NULL) {
                    ++((trav -> next) -> value);
                } else {
                    ListNode<int>* new_node = ListNode<int>(1);
                }
            }
            trav = trav -> next;
        }
    }
};
*/
/*
ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b) {
    ListNode<int>* trav_1 = a;
    ListNode<int>* trav_2 = b;
    size_t length_a = 0, length_b = 0;
    while(trav_1 != NULL) {
        ++length_a;
        trav_1 = trav_1 -> next;
        
    } while(trav_2 != NULL) {
        ++length_b;
        trav_2 = trav_2 -> next;
    }
    struct number_stack new_dollar;
    size_t count = length_a >= length_b ? length_a : length_b;
    int part_sum;
    trav_1 = a;
    trav_2 = b;
    while(count != 0) {
        part_sum = 0;
        if(count <= length_a) {
            part_sum += trav_1 -> value;
            trav_1 = trav_1 -> next;
        }
        if(count <= length_b) {
            part_sum += trav_2 -> value;
            trav_2 = trav_2 -> next;
        }
        new_dollar.push(part_sum);
        --count;
    }
    ListNode<int>* new_head = NULL;
    
    ListNode<int>* trav = new_head;
    
}
*/
