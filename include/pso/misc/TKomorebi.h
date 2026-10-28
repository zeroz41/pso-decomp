#ifndef PSO_MISC_TKOMOREBI_H
#define PSO_MISC_TKOMOREBI_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TKomorebi : public TObjBase {
    virtual ~TKomorebi();
    virtual void render();
    virtual void run_task();
    static void free_static();
    static void load_resources();
};

typedef char TKomorebi_size[sizeof(TKomorebi) == 0x90 ? 1 : -1];

extern "C" {
void *TKomorebi__create(void *arg0);
u8 *TKomorebi__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__dt__9TKomorebiFv(void *arg0, s16 arg1);
}

#endif
