#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_INPUT_STRING_LENGTH 128
#define MAX_WORD_LENGTH 32
#define WORD_DELIMITER " "


static char *dealWithWord(char *word)
{
    char *new_word = calloc(MAX_WORD_LENGTH, sizeof(char));
    int len = strlen(word);
    int i = 0;

    strcpy(new_word, word+1);
    i = len - 1;
    while(ispunct(word[i])) {
        i--;
    }
    new_word[i] = word[0];
    new_word[i+1] = 'a';
    new_word[i+2] = 'y';
    for(; i<len-1; i++) {
        new_word[i+3] =  word[i+1];
    }
            /* if (ispunct(word[len-1])) {
       new_word[len-2] = word[0];
        strcat(new_word, SUFFIX);
        new_word[len+1] = word[len-1];
    } else {
        new_word[len-1] = word[0];
        strcat(new_word, SUFFIX);
        }*/

    return new_word;
}


char *translatePigLatin(char *str)
{
    char *word;
    char *new_word;
    char *new_str = calloc(MAX_INPUT_STRING_LENGTH, sizeof(char));

    word = strtok(str, WORD_DELIMITER);
    while (word != NULL) {
        new_word = dealWithWord(word);
        strcat(new_str, new_word);
        free(new_word);
        word = strtok(NULL, WORD_DELIMITER);
        if (word != NULL) {
            strcat(new_str, " ");
        }
    }

    return new_str;
}


int main()
{
    char str[MAX_INPUT_STRING_LENGTH] = {0};
    char *piglatin_str;

    fgets(str, MAX_INPUT_STRING_LENGTH, stdin);
    str[strcspn(str, "\n")] = 0;
    piglatin_str = translatePigLatin(str);
    printf("%s\n", piglatin_str);
    free(piglatin_str);

    return 0;
}
