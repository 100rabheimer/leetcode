class Solution {
public:

    Node* flattenDFS(Node* head) {
        if (head == nullptr) return nullptr;

        Node* curr = head;
        Node* tail = head;

        while (curr != nullptr) {

            if (curr->child != nullptr) {

                Node* nextNode = curr->next;
                Node* childHead = curr->child;

                // Recursively flatten child list and get its tail
                Node* childTail = flattenDFS(childHead);

                // Connect current node with child list
                curr->next = childHead;
                childHead->prev = curr;

                // Remove child pointer
                curr->child = nullptr;

                // Connect child tail with original next
                childTail->next = nextNode;

                if (nextNode != nullptr) {
                    nextNode->prev = childTail;
                }

                tail = childTail;
                curr = nextNode;
            }
            else {
                tail = curr;
                curr = curr->next;
            }
        }

        return tail;
    }

    Node* flatten(Node* head) {
        if (head == nullptr) return nullptr;

        flattenDFS(head);

        return head;
    }
};