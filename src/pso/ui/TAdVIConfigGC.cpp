#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/unk/text_80307BE8.h"
#include "pso/system/memory.h"
#include "pso/misc/TLobby.h"
#include "pso/TObject.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/ui/TAdVIConfigGC.h"

struct Base_80307F6C_80307DEC { char pad[0x18]; };
struct VObj_80307F6C_80307DEC : Base_80307F6C_80307DEC {
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
    virtual void m10();
};
struct Base_803080B0_80307DEC { char pad[0x18]; };
struct VObj_803080B0_80307DEC : Base_803080B0_80307DEC {
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

struct Name_80307D00 { char s[0x18]; };

struct Cfg_80307D00 {
    u8 pad0[0x24];
    u32 win;
    Name_80307D00 names[4];
};

extern "C" {
void TAdVIConfigGC__vt5(void* p);
void *VIGetDTVStatus(void *);
void TAdVIConfigGC__vt4(void *arg0);
void *get_player_by_client_id(s32 i);
s32 get_window_layout_position(s32);
char *strncpy(char *, const char *, u32);
extern u8 player_names_window_pos[];
extern s32 local_client_id;
void *TAdVIConfigGC__ct(TAdVIConfigGC *arg0);
void TAdVIConfigGC__vt8(void);
void *__dt__13TAdVIConfigGCFv(void *arg0, s16 arg1);
void *destroy__13TAdVIConfigGCFPvs(void *arg0, s16 arg1);
int OSSetProgressiveMode(void*);
void *TAdYesNoBaseGC__ct(TAdYesNoBaseGC *arg0);
void *__dt__14TAdYesNoBaseGCFv(void *arg0, s16 arg1);
s32 VecCopy__FP3VecPC3Vec(void *);
void __dl__7TObjectFPv(void *);
int VIWaitForRetrace(void);
int VIConfigure(void*);
int VIFlush(void);
s32 memset(void *, int, int);

void TAdVIConfigGC::open_player_names_window() {
    s32 i;
    u8 *p;
    if (((Cfg_80307D00 *)this)->win != 0) {
        ((TWindowBase *)(((Cfg_80307D00 *)this)->win))->close();
        ((Cfg_80307D00 *)this)->win = 0;
    }
    ((Cfg_80307D00 *)this)->win = TAdVIConfigGC::draw_with_layer((s32)(get_window_layout_position(0x5A)), (s32)player_names_window_pos, (s32)local_client_id);
    if (((Cfg_80307D00 *)this)->win != 0) {
        ((TWindowSubTradeMain *)(((Cfg_80307D00 *)this)->win))->set_visible();
        ((TWindowSubTradeMain *)(((Cfg_80307D00 *)this)->win))->set_close_flag();
        for (i = 0; i < 4; i++) {
            p = (u8 *)get_player_by_client_id(i);
            if (p != 0) {
                strncpy(((Cfg_80307D00 *)this)->names[i].s, (char *)(p + 0x85C), 0x17);
                ((Cfg_80307D00 *)this)->names[i].s[0x17] = 0;
                TWindowSubStatusDisp::dispatch_without_flags((s32)(((Cfg_80307D00 *)this)->win), (s32)(((Cfg_80307D00 *)this)->names[i].s), (s32)i);
            } else {
                ((Cfg_80307D00 *)this)->names[i].s[0] = 0;
                TWindowSubStatusDisp::dispatch_without_flags((s32)(((Cfg_80307D00 *)this)->win), (s32)(((Cfg_80307D00 *)this)->names[i].s), (s32)i);
            }
        }
    }
}

s32 TAdVIConfigGC::get_field_14() { return *(s32 *)&this->m_down; }

void TAdVIConfigGC::update_visibility() {
    s32 flags;
    u8 *quest_vm_down_load_server;
    flags = TLobby::count_members();
    if ((s32) *(s32 *)&this->m_flags != flags) {
        *(s32 *)&this->m_flags = flags;
        open_player_names_window();
    }
    update_players_in_range((((u8 *)this)));
    quest_vm_down_load_server = (u8 *)(*(u8 * *)&this->m_24);
    if (quest_vm_down_load_server != NULL) {
        if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x18) != 0) {
            ((TQuestVmDownLoadServer *)quest_vm_down_load_server)->clear_flag4_bit4();
            allow_rendering__7TObjectFv((TObject *)(*(u8 * *)&this->m_24));
            return;
        }
        ((TObject *)quest_vm_down_load_server)->suspend_update();
        disallow_rendering__7TObjectFv((TObject *)(*(u8 * *)&this->m_24));
    }
}

void *destroy__13TAdVIConfigGCFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        if ((u32) *(u32 *)((s8 *)arg0 + 0x24) != 0U) {
            ((TQuestVmDownLoadServer *)(*(void **)((s8 *)arg0 + 0x24)))->clear_flag4_bit4();
            allow_rendering__7TObjectFv((TObject *)((void *)(*(u32 *)((s8 *)arg0 + 0x24))));
            ((TWindowBase *)(*(u32 *)((s8 *)arg0 + 0x24)))->close();
            *(u32 *)((s8 *)arg0 + 0x24) = 0U;
        }
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

u8 *TAdVIConfigGC::init(f32 farg0) {
    u8 *arg0 = (u8 *)this;
    VecCopy__FP3VecPC3Vec((u8 *)&this->m_prev);
    *(f32 *)&this->m_name = (f32) (farg0 * farg0);
    *(s32 *)&this->m_24 = 0;
    memset((u8 *)&this->m_28, 0, 0x60);
    *(s32 *)&this->m_flags = TLobby::count_members();
    *(s32 *)&this->m_down = 0;
    *(s32 *)((s8 *)arg0 + 0x18) = 0;
    ((TAdVIConfigGC *)arg0)->open_player_names_window();
    *(s32 *)&this->m_1c = 0;
    return arg0;
}

}

void TAdVIConfigGC::render() {
    struct VObj_80307F6C_80307DEC *o = (struct VObj_80307F6C_80307DEC *)this;
    o->m10();
}

extern s32 logo_clear_flag;

void TAdVIConfigGC::set_field48_clear_global() {
    this->m_48 = 1;
    logo_clear_flag = 0;
}

    extern unsigned char GXNtsc480Prog[];
    extern int active_gx_render_mode;
void TAdVIConfigGC::enable_progressive_mode(void * _w0) { OSSetProgressiveMode((void*)1); active_gx_render_mode = (int)GXNtsc480Prog; VIConfigure(GXNtsc480Prog); VIFlush(); VIWaitForRetrace(); VIWaitForRetrace(); }

int TAdVIConfigGC::disable_progressive_mode(void* _w0) { return OSSetProgressiveMode((void*)(0)); }
void TAdVIConfigGC__vt8(void) { get_localized_text_entry((s32)((void*)29), (s32)((void*)0)); }

void TAdVIConfigGC__vt5(void* p) { TAdVIConfigGC::disable_progressive_mode(p); ((TAdVIConfigGC *)p)->set_field48_clear_global(); }

void TAdVIConfigGC__vt4(void *ad_vi_config_gc) {
    void *x;
    x = VIGetDTVStatus(ad_vi_config_gc);
    if (x != NULL) {
        TAdVIConfigGC::enable_progressive_mode(ad_vi_config_gc);
    }
    ((TAdVIConfigGC *)ad_vi_config_gc)->set_field48_clear_global();
}

void TAdVIConfigGC::run_task() {
    struct VObj_803080B0_80307DEC *o = (struct VObj_803080B0_80307DEC *)this;
    o->m9();
}

extern s32 __vt__13TAdVIConfigGC[];

void *__dt__13TAdVIConfigGCFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TAdVIConfigGC;
        __dt__14TAdYesNoBaseGCFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *TAdVIConfigGC__class_name;

void *TAdVIConfigGC__ct(TAdVIConfigGC *ad_vi_config_gc) {
    TAdYesNoBaseGC__ct(ad_vi_config_gc);
    *(s32 **)((s8 *)ad_vi_config_gc + 0x18) = __vt__13TAdVIConfigGC;
    *(void * *)&ad_vi_config_gc->m_name = TAdVIConfigGC__class_name;
    ad_vi_config_gc->set_field_2c(0);
    ad_vi_config_gc->m_48 = 0;
    return ad_vi_config_gc;
}

}
