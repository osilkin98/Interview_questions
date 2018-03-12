// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
// 
// 
// 
// 
/*)
template <typename t>
ListNode<t>* removeKFromList(ListNode<t>* head, t k) {
    if(head == NULL) {return head;}
    ListNode<t>* iter = head;
    //std::cerr << "reached the head-pop loop\n";
    while(head -> value == k) {
        head = iter -> next;
        delete iter;
        std::cerr << "deleted linked node\n";
        iter = head;
        //std::cerr << "assigned the iterator to the head\n";
        if(head == NULL) {
            return head;
        }
    } 
    //std::cerr << "reached the traversial loop\n";
    ListNode<t>* target = iter -> next;
    while(target != NULL) {
        if(target -> value == k) {
            iter -> next = target -> next;
            delete target;
            //target = iter -> next;
        }
        iter = target;
        target = target -> next;
    }
    //std::cerr << "Completed test\n";
    //++count;
    return head;
}*/


template <typename data_t>
void print_node(ListNode<data_t>* node) {
	std::cout << "LinkedNode [" << node << "]: {\nValue: " << node->value << "\nNext address: " << node->next << "\n}\n";
}

template <typename data_t>
void delete_node(ListNode<data_t>* prev_node, ListNode<data_t>* target) {
	if (target == NULL)
		return;

	prev_node->next = target->next;
	delete target;
}

template <typename data_t>
void delete_head(ListNode<data_t>* head) {
	ListNode<data_t>* trash = head;
	head = head->next;
	delete trash;
}
template <typename data_t>
ListNode<data_t>* removeKFromList(ListNode<data_t>* head, data_t k) {
	ListNode<data_t>* prev = NULL;
	ListNode<data_t>* target = head;
	while (target != NULL) {
		if (target->value == k) {
			if (prev == NULL) {
				// save pointer to next
				head = target->next;
				delete target;
				target = head;
				continue;
			}
			else {
				delete_node(prev, target);
				target = prev->next;
				continue;
			}
		}
		prev = target;
		target = target->next;
	}
	return head;
}

