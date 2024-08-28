#ifndef HASH_H
#define HASH_H
#include <stdio.h>
#include <stdint.h>

typedef struct node {
  int val;
  const char* key;
  struct node* next;
} node; 

typedef struct HashMap {
  size_t mapSize;
  node* map;
} HashMap;

HashMap* initHashMap(size_t initialMapSize);

HashMap* deleteHashMap(HashMap* map);

uint64_t insertElement(HashMap* hashmap, const char* _key, int value);

node* findElement(HashMap* hashmap, const char* key);

#endif