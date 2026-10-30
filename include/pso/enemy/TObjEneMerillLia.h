#ifndef PSO_ENEMY_TOBJENEMERILLLIA_H
#define PSO_ENEMY_TOBJENEMERILLLIA_H

#include "types.h"
#include "pso/misc/MaterialOpacityFade.h"
#include "pso/enemy/TUnk_80493450.h"

struct TObjEneMerillLia : public TUnk_80493450 {
    virtual ~TObjEneMerillLia();
    virtual void run_task();
    virtual void render();
    virtual void beast_update_approach();
    virtual void beast_update_group_chase();
    virtual void vfunc_93();
    virtual void vfunc_94();
    virtual void vfunc_96();
    virtual void vfunc_97();
    virtual void vfunc_98();
    virtual void vfunc_99();
    virtual void vfunc_101();
    void sub_800D5570();
    virtual void vfunc_83();
    virtual void vfunc_60();
    virtual void vfunc_59();
    virtual void vfunc_58();

    MaterialOpacityFade fade;
    s32 get_clamped_level();
    void clamp_and_apply_mode_param();
    void reset_state_clear_status();
    void init_attack_state();
    void reset_action_state();
    static void search_target(void *ov);
    static s32 update_emerge_state(void *ov);
    static s32 update_kafun_attack(void *p);
    void init_params_from_position();
    void select_action_by_distance();
    static void destroy_rocks();
    void load_entry_params(s32 i);

    f32 m_3c4;
    u8 unk_3C8[0x8];
    f32 m_3d0;
    u8 unk_3D4[0x4];
    s16 m_3d8;
    u8 unk_3DA[0x2];
};

typedef char TObjEneMerillLiaFadeOffset[offsetof(TObjEneMerillLia, fade) == 0x3A8 ? 1 : -1];

typedef char TObjEneMerillLia_size[sizeof(TObjEneMerillLia) == 0x3DC ? 1 : -1];

extern "C" {
void *TObjEneMerillLia__create(void *arg0);
void *TObjEneMerillLia__ct(void *arg0v, void *arg1, void *arg2);
void TObjEneMerillLia__sub_800D4EC8(s32 arg0);
void TObjEneMerillLia__sub_800D501C(s32 arg0);
void TObjEneMerillLia__sub_800D5BCC(u8 *arg0);
void *__dt__16TObjEneMerillLiaFPvs(void *arg0, s16 arg1);
void render__16TObjEneMerillLiaFv(u8 *arg0);
void run_task__16TObjEneMerillLiaFv(u8 *arg0);
void spawn_ground_effect__16TObjEneMerillLiaFPv(u8 *arg0);
}

#endif
