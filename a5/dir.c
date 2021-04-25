/*Joel Maus*/
/*dir will show contents of directory and sort them*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char *argv[]){
int compareSize(const void*,const void*);
int compareName(const void*,const void*);
DIR *dir;
struct dirent *entry;
struct stat sz;
struct stat date;
struct tm *tm;
int size;
char* sortMethod; 
char modArray[50][50];
int item = 0;
char formattedTime[50][50];
char arrName[50][50];
char arrSize[50][50];
char modTemp[2]={'\0'};/*null char to be added to strings*/
int sizeOfFile[50];
if (argc>1){
	dir = opendir(argv[1]);

	if (argc>2)
	sortMethod = argv[2];
}
else
	dir = opendir(".");
	
while ((entry = readdir(dir)) != NULL ){ /********************/

	stat(entry->d_name,&sz); /*get size of file by name*/
	size = sz.st_size; /*save into size variable*/
	
	
	stat(entry->d_name,&date);
	tm = gmtime(&(date.st_ctime));
		
	sizeOfFile[item]=size;

	strcpy(arrName[item],entry->d_name);		/*copy name to arrName array*/
	strcpy(modArray[item],ctime(&date.st_mtime));
	strcat(modArray[item],modTemp);			/*add null terminator to strings*/
	strcat(arrName[item],modTemp);
	++item;		
} /**************************************************/
int total = item;

closedir(dir);
int y=0;

for (item=0;item<total;++item){ /**********************************/

	for (int x =4; x<16; ++x){
		formattedTime[item][y]=modArray[item][x];
		strcat(formattedTime[item],modTemp);/*split time modified to correct format*/
		++y;
	}
	formattedTime[item][y]='\0'; /*end of string*/

	y=0;
	printf("\n%i",*(sizeOfFile + item));/*PRINT*/
	
	if (*(sizeOfFile + item)>=10000)	printf(" ");
	else if (*(sizeOfFile + item)>=1000)	printf("  ");
	else if (*(sizeOfFile + item)>=100)	printf("   ");/*spacing depending on size of file in bytes*/
	else if (*(sizeOfFile + item)>=10)	printf("    ");
	else	printf("     ");

	printf("%s  ",formattedTime + item, modArray );/*PRINT*/
	printf(" %s",arrName + item);/*PRINT*/


} /***************************************************************/
char *tmparg[6] = {"Command-line", "readFile.txt","-g",NULL};


printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");/*process that sorts once file is created*/
pid_t pro;
pro = fork();/*create new process to read created text file*/
if (argv[2][1]=='t'){
;
tmparg[2]="-k";
tmparg[3]="2";
tmparg[4]="-M";
tmparg[5]=NULL;
}

else if (argv[2][1]=='s'){
;
tmparg[2]="-g";
tmparg[3]=NULL;
}

else/*make default sort by name*/
{
;
tmparg[2]="-k";
tmparg[3]="5";
tmparg[4]=NULL;

}

if (pro==0)
	execvp ("sort",tmparg);/*run sort on dir.c with text file created to sort through*/




qsort(sizeOfFile,total,sizeof(int),compareSize);
/*qsort(arrName,total,sizeof(char),compareName);*/
/*printf("\n\n");
for (int item=0;item<total;++item)
	printf("%i  \n",*(sizeOfFile + item));*/
	
qsort(arrName,total,sizeof(char),compareName);
/*for (int item =0;item<total;++item)*/
/*	printf("%s \n",*(arrName + item));*/


}
int compareSize(const void *num1, const void *num2){
	return (*(int*)num1 - *(int*)num2);
}
/*
int compareDate(const void *num1, const void *num2){

}
*/
int compareName(const void *num1, const void *num2){
	return (*(char*)num1 - *(char*)num2);
}


