#ifndef PSO_ITEM_TRELDATAFILE_H
#define PSO_ITEM_TRELDATAFILE_H
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
// MallocLoadFilePrc.cpp loads by name are children of resource_load_task_root; their m_name
// points at their own copy of the name (inferred: a resource load task).
class TRelDataFile : public TObject {
public:
    TRelDataFile(TObject *parent);
    TRelDataFile();
    virtual ~TRelDataFile();

    u8 *data;
    s32 size;
    void *root;
    char name[17];
};
LAYOUT_ASSERT(TRelDataFile_size, sizeof(TRelDataFile) == 0x3C);

#endif
