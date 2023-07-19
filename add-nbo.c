#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

uint32_t read_int_from_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    uint32_t integer;

    if (file == NULL) {
        printf("Error: cannot open file [%s]\n", file_path);
        return 0;
    }

    fread(&integer, sizeof(uint32_t), 1, file);
    fclose(file);

    return ntohl(integer);
}

int main(int argc, char *argv[]) {
    uint32_t int1 = read_int_from_file(argv[1]);
    uint32_t int2 = read_int_from_file(argv[2]);

    uint32_t result = int1 + int2;
    printf("Sum : %u\n", result);

    return 0;
}

