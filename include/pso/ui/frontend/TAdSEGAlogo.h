#ifndef PSO_UI_FRONTEND_TADSEGALOGO_H
#define PSO_UI_FRONTEND_TADSEGALOGO_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TAdSEGAlogo : public TObject {
public:
    static const char *class_name;
    static int state;
    TAdSEGAlogo(TObject *parent);
    virtual void render();
    virtual ~TAdSEGAlogo();
    virtual void run_task();
public:
    static void destroy_and_mark_done(TObject *fade);
    static void request_destroy(TObject *fade);

    s32 m_wait_frames; // 0x1C; inferred name: frames counted to 60 in run_task before the fade
};

struct NJS_TEXLIST;

// Texture list of logo_e, registered by register_texture_logo_e.
extern NJS_TEXLIST texture_logo_e_descriptor;
extern NJS_TEXLIST *logo_texture_e_handle;
void register_texture_logo_e(void);

extern int sega_logo_done_flag;

void free_held_object();

#endif
