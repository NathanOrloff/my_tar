#ifndef __OPTPARSE_H__
#define __OPTPARSE_H__

typedef struct Options {
	char *archive_name;
	char *filepaths[10];
	int file_count;
	int cflag;
	int xflag;
	int tflag;
	int hflag;
} Options;

Options parse(int argc, char *argv[]);

#endif // __OPTPARSE_H__
