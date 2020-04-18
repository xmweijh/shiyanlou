#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int findString(char * str, char * substr)
{
	int n = 0;
	while (*str != '\0')
	{
		//if (memcmp(str, substr, 4) == 0)
		//{
		//	return n;
		//}
		//else
		//{
		//	str++;
		//	n++;
		//	continue;
		//}
		if (*str != *substr)
		{
			str++;
			n++;
			continue;
		}
		//Create temporary pointer
		char* tmpStr = str;
		char* tmpSubstr = substr;
		while (*tmpSubstr != '\0')
		{
			if (*tmpStr != *tmpSubstr)
			{
				str++;
				n++;
				break;
			}
			tmpStr++;
			tmpSubstr++;
		}
		if (*tmpSubstr == '\0')
		{
			return n;
		}
	}
	return -1;
}

int main() {
	char* str = "abcdoasddotada";
	int res = findString(str, "dota");
	if (res == -1)
	{
		printf("could not find substring");
	}
	else
	{
		printf("finding substring at %d", res);
	}
	return 0;
}