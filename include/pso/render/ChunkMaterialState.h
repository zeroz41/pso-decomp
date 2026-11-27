#ifndef PSO_RENDER_CHUNKMATERIALSTATE_H
#define PSO_RENDER_CHUNKMATERIALSTATE_H
#include "types.h"
#include "pso/system/NinjaTypes.h"
extern "C" {
void set_chunk_material_override_pair(s32 first, s32 second);
// Sets up the matrix stack of depth entries in the locked cache, its first entry the identity.
void init_matrix_stack(void *buffer, s32 depth);
}
void submit_chunk_material_color(s32 chunkType, s16 *packedMaterial);
// Sets the material colour the constant-material draw uses, each channel
// clamped to [-1, 1] (njSetConstantMaterial).
void set_constant_material(const NJS_ARGB *color);
void init_light_globals(s32, s32);
void set_model_render_flags(u32 flags);
extern "C" {
f32 clampMaterialChannel(f32 value, f32 lower, f32 upper);
void set_chunk_material_override_pair(s32 first, s32 second);
}

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

#endif
