#include "pso/system/RlcArchive.h"
#include "types.h"
#include "pso/unk/TUnk_804DDD28.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSnapShot.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSnapShot_802A7D68.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/WindowLayoutRecord.h"

struct RecoveredGlobal_802A7AF8_lbl_804DDD28 { s32 value; u8 remaining[0x134]; };
typedef char RecoveredGlobal_802A7AF8_lbl_804DDD28_size[sizeof(RecoveredGlobal_802A7AF8_lbl_804DDD28) == 0x138 ? 1 : -1];

struct RecoveredGlobal_802A7B50_lbl_804DDD28 {
    s32 value;
    u8 remaining[0x134];
};

struct VBase_802A7994 { char pad[0x8]; };

struct VObj_802A7994 : VBase_802A7994 {
    virtual s32 m0(s32, s32);
    virtual void m1();
    virtual u32 m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 *m6(s32, s32);
    virtual void m7(); virtual void m8(); virtual void m9(); virtual void m10();
    virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18();
    virtual void m19(); virtual void m20(); virtual void m21(); virtual void m22();
    virtual void m23(); virtual void m24(); virtual void m25(); virtual void m26();
    virtual void m27(); virtual void m28(); virtual void m29(); virtual void m30();
    virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34();
    virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38();
    virtual void m39(); virtual void m40(); virtual void m41(); virtual void m42();
    virtual void m43(); virtual void m44(); virtual void m45(); virtual void m46();
    virtual void m47(); virtual void m48(); virtual void m49(); virtual void m50();
    virtual void m51(); virtual void m52(); virtual void m53(); virtual void m54();
    virtual void m55(); virtual void m56(); virtual void m57(); virtual void m58();
    virtual void m59(); virtual void m60(); virtual void m61(); virtual void m62();
    virtual void m63(); virtual void m64(); virtual void m65(); virtual void m66();
    virtual void m67(); virtual void m68(); virtual void m69(); virtual void m70();
    virtual void m71(); virtual void m72();
    virtual s32 m73();
    virtual void m74();
    virtual u8 *m75(s32);
};

struct Pair_802A7994 { s32 a; s32 b; };

extern "C" {
void *mem_alloc(u32 size);
void mem_free(void *p);
int TLobby__sub_802A7B8C(void);
void TLobby__sub_802A7BC8(void* p);
extern u32 snapshot_image_buffer;
void TLobby__sub_802A7BD8(void);
s32 fn_802A5C3C(u32 *arg0);
s32 memcpy(s32, s32, s32);
s32 fn_802A6070(s32, s32);
s32 fn_802A6078(s32, s32);
extern s32 lbl_805D669C;
void set_slot_position__6TLobbyFii(s32 arg0, s32 arg1);
s32 aram_dma_blocking__6TLobbyFllll(s32, s32, s32, s32, s32);
void free__10TObjPlayerFPv(void *a0);
extern RecoveredGlobal_802A7AF8_lbl_804DDD28 lbl_804DDD28;
u8 *TLobby__sub_802A7B50(u8 *arg0);
s32 TItemDrop__sub_800F9448(s32 arg0, s32 arg1);
void TLobby__sub_802A7848(void* p, s32 _w1);
int TLobby__sub_802A7868(void* p);
int match_coordinate_pair(void*);

void TLobby__sub_802A7848(void* p, s32 _w1) { ((TLobby *)p)->set_field_4(_w1); }
int TLobby__sub_802A7868(void* p) { return match_coordinate_pair(p); }

    extern int player_action_provider_selector;
void TLobby::set_photon_chair_flag(int a0) { player_action_provider_selector = a0; }
struct _VBase802A78E4_802a78e4_802A7848 { char pad[8]; };
struct _VObj802A78E4_802a78e4_802A7848 : _VBase802A78E4_802a78e4_802A7848 { virtual s32 m0(s32, s32); };
void TLobby::set_field_4(s32 v) { *(s32 *)&this->m_flags = v; }
s32 TLobby::get_hold_effect_size_by_type() {
    s32 hold_effect_count;
    hold_effect_count = TObjPlayer::get_hold_effect_count();
    switch (hold_effect_count) {
    case 0:
        return 0x38;
    case 1:
        return 0x10;
    default:
        return 0;
    }
}
s32 TLobby::send_packet(s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_r31;
    s32 temp_r31_2;
    s32 temp_r3;
    s32 temp_r0;
    temp_r31_2 = (arg3 + 0x1F) & 0xFFFFFFE0;
    temp_r3 = (s32)mem_alloc(temp_r31_2);
    if (temp_r3 == 0) {
        return 0;
    }
    TLobby::send_type2_event(arg4, temp_r3, temp_r31_2);
    temp_r0 = ((_VObj802A78E4_802a78e4_802A7848*)this)->m0(arg1, arg2);
    temp_r31 = ((TLobby *)temp_r3)->write_packet_header(arg3, temp_r0, 0x4000);
    mem_free((void *)temp_r3);
    return temp_r31;
}

s32 TUnk_804DDD28::load_action_motion_pairs(s32 arg1, s32 arg2, s32 arg3) {
    Pair_802A7994 sp8;
    s32 *slots;
    s32 i;
    s32 f4;
    s32 pkt;
    u8 *dst;
    s32 *drop;
    if (this->vfunc_4() == 0U) {
        return 0;
    }
    slots = ((VObj_802A7994 *)this)->m6(arg2, arg3);
    if (slots == NULL) {
        return 0;
    }
    TLobby__sub_802A7BC8(&sp8);
    dst = ((VObj_802A7994 *)this)->m75(arg2);
    for (i = 0; i < this->vfunc_75(); i++) {
        ((void (*)(s32, void *))set_slot_position__6TLobbyFii)(*slots, &sp8);
        f4 = ((TLobby *)(&sp8))->get_field_04();
        pkt = ((TLobby *)this)->send_packet(arg1, i, f4, ((TLobby *)(&sp8))->get_param());
        if (pkt != 0) {
            drop = (s32 *)TItemDrop__sub_800F9448(((VObj_802A7994 *)this)->m0(arg1, i), pkt);
        }
        ((TUnk_804DDD28 *)dst)->copy_motion_pair(*(void **)drop);
        slots++;
        dst += 8;
    }
    return 1;
}

void TUnk_804DDD28::copy_motion_pair(void*q) { *(u32*)((char*)this + 0x0) = *(u32*)((char*)q + 0x0); this->m_4 = *(u32*)((char*)q + 0x4); }

u8 *TUnk_804DDD28::vfunc_3(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)((u8 *)this) + 8) = &lbl_804DDD28.value;
        TLobby::free_if_positive((s32) this, -1);
        if (arg1 > 0) {
            free__10TObjPlayerFPv((this));
        }
    }
    return ((u8 *)this);
}

typedef char RecoveredGlobal_802A7B50_lbl_804DDD28_size[sizeof(RecoveredGlobal_802A7B50_lbl_804DDD28) == 0x138 ? 1 : -1];
u8 *TLobby__sub_802A7B50(u8 *arg0) {
    *(s32 **)((s8 *)arg0 + 8) = &(*(RecoveredGlobal_802A7B50_lbl_804DDD28 *)&lbl_804DDD28).value;
    ((TUnk_804DDD28 *)arg0)->sub_802A7318();
    return arg0;
}

int TLobby__sub_802A7B8C(void) { return 0; }
int TUnk_804DDD28::vfunc_4() { return 0; }
int TUnk_804DDD28::vfunc_8(s32, s32) { return 0; }
int TUnk_804DDD28::vfunc_9(s32, s32, s32) { return 0; }
void TUnk_804DDD28::vfunc_14() {  }
int TUnk_804DDD28::vfunc_75() { return 0; }
s32 TLobby::get_param() { return *(s32 *)&this->m_name; }
s32 TLobby::get_field_04() { return *(s32 *)&this->m_flags; }
void TLobby__sub_802A7BC8(void* p) { *(s32*)((char*)p + 0x0) = 0; *(s32*)((char*)p + 0x4) = 0; }
void TLobby__sub_802A7BD8(void) {
    if ((u32) snapshot_image_buffer != 0U) {
        mem_free(((void*)snapshot_image_buffer));
        snapshot_image_buffer = 0U;
    }
}
}
extern void *shared_snapshot_capture;
extern s32 snapshot_buffer_size;
s32 copy_if_space(void);
s32 copy_if_space(void) {
    if (fn_802A5C3C((u32 *)shared_snapshot_capture) >= 0x258) {
        return 0;
    }
    memcpy((*(s32 *)&snapshot_image_buffer), ((TWindowSnapShot *)shared_snapshot_capture)->get_size(), snapshot_buffer_size);
    return 1;
}

void TLobby::alloc_snapshot_buffer() {
  s32 temp_r31;
  s32 max_players;
  u32 temp_r3;
  u8 *temp_r31_3;
  if (((u32) snapshot_image_buffer) == 0U)
  {
    temp_r31 = TWindowSnapShot::get_height();
    max_players = TLobby::get_max_players();
    max_players = max_players * temp_r31;
    temp_r31 = TWindowSnapShot::get_width();
    temp_r31_3 = (u8 *) (temp_r31 + max_players);
    temp_r3 = ((int)mem_alloc((u32)temp_r31_3));
    snapshot_image_buffer = temp_r3;
    if (temp_r3 != 0U)
    {
      (*(u8 * *)&snapshot_buffer_size) = temp_r31_3;
    }
  }
}

void set_slot_position__6TLobbyFii(s32 arg0, s32 arg1) {
    s32 temp_r31;
    temp_r31 = ((RlcHeader *)(*(s32 *)&snapshot_image_buffer))->get_directory_offset();
    temp_r31 = (*(s32 *)&snapshot_image_buffer) + temp_r31;
    temp_r31 = temp_r31 + arg0 * 8;
    fn_802A6078(arg1, lbl_805D669C + ((RlcDirectoryEntry *)temp_r31)->get_offset());
    fn_802A6070(arg1, ((RlcDirectoryEntry *)temp_r31)->get_size());
}
void TLobby::send_type2_event(s32 arg0, s32 arg1, s32 arg2) {
    aram_dma_blocking__6TLobbyFllll(2, arg0, arg1, arg2, arg0);
}

extern "C" {

int get_resource_file_size__6TLobbyFv(void);
int Dolphin_ARAlloc(void);

    extern int snapshot_aligned_buffer_size;
void TWindowSnapShot::init_default() { TLobby::aram_transfer_sync((s32)((void*)1), (u32)((void*)((TWindowSnapShot *)shared_snapshot_capture)->get_field_8()), lbl_805D669C, snapshot_aligned_buffer_size); }

void TWindowSnapShot__sub_802A7DA0(void) {  }

void TWindowSnapShot::alloc_buffer() { TWindowSnapShot__sub_802A7EAC(); snapshot_aligned_buffer_size = ((get_resource_file_size__6TLobbyFv() + 0x1f) & 0xffffffe0); lbl_805D669C = Dolphin_ARAlloc(); }

}

struct Base_802A7DDC { char pad[0x3C]; };
struct VObj_802A7DDC : Base_802A7DDC {
    virtual void m0(int);
};

struct Stack_802A7F00 {
    f32 sp8;
    f32 spC;
};

struct RecoveredGlobal_802A7FB0_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

#pragma push
#pragma readonly_strings on
const char *TWindowSnapShot__name = "TWindowSnapShot";
#pragma pop

// inferred: window_snapshot_layout_entries, the layout table window_snapshot_layout points at
// (a sprite part and a text line).
struct SnapShotWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec_0;
    TextLayoutRecord rec_1;
};

extern s32 lbl_805D63F0;

SnapShotWindowLayout window_snapshot_layout_entries = {
    2, 1,
    {6, {372.0f, 240.0f}, {18.0f, 18.0f}, 178.0f, 203.0f, 0.5f, -1, &lbl_805D63F0, 0, 4},
    {3, {399.0f, 240.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
};

WindowDescriptor window_snapshot_layout = {
    {512.0f, 280.0f}, 50100.0f, &window_snapshot_layout_entries, 3,
};

struct RecoveredGlobal_802A80A0___vt__15TWindowSnapShot {
    s32 value;
    u8 remaining[0x14];
};

extern int player_motion_data_filename_ptr;
extern "C" {
s32 TObjBoss2Tunnel__sub_8007CAE8(f32 *, f32);
u8 *draw_default_entry__9TWindowDDFl();
s32 draw_visible_window_entries(void *, void *, void *);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
extern RecoveredGlobal_802A7FB0_lbl_8050E208 controller_input_state;
s32 verify_snapshot_checksum__15TObjBoss2TunnelFv(void);
extern s32 __vt__15TWindowSnapShot[];
s32 play_sound_effect(s32, s32, s32, s32);
void __dl__7TObjectFPv(void *);

void TWindowSnapShot::free_shared_instance() {
    struct VObj_802A7DDC *o;
    ((TWindowSnapShot *)shared_snapshot_capture)->update_both();
    o = (struct VObj_802A7DDC *)shared_snapshot_capture;
    if (o != NULL) {
        o->m0(1);
    }
    shared_snapshot_capture = NULL;
}
}

s32 load_player_motion_data(void) {
    s32 temp_r3;
    s32 var_r0;
    if ((void *) (*(u8 * *)&shared_snapshot_capture) != NULL) {
        return 0;
    }
    temp_r3 = (int)::operator new(0x40);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (((TWindowSnapShot *)temp_r3)->init_and_reset());
    }
    (*(u8 * *)&shared_snapshot_capture) = (unsigned char *) ((void *) var_r0);
    if ((u32) var_r0 == 0U) {
        return 0;
    }
    ((TWindowSnapShot *)var_r0)->start_capture((*(s32 *)&player_motion_data_filename_ptr));
    return 1;
}

s32 TWindowSnapShot::get_size() { return *(s32 *)&this->m_name; }
s32 TWindowSnapShot::get_field_8() { return *(s32 *)&this->m_prev; }
int TWindowSnapShot::get_height() { return 600; }

int TWindowSnapShot__sub_802A7EAC(void) {  return player_motion_data_filename_ptr; }

void TWindowSnapShot::play_open_sound() {
    play_sound_effect(0x52F16, 0, 0, 0);
    this->m_60 = (u8) (this->m_60 | 1);
}

void render__15TWindowSnapShotFv(u8 *arg0) {
    Stack_802A7F00 stack;
    u8 *temp_r3;
    temp_r3 = draw_default_entry__9TWindowDDFl();
    ((TWindowBase *)arg0)->draw_window_frame(temp_r3);
    draw_visible_window_entries(arg0, arg0 + 0x24, temp_r3);
    if (!(((TWindowSnapShot *)arg0)->m_60 & 2)) {
        if ((s32) *(s32 *)((s8 *)temp_r3 + 0x30) > 0) {
            stack.sp8 = 18.0f + *(f32 *)((s8 *)temp_r3 + 0x10);
            stack.spC = *(f32 *)((s8 *)temp_r3 + 0x14);
            TObjBoss2Tunnel__sub_8007CAE8(&stack.sp8, 18.0f);
        }
    } else {
        draw_window_text((f32 *)(temp_r3 + 0x10), (const char *)(get_localized_text_entry(0x24, 7)), -1, 0, 1000000.0f);
    }
}

typedef char RecoveredGlobal_802A7FB0_lbl_8050E208_size[sizeof(RecoveredGlobal_802A7FB0_lbl_8050E208) == 0x1B0 ? 1 : -1];
void TWindowSnapShot::run_task() {
    u8 *arg0 = (u8 *)this;
    if (!(this->m_2c & 2)) {
        this->m_5c = 0x01000000;
    }
    if ((TWindowShortListCtrl__check_controller_button((void *) ((u8 *)&controller_input_state.value + 0x20), 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 2) != 0)) {
        play_open_sound();
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_fade();
    ((TWindowBase *)arg0)->update_window_entry_list((u8 *)&this->m_24);
}

void *__dt__15TWindowSnapShotFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TWindowSnapShot;
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_802A80A0___vt__15TWindowSnapShot_size[sizeof(RecoveredGlobal_802A80A0___vt__15TWindowSnapShot) == 0x18 ? 1 : -1];
u8 *TWindowSnapShot__ct(TWindowSnapShot *window_snap_shot, s32 arg1) {
    s32 temp_r31;
    ((TWindowDD *)window_snap_shot)->construct_base((u8 *)&window_snapshot_layout, (s16)4, (u8 *)arg1);
    *(s32 **)((s8 *)window_snap_shot + 0x18) = &(*(RecoveredGlobal_802A80A0___vt__15TWindowSnapShot *)&__vt__15TWindowSnapShot).value;
    *(s32 *)((s8 *)window_snap_shot + 0) = (s32) TWindowSnapShot__name;
    window_snap_shot->m_60 = 0U;
    if (verify_snapshot_checksum__15TObjBoss2TunnelFv() == 0) {
        window_snap_shot->m_60 = (u8) (window_snap_shot->m_60 | 2);
    }
    temp_r31 = ((TWindowBase *)window_snap_shot)->get_array_entry(1);
    TWindowDuelResult::set_default_status((void *) temp_r31, get_localized_text_entry(0xF, 0x13));
    return (u8 *)window_snap_shot;
}

void *shared_snapshot_capture;
u32 snapshot_image_buffer;
s32 snapshot_buffer_size;
s32 lbl_805D669C;
int snapshot_aligned_buffer_size;
