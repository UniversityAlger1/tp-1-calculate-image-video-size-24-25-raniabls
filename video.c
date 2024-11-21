#include <string.h>
#include <stdio.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
   // YOUR CODE HERE - BEGIN
   // Calculate size of color section
    int sizePerFrameColor = w * h * 3; // in bytes
    int totalFramesColor = durationMovie * fps;
    long totalSizeColor = sizePerFrameColor * totalFramesColor; // in bytes

    // Calculate size of black-and-white section
    int sizePerFrameBW = w * h; // in bytes
    int totalFramesBW = durationCredits * fps;
    long totalSizeBW = sizePerFrameBW * totalFramesBW; // in bytes

    // Total size in bytes
    long totalSizeBytes = totalSizeColor + totalSizeBW;

    // Convert to requested unit
    if (strcmp(unit, "bt") == 0) {
        return (float)totalSizeBytes; // in bytes
    } else if (strcmp(unit, "ko") == 0) {
        return (float)totalSizeBytes / 1024; // in kilobytes
    } else if (strcmp(unit, "mo") == 0) {
        return (float)totalSizeBytes / (1024 * 1024); // in megabytes
    } else if (strcmp(unit, "go") == 0) {
        return (float)totalSizeBytes / (1024 * 1024 * 1024); // in gigabytes
    }

   // If the unit is not recognized, return 0
   // YOUR CODE HERE - END
   return 0;
}