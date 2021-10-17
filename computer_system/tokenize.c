
#include <stdio.h>

char keywords[32][10] = {"auto","break","case","char","const","continue","default",
"do","double","else","enum","extern","float","for","goto",
"if","int","long","register","return","short","signed",
"sizeof","static","struct","switch","typedef","union",
"unsigned","void","volatile","while"};

int main(void)
{
	char c;
	FILE *fp = fopen(__FILE__, "r");

	do
	{
		c = fgetc(fp);
		putchar(c);
	}
	while (c != EOF);

	fclose(fp);

	return 0;
}
