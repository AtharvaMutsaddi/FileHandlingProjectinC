#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"find.h"
typedef struct ReqNode
{
    char req[MAX];
    int isPresent;
    struct ReqNode * next;
}ReqNode;

ReqNode * insertAlphabetically(ReqNode * head, const char * req){
    ReqNode * newNode= (ReqNode*)malloc(sizeof(ReqNode));
    newNode->isPresent=0;
    newNode->next=NULL;
    strcpy(newNode->req, req);
    if (head==NULL)
    {
        (head)=newNode;
        return head;
    }
    // insert at head
    if (req[0] < (head)->req[0])
    {
        // printf("I am inserting at head!\n");
        newNode->next= (head);
        (head)=newNode;
        return head;
    }
    ReqNode * temp=head;
    while (temp->next != NULL && temp->next->req[0]<=req[0])
    {
        temp=temp->next;
    }
    if (temp->next!=NULL)
    {
        newNode->next=temp->next;
    }
    temp->next=newNode;
    return head;
    
    
}
int lenofLL(ReqNode * head){
    int size=0;
    while (head != NULL)
    {
        size++;
        head=head->next;
    }
    return size;
}
void displayLL(ReqNode * head){
    while (head != NULL)
    {
        printf("%s\n", head->req);
        head=head->next;
    }
    
}
void setIsPresent(ReqNode * head, const char * filename){
    while (head != NULL)
    {
        if(containsword(filename, head->req)){
            head->isPresent=1;
        }
        head=head->next;
    }
    
}
void findScore(ReqNode * head, const char * filename, const char * candidateName, int minReqyears){
    setIsPresent(head, filename);
    float sum;
    int size= lenofLL(head);
    printf("SKILL TALLY\n");
    while (head != NULL)
    {
        printf("%s : %d \n", head->req, head->isPresent);
        if(head->isPresent){
            sum++;
        }
        head=head->next;
    }
    float score= sum/(float)size;
    int years= findexp(filename);
    printf("YEARS OF EXP %d\n", years);
    float finalscore= (0.8*score + 0.2*(years/minReqyears));
    printf("\n#####################################################\n  %s score : %f\n",candidateName, finalscore*100);
    printf("\n#####################################################\nCreating Record...");
    FILE * fptr= fopen("record.csv", "a");
    fprintf(fptr,"%s,%f\n", candidateName, finalscore*100);
    fclose(fptr);
    system("python3 data.py");
    
}
void construct(){
    ReqNode * head=NULL;
    
    char skill[MAX];
    int flag=1;
    int error=0;
    char name[MAX];
    int yearsofExp;
    char fileName[MAX];
    printf("\nEnter Name of Candidate: ");
    scanf("%s", name);
    printf("\nEnter Name of File: ");
    scanf("%s", fileName);
    printf("\nEnter min years of experience you want: ");
    scanf("%d", &yearsofExp);
    while (flag)
    {
        int x=0;
        printf("\nEnter (1) to enter skill requirement or (-1) to stop adding skills: ");
        scanf("%d", &x);
        if (x==1)
        {
            printf("Enter skill required: ");
            scanf("%s", skill);
            head=insertAlphabetically(head, skill);
        }
        else if (x==-1)
        {
            printf("\n#####################################################\nSkills You want in The candidate:\n");
            displayLL(head);
            printf("\n#####################################################\n");
            flag=0;
        }
        else{
            
            printf("\nEnter a valid option!\n");
            error=1;
            flag=0;
        }
        
    }
    if(!error){
        findScore(head, fileName, name, yearsofExp);
    }
}
