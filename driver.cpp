#include <bits/stdc++.h>
using namespace std;
 

class Node {
public:
    int data;
    Node* next;
};
 

Node* SortedMerge(Node* pos1, Node* pos2);

void FrontBackSplit(Node* begin, Node** frontRef, Node** backRef);
 

void MergeSort(Node** headRef)
{
    Node* head = *headRef;
    Node* pos1;
    Node* pos2;

    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
    FrontBackSplit(head, &pos1, &pos2);
    MergeSort(&pos1);
    MergeSort(&pos2);

    *headRef = SortedMerge(pos1, pos2);
}
 
Node* SortedMerge(Node* pos1, Node* pos2)
{
    Node* result = NULL;
 
    if (pos1 == NULL)
        return (pos2);
    else if (pos2 == NULL)
        return (pos1);
 
    if (pos1->data <= pos2->data) {
        result = pos1;
        result->next = SortedMerge(pos1->next, pos2);
    }
    else {
        result = pos2;
        result->next = SortedMerge(pos1, pos2->next);
    }
    return (result);
}

void FrontBackSplit(Node* begin, Node** frontRef, Node** backRef)
{
    Node* end1;
    Node* begin1;
    begin1 = begin;
    end1 = begin->next;
 
   
    while (end1 != NULL) {
        end1 = end1->next;
        if (end1 != NULL) {
            begin1 = begin1->next;
            end1 = end1->next;
        }
    }
 

    *frontRef = begin;
    *backRef = begin1->next;
    begin1->next = NULL;
}
 
void display(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
int main()
{

    Node* res = NULL;
    Node* pos1 = NULL;
 

    push(&pos1, 4);
    push(&pos1, 2);
    push(&pos1, 1);
    push(&pos1, 6);
    push(&pos1, 0);
    push(&pos1, 3);
    MergeSort(&pos1);
 
    cout << "Sorted Linked List is: \n";
    display(pos1);
    cout << " " << endl;
 
    return 0;
}