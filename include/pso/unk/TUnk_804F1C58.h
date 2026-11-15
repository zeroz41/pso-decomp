#ifndef PSO_UNK_TUNK_804F1C58_H
#define PSO_UNK_TUNK_804F1C58_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804F1C58 : public TObject {
public:
    TUnk_804F1C58(TObject *parent, void *model);
    void set_field_38(s32 v);
    virtual ~TUnk_804F1C58();
    void *destroy(s16);
    void *model;
    s32 m_20;
    f32 m_24;
    void * m_28;
    s32 node_count;
    s32 m_30;
    s32 m_34;
    s32 m_38;
};
typedef char TUnk_804F1C58_size[sizeof(TUnk_804F1C58) == 0x3C ? 1 : -1];

#endif
