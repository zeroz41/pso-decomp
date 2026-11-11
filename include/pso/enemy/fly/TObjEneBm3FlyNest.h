#ifndef PSO_ENEMY_FLY_TOBJENEBM3FLYNEST_H
#define PSO_ENEMY_FLY_TOBJENEBM3FLYNEST_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD.h"

struct TObjEneBm3FlyNest : public TObjEneDD {
    virtual ~TObjEneBm3FlyNest();
    virtual void run_task();
    virtual void render();
    virtual void vfunc_88();
    // Slot 104, the first one TObjEneDD leaves to its subclasses (dispatch_action's state-0 handler).
    virtual void init(void *);
    virtual void render_with_state_debug();
    virtual void render_shadows();
    void init_params();
    void state_initial_emit(s32);
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    u8 unk_374[0x4];
    u32 m_394;
    u8 _pad398[0x10];
    u32 m_3a8;
    u32 m_3ac;
    u32 m_3b0;
    u32 m_3b4;
    u8 _pad3B8[0xC];
    u16 m_3c4;
    u8 _pad3C6[0x7A];
    void* m_440;
    u8 _pad444[0x70];
    u32 m_4b4;
    u32 m_4b8;
    u32 m_4bc;
    u32 m_4c0;
    u32 m_4c4;
    u32 m_4c8;
    u32 m_4cc;
    u32 m_4d0;
    u32 m_4d4;
    static void capture_attachment(void * _w0);
    void remove_child(u8 *child);
    s32 has_free_attack_slot(u16 id);
    void spawn_child();
    void update_replenish();
    void copy_pos();
    static void free_fly();
    static void *create(void *arg0);
    static void load_resources();
    static void init_vertex_table();
    u8 unk_4BC[0x20];
};

typedef char TObjEneBm3FlyNest_size[sizeof(TObjEneBm3FlyNest) == 0x4DC ? 1 : -1];

extern "C" {
u8 *__ct__26TObjEneBm3FlyNest_CarryFlyFP7TObjectlllll(u8 *self, void *parent, s32 a, s32 b, s32 unused, s32 c, s32 d);
void *TObjEneBm3FlyNest__ct(void *arg0, void *arg1, void *arg2);
void *TObjEneBm3FlyNest__sub_800B2A54(void *p);
void TObjEneBm3FlyNest__sub_800B318C(u8 *arg0, s32 arg1);
s32 TObjEneBm3FlyNest__sub_800B3AC8(u8 *arg0);
int TObjEneBm3FlyNest__sub_800B4158(void);
void *__dt__26TObjEneBm3FlyNest_CarryFlyFv(void *arg0, s16 arg1);
int copy_target_state__17TObjEneBm3FlyNestFPv(void *p, s32 sound_id);
void dispatch_state__17TObjEneBm3FlyNestFiUii(s32 arg0, u32 arg1, s32 arg2);
void handle_appear__17TObjEneBm3FlyNestFPvi(u8 *arg0, s32 arg1);
void handle_attachment_sample__17TObjEneBm3FlyNestFi(s32 arg0);
void handle_event__17TObjEneBm3FlyNestFPvi(void *arg0, s32 arg1);
void handle_motion_event__17TObjEneBm3FlyNestFPvi(u8 *arg0, s32 arg1);
void handle_state__17TObjEneBm3FlyNestFPvi(void *arg0, s32 arg1);
void render__17TObjEneBm3FlyNestFv(u8 *arg0);
void run_task__17TObjEneBm3FlyNestFv(u8 *arg0);
void state_dying__17TObjEneBm3FlyNestFPvi(u8 *actor, s32 arg1);
void state_spawn__17TObjEneBm3FlyNestFPvi(void *arg0, s32 arg1);
void state_wait__17TObjEneBm3FlyNestFPvi(void *arg0, s32 arg1);
void update_state__17TObjEneBm3FlyNestFPvi(void *arg0, s32 arg1);
}

#endif
