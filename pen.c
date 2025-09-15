#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
auto       break      case       char       const
continue   default    do         double     else
enum       extern     float      for        goto
if         int        long       register   return
short      signed     sizeof     static     struct
switch     typedef    union      unsigned   void
volatile   while
*/

#define PATH "C:\\Users\\orisa\\Documents\\newCode\\poseidon"

typedef struct Pen{
    int ink;
    char brand[16];
    char *colors[];  // Flexible array member
} Pen;

int main() {
    const char* colorSet[] = {"Blue", "Black", "Red", "Green"};
    const char* brandNames[] = {"Bic", "Parker", "Reynolds", "Sarasa"};
    int numColors = 4;
    

    // Allocate memory for Pen + array of 3 char* pointers
    Pen* myPen = malloc(sizeof(Pen) + sizeof(char*) * numColors);
    if (!myPen) {
        perror("malloc failed");
        return 1;
    }

    myPen->ink = 100;
    strncpy(myPen->brand, "Bic", sizeof(myPen->brand));
    
    for (int i = 0; i < numColors; i++) {
        myPen->colors[i] = strdup(colorSet[i]);  // Copy string into heap
    }

    printf("%s\n", PATH);
    int j = 0;
    while (myPen->ink > 0 && j < numColors) {
        printf("%s %s Pen ink level: %d\n", strdup(colorSet[j]), myPen->brand, myPen->ink);
        myPen->ink -= 10;
        j++;
        j = (j % numColors); // Cycle through colors
    }

    // Free allocated color strings
    for (int i = 0; i < numColors; i++) {
        free(myPen->colors[i]);
    }
    free(myPen);

    return 0;
}
/*
typedef struct {
    int ink;
    char brand[16];
    char *colors[];
} Pen;

int main() {
    printf("%s\n", PATH);
    Pen myPen = {100, "Bic"};
    while (myPen.ink > 0) {
        printf("%s Pen ink level: %d\n", myPen.brand, myPen.ink);
        myPen.ink -= 10; // Use some ink
    } 
    return 0;
}*/
/*
Server
Client
*/

