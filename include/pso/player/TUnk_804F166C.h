#ifndef PSO_PLAYER_TUNK_804F166C_H
#define PSO_PLAYER_TUNK_804F166C_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804F166C : public TObject {
public:
    virtual ~TUnk_804F166C();
    void *dt_with_child_queue(s16);
    void update_inward_orbit_point();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x4];
    f32 m_20;
    u8 unk_24[0x10];
    f32 m_34;
    u8 unk_38[0x4];
    f32 m_3c;
    f32 m_40;
    u8 unk_44[0x4];
    s32 m_48;
    u8 unk_4C[0x4];
};
typedef char TUnk_804F166C_size[sizeof(TUnk_804F166C) == 0x50 ? 1 : -1];

#endif
