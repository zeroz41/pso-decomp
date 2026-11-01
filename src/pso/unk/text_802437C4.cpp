#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/TWindowEffectLight.h"
#include "pso/misc/TWindowSubStatusDisp.h"
struct Win_802437C4 {
    u8 pad0[0x20];
    s16 id;
    u8 pad22[0x40 - 0x22];
    f32 x, y, w, h;
    u8 pad50[0x70 - 0x50];
    f32 sx, sy;
};

struct Ent_802437C4 { u8 pad0[8]; f32 x, y, w, h; };

struct Pt_802437C4 { f32 x, y; };

extern "C" {
s32 is_split_screen();
s32 sub_80244994__11TWindowBaseFv();
extern const f32 lbl_805DCA2C;
void spawn_action_palette_slot_light(Win_802437C4 *arg0, s32 arg1);
#pragma push
#pragma fp_contract on
void spawn_action_palette_slot_light(Win_802437C4 *arg0, s32 arg1) {
    Pt_802437C4 pt;
    s32 kind;
    Ent_802437C4 *e;
    f32 s;
    f32 hw;
    f32 s2;
    f32 hw2;
    if (sub_80244994__11TWindowBaseFv() == 0) {
        return;
    }
    switch (arg1) {
    case 1:
        kind = 0;
        e = (Ent_802437C4 *)((TWindowBase *)arg0)->get_array_entry(2);
        break;
    case 2:
        kind = 2;
        e = (Ent_802437C4 *)((TWindowBase *)arg0)->get_array_entry(4);
        break;
    case 3:
        kind = 1;
        e = (Ent_802437C4 *)((TWindowBase *)arg0)->get_array_entry(6);
        break;
        return;
    default:
        return;
    }
    if (is_split_screen() != 0) {
        hw = lbl_805DCA2C * arg0->w;
        s = arg0->sx;
        pt.x = s * ((lbl_805DCA2C * e->w + e->x) - hw) + (hw * s + arg0->x);
        hw2 = lbl_805DCA2C * arg0->h;
        s2 = arg0->sy;
        pt.y = s2 * ((lbl_805DCA2C * e->h + e->y) - hw2) + (hw2 * s2 + arg0->y);
    } else {
        pt.x = lbl_805DCA2C * e->w + (arg0->x + e->x);
        pt.y = lbl_805DCA2C * e->h + (arg0->y + e->y);
    }
    TWindowEffectLight::create(&pt, (void *)kind, (void *)arg0->id);
}
#pragma pop

}
