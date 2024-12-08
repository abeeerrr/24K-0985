/* Name/Roll Number: Abeer Fatima (24K-0985)
q7: In a Netflix-like streaming platform, 2D pointers are used to dynamically manage and personalize
the viewing experience for millions of users across diverse content categories and device types.
The platform employs a 2D pointer structure, where each row represents a user profile, and each
column corresponds to a content category (e.g., Action, Drama, Comedy). A double**
engagementMatrix pointer points to this 2D array, where each element stores a numerical
engagement score (e.g., average viewing time or like/dislike ratio) for a user's interaction with that
category.
Each user profile structure includes a pointer to their respective row in the engagement matrix,
allowing for quick retrieval and updates of personalized data. For example,
engagementMatrix[userIndex][categoryIndex] can be updated whenever the user streams content
from a specific category, dynamically recalibrating their preferences in real-time.
The system also uses a secondary 2D pointer structure to manage device-specific preferences.
For instance, deviceMatrix[userIndex][deviceIndex] points to dynamically allocated arrays holding
resolution preferences, playback history, and bandwidth usage for different devices (smart TVs,
laptops, smartphones) associated with a user's profile. This enables seamless transitions between
devices while maintaining personalized settings like resolution and playback position.
Additionally, another 2D pointer system tracks content metadata, where each row corresponds to a
content category and each column represents a specific piece of content. Each element in this
matrix contains a pointer to a structure with attributes like title, rating, runtime, and encoding
formats, enabling quick access to metadata for streaming.
This multi-layered 2D pointer-based design allows the platform to efficiently store, retrieve, and
update personalized recommendations, device preferences, and content metadata. By leveraging
such dynamic data structures, the system delivers a highly tailored, device-optimized viewing
experience for users, ensuring maximum engagement and satisfaction while handling the scalability
needs of a global user base.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    float rating;
    int runtime; 
    char encodingFormat[20];
} ContentMetadata;

typedef struct {
    char username[30];
    float *engagementScores;
    char **devicePreferences;
    int numDevices;
} UserProfile;

float **initializeEngagementMatrix(int numUsers, int numCategories) {
    float **matrix = (float **)malloc(numUsers * sizeof(float *));
    for (int i=0; i <numUsers; i++) {
        matrix[i] = (float *)calloc(numCategories, sizeof(float)); 
    }
    return matrix;
}

char ***initializeDevicePreferences(int numUsers, int *devicesPerUser) {
    char ***deviceMatrix = (char ***)malloc(numUsers * sizeof(char **));
    for (int i=0; i< numUsers; i++) {
        deviceMatrix[i] = (char **)malloc(devicesPerUser[i] * sizeof(char *));
        for (int j = 0; j < devicesPerUser[i]; j++) {
            deviceMatrix[i][j] = (char *)calloc(100, sizeof(char)); 
        }
    }
    return deviceMatrix;
}

ContentMetadata **initializeContentMetadata(int numCategories, int numContentPerCategory) {
    ContentMetadata **contentMatrix = (ContentMetadata **)malloc(numCategories * sizeof(ContentMetadata *));
    for (int i = 0; i < numCategories; i++) {
        contentMatrix[i] = (ContentMetadata *)malloc(numContentPerCategory * sizeof(ContentMetadata));
    }
    return contentMatrix;
}

void displayEngagementMatrix(float **matrix, int numUsers, int numCategories) {
    printf("\n--- Engagement Matrix ---\n");
    for (int i = 0; i < numUsers; i++) {
        printf("User %d: ", i + 1);
        for (int j = 0; j < numCategories; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void displayContentMetadata(ContentMetadata **contentMatrix, int numCategories, int numContentPerCategory) {
    printf("\n--- Content Metadata ---\n");
    for (int i = 0; i < numCategories; i++) {
        printf("Category %d:\n", i + 1);
        for (int j = 0; j < numContentPerCategory; j++) {
            printf("  Title: %s, Rating: %.1f, Runtime: %d min, Format: %s\n",
                   contentMatrix[i][j].title, contentMatrix[i][j].rating,
                   contentMatrix[i][j].runtime, contentMatrix[i][j].encodingFormat);
        }
    }
}

void freeEngagementMatrix(float **matrix, int numUsers) {
    for (int i = 0; i < numUsers; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void freeDevicePreferences(char ***deviceMatrix, int numUsers, int *devicesPerUser) {
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < devicesPerUser[i]; j++) {
            free(deviceMatrix[i][j]);
        }
        free(deviceMatrix[i]);
    }
    free(deviceMatrix);
}

void freeContentMetadata(ContentMetadata **contentMatrix, int numCategories) {
    for (int i = 0; i < numCategories; i++) {
        free(contentMatrix[i]);
    }
    free(contentMatrix);
}

int main() {
    int numUsers = 2, numCategories = 3, numContentPerCategory = 2;
    int devicesPerUser[] = {2, 3}; 

    float **engagementMatrix = initializeEngagementMatrix(numUsers, numCategories);

    char ***deviceMatrix = initializeDevicePreferences(numUsers, devicesPerUser);

    ContentMetadata **contentMatrix = initializeContentMetadata(numCategories, numContentPerCategory);

    engagementMatrix[0][0] = 5.0; 
    engagementMatrix[0][1] = 3.5; 
    engagementMatrix[1][0] = 4.2; 

    strcpy(deviceMatrix[0][0], "Resolution: 1080p, Bandwidth: 5Mbps");
    strcpy(deviceMatrix[0][1], "Resolution: 4K, Bandwidth: 15Mbps");

    strcpy(contentMatrix[0][0].title, "Action Movie 1");
    contentMatrix[0][0].rating = 4.5;
    contentMatrix[0][0].runtime = 120;
    strcpy(contentMatrix[0][0].encodingFormat, "H.264");

    strcpy(contentMatrix[0][1].title, "Action Movie 2");
    contentMatrix[0][1].rating = 4.7;
    contentMatrix[0][1].runtime = 150;
    strcpy(contentMatrix[0][1].encodingFormat, "H.265");

    displayEngagementMatrix(engagementMatrix, numUsers, numCategories);
    displayContentMetadata(contentMatrix, numCategories, numContentPerCategory);

    freeEngagementMatrix(engagementMatrix, numUsers);
    freeDevicePreferences(deviceMatrix, numUsers, devicesPerUser);
    freeContentMetadata(contentMatrix, numCategories);

    return 0;
}
