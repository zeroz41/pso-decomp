#ifndef PSO_ITEM_TUNK_8049C658_H
#define PSO_ITEM_TUNK_8049C658_H
#include "types.h"
#include "pso/system/task/TObject.h"

// The 0x20-byte trailer at the end of a relocatable data file: where its list of u16 word
// offsets to patch sits, how many there are, and the offset of the file's root object.
struct RelFileTrailer {
    u32 reloc_offset;
    u32 reloc_count;
    u8 pad_8[8];
    u32 root_offset;
    u8 pad_14[0xC];
};

// A loaded relocatable data file: the image, its size and the relocated root. The ones
// TLobby_800F8AA8.cpp loads by name are children of resource_load_task_root; their m_name
// points at their own copy of the name (inferred: a resource load task).
class TUnk_8049C658 : public TObject {
public:
    TUnk_8049C658(TObject *parent);
    TUnk_8049C658();
    virtual ~TUnk_8049C658();

    u8 *data;
    s32 size;
    void *root;
    char name[17];
};
LAYOUT_ASSERT(TUnk_8049C658_size, sizeof(TUnk_8049C658) == 0x3C);

#endif
