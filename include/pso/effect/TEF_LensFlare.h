#ifndef PSO_MISC_TEF_LENSFLARE_H
#define PSO_MISC_TEF_LENSFLARE_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TEF_LensFlare : public TObjBase {
    virtual ~TEF_LensFlare();
    virtual void render();
    virtual void run_task();
    int is_player_near(f32 farg0);
    u8 unk_90[0x4];
};

typedef char TEF_LensFlare_size[sizeof(TEF_LensFlare) == 0x94 ? 1 : -1];
#endif
