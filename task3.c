#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void mygrep(FILE*, char*);
void myreplace(FILE *fp,char *find, char * replace);

int  main(int argc,char *argv[])
{
	int behaviour;
	int GREP;
	int REPLACE;
	FILE *fp;
	char *filename=argv[1];
	char *find=argv[2];
	char * replace;
	//bool temp;
	

	if((mygrep(fp,find) == argc[0]))
	{
		if(argc != 3)
		{
			printf("usage\t./mygrep filename <string-to-search>\n");
			exit(1);
		}

		behaviour = GREP;
	}
	else if(myreplace(fp,find,replace)==argc[0])
	{
		if(argc != 4)
		{
			printf("\t./myreplace filename  <string-to-search> <string-to-replace>");
			exit(1);
		}
		behaviour = REPLACE;
		replace = argv[3];
	}
	else
	{
		behaviour = -1;
	}

	fp=fopen(filename,"rt");

	if(behaviour == GREP)
	{
		mygrep(fp,find);		
	}
	else if ( behaviour == REPLACE )
	{
		myreplace(fp,find,replace);		
	}
	
	fclose(fp);		
	return 0;
}



void mygrep(FILE *fp,char *find)
{
	char c1[500];
	char filename[50];

printf("Enter The name of the file \n");
scanf("%s", filename);
if((fp= fopen(filename, "r")) == NULL)
{
	printf("File Cannot Be opened \n");
}

else
{

	while(!feof(fp))
	{
		fgets(c1,sizeof(fp),fp);
		if(strcmp(c1,find))
		{
			printf("The string is :%s\n",c1);
		}
		else
		{
			printf("string not found \n");
		}
		
	}
}

fclose(fp);
}




void myreplace(FILE *fp,char *find, char * replace)
{
	char c1[500];
	int flen = strlen(find);
	char filename[50];

printf("Enter The name of the file \n");
scanf("%s", filename);
if((fp= fopen(filename, "r")) == NULL)
{
	printf("File Cannot Be opened \n");
}

else
{

	while(!feof(fp))
	{
		fgets(c1,sizeof(fp),fp);
		if(strcmp(c1,find))
		{
			find=replace;
			printf("The found string is :%s\n",c1);
			printf("The replaced srting is :%s\n",find);
		}
		else
		{
			printf("String Not found \n");
		}
	}
}
fclose(fp);
}