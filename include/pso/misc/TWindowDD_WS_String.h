#ifndef PSO_MISC_TWINDOWDD_WS_STRING_H
#define PSO_MISC_TWINDOWDD_WS_STRING_H
#include "types.h"
#include "pso/misc/TWindowBase.h"

class TWindowDD_WS_String : public TWindowBase {
public:
    virtual ~TWindowDD_WS_String();
    virtual void render();
    void draw(s32, s32, f32);
    void draw_entry_if_visible(void *);
    u8 unk_1C[0x38];
    u32 m_54;
    u8 unk_58[0x4];
    s32 m_5c;
    u8 unk_60[0x14];
};
typedef char TWindowDD_WS_String_size[sizeof(TWindowDD_WS_String) == 0x74 ? 1 : -1];

#endif
