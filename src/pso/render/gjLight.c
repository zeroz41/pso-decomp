/* Ginja's lights: the ambient colour, the colour channel's light mask and the five GX light objects. */
#define PSO_SDK_COMPACT_MATH
#include <dolphin/os.h>
#include <dolphin/gx.h>
#include "types.h"
#include "pso/render/gjLight.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/unk/text_803DD5E0.h"

#pragma scheduling off

u32 light_slot_mask_table[5] = { 1, 2, 4, 8, 16 };

void assert_light_id(s32 light) {
    if (light < 0 || light > 5) {
        OSPanic("gjLight.c", 0x12, "illegal Light ID.");
    }
}

void set_light_ambient_color(f32 r, f32 g, f32 b) {
    GXColor c;
    if (r >= 1.0f) {
        r = 1.0f;
    }
    if (g >= 1.0f) {
        g = 1.0f;
    }
    if (b >= 1.0f) {
        b = 1.0f;
    }
    c.r = (u8)(255.0f * r);
    c.g = (u8)(255.0f * g);
    c.b = (u8)(255.0f * b);
    c.a = 0xFF;
    GXSetChanAmbColor(GX_COLOR0A0, c);
}

void submit_light0(s32 light, s32 enable) {
    assert_light_id(light);
    if (enable == 0) {
        gx_chan_ctrl_light_mask &= ~light_slot_mask_table[light];
    } else {
        gx_chan_ctrl_light_mask |= light_slot_mask_table[light];
    }
}

void set_gx_light_color(s32 light, f32 r, f32 g, f32 b) {
    GXColor c;
    assert_light_id(light);
    c.r = (u8)(255.0f * r);
    c.g = (u8)(255.0f * g);
    c.b = (u8)(255.0f * b);
    c.a = 0xFF;
    GXInitLightColor(&gx_light_objects[light], c);
}

void init_distant_light(s32 light, f32 x, f32 y, f32 z) {
    assert_light_id(light);
    if (light == 0) {
        GXInitLightPos(&gx_light_objects[light], light_position_distance * -x, light_position_distance * -y,
                       light_position_distance * -z);
    } else {
        GXInitLightDir(&gx_light_objects[light], x, y, z);
    }
}

void load_gx_light_slot(s32 light) {
    assert_light_id(light);
    GXLoadLightObjImm(&gx_light_objects[light], light_slot_mask_table[light]);
}
