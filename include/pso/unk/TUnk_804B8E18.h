#ifndef PSO_UNK_TUNK_804B8E18_H
#define PSO_UNK_TUNK_804B8E18_H
#include "types.h"
#include "pso/object/base/TObjChara.h"

// The gogo ball in play, spawned by TUnk_804B8E00::run_task on the beat.
class TUnk_804B8E18 : public TObjChara {
public:
    TUnk_804B8E18(TObject *parent);
    virtual ~TUnk_804B8E18();
    virtual void run_task();
    virtual void render();
    s32 reflect_velocity_off_collision(void *, void *);
    void sub_8019A44C(s32);
    void update_goal_checks(u16);
    void update_best_time();
    s32 unk_334;
    s32 unk_338;
    f32 gravity; // inferred: run_task adds it to velocity.y every frame
    f32 unk_340;
    Vec velocity;
    s32 time;    // TLobby::get_clock_frames() % 2592
    s32 m_354;
    s32 unk_358;
    s32 unk_35c;
    s32 unk_360;
    CollisionBody collision_body;
    f32 unk_390[4];
    u8 unk_3A0[0x4];
};
typedef char TUnk_804B8E18_size[sizeof(TUnk_804B8E18) == 0x3A4 ? 1 : -1];

#endif
