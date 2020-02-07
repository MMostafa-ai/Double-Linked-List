#include <iostream>

using namespace std;

struct node
{
    int item;
    node *next;
    node *prev;

};


class DoubleLinkedList
{
    node *first,*last;
    int length;
public:
    DoubleLinkedList()
    {
        last=NULL;
        first=NULL;
        length=0;
    }
    void InsertFromFirst(int ele)
    {
        node *ptr= new node;
        ptr->item=ele;
        if(length==0){
        ptr->next=ptr->prev=NULL;
        first=ptr;
        last=ptr;
        }else
        {
        ptr->next=first;
        first->prev=ptr;
        first=ptr;
        ptr->prev=NULL;
        }
        length++;

    }

    void InsertFromLast(int ele)
    {
        node *ptr=new node;
        ptr->item=ele;

        if(length==0)
        {
            ptr->next=ptr->prev=NULL;
            first=ptr;
            last=ptr;
        }else
        {
            ptr->next=NULL;
            ptr->prev=last;
            last->next=ptr;
            last=ptr;
        }
        length++;
    }

    void inserByPos(int pos,int ele)
    {
        if(pos>length||pos<0){return;}
        else if(pos==0){InsertFromFirst(ele);}
        else if(pos==length){InsertFromLast(ele);}
        else {
        node *ptr=new node;
        node *curr=first;
        ptr->item=ele;

        for(int i=0;i<pos;i++)
        {
            curr=curr->next;
        }
        ptr->next=curr;
        ptr->prev=curr->prev;
        (curr->prev)->next=ptr;
        curr->prev=ptr;

        }
    }
    void RemoveFirst()
    {
        if(length==0){return;}
        else if(length==1)
        {
            delete first;
            first=last=NULL;
            length--;
        }
        else
        {
            first=first->next;
            delete first->prev;
            first->prev=NULL;
            length--;
        }

    }
    void RemoveLast()
    {
        if(length==0){return;}
        else if(length==1)
        {
            delete last;
            first=last=NULL;
            length--;
        }
        else
        {
            last=last->prev;
            delete last->next;
            last->next=NULL;
            length--;
        }
    }
    void RemoveByEle(int ele)
    {
        if(length==0){return;}
        else if(first->item==ele){RemoveFirst();}
        else if(last->item==ele){RemoveLast();}
        else
        {
            node *curr=first;
            while(curr->next!=NULL)
            {
                curr=curr->next;
                if(curr->item==ele)
                {
                    (curr->prev)->next=curr->next;
                    (curr->next)->prev=curr->prev;
                    delete curr;
                    length--;
                    break;
                }
            }
        }
    }
    void RemoveByPos(int pos)
    {
        if(pos==0){RemoveFirst();}
        else if(pos==length){RemoveLast();}
        else if(pos>length||pos<0){return;}
        else
        {
            node *curr=first;
            for(int i=0;i<pos;i++)
            {
                curr=curr->next;
            }
            (curr->prev)->next=curr->next;
            (curr->next)->prev=curr->prev;
            delete curr;
            length--;

        }
    }

    int size(){return length;}

    void reverse()
    {
        if(length==0||length==1){return;}
        else
        {
            node *curr=first;
            node *pre=first;
            node *temp=last;

            for(int i=0;i<length;i++)
            {
                pre=curr;
                curr=curr->next;
                pre->prev=curr;
                curr->next=pre;
                if(pre==first){pre->next=NULL;}
                else if(curr==last){curr->prev=NULL;}
            }
            temp=last;
            last=first;
            first=temp;


        }
    }

    void print (){
        node *curr=first;
        while(curr!=NULL)
        {
            cout<<curr->item<<" ";
            curr=curr->next;
        }
     }

};

int main()
{
DoubleLinkedList d;
d.InsertFromLast(4);
d.InsertFromLast(3);
d.InsertFromFirst(1);
d.InsertFromFirst(0);
d.InsertFromFirst(448);
d.inserByPos(4,232);
d.RemoveByEle(0);
d.RemoveByPos(1);
d.reverse();
d.print();

}
