/********************************* includes **********************************/
//stdlib includes
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

//Project includes
#include "generalDef.h"

/******************************** constants **********************************/
#define HELLO_MESSAGE "Hello world"

/******************************** function definitions ***********************/
int main(int argc, char *argv[])
{
  UNUSED(argc);
  UNUSED(argv);

  printf(HELLO_MESSAGE "\n");

  return 0;
}
