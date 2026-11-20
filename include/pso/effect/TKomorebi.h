#ifndef PSO_EFFECT_TKOMOREBI_H
#define PSO_EFFECT_TKOMOREBI_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TKomorebi : public TObjBase {
    TKomorebi(TObject *parent, s32 arg2);
    virtual ~TKomorebi();
    virtual void render();
    virtual void run_task();
    static void free_static();
    static void load_resources();
};

typedef char TKomorebi_size[sizeof(TKomorebi) == 0x90 ? 1 : -1];

extern "C" {
void *TKomorebi__create(void *arg0);
void *__dt__9TKomorebiFv(void *arg0, s16 arg1);
}

#endif
