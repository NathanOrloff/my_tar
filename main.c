#include <stdio.h>
#include <stdlib.h>

#include "optparse.h"

int main(int argc, char *argv[]) {
	Options opts = parse(argc, argv);
	
	printf("file: %s\n", opts.archive_name);
	printf("cflag: %d\n", opts.cflag);
	printf("xflag: %d\n", opts.xflag);
	printf("tflag: %d\n", opts.tflag);
	printf("hflag: %d\n", opts.hflag);

	for (int i = 0; i < opts.file_count; i++) {
		printf("target: %s\n", opts.filepaths[i]);
	}

	return 0;
}
