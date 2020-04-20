#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int getFileLines(FILE* file)
{
	if (file == NULL)
	{
		return -1;
	}
	char buf[1024];
	int num = 0;
	while ( fgets(buf,1024,file) != NULL)
	{
		num++;
	}
	fseek(file, 0, SEEK_SET);
	return num;
}

void readFileData(FILE* file, int len, char** pArray)
{
	if (file == NULL)
	{
		return;
	}
	if (len <= 0)
	{
		return;
	}
	if (pArray == NULL)
	{
		return;
	}
	char buf[1024];
	int index = 0;
	while (fgets(buf, 1024, file) != NULL)
	{
		int currentLen = strlen(buf) + 1;
		char* currentP = malloc(sizeof(char) * currentLen);
		strcpy(currentP, buf);
		pArray[index++] = currentP;
		memset(buf, 0, 1024);
	}
}

void showFileData(char ** pArray, int len)
{
	for (size_t i = 0; i < len; i++)
	{
		printf("%d: %s", i + 1, pArray[i]);
	}
}

void freeSpace(char** pArray, int len)
{
	for (size_t i = 0; i < len; i++)
	{
		if (pArray[i] != NULL)
		{
			free(pArray[i]);
			pArray[i] = NULL;
		}
	}
}

int main() {
	FILE * file = fopen("./test.txt", "r");
	if (file == NULL)
	{
		printf("File open failed.");
	}
	int len = getFileLines(file);
	char** pArray = malloc(sizeof(char*) * len);
	readFileData(file, len, pArray);
	showFileData(pArray,len);
	freeSpace(pArray,len);
	pArray = NULL;
	return 0;
}