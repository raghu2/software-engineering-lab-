#include<stdio.h>
#include<stdlib.h>

#include "resultcalc.h"
#include "gradecalc.h"
#include "addnew.h"
#include "rollquery.h"
#include "displaystruct.h"

struct infos{
	char rollnumber[10];
	char name[10];
	char address[10];
	int marks1;
	int marks2;
	float avg;
	char grade;
};
struct infos info[10];

FILE *inp;
int i,num=0,choice,option;
char str[10];

void main(){

	inp=fopen("fileinfo.txt","r");

	while(!feof(inp)){
		fscanf(inp,"%s",(info[num].rollnumber));
		fscanf(inp,"%s",(info[num].name));
		fscanf(inp,"%s",(info[num].address));
		fscanf(inp,"%d",&(info[num].marks1));
		fscanf(inp,"%d",&(info[num].marks2));
		num++;
	}

	fclose(inp);

	printf("There are total %d number of records\n",num-1);

	for(i=0;i<num-1;i++){
		info[i].avg=avgresult(info[i].marks1,info[i].marks2);
		info[i].grade=graderesult(info[i].avg);
	}

	do{
		printf("enter the operation you want\n1-add new input\n2-query based on roll number\n");
		scanf("%d",&choice);
		if(choice==1){
			addnewinput(num);
		}
		else if(choice==2){
			printf("enter the roll number whose details you want\n");
			scanf("%s",str);
			roll(str);
		}
		else{
			printf("enter the correct input\n");
		}
		printf("do you want to do more of this sort?\n enter 0 to continue\n");
		scanf("%d",&option);
	}while(option==0);

	display();
}
