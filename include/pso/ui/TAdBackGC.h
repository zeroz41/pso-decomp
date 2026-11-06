#ifndef PSO_UI_TADBACKGC_H
#define PSO_UI_TADBACKGC_H

#include "pso/TObject.h"
#include "types.h"

class TAdBackGC : public TObject {
public:
    virtual ~TAdBackGC();
    void sub_8029A6EC();
    virtual void run_task();
    virtual void render();
public:
    static void run_task();
};

extern "C" {
int draw_title_background_layer(void *p, int a1, int a2, f32 a3);
int render_logo_with_default(void *p, int a1, int a2, f32 a3);
}

#endif
