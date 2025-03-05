#ifndef LEVEL_H
#define LEVEL_H

#include "cprocessing.h"

// Constants
#define TILE_SIZE 60
#define Box_SIZE 50

 #define NUM_BLOCKS 20
typedef struct {
    float x, y;  // Position of the block
} Block;

typedef struct {
    float x, y;
} Box;

Box box;  // Single box for row 3


// Function prototypes
void InitializeLevel(void);
void DrawLevel(void);
void Level_Exit(void);

#endif // LEVEL_H
