#include<stdio.h>
#include<stdlib.h>
/*
    Author: Omar Yassin
    Version:1.0.50
*/
struct node {
    int jobNum;
    int exTime;
    struct node *next;
};

struct list {
    struct node *start;
};


void InitList(struct list *sList)
{
    sList->start = NULL;
}

void push(struct list *sList, int jobNum, int exTime)
{
    struct node *p;
    p = malloc(sizeof(struct node));//allocating place in memory for the node
    p->jobNum = jobNum;//setting the jobNumber for the node
    p->exTime = exTime;//setting the Execution time for the node
    p->next = sList->start;
    sList->start = p;
}

void deleteNode(struct list *sList, struct node *n){
    struct node *head = sList->start;
    // When node to be deleted is head node
    if(head == n){
        if(head->next == NULL) {
            head=NULL;
            return;
        }

        // Copy the data of next node to head
        head->jobNum = head->next->jobNum;
        head->exTime = head->next->exTime;

        // store address of next node
        n = head->next;

        // Remove the link of next node
        head->next = head->next->next;

        // free memory
        free(n);

        return;
    }


    // When not first node, follow the normal deletion process

    // find the previous node
    struct node *prev = head;
    while(prev->next != NULL && prev->next != n)
        prev = prev->next;

    // Check if node really exists in Linked List
    if(prev->next == NULL){
        printf("\n Given node is not present in Linked List");
        return;
    }

    // Remove node from Linked List
    prev->next = prev->next->next;

    // Free memory
    free(n);

    return;
}

void printLast(struct list *sList)
{
    struct node *p = sList->start;
    while(p != NULL) {//printing the last node
        printf("JobNum: %d \n", p->jobNum);
        p = p->next;
    }
}
void TimeSlice(struct list *sList,int timeSlice,int jobs)
{
    struct node *head = sList->start;
    struct node *p = sList->start;
    int last_node=jobs-1;
    int first=0;
    int count=0;
    int done=1;
    while(done) {
        if (p->exTime>=timeSlice) {//checking if the exTime is bigger than the timeSlice
            p->exTime-=timeSlice;
        }else{//else set the extime to 0
            p->exTime=0;
        }
        if (p->exTime<=0 && first==0) {
            printf("this is the first job to with ID of %d \n",p->jobNum,p->exTime);
            deleteNode(sList, p);// delete the first node that reatched 0
            first=1;
            count++;
            p = p->next;//go to the next node

        }
        else if (p->exTime<=0) {
            printf("JobNum: %d \n",p->jobNum,p->exTime);
            deleteNode(sList, p);//delete the node that reatched 0
            count++;
            if (count==last_node) {// check if the next node is the last node
                printLast(sList);
            }
        }
        if (head->next == NULL) {//checking if node after the head is null
            p=head;
            break;
        }
        if (p->next == NULL) {// checking if the next node is null
            p=head;
        }
        p = p->next;
    }
}


int main(int argc, char** argv)
{
    int x;
    int jobs;
    int exTime;
    int timeSlice;
    struct list MyList;
    InitList(&MyList);
    printf("Enter the time slice: \n" );
    scanf("%d",&timeSlice );
    printf("Enter the number of jobs: \n" );
    scanf("%d",&jobs );
    for(x = 0; x < jobs; x++){//adding excution time and job number to the list
        printf("Enter Execution time for job num %d \n",x);
        scanf("%d", &exTime);
        push(&MyList, x, exTime);
    }
    TimeSlice(&MyList,timeSlice,jobs);

    return 0;
}
