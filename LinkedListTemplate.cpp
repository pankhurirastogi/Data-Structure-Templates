#include<iostream>
#include<malloc.h>
using namespace std;
struct ListNode{
int val;
ListNode * next;
};
ListNode* insertNode(ListNode * start, int val)
{

    ListNode * neew = (ListNode*)malloc(sizeof(ListNode));
    neew->val = val;
    neew->next = NULL;
    ListNode * ptr;
  /**  if(start!=NULL)
    {
        cout<<"not null";
        return start;
    }**/

    if(start == NULL)
    {

        start = neew;
        return start;
    }
    ptr= start;
    while(ptr->next!=NULL)
    {

        ptr = ptr->next;
    }
    ptr->next=neew;
    return start;
}
void traverseLinkedList(ListNode * start)
{   ListNode * ptr ;
    ptr= start;
    while(ptr!=NULL)
    {
        cout<<ptr->val<<"\n";
        ptr = ptr->next;
    }


}
int main()
{   ListNode * start1 = NULL;
    ListNode * start2 = NULL;
     start1= insertNode(start1, 3);
     start1 = insertNode(start1,4);
     start1= insertNode(start1,5);
     start2= insertNode(start2, 2);
     start2 = insertNode(start2,1);
     start2= insertNode(start2,0);
     traverseLinkedList( start1);
     traverseLinkedList( start2);

    return 0;
}
