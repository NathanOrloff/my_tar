#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "create.h"


int process_file(FILE *fptr, char *filepath);
int generate_header(char *filepath, unsigned char *header);
int generate_body(FILE *fptr, char *filepath);


int create_archive(char *archive_name, char **filepaths, int file_count) {
	FILE *fptr;
	int err = 0;
	fptr = fopen(archive_name, "w");
	if (fptr == NULL) {
		fprintf(stderr, "Error creating file: %s\n", archive_name);
		return -1;
	}
	for (int i = 0; i < file_count; i++) {
		err = process_file(fptr, filepaths[i]);
		if (err != 0) {
			fprintf(stderr, "Error processing: %s\n", filepaths[i]);
			goto FINALLY;
		}
	}

FINALLY:
	fclose(fptr);
	return err;
}

int process_file(FILE *fptr, char *filepath) {
	int err = 0;
	unsigned char header[HEADER_SIZE] = {0};
	
	err = generate_header(filepath, &header);
	if (err != 0) {
		fprintf(stderr, "Error generating header for: %s\n", filepath);
		return -1;
	}

	size_t written = fwrite(&header, sizeof(unsigned char), HEADER_SIZE, fptr);
	if (written < HEADER_SIZE) {
		fprintf(stderr, "Error writing header to archive for file: %s\n", filepath);
		return -1;
	}

	err = generate_body(fptr, filepath);
	if (err != 0) {
		fprintf(stderr, "Error generating body for: %s\n", filepath);
		return -1;
	}

	return 0;
}

int generate_header(char *filepath, unsigned char *header) {
	return 0;
}

int generate_body(FILE *fptr, char *filepath) {
	return 0;
}

int generate_end_code() {

}

int fill_name() {

}

int fill_file_mode() {

}

int fill_user_id() {

}

int fill_group_id() {

}

int fill_file_size() {

}

int fill_mtime() {

}

int fill_checksum() {

}

int fill_type_flag() {

}

int fill_linkname() {

}

int fill_magic() {

}

int fill_version() {

}

int fill_uname() {

}

int fill_gname() {

}

int fill_devmajor() {

}

int fill_devminor() {

}

int fill_prefix() {

}

int fill_body() {

}
