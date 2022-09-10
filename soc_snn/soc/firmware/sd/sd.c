#include "sd.h"
#include <stdio.h>
#include <liblitesdcard/sdcard.h>
#include <libfatfs/ff.h>			
#include <libfatfs/diskio.h>
#define SDCARD_DEBUG

static FATFS  fatfs;

int sd_init(void){
  	fatfs_set_ops_sdcard();
	FRESULT rc;
	TCHAR *Path = "0:/";
	rc = f_mount(&fatfs,Path,0);
	printf("=> %x\n", rc);
	if (rc) {
		printf(" ERROR : f_mount returned %d\r\n", rc);
		return 0;
	}
	return 1;
}

int sd_eject(void){
  	fatfs_set_ops_sdcard();
	FRESULT rc;
	TCHAR *Path = "0:/";
	rc = f_mount(0,Path,1);
	if (rc){
		printf(" ERROR : f_mount returned %d\r\n", rc);
		return 0;
	}
	return 1;
}

void show_SD_info(void){
  sdcard_decode_cid();
  sdcard_decode_csd();
}

int read_file(const char* path, char* data) {
  	
	fatfs_set_ops_sdcard();
	UINT* br;
	FIL fptr[1];
	FRESULT op = f_open(fptr, path, FA_READ);
	printf("%d", fptr->obj.objsize);

	if (op != FR_OK){
		printf("Could not open file: %s\n", path);
		return 0;
	}

	if (fptr->obj.objsize == 0){
		return 0;
	}

	char buff[fptr->obj.objsize + 1];

	f_read(fptr, (void*) buff, fptr->obj.objsize, br);

 	printf("Successfully read file: %s\n", path);
	// printf("text: %s\n", buff);
	f_close(fptr);

  	data = buff;
  
	return 1;
}


void read_line(const char* path){
	fatfs_set_ops_sdcard();
	FIL fptr[1];
	FRESULT op = f_open(fptr, path, FA_READ);
	char string[93];
	char var[93];
	int index = 93;
	while ((f_eof(fptr) == 0)){
		f_gets((char*)string, sizeof(string), fptr);// read current line
		f_lseek(fptr, index);// move to the next line
		index = index + 93;
		printf("%s\n", string);
	}
}