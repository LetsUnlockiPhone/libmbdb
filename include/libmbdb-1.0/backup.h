/**
  * libmbdb-1.0 - backup_file.h
  * Copyright (C) 2013 Crippy-Dev Team
  * Copyright (C) 2010-2013 Joshua Hill
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#ifndef BACKUP_H_
#define BACKUP_H_

#include "backup_file.h"
#include "mbdb.h"

typedef struct backup_t {
	char* path;
	//mbdx_t* mbdx;
	mbdb_t* mbdb;
	/*plist_t info;
	plist_t status;
	plist_t manifest;
	backup_file_t** files;
	unsigned int count;
	unsigned char* udid;
	unsigned char* directory;*/
} backup_t;

backup_t* backup_open(const char* directory, const char* udid);
int backup_get_file_index(backup_t* backup, const char* domain, const char* path);
char* backup_get_file_path(backup_t* backup, backup_file_t* bfile);
backup_file_t* backup_get_file(backup_t* backup, const char* domain, const char* path);
int backup_update_file(backup_t* backup, backup_file_t* bfile);
int backup_remove_file(backup_t* backup, backup_file_t* bfile);
void backup_free(backup_t* backup);

int backup_get_num_files(backup_t* backup);
backup_file_t* backup_get_file_by_index(backup_t* backup, int index);
int backup_mkdir(backup_t * backup, char *domain, char *path, int mode, int uid, int gid, int flag);
int backup_symlink(backup_t * backup, char *domain, char *path, char *to, int uid, int gid, int flag);
int backup_add_file_from_path(backup_t * backup, char *domain, char *localpath, char *path, int mode, int uid, int gid, int flag);
int backup_add_file_from_data(backup_t * backup, char *domain, char *data, unsigned int size, char *path, int mode, int uid, int gid, int flag);

#endif /* BACKUP_H_ */
