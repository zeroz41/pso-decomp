#ifndef PSO_OBJECT_TUNK_804E094C_H
#define PSO_OBJECT_TUNK_804E094C_H
#include "types.h"
#include "pso/object/TObjPathObj.h"

struct NJS_OBJECT;

class TUnk_804E094C : public TObjPathObj {
public:
    TUnk_804E094C(TObject *parent, void *set_data);
    virtual ~TUnk_804E094C();
    s32 sub_802C2548();
    s32 update_path_follow_rotation(void *, f32);
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
LAYOUT_ASSERT(TUnk_804E094C_size, sizeof(TUnk_804E094C) == 0xCC);

#endif
