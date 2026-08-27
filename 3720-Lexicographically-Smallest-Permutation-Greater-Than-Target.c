char* lexGreaterPermutation(char* s, char* target) {
    int n = strlen(s);
    int count[26] = {0};

    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }

    char* ans = (char*)malloc((n + 1) * sizeof(char));

    for (int i = 0; i < n; i++) {
        int t = target[i] - 'a';

        /* Try to keep the same character */
        if (count[t] > 0) {
            ans[i] = target[i];
            count[t]--;
        } 
        else {
            /* Find the smallest character greater than target[i] */
            int j;
            for (j = t + 1; j < 26; j++) {
                if (count[j] > 0)
                    break;
            }

            if (j == 26) {
                /* Need to backtrack */
                int k = i - 1;

                while (k >= 0) {
                    count[ans[k] - 'a']++;

                    int c;
                    for (c = ans[k] - 'a' + 1; c < 26; c++) {
                        if (count[c] > 0)
                            break;
                    }

                    if (c < 26) {
                        ans[k] = 'a' + c;
                        count[c]--;

                        k++;

                        /* Fill remaining positions smallest first */
                        int pos = k;

                        for (int x = 0; x < 26; x++) {
                            while (count[x] > 0) {
                                ans[pos++] = 'a' + x;
                                count[x]--;
                            }
                        }

                        ans[n] = '\0';
                        return ans;
                    }

                    k--;
                }

                free(ans);
                return "";
            }

            ans[i] = 'a' + j;
            count[j]--;

            /* Fill the remaining characters in smallest order */
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

    /* s itself can only produce target, not something greater */
    free(ans);
    return "";
}