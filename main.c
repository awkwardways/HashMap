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
  HashMap* myMap = initHashMap(128);  //initialize hash map
  uint64_t temp = insertElement(myMap, argv[1], 1); //get first element and insert
  uint64_t tempAgain = insertElement(myMap, argv[2], 1);  //get second element and insert

  // printf("%d\n", temp); 
  // printf("value at index %d is %d with string %s\n", temp, (myMap->map[temp].val), myMap->map[temp].key);

  printf("Hash of first element is: %d\nHash of second element is: %d\n", temp, tempAgain);

  // node* tempNode = findElement(myMap, argv[1]);
  // node* tempNodeAgain = findElement(myMap, argv[2]);

  // if(tempNode != NULL) {
  //   printf("Key %s has the value %d assigned\n", tempNode->key, tempNode->val);
  // }
  // else {
  //   printf("Element not found\n");
  // }
  // if(tempNodeAgain != NULL) {
  //   printf("Key %s has the value %d assigned\n", tempNodeAgain->key, tempNodeAgain->val);
  // }
  // else {
  //   printf("Element not found\n");
  // }

  myMap = deleteHashMap(myMap);
  return EXIT_SUCCESS;
}