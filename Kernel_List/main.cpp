#include <iostream>
# define contain(head, l, p,ptr) do \
{\
p* ptr=(p*)((char *)tmp-(char *)((char *)(&((p *)0)->node)));\
printf("%d------%d\n",ptr->id,ptr->age);\
tmp=tmp->next;\
} while (tmp!=0)

typedef  struct list{
    struct list* next;
}l;
typedef  struct person{
    struct list node;
    int id;
    int age;
}p;

int main() {
    p* p1=(p *)malloc(sizeof(p));
    p1->node=*(l *)malloc(sizeof(l));
    p1->age=1;
    p1->id=1;
    p* p2=(p *)malloc(sizeof(p));
    p2->node=*(l *)malloc(sizeof(l));
    p2->id=2;
    p2->age=2;
    p1->node.next=&p2->node;
    l* head;
    head=&p1->node;
    p2->node.next=0;
    l* tmp=head;
//    l* tmp=head;
//    while (tmp!=0){
//        p* ptr=(p*)((char *)tmp-(char *)((char *)(&((p *)0)->node)));
//        printf("%d------%d\n",ptr->id,ptr->age);
//        tmp=tmp->next;
//    }
    contain(head, l, p,ptr);
    return 0;
}
