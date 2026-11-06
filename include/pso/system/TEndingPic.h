#ifndef PSO_SYSTEM_TENDINGPIC_H
#define PSO_SYSTEM_TENDINGPIC_H

#include "pso/TObject.h"
#include "types.h"

class TEndingPic : public TObject {
public:
    virtual ~TEndingPic();
    virtual void run_task();
    virtual void render();
public:
    void advance_animation_state();
    void draw_current_pic();
    void init_positions();
    void send_obj_position_event(s32 arg1);
    void set_phase_18();
    void update_player_object();
    void update_shield();
};

extern "C" {
void TEndingPic__sub_803530A0(void *p);
void TEndingPic__sub_80353110(void *p);
void TEndingPic__sub_80353134(void *p);
void TEndingPic__sub_80353194(void *arg0);
void TEndingPic__sub_803531D0(void *a0);
void TEndingPic__sub_803531F8(void);
u8 *__ct__10TEndingPicFv(u8 *arg0, u8 *arg1);
}
int get_ending_ab_wall_texture_list(void);

#endif
