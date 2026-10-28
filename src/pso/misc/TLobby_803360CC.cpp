#include "types.h"
#include "pso/camera/CameraViewParams.h"
#include "pso/misc/TLobby_803360CC.h"
#include "pso/misc/TUnk_804EE470.h"
#include "pso/ui/TUnk_804EE458.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TUnk_804EEF64.h"
struct TCameraCtrl;
#include "pso/player/TObjPlayer_8023E480.h"

#include "pso/map/FloorArea.h"
#include "pso/unk/text_802A1144.h"

#include "pso/unk/TUnk_804EEF80.h"

#include "pso/TObject.h"
#include "pso/TAdMultiChgGameModeGC.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/TItemReverseTechCtrl.h"
#include "pso/enemy/TObjEneDolmOlm.h"
#include "pso/misc/TKeyBoardControl.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/object/TObjLuker.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8033670C_lbl_804EE58C {
    s32 value;
    u8 remaining[0x4C];
};

typedef struct { s32 a, b, c; } V3_80336520;
typedef struct {
    s32 pad0[2];
    f32 f8, fC;
    s32 pad10[6];
    f32 f28, f2C, f30, f34, f38, f3C, f40, f44;
} Cam_80336520;

struct O_8033612C { u8 pad[0x1C]; void *f1c; void *f20; void *f24; u8 pad2[0x3C - 0x28]; u32 flags; void *h[3]; };

struct RecoveredGlobal_80336340_TKeyBoardControl__data_80506270 {
    s32 value;
    u8 remaining[0xAC];
};

struct Obj_80336340 { u8 pad[0x40]; void *objs[3]; };

struct Tbl_80336750 { const char *s[5]; };

class C_803362A4 {
public:
    void f();
};
typedef void (C_803362A4::*PMF_803362A4)();

extern "C" {
void TKeyBoardControl__sub_8000F9CC(s32 arg0);
    extern int lobby_game_mode_state;
void queue_destruction__7TObjectFv(void *arg0);
s32 __dl__7TObjectFPv(void *);
s32 __dt__7TObjectFv(void *, s32);
extern s32 lbl_804EEF64[];
extern u32 title_scene_instance;
    extern int lbl_805D68C8;
s32 release_texture_list(void *, s32);
u64 call_funcs_reverse__6TLobbyFPvUi(void *, int);
extern RecoveredGlobal_8033670C_lbl_804EE58C lobby_load_callback_table;
extern u8 *lobby_title_texture_list;
void disallow_rendering__7TObjectFv(TObject *arg0);
void hide_title_layers_and_release(O_8033612C *arg0);
int TKeyBoardControl__sub_8000F828(void);
void TKeyBoardControl__sub_8000F90C(int);
s32 create_particle__20TAdLoadQuestPrtTxtGCFPvll(void *, int, int);
void *__nw__7TObjectFUl(u32);
void __ct__7TObjectFP7TObject(void *);
extern V3_80336520 lbl_80477818;
extern u8 lbl_80477824[];
extern s32 tl_clipout;
extern s32 tl_fade;
extern const f32 lbl_805DF8E8;
extern const f32 lbl_805DF8EC;
extern const f32 lbl_805DF8F0;
extern const f32 lbl_805DF8F4;
extern const f32 lbl_805DF8F8;
extern const f32 lbl_805DF8FC;
extern const f32 lbl_805DF900;
extern const f32 lbl_805DF904;
extern const f32 lbl_805DF908;

void TWindowOptionCtrl__sub_802273B4(s32 arg0);
extern RecoveredGlobal_80336340_TKeyBoardControl__data_80506270 TKeyBoardControl__global_key_state;
s32 run_load_callback_table(void *, int);
extern const Tbl_80336750 title_texture_filename_table;
extern u8 title_texture_list[];
extern const s32 current_language;
s32 TAdTrialAgreementGC__sub_80335958(int);
s32 TLobby__sub_80336030(void *);
extern PMF_803362A4 TLobby__state_handler_pmf_table[];

void TLobby::queue_destruction_and_cleanup() {
    queue_destruction__7TObjectFv((this));
    if ((u32) title_scene_instance != 0U) {
        hide_title_layers_and_release((O_8033612C *)((void*)((void*)title_scene_instance)));
    }
}

void TLobby::destroy_download_server(void* _w0) {
    queue_destruction__7TObjectFv((_w0));
    if ((u32) title_scene_instance != 0U) {
        ((TLobby *)title_scene_instance)->set_flag_and_clear_download();
    }
}

void hide_title_layers_and_release(O_8033612C *arg0) {
    s32 i;
    arg0->flags |= 4;
    if (arg0->f1c != 0) {
        disallow_rendering__7TObjectFv((TObject *)arg0->f1c);
    }
    if (arg0->f24 != 0) {
        disallow_rendering__7TObjectFv((TObject *)arg0->f24);
    }
    if (arg0->f20 != 0) {
        disallow_rendering__7TObjectFv((TObject *)arg0->f20);
    }
    for (i = 0; i != 3; i++) {
        if (arg0->h[i] != 0) {
            queue_destruction__7TObjectFv((arg0->h[i]));
            arg0->h[i] = 0;
        }
    }
}

void TLobby::set_flag_and_clear_download() {
    *(s32 *)((s8 *)this + 0x3C) = (s32) (*(s32 *)((s8 *)this + 0x3C) | 1);
    if ((u32) *(u32 *)((s8 *)this + 0x24) != 0U) {
        ((TQuestVmDownLoadServer *)(*(void **)((s8 *)this + 0x24)))->clear_flag4_bit4();
    }
}

void TLobby__sub_803361FC(void) {  }
void TLobby::open_keyboard() { lobby_game_mode_state = 3; TKeyBoardControl__sub_8000F9CC((s32)((void*)19)); }
void TLobby::request_change_game_mode() { lobby_game_mode_state = 2; TAdMultiChgGameModeGC::set_mode_change_state(); }
void TLobby::enter_game_mode_change() { lobby_game_mode_state = 1; TAdMultiChgGameModeGC::set_game_mode_state(); }
void TLobby::enter_chg_game_mode() { lobby_game_mode_state = 0; TAdMultiChgGameModeGC::set_mode_0x15(); }
void TLobby__sub_803362A4(void *arg0_) {
    u8 *arg0 = (u8 *)arg0_;
    if (TAdTrialAgreementGC__sub_80335958(*(s32 *)(arg0 + 0x24)) != 0) {
        TKeyBoardControl__sub_8000F90C(2);
        if (((TAdSinglePlyChrSelectGC *)arg0)->start_offline_seq() != 0) {
            ((void (*)(void *))TLobby__sub_803361FC)(arg0);
            PMF_803362A4 m = TLobby__state_handler_pmf_table[TLobby__sub_80336030(arg0)];
            (((C_803362A4 *)arg0)->*m)();
        }
    }
}
void TUnk_804EEF64::render() {  }

typedef char RecoveredGlobal_80336340_TKeyBoardControl__data_80506270_size[sizeof(RecoveredGlobal_80336340_TKeyBoardControl__data_80506270) == 0xB0 ? 1 : -1];
void TUnk_804EEF64::run_task() {
    s32 i;
    TAdMultiChgGameModeGC::set_default_camera();
    if (((TAdPlayerLoadGC *)0)->probe_card_slot() == 0) {
        for (i = 0; i != 3; i++) {
            if (((Obj_80336340 *)this)->objs[i] != NULL) {
                queue_destruction__7TObjectFv(((Obj_80336340 *)this)->objs[i]);
                ((Obj_80336340 *)this)->objs[i] = NULL;
            }
        }
        TAdMultiChgGameModeGC::request_scene_change();
        return;
    }
    if ((s32) *(s32 *)((s8 *)((Obj_80336340 *)this) + 0x34) < (s32) ((TUnk_804EEF64 *)((Obj_80336340 *)this))->m_38) {
        if ((((TKeyBoardControl *)(&TKeyBoardControl__global_key_state.value))->has_any_key_pressed() != 0) || (TKeyBoardControl::any_pad_input_active() != 0)) {
            *(s32 *)((s8 *)((Obj_80336340 *)this) + 0x34) = 0;
        }
        TLobby__sub_803362A4(((Obj_80336340 *)this));
    }
    if ((s32) ((TUnk_804EEF64 *)((Obj_80336340 *)this))->m_38 == (s32) *(s32 *)((s8 *)((Obj_80336340 *)this) + 0x34)) {
        ((TObject *)(*(void **)((s8 *)((Obj_80336340 *)this) + 0x24)))->suspend_update();
        TWindowOptionCtrl__sub_802273B4(0x1E);
    }
    if (((s32) ((TUnk_804EEF64 *)((Obj_80336340 *)this))->m_38 < (s32) *(s32 *)((s8 *)((Obj_80336340 *)this) + 0x34)) && (((TAdSinglePlyChrSelectGC *)((Obj_80336340 *)this))->start_offline_seq() != 0)) {
        TKeyBoardControl__sub_8000F90C(2);
        set_opening_movie_purpose(0);
        TKeyBoardControl__sub_8000F9CC(3);
    }
    *(s32 *)((s8 *)((Obj_80336340 *)this) + 0x34) = (s32) (*(s32 *)((s8 *)((Obj_80336340 *)this) + 0x34) + 1);
}

void TUnk_804EEF64::sub_8033645C() { if (*(unsigned int*)((char*)this + 0x2c) != 0) { queue_destruction__7TObjectFv(((void*)(*(void**)((char*)this + 0x2c)))); *(int*)((char*)this + 0x2c) = 0; } }
void *TUnk_804EEF64::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804EEF64;
        (*(s32 *)&title_scene_instance) = 0;
        if ((u32) this->m_20 != 0U) {
            queue_destruction__7TObjectFv((this->m_20));
        }
        sub_8033645C();
        end_view_override();
        TLobby::stop_audio_streams();
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}
u8 *TUnk_804EEF64::construct_title_scene() {
    u8 *arg0 = (u8 *)this;
    void *p;

    __ct__7TObjectFP7TObject(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = lbl_804EEF64;
    title_scene_instance = (u32)arg0;
    this->m_30 = 0;
    *(s32 *)((s8 *)arg0 + 0x34) = 0;
    *(s32 *)((s8 *)arg0 + 0x2C) = 0;
    *(s32 *)((s8 *)arg0 + 0x3C) = 0;
    TKeyBoardControl__sub_8000F90C(1);
    TAdMultiPlyChrSelectGC::reset_slot_selections();
    TObjEneDolmOlm::reset_count();
    TAdMultiPlyChrSelectGC__sub_803367E8();
    lobby_game_mode_state = 0;
    if (TKeyBoardControl__sub_8000F828() == 0) {
        this->m_38 = 0x4B0;
    } else {
        this->m_38 = 0x320;
    }
    p = __nw__7TObjectFUl(0x24);
    if (p != 0) {
        p = ((TUnk_804EEF80 *)p)->construct(arg0);
    }
    *(void **)((s8 *)arg0 + 0x1C) = p;
    p = (void *)new TUnk_804EE458((int)arg0);
    *(void **)((s8 *)arg0 + 0x24) = p;
    p = (void *)new TUnk_804EE470((TObject *)(void *)tl_clipout);
    this->m_20 = p;
    this->m_28 = 0;
    if (*(void **)((s8 *)arg0 + 0x24) != 0) {
        ((TObject *)(*(void **)((s8 *)arg0 + 0x24)))->suspend_update();
    }
    TAdMultiChgGameModeGC::apply_bgm_col_ctrl((s32)lbl_80477824);
    {
        Cam_80336520 cam;
        cam.f8 = lbl_805DF8E8;
        cam.fC = lbl_805DF8EC;
        cam.f28 = lbl_805DF8F0;
        cam.f2C = lbl_805DF8F4;
        cam.f34 = cam.f30 = lbl_805DF8F8;
        cam.f38 = lbl_805DF8FC;
        cam.f3C = lbl_805DF900;
        cam.f40 = lbl_805DF904;
        cam.f44 = lbl_805DF908;
        ((CameraViewParams *)&cam)->begin_override();
    }
    {
        V3_80336520 v = lbl_80477818;
        this->m_40 = create_particle__20TAdLoadQuestPrtTxtGCFPvll(&v, 0x1E3, 1);
        *(s32 *)((s8 *)arg0 + 0x44) = create_particle__20TAdLoadQuestPrtTxtGCFPvll(&v, 0x1E4, 1);
        this->m_48 = create_particle__20TAdLoadQuestPrtTxtGCFPvll(&v, 0x1E5, 1);
    }
    p = __nw__7TObjectFUl(0x28);
    if (p != 0) {
        ((TLobby *)p)->init_fade((void *)tl_fade, (void *)TLobby::destroy_download_server);
    }
    TItemReverseTechCtrl::create((TObject *)arg0);
    return arg0;
}

typedef char RecoveredGlobal_8033670C_lbl_804EE58C_size[sizeof(RecoveredGlobal_8033670C_lbl_804EE58C) == 0x50 ? 1 : -1];
void TLobby::destroy_global_object() {
    u32 temp_r4;
    temp_r4 = (u32) call_funcs_reverse__6TLobbyFPvUi(&lobby_load_callback_table.value, 0x20);
    if ((void *) lobby_title_texture_list != NULL) {
        release_texture_list(lobby_title_texture_list, (s32) temp_r4);
        lobby_title_texture_list = NULL;
    }
}
}

void initialize_lobby_title_scene(void) {
    title_scene_instance = 0;
    TLobby::update_menu_cursor();
    Tbl_80336750 t = title_texture_filename_table;
    lobby_title_texture_list = title_texture_list;
    TLobby__sub_8023E4B4((s32)t.s[current_language], (s32)title_texture_list);
    run_load_callback_table(&lobby_load_callback_table, 0x20);
    TLobby::reset_counter();
    set_current_floor_area(0);
}

void TAdMultiPlyChrSelectGC__sub_803367E8(void) { lbl_805D68C8 = 0; }
