#ifndef PSO_OBJECT_TOBJMAPCSN_H
#define PSO_OBJECT_TOBJMAPCSN_H

#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/vector.h"

// object set data passed (as an address) to TObjMapCsn::create
struct MapCsnSetData {
    u8 pad_0[0xC];
    Vec position;
    s32 rotation_x;
    s32 rotation_y;
    s32 rotation_z;
    Vec scale;
    s32 params[2];
};

struct TObjMapCsn : public TObjCollidable {
    virtual ~TObjMapCsn();
    u32 m_ac;
    void* m_b0;
    u8 unk_B4[0x8];
    f32 m_bc;
    u32 m_c0;
    u32 m_c4;
    u32 m_c8;
    u32 m_cc;
    u32 m_d0;
    void* m_d4;
    u8 _padD8[0x11C];
    void* m_1f4;
    virtual void render();
    void update_state();
    s32 build_box_triangles();
    static s32 create(s32 arg0);
    void*get_data_ptr();
    static s32 get_map_count();
    void*init();
    static s32 init_and_return(s32 arg0);
    u8 unk_1F8[0x5C];
};

typedef char TObjMapCsn_size[sizeof(TObjMapCsn) == 0x254 ? 1 : -1];
#endif
