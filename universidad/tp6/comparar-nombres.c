#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define tamList 100

typedef char list[tamList];

int main() {
	int i;
	
	list name1 = "Palma Jose";
	list name2 = "Gutierrez Joel";
	printf("%d\n", strcmp(name1, name2));
	
	name1[0] = tolower(name1[0]);
	printf("%s\n", name1);
	
	name1[0] = toupper(name1[0]);
	printf("%s\n", name1);
	return 0;
}

