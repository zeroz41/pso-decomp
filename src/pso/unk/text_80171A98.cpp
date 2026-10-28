#include "types.h"
#include "pso/unk/text_80171A98.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TOMine.h"
#include "pso/misc/TOMineTrap.h"
#include "pso/player/TObjPlayer.h"

struct Base_80171A98 { char pad[0x18]; };

struct VIcon_80171A98 : Base_80171A98 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4();
    virtual void m5(void *);
};

struct Icon_80171A98 {
    s32 f0;
    u8 pad4[0x18 - 4];
    void **vt;
    u8 pad1C[0x24 - 0x1C];
    s32 f24;
    u8 pad28[0x30 - 0x28];
    u32 f30;
    s32 f34;
    u8 pad38[0x68 - 0x38];
    f32 f68;
    f32 f6C;
    u8 pad70[0x84 - 0x70];
    s32 f84;
    s32 f88;
    s32 f8C;
    u8 pad90[0x326 - 0x90];
    s16 f326;
    u8 pad328[0x34C - 0x328];
    f32 f34C;
    f32 f350;
    s32 f354;
    f32 f358;
    u16 f35C;
    u8 pad35E[0x374 - 0x35E];
    s32 f374;
    s32 f378;
};

extern "C" {
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
void init_collision_body_parts(void *, void *, s32);
void TOMine__ct(void *, void *, void *);
extern u8 mine_collision_body_parts[];
extern s32 __vt__12TOMineIcon03[];
extern s32 TOMineIcon03__name;
extern s32 game_difficulty_selection;
extern void *lbl_805D5A50;
extern const f32 lbl_805DB8C0;
extern const f32 lbl_805DB8C4;
extern const f32 lbl_805DB8C8;
extern const f32 lbl_805DB8CC;
extern const f32 lbl_805DB8D0;
#pragma push
#pragma fp_contract on
void *TOMineIcon03__ct(void *arg0, void *arg1, void *arg2) {
    TOMine__ct(arg0, arg1, arg2);
#define self ((Icon_80171A98 *)arg0)
    self->vt = ((void * *)&__vt__12TOMineIcon03);
    self->f0 = TOMineIcon03__name;
    ((VIcon_80171A98 *)self)->m5(arg2);
    ((TObjPlayer *)self)->init_position_vectors();
    ((TUnk_804806E8 *)self)->calc_attach_pos();
    self->f34 = get_bml_model(lbl_805D5A50, 6);
    self->f24 = TObjFish__sub_8001EDB0(lbl_805D5A50, 6);
    self->f374 = get_bml_model(lbl_805D5A50, 2);
    self->f378 = TObjFish__sub_8001EDB0(lbl_805D5A50, 2);
    self->f326 = 0;
    if (self->f84 < 0) {
        self->f84 = 0;
    }
    if (self->f88 < 6) {
        self->f88 = 6;
    } else if (self->f88 > 8) {
        self->f88 = 8;
    }
    if (self->f8C < 0) {
        self->f8C = 0;
    }
    self->f358 = (f32)self->f84 * (lbl_805DB8C4 * (f32)game_difficulty_selection + lbl_805DB8C0);
    if (game_difficulty_selection == 3) {
        self->f358 *= lbl_805DB8C4;
    }
    self->f354 = self->f88;
    self->f34C = lbl_805DB8CC * self->f68 + lbl_805DB8C8;
    self->f350 = lbl_805DB8CC * self->f6C + lbl_805DB8D0;
    ((TOMine *)self)->update_state();
    self->f35C = 0xFFFF;
    self->f30 |= 0x60000000;
    init_collision_body_parts(self, mine_collision_body_parts, 1);
    ((TUnk_804AF8A0 *)self)->refresh_collision_body_centers();
    ((TObjPlayer *)self)->register_object_by_id();
    return self;
#undef self
}
#pragma pop

}
