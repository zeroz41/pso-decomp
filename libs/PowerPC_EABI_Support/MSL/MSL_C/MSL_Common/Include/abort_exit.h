#ifndef _MSL_COMMON_ABORT_EXIT_H
#define _MSL_COMMON_ABORT_EXIT_H

#ifdef __cplusplus
extern "C" {
#endif

void exit(int status);
void abort(void);
void _ExitProcess(void);

extern void (*__stdio_exit)(void);

#ifdef __cplusplus
};
#endif

#endif
