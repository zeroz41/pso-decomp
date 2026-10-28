#include "types.h"
#include "pso/misc/TWindowCtrlMain.h"

#include "pso/misc/TWindowCtrlMain_8024EEF8.h"

#include "pso/TParticleCtrl.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TWindowKeyBoardSoft.h"
#include "pso/player/TObjPlayer_80141D1C.h"

struct Ent_8024D520 { void *obj; u8 pad[0x18]; };

struct Obj_8024D520 { s32 id; u8 pad[0x14]; void *vt; };

struct WBase_8024D3C0 { u8 pad[0x18]; };

struct W_8024D3C0 : WBase_8024D3C0 { virtual ~W_8024D3C0(); };

struct WBase_8024D690 { u8 pad[0x18]; };

struct W_8024D690 : WBase_8024D690 { virtual ~W_8024D690(); };

extern "C" {
bool TWindowCtrlMain__sub_8024D868(u8 *arg0);
void *__nw__7TObjectFUl(u32);
void *__ct__7TObjectFP7TObject(void *, void *);
void *TWindowCtrlClipOut__ct(void *, void *);
void *TWindowCtrlSub__ct(void *, void *);
void *TWindowCtrlScreen__ct(void *, void *);
extern Ent_8024D520 TWindowCtrlMain__viewport_states[6];
extern s32 TWindowCtrlMain__name;
extern void *tl_01;
extern void *tl_window;
extern void *tl_clipout;
extern void *tl_fadeafter;
extern void *TWindowCtrlMain__instance;
extern void *TWindowCtrlMain__window_task_root;
extern void *TWindowCtrlMain__screen_controller;
extern void *TWindowCtrlMain__sub_controller;
extern void *window_clip_out_instance;
void TWindowCtrlMain__sub_8024D838(void);
void TWindowCtrlMain__sub_8024D85C(void* p);
int TCameraCtrl__sub_80068EF0(void);
s32 TWindowCtrlMain__sub_8024CE24(void);
s32 TWindowMainMenu__sub_8024E3D4(void *);
int spawn_action_palette_slot_light(void*);
int open_submenu__15TWindowSubEquipFll(void*);
int render_nodes__7TObjectFv(void);
int send_and_handle__6TLobbyFii(void*);
int try_open_battle_menu__15TWindowMainMenuFs(void*);
int update_com_card__9TWindowDDFv(void*);

void TWindowCtrlMain::render() { set_default_alpha_blend(); TParticleCtrl::begin_effect_render(); TCameraCtrl::restore_full_screen_view(); TWindowCtrlMain__sub_8024CE24(); render_nodes__7TObjectFv(); TCameraCtrl__sub_80068EF0(); TParticleCtrl::end_effect_render(); }
void TWindowCtrlMain::run_task() { { (void)(update_com_card__9TWindowDDFv(this)); return; } }
}
void load_hud_palette_textures(void);
extern void *TWindowCtrlMain__display_flags;
extern f32 window_depth_order_cursor;
extern const f32 lbl_805DCC58;
TWindowCtrlMain::~TWindowCtrlMain() {
    W_8024D3C0 *root;
    s32 i;
    root = (W_8024D3C0 *)TWindowCtrlMain__window_task_root;
    TWindowCtrlMain__window_task_root = NULL;
    if (window_clip_out_instance != NULL) {
        delete (W_8024D3C0 *)window_clip_out_instance;
        window_clip_out_instance = NULL;
    }
    if (TWindowCtrlMain__sub_controller != NULL) {
        delete (W_8024D3C0 *)TWindowCtrlMain__sub_controller;
        TWindowCtrlMain__sub_controller = NULL;
    }
    if (TWindowCtrlMain__screen_controller != NULL) {
        delete (W_8024D3C0 *)TWindowCtrlMain__screen_controller;
        TWindowCtrlMain__screen_controller = NULL;
    }
    for (i = 5; i >= 0; i--) {
        TWindowCtrlMain::release_ptr((void **)(&TWindowCtrlMain__viewport_states[i]));
    }
    if (TWindowCtrlMain__instance != NULL) {
        delete (W_8024D3C0 *)TWindowCtrlMain__instance;
        TWindowCtrlMain__instance = NULL;
    }
    if (root != NULL) {
        delete root;
    }
}
TWindowCtrlMain::TWindowCtrlMain() : TObject((TObject *)tl_fadeafter) {
    Ent_8024D520 *e;
    s32 i;
    void *p;
    ((Obj_8024D520 *)this)->id = TWindowCtrlMain__name;
    if (TWindowCtrlMain__window_task_root == 0) {
        p = __nw__7TObjectFUl(0x1C);
        if (p != 0) {
            p = __ct__7TObjectFP7TObject(p, 0);
        }
        TWindowCtrlMain__window_task_root = p;
    }
    if (TWindowCtrlMain__instance == 0) {
        p = __nw__7TObjectFUl(0x1C);
        if (p != 0) {
            p = __ct__7TObjectFP7TObject(p, TWindowCtrlMain__window_task_root);
        }
        TWindowCtrlMain__instance = p;
    }
    for (i = 0; i < 6; i++) {
        e = &TWindowCtrlMain__viewport_states[i];
        ((TWindowCtrlMain *)e)->init_fields();
        p = __nw__7TObjectFUl(0x1C);
        if (p != 0) {
            p = __ct__7TObjectFP7TObject(p, TWindowCtrlMain__window_task_root);
        }
        e->obj = p;
    }
    if (TWindowCtrlMain__screen_controller == 0) {
        p = __nw__7TObjectFUl(0x1C);
        if (p != 0) {
            p = TWindowCtrlScreen__ct(p, tl_window);
        }
        TWindowCtrlMain__screen_controller = p;
    }
    if (TWindowCtrlMain__sub_controller == 0) {
        p = __nw__7TObjectFUl(0x1C);
        if (p != 0) {
            p = TWindowCtrlSub__ct(p, tl_01);
        }
        TWindowCtrlMain__sub_controller = p;
    }
    if (window_clip_out_instance == 0) {
        p = __nw__7TObjectFUl(0x1C);
        if (p != 0) {
            p = TWindowCtrlClipOut__ct(p, tl_clipout);
        }
        window_clip_out_instance = p;
    }
}


void TWindowCtrlMain::free_all_windows() {
    W_8024D690 *root;
    s32 i;
    root = (W_8024D690 *)TWindowCtrlMain__window_task_root;
    TWindowCtrlMain__window_task_root = NULL;
    if (window_clip_out_instance != NULL) {
        delete (W_8024D690 *)window_clip_out_instance;
        window_clip_out_instance = NULL;
    }
    if (TWindowCtrlMain__sub_controller != NULL) {
        delete (W_8024D690 *)TWindowCtrlMain__sub_controller;
        TWindowCtrlMain__sub_controller = NULL;
    }
    if (TWindowCtrlMain__screen_controller != NULL) {
        delete (W_8024D690 *)TWindowCtrlMain__screen_controller;
        TWindowCtrlMain__screen_controller = NULL;
    }
    for (i = 5; i >= 0; i--) {
        TWindowCtrlMain::release_ptr((void **)(&TWindowCtrlMain__viewport_states[i]));
    }
    if (TWindowCtrlMain__instance != NULL) {
        delete (W_8024D690 *)TWindowCtrlMain__instance;
        TWindowCtrlMain__instance = NULL;
    }
    if (root != NULL) {
        delete root;
    }
    TWindowCtrlMain::free_keyboard_soft();
    TWindowCtrlMain::free_window();
}

void TWindowCtrlMain::reset_all(void* _w0) {
    s32 i;
    load_hud_palette_textures();
    TWindowCtrlMain__sub_8024EF30();
    TWindowKeyBoardSoft::get_or_create_instance();
    TWindowCtrlMain__display_flags = 0;
    TWindowCtrlMain__window_task_root = 0;
    TWindowCtrlMain__screen_controller = 0;
    TWindowCtrlMain__sub_controller = 0;
    window_clip_out_instance = 0;
    TWindowCtrlMain__instance = 0;
    window_depth_order_cursor = lbl_805DCC58;
    for (i = 0; i < 6; i++) {
        ((TWindowCtrlMain *)(&TWindowCtrlMain__viewport_states[i]))->init_fields();
    }
}

void TWindowCtrlMain__sub_8024D838(void) { TWindowCtrlMain::reset_all((void*)((void*)(0))); }
void TWindowCtrlMain__sub_8024D85C(void* p) { *(s16*)((char*)p + 0x20) = 60; }

bool TWindowCtrlMain__sub_8024D868(u8 *arg0) {
    return *(s16 *)((s8 *)arg0 + 0x20) <= 0;
}

void TWindowCtrlMain::update_child_2c() { void* m = *(void**)((char*)this + 0x2c); if (m) send_and_handle__6TLobbyFii(m); }
void TWindowCtrlMain::spawn_palette_slot_light() { void* m = *(void**)((char*)this + 0x34); if (m) spawn_action_palette_slot_light(m); }
void TWindowCtrlMain::update_field28() { void* m = *(void**)((char*)this + 0x28); if (m) open_submenu__15TWindowSubEquipFll(m); }
void TWindowCtrlMain::free_member() { void* m = *(void**)((char*)this + 0x28); if (m) try_open_battle_menu__15TWindowMainMenuFs(m); }
s32 TWindowCtrlMain::get_main_menu_message() {
    void *p = *(void **)((s8 *)this + 0x28);
    if (p == 0) {
        return 0;
    }
    return TWindowMainMenu__sub_8024E3D4(p);
}
