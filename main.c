#include <stdio.h>
#include <stdlib.h>

#include "optparse.h"
#include "create.h"

int main(int argc, char *argv[]) {
	int err = 0;
	Options opts = parse(argc, argv);
	
	printf("file: %s\n", opts.archive_name);
	printf("cflag: %d\n", opts.cflag);
	printf("xflag: %d\n", opts.xflag);
	printf("tflag: %d\n", opts.tflag);
	printf("hflag: %d\n", opts.hflag);

	for (int i = 0; i < opts.file_count; i++) {
		printf("target: %s\n", opts.filepaths[i]);
	}

	err = create_archive(opts.archive_name, opts.filepaths, opts.file_count);
	if (err != 0) {
		fprintf(stderr, "Error creating archive: %s\n", opts.archive_name);
		goto FINALLY;
	}


FINALLY:
	free(opts.filepaths);
	return err;
}
