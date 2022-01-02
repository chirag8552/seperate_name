#include<stdio.h>
#include <string.h>

void finddelim(char [],int *);

int main()
{
    char str[40] = {0};
    char temp_str[40] = {0};
    char opt[5] = {0};
    char delim[] = "<->";
    char fname[40] = {0};
    char lname[40] = {0};

do{
    int count = 0;

    memset(&temp_str,'\0',40);
    memset(&str,'\0',40);
    memset(&fname,'\0',40);
    memset(&lname,'\0',40);

    printf (" Enter name : ");
    scanf(" %[^\n]s", str);

    strcpy(temp_str,str);

    finddelim(temp_str,&count);

    strncpy(fname,str,count);
    strncpy(lname,str+count+3,40);

    printf("First Name : %s\n", fname);
    printf("Last Name  : %s\n", lname);

    printf("Check for next string?");
    scanf(" %s",&opt);
}while (strcmp(opt,"y")==0);

return 0;
}

void finddelim(char ptr[],int *cnt)
{
   int ct=0;
   int i =0;

   for(i=0;ptr[i];i++)
   {
        if((ptr[i] == '<') && (ptr[i+1] == '-')
              && (ptr[i+2] == '>'))
        {
             break;
        }
   ct++;
   }

   *cnt=ct;
}
