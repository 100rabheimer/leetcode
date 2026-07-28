
class MyLinkedList {

    struct Node{
        int data;
        Node* next;

        Node(int val)
        {
            data = val;
            next = NULL;
        }
    };

    Node* head;

public:

    MyLinkedList() {
        head = NULL;
    }


    int get(int index) {

        Node* temp = head;

        int count = 0;

        while(temp != NULL)
        {
            if(count == index)
                return temp->data;

            count++;
            temp=temp->next;
        }

        return -1;
    }


    void addAtHead(int val) {

        Node* newNode = new Node(val);

        newNode->next = head;

        head = newNode;
    }


    void addAtTail(int val) {

        Node* newNode = new Node(val);

        if(head==NULL)
        {
            head=newNode;
            return;
        }

        Node* temp=head;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        temp->next=newNode;
    }


    void addAtIndex(int index, int val) {

        if(index==0)
        {
            addAtHead(val);
            return;
        }


        Node* temp=head;

        int count=0;


        while(temp!=NULL && count<index-1)
        {
            temp=temp->next;
            count++;
        }


        if(temp==NULL)
            return;


        Node* newNode=new Node(val);

        newNode->next=temp->next;

        temp->next=newNode;
    }


    void deleteAtIndex(int index) {

        if(head==NULL)
            return;


        if(index==0)
        {
            Node* temp=head;

            head=head->next;

            delete temp;

            return;
        }


        Node* temp=head;

        int count=0;


        while(temp!=NULL && count<index-1)
        {
            temp=temp->next;
            count++;
        }


        if(temp==NULL || temp->next==NULL)
            return;


        Node* del=temp->next;

        temp->next=temp->next->next;

        delete del;
    }
};
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */