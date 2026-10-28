#include "types.h"
#include "pso/boss/TBoss8Dragon_802F3638.h"
#include "pso/object/TObjControl.h"
#include "pso/ui/TObjLiveMonitor.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjLiveCamera.h"
#include "pso/TObjLiveMonitor.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/TObjLiveCameraCtrl.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/object/TObjMotion.h"

struct O_8030B370 { u8 pad[0x24]; u32 a; s32 t; };

extern "C" {

s32 is_split_screen();
s32 rand();

#pragma push
#pragma fp_contract on
void fn_8030B370(O_8030B370 *o) {
    f32 r;
    if (o->t >= 0) {
        if (--o->t <= 0) {
            if (is_split_screen() != 0) {
                o->a = (u32)(3.0f * (3.0517578e-05f * (f32)rand()) + 1.0f);
            } else {
                o->a = (u32)(5.0f * (3.0517578e-05f * (f32)rand()));
            }
            r = 3.0517578e-05f * (f32)rand();
            o->t = (s32)(300.0f * r + 300.0f);
        }
    }
}

#pragma pop

s32 TObjPlayer__sub_80084500();
s32 TObjLiveMonitor__sub_8030C050(void* p);
s32 push_matrix();
s32 draw_ginja_object(int);

void render__15TObjLiveMonitorFv(TObjLiveMonitor *live_monitor) {
    s32 table_entry;
    table_entry = TObjLiveCameraCtrl::get_table_entry(0);
    if ((table_entry != 0) && (TObjLiveMonitor__sub_8030C050((void *)table_entry) != 0)) {
        ((TObjLiveMonitor *)table_entry)->update_camera();
    } else if (is_split_screen() == 0) {
        TObjPlayer__sub_80084500();
    } else {
        live_monitor->render_live_monitor_screen();
    }
    push_matrix();
    draw_ginja_object((int) (*(s32 *)((s8 *)live_monitor + 0x1C)));
    pop_matrix();
}

int run_task__15TObjLiveMonitorFv(void* p) { return ((int (*)(void *))fn_8030B370)(p); }

}

TObjLiveMonitor::~TObjLiveMonitor() {}

extern "C" {

s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
s32 __ct__7TObjectFP7TObject();

extern s32 __vt__15TObjLiveMonitor[];
extern s32 TObjLiveMonitor__name;
extern int live_monitor_shared_resource;

void *__ct__15TObjLiveMonitorFv(void *arg0) {
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)arg0 + 0x18) = (s32 *)__vt__15TObjLiveMonitor;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjLiveMonitor__name;
    *(s32 *)((s8 *)arg0 + 0x1C) = get_bml_model(live_monitor_shared_resource, 1);
    *(s32 *)((s8 *)arg0 + 0x20) = TObjFish__sub_8001EDB0(live_monitor_shared_resource, 0);
    *(s32 *)((s8 *)arg0 + 0x24) = 5;
    *(s32 *)((s8 *)arg0 + 0x28) = 0;
    return arg0;
}

void *__nw__7TObjectFUl(int);

void *TObjLiveMonitor::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x2C);
    if (o != NULL) {
        o = ((void *(*)(void *, void *))__ct__15TObjLiveMonitorFv)(o, arg0);
    }
    return o;
}

}

struct RecoveredGlobal_8030B658_lbl_804E76C0 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8030B658_lbl_804E76C0_size[sizeof(RecoveredGlobal_8030B658_lbl_804E76C0) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8030B708___vt__14TObjLiveCamera {
    s32 value;
    u8 remaining[0x30];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8030B658_lbl_804E76C0 bm_obj_boss8_monitor_resource_descriptor;
s32 __ct__13TUnk_804B9870FP7TObject(void *, void *);
extern s32 __vt__14TObjLiveCamera[];
extern s32 TObjLiveCamera__class_name;
int TLobby__sub_8001FE7C(void*, void*);
void __dl__7TObjectFPv(void *);

void TObjLiveCamera__sub_8030B630(void) { TLobby__sub_8001FE7C((void*)live_monitor_shared_resource, (void*)1); }

void TObjLiveCamera::load_static_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &bm_obj_boss8_monitor_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&live_monitor_shared_resource) = var_r0;
}

void render__14TObjLiveCameraFv(void) {  }
void run_task__14TObjLiveCameraFv(void) {  }

void *__dt__14TObjLiveCameraFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TObjLiveCamera;
        __dt__13TUnk_804B9870Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_05;

typedef char RecoveredGlobal_8030B708___vt__14TObjLiveCamera_size[sizeof(RecoveredGlobal_8030B708___vt__14TObjLiveCamera) == 0x34 ? 1 : -1];
u8 *TObjLiveCamera__ct(u8 *live_camera, s32 parent, s32 arg2) {
    __ct__13TUnk_804B9870FP7TObject((void *)live_camera, (void *)parent);
    *(s32 **)((s8 *)live_camera + 0x18) = &(*(RecoveredGlobal_8030B708___vt__14TObjLiveCamera *)&__vt__14TObjLiveCamera).value;
    *(s32 *)((s8 *)live_camera + 0) = (s32) TObjLiveCamera__class_name;
    ((TObjLiveCamera *)(live_camera))->apply_object_set_data((void *)arg2);
    return live_camera;
}

void *TObjLiveCamera__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x90);
    if (o != NULL) {
        o = TObjLiveCamera__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

int update_single_screen__11TCameraCtrlFv(void*);
int get_global_part_count__12TBoss8DragonFl(void*);

void fn_8030B7B4(void) {  }
void fn_8030B7B8(void) {  }
void TObjLiveMonitor::update_camera() { void* m = *(void**)((char*)this + 0x50); if (m) update_single_screen__11TCameraCtrlFv(m); }
int call_null__12TBoss8DragonFv(void) { return get_global_part_count__12TBoss8DragonFl((void*)(0)); }

}

extern "C" {
s32 angle_diff_s16(int);

u8 *get_player_by_client_id(s32);
u32 TBoss8Dragon__sub_802F3348(int);
s32 TBoss8Dragon__sub_802FCCBC(int);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);

f32 calc_random_ratio__10TObjPlayerFv(void *);

void TObjPlayer__sub_80082CBC(void *effect);
void TObjPlayer__sub_80082CCC(void *effect);

    extern int local_client_id;
int TBoss8Dragon__sub_8030B80C(void) {  return (local_client_id & 0xffff); }

void TObjLiveCameraCtrl::sub_8030B818(int _w1) {
  s32 temp_r0;
  s32 var_r3;
  s32 new_var;
  f32 f;
  new_var = angle_diff_s16(this->m_28);
  f = (f32) new_var;
  temp_r0 = (s32) (f *= 0.05f);
  if (temp_r0 < (-0x280))
  {
    var_r3 = -0x280;
  }
  else
  {
    var_r3 = 0x280;
    if (temp_r0 < 0x280)
    {
      var_r3 = temp_r0;
    }
  }
  this->m_28 = (s32) ((this->m_28) + var_r3);
}

#pragma push
#pragma fp_contract on
void TBoss8Dragon::choose_next_camera_shot() {
    u8 *arg0 = (u8 *)this;
    f32 r;
    u8 *p;
    if (this->m_1e < 0) {
        return;
    }
    if (--this->m_1e > 0) {
        return;
    }
    r = calc_random_ratio__10TObjPlayerFv((u8 *)&this->unk_54);
    if (r < 0.3f) {
        *(s16 *)&this->unk_1C = 1;
    } else if (r < 0.4f) {
        *(s16 *)&this->unk_1C = 2;
    } else if (r < 0.6f) {
        *(s16 *)&this->unk_1C = 3;
    } else {
        *(s16 *)&this->unk_1C = 4;
    }
    switch (*(s16 *)&this->unk_1C) {
    case 0:
        break;
    case 1:
        this->m_1e = 1.8e+02f * (r = calc_random_ratio__10TObjPlayerFv((u8 *)&this->unk_54), r) + 1.8e+02f;
        *(u16 *)((s8 *)arg0 + 0x24) = ((int (*)(void *))TBoss8Dragon__sub_8030B80C)(arg0);
        *(s32 *)&this->unk_28 = 65535.0f * calc_random_ratio__10TObjPlayerFv((u8 *)&this->unk_54);
        this->m_2c = 2.0f * (8e+01f * (calc_random_ratio__10TObjPlayerFv((u8 *)&this->unk_54) - 0.5f));
        *(f32 *)&this->unk_30 = 15.0f * (r = calc_random_ratio__10TObjPlayerFv((u8 *)&this->unk_54), r) + 5.0f;
        break;
    case 2:
        this->m_1e = 1.8e+02f * (r = calc_random_ratio__10TObjPlayerFv((u8 *)&this->unk_54), r) + 1.8e+02f;
        *(u16 *)((s8 *)arg0 + 0x24) = ((int (*)(void *))TBoss8Dragon__sub_8030B80C)(arg0);
        p = get_player_by_client_id(*(u16 *)((s8 *)arg0 + 0x24));
        if (p != NULL) {
            *(s32 *)&this->unk_28 = *(s32 *)((s8 *)p + 0x60) - 0x8000;
        }
        break;
    case 3:
        this->m_1e = 1.5e+02f * (r = calc_random_ratio__10TObjPlayerFv((u8 *)&this->unk_54), r) + 1.5e+02f;
        *(u16 *)((s8 *)arg0 + 0x24) = ((u16 (*)(void *))call_null__12TBoss8DragonFv)(arg0);
        p = get_enemy_entity(*(u16 *)((s8 *)arg0 + 0x24));
        if (p != NULL) {
            *(s32 *)&this->unk_28 = *(s32 *)((s8 *)p + 0x60) - 0x8000;
        }
        break;
    case 4:
        this->m_1e = 1.2e+02f * (r = calc_random_ratio__10TObjPlayerFv((u8 *)&this->unk_54), r) + 1.2e+02f;
        *(s32 *)&this->unk_28 = 65535.0f * calc_random_ratio__10TObjPlayerFv((u8 *)&this->unk_54);
        *(f32 *)&this->m_34 = 3.6e+02f * sin_table_lookup(*(s32 *)&this->unk_28);
        *(f32 *)&this->m_38 = 2.5e+02f;
        *(f32 *)&this->unk_3C = 3.6e+02f * cos_table_lookup(*(s32 *)&this->unk_28);
        this->m_40 = 0.0f;
        *(f32 *)&this->unk_44 = 0.0f;
        this->m_48 = 0.0f;
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TBoss8Dragon::update_live_camera() {
    u8 *arg0 = (u8 *)this;
    u32 boss8_dragon;
    u8 *player;
    u8 *temp_r3_2;
    u8 *enemy_entity;
    switch (*(s16 *)&this->unk_1C) {
    case 1:
        player = (u8 *)(get_player_by_client_id((s32) *(u16 *)((s8 *)arg0 + 0x24)));
        if (player != NULL) {
            *(f32 *)&this->m_34 = (f32) ((3e+01f * sin_table_lookup((int) (*(s32 *)&this->unk_28))) + *(f32 *)((s8 *)player + 0x38));
            *(f32 *)&this->m_38 = (f32) (*(f32 *)((s8 *)player + 0x3C) + *(f32 *)&this->unk_30);
            *(f32 *)&this->unk_3C = (f32) ((3e+01f * cos_table_lookup((int) (*(s32 *)&this->unk_28))) + *(f32 *)((s8 *)player + 0x40));
            this->m_40 = (f32) *(f32 *)((s8 *)player + 0x38);
            *(f32 *)&this->unk_44 = (f32) (*(f32 *)((s8 *)player + 0x3C) + *(f32 *)&this->unk_30);
            this->m_48 = (f32) *(f32 *)((s8 *)player + 0x40);
            *(s32 *)&this->unk_28 = (s32) (*(s32 *)&this->unk_28 + this->m_2c);
        }
        return;
    case 2:
        temp_r3_2 = (u8 *)(get_player_by_client_id((s32) *(u16 *)((s8 *)arg0 + 0x24)));
        if (temp_r3_2 != NULL) {
            *(f32 *)&this->m_34 = (f32) ((45.42f * sin_table_lookup((int) (*(s32 *)&this->unk_28))) + *(f32 *)((s8 *)temp_r3_2 + 0x38));
            *(f32 *)&this->m_38 = (f32) (25.43f + *(f32 *)((s8 *)temp_r3_2 + 0x3C));
            *(f32 *)&this->unk_3C = (f32) ((45.42f * cos_table_lookup((int) (*(s32 *)&this->unk_28))) + *(f32 *)((s8 *)temp_r3_2 + 0x40));
            this->m_40 = (f32) (((-5.0f) * sin_table_lookup((int) (*(s32 *)&this->unk_28))) + *(f32 *)((s8 *)temp_r3_2 + 0x38));
            *(f32 *)&this->unk_44 = (f32) (19.8f + *(f32 *)((s8 *)temp_r3_2 + 0x3C));
            this->m_48 = (f32) (((-5.0f) * cos_table_lookup((int) (*(s32 *)&this->unk_28))) + *(f32 *)((s8 *)temp_r3_2 + 0x40));
            ((TObjLiveCameraCtrl *)arg0)->sub_8030B818((int)((int) (*(s32 *)((s8 *)temp_r3_2 + 0x60) - 0x8000)));
            return;
        }
        break;
    case 3:
        enemy_entity = (u8 *)(get_enemy_entity(*(u16 *)((s8 *)arg0 + 0x24)));
        if ((enemy_entity != NULL) && (*(f32 *)((s8 *)enemy_entity + 0x3C) >= 0.0f)) {
            *(f32 *)&this->m_34 = (f32) ((5e+01f * sin_table_lookup((int) (*(s32 *)&this->unk_28))) + *(f32 *)((s8 *)enemy_entity + 0x38));
            *(f32 *)&this->m_38 = (f32) (1.2e+02f + *(f32 *)((s8 *)enemy_entity + 0x3C));
            *(f32 *)&this->unk_3C = (f32) ((5e+01f * cos_table_lookup((int) (*(s32 *)&this->unk_28))) + *(f32 *)((s8 *)enemy_entity + 0x40));
            this->m_40 = (f32) (((-1.2e+02f) * sin_table_lookup((int) (*(s32 *)&this->unk_28))) + *(f32 *)((s8 *)enemy_entity + 0x38));
            *(f32 *)&this->unk_44 = (f32) (2e+01f + *(f32 *)((s8 *)enemy_entity + 0x3C));
            this->m_48 = (f32) (((-1.2e+02f) * cos_table_lookup((int) (*(s32 *)&this->unk_28))) + *(f32 *)((s8 *)enemy_entity + 0x40));
            ((TObjLiveCameraCtrl *)arg0)->sub_8030B818((int)((int) (*(s32 *)((s8 *)enemy_entity + 0x60) - 0x8000)));
            return;
        }
        break;
    case 5:
        boss8_dragon = TBoss8Dragon__sub_802F3348(0);
        if ((boss8_dragon != 0U) && (TBoss8Dragon__sub_802FCCBC(boss8_dragon) != 0)) {
            this->m_1e = 0;
        }
        break;
    }
}
#pragma pop

void TBoss8Dragon::update_toggle_state() {
    if ((s32) *(s32 *)&this->unk_4C >= TBoss8Dragon__sub_802F3638()) {
        if ((s32) *(s32 *)&this->unk_20 == 1) {
            if ((u32) this->m_50 != 0U) {
                TObjPlayer__sub_80082CBC(*(void * *)&this->m_50);
            }
            *(s32 *)&this->unk_20 = 0;
        }
    } else if ((s32) *(s32 *)&this->unk_20 == 0) {
        if ((u32) this->m_50 != 0U) {
            TObjPlayer__sub_80082CCC(*(void * *)&this->m_50);
        }
        *(s32 *)&this->unk_20 = 1;
    }
}

}

struct Cam_8030BED4 {
    s32 f0;
    u8 pad4[0x18 - 4];
    s32 *vt;
    s16 f1c, f1e;
    s32 f20;
    u16 f24;
    s32 f28, f2c;
    f32 f30;
    f32 f34[3];
    f32 f40[3];
    s32 f4c;
    void *f50;
    u8 f54[4];
};

extern "C" {
void queue_destruction__7TObjectFv(void *);
void update_toggle_state__12TBoss8DragonFv(void *);
void update_live_camera__12TBoss8DragonFv(void *);
void choose_next_camera_shot__12TBoss8DragonFv(void *);
s32 get_current_floor();
void subtractive_rng_seed(void *, s32);
s32 __ct__14SubtractiveRngFv(void *);
u8 *fn_800832EC(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);
s32 is_room_enemy_set_cleared(s32 floor, s16 room);

extern s32 lbl_804757E0[];
extern s32 __vt__18TObjLiveCameraCtrl[];
extern s32 TObjLiveCameraCtrl__class_name;
extern s32 tl_particlemodel;
extern s32 live_camera_controller_next_slot;
extern s32 TObjLiveCameraCtrl__instances;

void fn_8030C058(void);
s32 memset(s32 *, s32, s32);
}
void reset_globals_805D6A84(void);

void TObjLiveCameraCtrl::run_task() {
    update_toggle_state__12TBoss8DragonFv(this);
    update_live_camera__12TBoss8DragonFv(this);
    choose_next_camera_shot__12TBoss8DragonFv(this);
    if (camera_object != NULL) {
        ((TCameraCtrl *)camera_object)->copy_position_vectors(vector_34, vector_40);
    }
}

extern "C" {
void __dt__7TObjectFv(void *, s32);
void __dl__7TObjectFPv(void *);

TObjLiveCameraCtrl *__dt__18TObjLiveCameraCtrlFv(TObjLiveCameraCtrl *self, s16 flag) {
    if (self != NULL) {
        *(s32 **)((s8 *)self + 0x18) = __vt__18TObjLiveCameraCtrl;
        ((TObject **)&TObjLiveCameraCtrl__instances)[self->slot_index] = NULL;
        if (self->camera_object != NULL) queue_destruction__7TObjectFv(self->camera_object);
        __dt__7TObjectFv(self, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
}
TObjLiveCameraCtrl::TObjLiveCameraCtrl(TObject *parent) : TObject(parent) {
    void *p;
    s32 n;
    __ct__14SubtractiveRngFv(((Cam_8030BED4 *)this)->f54);
    ((Cam_8030BED4 *)this)->f0 = TObjLiveCameraCtrl__class_name;
    n = live_camera_controller_next_slot;
    *(Cam_8030BED4 **)((s8 *)((u8 *)(&TObjLiveCameraCtrl__instances) + n * 4) + 0) = ((Cam_8030BED4 *)this);
    live_camera_controller_next_slot = n + 1;
    ((Cam_8030BED4 *)this)->f4c = n;
    ((Cam_8030BED4 *)this)->f1c = 0;
    ((Cam_8030BED4 *)this)->f1e = 0;
    ((Cam_8030BED4 *)this)->f20 = 1;
    ((Cam_8030BED4 *)this)->f24 = 0xFFFF;
    ((Cam_8030BED4 *)this)->f28 = 0;
    ((Cam_8030BED4 *)this)->f2c = 0;
    ((Cam_8030BED4 *)this)->f30 = 0.0f;
    ((Cam_8030BED4 *)this)->f34[0] = 0.0f;
    ((Cam_8030BED4 *)this)->f34[1] = 0.0f;
    ((Cam_8030BED4 *)this)->f34[2] = 0.0f;
    ((Cam_8030BED4 *)this)->f40[0] = 0.0f;
    ((Cam_8030BED4 *)this)->f40[1] = 0.0f;
    ((Cam_8030BED4 *)this)->f40[2] = 1.0f;
    subtractive_rng_seed(((Cam_8030BED4 *)this)->f54, 0);
    if (is_room_enemy_set_cleared(get_current_floor(), 1) == 0) {
        ((Cam_8030BED4 *)this)->f1c = 5;
        ((Cam_8030BED4 *)this)->f1e = -1;
        ((Cam_8030BED4 *)this)->f34[0] = 0.0f;
        ((Cam_8030BED4 *)this)->f34[1] = 155.0f;
        ((Cam_8030BED4 *)this)->f34[2] = (-7.1e+02f);
        ((Cam_8030BED4 *)this)->f40[0] = 0.0f;
        ((Cam_8030BED4 *)this)->f40[1] = 155.0f;
        ((Cam_8030BED4 *)this)->f40[2] = (-7.2e+02f);
    }
    p = __nw__7TObjectFUl(0x3C);
    if (p != 0) {
        p = fn_800832EC((u8 *)p, (s32)tl_particlemodel, (s32)lbl_804757E0[((Cam_8030BED4 *)this)->f4c], (s32)(((Cam_8030BED4 *)this)->f34), (s32)(((Cam_8030BED4 *)this)->f40), (f32)0.5f);
    }
    ((Cam_8030BED4 *)this)->f50 = p;
}

s32 TObjLiveCameraCtrl::get_table_entry(s32 arg0) {
    if (arg0 < 0) {
        return 0;
    }
    if (arg0 > 1) {
        return 0;
    }
    return *(s32 *)((s8 *)&TObjLiveCameraCtrl__instances + (arg0 * 4));
}

s32 TObjLiveMonitor__sub_8030C050(void* p) { return *(s32*)((char*)p + 0x20); }
void fn_8030C058(void) {  }

void reset_globals_805D6A84(void) {
    live_camera_controller_next_slot = 0;
    memset(&TObjLiveCameraCtrl__instances, 0, 4);
}
