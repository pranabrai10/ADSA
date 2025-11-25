#include <stdio.h>
#include <string.h>

// Function to create LPS (Longest Prefix Suffix) array
void computeLPS(char pattern[], int m, int lps[]) {
    int len = 0;          // length of previous longest prefix suffix
    lps[0] = 0;           // lps[0] is always 0

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // try shorter prefix
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP search function
void KMPSearch(char pattern[], char text[]) {
    int m = strlen(pattern);
    int n = strlen(text);

    int lps[m];
    computeLPS(pattern, m, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern

    printf("\nPattern found at positions: ");

    int found = 0;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("%d ", i - j);
            found = 1;
            j = lps[j - 1];
        }

        else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];   // use LPS to avoid re-check
            else
                i++;
        }
    }

    if (!found)
        printf("No match found.");
}

int main() {
    char text[200], pattern[100];

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';   // remove newline

    printf("Enter the pattern to search: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0';

    KMPSearch(pattern, text);

    return 0;
}
