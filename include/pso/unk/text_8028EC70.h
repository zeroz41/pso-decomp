#ifndef PSO_UNK_TEXT_8028EC70_H
#define PSO_UNK_TEXT_8028EC70_H

#include "types.h"

extern "C" {
void TAdSinglePlyChrSelectGC__sub_8028ED54(saddr part);
}

// Steps one appearance part up, then down, to the first variant no saved character uses.
s32 select_unused_appearance_part(void *appearance, s32 part);

#endif
