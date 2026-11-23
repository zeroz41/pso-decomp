#ifndef PSO_UI_FRONTEND_TADSEGALOGO_H
#define PSO_UI_FRONTEND_TADSEGALOGO_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TAdSEGAlogo : public TObject {
public:
    TAdSEGAlogo(TObject *parent);
    virtual void render();
    virtual ~TAdSEGAlogo();
    virtual void run_task();
public:
    static void destroy_and_mark_done(TObject *fade);
    static void request_destroy(TObject *fade);

    s32 m_wait_frames; // 0x1C; inferred name: frames counted to 60 in run_task before the fade
};

#endif
