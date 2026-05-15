#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/cdefs.h>

//strspn
size_t STRSPN_TEST(const char *str, const char *accept) {
	//Only accepts chars; not null.
	if (accept[0] == '\0')
		return 0;
	// Suponiendo que accept es un caracter como a, b, c... n. Por ello [1] es \0.
	if (__glibc_unlikely(accept[1] == '\0')) {
		const char* a = str;
		for(; *str == *accept;str++);
		// Esto es una operadores de punteros. TODO: Debo aprender de ello.
		return str - a;
	}

	// I had seen it in leetcode. I think it was somenthing like
	// [ord('a') - ord('a')]... I do not remember. But it was somenthing like that
	unsigned char table[256];
	unsigned char*p = memset(table, 0, 64);
	memset(p + 64, 0, 64);
	memset(p + 128, 0, 64);
	memset(p + 192, 0, 64);

	unsigned char *s = (unsigned char *) accept;

	do {
		p[*s++] = 1;
	} while(*s);

	//Why does it return 0,1,2,3?
	//Loop unrolling. Never thought about it and its optimization. Damn.
	s = (unsigned char *) str;
	if (!p[s[0]]) return 0;
	if (!p[s[1]]) return 1;
	if (!p[s[2]]) return 2;
	if (!p[s[3]]) return 3;


}

char* hello(char *restrict s, const char *restrict delim, char **restrict save_ptr) {
	char c = '\0';
	char *end = &c;
	return NULL;
} 
int main(int argc, char *argv[])
{	
	int arr[] = {10,0};
	int *ptr = arr;

	if (!ptr[1]) printf("Hola mund\n");


	return 0;
}
