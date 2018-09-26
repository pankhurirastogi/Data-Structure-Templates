#include<iostream>
#include<malloc.h>
using namespace std;
struct ListNode{
int val;
ListNode * next;
};
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
/** The method is used to
        find the intersection of LinkedLists**/
        ListNode * ptr1 = (ListNode*)malloc(sizeof(ListNode));
        ListNode * ptr2 = (ListNode*)malloc(sizeof(ListNode));

        if(headA==NULL || headB==NULL)
            return NULL;
        ptr1 = headA;
        ptr2 = headB;
        int len1 = 0;
        int len2 = 0;

        while(ptr1!=NULL)
        {
            ptr1 = ptr1->next;
            len1++;
        }
        while (ptr2!=NULL)
        {
            ptr2=ptr2->next;
            len2++;
        }
        ptr1 = headA;
        ptr2 = headB;




        int diff = abs(len1-len2);
        if(len1>len2)
        {
            while(diff!=0)
            {
                ptr1 =ptr1->next;
                diff--;
            }
        }

        else if(len2>len1)
        {    while(diff!=0)
            {
                ptr2 =ptr2->next;
                diff--;
            }

        }



        while(!(ptr1==NULL || ptr2==NULL))
        {
            if(ptr1==ptr2)
            {
                break;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;

    }
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
