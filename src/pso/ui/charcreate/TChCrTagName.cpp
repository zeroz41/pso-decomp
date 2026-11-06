#include "pso/TChCrTag.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/TChCrTagName.h"
class TChCrTagName : public TChCrTag {
public:
    virtual void render_shadows();
    virtual ~TChCrTagName();
};

#include "types.h"

struct RecoveredGlobal_802A28C0___vt__12TChCrTagName {
    s32 value;
    u8 remaining[0x1C];
};

struct Tag_802A265C {
    u8 pad[0x20];
    s32 f20;
    u8 pad24[0xC];
    f32 f30;
};

#include "pso/math/TMath.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
struct VBase_802A2500 { char pad[0x18]; };

struct TChCrTagName_802A2500 : VBase_802A2500 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
    s32 f1c;
    s32 f20;
    f32 f24;
    u8 pad28[0x3C - 0x28];
    f32 f3c;
    f32 f40;
    u8 pad44[4];
    vec2f pos;
};

struct VBase_802A226C { char pad[0x18]; };

struct TChCrTagName_802A226C : VBase_802A226C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
    s32 f1c;
    s32 f20;
    f32 f24;
    u8 pad28[0x3C - 0x28];
    f32 f3c;
    f32 f40;
    s32 f44;
    vec2f pos;
};

struct VBase_802A208C { char pad[0x18]; };

struct TChCrTagName_802A208C : VBase_802A208C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
    s32 f1c;
    s32 f20;
    f32 f24;
    u8 pad28[0x3C - 0x28];
    f32 f3c;
    f32 f40;
    s32 f44;
    vec2f pos;
};

extern "C" {
u8 * __ct__8TChCrTagFP7TObjectPv(void *, s32);
extern void *__vt__12TChCrTagName[];
__declspec(section ".rodata") extern const char lbl_804663F8[] = "TChCrTagName";
const char *TChCrTagName__class_name = lbl_804663F8;
f32 cos_table_lookup(s32);
f32 calc_highlight_scale__12TChCrTagNameFPv(Tag_802A265C *arg0);
extern vec2f lbl_80466408[];
void draw_tag_sprite__12TChCrTagNameFPv(TChCrTagName_802A2500 *self);
extern vec2f lbl_80466410[];
extern vec2f lbl_80466418[];
extern vec2f lbl_80466420[];
extern vec2f lbl_80466428[];
int TChCrTagName__sub_802A226C(TChCrTagName_802A226C *self);
f32 sin_table_lookup(s32);
extern vec2f lbl_80466430[];
struct TChCrTagName_802A226C; int TChCrTagName__sub_802A226C(TChCrTagName_802A226C *);
s32 update_fade__8TChCrTagFPv();
void *__nw__7TObjectFUl(int);

#pragma push
#pragma fp_contract on
void draw_ui_sprite_shaded(s32 sprite_id, const vec2f *position, const vec2f *scale,
                           f32 depth, f32 alpha, f32 brightness);

#pragma push
#pragma fp_contract on

#pragma push
#pragma fp_contract on
int draw_tag_sprites__12TChCrTagNameFPv(void *p) {
    s32 id;
    TChCrTagName_802A208C *self = (TChCrTagName_802A208C *)p;
    f32 s;
    f32 depth;
    f32 t;
    f32 bright;
    f32 t2;
    f32 alpha;
    vec2f pos;
    vec2f scale = lbl_80466430[0];
    if (self->f24 > self->f40) {
        t = (self->f24 - self->f40) / ((1.0f) - self->f40);
    } else {
        return;
    }
    s = calc_highlight_scale__12TChCrTagNameFPv((Tag_802A265C *)self);
    if (self->m4() != 0) {
        depth = (-1.8125f);
    } else {
        depth = (0.3125f) * s + (-2.125f);
    }
    bright = (0.75f) * (s * s) + (0.25f);
    t2 = t * t;
    ((TWindowSubSymbolChatPartsSet *)(&pos))->copy_vec2(&self->pos);
    pos.x += (5.0f);
    pos.y += (9.0f);
    alpha = t2;
    id = self->f20 + 0x4B;
    if (self->m4() != 0) {
        alpha = (0.25f) * sin_table_lookup(self->f44 << 9) + t2;
        if (alpha < 0.0f) {
            alpha = 0.0f;
        } else if (alpha > (1.0f)) {
            alpha = (1.0f);
        }
    }
    draw_ui_sprite_shaded(id, &pos, &scale, depth, alpha, bright);
    ((TWindowSubSymbolChatPartsSet *)(&pos))->copy_vec2(&self->pos);
    pos.x = (169.0f);
    pos.y += (3.0f);
    draw_ui_sprite_shaded(self->f20 + 0x57, &pos, &scale, depth, t2, bright);
}
#pragma pop

int TChCrTagName__sub_802A226C(TChCrTagName_802A226C *self) {
    f32 s;
    f32 depth;
    f32 t = (1.0f);
    f32 bright;
    if (self->f24 < self->f40) {
        t = (self->f24 - self->f3c) / (self->f40 - self->f3c);
    }
    s = calc_highlight_scale__12TChCrTagNameFPv((Tag_802A265C *)self);
    if (self->m4() != 0) {
        depth = (-2.125f);
    } else {
        depth = (0.3125f) * s + (-2.4375f);
    }
    bright = (0.75f) * (s * s) + (0.25f);
    t = t * t;
    {
        vec2f scale = lbl_80466410[0];
        vec2f pos;
        ((TWindowSubSymbolChatPartsSet *)(&pos))->copy_vec2(&self->pos);
        draw_ui_sprite_shaded(0x41, &pos, &scale, depth, t, bright);
        pos.y += (22.0f);
        draw_ui_sprite_shaded(0x42, &pos, &scale, depth, t, bright);
    }
    {
        vec2f scale = lbl_80466418[0];
        vec2f pos;
        ((TWindowSubSymbolChatPartsSet *)(&pos))->copy_vec2(&self->pos);
        pos.x += (226.0f);
        draw_ui_sprite_shaded(self->f20 == 0 ? 0x44 : 0x48, &pos, &scale, depth, t, bright);
        pos.y += (22.0f);
        draw_ui_sprite_shaded(self->f20 == 11 ? 0x46 : 0x4A, &pos, &scale, depth, t, bright);
    }
    {
        vec2f scale = lbl_80466420[0];
        vec2f pos;
        ((TWindowSubSymbolChatPartsSet *)(&pos))->copy_vec2(&self->pos);
        pos.x += (226.0f);
        pos.y += (8.0f);
        draw_ui_sprite_shaded(0x40, &pos, &scale, depth, t, bright);
    }
    if (self->f24 < (1.0f)) {
        vec2f scale = lbl_80466428[0];
        vec2f pos;
        ((TWindowSubSymbolChatPartsSet *)(&pos))->copy_vec2(&self->pos);
        pos.x -= (3.0f);
        draw_ui_sprite_shaded(0x3F, &pos, &scale, depth, t, bright);
    }
}
#pragma pop

void draw_tag_sprite__12TChCrTagNameFPv(TChCrTagName_802A2500 *self) {
    f32 s;
    f32 depth;
    f32 t;
    vec2f pos;
    s32 id = self->f20 / 4 + 0x3C;
    vec2f scale = lbl_80466408[0];
    t = (1.0f);
    if (self->f24 < self->f40) {
        t = (self->f24 - self->f3c) / (self->f40 - self->f3c);
    }
    s = calc_highlight_scale__12TChCrTagNameFPv((Tag_802A265C *)self);
    if (self->m4() != 0) {
        depth = (-2.4375f);
    } else {
        depth = (0.3125f) * s + (-2.75f);
    }
    ((TWindowSubSymbolChatPartsSet *)(&pos))->copy_vec2(&self->pos);
    pos.y += (3.0f);
    draw_ui_sprite_shaded(id, &pos, &scale, depth, t * t, (0.75f) * (s * s) + (0.25f));
}
#pragma pop

__declspec(section ".rodata") vec2f lbl_80466408[1] = {{9.625f, 1.0f}};
__declspec(section ".rodata") vec2f lbl_80466410[1] = {{28.25f, 1.0f}};
__declspec(section ".rodata") vec2f lbl_80466418[1] = {{1.0f, 1.0f}};
__declspec(section ".rodata") vec2f lbl_80466420[1] = {{1.0f, 1.75f}};
__declspec(section ".rodata") vec2f lbl_80466428[1] = {{1.0f, 3.75f}};
__declspec(section ".rodata") vec2f lbl_80466430[1] = {{1.0f, 1.0f}};

void render__12TChCrTagNameFv(void* p) { draw_tag_sprite__12TChCrTagNameFPv((TChCrTagName_802A2500 *)(p)); TChCrTagName__sub_802A226C((TChCrTagName_802A226C *)((TChCrTagName_802A226C *)(p))); draw_tag_sprites__12TChCrTagNameFPv(p); }

#pragma fp_contract on

#pragma fp_contract on
f32 calc_highlight_scale__12TChCrTagNameFPv(Tag_802A265C *arg0) {
    s32 r;
    switch (TChCrCharSelect::get_selected_index()) {
    case 0:
        r = 0;
        break;
    default:
        if (arg0->f20 / 4 == TChCrCharSelect::get_selected_char()) {
            r = 0;
        } else {
            r = 1;
        }
        break;
    }
    if (r != 0) {
        return arg0->f30;
    }
    return (0.4f) * arg0->f30 + (0.6f);
}
#pragma fp_contract reset

void update_slide_in__12TChCrTagNameFPv(u8 *arg0) {
  f32 temp_f1;
  f32 temp_f2;
  f32 var_f4;
  f32 temp_f3;
  var_f4 = (1.0f);
  *((f32 *) (((s8 *) arg0) + 0x48)) = (f32) (58.0f);
  *((f32 *) (((s8 *) arg0) + 0x4C)) = (f32) (((27.0f) * ((f32) (*((s32 *) (((s8 *) arg0) + 0x20))))) + (1e+02f));
  temp_f2 = *((f32 *) (((s8 *) arg0) + 0x24));
  temp_f1 = *((f32 *) (((s8 *) arg0) + 0x40));
  if (temp_f2 < temp_f1)
  {
    if (1)
    {
      temp_f3 = *((f32 *) (((s8 *) arg0) + 0x3C));
      temp_f1 = (temp_f2 - temp_f3) / (temp_f1 - temp_f3);
      var_f4 = (0.5f) * ((1.0f) - cos_table_lookup((s32) ((32768.0f) * temp_f1)));
    }
  }
  *((f32 *) (((s8 *) arg0) + 0x48)) = (f32) ((*((f32 *) (((s8 *) arg0) + 0x48))) + (((3e+02f) * var_f4) + (-3e+02f)));
}

void run_task__12TChCrTagNameFv(void *ch_cr_tag_name) {
    update_fade__8TChCrTagFPv();
    update_slide_in__12TChCrTagNameFPv((u8 *)ch_cr_tag_name);
    *(s32 *)((s8 *)ch_cr_tag_name + 0x44) = (s32) (*(s32 *)((s8 *)ch_cr_tag_name + 0x44) + 1);
}

extern void *tl_03;

#pragma push
#pragma fp_contract on
typedef char RecoveredGlobal_802A28C0___vt__12TChCrTagName_size[sizeof(RecoveredGlobal_802A28C0___vt__12TChCrTagName) == 0x20 ? 1 : -1];

s32 TChCrTagName__vt4(u8 *arg0) {
    switch (TChCrCharSelect::get_selected_index()) {
    case 0:
        if (*(s32 *)(arg0 + 0x20) / 4 == TChCrCharSelect::get_selected_char()) {
            return 1;
        }
        break;
    case 1:
    case 2:
        if (*(s32 *)(arg0 + 0x20) == TChCrCharSelect::get_instance()) {
            return 1;
        }
        break;
    }
    return 0;
}
TChCrTagName::~TChCrTagName() {}

u8 *__ct__12TChCrTagNameFv(u8 *ch_cr_tag_name, s32 arg1, s32 _w2) {
    __ct__8TChCrTagFP7TObjectPv(ch_cr_tag_name, arg1);
    *(s32 **)((s8 *)ch_cr_tag_name + 0x18) = (s32 *)__vt__12TChCrTagName;
    *(s32 *)((s8 *)ch_cr_tag_name + 0) = (s32) TChCrTagName__class_name;
    *(f32 *)((s8 *)ch_cr_tag_name + 0x28) = (f32) (0.033333335f);
    *(f32 *)((s8 *)ch_cr_tag_name + 0x2C) = (f32) (-0.022222223f);
    *(f32 *)((s8 *)ch_cr_tag_name + 0x34) = (f32) (0.6666667f);
    *(f32 *)((s8 *)ch_cr_tag_name + 0x38) = (f32) (-0.06666667f);
    *(f32 *)((s8 *)ch_cr_tag_name + 0x3C) = (f32) (0.0f);
    *(f32 *)((s8 *)ch_cr_tag_name + 0x40) = 0.8f - 0.053333335f * (f32) (0xC - *(s32 *)((s8 *)ch_cr_tag_name + 0x20));
    update_slide_in__12TChCrTagNameFPv(ch_cr_tag_name);
    *(s32 *)((s8 *)ch_cr_tag_name + 0x44) = 0;
    return ch_cr_tag_name;
}
#pragma pop

void *create__12TChCrTagNameFPv(void *arg0) {
    void *o = __nw__7TObjectFUl(0x50);
    if (o != NULL) {
        o = __ct__12TChCrTagNameFv((u8 *)o, (s32)tl_03, (s32)arg0);
    }
    return o;
}

void create_all__12TChCrTagNameFv(void) { { int i; for (i = 0; i < 12; i++) { create__12TChCrTagNameFPv((void *)((void*)i)); } } }

void __dt__12TChCrTagNameFv();
void render_shadows__7TObjectFv();
void *__vt__12TChCrTagName[] = {
    0, 0,
    (void *)__dt__12TChCrTagNameFv,
    (void *)run_task__12TChCrTagNameFv,
    (void *)render__12TChCrTagNameFv,
    (void *)render_shadows__7TObjectFv,
    (void *)TChCrTagName__vt4,
    0,
};
}
