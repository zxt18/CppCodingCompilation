#include <stdio.h>

#define LOWER_MASK 0x0F
#define UPPER_MASK 0xF0
#define FLAG1 0x01
#define FLAG2 0x02
#define FLAG3 0x04
#define FLAG4 0x08
#define FLAG5 0x010


int main (int argc, char* argv[])
{
  char value=0xA5;
  char lower= value& LOWER_MASK;
  char upper = (value & UPPER_MASK) >>4;
  printf("Lower : %x\n", lower);
  printf("Upper : %x\n", upper);z
}
