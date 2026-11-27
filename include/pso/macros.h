#ifndef PSO_MACROS_H
#define PSO_MACROS_H

/* PSO engine macros.
 * Derived from pso-gc-reference decomp (mrb0nk500).
 * Adapted for GPOE8P (PSO EP I&II Plus, MWCC 2.6).
 */

#define EXTERN_OBJECT_NAME(name) extern const char *name##_name;
#define OBJECT_NAME(name) const char *name##_name = #name;

#define OBJECT_NAMES \
    o(TObject) \
    o(TMainTask)

#define TL_OBJECTS \
    o(tl_su, TL_SU) \
    TL_OBJECTS_AT_TL_00

#define TL_OBJECTS_AT_TL_00 \
    TL_00_OBJECTS \
    TL_02_OBJECTS \
    o(tl_particle, TL_PARTICLE) \
    TL_PARTICLE_MODEL_OBJECTS

#define TL_OBJECTS_AT_TL_00_WITHOUT_TL_PARTICLE \
    TL_00_OBJECTS \
    TL_02_OBJECTS \
    TL_PARTICLE_MODEL_OBJECTS

#define TL_OBJECTS_AT_TL_02 \
    TL_02_OBJECTS \
    o(tl_particle, TL_PARTICLE) \
    TL_PARTICLE_MODEL_OBJECTS

#define TL_00_OBJECTS \
    o(tl_00, TL_00) \
    o(tl_camera, TL_CAMERA) \
    o(tl_01, TL_01)

#define TL_02_OBJECTS \
    o(tl_02, TL_02) \
    o(tl_item_equip, TL_ITEM_EQUIP) \
    o(tl_03, TL_03) \
    o(tl_loc_start, TL_LOC_START) \
    o(tl_04, TL_04) \
    o(tl_05, TL_05) \
    o(tl_06, TL_06) \
    o(tl_07, TL_07) \
    o(tl_loc_end, TL_LOC_END) \
    o(tl_window, TL_WINDOW)

#define TL_PARTICLE_MODEL_OBJECTS \
    o(tl_particlemodel, TL_PARTICLEMODEL) \
    o(tl_radermap, TL_RADERMAP) \
    o(tl_clipout, TL_CLIPOUT) \
    o(tl_fade, TL_FADE) \
    o(tl_fadeafter, TL_FADEAFTER)

/* Declaration order of the task layers (TObject.cpp's .sdata and .sbss);
 * init_main_task creates tl_item_equip before tl_03. */
#define TL_OBJECTS_IN_ADDRESS_ORDER \
    o(tl_su, TL_SU) \
    o(tl_00, TL_00) \
    o(tl_camera, TL_CAMERA) \
    o(tl_01, TL_01) \
    o(tl_02, TL_02) \
    o(tl_03, TL_03) \
    o(tl_item_equip, TL_ITEM_EQUIP) \
    o(tl_loc_start, TL_LOC_START) \
    o(tl_04, TL_04) \
    o(tl_05, TL_05) \
    o(tl_06, TL_06) \
    o(tl_07, TL_07) \
    o(tl_loc_end, TL_LOC_END) \
    o(tl_window, TL_WINDOW) \
    o(tl_particle, TL_PARTICLE) \
    TL_PARTICLE_MODEL_OBJECTS

#define __packed__

#define WEAK_FUNC __declspec(weak)

#define as(type, var) reinterpret_cast<type>(var)

#define PRIVATE_MEMBER_GETTER(type, name) \
    type name() { \
        return m_##name; \
    }

#define PRIVATE_MEMBER_SETTER(type, name) \
    void set_##name(type val) { \
        m_##name = val; \
    }

#define PRIVATE_MEMBER_ACCESSORS(type, name) \
    PRIVATE_MEMBER_GETTER(type &, name); \
    PRIVATE_MEMBER_SETTER(type, name)

#define PRIVATE_MEMBER_ACCESSORS_NON_REF(type, name) \
    PRIVATE_MEMBER_GETTER(type, name); \
    PRIVATE_MEMBER_SETTER(type, name)

#define ABS(x) ((x) < 0 ? -(x) : (x))

#endif
