#ifndef PSO_BOSS_GOLDRAGON_TOBJBOSS8PILLERCTRL_H
#define PSO_BOSS_GOLDRAGON_TOBJBOSS8PILLERCTRL_H

#include "types.h"
#include "pso/system/vector.h"
#include "pso/system/task/TObject.h"

struct Ent_8035C03C;

struct TObjBoss8PillerCtrl : public TObject {
    TObjBoss8PillerCtrl(TObject *parent, f32, const Vec *pos, u16 id);
    virtual ~TObjBoss8PillerCtrl();
    virtual void run_task();
    virtual void render();
    s32 fn_8035BFF8(const Vec *pos);
    void sub_8035C034(Vec *pos);

    Vec position;
    s32 frame;          // run_task: spawns a ring on frames 0, 5, 10 and 15, ends after 0x32
    u16 piller_arg;     // the ctor's id, handed to each TObjBoss8Piller it spawns
    u8 pad_2E[0x2];
    void *buffer;       // freed by the dtor; nothing in this unit sets it
    const Ent_8035C03C *step; // next entry of boss8_piller_ctrl_params
};

LAYOUT_ASSERT(TObjBoss8PillerCtrl_size, sizeof(TObjBoss8PillerCtrl) == 0x38);

// Spawns a TObjBoss8PillerCtrl under tl_05 (pso/unk/text_802FE908.cpp); the ctor drops the f32
void create_boss8_piller_ctrl(const Vec *position, u16 id, f32 ignored);

#endif
