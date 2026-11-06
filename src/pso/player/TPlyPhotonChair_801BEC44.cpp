#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TPlyPhotonChair.h"
#include "pso/player/TObjPlayer.h"

struct O_801BEC50 { u16 a; u16 b; f32 x; f32 y; f32 z; };

struct O_801BEC78 { u16 a; u16 pad; s32 b; };

extern "C" {
extern const f32 TObjPlayer__data_805DC278;
void TObjPlayer__sub_801BEC78(O_801BEC78 *p);
int TPlyPhotonChair::is_mounted() { return (*(u32*)((char*)this + 0x334) >> 26) & 0x1; }

void TObjPlayer::init_vec_record() {
    O_801BEC50 *p = (O_801BEC50 *)this;
    p->a = 0xFFFF;
    p->b = 0;
    p->x = p->y = p->z = TObjPlayer__data_805DC278;
}

void TObjPlayer__sub_801BEC78(O_801BEC78 *p) {
    p->a = 0xFFFF;
    p->b = 0;
}

s32 TObjPlayer::get_entrance_id() { return *(s32*)((char*)this + 0x3c8); }

}
