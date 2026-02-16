#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

#include "optparse.h"

static struct option long_options[] = {
	{"file", required_argument, NULL, 'f'},
	{"create", no_argument, NULL, 'c'},
	{"extract", no_argument, NULL, 'x'},
	{"list", no_argument, NULL, 't'},
	{"help", no_argument, NULL, 'h'},
	{0, 0, 0, 0}
};


/* parse:
 *
 * parses user inputs into struct
 * 
 * input: argc and arcv
 * output: options struct
 * */
Options parse(int argc, char *argv[]) {
	Options opts;
	int option_index = 0;
	int c;
	while((c = getopt_long(argc, argv, "f:cxth", long_options, &option_index)) != -1) {
		switch (c) {
			case 'f':
				opts.archive_name = optarg;
				break;
			case 'c':
				opts.cflag = 1;
				break;
			case 'x':
				opts.xflag = 1;
				break;
			case 't':
				opts.tflag = 1;
				break;
			case 'h':
				opts.hflag = 1;
				break;
		}
	}

	int i = 0;
	while (optind < argc && i < 10) {
		opts.filepaths[i++] = argv[optind++];
	}
	opts.file_count = i;

	return opts;
}


/* help:
 *
 * prints help message for user
 * */
void help() {

}
