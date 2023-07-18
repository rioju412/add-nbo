#include <stdio.h>
#include <stdint.h>
#include <byteswap.h>

uint32_t swap_byte(uint32_t n) {
	
    uint32_t result = bswap_32(n);
    return result;
}


uint32_t read_byte(const char* filename) {
	
	FILE* file = fopen(filename, "rb");

	if (file == NULL) {
		perror("Can't open file");
	}

	uint32_t readData;
	fread(&readData, sizeof(readData), 1, file);
	fclose(file);

	return swap_byte(readData);

}

int main(int argc, char* argv[]) {

	const char* filename1 = argv[1];
	const char* filename2 = argv[2];

	uint32_t n1 = read_byte(filename1);
	uint32_t n2 = read_byte(filename2);

	printf("%d(0x%02x) + %d(0x%02x) = %d(0x%02x)\n", n1, n1, n2, n2, n1+n2, n1+n2);
	return 0;
}

