#include <string.h>
#include <stdio.h>
#include "config/coloredBitmap.h"
//#include <stdio.h>
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) {
   // YOUR CODE HERE - BEGIN
int taille = (3 * (w * h * 8)) ;

  printf("Taille en bits: %d\n", taille);

 if (strcmp(unit, "bt") == 0) {
        return (float)taille; 
    } else if (strcmp(unit, "ko") == 0) {
        return (float)taille / 8 / 1024; 
    } else if (strcmp(unit, "mo") == 0) {
        return (float)taille / 8 / 1024 / 1024;
    } else if (strcmp(unit, "go") == 0) {
        return (float)taille / 8 / 1024 / 1024 / 1024;
    }
    return 0; 
    // YOUR CODE HERE - END
}