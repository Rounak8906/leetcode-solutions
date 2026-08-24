bool sumGame(char* num) {
    int n = strlen(num);
    int half = n / 2;

    int leftSum = 0, rightSum = 0;
    int leftQ = 0, rightQ = 0;

    for (int i = 0; i < half; i++) {
        if (num[i] == '?')
            leftQ++;
        else
            leftSum += num[i] - '0';
    }

    for (int i = half; i < n; i++) {
        if (num[i] == '?')
            rightQ++;
        else
            rightSum += num[i] - '0';
    }

    int sumDiff = leftSum - rightSum;
    int qDiff = leftQ - rightQ;

    if (qDiff % 2 != 0)
        return true;

    if (sumDiff == 0 && qDiff == 0)
        return false;

    return abs(sumDiff) != (abs(qDiff) / 2) * 9;
}