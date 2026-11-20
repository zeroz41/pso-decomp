#ifndef PSO_UNK_TEXT_80072004_H
#define PSO_UNK_TEXT_80072004_H

#include "types.h"
#include "pso/player/TPlyGuildCardTag.h"

// gc_tag's out-of-line constructor, destructor and init() (the copies kept
// are pso/player/TPlyDispConfig.cpp's), called by hand on raw memory from
// functions that are not real constructors/destructors yet:
// - TObjPlayer::init_subobject constructs the gc_tag at +4 after storing the
//   lbl_804C3E50 vtable, and TObjPlayer__sub_801BF9F0 is the matching
//   destructor; TObjPlayer.cpp inlines in-class inlines (dont_inline off), so
//   it cannot call gc_tag's own inline members there.
// - the lock-on cursor code constructs and destroys gc_tag base subobjects.
// Drop these once those callers are the real constructors/destructors.
extern "C" {
gc_tag *__ct__6gc_tagFv(gc_tag *self);
gc_tag *__dt__6gc_tagFv(gc_tag *self, s16 flags);
void init__6gc_tagFv(gc_tag *self);
}

#endif
