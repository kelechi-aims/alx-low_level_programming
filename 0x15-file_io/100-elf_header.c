#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <elf.h>

/**
 * main - displays the information contained in the ELF header
 * at the start of an ELF file
 * @argc: argument counter
 * @argv: argument vector
 */
int main(int argc, char *argv)
