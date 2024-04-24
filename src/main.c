#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

enum hash_type {LM, NTLM, MD2, MD4, MD5, SHA1, SHA224, SHA256, SHA384, SHA512};
const char *hash_names[] = {"LM", "NTLM", "MD2", "MD4", "MD5", "SHA1", "SHA224", "SHA256", "SHA384", "SHA512"};

void print_help();

int main(int argc, char *argv[])
{
    int option;
    char *hash_path = "";
    char *wordlist_path = "";
    enum hash_type hash_type;

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
            wordlist_path = optarg;
            printf("Wordlist: %s\n", wordlist_path);
            break;
        case 'i':
            hash_path = optarg;
            printf("Hash: %s\n", hash_path);
            break;
        case 'h':
            hash_type = atoi(optarg);
            printf("Hash type: %s\n", hash_names[hash_type]);
            break;
        case 'f':
            printf("filename : %s\n", optarg);
            break;
        case ':':
            printf("Option -%c requires an argument\n", optopt);
            print_help();
            break;
        }
    }

    for(; optind < argc; optind++){
    	printf("extra arguments: %s\n", argv[optind]);
    }

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