#ifndef PSO_UNK_TEXT_80355970_H
#define PSO_UNK_TEXT_80355970_H

#include "types.h"
#include "pso/system/vector.h"

// Defined in TBoss5GryphonTornado.cpp: drops a tornado onto the floor under pos_src
// (none when no floor is found within the start height). gryphon is the TBoss5Gryphon that
// launched it (the shock wave passes its owner); kind is stored as the tornado's u16 m_24.
extern "C" {
s32 spawn_gryphon_tornado(s32 parent, s32 gryphon, const Vec *pos_src, u16 kind);
}

#endif
