#ifndef PSO_UI_TADBACKTXTGC_H
#define PSO_UI_TADBACKTXTGC_H

#include "pso/TObject.h"
#include "types.h"

class TAdBackTxtGC : public TObject {
public:
    virtual ~TAdBackTxtGC();
    void draw_character_background_frame(s32, s32);
    virtual void render();
    virtual void run_task();
};

class TAdBackTxtGC;
extern "C" {
void *__ct__12TAdBackTxtGCFv(void *arg0);
void register_texture_f256_backtext(void);
void render__12TAdBackTxtGCFv(TAdBackTxtGC *arg0);
void run_task__12TAdBackTxtGCFv(void *arg0);
}

#endif
