#include<iostream>
using namespace std;
class Node{
public: 
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
class LinkedList{
public:
    Node* head;
    Node* tail;
    int size;
    LinkedList(){
        head = tail = NULL;
        size = 0;
    }
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    void insertAtEnd(int val){
        Node* temp = new Node(val);
        if(size == 0) head = tail = temp;
        else{
             tail->next = temp;
             tail = temp;
        }
        size++;
    }
    void insertAtHead(int val){
        Node* temp = new Node(val);
        if(size==0) head = tail = temp;
        else{
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void inserAt(int idx, int val){
        if(idx<0 || idx>size) cout<<"invalid index";
        else if(idx == 0) insertAtHead(val);
        else if(idx==size) insertAtEnd(val);
        else{
            Node* t = new Node(val);
            Node* temp = head;
            for(int i=1;i<=idx- 1;i++){
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }
    void addCycle(int idx){
        Node *temp = head;
        for(int i=0;i<idx;i++) temp = temp->next;
        tail->next = temp;
    }
    
    //1
    Node* deleteMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head;
        if(slow->next == NULL) return NULL;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(slow->next == NULL){
            head->next = NULL;
            return head;
        }
        slow->val = slow->next->val;
        slow->next = slow->next->next;
        return head;
    }

    //2
    Node* mergeInBetween(Node* list1, int a, int b, Node* list2) {
        Node* tempA = list1;
        Node* tempB = list1;
        for(int i=0;i<a-1;i++){
            tempA = tempA->next;
        }
        for(int i=0;i<=b;i++){
            tempB = tempB->next;
        }
        tempA->next = list2;
        while(list2->next != NULL){
            list2 = list2->next;
        }
        list2->next = tempB;
        return list1;
    }

    //3
    Node* swapNodes(Node* head, int k) {
        Node* startK = head;
        for(int i=1;i<k;i++){
            startK = startK->next;
        }
        Node* slow = head;
        Node* fast = head;
        for(int i=1;i<=k;i++){
            fast = fast->next;
        }
        while(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        int temp = slow->val;
        slow->val = startK->val;
        startK->val = temp;
        return head;
    }

    //4
    Node* removeElements(Node* head, int val) {
        if(head==NULL) return NULL;
        Node* temp = head;
        while(temp!=NULL && temp->val == val){
            temp = temp->next;
        }
        head = temp;
        while(temp != NULL){
            if(temp->next != NULL && temp->next->val == val){
                temp->next = temp->next->next;
            }
            else temp = temp->next;
        }
        return head;
    }

    //5
    int lenCycle(){
        Node* slow = head;
        Node* fast = head->next;
        int len = 0;
        while(fast != slow){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = slow->next;
        len++;
        while(slow != fast){
            len++;
            slow = slow->next;
        }
        return len;
    }
};
int main(){
    LinkedList ll;
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.insertAtEnd(4);
    ll.insertAtEnd(5);
    ll.insertAtEnd(6);
    ll.insertAtEnd(7);
    ll.insertAtEnd(8);
    ll.insertAtEnd(2);
    ll.addCycle(1);
    //1->2->3->4->5->6->7->8->2->cycle at 2 so length of cycle should be 8
    cout<<endl<<"Length of cycle is "<<ll.lenCycle();
}