/* A Simple Memory Allocator */

#include <stddef.h>

typedef char ALIGN[16];

union header {
  // Store information for every block newly allocated memory block
  struct {
    size_t size;
    unsigned is_free;
    struct header_t *next;
  } s;
  ALIGN stub;
};

typedef union header header_t;

// Allocate bytes on the heap
void *malloc(size_t size) {
  void *block;
  block = sbrk(size);
  if (block == (void *)-1)
    return NULL;
  return block;
}
