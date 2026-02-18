#ifndef __CREATE_H__
#define __CREATE_H__

#define HEADER_SIZE 512
#define BLOCK_SIZE 512


int create_archive(char *archive_name, char **filepaths, int file_count);

#endif // __CREATE_H__
