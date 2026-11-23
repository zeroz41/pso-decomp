#include "pso/system/ResourceFile.h"
#include "types.h"
#include "pso/unk/text_801A5778.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {
s32 load_gvpl_palette(void *, void *);
s32 DCStoreRange(void *, int);
void fn_801A5778(const char *filename, saddr *arg1) {
    u8 *temp_r3;
    temp_r3 = load_disc_file(filename);
    load_gvpl_palette(temp_r3, arg1);
    DCStoreRange((void *) (*arg1), 0x40000);
    TAdSinglePlyChrSelectGC::safe_free((saddr)temp_r3);
}

}
