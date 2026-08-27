char* lexGreaterPermutation(char* s, char* target) {
    int n = strlen(s);
    int count[26] = {0};

    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }

    char* ans = (char*)malloc((n + 1) * sizeof(char));

    int i;

    /* Match target as much as possible */
    for (i = 0; i < n; i++) {
        int c = target[i] - 'a';

        if (count[c] > 0) {
            ans[i] = target[i];
            count[c]--;
        } else {
            break;
        }
    }

    /*
     * If we could not match target at position i,
     * first try making THIS position bigger.
     */
    if (i < n) {
        int targetChar = target[i] - 'a';

        for (int c = targetChar + 1; c < 26; c++) {
            if (count[c] > 0) {
                ans[i] = 'a' + c;
                count[c]--;

                int pos = i + 1;

                for (int x = 0; x < 26; x++) {
                    while (count[x] > 0) {
                        ans[pos++] = 'a' + x;
                        count[x]--;
                    }
                }

                ans[n] = '\0';
                return ans;
            }
        }
    }

    /*
     * If we cannot make the current position bigger,
     * backtrack to an earlier position.
     */
    for (int k = i - 1; k >= 0; k--) {

        /* Put the character back */
        count[ans[k] - 'a']++;

        int targetChar = target[k] - 'a';

        /* Find smallest character greater than target[k] */
        for (int c = targetChar + 1; c < 26; c++) {

            if (count[c] > 0) {

                ans[k] = 'a' + c;
                count[c]--;

                /* Fill rest in sorted order */
                int pos = k + 1;

                for (int x = 0; x < 26; x++) {
                    while (count[x] > 0) {
                        ans[pos++] = 'a' + x;
                        count[x]--;
                    }
                }

                ans[n] = '\0';
                return ans;
            }
        }
    }

    free(ans);
    return "";
}