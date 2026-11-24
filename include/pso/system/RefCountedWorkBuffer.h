#ifndef PSO_SYSTEM_REFCOUNTEDWORKBUFFER_H
#define PSO_SYSTEM_REFCOUNTEDWORKBUFFER_H

#include "types.h"

extern "C" {
void ref_counted_work_buffer_init(void);
void ref_counted_work_buffer_finish(void);
}

#endif
