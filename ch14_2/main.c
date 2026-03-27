#include <stdio.h>
#include "chunk.h"

int main() {
  Chunk chunk;
  initChunk(&chunk);

  // Simulate instructions across lines
  // Instructions 0–9 → line 5
  for (int i = 0; i < 10; i++) {
    writeChunk(&chunk, OP_CONSTANT, 5);
  }

  // Instructions 10–15 → line 6
  for (int i = 10; i < 16; i++) {
    writeChunk(&chunk, OP_ADD, 6);
  }

  // Instructions 16–20 → line 7
  for (int i = 16; i < 21; i++) {
    writeChunk(&chunk, OP_RETURN, 7);
  }

  // 🔹 Print instruction → line mapping
  printf("Instructions:\n");
  for (int i = 0; i < chunk.count; i++) {
    printf("Instruction %d -> line %d\n", i, getLine(&chunk, i));
  }

  // 🔹 Print compressed storage
  printf("\nCompressed storage:\n");
  for (int i = 0; i < chunk.lineCount; i++) {
    printf("lines[%d] = {offset: %d, line: %d}\n",
           i,
           chunk.lines[i].offset,
           chunk.lines[i].line);
  }

  freeChunk(&chunk);
  return 0;
}