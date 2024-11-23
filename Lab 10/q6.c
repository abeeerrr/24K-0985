/*
Name/Roll Number: Abeer Fatima (24K-0985)

Q6: Define a structure to represent a point in 2D space with x and y coordinates. Implement
functions to calculate the distance between two points and to check if a point lies within
a specific rectangular boundary.

*/
#include <stdio.h>
#include <math.h>

struct Point {
    float x;
    float y;
};

float calculateDistance(struct Point p1, struct Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int isPointWithinBoundary(struct Point p, float xMin, float yMin, float xMax, float yMax) {
   
    if (p.x >= xMin && p.x <= xMax && p.y >= yMin && p.y <= yMax) {
        return 1; 
    }
    return 0; 
}

int main() {
    struct Point p1, p2;

    
    printf("Enter coordinates for Point 1 (x y): ");
    scanf("%f %f", &p1.x, &p1.y);

    printf("Enter coordinates for Point 2 (x y): ");
    scanf("%f %f", &p2.x, &p2.y);

    
    float distance = calculateDistance(p1, p2);
    printf("The distance between Point 1 and Point 2 is: %.2f\n", distance);

    
    float xMin = 0.0, yMin = 0.0, xMax = 10.0, yMax = 10.0;

    
    if (isPointWithinBoundary(p1, xMin, yMin, xMax, yMax)) {
        printf("Point 1 is inside the rectangular boundary.\n");
    } else {
        printf("Point 1 is outside the rectangular boundary.\n");
    }

    
    if (isPointWithinBoundary(p2, xMin, yMin, xMax, yMax)) {
        printf("Point 2 is inside the rectangular boundary.\n");
    } else {
        printf("Point 2 is outside the rectangular boundary.\n");
    }

    return 0;
}
