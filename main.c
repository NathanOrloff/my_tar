#include <stdio.h>
#include <stdlib.h>

#include "optparse.h"
#include "create.h"

void print_help();

	
int main(int argc, char *argv[]) {
	int err = 0;
	Options opts = parse(argc, argv);
	err = validate_options(opts);
	if (err != 0) {
		fprintf(stderr, "Error invalid options\n");
		goto FINALLY;
	}

	if (opts.hflag) {
		print_help();
	}
	else if (opts.cflag) {
		err = create_archive(opts.archive_name, opts.filepaths, opts.file_count);
		if (err != 0) {
			fprintf(stderr, "Error creating archive: %s\n", opts.archive_name);
			goto FINALLY;
		}
	}
	else if (opts.xflag) {

	}
	else if (opts.tflag) {
	
	}
	else {
		print_help();
	}

FINALLY:
	free(opts.filepaths);
	return err;
}


/* help:
 *
 * prints help message for user
 * */
void print_help() {
	printf("Usage: tar [OPTION...] [FILE]...\n");
	printf("'my_tar' saves many files together into a single tape or disk archive\n\n");
	printf("Main operation mode:\n");
	printf("\t-c, --create               create a new archive\n");
	printf("\t-t, --list                 list the contents of an archive\n");
	printf("\t-x, --extract              extract files from an archive\n");
	return;
}

