#ifndef __SD
#define __SD

int sd_init(void);
int sd_eject(void);
int read_file(const char* path);

#endif 