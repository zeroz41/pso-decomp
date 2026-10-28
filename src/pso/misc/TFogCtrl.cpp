#include "types.h"
#include "pso/misc/TFogCtrl.h"
#include "pso/unk/text_803E1FC8.h"
#include "pso/unk/text_803E2008.h"
#include "pso/unk/text_803E2070.h"
#include <stddef.h>

#include "pso/TParticleCtrl.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFogCollisionPoison.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/CurrentArea.h"

struct RecoveredGlobal_800FAD08_TFogCtrl__data_80501188 {
    s32 value;
    u8 remaining[0xC];
};

struct ByteBlock_8 { u8 bytes[0x8]; };

struct ByteBlock_20 { u8 bytes[0x20]; };

struct Row_800FAFE0 { u8 pad[0x40]; s32 identity; };

struct Ctrl_800FAFE0 {
    u8 pad[0x174];
    struct Row_800FAFE0 *slots[4];
    s32 selected;
};

struct GXFogAdjTable_800FAE1C {
    u16 r[10];
};

struct TFogCtrl_800FAE1C {
    u8 pad[0x188];
    u32 color;
    f32 end;
    f32 start;
    f32 width;
};

typedef char RecoveredGlobal_800FAD08_TFogCtrl__data_80501188_size[sizeof(RecoveredGlobal_800FAD08_TFogCtrl__data_80501188) == 0x10 ? 1 : -1];

struct RecoveredGlobal_800FB8A0___vt__8TFogCtrl {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_800FB8A0_TFogCtrl__data_80501188 {
    s32 value;
    u8 remaining[0xC];
};

struct O_800FB400 { u8 pad[0x174]; s32 arr[1]; };

struct Fog_800FB424 { u8 pad[0x40]; s32 entry; f32 f44; s32 f48[3]; };

struct Ctrl_800FB424 { u8 pad[0x174]; Fog_800FB424 *fogs[1]; };

struct FogRow_800FB134 {
    u32 flags;
    u32 color;
    f32 end;
    f32 start;
    f32 rate;
    u32 reserved14;
    f32 speed;
    f32 reserved1c;
    f32 end_amplitude;
    f32 reserved24;
    f32 start_amplitude;
    f32 reserved2c;
    f32 width;
    f32 reserved34;
    u8 phases[8];
};

struct FogCtrl_800FB134 {
    u8 prefix[0x1C];
    u32 dirty;
    u8 pad20[0x174 - 0x20];
    FogRow_800FB134 *slots[4];
    s32 selected;
    u32 color;
    f32 end;
    f32 start;
    f32 width;
};

struct TFogCtrl_800FB92C {
    s32 f0;
    u8 pad4[0x18 - 4];
    void *vt;
    s32 f1C;
    s32 f20;
    Fog_800FB424 fogs[4];
    Fog_800FB424 *ptrs[4];
    s32 f184;
    u8 pad188[0x19C - 0x188];
    s32 f19C;
    s32 f1A0;
    s32 f1A4;
    s32 f1A8;
    s32 f1AC;
    s32 f1B0;
    s32 f1B4;
    f32 f1B8;
    f32 f1BC;
    s32 f1C0;
    s32 index;
};

typedef char RecoveredGlobal_800FB8A0___vt__8TFogCtrl_size[sizeof(RecoveredGlobal_800FB8A0___vt__8TFogCtrl) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_800FB8A0_TFogCtrl__data_80501188_size[sizeof(RecoveredGlobal_800FB8A0_TFogCtrl__data_80501188) == 0x10 ? 1 : -1];

struct RecoveredGlobal_800FBB68_lbl_8049C670 { s32 value; u8 remaining[0x8C]; };

typedef char RecoveredGlobal_800FBB68_lbl_8049C670_size[sizeof(RecoveredGlobal_800FBB68_lbl_8049C670) == 0x90 ? 1 : -1];

struct FogParam_800FBC5C {
    s32 f0;
    s32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    s32 f14;
    f32 f18[8];
    u8 f38[8];
};

struct Row_800FB498 {
    u32 flags;
    u32 color;
    f32 end;
    f32 start;
    f32 rate;
    u32 f14;
    f32 speed;
    f32 f1C;
    f32 endAmp;
    f32 f24;
    f32 startAmp;
    f32 f2C;
    f32 width;
    f32 f34;
    u8 phases[8];
    s32 identity;
    f32 randomPhase;
};

struct Ctrl_800FB498 {
    u8 pad0[0x20];
    s32 mode;
    u8 pad24[0x150];
    Row_800FB498 *slots[4];
    s32 selected;
    u8 pad188[0x14];
    s32 reqFrom;
    s32 reqTo;
    s32 reqCommit;
    s32 pad1A8;
    s32 blendFrom;
    s32 blendTo;
    s32 blendCommit;
    f32 amount;
    f32 rate;
};

struct O_800FB400;

struct FogCtrl_800FB134;
extern "C" {

s32 is_split_screen();
s32 get_camera_mode__11TCameraCtrlFv();
s32 get_random_float__21TObjEneMe3ShinowaRealFv(f32);
void read_disc_file(void *, void *);
s32 TFogCtrl__sub_800FAC84(void* p);
s32 request_fog__8TFogCtrlFPvii(u8 *arg0, s32 arg1, s32 arg2);
void TFogCtrl__sub_800FB400(O_800FB400 *self, s32 i, s32 j);
u8 * __dt__8TFogCtrlFv(u8 *arg0, s16 arg1);
TFogCtrl_800FB92C * __ct__8TFogCtrlFP7TObjectl(TFogCtrl_800FB92C *self, void *parent, s32 index);
void TFogCtrl__sub_800FBA54(void);
void TFogCtrl__sub_800FBA58(void);
void TFogCtrl__sub_800FBAAC(void);
void create_area_fog_ctrl(void);
void mem_free(void *p);
void *mem_alloc(u32 size);
void __dl__7TObjectFPv(s32);
u32 __nw__7TObjectFUl(int);
u8 * __dt__7TObjectFv(void *, s16);
void GXInitFogAdjTable(GXFogAdjTable_800FAE1C *, s32, void *);
void GXSetFogRangeAdj(s32, s32, GXFogAdjTable_800FAE1C *);
f32 sin_table_lookup(s32);

extern s32 TFogCtrl__fog_instance_table[];
extern RecoveredGlobal_800FB8A0___vt__8TFogCtrl __vt__8TFogCtrl;
extern u8 lbl_8043DA20[];
extern u8 lbl_8043DA30[];
extern RecoveredGlobal_800FBB68_lbl_8049C670 area_fog_row_table;
extern u8 fog_default_entry[];
extern u8 scene_projection_state[];
extern s32 lbl_805D2B18;
extern u32 fog_entry_array;
extern s32 fog_update_flags;
extern s32 actor_frame_tick;
extern s32 *tl_02;

extern const f32 TFogCtrl__data_805DA948 = 0.0f;
extern const f32 TFogCtrl__data_805DA94C = 640.0f;
#define FOG_ZERO (*(const f32 *)&TFogCtrl__data_805DA948)
#define FOG_MAX (*(const f32 *)&TFogCtrl__data_805DA94C)

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 TFogCtrl::select_fog_for_viewport(s32 arg0, s32 arg1, s32 arg2) {
    if (is_split_screen() == 0) {
        arg0 = 0;
    }
    if ((arg0 >= 0) && (arg0 < 4) && ((u32) TFogCtrl__fog_instance_table[arg0] != 0U)) {
        return ((s32)((TFogCtrl *)(TFogCtrl__fog_instance_table[arg0]))->select_fog(arg1, arg2));
    }
    return 0;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 TFogCtrl::restore_fog_for_player(s32 arg1, s32 arg0) {
    if (is_split_screen() == 0) {
        arg1 = 0;
    }
    if ((arg1 >= 0) && (arg1 < 4)) {
        s32 elem = *(s32 *)(((s8 *)&TFogCtrl__fog_instance_table) + arg1 * 4);
        if ((u32) elem != 0U) {
            return ((TFogCtrl *)elem)->restore_fog(arg0);
        }
    }
    return 0;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 TFogCtrl__sub_800FAC84(void* p) { return *(s32*)((char*)*(void**)((char*)p + 0x174) + 0x40); }
}
void copy_fog_entry(u8 *arg0, u8 *arg1);
s32 apply_fog_entry(void *arg0);
void init_scene_fog_system(void);
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void copy_fog_entry(u8 *arg0, u8 *arg1) {
    s32 var_r5;
    s32 var_r7;
    u8 *var_r6;
    var_r5 = *(s32 *)((s8 *)arg1 + 0);
    var_r6 = (u8 *)arg1 + 0x14;
    var_r7 = (long) ((u8 *)arg0 + 0x14);
    *(s32 *)((s8 *)arg0 + 0) = var_r5;
    var_r5 = *(s32 *)((s8 *)arg1 + 4);
    *(s32 *)((s8 *)arg0 + 4) = var_r5;
    *(f32 *)((s8 *)arg0 + 8) = (f32) *(f32 *)((s8 *)arg1 + 8);
    *(f32 *)((s8 *)arg0 + 0xC) = (f32) *(f32 *)((s8 *)arg1 + 0xC);
    *(f32 *)((s8 *)arg0 + 0x10) = (f32) *(f32 *)((s8 *)arg1 + 0x10);
    var_r5 = *(s32 *)((s8 *)arg1 + 0x14);
    *(s32 *)((s8 *)arg0 + 0x14) = var_r5;
    *(ByteBlock_20 *)(var_r7 + 4) = *(const ByteBlock_20 *)((s32) var_r6 + 4);
    var_r7 += 0x20;
    var_r6 += 0x20;
    *(ByteBlock_8 *)((s32) arg0 + 0x38) = *(const ByteBlock_8 *)((s32) arg1 + 0x38);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

void*TFogCtrl::get_entry(int a0) {  return (char*)((*(int *)&fog_entry_array)) + a0 * 64; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TFogCtrl::clear_split_screen_fog() {
    u32 temp_r3;
    if (is_split_screen() == 1) {
        temp_r3 = *(s32 *)((s8 *)(&(*(RecoveredGlobal_800FAD08_TFogCtrl__data_80501188 *)&TFogCtrl__fog_instance_table).value) + ((TCameraCtrl::get_nth_view_player_id((int) (get_camera_mode__11TCameraCtrlFv())) * 4) & 0x3FFFC));
        if (temp_r3 != 0U) {
            ((TFogCtrl *)temp_r3)->clear_active_flag();
        }
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TFogCtrl::update_all() {
    s32 var_r29;
    s32 var_r31;
    s32 temp_r3;

    if (is_split_screen() == 0) {
        var_r29 = 0;
        var_r31 = 0;
        do {
            temp_r3 = *(TFogCtrl__fog_instance_table + var_r31);
            if ((u32)temp_r3 != 0U) {
                ((TFogCtrl *)temp_r3)->clear_active_flag();
            }
            var_r29 += 1;
            var_r31 += 1;
        } while (var_r29 != 4);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TFogCtrl::clear_active_flag() {
    s32 temp_r3;

    if (is_split_screen() == 0) {
        temp_r3 = this->m_1c;
        if (temp_r3 & 1) {
            this->m_1c = (s32) (temp_r3 & 0xFFFFFFFE);
            apply_fog_entry(this);
        }
    } else {
        apply_fog_entry(this);
        this->m_1c = (s32) (this->m_1c & 0xFFFFFFFE);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 apply_fog_entry(void *arg0) {
    TFogCtrl_800FAE1C *self = (TFogCtrl_800FAE1C *)arg0;
    GXFogAdjTable_800FAE1C tbl;
    set_scene_fog_type(2);
    fn_803E1FC8((self->color << 8) | (self->color >> 24));
    set_scene_fog_distances(self->start, self->end);
    if (is_split_screen() == 0) {
        if (self->width >= FOG_MAX) {
            self->width = FOG_MAX;
        } else if (self->width <= FOG_ZERO) {
            self->width = FOG_ZERO;
        }
        GXInitFogAdjTable(&tbl, (s32)self->width, scene_projection_state);
        GXSetFogRangeAdj(1, 0x140, &tbl);
    } else {
        if (self->width >= (3.2e+02f)) {
            self->width = (3.2e+02f);
        } else if (self->width <= FOG_ZERO) {
            self->width = FOG_ZERO;
        }
        GXInitFogAdjTable(&tbl, (s32)self->width, scene_projection_state);
        GXSetFogRangeAdj(1, 0xA0, &tbl);
    }
    TParticleCtrl::end_effect_render();
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" {
s32 TFogCtrl::restore_fog(s32 arg1) {
    s32 temp_r0;
    if (get_param() != 0) {
        return 0;
    }
    temp_r0 = this->m_184;
    if (temp_r0 == 0) {
        return 1;
    }
    if ((temp_r0 == 3) && ((s32) this->m_1b4 == 0)) {
        return 1;
    }
    if (arg1 & 1) {
        this->m_20 = 1;
    } else {
        this->m_20 = 2;
    }
    this->m_19c = (s32) this->m_184;
    this->m_1a0 = 0;
    this->m_1a4 = 0;
    return 1;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 TFogCtrl::select_fog(s32 arg1, s32 arg2) {
    struct Ctrl_800FAFE0 *self = (struct Ctrl_800FAFE0 *)this;
    if (this->get_param() != 0) {
        return 0;
    }
    if (self->slots[self->selected]->identity == arg1) {
        return 1;
    }
    this->load_entry_into_slot(2, arg1);
    this->request_transition(1, arg2);
    return 1;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 request_fog__8TFogCtrlFPvii(u8 *fog_ctrl, s32 arg1, s32 arg2) {
  s32 var_r30;
  s32 var_r31;
  s32 var_r4;
  s32 entry;
  u8 *var_r29;
  u8 *var_r3;
  var_r29 = fog_ctrl;
  var_r30 = arg1;
  var_r31 = arg2;
  if (((TFogCtrl *)fog_ctrl)->get_param() != 0)
  {
    var_r3 = (u8 *) 0;
    return 0;
  }
  var_r3 = (u8 *) (var_r29 + ((*((s32 *) (((s8 *) var_r29) + 0x184))) * 4));
  var_r3 = (u8 *) (*((u8 **) (((s8 *) var_r3) + 0x174)));
  if (((s32) (*((s32 *) (((s8 *) var_r3) + 0x40)))) == var_r30)
  {
    var_r3 = (u8 *) ((void *) 1);
    if (var_r3 && var_r3)
    {
    }
    return 1;
  }
  var_r3 = (u8 *) var_r29;
  entry = var_r30;
  var_r4 = 2;
  ((TFogCtrl *)var_r3)->load_entry_into_slot(2, (int) entry);
  var_r3 = (u8 *) var_r29;
  entry = var_r31;
  var_r4 = 0;
  ((TFogCtrl *)var_r3)->request_transition(0, (s32)((int) entry));
  var_r3 = (u8 *) ((void *) 1);
  return 1;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TFogCtrl::request_transition(s32 arg1, s32 arg2) {
    if (arg2 & 1) {
        this->m_20 = 1;
    } else {
        this->m_20 = 2;
    }
    this->m_19c = (s32) this->m_184;
    this->m_1a0 = 2;
    this->m_1a4 = arg1;
}
#pragma pop

s32 TFogCtrl::get_param() { return this->m_1c0; }

#pragma push
#pragma fp_contract on
void TFogCtrl::apply_slot_params(s32 idx) {
    FogCtrl_800FB134 *self = (FogCtrl_800FB134 *)this;
    FogRow_800FB134 *row = self->slots[idx];
    f32 t;
    self->color = row->color;
    self->end = row->end;
    self->start = row->start;
    self->width = FOG_MAX;
    if (FOG_ZERO != row->end_amplitude) {
        t = row->end_amplitude * sin_table_lookup((s32)((182.04445f) * ((f32)actor_frame_tick * row->speed + (f32)row->phases[2])));
        self->end += t;
    }
    if (FOG_ZERO != row->start_amplitude) {
        t = row->start_amplitude * sin_table_lookup((s32)((182.04445f) * ((f32)actor_frame_tick * row->speed + (f32)row->phases[4])));
        self->start += t;
    }
    if (FOG_ZERO != row->width) {
        self->width = (f32)row->phases[6] * sin_table_lookup((s32)((182.04445f) * ((f32)actor_frame_tick * row->speed))) + row->width;
    }
    self->dirty |= 1;
}
#pragma pop

s32 TFogCtrl::is_controller_animated(s32 arg0, s32 arg1) {
  f32 temp_f31;
  f32 var_f31;
  s32 temp_r3;
  u8 *temp_r31;
  temp_r3 = arg0 + (arg1 * 4);
  temp_r31 = (u8 *) (*((u8 **) (((s8 *) temp_r3) + 0x174)));
  temp_r3 = *((s32 *) (((s8 *) temp_r31) + 0));
  if (temp_r3 & 2)
  {
    if (((FOG_ZERO != (*((f32 *) (((s8 *) temp_r31) + 0x20)))) || (FOG_ZERO != (*((f32 *) (((s8 *) temp_r31) + 0x28))))) || (((u8) (*((u8 *) (((s8 *) temp_r31) + 0x3E)))) != 0))
    {
      return 1;
    }
    return 0;
  }
  if (temp_r3 & 4)
  {
    temp_f31 = *((f32 *) (((s8 *) temp_r31) + 0x44));
    get_random_float__21TObjEneMe3ShinowaRealFv((f32) temp_f31);
    var_f31 = temp_f31 + (*((f32 *) (((s8 *) temp_r31) + 0x18)));
    get_random_float__21TObjEneMe3ShinowaRealFv((f32) var_f31);
    if (var_f31 < FOG_ZERO)
    {
      var_f31 += (128.0f);
    }
    else
      if (var_f31 >= (128.0f))
    {
      var_f31 -= (128.0f);
    }
    *((f32 *) (((s8 *) temp_r31) + 0x44)) = var_f31;
    return 1;
  }
  return 0;
}

void TFogCtrl__sub_800FB400(O_800FB400 *self, s32 i, s32 j) {
    s32 t = self->arr[i];
    self->arr[i] = self->arr[j];
    self->arr[j] = t;
}

void TFogCtrl::load_entry_into_slot(s32 i, s32 entry) {
    Ctrl_800FB424 *self = (Ctrl_800FB424 *)this;
    s32 k;
    Fog_800FB424 *f = self->fogs[i];
    f->entry = entry;
    copy_fog_entry((u8 *)f, (u8 *)TFogCtrl::get_entry(entry));
    f->f44 = FOG_ZERO;
    for (k = 0; k < 3; k++) {
        f->f48[k] = 0;
    }
}

void TFogCtrl::render() {  }

#pragma push
#pragma fp_contract on
void run_task__8TFogCtrlFv(Ctrl_800FB498 *arg0) {
    u32 c0;
    u32 c1;
    Row_800FB498 *mixed;
    Row_800FB498 *from;
    Row_800FB498 *to;
    s32 update;
    f32 amount;
    f32 inv;
    f32 a;
    f32 b;
    u32 color;

    update = 0;
    switch (arg0->mode) {
    case 0:
        if (TFogCtrl::is_controller_animated((s32)arg0, arg0->selected) != 0) {
            update = 1;
        }
        break;
    case 1:
        TFogCtrl__sub_800FB400((O_800FB400 *)arg0, arg0->reqTo, arg0->reqCommit);
        update = 1;
        arg0->selected = arg0->reqCommit;
        arg0->mode = 0;
        break;
    case 2:
        arg0->blendFrom = arg0->reqFrom;
        arg0->blendTo = arg0->reqTo;
        arg0->blendCommit = arg0->reqCommit;
        arg0->amount = FOG_ZERO;
        if (arg0->blendTo == 0) {
            arg0->rate = arg0->slots[arg0->blendFrom]->rate;
        } else {
            arg0->rate = arg0->slots[arg0->blendTo]->rate;
        }
        if (arg0->rate <= FOG_ZERO) {
            arg0->rate = (0.001f);
        }
        arg0->selected = 3;
        arg0->slots[3]->identity = arg0->slots[arg0->blendTo]->identity;
        arg0->mode = 3;
    case 3:
        mixed = arg0->slots[3];
        from = arg0->slots[arg0->blendFrom];
        to = arg0->slots[arg0->blendTo];
        mixed->randomPhase = FOG_ZERO;
        amount = arg0->amount;
        if (amount >= 1.0f) {
            TFogCtrl__sub_800FB400((O_800FB400 *)arg0, arg0->reqTo, arg0->reqCommit);
            arg0->selected = arg0->blendCommit;
            arg0->mode = 0;
        } else {
            c0 = from->color;
            c1 = to->color;
            inv = 1.0f - amount;
            a = (f32)((c0 >> 16) & 0xFF) * inv;
            b = (f32)((c1 >> 16) & 0xFF) * amount;
            color = (u8)(u32)(a + b) << 16;
            a = (f32)((c0 >> 8) & 0xFF) * inv;
            b = (f32)((c1 >> 8) & 0xFF) * amount;
            color |= (u8)(u32)(a + b) << 8;
            a = (f32)(c0 & 0xFF) * inv;
            b = (f32)(c1 & 0xFF) * amount;
            color |= (u8)(u32)(a + b);
            mixed->color = color;
            mixed->end = from->end * inv + to->end * amount;
            mixed->start = from->start * inv + to->start * amount;
            mixed->speed = to->speed;
            mixed->endAmp = from->endAmp * inv + to->endAmp * amount;
            mixed->startAmp = from->startAmp * inv + to->startAmp * amount;
            mixed->width = from->width * inv + to->width * amount;
            mixed->phases[2] = from->phases[2] * inv + to->phases[2] * amount;
            mixed->phases[4] = from->phases[4] * inv + to->phases[4] * amount;
            mixed->phases[6] = from->phases[6] * inv + to->phases[6] * amount;
            arg0->amount += arg0->rate;
        }
        update = 1;
        break;
    }
    if (update != 0) {
        ((TFogCtrl *)arg0)->apply_slot_params(arg0->selected);
    }
}
#pragma pop

u8 *__dt__8TFogCtrlFv(u8 *arg0, s16 arg1) {
    s32 temp_r0;
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &__vt__8TFogCtrl.value;
        reset_scene_fog();
        TParticleCtrl::end_effect_render();
        temp_r0 = ((TFogCtrl *)arg0)->m_1c4;
        if ((temp_r0 >= 0) && (temp_r0 < 4)) {
            *(s32 *)((s8 *)(&(*(RecoveredGlobal_800FB8A0_TFogCtrl__data_80501188 *)&TFogCtrl__fog_instance_table).value) + (temp_r0 * 4)) = 0;
        }
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma opt_common_subs off
}
TFogCtrl::TFogCtrl(TObject *parent, s32 index) : TObject(parent) {
    s32 i;
    f32 one;
    ((TFogCtrl_800FB92C *)this)->f0 = lbl_805D2B18;
    ((TFogCtrl_800FB92C *)this)->index = index;
    if (((TFogCtrl_800FB92C *)this)->index >= 0 && ((TFogCtrl_800FB92C *)this)->index < 4) {
        ((TFogCtrl_800FB92C **)&TFogCtrl__fog_instance_table)[((TFogCtrl_800FB92C *)this)->index] = ((TFogCtrl_800FB92C *)this);
    }
    ((TFogCtrl_800FB92C *)this)->f20 = 0;
    one = FOG_ZERO;
    for (i = 0; i < 4; i++) {
        ((TFogCtrl_800FB92C *)this)->fogs[i].entry = 0;
        copy_fog_entry((u8 *)&((TFogCtrl_800FB92C *)this)->fogs[i], fog_default_entry);
        ((TFogCtrl_800FB92C *)this)->fogs[i].f44 = one;
        ((TFogCtrl_800FB92C *)this)->ptrs[i] = &((TFogCtrl_800FB92C *)this)->fogs[i];
    }
    ((TFogCtrl_800FB92C *)this)->f184 = 0;
    one = FOG_ZERO;
    ((TFogCtrl_800FB92C *)this)->f19C = 0;
    ((TFogCtrl_800FB92C *)this)->f1A0 = 0;
    ((TFogCtrl_800FB92C *)this)->f1A4 = 0;
    ((TFogCtrl_800FB92C *)this)->f1A8 = 0;
    ((TFogCtrl_800FB92C *)this)->f1AC = 0;
    ((TFogCtrl_800FB92C *)this)->f1B0 = 0;
    ((TFogCtrl_800FB92C *)this)->f1B4 = 0;
    ((TFogCtrl_800FB92C *)this)->f1B8 = one;
    ((TFogCtrl_800FB92C *)this)->f1BC = one;
    ((TFogCtrl_800FB92C *)this)->f1C0 = 0;
    ((TFogCtrl_800FB92C *)this)->f1C = 0;
    this->apply_slot_params(0);
}

#pragma pop

void TFogCtrl__sub_800FBA54(void) {  }

void TFogCtrl__sub_800FBA58(void) {
    s32 var_r29;
    s32 var_r31;
    s32 temp_r3;

    var_r29 = 0;
    var_r31 = 0;
    do {
        temp_r3 = *(TFogCtrl__fog_instance_table + var_r31);
        if ((u32) temp_r3 != 0U) {
            ((s32 (*)(s32))TFogCtrl__sub_800FBA54)(temp_r3);
        }
        var_r29 += 1;
        var_r31 += 1;
    } while (var_r29 != 4);
}

void TFogCtrl__sub_800FBAAC(void) {  }

void TFogCtrl::update_fog_entries() {
    s32 i;
    s32 j;
    s32 v;
    if (TLobby::is_online_ready() != 0) {
        if (!(fog_update_flags & 2)) {
            read_disc_file(lbl_8043DA30, (void *)fog_entry_array);
            fog_update_flags |= 2;
        }
    } else if (fog_update_flags & 2) {
        read_disc_file(lbl_8043DA20, (void *)fog_entry_array);
        fog_update_flags &= ~2;
    }
    i = 0;
    j = 0;
    do {
        v = *(TFogCtrl__fog_instance_table + j);
        if ((u32)v != 0U) {
            ((void (*)(s32))TFogCtrl__sub_800FBAAC)(v);
        }
        i += 1;
        j += 1;
    } while (i != 4);
    TParticleCtrl::end_effect_render();
}

void create_area_fog_ctrl(void) {
    s32 *var_r3;
    s32 *var_r4;
    s32 var_r31;
    s32 var_r5;
    u32 temp_r3;
    u32 temp_r3_2;
    if (is_split_screen() != 0) {
        var_r31 = 0;
        do {
            var_r3 = (s32 *)((u8 *)((s32 *)0x1C8));
            temp_r3 = __nw__7TObjectFUl(0x1C8);
            if (temp_r3 != 0U) {
                var_r4 = (s32 *)tl_02;
                var_r5 = var_r31;
                ((s32 (*)(int, int, int))__ct__8TFogCtrlFP7TObjectl)((int)temp_r3, (int)var_r4, (int)var_r5);
            }
            var_r31 += 1;
        } while (var_r31 != 4);
    } else {
        var_r3 = (s32 *)((u8 *)((s32 *)0x1C8));
        temp_r3_2 = __nw__7TObjectFUl(0x1C8);
        if (temp_r3_2 != 0U) {
            var_r4 = (s32 *)tl_02;
            var_r5 = 0;
            ((s32 (*)(int, int, int))__ct__8TFogCtrlFP7TObjectl)((int)temp_r3_2, (int)var_r4, 0);
        }
    }
    TObjFogCollisionPoison::create();
    var_r4 = (s32 *)&area_fog_row_table.value;
    var_r3 = (s32 *)&area_fog_row_table.value;
    var_r3 = (s32 *)(*(s32 *)((s8 *)&area_fog_row_table.value + (get_current_area() * 4)));
    var_r4 = (s32 *)((u8 *)((s32 *)1));
    TFogCtrl::update_all((int)var_r3, 1);
}

void TFogCtrl::reset() {
    TObjFogCollisionPoison__sub_801533BC();
    TQuestVmDownLoadServer::destroy_instance();
    if ((u32) fog_entry_array != 0U) {
        mem_free((void *)fog_entry_array);
    }
    fog_entry_array = 0U;
    ((s32 (*)(s32))fn_803E1FC8)(-1);
    set_scene_fog_distances((1e+03f), (1e+04f));
    reset_scene_fog();
    TParticleCtrl::begin_effect_render();
}

void init_scene_fog_system(void) {
    s32 i;
    fog_update_flags = 0;
    (*(FogParam_800FBC5C *)&fog_default_entry).f0 = 1;
    (*(FogParam_800FBC5C *)&fog_default_entry).f4 = 0;
    (*(FogParam_800FBC5C *)&fog_default_entry).f8 = 4000.0f;
    (*(FogParam_800FBC5C *)&fog_default_entry).fC = 100.0f;
    (*(FogParam_800FBC5C *)&fog_default_entry).f10 = 0.01f;
    (*(FogParam_800FBC5C *)&fog_default_entry).f14 = 0;
    for (i = 0; i < 8; i++) {
        (*(FogParam_800FBC5C *)&fog_default_entry).f18[i] = FOG_ZERO;
        (*(FogParam_800FBC5C *)&fog_default_entry).f38[i] = 0;
    }
    (*(FogParam_800FBC5C *)&fog_default_entry).f18[6] = FOG_MAX;
    fog_entry_array = (u32)mem_alloc(0x2000);
    for (i = 0; i < 0x80; i++) {
        copy_fog_entry((u8 *)&((FogParam_800FBC5C *)fog_entry_array)[i], (u8 *)&fog_default_entry);
    }
    read_disc_file(lbl_8043DA20, (void *)fog_entry_array);
    for (i = 0; i < 4; i++) {
        TFogCtrl__fog_instance_table[i] = 0;
    }
    TParticleCtrl::end_effect_render();
    TFogCtrl::create_instance();
    TObjFogCollisionPoison::clear_state_array();
}
