#include "types.h"
#include "pso/render/render_util.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/TEffect.h"
#include "pso/system/PadRumble.h"
#include "pso/ui/keyboard/TKeyBoardControl_803DE9C4.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/stelth/TObjEneMe3Stelth.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSnapShot.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"
#include "pso/render/BlobShadow.h"



struct RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270 {
    s32 value;
    u8 remaining[0xAC];
};

struct RecoveredGlobal_8000F9E4_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F90C_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F9CC_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F8FC_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F8EC_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F91C_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct G_8000F92C { s32 f0; s32 f4; s32 f8; s32 fc; s32 f10; };

struct G_8000F9B0 { s32 f0; s32 f4; s32 f8; s32 fc; s32 f10; };

typedef struct GXColor_8000FA00 { u8 r, g, b, a; } GXColor_8000FA00;

struct Cfg_8000FAE4 {
    void *rmode;
    s32 count;
    u32 fb[3];
    u32 fbsize;
    u32 heap;
    u32 heapsize;
};

extern s32 lbl_805D49C0;
extern "C" {
void TKeyBoardControl__sub_8000F950(void);
void TKeyBoardControl__sub_8000F95C(void);
void mark_area_change_pending(void);
void clear_keyboard_key_state(void);
s32 disable_disconnected_ports__16TKeyBoardControlFv(void *);
void TKeyBoardControl__sub_8000F764(void);
void TKeyBoardControl__sub_8000F7FC(void);
extern RecoveredGlobal_8000F9E4_lbl_804FE120 main_phase_state;
void TKeyBoardControl__sub_8000F9E4(void);
void TKeyBoardControl__sub_8000F90C(s32 arg0);
void TKeyBoardControl__sub_8000F9CC(s32 arg0);
s32 get_main_phase(void);
s32 TKeyBoardControl__sub_8000F8EC(void);
void TKeyBoardControl__sub_8000F91C(s32 arg0);
bool is_keyboard_active(void);
s32 TKeyBoardControl__sub_8000F92C(void);
s32 request_queued_main_phase(void);
void GXSetCopyClear(GXColor_8000FA00 clear_clr, u32 clear_z);
void GXCopyDisp(void *dest, int clear);
void GXInitLightPos(void *lt_obj, f32 x, f32 y, f32 z);
void GXInitLightColor(void *lt_obj, GXColor_8000FA00 color);
void GXLoadLightObjImm(void *lt_obj, int light);
void GXSetChanAmbColor(int chan, GXColor_8000FA00 amb_color);
void GXSetChanMatColor(int chan, GXColor_8000FA00 mat_color);
s32 DVDInit();
u32 OSGetArenaHi();
u32 OSGetArenaLo();
s32 OSInit();
s32 OSSetArenaLo(u32);
void TLobby__sub_8007EB70(void);
void fn_800FFE10(void);
void install_depth_alpha_state(void);
void init_char_select_globals__23TAdSinglePlyChrSelectGCFv(void);
void reset_story_select__6TLobbyFv(void);
void TLobby__sub_8020E3C0(void);
s32 TLobby__sub_80226BA4();
void init_adx_audio_system(void);
void init_buffers(void);
void request_chara_making_archives(void);
void TCharaMaking__sub_8028E790(void);
s32 verify_game_file_integrity();
s32 TLobby__sub_8032C91C();
u32 OSInitAlloc(u32, u32, int);
s32 VIInit();
s32 PADInit();
s32 PADSetSpec(int);
s32 GXSetPixelFmt(int, int);
s32 init_debug_text_buffer(s32, int, int);
void set_debug_text_scale(u16 arg0);
void set_matrix_identity(u8 *arg0);
void init_record_and_slot_arrays(s32 arg0, s32 arg1, void *arg2, void *arg3);
u32 calc_framebuffer_size_bytes(int, void *);
void init_system_heap_and_global_allocator(u8 *start, s32 size);
s32 xmalloc__FUl(u32);
s32 init_pad_slots_and_read__16TKeyBoardControlFv(int, int, int);
void TObjPlayer__sub_803E492C(s32 a, s32 b);
int TKeyBoardControl__sub_8000F828(void);
int OSResetSystem(void*, void*, void*);
void TAdPlayerLoadGC__sub_801E1350(void);
void release_all__23TAdSinglePlyChrSelectGCFv(void);
void TAdWarningBaseGC__sub_8032D188(void);
int clear_split_screen_fog__8TFogCtrlFv(void*);
void TLobby__sub_80147978(void);
void TLobby__sub_8020E3BC(void);
}
extern s32 keyboard_active_flag;
void activate_keyboard(void);
void deactivate_keyboard(void);
extern s32 keyboard_key_state;
extern RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270 TKeyBoardControl__global_key_state;
extern u8 gx_default_light_obj[];
extern void *video_initial_draw_framebuffer;
extern void *video_initial_display_framebuffer;
extern GXColor_8000FA00 lbl_805D7D00;
extern GXColor_8000FA00 lbl_805D7D04;
extern GXColor_8000FA00 lbl_805D7D08;
extern const f32 lbl_805D7D0C;
extern const f32 lbl_805D7D10;
extern GXColor_8000FA00 lbl_805E1200;
void init_gx_lighting_defaults(void);
void init_disc_error_messages(void);
void load_menu_font(void);
void load_ply_level_tbl(void);
void init_particle_sprite_atlas(void);
void load_info_icon(void);
void init_video_and_gx(void *arg0);
extern u8 GXNtsc480IntDf[];
extern int lbl_805D49A0;
extern int lbl_805D49A4;
extern int player_matrix_stack_buffer;
extern s32 keyboard_input_buffer;
extern int resource_decompress_buffer;
void init_game_systems(void);
void shutdown_and_reset_system(void);
void update_music_sequencer(void);
extern "C" {
void update_global_sound_frame(void);
void TLobby__sub_8022809C(void);
void TLobby__sub_802433A8(void);
void TObjBoss2Tunnel__sub_8036EF4C(void);
void TObjPlayer__sub_80083FB0(void);
void TObjPlayer__sub_801D92A4(void);
void fn_800FFE0C(void);
void TWindowSnapShot__sub_802A7DA0(void);
void TWindowSubStatusDisp__sub_803386F0(void);
int VIWaitForRetrace(void);
int VIFlush(void);
int VISetBlack(void*);
int xfree__FPv(void*);

extern s32 lbl_805D62B0;

typedef char RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270_size[sizeof(RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270) == 0xB0 ? 1 : -1];
void TKeyBoardControl__sub_8000F764(void) {
    TKeyBoardControl::read_pads();
    disable_disconnected_ports__16TKeyBoardControlFv(&TKeyBoardControl__global_key_state.value);
    TKeyBoardControl::flush_input();
    update_pad_rumble();
    TLobby::reset_state_byte();
}

void TKeyBoardControl::run_tasks() {
    TObjPlayer__sub_80083FB0();
    update_global_sound_frame();
    if ((s32) lbl_805D62B0 != 0) {
        update_music_sequencer();
    }
    keyboard_task_object.run_tasks();
}

int TKeyBoardControl::get_fog_ctrl() { return clear_split_screen_fog__8TFogCtrlFv(this); }

void TKeyBoardControl__sub_8000F7FC(void) {
    end_of_render_root.run_tasks();
}

}
