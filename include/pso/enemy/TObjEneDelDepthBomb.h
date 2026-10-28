#ifndef PSO_ENEMY_TOBJENEDELDEPTHBOMB_H
#define PSO_ENEMY_TOBJENEDELDEPTHBOMB_H

#include "types.h"
#include "pso/player/TObjChara.h"

struct TObjEneDelDepthBomb : public TObjChara {
    virtual ~TObjEneDelDepthBomb();
    virtual void render();
    virtual void run_task();
    void* m_334;
    u8 unk_338[0x4];
    f32 m_33c;
    u8 unk_340[0x4];
    f32 m_344;
    u32 m_348;
    u32 m_34c;
    u32 m_350;
    f32 get_depth_radius();
    u8 unk_354[0x4];
};

typedef char TObjEneDelDepthBomb_size[sizeof(TObjEneDelDepthBomb) == 0x358 ? 1 : -1];

extern "C" {
u8 *TObjEneDelDepthBomb__ct(TObjEneDelDepthBomb *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
int TObjEneDelDepthBomb__sub_80313268(void);
u8 *TObjEneDelDepth__ct(u8 *arg0, s32 arg1, s32 arg2);
void TObjEneDelDepth__sub_803138F8(void *a0);
void TObjEneDelDepth__sub_80313954(u8 *arg0);
void TObjEneDelDepth__sub_80313DE4(void *p);
void TObjEneDelDepth__sub_803142DC(u8 *arg0);
void TObjEneDelDepth__sub_80314500(u8 *actor);
void TObjEneDelDepth__sub_80314EC4(u8 *arg0);
void TObjEneDelDepth__sub_80315518(void);
void *__dt__15TObjEneDelDepthFv(void *arg0, s16 arg1);
void *__dt__19TObjEneDelDepthBombFv(void *arg0, s16 arg1);
void *create__19TObjEneDelDepthBombFPvPvPvPv(void *arg0, void *arg1, void *arg2, void *arg3);
void move_toward_target__15TObjEneDelDepthFv(u8 *arg0);
void render__19TObjEneDelDepthBombFv(u8 *arg0);
void set_depth_offset__15TObjEneDelDepthFPvii(void *arg0, s32 arg1, s32 arg2);
void set_draw_mode__15TObjEneDelDepthFPvi(void *arg0, s32 arg1);
void start_move_toward_player__15TObjEneDelDepthFv(u8 *actor);
}

#endif
