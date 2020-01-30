#include<stdio.h>
#include<stdlib.h>

FILE *inp2;

struct infos2{
        char rollnumber[10];
        char name[10];
        char address[10];
        int marks1;
        int marks2;
        float avg;
        char grade;
};
struct infos2 info1[10];

int i,num;

void display(){

	num=0;
        inp2=fopen("fileinfo.txt","r");

        while(!feof(inp2)){
                fscanf(inp2,"%s",(info1[num].rollnumber));
                fscanf(inp2,"%s",(info1[num].name));
                fscanf(inp2,"%s",(info1[num].address));
                fscanf(inp2,"%d",&(info1[num].marks1));
                fscanf(inp2,"%d",&(info1[num].marks2));
                num++;
        }

        fclose(inp2);

        printf("There are total %d number of records\n",num-1);

	for(i=0;i<num-1;i++){
		printf("%s \t %s \t %s \t %d \t %d \t %f \t %c \n",(info1[i].rollnumber),(info1[i].name),(info1[i].address),info1[i].marks1,info1[i].marks2,info1[i].avg,info1[i].grade);
	}
}

