#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define INVALID_HASH_FILE -1
#define INVALID_WORDLIST_FILE -2
#define INVALID_HASH_TYPE -3
#define INVALID_INPUT -4

#define NUM_HASH_TYPES 10

enum hash_type {LM = 1, NTLM, MD2, MD4, MD5, SHA1, SHA224, SHA256, SHA384, SHA512};
const char *hash_names[] = {"null", "LM", "NTLM", "MD2", "MD4", "MD5", "SHA1", "SHA224", "SHA256", "SHA384", "SHA512"};
struct input {
    char *hash_path;
    char *wordlist_path;
    enum hash_type hash_type;
};

void print_help();
void end_program(int error_code);

int main(int argc, char *argv[]) {
    struct input input;
    int option;
    
    FILE *hash_file;
    FILE *wordlist_file;

    if (argc == 1) {
        print_help();
        return 0;
    }

    while ((option = getopt(argc, argv, ":w:i:h:")) != EOF) {
        switch (option) {
            case '?':
                printf("Unknown option: %c\n", optopt);
                print_help();
                break;
            case 'w':
                input.wordlist_path = optarg;
                printf("Wordlist: %s\n", input.wordlist_path);
                break;
            case 'i':
                input.hash_path = optarg;
                printf("Hash: %s\n", input.hash_path);
                break;
            case 'h':
                input.hash_type = atoi(optarg);
                printf("Hash type: %s\n", hash_names[input.hash_type]);
                break;
            case ':':
                printf("Option -%c requires an argument\n", optopt);
                print_help();
                break;
        }
    }

    for(; optind < argc; optind++) {
        end_program(INVALID_INPUT);
    }

    hash_file = fopen(input.hash_path, "r");
    wordlist_file = fopen(input.wordlist_path, "r");

    if (hash_file == NULL) {
        end_program(INVALID_HASH_FILE);
    } else if (wordlist_file == NULL) {
        end_program(INVALID_WORDLIST_FILE);
    } else if (input.hash_type < 1 || input.hash_type > NUM_HASH_TYPES) {
        end_program(INVALID_HASH_TYPE);
    } else {
        bruteforce(hash_file, wordlist_file, input.hash_type);
    }


    fclose(hash_file);
    fclose(wordlist_file);
    return 0;
}

void print_help() {
    printf("Usage: ./main -w <wordlist> -i <hashfile> -h <hashtype>\n");
    printf("Options:\n");
    printf("  -w <wordlist>    Specify wordlist file path\n");
    printf("  -i <hashfile>    Specify hash file path\n");
    printf("  -h <hashtype>    Specify hash type (0-9)\n");
    printf("  -help            Display this help message\n");
    exit(0);
}

void end_program(int error_code) {
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

    print_help();
    exit(0);
}

void bruteforce(FILE *hash_file, FILE *wordlist_file, int hash_type) {
    // function implmentation

    return;
}