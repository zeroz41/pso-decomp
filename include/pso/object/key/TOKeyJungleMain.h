#ifndef PSO_OBJECT_KEY_TOKEYJUNGLEMAIN_H
#define PSO_OBJECT_KEY_TOKEYJUNGLEMAIN_H

#include "types.h"
#include "pso/object/key/TOKey.h"

// The jungle main switch (bm_obj_jungle_mkey). Its switch is a story flag
// (TOKeyJungleMain__data_804653C8[switch_id], set param 4 clamped to 0-2)
// that TODoorJungleMain also reads.
struct TOKeyJungleMain : public TOKey {
    TOKeyJungleMain(TObject *parent, void *set_data);
    virtual ~TOKeyJungleMain();
    virtual void update_lock_state();
    virtual void update_switch_on();
    virtual void update_switch_off();
    virtual void send_switch_on();
    virtual void debug_draw_key_id();
    virtual void play_activate_sound();
    void render();
    static void init_key_slots(void* _w0);
    f32 switch_frame;   // the fe_obj_start_switch motion's frame
    f32 sw_naka_frame;  // the fe_obj_start_sw_naka motion's frame
    static void dispatch_by_phase(s32 arg0, u16 arg1);
    static void *create(void *arg0);
    static void release_static_resource();
    static void load_static_resource();
};

// The story flag of each key (switch_id 0-2).
extern const s32 TOKeyJungleMain__data_804653C8[3];

typedef char TOKeyJungleMain_size[sizeof(TOKeyJungleMain) == 0xF0 ? 1 : -1];
#endif
