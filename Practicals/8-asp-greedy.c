#include <stdio.h>
#include <stdlib.h>

struct Activity {
    int start;
    int finish;
};

// Swap function for sorting
void swap(struct Activity *a, struct Activity *b) {
    struct Activity temp = *a;
    *a = *b;
    *b = temp;
}

// Sort activities by finish time
void sortActivities(struct Activity activities[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (activities[i].finish > activities[j].finish) {
                swap(&activities[i], &activities[j]);
            }
        }
    }
}

// Function to select activities
void activitySelection(struct Activity activities[], int n) {

    // Sort by finish time
    sortActivities(activities, n);
    printf("\nSelected activities (start, finish):\n");

    int lastFinish = activities[0].finish;
    printf("(%d, %d)\n", activities[0].start, activities[0].finish);

    // Select remaining compatible activities
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastFinish) {
            printf("(%d, %d)\n", activities[i].start, activities[i].finish);
            lastFinish = activities[i].finish;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    struct Activity activities[n];

    printf("Enter start and finish times of each activity:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d - Start: ", i + 1);
        scanf("%d", &activities[i].start);
        printf("Activity %d - Finish: ", i + 1);
        scanf("%d", &activities[i].finish);
    }

    activitySelection(activities, n);
    return 0;
}
