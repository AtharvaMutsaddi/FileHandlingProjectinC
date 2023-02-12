#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 200
int containsword(const char* argv1, const char* argv2){
    FILE * fptr;
    char word[MAX];
    char ch;

    fptr=fopen(argv1, "r");
    while ((ch=getc(fptr) != EOF))
    {
        while (fscanf(fptr, "%s", word) !=EOF)
        {
            if (!strcmp(word, argv2))
            {
                return 1;
            }
            
        }
        
    }
    fclose(fptr);
    return 0;
}
int findexp(const char* argv1){
    FILE * fptr;
    char temp[MAX];
    char ch;
    int ans=0;
    fptr=fopen(argv1, "r");
    while (!feof(fptr))
    {
        fgets(temp, MAX, fptr);
        if(strstr(temp, "years")){
            // printf("%s", temp);
            sscanf(temp, "%*[^0123456789]%d", &ans);
        }
    }
    fclose(fptr);
    return ans;
}

