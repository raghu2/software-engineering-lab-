//program involving different tasks that specify the inerstion and updation of records in a file using a structure.
#include<stdio.h>
#include<stdlib.h>

struct infos{
	char roll[10];
	char name[10];
	char address[20];
	int marks1;
	int marks2;
	float avg;
	char grade;
};

struct infos info[10];
FILE *inp;
int i,num=0;

void avgresult(int a,int b){
	info[i].avg=(a+b)/2;
}

void grade(float a){
	if(a>=9){
		info[i].grade='A';
	}
	else if(a>=8){
		info[i].grade='B';
	}
	else if(a>=7){
		info[i].grade='C';
	}
	else if(a>=6){
		info[i].grade='D';
	}
	else{
		info[i].grade='F';
	}
}

void displaystruct(struct infos a[10]){
	printf("Roll \t\t Name \t Address \t Marks1 \t Marks2 \t Average \t Grade \n\n");
	for(i=0;i<num-1;i++){
		printf("%s \t %s \t %s \t %d \t\t %d \t\t %f \t %c \n",a[i].roll,a[i].name,a[i].address,a[i].marks1,a[i].marks2,a[i].avg,a[i].grade);
	}
}

void main(){
	inp=fopen("fileinfo.txt","r");
	while(!feof(inp)){
		fscanf(inp,"%s",&(info[num].roll));
		fscanf(inp,"%s",&(info[num].name));
		fscanf(inp,"%s",&(info[num].address));
		fscanf(inp,"%d",&(info[num].marks1));
		fscanf(inp,"%d",&(info[num].marks2));
		num++;
	}
	fclose(inp);
	for(i=0;i<num-1;i++){
		avgresult(info[i].marks1,info[i].marks2);
		grade(info[i].avg);
	}
	displaystruct(info);
}
