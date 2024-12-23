#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbersRecursive(ListNode* l1, ListNode* l2, int carry = 0) {
    if (!l1 && !l2 && carry == 0) return nullptr;

    int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
    ListNode* node = new ListNode(sum % 10);
    node->next = addTwoNumbersRecursive(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, sum / 10);
    return node;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    ListNode* result = addTwoNumbersRecursive(l1, l2);
    cout << "Sum: ";
    printList(result);

    return 0;
}
