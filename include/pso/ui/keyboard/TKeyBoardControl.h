#ifndef PSO_UI_KEYBOARD_TKEYBOARDCONTROL_H
#define PSO_UI_KEYBOARD_TKEYBOARDCONTROL_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowKeyBoardBase;
struct TWindowKeyBoardHard;
struct TWindowKeyBoardSoft;

struct TKeyBoardControl : public TObject {
    TKeyBoardControl(TObject *parent, u32 width, u32 lines, u8 mode, s32 client);
    virtual ~TKeyBoardControl();
    virtual void render();
    virtual void run_task();
    u16 flags;
    s16 client_index;
    TWindowKeyBoardBase *m_base;
    TWindowKeyBoardHard *m_hard;
    TWindowKeyBoardSoft *m_soft;
    void hide();
    void show();
    void set_flag62_bit2();
    void set_soft_flag60_bit1();
    s32 get_cursor_position();
    void set_depth(f32 depth);
    void set_position(void *pos);
    void set_soft_position(u8 *pos);
    void set_hard_position(u8 *pos);
    void set_sub_position(u8 *pos);
    void set_text(const char *s);
    char *realloc_buffer();
    int is_cancelled();
    int is_confirmed();
    static void run_main_frame();
    static void run_tasks();
    static void update();
    static s32 get_input();
    static s32 get_key_state();
    static void alloc_buffer();
    void clear_keyboard_flag60_bit1();
    void set_composer_flag62_bit4();
    static void update_main_menu_scene();
    static void clear_main_menu_scene_flag();
    static void dispatch_select_phase(TObject *fade);
};

LAYOUT_ASSERT(TKeyBoardControl_size, sizeof(TKeyBoardControl) == 0x2C);

extern u8 main_menu_scene_active_flag;

// One controller's state in keyboard_control_pad_slots (0x34 bytes, four of them),
// filled by read_pads and returned by get_pad_slot.
struct PadSlot {
    s32 f0;
    s32 f4;
    u32 held;
    u32 notHeld;
    u32 pressed;
    u32 released;
    u16 trigR;
    u16 trigL;
    s16 stickX;
    s16 stickY;
    s16 substickX;
    s16 substickY;
    u8 reserved[0xC];
    s32 *conn;
};

extern PadSlot keyboard_control_pad_slots[4];

// One pad button and the game button map_pad_buttons reports for it.
struct PadButtonMapping {
    u32 pad_mask;
    u32 button;
};

extern PadButtonMapping pad_button_map_table[12];

struct PADStatus;

// Device codes 0, 6, 12 and 18 select slots 0-3; any other code gives slot 0.
PadSlot *get_pad_slot(u32 device);
// Points the four slots at their status buffers and reads the pads once.
void init_pad_slots_and_read(s32, s32, s32);
// Reads the four pads into keyboard_control_pad_slots: held, pressed and released buttons and scaled sticks.
void read_pads(void);
// Maps PAD button bits to the game's button bits.
s32 map_pad_buttons(u16 button_bits);
// Scales a stick value from the pad's +-89 range to +-128.
s16 scale_axis_value(s16 x);
// Clamps the main stick of one pad status to +-89 on both axes.
void clamp_pad_axes(PADStatus *pad);
void init_light_globals(s32, s32);

void set_model_render_flags(u32 flags);

#endif
