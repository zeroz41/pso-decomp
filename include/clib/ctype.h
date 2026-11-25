#ifndef _CTYPE_H_
#define _CTYPE_H_

#ifdef __cplusplus
extern "C" {
#endif

int islower(int c);
int tolower(int c);
int toupper(int c);

extern unsigned char __upper_map[256];

#ifdef __cplusplus
}
#endif

#endif
