#include <stdlib.h>

static int compareRows(const void* a, const void* b) {
    int* rowA = *(int**)a;
    int* rowB = *(int**)b;
    if (rowA[0] != rowB[0]) {
        return rowA[0] - rowB[0];
    }
    return rowA[1] - rowB[1];
}

int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize) {
    if (reservedSeatsSize == 0) {
        return n * 2;
    }

    qsort(reservedSeats, reservedSeatsSize, sizeof(int*), compareRows);

    int totalGroups = 0;
    int distinctReservedRows = 0;
    int i = 0;

    while (i < reservedSeatsSize) {
        int currentRow = reservedSeats[i][0];
        int mask = 0;

        // Collect all reserved seats for the current row
        while (i < reservedSeatsSize && reservedSeats[i][0] == currentRow) {
            int seat = reservedSeats[i][1];
            mask |= (1 << seat);
            i++;
        }

        distinctReservedRows++;

        int leftFree = (mask & 0x003C) == 0;    // seats 2, 3, 4, 5
        int rightFree = (mask & 0x03C0) == 0;   // seats 6, 7, 8, 9
        int middleFree = (mask & 0x00F0) == 0;  // seats 4, 5, 6, 7

        if (leftFree && rightFree) {
            totalGroups += 2;
        } else if (leftFree || rightFree || middleFree) {
            totalGroups += 1;
        }
    }

    // Add 2 groups for each untouched row
    totalGroups += (n - distinctReservedRows) * 2;

    return totalGroups;
}