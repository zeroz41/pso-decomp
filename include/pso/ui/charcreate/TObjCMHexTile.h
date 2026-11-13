#ifndef PSO_UI_CHARCREATE_TOBJCMHEXTILE_H
#define PSO_UI_CHARCREATE_TOBJCMHEXTILE_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/math/TMath.h"

class TObjCMHexTile : public TObject {
public:
    virtual ~TObjCMHexTile();
    virtual void run_task();
    virtual void render();

    s32 state;
    s32 state_end_frame[3];
    vec2f m_2c;
    vec2f offset;
    vec2f pos;
    f32 m_44;
    f32 scale;
    f32 alpha;
    s32 frame;
};

typedef char TObjCMHexTile_size[sizeof(TObjCMHexTile) == 0x54 ? 1 : -1];

extern "C" {
void fn_802947A8(void);
TObjCMHexTile *__ct__13TObjCMHexTileFv(TObjCMHexTile *self, TObject *parent, void *pos);
}

#endif
