#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "constants.h"

void hash_lm(FILE *hash_file, FILE *wordlist_file, char word[MAX_STRING_LENGTH],
             char hash[MAX_STRING_LENGTH], int found);

void hash_ntlm(FILE *hash_file, FILE *wordlist_file,
               char word[MAX_STRING_LENGTH], char hash[MAX_STRING_LENGTH],
               int found);

void hash_md2(FILE *hash_file, FILE *wordlist_file,
              char word[MAX_STRING_LENGTH], char hash[MAX_STRING_LENGTH],
              int found);

void hash_md4(FILE *hash_file, FILE *wordlist_file,
              char word[MAX_STRING_LENGTH], char hash[MAX_STRING_LENGTH],
              int found);

void hash_md5(FILE *hash_file, FILE *wordlist_file,
              char word[MAX_STRING_LENGTH], char hash[MAX_STRING_LENGTH],
              int found);

void hash_sha1(FILE *hash_file, FILE *wordlist_file,
               char word[MAX_STRING_LENGTH], char hash[MAX_STRING_LENGTH],
               int found);

void hash_sha224(FILE *hash_file, FILE *wordlist_file,
                 char word[MAX_STRING_LENGTH], char hash[MAX_STRING_LENGTH],
                 int found);

void hash_sha256(FILE *hash_file, FILE *wordlist_file,
                 char word[MAX_STRING_LENGTH], char hash[MAX_STRING_LENGTH],
                 int found);

void hash_sha384(FILE *hash_file, FILE *wordlist_file,
                 char word[MAX_STRING_LENGTH], char hash[MAX_STRING_LENGTH],
                 int found);

void hash_sha512(FILE *hash_file, FILE *wordlist_file,
                 char word[MAX_STRING_LENGTH], char hash[MAX_STRING_LENGTH],
                 int found);