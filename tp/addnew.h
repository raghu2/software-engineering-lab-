#include<stdio.h>
#include<stdlib.h>

//#include "resultcalc.h"
//#include "gradecalc.h"

FILE *inp1;
char rolln[10],name[10],address[10],c;
int marksa,marksb;
float av;

void addnewinput(int a){
	if(a>=9){
		printf("entering not possible since structure is full\n");
	}
	else{
		printf("enter the details you want to enter in the format of roll number,name,address,marks1,marks2");
		scanf("%s %s %s %d %d",rolln,name,address,&marksa,&marksb);
		inp1=fopen("fileinfo.txt","a");
		fprintf(inp1,"%s ",rolln);
                fprintf(inp1,"%s ",name);
                fprintf(inp1,"%s ",address);
                fprintf(inp1,"%d ",marksa);
                fprintf(inp1,"%d ",marksb);
		a++;

		av=avgresult(marksa,marksb);
		c=graderesult(av);
                fprintf(inp1,"%f ",av);
                fprintf(inp1,"%d",c);
	}
	fclose(inp1);
}
