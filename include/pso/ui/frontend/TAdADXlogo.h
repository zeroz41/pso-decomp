#ifndef PSO_UI_FRONTEND_TADADXLOGO_H
#define PSO_UI_FRONTEND_TADADXLOGO_H
#include "pso/system/task/TObject.h"
#include "types.h"

extern u32 TAdADXlogo__done;

class TAdADXlogo : public TObject {
public:
    s32 m_frames;

    TAdADXlogo(TObject *parent);
    virtual ~TAdADXlogo();
    virtual void run_task();
    virtual void render();

    static void fade_in_done(TObject *fade);
    static void fade_out_done(TObject *fade);
};

void free_adx_logo_texture();
void load_adx_logo_texture();

#endif
