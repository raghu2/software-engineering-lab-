#include<stdio.h>
#include<stdlib.h>

char graderesult(float a){
	char g;
	if(a>=9){
                g='A';
        }
        else if(a>=8){
                g='B';
        }
        else if(a>=7){
                g='C';
        }
        else if(a>=6){
                g='D';
        }
        else{
                g='F';
        }
	return g;
}

