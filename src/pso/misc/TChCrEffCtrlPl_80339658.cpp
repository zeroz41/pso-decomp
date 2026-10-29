#include "pso/TChCrEffCtrlPl.h"
#include "pso/render/render_util.h"


#include "types.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/TWindowSubTradeMessage.h"

#pragma readonly_strings on

extern "C" {
const char *TChCrEffCtrlPl__name = "TChCrEffCtrlPl";
}


struct O_80339808 { s32 f0; u8 pad[0x14]; void *vt; s32 f1c; s32 f20; u8 v[8]; f32 f2c; u8 pad2[4]; s32 f34; };

struct O_803396C8 { u8 pad[0x24]; f32 x; f32 y; f32 f2c; f32 f30; s32 f34; };

extern "C" {
s32 draw_ui_sprite(int, void *, f32, f32);
extern u8 lbl_80477C70[];
extern const char *TChCrEffCtrlPl__name;
O_80339808 *__ct__14TChCrEffCtrlPlFP7TObject(O_80339808 *arg0, void * _w1);
f32 sin_table_lookup(s32);
extern const f32 lbl_80477C78[];
void *__nw__7TObjectFUl(int);

#pragma push
#pragma opt_common_subs off
void TChCrEffCtrlPl::render() {
    u8 *arg0 = (u8 *)this;
    f32 var_f2;
    set_depth_buffer_settings_1();
    var_f2 = (2.5f) * *(f32 *)((s8 *)arg0 + 0x2C);
    if (var_f2 > (1.0f)) {
        var_f2 = (1.0f);
    }
    draw_ui_sprite((int) (*(s32 *)((s8 *)arg0 + 0x1C)), arg0 + 0x24, (f32) ((-1.8125f)), var_f2);
    draw_ui_sprite((int) (*(s32 *)((s8 *)arg0 + 0x20)), arg0 + 0x24, (f32) ((-1.8125f)), (f32) (*(f32 *)((s8 *)arg0 + 0x30)));
    restore_saved_depth_alpha_state();
}
#pragma pop

#pragma push
#pragma fp_contract on
void TChCrEffCtrlPl::run_task() {
    O_803396C8 *self = (O_803396C8 *)this;
    f32 s;
    f32 v;
    f32 x;
    f32 y;
    self->f34 += 0xB60;
    self->x += (0.05f) * (lbl_80477C78[0] - self->x);
    self->y += (0.05f) * (lbl_80477C78[1] - self->y);
    self->f2c += (0.011111111f);
    if (self->f2c > 1.0f) {
        self->f2c = 1.0f;
    }
    self->f30 = self->f2c;
    if ((1.0f) == self->f2c) {
        s = (1.0f);
        v = sin_table_lookup(self->f34);
        if ((self->f34 & 0x20000) && v > (0.7f)) {
            s -= v - (0.7f);
        }
        self->f30 = s * self->f2c;
    }
}
#pragma pop

TChCrEffCtrlPl::~TChCrEffCtrlPl() {}

}
TChCrEffCtrlPl::TChCrEffCtrlPl(TObject *object) : TObject(object) {
    ((O_80339808 *)this)->f0 = ((s32)TChCrEffCtrlPl__name);
    ((O_80339808 *)this)->f1c = TChCrEffCtrlPl::get_clamped_player_index() + 0x8B;
    ((O_80339808 *)this)->f20 = TChCrEffCtrlPl::get_clamped_player_index() + 0xBC;
    ((TWindowSubSymbolChatPartsSet *)(((O_80339808 *)this)->v))->copy_vec2(lbl_80477C70);
    ((O_80339808 *)this)->f2c = 0.0f;
    ((O_80339808 *)this)->f34 = 0;
}

void *TChCrEffCtrlPl::create() {
    void *o = __nw__7TObjectFUl(0x38);
    if (o != NULL) {
        o = __ct__14TChCrEffCtrlPlFP7TObject((O_80339808 *)(o), this);
    }
    return o;
}
