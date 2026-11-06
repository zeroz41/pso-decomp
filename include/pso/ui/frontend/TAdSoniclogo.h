#ifndef PSO_UI_FRONTEND_TADSONICLOGO_H
#define PSO_UI_FRONTEND_TADSONICLOGO_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TAdSoniclogo : public TObject {
public:
    TAdSoniclogo(TObject *parent);
    virtual void render();
    virtual ~TAdSoniclogo();
    virtual void run_task();
public:
    static void request_destroy();

    s32 m_wait_frames; // 0x1C; inferred name: frames counted to 0x3C in run_task before the fade
};

extern "C" {
void TLogo__sub_8001C360(void);
void TLogo__sub_8001C364(void);
}

#endif
