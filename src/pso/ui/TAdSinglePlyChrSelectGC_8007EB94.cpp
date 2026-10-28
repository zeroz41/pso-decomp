#include "types.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/misc/TQuestVmDownLoadServer.h"

extern "C" {

int xmalloc__FUl(void*);
s32 xfree__FPv();

}

void *operator new(size_t size) { return (void *)xmalloc__FUl((void *)size); }

extern "C" {
void TAdSinglePlyChrSelectGC::safe_free(u32 arg0) {
    if (arg0 != 0U) {
        xfree__FPv();
    }
}

}
