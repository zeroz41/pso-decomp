#ifndef PSO_UI_FRONTEND_TADSONICLOGO_H
#define PSO_UI_FRONTEND_TADSONICLOGO_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TAdSoniclogo : public TObject {
public:
    static const char *class_name;
    static int state;
    TAdSoniclogo(TObject *parent);
    virtual void render();
    virtual ~TAdSoniclogo();
    virtual void run_task();
public:
    static void request_destroy(TObject *fade);

    s32 m_wait_frames; // 0x1C; inferred name: frames counted to 0x3C in run_task before the fade
};

void load_sonic_logo_texture();
void free_sonic_logo_texture();

#endif
