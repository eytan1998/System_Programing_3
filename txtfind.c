#include <stdio.h>
#include <string.h>

int getLine(char s[]);

int getWord(char w[]);

int subString(char *str1, char *str2);

int similar(char *s, char *t, int n);

void print_lines(char *str);

void print_similar_words(char *str);

#define LINE 256
#define WORD 30
#define MAX_ROWS 250

#define TRUE 1
#define FALSE 0

int main() {
    char word[WORD];
    getWord(word);
    char choice;
    scanf(" %c", &choice);
    switch (choice) {
        case 'a':
            print_lines(word);
            break;
        case 'b':
            print_similar_words(word);
            break;
        default:
            break;
    }
    return 0;
}

int getLine(char s[]) {
    int i;
    char c;
    for (i = 0; i < LINE; ++i) {
        c = getchar();
        s[i] = c;
        //if the c is end of file check if is word or not
        if (c == EOF) {
            //false mean no more word to read
            if (i == 0) return FALSE;
            s[i] = '\n';
            break;
        }
        //if end of line
        if (c == '\n') {
            break;
        }
    }
    //to preserve the /n
    //i+1 in array bound because i<LINE and s is [LINE+1]
    s[i + 1] = '\0';
    return TRUE;
}

int getWord(char w[]) {
    int i;
    char c;
    for (i = 0; i < WORD; ++i) {
        c = getchar();
        w[i] = c;
        //if the c is end of file check if is word or not
        if (c == EOF) {
            //false mean no more word to read
            if (i == 0) return FALSE;
            break;
        }
        //if word ended
        if (w[i] == '\n'
            || w[i] == '\t'
            || w[i] == ' ')
            break;

    }
    //mark end of string for the string function to work
    w[i] = '\0';
    return TRUE;
}

int subString(char *str1, char *str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    //to simplify that str1 is smaller or equal to str2 (len2-len1+1)
    //if not swap them
    if (len1 > len2) {
        char *tmp = str2;
        str2 = str1;
        str1 = tmp;
        len1 = strlen(str1);
        len2 = strlen(str2);
    }
    //guaranteed str1 < str2
    //check if equal (like bubble)
    for (int i = 0; i < len2 - len1 + 1; ++i) {
        if (strncmp(str1, str2 + i, len1) == 0) return TRUE;
    }
    return FALSE;
}

int similar(char *s, char *t, int n) {
    //like marge
    int i = 0;
    int j = 0;
    size_t lens = strlen(s);
    size_t lent = strlen(t);

    //to simplify that s is smaller or equal to t (to know who to advance if not equal)
    //if not swap them
    if (lens > lent) {
        char *tmp = s;
        s = t;
        t = tmp;
        lens = strlen(s);
        lent = strlen(t);
    }
    //advance j because t is the larger string
    while (i < lens && j < lent) {
        if (s[i] != t[j++]) {
            //if not equal reduce the margin error
            n--;
            if (n < 0) return FALSE;
        } else i++;
    }
    //if tail is large then the margin error -> fail
    if (lens - i > n) return FALSE;
    if (lent - j > n) return FALSE;

    return TRUE;

}

void print_lines(char *str) {
    //cannot be more than max row
    for (int i = 0; i < MAX_ROWS; ++i) {
        char newLine[LINE + 1];
        //if false = eof
        if (getLine(newLine) == FALSE) break;
        //if is sub string -> print the line
        if (subString(newLine, str) == TRUE) printf("%s", newLine);
    }
}

void print_similar_words(char *str) {
    //cannot be more words than line length and max line number
    for (int i = 0; i < LINE*MAX_ROWS; ++i) {
        char newWord[WORD+1];
        //if false = eof
        if (getWord(newWord) == FALSE) break;
        //if the words similar -> print the word
        if (similar(newWord, str, 1) == TRUE) printf("%s\n", newWord);
    }
}

