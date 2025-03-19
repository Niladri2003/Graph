#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
#include<time.h>

struct ListNode{
    int vertex;
    struct ListNode *next;
}
struct edge{
    int source;
    int destination;
}

struct graph{
    int v;
    int e;
    struct ListNode *adjList[];
}

void rand_init(void){
    // initialize the random generator rand();
    time_t t;
    srand((unsigned) time(&t));

}

int insertEdge(struct graph* G, const struct edge E){
    int n,from,to;
    n=G->v;
    from=E.source;
    to=E.destination;
    if(0>from||from>n||0>to||to>n) return -1;
    struct ListNode *prev=NULL,*ptr=G->adjList[from];
    while(ptr!=NULL){
        if(ptr->vertex){
            return 0;
        }else{
            prev=ptr;
            ptr=ptr->next;
        }
    }
    if(ptr==NULL){
        struct ListNode *newNode=(struct ListNode *) malloc(sizeof(struct ListNode));
        newNode->vertex=to;
        newNode->next=NULL;
        if(prev==NULL){
            G->adjList[from]=newNode;
        }else{
            prev->next=newNode;

        }
    }
    return -1;
}

int removeEdge(struct graph* G,const struct edge E){
    int n,from,to;
    n=G->v;
    from=E.source;
    to=E.destination;
    if(0>from||from>n||0>to||to>n) return -1;
    struct ListNode *prev=NULL, *ptr=G->adjList[from];
    while(ptr!=NULL){
        if(ptr->vertex==to){
            if(prev==NULL){
                G->adjList[from]=ptr->next;
                free(ptr);
            }else{
                prev->next=ptr->next;
                free(ptr);
            }
            return 1;
        }else{
            prev=ptr;
            ptr=ptr->next;
        }
    }
    return 0;
}

struct graph* createGraph(const int numVertices){
    assert(numVertices >=0);
}