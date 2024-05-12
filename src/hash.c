#include <stdio.h>
#include <string.h>

#include "constants.h"

void hash_lm(FILE *hash_file, FILE *wordlist_file, char word[MAX_STRING_LENGTH],
             char hash[MAX_STRING_LENGTH], int found) {
    while (fgets(word, MAX_STRING_LENGTH, wordlist_file) != NULL &&
           found == FALSE) {
        word[strcspn(word, "\n")] = '\0';
        printf("%s\n", word);
    }
    return;
}

void hash_ntlm(FILE *hash_file, FILE *wordlist_file,
               char word[MAX_STRING_LENGTH], char hash[MAX_STRING_LENGTH],
               int found) {
    return;
}

void hash_md2(FILE *hash_file, FILE *wordlist_file,
              char word[MAX_STRING_LENGTH], char hash[MAX_STRING_LENGTH],
              int found) {
    return;
}

void hash_md4(FILE *hash_file, FILE *wordlist_file,
              char word[MAX_STRING_LENGTH], char hash[MAX_STRING_LENGTH],
              int found) {
    return;
}

void hash_md5(FILE *hash_file, FILE *wordlist_file,
              char word[MAX_STRING_LENGTH], char hash[MAX_STRING_LENGTH],
              int found) {
    return;
}

void hash_sha1(FILE *hash_file, FILE *wordlist_file,
               char word[MAX_STRING_LENGTH], char hash[MAX_STRING_LENGTH],
               int found) {
    return;
}

void hash_sha224(FILE *hash_file, FILE *wordlist_file,
                 char word[MAX_STRING_LENGTH], char hash[MAX_STRING_LENGTH],
                 int found) {
    return;
}

void hash_sha256(FILE *hash_file, FILE *wordlist_file,
                 char word[MAX_STRING_LENGTH], char hash[MAX_STRING_LENGTH],
                 int found) {
    return;
}

void hash_sha384(FILE *hash_file, FILE *wordlist_file,
                 char word[MAX_STRING_LENGTH], char hash[MAX_STRING_LENGTH],
                 int found) {
    return;
}

void hash_sha512(FILE *hash_file, FILE *wordlist_file,
                 char word[MAX_STRING_LENGTH], char hash[MAX_STRING_LENGTH],
                 int found) {
    return;
}
