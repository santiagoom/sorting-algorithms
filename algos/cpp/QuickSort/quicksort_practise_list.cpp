#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void quicksort(ListNode *head, ListNode *end) {
        if (head != end) {
            ListNode *pivot = partion(head, end);
            quicksort(head, pivot);
            quicksort(pivot->next, end);
        }
    }

    ListNode *partion(ListNode *head, ListNode *end) {
        int val = head->val;
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != end) {
            if (fast->val < val) {
                slow = slow->next;
                swap(slow->val, fast->val);
            }
            fast = fast->next;
        }
        swap(slow->val, head->val);
        return slow;
    }

    void printLinklist(ListNode *listnode) {
        while (listnode != nullptr) {
            cout << listnode->val << " ";
            listnode = listnode->next;
        }
        cout << endl;
    }
};


int main() {
    auto *so = new Solution();
    ListNode *l1 = new ListNode(6);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    so->printLinklist(l1);
    so->quicksort(l1, l1->next->next->next->next->next);
    so->printLinklist(l1);
    return 0;
}
