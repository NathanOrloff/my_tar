#ifndef __OPTPARSE_H__
#define __OPTPARSE_H__

typedef struct Options {
	char *archive_name;
	char **filepaths;
	int file_count;
	int cflag;
	int xflag;
	int tflag;
	int hflag;
} Options;

Options parse(int argc, char *argv[]);
int validate_options(Options opts);

#endif // __OPTPARSE_H__
