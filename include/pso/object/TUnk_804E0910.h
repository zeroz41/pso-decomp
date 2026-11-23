#ifndef PSO_OBJECT_TUNK_804E0910_H
#define PSO_OBJECT_TUNK_804E0910_H
#include "types.h"
#include "pso/object/TObjPathObj.h"

struct NJS_OBJECT;

class TUnk_804E0910 : public TObjPathObj {
public:
    TUnk_804E0910(TObject *parent, void *set_data);
    static void *create(void *set_data);
    static void load_static_resource();
    static void destroy_instance();
    virtual ~TUnk_804E0910();
    s32 sub_802C1E34();
    s32 sub_802C1BFC();
    virtual void vfunc_13();
    virtual void vfunc_14();
    // get_bml_model(archive, 0), drawn posed by the m_9c motion (name inferred).
    NJS_OBJECT *motion_model;
    saddr m_9c;
    u8 unk_A0[0x4];
    f32 m_a4;
    f32 m_a8;
    u8 unk_AC[0xC];
    s32 m_b8;
    u8 unk_BC[0x4];
    s32 m_c0;
    u8 unk_C4[0x4];
    s32 m_c8;
};
LAYOUT_ASSERT(TUnk_804E0910_size, sizeof(TUnk_804E0910) == 0xCC);

#endif
