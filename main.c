#include <stdio.h>
#include <stdint.h>
#include "hash.h"

#define EXIT_SUCCESS      0
#define EXIT_FAILURE      1
#define FNV_OFFSET_BASIS  0xcbf29ce484222325
#define FNV_PRIME         0x00000100000001b3


// uint64_t FNV1A(const char* str) {
//   uint64_t hash = FNV_OFFSET_BASIS;
//   while(*str != '\0') {
//     hash ^= *(str++);
//     hash *= FNV_PRIME;
//   }
//   return hash;
// }

int main(int argc, char* argv[]) {
  HashMap* myMap = initHashMap(23);  
  char* variableNames[] = {
    "",
    "i",
    "x",
    "y",
    "z",
    "temp",
    "aux",
    "idx",
    "foo",
    "bar",
    "src",
    "costarring",
    "liquid"
  };
  for(size_t idx = 0; idx < 13; ++idx) {
    printf("%d: %s\n", insertElement(myMap, variableNames[idx], 1), variableNames[idx]);
  }
  node* temp = NULL;
  if(temp = findElement(myMap, "z")) {
    printf("Element found %s\n", temp->key);
  }
  else {
    printf("Does not exist\n");
  }
  myMap = deleteHashMap(myMap);
  return EXIT_SUCCESS;
}