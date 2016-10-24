#include <stdio.h>

int checkIntSigned(int);
char checkCharSigned(char);
float checkFloatSigned(float);

int checkIntUnSigned(int);
char checkCharUnSigned(char);
float checkFloatUnSigned(float);

int
main(int argc,char **argv){
printf("range of int = %d",checkInt(521));
printf("range of char = %d",checkChar('a'));
printf("range of float = %f",checkFloat(56.23));
return 0;
}

int checkIntSigned(int var)
{
int range;
range = var;
return range;
}
int checkIntUnSigned(unsigned int var)
{
unsigned int range;
range = var;
return range;
}

char checkCharSigned(char var) 
{
int range;
range = var;

return range;
}
char checkCharUnSigned(unsigned char var) 
{
unsigned int range;
range = var;

return range;
}

float checkFloatSigned(float var)
{
float range;
range = var;

return range;
}
float checkFloatUnSigned(unsigned float var)
{
unsigned float range;
range = var;

return range;
}
