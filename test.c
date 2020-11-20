#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 20

/*void Foo()
{
	printf("%d\n", BUFFER_SIZE);
} */

void	foo(char *ptr[], int size)
{
	int i = 0;

	while (size--)
	{
		ptr[i] = 0;
		i++;
	}
}

int main()
{
	char *buf1[BUFFER_SIZE];
	char buf2[BUFFER_SIZE];
	/*int fd1 = open("/Users/dchani/21/get_next_line/file1", O_RDONLY);
	//int fd2 = open("/Users/dchani/21/get_next_line/file2", O_RDONLY);
//	foo(buf1, BUFFER_SIZE);
	read(fd1, buf1, 20);
	read(fd1, buf2, 20);
	//read(fd1, buf1, 10);
	printf("Hello"); */
	buf1[3] = (char*)malloc(3);
}
