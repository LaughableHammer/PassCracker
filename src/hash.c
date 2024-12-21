#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "../include/constants.h"

void hash_lm(FILE *hash_file, FILE *wordlist_file, char word[MAX_STRING_LENGTH],
             char hash[MAX_STRING_LENGTH], int found) {
  while (fgets(word, MAX_STRING_LENGTH, wordlist_file) != NULL &&
         found == FALSE) {
    word[strcspn(word, "\n")] = '\0';
    printf("Word: %s\n", word);

    // Make password uppercase
    for (int i = 0; i < strlen(word); i++) {
      word[i] = toupper(word[i]);
    }

    // Pad password so it is 14 characters long
    for (int i = strlen(word); i < 14; i++) {
      word[i] = 0;
    }

    // Split password into 2 strings
    char string1[8];
    char string2[8];

    strncpy(string1, word, 7);
    strncpy(string2, word + 7, 7);
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
