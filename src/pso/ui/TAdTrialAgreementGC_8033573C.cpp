#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/ui/TAdTrialAgreementGC.h"
#include "pso/ui/TAdPlayerLoadGC_801E0C30.h"
#include "pso/ui/TAdScrollWinGC_80327504.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/ui/TAdAgreementBaseGC.h"
#include "pso/ui/TAdTrialAgreementGC_8033573C.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/misc/TLobby_80335E08.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/ui/TAdTrialAgreementGC_80335958.h"
#include "pso/ui/TUnk_804EE458.h"
#include "pso/misc/TWindowChoiceSetting.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TUnk_804EE470.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer_80141D1C.h"

struct Base_803357EC_8033573C { char pad[0x18]; };
struct VObj_803357EC_8033573C : Base_803357EC_8033573C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
};

struct RecoveredGlobal_80335870___vt__19TAdTrialAgreementGC {
    s32 value;
    u8 remaining[0x34];
};

extern "C" {

s32 __nw__7TObjectFUl(int);
s32 TAdAgreementBaseGC__ct(void *);
extern s32 __vt__19TAdTrialAgreementGC[];
extern s32 TAdTrialAgreementGC__name;
s32 wait_for_load__19TAdTrialAgreementGCFv(s32);

extern s32 pso_system_card_filename[];

s32 TAdTrialAgreementGC::check_card_file(s32 arg0) {
    s32 temp_r3;

    if (((TAdPlayerLoadGC *)0)->probe_card_slot() == 0) {
        return 0;
    }
    if (((TAdPlayerLoadGC *)0)->probe_and_check_card() == 0) {
        return 0;
    }
    wait_for_load__19TAdTrialAgreementGCFv(arg0);
    if (TAdPlayerLoadGC::check_memcard_status(0) != 0) {
        return 0;
    }
    wait_for_load__19TAdTrialAgreementGCFv(arg0);
    temp_r3 = find_card_file__15TAdPlayerLoadGCFiPv(0, (const char *)pso_system_card_filename);
    if ((temp_r3 == 0) || ((temp_r3 + 0x10000) == 0xFF41U)) {
        return 1;
    }
    return 0;
}

void TAdTrialAgreementGC::run_task() {
    struct VObj_803357EC_8033573C *o = (struct VObj_803357EC_8033573C *)this;
    o->m9();
}

}
TAdTrialAgreementGC::~TAdTrialAgreementGC() {

}

typedef char RecoveredGlobal_80335870___vt__19TAdTrialAgreementGC_size[sizeof(RecoveredGlobal_80335870___vt__19TAdTrialAgreementGC) == 0x38 ? 1 : -1];
u8 *TAdTrialAgreementGC__ct(u8 *ad_trial_agreement_gc) {
    s32 ad_scroll_win_gc;
    s32 var_r0;
    TAdAgreementBaseGC__ct(ad_trial_agreement_gc);
    *(s32 **)((s8 *)ad_trial_agreement_gc + 0x18) = &(*(RecoveredGlobal_80335870___vt__19TAdTrialAgreementGC *)&__vt__19TAdTrialAgreementGC).value;
    *(s32 *)((s8 *)ad_trial_agreement_gc + 0) = (s32) TAdTrialAgreementGC__name;
    ((TAdTrialAgreementGC *)ad_trial_agreement_gc)->m_38 = 0;
    if (TAdTrialAgreementGC::check_card_file((s32)ad_trial_agreement_gc) != 0) {
        ((TAdTrialAgreementGC *)(ad_trial_agreement_gc))->vfunc_7();
        queue_destruction__7TObjectFv((ad_trial_agreement_gc));
        return ad_trial_agreement_gc;
    }
    ad_scroll_win_gc = __nw__7TObjectFUl(0x54);
    var_r0 = ad_scroll_win_gc;
    if (var_r0 != 0) {
        var_r0 = (s32)TAdScrollWinGC__ct((TAdScrollWinGC *)((void *)ad_scroll_win_gc), (ad_trial_agreement_gc), 1, 0);
    }
    ((TAdTrialAgreementGC *)ad_trial_agreement_gc)->m_38 = var_r0;
    return ad_trial_agreement_gc;
}

void TAdTrialAgreementGC::draw_record_with_camera(s32 arg0, s32 arg1, s32 arg2) {
    TLobby::draw_with_camera((s32)((void *) (TLobby::get_record(arg1))), arg2, 0x20, (-1e+01f));
}

struct RecoveredGlobal_80335BD4_lbl_8050BEC0 { s32 value; u8 remaining[0x1C]; };
typedef char RecoveredGlobal_80335BD4_lbl_8050BEC0_size[sizeof(RecoveredGlobal_80335BD4_lbl_8050BEC0) == 0x20 ? 1 : -1];

struct RecoveredGlobal_80335BD4_lbl_8058D4C0 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80335BD4_lbl_8058D4C0_size[sizeof(RecoveredGlobal_80335BD4_lbl_8058D4C0) == 0x10 ? 1 : -1];

struct RecoveredGlobal_80335A58_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_80335A58_lbl_8050E3B8 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_80335974_lbl_8050E208
{
  s32 value;
  u8 remaining[0x1AC];
};

struct RecoveredGlobal_80335974_lbl_8050E3B8
{
  s32 value;
  u8 remaining[0x1AC];
};

extern "C" {
s32 TCameraCtrl__sub_80068EF0();
s32 draw_record_with_camera__19TAdTrialAgreementGCFlll(void *, void *, int);
extern RecoveredGlobal_80335BD4_lbl_8050BEC0 saved_model_draw_color;
extern RecoveredGlobal_80335BD4_lbl_8058D4C0 model_material_color;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;

s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(int, int);
s32 play_sound_effect(int, int, int, int);
extern RecoveredGlobal_80335A58_lbl_8050E208 controller_input_state;
extern RecoveredGlobal_80335A58_lbl_8050E3B8 controller_physical_port_bank;

f32 sin_table_lookup(s32);

void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

u8 TAdTrialAgreementGC__sub_80335958(u8 *arg0) {
    return (u8) (*(s32 *)((s8 *)arg0 + 0x24) == 2);
}

s32 TUnk_804EE458::sub_8033596C() { return this->m_20; }

typedef char RecoveredGlobal_80335A58_lbl_8050E208_size[sizeof(RecoveredGlobal_80335A58_lbl_8050E208) == 0x1B0 ? 1 : -1];
typedef char RecoveredGlobal_80335A58_lbl_8050E3B8_size[sizeof(RecoveredGlobal_80335A58_lbl_8050E3B8) == 0x1B0 ? 1 : -1];

typedef struct RecoveredGlobal_80335974_lbl_8050E208 RecoveredGlobal_80335974_lbl_8050E208;
typedef struct RecoveredGlobal_80335974_lbl_8050E3B8 RecoveredGlobal_80335974_lbl_8050E3B8;
void TAdTrialAgreementGC::update_title_prompt() {
    u8 *arg0 = (u8 *)this;
  float new_var;
  if ((TWindowShortListCtrl__check_controller_button((int)((void *) (((u8 *) (&(*(RecoveredGlobal_80335974_lbl_8050E3B8 *)&controller_physical_port_bank).value)) + 0x20)), 8) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) (((u8 *) (&(*(RecoveredGlobal_80335974_lbl_8050E208 *)&controller_input_state).value)) + 0x160), 4) != 0))
  {
    play_sound_effect(0x52D01, 0, 0, 0);
    *(s32 *)&this->m_24 = 1;
  }
  new_var = 1.0f + sin_table_lookup((s32) (182.04445f * ((f32) (((*(s32 *)&this->m_38) % 120) * 3))));
  *((f32 *) (((s8 *) arg0) + 0x28)) = (f32) (new_var / 2.0f);
}

void TAdTrialAgreementGC::handle_cursor_input() {
    u8 *input;
    input = (u8 *)&controller_physical_port_bank.value + 0x20;
    *(f32 *)&this->m_28 = (f32) 1.0f;
    if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((int)input, 0x10, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state.value + 0x160)), 0x10, 6, 1) != 0)) {
        *(s32 *)&this->_pad20 = (s32) (*(s32 *)&this->_pad20 - 1);
        if ((s32) *(s32 *)&this->_pad20 < 0) {
            *(s32 *)&this->_pad20 = 3;
        }
        play_sound_effect(0x54100, 0, 0, 0);
    }
    if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((int)input, 0x20, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state.value + 0x160)), 0x20, 6, 1) != 0)) {
        *(s32 *)&this->_pad20 = (s32) (*(s32 *)&this->_pad20 + 1);
        if ((s32) *(s32 *)&this->_pad20 >= 4) {
            *(s32 *)&this->_pad20 = 0;
        }
        play_sound_effect(0x54100, 0, 0, 0);
    }
    if ((TWindowShortListCtrl__check_controller_button((int)input, 4) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 4) != 0)) {
        *(s32 *)&this->m_24 = 2;
        play_sound_effect(0x40042309, 0, 0, 0);
    }
}

void TAdTrialAgreementGC::render_screen() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    s32 temp_r31;
    s32 var_r31;
    if (TMainTask::get_render_pass() != 0) {
        TParticleCtrl::begin_effect_render();
        TCameraCtrl::restore_full_screen_view();
        saved_model_render_flags = model_render_flags;
        copy_argb((NJS_ARGB *)&saved_model_draw_color.value, (NJS_ARGB *)&model_material_color.value);
        if ((s32) this->m_24 == 0) {
            model_render_flags |= 0x10;
            set_constant_material((const NJS_ARGB *)((arg0 + 0x28)));
            bind_title_texture_list();
            TLobby::draw_with_camera((int) (TLobby::get_record(0xA)), 0xA, 0x22, (-1e+01f));
        }
        temp_r0 = this->m_24;
        if ((temp_r0 == 1) || (temp_r0 == 2)) {
            var_r31 = 0xB;
            do {
                draw_record_with_camera__19TAdTrialAgreementGCFlll((void *)arg0, (void *)var_r31, (int)var_r31);
                var_r31 += 1;
            } while (var_r31 != 0xF);
            bind_title_texture_list();
            set_additive_blend();
            temp_r31 = ((TUnk_804EE458 *)arg0)->sub_8033596C();
            if ((s32) this->m_24 == 1) {
                draw_record_with_camera__19TAdTrialAgreementGCFlll(arg0, (void *)(temp_r31 + 0xF), 0xF);
                draw_record_with_camera__19TAdTrialAgreementGCFlll(arg0, (void *)(temp_r31 + 0x13), 0x13);
                draw_record_with_camera__19TAdTrialAgreementGCFlll(arg0, (void *)(temp_r31 + 0x17), 0x17);
            }
            if ((s32) this->m_24 == 2) {
                draw_record_with_camera__19TAdTrialAgreementGCFlll(arg0, (void *)(temp_r31 + 0x1B), 0x1B);
                draw_record_with_camera__19TAdTrialAgreementGCFlll(arg0, (void *)(temp_r31 + 0x1F), 0x1F);
                draw_record_with_camera__19TAdTrialAgreementGCFlll(arg0, (void *)(temp_r31 + 0x23), 0x23);
            }
            set_default_alpha_blend();
        }
        copy_argb((NJS_ARGB *)&model_material_color.value, (NJS_ARGB *)&saved_model_draw_color.value);
        model_render_flags = saved_model_render_flags;
        TCameraCtrl__sub_80068EF0();
        TParticleCtrl::end_effect_render();
    }
}

void TAdTrialAgreementGC::run_state() {

    switch (this->m_24) {
    case 0:
        update_title_prompt();
        break;
    case 1:
        handle_cursor_input();
        break;
    case 2:
        break;
    }
    this->m_38 = (this->m_38 + 1);
}

extern s32 __vt__13TUnk_804EE458[];

void *__dt__13TUnk_804EE458Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TUnk_804EE458;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}

TUnk_804EE458::TUnk_804EE458(int a1) : TObject((TObject *)a1) {
    *(int*)((char*)this + 0x1c) = a1;
    this->m_20 = 0;
    *(int*)((char*)this + 0x24) = 0;
    this->m_28 = 0.0f;
    *(float*)((char*)this + 0x2c) = 1.0f;
    this->m_30 = 1.0f;
    *(float*)((char*)this + 0x34) = 1.0f;
    this->m_38 = 0;
}

void TLobby__sub_80335E74(void) {  }
void TLobby__sub_80335E78(void) {  }
