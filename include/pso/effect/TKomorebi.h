#ifndef PSO_EFFECT_TKOMOREBI_H
#define PSO_EFFECT_TKOMOREBI_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TKomorebi : public TObjBase {
    virtual ~TKomorebi();
    virtual void render();
    virtual void run_task();
    static void free_static();
    static void load_resources();
};

LAYOUT_ASSERT(TKomorebi_size, sizeof(TKomorebi) == 0x90);

extern "C" {
void *TKomorebi__create(void *arg0);
u8 *TKomorebi__ct(u8 *arg0, saddr arg1, s32 arg2);
void *__dt__9TKomorebiFv(void *arg0, s16 arg1);
}

#endif
