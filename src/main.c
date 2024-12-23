#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../include/constants.h"
#include "../include/hash.h"

enum hash_type {
  LM = 1,
  NTLM,
  MD2,
  MD4,
  MD5,
  SHA1,
  SHA224,
  SHA256,
  SHA384,
  SHA512
};
const char *hash_names[] = {"null",   "LM",     "NTLM",  "MD2",
                            "MD4",    "MD5",    "SHA1",  "SHA224",
                            "SHA256", "SHA384", "SHA512"};
struct input {
  char *hash_path;
  char *wordlist_path;
  enum hash_type hash_type;
};

void print_help(char *argv[]);
void end_program(int error_code, char *argv[]);
void bruteforce(FILE *hash_file, FILE *wordlist_file, int hash_type);

int main(int argc, char *argv[]) {
  struct input input;
  int option;

  FILE *hash_file;
  FILE *wordlist_file;

  if (argc < 7) {
    print_help(argv);
    return 1;
  }

  while ((option = getopt(argc, argv, ":w:i:h:")) != EOF) {
    switch (option) {
    case '?':
      print_help(argv);
      break;
    case 'w':
      input.wordlist_path = optarg;
      break;
    case 'i':
      input.hash_path = optarg;
      break;
    case 'h':
      input.hash_type = atoi(optarg);
      break;
    case ':':
      print_help(argv);
      break;
    }
  }

  for (; optind < argc; optind++) {
    end_program(INVALID_INPUT, argv);
  }

  hash_file = fopen(input.hash_path, "r");
  wordlist_file = fopen(input.wordlist_path, "r");

  if (hash_file == NULL) {
    end_program(INVALID_HASH_FILE, argv);
  } else if (wordlist_file == NULL) {
    end_program(INVALID_WORDLIST_FILE, argv);
  } else if (input.hash_type < 1 || input.hash_type > NUM_HASH_TYPES) {
    end_program(INVALID_HASH_TYPE, argv);
  } else {
    bruteforce(hash_file, wordlist_file, input.hash_type);
  }

  fclose(hash_file);
  fclose(wordlist_file);
  return 0;
}

void print_help(char *argv[]) {
  printf("Usage: %s -w <wordlist> -i <hashfile> -h <hashtype>\n", argv[0]);
  printf("Options:\n");
  printf("  -w <wordlist>    Specify wordlist file path\n");
  printf("  -i <hashfile>    Specify hash file path\n");
  printf("  -h <hashtype>    Specify hash type (1-10)\n");
  printf("  -help            Display this help message\n");
  exit(0);
}

void end_program(int error_code, char *argv[]) {
  switch (error_code) {
  case -1:
    printf("Invalid hash file\n");
    break;
  case -2:
    printf("Invalid wordlist file\n");
    break;
  case -3:
    printf("Invalid hash type\n");
    break;
  case -4:
    printf("Invalid command line arguments provided\n");
    break;
  }

  print_help(argv);
  exit(0);
}

void bruteforce(FILE *hash_file, FILE *wordlist_file, int hash_type) {
  char word[MAX_STRING_LENGTH];
  char hash[MAX_STRING_LENGTH];
  int found = FALSE;
  switch (hash_type) {
  case LM:
    hash_lm(hash_file, wordlist_file, word, hash, found);
    break;
  case NTLM:
    hash_ntlm(hash_file, wordlist_file, word, hash, found);
    break;
  case MD2:
    hash_md2(hash_file, wordlist_file, word, hash, found);
    break;
  case MD4:
    hash_md4(hash_file, wordlist_file, word, hash, found);
    break;
  case MD5:
    hash_md5(hash_file, wordlist_file, word, hash, found);
    break;
  case SHA1:
    hash_sha1(hash_file, wordlist_file, word, hash, found);
    break;
  case SHA224:
    hash_sha224(hash_file, wordlist_file, word, hash, found);
    break;
  case SHA256:
    hash_sha256(hash_file, wordlist_file, word, hash, found);
    break;
  case SHA384:
    hash_sha384(hash_file, wordlist_file, word, hash, found);
    break;
  case SHA512:
    hash_sha512(hash_file, wordlist_file, word, hash, found);
    break;
  default:
    printf("Unknown hash type: %d\n", hash_type);
    return;
  }
}