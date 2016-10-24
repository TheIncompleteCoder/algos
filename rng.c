#include <stdio.h>
void printSign(size_t bytes,char *str)
{
int bits = 8*bytes;
int from = -(1 << (bits-1));
int to = (1 << (bits-1))-1;
printf("+----------sign %s: from %d to %d-----------+\n",str,from,to);
}

void printUnsign(size_t bytes,char *str)
{
int bits = 8*bytes;
unsigned int to = ((1 << (bits-1))-1)+(1 << (bits-1));
printf("+-----------unsign %s: from %u to %u------------+\n",str,0,to);
}

int main()
{
printf("for signed.......\n");
printSign(sizeof(int),"int");
printSign(sizeof(char),"char");
printSign(sizeof(float),"float");

printf("for unsigned.......\n");
printUnsign(sizeof(int),"int");
printUnsign(sizeof(char),"char");
printUnsign(sizeof(float),"float");
return 0;
}
