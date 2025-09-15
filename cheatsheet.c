#include <stdio.h>
//#include <string.h>

void greeting(void); //prototype
int leftshift(int x, int n); //prototype 
void printAscii(void); //prototype
void bufferOverflow(void); //prototype

int main() //gcc cheatsheet.c -o cheatsheet.exe -std=c17 //
{
    int a = 1;
    int b = 8;
    greeting();
    printAscii();
    bufferOverflow();
    //printf("Seek A Firm Footing In The Depths: Solidum Petit In Profundis\n");
    printf("\n\nLeft shift %d by %d: %d\n\n", a, b, leftshift(a, b)); // Outputs 8
    return leftshift(a, b);
}

void greeting(void) { 
    char howFar[] = "Seek a Firm Footing In The Depths: Solidum Petit In Profundis\n";
    printf("%s", howFar);
}

int leftshift(int x, int n) {  //prototype implementation
    return x << n;
}
void printAscii(void){ 
    for (int i = 0; i < 128; i++) {
        printf("ASCII %3d = %c\n", i, i);
    } //prototype
}
void bufferOverflow(void){ 
    char buffer[8];
    printf("Enter some text: ");
    gets(buffer); // unsafe function, use fgets instead
    printf("You entered: %s\n", buffer);
}