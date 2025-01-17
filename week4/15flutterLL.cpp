#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
    Node* child;

    //constructor for insertion
    Node(int data){
        this-> data = data;
        this-> next = NULL;
    }
};


Node *merge(Node *left, Node *right) {
  if (left == NULL)
    return right;
  if (right == NULL)
    return left;
  Node *ans = new Node(-1);
  Node *temp = ans;
  while (left != NULL && right != NULL) {
    if (left->data < right->data) {
      temp->child = left;
      temp = left;
      left = left->child;
    } else {
      temp->child = right;
      temp = right;
      right = right->child;
    }
  }
  while (left != NULL) {
    temp->child = left;
    temp = left;
    left = left->next;
  }
  while (right != NULL) {
    temp->child = right;
    temp = right;
    right = right->next;
  }
  ans = ans->child;
  return ans;
}
Node *flattenLinkedList(Node *head) {
  // Write your code here
  if (head == NULL || head->next == NULL)
    return head;
  
  Node *curr = head;
  
  Node *next = curr->next;
  curr->next = NULL;
  while (curr->child != NULL) {
    curr = curr->child;
  }
  Node* restpart= flattenLinkedList(next);
  Node* result=merge(head,restpart);

  return result;
}