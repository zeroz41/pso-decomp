#ifndef PSO_UNK_TLOBBY_801D6DC4_H
#define PSO_UNK_TLOBBY_801D6DC4_H

#include "types.h"

extern "C" {
u8 TLobby__sub_801D6DDC(void *record);
}

struct ClampValueBelow200Object { u8 pad[0x16]; s16 v; };

struct NormalizeBattleRuleValueObject { u8 pad[0xB]; u8 v; };

struct TLobbyObject { u8 pad[0xE]; u8 v; };

struct ClampValueBelow2Object { u8 pad[0xD]; u8 v; };

struct TLobbyObject2 { u8 pad[0xC]; u8 v; };

struct GetRuleFieldAObject { u8 pad[0xA]; u8 v; };

struct ClampRuleValue2Object { u8 pad[0x8]; u8 v; };

struct NormalizeBattleRuleValueBObject { u8 pad[0x9]; u8 v; };

struct TLobbyObject3 { u8 pad[0x7]; u8 v; };

#endif
