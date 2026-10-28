#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
u16 get_entity_id(void *);
s32 sub_801AF454__10TObjPlayerFl(void *, u16);
s32 select_class_action_provider__10TObjPlayerFv(void *, int);
extern s32 TObjPlayer__shared_model_buffer;
void TObjPlayer::sub_801BD318() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;
    temp_r4 = get_entity_id(arg0) * 0xC00;
    (*(s32 *)&this->motion_buffer) = (s32) (TObjPlayer__shared_model_buffer + temp_r4);
    select_class_action_provider__10TObjPlayerFv(arg0, temp_r4);
    sub_801AF454__10TObjPlayerFl(arg0, get_entity_id(arg0));
    ((TObjPlayer *)arg0)->init_idle_animation();
    ((TObjPlayer *)arg0)->draw();
}

}
