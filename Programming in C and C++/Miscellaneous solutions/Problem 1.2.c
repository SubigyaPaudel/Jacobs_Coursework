#include <stdio.h>

int main() {
int result;
result = (2 + 7) * 9 / 3;
printf("The result is %d\n",result); /*in the orginal program which was not debugged, an argument was missing. So the printf function did not know what to insert at the place where %d was written */
return 0;
}
 