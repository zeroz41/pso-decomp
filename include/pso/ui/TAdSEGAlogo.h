#ifndef PSO_UI_TADSEGALOGO_H
#define PSO_UI_TADSEGALOGO_H

#include "pso/TObject.h"
#include "types.h"

class TAdSEGAlogo : public TObject {
public:
    virtual void render();
    virtual ~TAdSEGAlogo();
    virtual void run_task();
public:
    static void destroy_and_mark_done();
    static void request_destroy();
};

extern "C" {
void *__ct__11TAdSEGAlogoFv(void *ad_seg_alogo);
}

#endif
