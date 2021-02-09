#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){
	char Name[16];
	fgets(Name, sizeof(Name), stdin);
	printf("%s \n",Name);
	return 0;
}