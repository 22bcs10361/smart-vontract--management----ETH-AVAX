#include <stdio.h>
#include <stdlib.h>

// Function to compare two routes for qsort
int compareRoutes(const void *a, const void *b) {
    int *routeA = (int *)a;
    int *routeB = (int *)b;
    if (routeA[0] != routeB[0]) {
        return routeA[0] - routeB[0];
    } else {
        return routeA[1] - routeB[1];
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    if (N == 0) {
        printf("0\n");
        return 0;
    }

    int busRoutes[N][2];
    
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &busRoutes[i][0], &busRoutes[i][1]);
    }
    
    // Sort the bus routes based on their starting points, and then by their ending points
    qsort(busRoutes, N, sizeof(busRoutes[0]), compareRoutes);

    // Initialize the count of non-overlapping routes
    int remainingBuses = 1;  // Start with the first bus route
    int currentEnd = busRoutes[0][1];  // The end of the current merged route
    
    for (int i = 1; i < N; i++) {
        if (busRoutes[i][0] <= currentEnd) {
            // There is an overlap, merge the routes by extending the current route's end
            if (busRoutes[i][1] > currentEnd) {
                currentEnd = busRoutes[i][1];
            }
        } else {
            // No overlap, start a new route
            remainingBuses++;
            currentEnd = busRoutes[i][1];
        }
    }
    
    printf("%d\n", remainingBuses);
    return 0;
}
