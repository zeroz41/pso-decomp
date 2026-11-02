#include "types.h"

// Per-technique boost factors (19 techniques), one row per class row below.
static const f32 lbl_804493E8[19] = {
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
};
static const f32 lbl_80449434[19] = {
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.5f,
    1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
};
static const f32 lbl_80449480[19] = {
    0.0f, 0.3f, 0.3f, 0.0f, 0.3f, 0.3f, 0.0f, 0.3f, 0.3f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
};
static const f32 lbl_804494CC[19] = {
    0.3f, 0.0f, 0.0f, 0.3f, 0.0f, 0.0f, 0.3f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,
};
static const f32 lbl_80449518[19] = {
    0.0f, 0.3f, 0.0f, 0.0f, 0.3f, 0.0f, 0.0f, 0.3f, 0.0f, 0.3f,
    1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
};

extern "C" {
s8 TObjPlayer__sub_801AFDBC(s8);

// Technique boost row per character class (12 classes).
const f32 *class_technique_boost_table[12] = {
    lbl_804493E8, lbl_804493E8, lbl_804493E8, lbl_804493E8, lbl_804493E8, lbl_804493E8,
    lbl_80449434, lbl_80449480, lbl_804494CC, lbl_804493E8, lbl_80449518, lbl_804493E8,
};

f32 get_class_technique_boost(s8 arg0, s16 arg1);
f32 get_class_technique_boost(s8 arg0, s16 arg1) {
    return class_technique_boost_table[TObjPlayer__sub_801AFDBC(arg0)][arg1];
}

}
