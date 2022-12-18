#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30

int getLine(char s[]);

int getWord(char w[]);

int subString(char *str1, char *str2);

int similar(char *s, char *t, int n);

void print_lines(char *str);

void print_similar_words(char *str);

int main() {
    char word[WORD];
    getWord(word);
    char choise;
    scanf(" %c", &choise);
    getchar();
    getchar();
    switch (choise) {
        case 'a':
//            printf("%d\n",subString("looking for the word cat",word));

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
        if (c == EOF) {
            s[0]=0;
            return 0;
        }
        if (c == '\n') break;
    }
    s[i + 1] = '\0';
    return i + 1;
}

int getWord(char w[]) {
    int i;
    char c;
    for (i = 0; i < WORD; ++i) {
        c = getchar();
        w[i] = c;

        if (c == EOF) {
            w[0]=0;
            return 0;
        }
        if (w[i] == '\n'
            || w[i] == '\t'
            || w[i] == ' ')
            break;

    }
    w[i] = '\0';
    return i;
}

int subString(char *str1, char *str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    if (len1 > len2) {
        char *tmp = str2;
        str2 = str1;
        str1 = tmp;
        len1 = strlen(str1);
        len2 = strlen(str2);
    }
    //len 1 < len 2
    for (int i = 0; i < len2 - len1 + 1; ++i) {
        if (strncmp(str1, str2 + i, len1) == 0) return 1;

    }
    return 0;
}

int similar(char *s, char *t, int n) {
    int i = 0;
    int j = 0;
    size_t lens = strlen(s);
    size_t lent = strlen(t);

    //s>t
    while (i < lens && j < lent) {
        if (s[i++] != t[j]) {
            n--;
            if (n < 0) return 0;
        } else j++;
    }
    if (lens - i > n) return 0;
    if (lent - j > n) return 0;

    return 1;

}

void print_lines(char *str) {

    while (1) {
        char newLine[LINE];
        getLine(newLine);
//        printf("debug: %s\n", newLine);
        if (strlen(newLine)== 0) break;
        if (subString(newLine, str) == 1)printf("%s", newLine);
    }
}

void print_similar_words(char *str) {
    while (1) {
        char newWord[WORD];
        getWord(newWord);
        if (strlen(newWord) == 0) break;
        if (similar(newWord, str, 1) == 1)printf("%s\n", newWord);
    }
}


