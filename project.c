#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *fptr;
FILE *fptr1;
int file2();
int sam(char name[]);
int password();
int file3();
int edit1(char fname1[]);
int file1()
{
	int n;
	printf("------------------------------------\n");
	printf("1.Open already created BUG \n2.To create an new BUG\n");
	printf("Enter choice:");scanf("%d",&n);
	printf("------------------------------------\n");	
	switch(n)
	{
		case 1:file2();
			break;
		case 2:file3();
			break;	
	}
}
int sam(char name[])
{
	fptr=fopen("document11.txt","a");
	fprintf(fptr,"%s",name);
	fprintf(fptr,"\n");
	fclose(fptr);
}
int file3()
{
	int name1;char name[200];
	printf("Enter file(PES1UG19CSXXX):");scanf("%d",&name1);	
	sprintf(name,"PES1UG19CS%d.txt",name1);
	fptr=fopen(name,"w");
	if (fptr==NULL)
	{	
		printf("Can't open %s \n",name);	
		system("pause");
		file3();
	}
	getchar();
	printf("\n\n DETAILS RELATED TO BUG\n");
	printf("------------------------\n");
	printf("ID                                 : PES1UG19CS%d\n",name1);
	fprintf(fptr,"ID                              : PES1UG19CS%d\n",name1);
	char bug[200];
	printf("Type of bug                        : ");
	fgets(bug,sizeof(bug),stdin);
	fprintf(fptr,"Type of Bug                     : %s",bug);
	char bug1[500];	
	printf("Brief Description                  : ");
	fgets(bug1,sizeof(bug1),stdin);
	fprintf(fptr,"Brief Description               : %s",bug1);
	char bug2[50];	
	printf("Priority of bug(LOW/HIGH)          : ");
	fgets(bug2,sizeof(bug2),stdin);
	fprintf(fptr,"Priority of Bug                 : %s",bug2);
	char time[100];
	printf("Time(hh:min) & Date(dd/mm/yyyy)    : ");
	fgets(time,sizeof(time),stdin); 
	fprintf(fptr,"Time(hh:min) & Date(dd/mm/yyyy) : %s",time);
	char bug3[200];
	printf("Status of Bug                      : ");
	fgets(bug3,sizeof(bug3),stdin);
	fprintf(fptr,"Status of Bug                   : %s",bug3);
	char bug4[100];
	printf("Name of the person(who filled bug) : ");
	fgets(bug4,sizeof(bug4),stdin);
	fprintf(fptr,"Person's name                   : %s",bug4);
	fclose(fptr);
	sam(name);
	printf("**-------**-------**-------**-------**\n");
	printf("________________________________________\n");
	printf("1. To create an new BUG.\n2. To open an old BUG.\n3. To Exit\n");
	int n;printf("Enter Choice:");scanf("%d",&n);
	printf("________________________________________\n");
	switch(n)
	{
		case 1: file3();
				break;
		case 2: file2();
				break;
		case 3: printf("************* THANK YOU ************\n");
				exit(1);
	}
}
int file2()
{
	int name2;char fname1[200];
	printf("Enter file(PES1UG19CSXXX):");scanf("%d",&name2);	
	sprintf(fname1,"PES1UG19CS%d.txt",name2);
	char c;
	fptr=fopen(fname1,"r");
	printf("\n\n DETAILS RELATED TO BUG\n");
	printf("------------------------\n");
	if (fptr==NULL)
	{
		printf("NO SUCH FILE EXIST !!!!!\n");
		exit(0);
	}
	c=fgetc(fptr);
	while(c!=EOF)
	{
		printf("%c",c);
		c=fgetc(fptr);
	}
	fclose(fptr);	
	printf("**-------**-------**-------**-------**\n");
	printf("________________________________________\n");
	printf("1. To change Status.\n2. To create an new BUG.\n3. To open an old BUG.\n4. To Exit\n");
	int n;printf("Enter Choice:");scanf("%d",&n);
	printf("________________________________________\n");	
	switch(n)
	{
		case 1: edit1(fname1);
				break;
		case 2: file3();
				break;
		case 3: file2();
				break;
		case 4: printf("************* THANK YOU ************\n");
				exit(1);
	}
}
int edit1(char fname1[])
{
     int lno=5, linectr = 0;
     char str[256],fname[256];        
     char newln[256], temp[] = "temp.txt";
	fptr = fopen(fname1, "r");
	if (!fptr) 
        {
                printf("Unable to open the input file!!\n");
                return 0;
        }
        fptr1= fopen(temp, "w");
        if (!fptr1) 
        {
                printf("Unable to open a temporary file to write!!\n");
                fclose(fptr);
                return 0;
        }
		getchar();
       printf("Type the current Status:");
        fgets(newln,sizeof(newln), stdin);
        lno++;
        while (!feof(fptr)) 
        {
            strcpy(str, "\0");
            fgets(str,sizeof(str), fptr);
            if (!feof(fptr)) 
            {
                linectr++;
                if (linectr != lno) 
                    {
                        fprintf(fptr1, "%s", str);
                    } 
                    else 
                    {
                        fprintf(fptr1, "Status of Bug                   : %s", newln);
                    }
                }
        }
        fclose(fptr);
        fclose(fptr1);
        remove(fname1);
        rename(temp, fname1);
	   printf("________________________________________\n");
        printf("1. To continue.\n2. To Exit.\n");
		int n2;	
	printf("Enter choice:");scanf("%d",&n2);
	switch(n2)
	{
		case 1: file1();
			break;
		case 2: printf("************* THANK YOU ************\n");
			exit(1);	
	}
  }

int password()
{	
	char pass[100];
	printf("Enter Password:");scanf("%s",pass);
	if (strcmp(pass,"bug_tracker")==0)
	{
		file1();
	}
	else
	{
		printf("WRONG PASSWORD\n");
		printf("TRY AGAIN !!!!\n");
		password();
	}
}
int main()
{
	printf("\n\n WELCOME TO  ''BUG TRACKER SOFTWARE''\n");
	printf("______________________________________\n");
	printf("\nPlease Wait......\n");
	char c;
	printf("-------------------------\n");
	fptr=fopen("document11.txt","r");
	if (fptr==NULL)
	{
		printf("NO SUCH BUG IS CREATED !!!!!\n");
		exit(0);
	}
	c=fgetc(fptr);
	while(c!=EOF)
	{
		printf("%c",c);
		c=fgetc(fptr);
	}
	fclose(fptr);	
	printf("-------------------------\n\n");
	password();
}
