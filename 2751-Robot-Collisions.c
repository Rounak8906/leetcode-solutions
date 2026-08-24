#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int pos;
    int health;
    char dir;
    int id;
} Robot;

// Comparator to sort robots by position ascending
int compareRobots(const void* a, const void* b) {
    return ((Robot*)a)->pos - ((Robot*)b)->pos;
}

int* survivedRobotsHealths(int* positions, int positionsSize, int* healths, int healthsSize, char* directions, int* returnSize) {
    int n = positionsSize;
    Robot* robots = (Robot*)malloc(n * sizeof(Robot));

    for (int i = 0; i < n; i++) {
        robots[i].pos = positions[i];
        robots[i].health = healths[i];
        robots[i].dir = directions[i];
        robots[i].id = i;
    }

    qsort(robots, n, sizeof(Robot), compareRobots);

    // Stack to keep track of right-moving robots ('R')
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++) {
        if (robots[i].dir == 'R') {
            stack[++top] = i;
        } else {
            // Collision handling for 'L' robot against preceding 'R' robots
            while (top >= 0 && robots[i].health > 0) {
                int r_idx = stack[top];

                if (robots[r_idx].health < robots[i].health) {
                    robots[r_idx].health = 0;
                    robots[i].health -= 1;
                    top--;
                } else if (robots[r_idx].health > robots[i].health) {
                    robots[r_idx].health -= 1;
                    robots[i].health = 0;
                } else {
                    // Both have equal health
                    robots[r_idx].health = 0;
                    robots[i].health = 0;
                    top--;
                }
            }
        }
    }

    // Map surviving healths back to their original input indices
    int* orig_health = (int*)calloc(n, sizeof(int));
    int survivor_count = 0;

    for (int i = 0; i < n; i++) {
        if (robots[i].health > 0) {
            orig_health[robots[i].id] = robots[i].health;
            survivor_count++;
        }
    }

    // Collect surviving robots in original input order
    int* result = (int*)malloc(survivor_count * sizeof(int));
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (orig_health[i] > 0) {
            result[idx++] = orig_health[i];
        }
    }

    *returnSize = survivor_count;

    // Clean up temporary memory
    free(robots);
    free(stack);
    free(orig_health);

    return result;
}

