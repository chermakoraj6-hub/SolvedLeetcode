char* longestPalindrome(char* s) {
  int lenS = strlen(s);

    char *tmp = (char*)malloc(sizeof(char) * (2 * lenS + 2));
    int k = 0;
    tmp[k++] = '#';

    for (int i = 0; i < lenS; i++) {
        tmp[k++] = s[i];
        tmp[k++] = '#';
    }
    tmp[k] = '\0';

    int n = strlen(tmp);
    int *len = (int*)calloc(n, sizeof(int));
    int center = 0, right = 0;
    int maxLen = 0, maxCenter = 0;

    for (int i = 0; i < n; i++) {
        int mirror = 2 * center - i;

        if (i < right)
            len[i] = (right - i < len[mirror]) ? right - i : len[mirror];

        while (i - len[i] - 1 >= 0 && i + len[i] + 1 < n && 
               tmp[i - len[i] - 1] == tmp[i + len[i] + 1])
        {
            len[i]++;
        }

        if (i + len[i] > right) {
            center = i;
            right = i + len[i];
        }
        if (len[i] > maxLen) {
            maxLen = len[i];
            maxCenter = i;
        }
    }
    int start = (maxCenter - maxLen) / 2;
    char *result = (char*)malloc(maxLen + 1);
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';

    free(tmp);
    free(len);
    return result;
}  


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna