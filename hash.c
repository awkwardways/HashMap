#include "hash.h"
#include <stdlib.h>
#include <stdint.h>

#define FNV_OFFSET_BASIS  0xcbf29ce484222325
#define FNV_PRIME         0x00000100000001b3

// Make resizing mechanism
// Safety checks
// Memory management
// // Collision management (fix collision insertion)

node* deleteList(node currentNode) {
  printf("deleting %s\n", currentNode.key);
  if(currentNode.next == NULL) {
    return &currentNode;
  }
  free(deleteList(*currentNode.next));
}

void deleteLists(size_t sizeOfMap, node* map) {
  size_t idx = sizeOfMap;
  while(idx < sizeOfMap) {
    //recursive call upon current node
    deleteList(map[idx]);
    idx++;
  }
}

void nullifyLinkedList(node* map, size_t initialMapSize) {
  for(size_t idx = 0; idx < initialMapSize; idx++) map[idx].next = NULL;
}

uint64_t FNV1A(const char* str) {
  uint64_t hash = FNV_OFFSET_BASIS;
  while(*str != '\0') {
    hash ^= *(str++);
    hash *= FNV_PRIME;
  }
  return hash;
}

//Dynamically allocates a hashmap of size initialMapSize and initializes all node pointers to the next node as NULL
HashMap* initHashMap(size_t initialMapSize) {
  HashMap* newmap = (HashMap*) malloc(sizeof(HashMap));
  newmap->mapSize = initialMapSize;
  newmap->map = (node*) malloc(initialMapSize * sizeof(node));
  nullifyLinkedList(newmap->map, initialMapSize);
  return newmap;
}

//Deletes all dynamically allocated memory
HashMap* deleteHashMap(HashMap* hashmap) {
  deleteLists(hashmap->mapSize, hashmap->map);
  free(hashmap->map);
  hashmap->map = NULL;
  free(hashmap);
  hashmap = NULL;
  return hashmap;
}

//Insert an integer into a hashmap using a string as a key
uint64_t insertElement(HashMap* hashmap, const char* _key, int value) {
  //hash the string
  uint64_t idx = FNV1A(_key) % hashmap->mapSize;
  node* it = &hashmap->map[FNV1A(_key) % hashmap->mapSize];

  while(it->next != NULL) it++;
  
  //insert element and create next node
  it->key = _key;
  it->val = value;
  it->next = (node*) malloc(sizeof(node));
  it->next->next = NULL;  //Nullify new node's next pointer to signal an unpopulated node (new node has not been occupied)

  return idx;
}

//Looks for key in hashmap. Returns NULL if key doesn't exist
node* findElement(HashMap* hashmap, const char* key) {
  size_t idx = FNV1A(key) % hashmap->mapSize;
  node* it = &hashmap->map[idx];
  while(it != NULL) {
    if(key == it->key) break;
    it = it->next;
  }
  return it;
}

