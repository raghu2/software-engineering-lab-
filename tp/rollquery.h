#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct infos1{
        char rollnumber[10];
        char name[10];
        char address[10];
        int marks1;
        int marks2;
        float avg;
        char grade;
};
struct infos1 info2[10];

FILE *inp3;
int num,ch,i,o,num1,num2;
char word[10],gr;
float av1;

void roll(char s[10]){

	num=0;
	printf("enter the option you want to choose\n 1-details based on roll number\n 2-update based on roll number\n");
	scanf("%d",&o);
	if(o==1){
		inp3=fopen("fileinfo.txt","a+");
		while(!feof(inp3)){
			fscanf(inp3,"%s",word);
			if(strcmp(word,s)==0){
				printf("%s",word);
				for(i=0;i<2;i++){
					fscanf(inp3,"%s",word);
					printf("%s\t",word);
				}
				fscanf(inp3,"%d",&num1);
				fscanf(inp3,"%d",&num2);
				av1=avgresult(num1,num2);
				gr=graderesult(av1);
				printf("%d\t%d\t%f\t%c\n",num1,num2,av1,gr);
				break;
			}
		}
		fclose(inp3);
	}
	else if(o==2){
		inp3=fopen("fileinfo.txt","a+");

		while((!feof(inp3)) && ((strcmp(word,s)))){
			fscanf(inp3,"%s",(info2[num].rollnumber));
			fscanf(inp3,"%s",(info2[num].name));
			fscanf(inp3,"%s",(info2[num].address));
			fscanf(inp3,"%d",&(info2[num].marks1));
			fscanf(inp3,"%d",&(info2[num].marks2));
			num++;
		}

		printf("enter what do you want to update \n 1-name \n 2-address \n 3-marks1 \n 4-marks2 \n");
		scanf("%d",&ch);
		switch(ch){
			case 1:printf("enter new name\n");
				scanf("%s",info2[num-1].name);
				break;
                        case 2:printf("enter new address\n");
                               scanf("%s",info2[num-1].address);
                               break;
                        case 3:printf("enter new marks1\n");
                               scanf("%d",&(info2[num-1].marks1));
                               break;
                        case 4:printf("enter new marks2\n");
                               scanf("%d",&(info2[num-1].marks2));
                               break;
			default:break;
		}
		printf("value updated");
		fclose(inp3);
		inp3=fopen("fileinfo.txt","w");
		for(i=0;i<ov;i++){
			fprintf(inp3,"%s ",info2[i].rollnumber);
                        fprintf(inp3,"%s ",info2[i].name);
                        fprintf(inp3,"%s ",info2[i].address);
                        fprintf(inp3,"%d ",info2[i].marks1);
                        fprintf(inp3,"%d ",info2[i].marks2);
			info2[i].avg=avgresult(info2[i].marks1,info2[i].marks2);
			info2[i].grade=graderesult(info2[i].avg);
                        fprintf(inp3,"%f ",info2[i].avg);
                        fprintf(inp3,"%c\n",info2[i].grade);
		}
		fclose(inp3);
	}

}


