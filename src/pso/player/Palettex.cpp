#include "types.h"
#include "pso/player/Palettex.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/quest/TQuestThread.h"
#include "pso/system/data/FlagWord.h"
#include "pso/ui/frontend/TAdPlyPltAnimCtrlGC.h"
#include "pso/ui/frontend/TAdRicoRing_8001BEE8.h"

// The palette state of one client: its flags and the quest label run_palettex_callback starts.
struct PalettexState {
    FlagWord flags;
    s32 callback_label;

    PalettexState();
    ~PalettexState();
    void run_callback();
    s32 get_callback_label();
    void set_callback_label(s32 label);
    u8 is_enabled();
    void disable();
    void enable();
    s32 is_activated();
    void restore();
    void activate();
    void reset();
};

// The original's static initializer precedes this file's inline copies, which a
// compiler-generated one never does, so the initializer is spelled out.
struct DestructorChain {
    DestructorChain *next;
    void *destructor;
    void *object;
};
extern "C" {
static void __sinit_Palettex_cpp();
static void destroy_palettex_states();
PalettexState *__ct__13PalettexStateFv(PalettexState *self);
void __dt__13PalettexStateFv(PalettexState *self, s16 mode);
void __construct_array(void *array, void *ctor, void *dtor, u32 size, u32 count);
void __destroy_arr(void *array, void *dtor, u32 size, u32 count);
void *__register_global_object(void *object, void *destructor, void *chain);
}
#pragma push
#pragma suppress_init_code on
#pragma no_static_dtors on
static DestructorChain palettex_states_dtor_chain;
PalettexState palettex_states[4];
#pragma pop
__declspec(section ".ctors") static void *const palettex_initializer = (void *)__sinit_Palettex_cpp;

void run_palettex_callback(u16 client_index) {
    if (is_local_client(client_index) != 0) {
        palettex_states[client_index].run_callback();
    }
}

void set_palettex_callback(u16 client_index, s32 label) {
    if (is_local_client(client_index) != 0) {
        palettex_states[client_index].set_callback_label(label);
    }
}

u8 TObjPlayer__sub_80354C7C(u16 client_index) {
    if (is_local_client(client_index) != 0) {
        return palettex_states[client_index].is_enabled();
    }
    return 0;
}

void TObjPlayer__sub_80354CCC(u16 client_index) {
    if (is_local_client(client_index) != 0) {
        palettex_states[client_index].disable();
    }
}

void TObjPlayer__sub_80354D14(u16 client_index) {
    if (is_local_client(client_index) != 0) {
        palettex_states[client_index].enable();
    }
}

s32 is_palettex_activated(u16 client_index) {
    if (is_local_client(client_index) != 0) {
        return palettex_states[client_index].is_activated();
    }
    return 0;
}

void TObjPlayer__sub_80354DAC(u16 client_index) {
    if (is_local_client(client_index) != 0) {
        palettex_states[client_index].restore();
    }
}

void activate_palettex(u16 client_index) {
    if (is_local_client(client_index) != 0) {
        palettex_states[client_index].activate();
    }
}

s32 is_local_client(u16 client_index) {
    TObjPlayer *player = get_player_by_client_id(client_index);
    if (player == NULL) {
        return 0;
    }
    if (TObjPlayer::is_locally_controlled(player) != 0) {
        return 1;
    }
    return 0;
}

void reset_client_quest_slot_table() {
    s32 i;
    for (i = 0; i < 4; i++) {
        palettex_states[i].reset();
    }
}

void PalettexState::run_callback() { TQuestThread::create_in_root(get_callback_label()); }


static void __sinit_Palettex_cpp() {
    __construct_array(palettex_states, (void *)__ct__13PalettexStateFv, (void *)__dt__13PalettexStateFv,
        sizeof(PalettexState), 4);
    __register_global_object(NULL, (void *)destroy_palettex_states, &palettex_states_dtor_chain);
}

static void destroy_palettex_states() {
    __destroy_arr(palettex_states, (void *)__dt__13PalettexStateFv, sizeof(PalettexState), 4);
}

inline s32 PalettexState::get_callback_label() { return callback_label; }
inline void PalettexState::set_callback_label(s32 label) { callback_label = label; }
inline u8 PalettexState::is_enabled() { return fn_8035510C(&flags.bits, 3); }
inline void PalettexState::disable() { flags.clear(2); }
inline void PalettexState::enable() { flags.set(3); }
inline s32 PalettexState::is_activated() { return test_flags_any(&flags.bits, 1); }
inline void PalettexState::restore() { flags.clear(3); }
inline void PalettexState::activate() { flags.set(1); }
inline void PalettexState::reset() {
    flags.reset();
    callback_label = 0;
}

PalettexState::~PalettexState() {}

PalettexState::PalettexState() { reset(); }
