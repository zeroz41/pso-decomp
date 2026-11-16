#include "types.h"
#include <stddef.h>
#include "pso/quest/TQuestVmDownLoadServer_803E6970.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/quest/QuestDownloadServer.h"

// inferred: length-prefixed byte strings (the length counts itself), indexed by the off field of
// the match entries below.
const u8 quest_download_lz_match_strings[] = {
    0x00,
    0x01,
    0x02, 0xC3,
    0x02, 0xE9,
    0x02, 0xEA,
    0x02, 0xEB,
    0x02, 0xEC,
    0x02, 0xED,
    0x02, 0xAB,
    0x02, 0xAD,
    0x02, 0xAF,
    0x02, 0xB1,
    0x02, 0xB3,
    0x02, 0xC3,
    0x02, 0xE8,
    0x02, 0xA4,
    0x03, 0xB7, 0xE9,
    0x02, 0xC3,
    0x02, 0xC3,
    0x03, 0xE9, 0xA4,
    0x02, 0xC9,
    0x03, 0xEC, 0xC9,
    0x04, 0xEC, 0xC9, 0xE2,
    0x02, 0xBD,
    0x02, 0xC8,
    0x02, 0xA8,
    0x02, 0xB5,
    0x02, 0xB7,
    0x02, 0xB9,
    0x02, 0xBB,
    0x03, 0xBB, 0xE8,
    0x03, 0xBB, 0xEB,
    0x03, 0xBB, 0xEC,
    0x03, 0xBB, 0xED,
    0x02, 0xAE,
    0x03, 0xAE, 0xE8,
    0x03, 0xAE, 0xEB,
    0x03, 0xAE, 0xEC,
    0x03, 0xAE, 0xED,
    0x02, 0xA6,
    0x03, 0xA6, 0xC0,
    0x04, 0xA6, 0xC0, 0xC3,
    0x04, 0xA6, 0xC0, 0xED,
    0x03, 0xA6, 0xC7,
    0x04, 0xA6, 0xC7, 0xB7,
    0x05, 0xA6, 0xC7, 0xB7, 0xE7,
    0x04, 0xA6, 0xC7, 0xB9,
    0x03, 0xA6, 0xCA,
    0x04, 0xA6, 0xCA, 0xE9,
    0x03, 0xA6, 0xCB,
    0x03, 0xAB, 0xC3,
    0x03, 0xAB, 0xED,
    0x03, 0xB1, 0xEC,
    0x02, 0xE1,
    0x02, 0xC3,
    0x02, 0xC3,
    0x02, 0xDD,
    0x03, 0xDD, 0xA4,
    0x04, 0xDD, 0xAB, 0xC3,
    0x04, 0xDD, 0xAB, 0xED,
    0x03, 0xDD, 0xAF,
    0x04, 0xDD, 0xB1, 0xEC,
    0x02, 0xC4,
    0x02, 0xE2,
    0x03, 0xB7, 0xE7,
    0x03, 0xB3, 0xED,
    0x02, 0xA2,
    0x03, 0xAC, 0xE9,
    0x03, 0xB5, 0xA4,
    0x03, 0xB5, 0xC3,
    0x03, 0xB5, 0xE9,
    0x03, 0xB5, 0xEA,
    0x03, 0xB5, 0xEB,
    0x03, 0xB5, 0xEC,
    0x02, 0xC3,
    0x02, 0xC7,
    0x02, 0xCB,
    0x02, 0xDF,
    0x03, 0xAB, 0xEA,
    0x03, 0xAB, 0xE9,
    0x03, 0xB9, 0xEC,
    0x03, 0xB7, 0xA4,
    0x04, 0xB7, 0xAB, 0xC3,
    0x04, 0xB7, 0xAB, 0xED,
    0x03, 0xB7, 0xAF,
    0x04, 0xB7, 0xB1, 0xEC,
    0x03, 0xEC, 0xE8,
    0x03, 0xEC, 0xEB,
    0x03, 0xEC, 0xEC,
    0x03, 0xEC, 0xED,
};

const Ent_803E9DE0 quest_download_lz_match_entry_table[] = {
    { 0xA6, 0x05, 0x02, 0x00 },
    { 0xA6, 0x01, 0x04, 0x00 },
    { 0xA6, 0x04, 0x06, 0x00 },
    { 0xA6, 0x07, 0x08, 0x00 },
    { 0xA6, 0x08, 0x08, 0x01 },
    { 0xA6, 0x09, 0x0A, 0x00 },
    { 0xA6, 0x0A, 0x0A, 0x01 },
    { 0xA6, 0x02, 0x0C, 0x00 },
    { 0x80, 0x05, 0x01, 0x00 },
    { 0x81, 0x06, 0x01, 0x01 },
    { 0x88, 0x04, 0x01, 0x01 },
    { 0x8D, 0x07, 0x01, 0x01 },
    { 0x8D, 0x08, 0x01, 0x01 },
    { 0xA7, 0x01, 0x01, 0x01 },
    { 0xA7, 0x04, 0x01, 0x01 },
    { 0xAA, 0x01, 0x0E, 0x01 },
    { 0xAA, 0x04, 0x10, 0x02 },
    { 0xAA, 0x07, 0x12, 0x03 },
    { 0xAA, 0x08, 0x12, 0x01 },
    { 0xAA, 0x09, 0x14, 0x05 },
    { 0xAA, 0x0A, 0x14, 0x01 },
    { 0xAA, 0x02, 0x16, 0x07 },
    { 0xAA, 0x05, 0x18, 0x08 },
    { 0xA7, 0x0B, 0x1A, 0x09 },
    { 0xA7, 0x07, 0x08, 0x0A },
    { 0xA7, 0x08, 0x08, 0x01 },
    { 0xA7, 0x09, 0x0A, 0x0C },
    { 0xA7, 0x0A, 0x0C, 0x0D },
    { 0x88, 0x07, 0x01, 0x00 },
    { 0x88, 0x08, 0x01, 0x01 },
    { 0x8F, 0x07, 0x01, 0x01 },
    { 0x8F, 0x08, 0x01, 0x01 },
    { 0x88, 0x09, 0x01, 0x00 },
    { 0x88, 0x0A, 0x01, 0x01 },
    { 0x88, 0x02, 0x01, 0x00 },
    { 0xA9, 0x05, 0x1C, 0x01 },
    { 0xA9, 0x01, 0x0E, 0x02 },
    { 0xA9, 0x04, 0x10, 0x03 },
    { 0xA9, 0x07, 0x12, 0x04 },
    { 0xA9, 0x08, 0x12, 0x01 },
    { 0xA9, 0x09, 0x14, 0x06 },
    { 0xA9, 0x0A, 0x14, 0x01 },
    { 0xA9, 0x02, 0x16, 0x08 },
    { 0x80, 0x01, 0x01, 0x00 },
    { 0xE9, 0x00, 0x01, 0x01 },
    { 0xEA, 0x00, 0x1E, 0x01 },
    { 0x8D, 0x04, 0x21, 0x02 },
    { 0xC0, 0x00, 0x04, 0x03 },
    { 0x8D, 0x01, 0x0C, 0x04 },
    { 0x81, 0x01, 0x01, 0x00 },
    { 0xC1, 0x00, 0x01, 0x01 },
    { 0xAC, 0x05, 0x23, 0x01 },
    { 0xAC, 0x01, 0x04, 0x02 },
    { 0xAC, 0x04, 0x06, 0x03 },
    { 0xAC, 0x07, 0x08, 0x04 },
    { 0xAC, 0x08, 0x08, 0x01 },
    { 0xAC, 0x09, 0x0A, 0x06 },
    { 0xAC, 0x0A, 0x0A, 0x01 },
    { 0xAC, 0x02, 0x0C, 0x08 },
    { 0x80, 0x04, 0x01, 0x00 },
    { 0x8B, 0x04, 0x01, 0x01 },
    { 0xFA, 0x00, 0x01, 0x01 },
    { 0x81, 0x04, 0x01, 0x00 },
    { 0x80, 0x07, 0x01, 0x00 },
    { 0x80, 0x08, 0x01, 0x01 },
    { 0x8D, 0x05, 0x01, 0x01 },
    { 0x8B, 0x07, 0x08, 0x01 },
    { 0x8B, 0x08, 0x08, 0x01 },
    { 0x8B, 0x09, 0x0A, 0x03 },
    { 0x81, 0x07, 0x01, 0x00 },
    { 0x81, 0x08, 0x01, 0x01 },
    { 0xDA, 0x00, 0x25, 0x01 },
    { 0x80, 0x09, 0x01, 0x00 },
    { 0x80, 0x0A, 0x01, 0x01 },
    { 0xCC, 0x00, 0x28, 0x01 },
    { 0x8D, 0x09, 0x0A, 0x02 },
    { 0xCA, 0x00, 0x2A, 0x01 },
    { 0xCB, 0x00, 0x2D, 0x01 },
    { 0x81, 0x09, 0x01, 0x00 },
    { 0x81, 0x0A, 0x01, 0x01 },
    { 0xF7, 0x00, 0x01, 0x01 },
    { 0x80, 0x02, 0x01, 0x00 },
    { 0x8B, 0x01, 0x01, 0x01 },
    { 0x8B, 0x0A, 0x1C, 0x01 },
    { 0xDB, 0x00, 0x31, 0x02 },
    { 0xF5, 0x00, 0x33, 0x03 },
    { 0x81, 0x02, 0x01, 0x00 },
    { 0x82, 0x01, 0x01, 0x00 },
    { 0x89, 0x03, 0x01, 0x01 },
    { 0xEB, 0x00, 0x01, 0x01 },
    { 0xFB, 0x00, 0x01, 0x01 },
    { 0xDC, 0x00, 0x35, 0x01 },
    { 0xB2, 0x01, 0x37, 0x02 },
    { 0xB2, 0x04, 0x39, 0x03 },
    { 0xB2, 0x05, 0x39, 0x01 },
    { 0xB2, 0x07, 0x3B, 0x05 },
    { 0xB2, 0x08, 0x3B, 0x01 },
    { 0x90, 0x01, 0x3D, 0x07 },
    { 0x90, 0x04, 0x3D, 0x01 },
    { 0xB2, 0x09, 0x3D, 0x01 },
    { 0xB2, 0x0A, 0x3D, 0x01 },
    { 0x90, 0x0B, 0x3F, 0x01 },
    { 0x90, 0x07, 0x42, 0x02 },
    { 0x90, 0x08, 0x42, 0x01 },
    { 0x90, 0x09, 0x45, 0x04 },
    { 0x90, 0x0A, 0x48, 0x05 },
    { 0xB2, 0x02, 0x31, 0x10 },
    { 0x8A, 0x03, 0x01, 0x00 },
    { 0x82, 0x04, 0x01, 0x00 },
    { 0x82, 0x05, 0x01, 0x01 },
    { 0x89, 0x01, 0x01, 0x01 },
    { 0x89, 0x04, 0x01, 0x01 },
    { 0xCD, 0x00, 0x01, 0x01 },
    { 0xDD, 0x00, 0x0E, 0x01 },
    { 0x89, 0x0A, 0x0C, 0x02 },
    { 0x8A, 0x01, 0x01, 0x00 },
    { 0x8A, 0x04, 0x01, 0x01 },
    { 0x8A, 0x0A, 0x0C, 0x01 },
    { 0x82, 0x07, 0x01, 0x00 },
    { 0x82, 0x08, 0x01, 0x01 },
    { 0x89, 0x06, 0x01, 0x01 },
    { 0xAB, 0x01, 0x4B, 0x01 },
    { 0xAB, 0x04, 0x4B, 0x01 },
    { 0xAB, 0x0A, 0x4D, 0x01 },
    { 0xAB, 0x07, 0x50, 0x02 },
    { 0xAB, 0x08, 0x50, 0x01 },
    { 0xAB, 0x09, 0x53, 0x04 },
    { 0xAB, 0x0B, 0x56, 0x05 },
    { 0xE7, 0x00, 0x04, 0x08 },
    { 0x89, 0x07, 0x08, 0x09 },
    { 0x89, 0x08, 0x08, 0x01 },
    { 0x89, 0x09, 0x0A, 0x0B },
    { 0x8A, 0x06, 0x01, 0x00 },
    { 0x9C, 0x04, 0x01, 0x01 },
    { 0x8A, 0x07, 0x08, 0x01 },
    { 0x8A, 0x08, 0x08, 0x01 },
    { 0x8A, 0x09, 0x0A, 0x03 },
    { 0x82, 0x09, 0x01, 0x00 },
    { 0x82, 0x0A, 0x01, 0x01 },
    { 0x89, 0x02, 0x01, 0x01 },
    { 0x91, 0x01, 0x01, 0x01 },
    { 0x91, 0x04, 0x01, 0x01 },
    { 0x89, 0x0B, 0x1A, 0x01 },
    { 0x91, 0x0B, 0x1A, 0x01 },
    { 0x91, 0x07, 0x08, 0x03 },
    { 0x91, 0x08, 0x08, 0x01 },
    { 0x91, 0x09, 0x0A, 0x05 },
    { 0x91, 0x0A, 0x0C, 0x06 },
    { 0x8A, 0x02, 0x01, 0x00 },
    { 0xEC, 0x00, 0x01, 0x01 },
    { 0x8A, 0x0B, 0x1A, 0x01 },
    { 0x82, 0x02, 0x01, 0x00 },
    { 0x92, 0x0A, 0x59, 0x01 },
    { 0x92, 0x07, 0x5B, 0x01 },
    { 0x92, 0x04, 0x5E, 0x01 },
    { 0x92, 0x01, 0x62, 0x02 },
    { 0x92, 0x05, 0x66, 0x04 },
    { 0x93, 0x04, 0x69, 0x01 },
    { 0x93, 0x01, 0x6D, 0x01 },
    { 0x93, 0x07, 0x72, 0x03 },
    { 0x93, 0x08, 0x72, 0x01 },
    { 0x92, 0x08, 0x76, 0x09 },
    { 0x92, 0x09, 0x79, 0x01 },
    { 0x92, 0x06, 0x7D, 0x0B },
    { 0xED, 0x00, 0x01, 0x00 },
    { 0x83, 0x01, 0x01, 0x00 },
    { 0x94, 0x07, 0x01, 0x01 },
    { 0x94, 0x08, 0x01, 0x01 },
    { 0x96, 0x03, 0x01, 0x01 },
    { 0x96, 0x07, 0x1C, 0x01 },
    { 0x96, 0x08, 0x1C, 0x01 },
    { 0x96, 0x04, 0x80, 0x03 },
    { 0x96, 0x01, 0x83, 0x04 },
    { 0x96, 0x05, 0x12, 0x05 },
    { 0x96, 0x09, 0x86, 0x06 },
    { 0xF6, 0x00, 0x89, 0x07 },
    { 0x94, 0x09, 0x04, 0x08 },
    { 0xCE, 0x00, 0x06, 0x09 },
    { 0xAF, 0x08, 0x08, 0x0A },
    { 0xAF, 0x09, 0x0A, 0x0B },
    { 0xAF, 0x0A, 0x0A, 0x01 },
    { 0x94, 0x01, 0x0C, 0x0D },
    { 0x8E, 0x07, 0x01, 0x00 },
    { 0x95, 0x07, 0x01, 0x01 },
    { 0x95, 0x08, 0x01, 0x01 },
    { 0x97, 0x07, 0x01, 0x01 },
    { 0xDE, 0x00, 0x14, 0x01 },
    { 0x8E, 0x04, 0x8B, 0x02 },
    { 0x97, 0x04, 0x8D, 0x01 },
    { 0x95, 0x09, 0x04, 0x04 },
    { 0xCF, 0x00, 0x06, 0x05 },
    { 0x8E, 0x01, 0x0C, 0x06 },
    { 0x95, 0x01, 0x0C, 0x01 },
    { 0x98, 0x01, 0x0C, 0x01 },
    { 0x83, 0x04, 0x01, 0x00 },
    { 0x83, 0x05, 0x01, 0x00 },
    { 0x87, 0x05, 0x01, 0x01 },
    { 0x88, 0x05, 0x01, 0x01 },
    { 0xB1, 0x03, 0x8F, 0x01 },
    { 0xB1, 0x07, 0x91, 0x01 },
    { 0xB1, 0x08, 0x91, 0x01 },
    { 0xB1, 0x04, 0x94, 0x03 },
    { 0xB1, 0x01, 0x98, 0x04 },
    { 0xB1, 0x05, 0x9C, 0x05 },
    { 0xB1, 0x09, 0x9F, 0x06 },
    { 0x83, 0x07, 0x01, 0x00 },
    { 0x83, 0x08, 0x01, 0x01 },
    { 0xD5, 0x00, 0xA3, 0x01 },
    { 0x83, 0x09, 0x01, 0x00 },
    { 0x83, 0x0A, 0x01, 0x01 },
    { 0xD0, 0x00, 0x01, 0x01 },
    { 0xD2, 0x00, 0xA5, 0x01 },
    { 0x8E, 0x05, 0x01, 0x00 },
    { 0x97, 0x05, 0x01, 0x01 },
    { 0xC3, 0x00, 0x01, 0x01 },
    { 0xD1, 0x00, 0x01, 0x01 },
    { 0x99, 0x04, 0x39, 0x01 },
    { 0x9A, 0x01, 0xA7, 0x01 },
    { 0x99, 0x07, 0x3B, 0x03 },
    { 0x99, 0x08, 0x3B, 0x01 },
    { 0xD3, 0x00, 0xA5, 0x05 },
    { 0x83, 0x02, 0x01, 0x00 },
    { 0xAF, 0x04, 0x01, 0x01 },
    { 0xC2, 0x00, 0x01, 0x01 },
    { 0xFC, 0x00, 0x01, 0x01 },
    { 0xD9, 0x00, 0xAA, 0x01 },
    { 0xEE, 0x00, 0xA5, 0x02 },
    { 0x84, 0x01, 0x01, 0x00 },
    { 0x8E, 0x08, 0x01, 0x01 },
    { 0x97, 0x08, 0x01, 0x01 },
    { 0x9B, 0x03, 0x01, 0x01 },
    { 0xEF, 0x00, 0x01, 0x01 },
    { 0xF0, 0x00, 0xAD, 0x01 },
    { 0x9B, 0x07, 0x1C, 0x02 },
    { 0x9B, 0x08, 0x1C, 0x01 },
    { 0x9B, 0x04, 0x80, 0x04 },
    { 0x9B, 0x01, 0x83, 0x05 },
    { 0xD4, 0x00, 0xAF, 0x06 },
    { 0x9B, 0x05, 0x12, 0x07 },
    { 0x9B, 0x09, 0x86, 0x08 },
    { 0x9B, 0x06, 0x37, 0x09 },
    { 0xAD, 0x0B, 0xB2, 0x01 },
    { 0xAD, 0x05, 0xB5, 0x02 },
    { 0xAD, 0x01, 0xB8, 0x03 },
    { 0xAD, 0x04, 0xBB, 0x04 },
    { 0xAD, 0x07, 0xBE, 0x05 },
    { 0xAD, 0x08, 0xBE, 0x01 },
    { 0xAD, 0x09, 0xC1, 0x07 },
    { 0xAD, 0x0A, 0xC1, 0x01 },
    { 0xB0, 0x05, 0xC4, 0x12 },
    { 0xDF, 0x00, 0x28, 0x13 },
    { 0x8E, 0x09, 0x04, 0x14 },
    { 0x98, 0x09, 0x04, 0x01 },
    { 0xB0, 0x01, 0x04, 0x01 },
    { 0xB0, 0x04, 0x06, 0x17 },
    { 0xE0, 0x00, 0x06, 0x01 },
    { 0xB0, 0x07, 0x08, 0x19 },
    { 0xB0, 0x08, 0x08, 0x01 },
    { 0xB0, 0x09, 0x0A, 0x1B },
    { 0xB0, 0x0A, 0x0A, 0x01 },
    { 0xB0, 0x02, 0x0C, 0x1D },
    { 0x84, 0x04, 0x01, 0x00 },
    { 0x8E, 0x06, 0x01, 0x01 },
    { 0xC4, 0x00, 0x01, 0x01 },
    { 0xFD, 0x00, 0x01, 0x01 },
    { 0x84, 0x07, 0x01, 0x00 },
    { 0x84, 0x08, 0x01, 0x01 },
    { 0x9C, 0x07, 0x01, 0x01 },
    { 0x9C, 0x08, 0x01, 0x01 },
    { 0x84, 0x09, 0x01, 0x00 },
    { 0x84, 0x0A, 0x01, 0x01 },
    { 0x9C, 0x09, 0x01, 0x01 },
    { 0xF1, 0x00, 0x01, 0x01 },
    { 0xF2, 0x00, 0x35, 0x01 },
    { 0x84, 0x02, 0x01, 0x00 },
    { 0xC8, 0x00, 0x01, 0x01 },
    { 0xFE, 0x00, 0x01, 0x01 },
    { 0xD6, 0x00, 0xC6, 0x01 },
    { 0xD7, 0x00, 0xC8, 0x02 },
    { 0xE8, 0x00, 0xCA, 0x03 },
    { 0xE1, 0x00, 0x01, 0x00 },
    { 0x85, 0x01, 0x01, 0x00 },
    { 0xD8, 0x00, 0x01, 0x01 },
    { 0xE2, 0x00, 0xCC, 0x01 },
    { 0x85, 0x04, 0x01, 0x00 },
    { 0x85, 0x07, 0x01, 0x00 },
    { 0x85, 0x08, 0x01, 0x01 },
    { 0xC5, 0x00, 0x01, 0x00 },
    { 0x85, 0x09, 0x01, 0x00 },
    { 0x85, 0x0A, 0x01, 0x01 },
    { 0xAE, 0x01, 0xCF, 0x01 },
    { 0xAE, 0x08, 0x10, 0x02 },
    { 0xAE, 0x04, 0x12, 0x03 },
    { 0xAE, 0x09, 0x86, 0x04 },
    { 0xAE, 0x07, 0x39, 0x05 },
    { 0xE3, 0x00, 0x28, 0x00 },
    { 0x85, 0x02, 0x01, 0x00 },
    { 0x86, 0x01, 0x01, 0x00 },
    { 0x9D, 0x07, 0x1C, 0x01 },
    { 0x9D, 0x08, 0x1C, 0x01 },
    { 0x9E, 0x04, 0x39, 0x03 },
    { 0x9E, 0x0B, 0x39, 0x01 },
    { 0x9E, 0x02, 0xA7, 0x01 },
    { 0x9E, 0x07, 0x3B, 0x06 },
    { 0x9E, 0x08, 0x3B, 0x01 },
    { 0x9E, 0x09, 0xD2, 0x01 },
    { 0x9E, 0x01, 0x3D, 0x09 },
    { 0x9E, 0x0A, 0x3D, 0x01 },
    { 0xE4, 0x00, 0xC6, 0x0B },
    { 0x86, 0x04, 0x01, 0x00 },
    { 0xA8, 0x01, 0x01, 0x01 },
    { 0xA8, 0x04, 0x01, 0x01 },
    { 0xF8, 0x00, 0x01, 0x01 },
    { 0xA8, 0x0B, 0x1A, 0x01 },
    { 0xA8, 0x07, 0x08, 0x02 },
    { 0xA8, 0x08, 0x08, 0x01 },
    { 0xA8, 0x09, 0x0A, 0x04 },
    { 0xA8, 0x0A, 0x0C, 0x05 },
    { 0x86, 0x07, 0x01, 0x00 },
    { 0x86, 0x08, 0x01, 0x01 },
    { 0x86, 0x09, 0x01, 0x00 },
    { 0x86, 0x0A, 0x01, 0x01 },
    { 0xF9, 0x00, 0x01, 0x01 },
    { 0x86, 0x02, 0x01, 0x00 },
    { 0xE5, 0x00, 0x01, 0x01 },
    { 0xC9, 0x00, 0x01, 0x00 },
    { 0xE6, 0x00, 0x04, 0x01 },
    { 0x8C, 0x0B, 0x01, 0x00 },
    { 0xF3, 0x00, 0x01, 0x01 },
    { 0x9F, 0x07, 0x59, 0x01 },
    { 0x9F, 0x08, 0x59, 0x01 },
    { 0xA0, 0x07, 0x5B, 0x01 },
    { 0xA0, 0x04, 0x5E, 0x01 },
    { 0xA0, 0x01, 0x62, 0x02 },
    { 0xA0, 0x05, 0x66, 0x04 },
    { 0xA1, 0x04, 0x69, 0x01 },
    { 0xA1, 0x01, 0x6D, 0x01 },
    { 0xA1, 0x07, 0x72, 0x03 },
    { 0xA1, 0x08, 0x72, 0x01 },
    { 0xA0, 0x08, 0x76, 0x09 },
    { 0xA0, 0x09, 0x79, 0x01 },
    { 0xA0, 0x06, 0x7D, 0x0B },
    { 0xC6, 0x00, 0x06, 0x0E },
    { 0x87, 0x01, 0x01, 0x00 },
    { 0xA2, 0x03, 0x39, 0x01 },
    { 0xA2, 0x07, 0xD5, 0x01 },
    { 0xA2, 0x08, 0xD5, 0x01 },
    { 0xA2, 0x04, 0xD8, 0x03 },
    { 0xA2, 0x01, 0xDC, 0x04 },
    { 0xA2, 0x05, 0xE0, 0x05 },
    { 0xA2, 0x09, 0xE3, 0x06 },
    { 0xA3, 0x01, 0x0A, 0x08 },
    { 0xA3, 0x04, 0x0A, 0x01 },
    { 0xA3, 0x0B, 0xE7, 0x01 },
    { 0xA3, 0x07, 0xEA, 0x02 },
    { 0xA3, 0x08, 0xEA, 0x01 },
    { 0xA3, 0x09, 0xED, 0x04 },
    { 0xA3, 0x0A, 0xF0, 0x05 },
    { 0x87, 0x04, 0x01, 0x00 },
    { 0x87, 0x07, 0x01, 0x00 },
    { 0x87, 0x08, 0x01, 0x01 },
    { 0x8C, 0x07, 0x01, 0x01 },
    { 0x8C, 0x08, 0x01, 0x01 },
    { 0x87, 0x09, 0x01, 0x00 },
    { 0x87, 0x0A, 0x01, 0x01 },
    { 0x8C, 0x09, 0x01, 0x01 },
    { 0xA4, 0x01, 0x01, 0x01 },
    { 0xA4, 0x04, 0x01, 0x01 },
    { 0xA4, 0x0B, 0x1A, 0x01 },
    { 0xA4, 0x07, 0x08, 0x02 },
    { 0xA4, 0x08, 0x08, 0x01 },
    { 0xA4, 0x09, 0x0A, 0x04 },
    { 0xA4, 0x0A, 0x0C, 0x05 },
    { 0x87, 0x02, 0x01, 0x00 },
    { 0x8C, 0x0A, 0x01, 0x01 },
    { 0x88, 0x01, 0x01, 0x00 },
    { 0xF4, 0x00, 0x01, 0x01 },
    { 0xC7, 0x00, 0x01, 0x00 },
    { 0x84, 0x06, 0x01, 0x00 },
    { 0x85, 0x06, 0x01, 0x01 },
    { 0x86, 0x06, 0x01, 0x01 },
    { 0xA5, 0x07, 0x01, 0x01 },
    { 0xA5, 0x08, 0x01, 0x01 },
};

// First match entry per lead byte (lead - 0xA0); a lead byte's entries end where the next one's begin.
const s16 quest_download_lz_match_index_table[] = {
    1, 1, 1, 8, 8, 28, 28, 32, 32, 34, 34, 43, 49, 59, 62, 63,
    69, 72, 78, 81, 86, 87, 107, 108, 115, 118, 132, 137, 148, 151, 164, 165,
    182, 194, 195, 195, 205, 208, 208, 212, 221, 227, 227, 261, 265, 269, 274, 280,
    281, 284, 284, 284, 285, 285, 285, 287, 287, 288, 295, 295, 296, 297, 297, 309,
    318, 320, 323, 325, 325, 327, 327, 327, 327, 343, 358, 359, 363, 373, 375, 375,
    377, 377, 377, 378, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383,
};

// inferred: the token list sub_803EA1A8 runs after each slot's own tokens; {-1, 0xFF, 0xFF} ends it.
const Tok_803E9FFC quest_download_lz_default_tokens[4] = {
    { 0, 0x19, 0 },
    { -1, 0xFF, 0xFF },
};

extern "C" {
s32 TQuestVmDownLoadServer::is_download_cmd_allowed(u8 arg0) {
    if ((lbl_805D7888 - 1) <= 1U) {
        return 0;
    }
    switch (arg0) {
    case 0x9D:
    case 0xA1:
    case 0xA3:
    case 0xA5:
    case 0xA7:
    case 0xA9:
    case 0xC3:
    case 0xE3:
    case 0xE5:
    case 0xE7:
    case 0xEE:
    case 0xF2:
    case 0xF3:
        return 1;
    default:
        return 0;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
#pragma opt_common_subs off
inline s32 IsX_803E9FFC(u8 arg0) {
    if ((lbl_805D7888 - 1) <= 1U) {
        return 0;
    }
    switch (arg0) {
    case 0x9D:
    case 0xA1:
    case 0xA3:
    case 0xA5:
    case 0xA7:
    case 0xA9:
    case 0xC3:
    case 0xE3:
    case 0xE5:
    case 0xE7:
    case 0xEE:
    case 0xF2:
    case 0xF3:
        return 1;
    default:
        return 0;
    }
}
// Inferred: true for the characters that end a name (space, punctuation, SJIS-range markers).
inline s32 IsBreakChar_803E9A74(u8 c) {
    if (c >= 0xA0) {
        return 0;
    }
    switch (c) {
    case 0x20:
    case 0x21:
    case 0x2C:
    case 0x2E:
    case 0x3A:
    case 0x3B:
    case 0x3F:
    case 0x98:
    case 0x9B:
    case 0x9C:
        return 1;
    default:
        return 0;
    }
}
Seg_803E9FFC *TQuestVmDownLoadServer__sub_803E9A74(s32 pos, s32 end, u8 a, u8 b) {
    s32 n;
    Obj_803EADD4 *slot;
    Ent_803E9DE0 *sub;
    Ent_803E9DE0 *e;
    Seg_803E9FFC *head;
    head = NULL;
    if (pos >= end) {
        if (lbl_805D7888 < 3) {
            return NULL;
        }
        return (Seg_803E9FFC *)-1;
    }
    slot = &((Obj_803EADD4 *)quest_download_slot_chain_table)[pos];
    e = (Ent_803E9DE0 *)slot->x0;
    if ((u32)e == 0xFFFFFFFF) {
        return (Seg_803E9FFC *)-1;
    }
    if (e == NULL && IsBreakChar_803E9A74(((u8 *)&quest_download_scratch_storage)[pos])) {
        if (a == 0 || TQuestVmDownLoadServer::is_valid_item_for_slot(a, b)) {
            Seg_803E9FFC *s = (Seg_803E9FFC *)TQuestVmDownLoadServer__sub_803ECF0C();
            if (s != NULL) {
                s->off = 1;
                s->a = 0xFF;
                s->x2 = 0xFF;
                s->b = 0;
                s->x3 = 0;
                s->next = NULL;
            }
            return s;
        }
    }
    // Entries that end at this position.
    for (; e != NULL; e -= (s8)e->d) {
        if (TQuestVmDownLoadServer::is_valid_item_for_slot(e->a, e->b)) {
            if (a == 0 || TQuestVmDownLoadServer__sub_803E7390(a, b, e->a)) {
                u8 *text = (u8 *)&quest_download_scratch_storage + pos;
                n = quest_download_lz_match_strings[e->off];
                if (pos + n >= end || !IsX_803E9FFC(text[n])) {
                    Seg_803E9FFC *s = (Seg_803E9FFC *)TQuestVmDownLoadServer__sub_803ECF0C();
                    if (s != NULL) {
                        s->off = n;
                        s->x2 = s->a = e->a;
                        s->x3 = s->b = e->b;
                        s->next = head;
                        head = s;
                    }
                }
            }
        }
        if ((s8)e->d == 0) {
            break;
        }
    }
    // Entries continued by the segments that follow them.
    for (sub = (Ent_803E9DE0 *)slot->x0; sub != NULL; sub -= (s8)sub->d) {
        if (a == 0 || TQuestVmDownLoadServer__sub_803E7390(a, b, sub->a)) {
            Seg_803E9FFC *r;
            n = quest_download_lz_match_strings[sub->off];
            r = TQuestVmDownLoadServer__sub_803E9A74(pos + n, end, sub->a, sub->b);
            if ((u32)r == 0xFFFFFFFF) {
                TQuestVmDownLoadServer__sub_803ECE5C((Node_803ECE5C *)head);
                return (Seg_803E9FFC *)-1;
            }
            if (r != NULL) {
                Seg_803E9FFC *s;
                for (s = r;; s = s->next) {
                    s->off += n;
                    s->x2 = sub->a;
                    s->x3 = sub->b;
                    if (s->next == NULL) {
                        break;
                    }
                }
                s->next = head;
                head = r;
            }
        }
        if ((s8)sub->d == 0) {
            break;
        }
    }
    return head;
}
#pragma pop

const Ent_803E9DE0 *TQuestVmDownLoadServer::find_longest_match_entry(s32 arg1, s32 *arg2) {
    u8 *arg0 = (u8 *)this;
    const u8 *s;
    u8 *a;
    s32 k;
    s32 rem;
    const Ent_803E9DE0 *p;
    s32 m;
    s32 best = 1;
    u8 c = arg0[0];
    if (c < 0xA0) {
        *arg2 = 1;
        return NULL;
    }
    c -= 0xA0;
    for (p = &quest_download_lz_match_entry_table[quest_download_lz_match_index_table[c + 1]] - 1; p >= &quest_download_lz_match_entry_table[quest_download_lz_match_index_table[c]]; p--) {
        a = arg0 + 1;
        rem = arg1 - 1;
        s = &quest_download_lz_match_strings[p->off];
        m = 1;
        k = *s++ - 1;
        while (1) {
            if (k == 0) {
                if (m > best) {
                    best = m;
                }
                *arg2 = best;
                return p;
            }
            if (rem == 0) {
                if (lbl_805D7888 >= 3) {
                    return (const Ent_803E9DE0 *)-1;
                }
                break;
            }
            m++;
            if (*s != *a) {
                if (m > best) {
                    best = m;
                }
                break;
            }
            a++;
            s++;
            rem--;
            k--;
        }
    }
    *arg2 = best;
    return NULL;
}

void TQuestVmDownLoadServer::latch_slot_value(s32 arg0) {
    struct Fields_temp_r3 { u8 pad_0[20]; u8 field_14; u8 field_15; u8 field_16; };
    u8 *temp_r3;
    temp_r3 = (u8 *)quest_download_slot_chain_table + (arg0 * 0x1C);
    if (((s8) ((Fields_temp_r3*)temp_r3)->field_16 == 0) && ((s8) ((Fields_temp_r3*)temp_r3)->field_14 != 0)) {
        ((Fields_temp_r3*)temp_r3)->field_16 = (u8) ((Fields_temp_r3*)temp_r3)->field_15;
    }
}

s32 TQuestVmDownLoadServer__sub_803E9F54(s32 arg0) {
    R_803E9F54 *r;
    if (arg0 >= quest_text_end) {
        return 0;
    }
    r = &((R_803E9F54 *)quest_download_slot_chain_table)[arg0];
    if (lbl_805D7848 == 2 && r->a == 0) {
        return 0;
    }
    return (s8)r->b;
}

N_803E9FA4 *TQuestVmDownLoadServer::insert_sorted_node(N_803E9FA4 *arg1) {
    N_803E9FA4 *cur;
    N_803E9FA4 *prev;
    s16 k = arg1->key;
    if (((N_803E9FA4 *)this) == NULL || ((N_803E9FA4 *)this)->key < k) {
        arg1->next = ((N_803E9FA4 *)this);
        return arg1;
    }
    cur = ((N_803E9FA4 *)this)->next;
    prev = ((N_803E9FA4 *)this);
    while (cur != NULL) {
        if (cur->key < k) {
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    prev->next = arg1;
    arg1->next = cur;
    return ((N_803E9FA4 *)this);
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void *TQuestVmDownLoadServer__sub_803E9FFC(s32 arg0, s32 arg1, const Tok_803E9FFC *t) {
    s32 off;
    Out_803E9FFC *head;
    Out_803E9FFC *tail;
    s32 pos;
    Seg_803E9FFC *s;
    Seg_803E9FFC *first;
    Out_803E9FFC *o;
    off = t->off;
    head = NULL;
    tail = NULL;
    pos = arg0 + off;
    s = TQuestVmDownLoadServer__sub_803E9A74(pos, arg1, t->a, t->b);
    if ((u32)s == 0xFFFFFFFFU) {
        return (void *)-1;
    }
    for (first = s; s != NULL; s = s->next) {
        o = (Out_803E9FFC *)TQuestVmDownLoadServer__sub_803ECF48();
        if (o == NULL) {
            break;
        }
        if (head == NULL) {
            head = o;
        }
        o->off = off + s->off;
        o->a = s->a;
        o->b = s->b;
        o->src = t;
        o->x8 = 0;
        o->xa = 0;
        o->next = NULL;
        if (tail != NULL) {
            tail->next = o;
        }
        tail = o;
    }
    TQuestVmDownLoadServer__sub_803ECE5C((Node_803ECE5C *)first);
    if (off > 0 && TQuestVmDownLoadServer::is_valid_item_for_slot(t->a, t->b) != 0) {
        if (pos >= arg1 || IsX_803E9FFC(((u8 *)&quest_download_scratch_storage)[pos]) == 0) {
            o = (Out_803E9FFC *)TQuestVmDownLoadServer__sub_803ECF48();
            if (o != NULL) {
                if (head == NULL) {
                    head = o;
                }
                o->off = off;
                o->a = t->a;
                o->b = t->b;
                o->src = t;
                o->x8 = 0;
                o->xa = 0;
                o->next = NULL;
                if (tail != NULL) {
                    tail->next = o;
                }
            }
        }
    }
    return head;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline N_803E9FA4 *merge_sorted_nodes(N_803E9FA4 *head, N_803E9FA4 *list) {
    N_803E9FA4 *n;
    N_803E9FA4 *next;
    for (n = list; n != NULL; n = next) {
        next = n->next;
        head = ((TQuestVmDownLoadServer *)head)->insert_sorted_node(n);
    }
    return head;
}
// inferred: stores the length of the run of download-allowed commands after start
inline void set_allowed_cmd_run(Out_803E9FFC *o, s32 start, s32 end) {
    s32 i;
    for (i = start + 1; i < end; i++) {
        if (!TQuestVmDownLoadServer::is_download_cmd_allowed(((u8 *)&quest_download_scratch_storage)[i])) {
            break;
        }
    }
    o->off = i - start;
}
s32 TQuestVmDownLoadServer__sub_803EA1A8(s32 start, s32 end) {
    Obj_803EADD4 *e;
    Node_803ECDC4 *tok;
    N_803E9FA4 *list;
    Out_803E9FFC *o;
    e = (Obj_803EADD4 *)&quest_download_slot_chain_table[start];
    if ((u32)e->x4 != 0xFFFFFFFF) {
        for (tok = e->x4; tok != NULL; tok = tok->next) {
            list = (N_803E9FA4 *)TQuestVmDownLoadServer__sub_803E9FFC(start, end, (Tok_803E9FFC *)tok);
            if ((u32)list == 0xFFFFFFFF) {
                if (e->x8 != NULL) {
                    TQuestVmDownLoadServer__sub_803ECD8C(e->x8);
                    e->x8 = NULL;
                }
                return 0;
            }
            if (list != NULL) {
                e->x8 = (Node_803ECD8C *)merge_sorted_nodes((N_803E9FA4 *)e->x8, list);
            }
        }
    }
    list = (N_803E9FA4 *)TQuestVmDownLoadServer__sub_803E9FFC(start, end, quest_download_lz_default_tokens);
    if ((u32)list == 0xFFFFFFFF) {
        if (e->x8 != NULL) {
            TQuestVmDownLoadServer__sub_803ECD8C(e->x8);
            e->x8 = NULL;
        }
        return 0;
    }
    if (list != NULL) {
        quest_download_slot_chain_table[start].head = (Elem_803ED9AC *)merge_sorted_nodes((N_803E9FA4 *)quest_download_slot_chain_table[start].head, list);
    }
    if (e->x8 == NULL) {
        o = (Out_803E9FFC *)TQuestVmDownLoadServer__sub_803ECF48();
        if (o == NULL) {
            return -1;
        }
        set_allowed_cmd_run(o, start, end);
        o->a = 0x28;
        o->b = 0;
        o->src = NULL;
        o->x8 = 0;
        o->xa = 0;
        o->next = NULL;
        e->x8 = (Node_803ECD8C *)o;
        return 1;
    }
    return 1;
}
#pragma pop

Node_803EA384 *TQuestVmDownLoadServer::build_item_list(s32 arg0, Hdr_803EA384 *arg1) {
    s16 id;
    s32 x4;
    s32 n;
    Item_803EA384 *it;
    Node_803EA384 *head;
    Node_803EA384 *prev;
    Node_803EA384 *node;
    u8 unused[8];
    it = arg1->items;
    head = NULL;
    prev = NULL;
    id = arg1->id;
    x4 = arg1->x4;
    n = arg1->count;
    while (n-- != 0) {
        node = TQuestVmDownLoadServer__sub_803ECF84();
        if (node == NULL) {
            break;
        }
        if (head == NULL) {
            head = node;
        }
        node->id = id;
        node->a = it->a;
        node->b = it->b;
        node->x4 = x4;
        node->c = it->c;
        node->next = NULL;
        if (prev != NULL) {
            prev->next = node;
        }
        prev = node;
        it++;
    }
    return head;
}

struct Slot_803EA428 {
    const Ent_803E9DE0 *x0;
    Node_803EA384 *list;
    Out_803E9FFC *x8;
    Node_803ECD54 *xc;
    u8 pad10[4];
    s8 x14;
    s8 x15;
    u8 pad16;
    s8 width;
    s8 x18;
    u8 pad19[3];
};

// lbl_80595008 and quest_download_slot_chain_table are addressed from one base register in this function
// (slot = lbl_80595008 + 0x990 + start * 0x1C), so they are one object here.
struct Work_80595008 {
    u8 pad_0[0x8C0];
    Out_803F0268 match;
    u8 pad_match_end[0xD0 - sizeof(Out_803F0268)];
    Slot_803EA428 slots[80];
};

extern Work_80595008 lbl_80595008;

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
#pragma opt_propagation off
inline void append_candidate_items(Node_803EA384 *item, Node_803EA384 **tail) {
    while (*tail != NULL) {
        tail = &(*tail)->next;
    }
    *tail = item;
}
inline void set_candidate_span(Slot_803EA428 *slot, s32 maximum) {
    slot->width = maximum;
}
struct QuestDownloadWorkspaceAddress {
    size_t address;
    QuestDownloadWorkspaceAddress(size_t base) : address(base) {}
};
#pragma pop

#define QUEST_WORKSPACE_MATCH(address) reinterpret_cast<Out_803F0268 *>((address) + offsetof(Work_80595008, match))

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
#pragma opt_lifetimes off
#pragma opt_propagation off
s32 TQuestVmDownLoadServer__sub_803EA428(s32 start, s32 end) {
    size_t position;
    Slot_803EA428 *slot;
    s32 stop;
    u32 candidateLength;
    u8 *text;
    Ent_803E6970 *last;
    u8 runKind;
    u32 length;
    u8 kind;

    QuestDownloadWorkspaceAddress workspace(reinterpret_cast<size_t>(&lbl_80595008));
    length = end - start;
    if (length == 0) {
        return 0;
    }
    text = (u8 *)&quest_download_scratch_storage + start;
    // position holds the slot displacement on the run paths and an input address in the text scans.
    position = start * sizeof(Slot_803EA428);
    slot = reinterpret_cast<Slot_803EA428 *>(workspace.address + offsetof(Work_80595008, slots) + position);
    kind = 0;
    if (TQuestVmDownLoadServer__sub_803EDB58(*text)) {
        position = reinterpret_cast<size_t>(text + 1);
        kind = 0x1F;
        for (end = 1; end < length; end++, position++) {
            if (!TQuestVmDownLoadServer__sub_803EDB58(*reinterpret_cast<u8 *>(position))) {
                break;
            }
        }
        if (lbl_805D7888 >= 3 && end >= length) {
            return 0;
        }
    } else if (TQuestVmDownLoadServer__sub_803EDB3C(*text)) {
        position = reinterpret_cast<size_t>(text + 1);
        kind = 0x19;
        for (end = 1; end < length; end++, position++) {
            if (!TQuestVmDownLoadServer__sub_803EDB74(*reinterpret_cast<u8 *>(position))) {
                break;
            }
        }
        if (lbl_805D7888 >= 3 && end >= length) {
            return 0;
        }
    } else if (TQuestVmDownLoadServer__sub_803EDB20(*text)) {
        if (lbl_805D7888 >= 3 && length <= 1) {
            return 0;
        }
        candidateLength = 1;
        end = 1;
        kind = 0x19;
        goto candidates;
    } else if ((s8)*text != 0 && *text < 0xA0) {
        if (lbl_805D7888 >= 3 && length <= 1) {
            return 0;
        }
        candidateLength = 1;
        end = 1;
        kind = 0x29;
        goto candidates;
    } else if ((s8)*text == 0 && (((Ent_803E6970 *)&quest_download_entry_table)[start].ch & 0xFF00) == 0) {
        for (stop = start + 1; stop < end; stop++) {
            if ((((Ent_803E6970 *)&quest_download_entry_table)[stop].ch & 0xFF00) != 0) {
                break;
            }
        }
        runKind = 0x19;
        goto emit_run;
    } else if ((s8)*text == 0 && TQuestVmDownLoadServer::is_download_command(((Ent_803E6970 *)&quest_download_entry_table)[start].ch, 0)) {
        for (stop = start + 1; stop < end; stop++) {
            if (!TQuestVmDownLoadServer::is_download_command(((Ent_803E6970 *)&quest_download_entry_table)[stop].ch, 1)) {
                break;
            }
        }
        runKind = 0x19;
    emit_run:
        if (lbl_805D7888 >= 3 && stop == end) {
            return 0;
        }
        Node_803EA384 *item = TQuestVmDownLoadServer__sub_803ECF84();
        if (item != NULL) {
            item->id = stop - start;
            item->a = runKind;
            item->b = 0;
            item->x4 = -1;
            item->c = 0;
            item->next = NULL;
            reinterpret_cast<s8 *>(workspace.address + offsetof(Work_80595008, slots) + offsetof(Slot_803EA428, width))[position] = stop - start + 1;
            append_candidate_items(item, &slot->list);
        }
        return 1;
    } else if ((s8)*text == 0) {
        for (stop = start + 1, text++; stop < end; stop++, text++) {
            if ((s8)*text != 0) {
                break;
            }
        }
        Ent_803E6970 *table = (Ent_803E6970 *)&quest_download_entry_table;
        last = table + stop;
        if (TQuestVmDownLoadServer__sub_803EC884((--last)->ch)) {
            runKind = 0x28;
        } else if (TQuestVmDownLoadServer::is_valid_sjis_code(last->ch)) {
            runKind = 0x29;
        } else {
            runKind = 0x19;
        }
        goto emit_run;
    } else {
        end = 1;
    }

    {
        u8 *p = text;
        u32 remaining = length;
        candidateLength = 0;
        for (; candidateLength < remaining; candidateLength++) {
            if ((s8)*p++ == 0) {
                break;
            }
        }
        switch (TQuestVmDownLoadServer__sub_803F06B8((char *)text, candidateLength, QUEST_WORKSPACE_MATCH(workspace.address))) {
        case 2:
            if (lbl_805D7888 >= 3) {
                return 0;
            }
            break;
        case 1:
            if (kind != 0 && QUEST_WORKSPACE_MATCH(workspace.address)->len <= end) {
                TQuestVmDownLoadServer__sub_803EED9C(QUEST_WORKSPACE_MATCH(workspace.address)->x4);
                candidateLength = end;
                slot->width = QUEST_WORKSPACE_MATCH(workspace.address)->len2;
            } else {
                Node_803EA384 *item = TQuestVmDownLoadServer::build_item_list(start, (Hdr_803EA384 *)QUEST_WORKSPACE_MATCH(workspace.address));
                append_candidate_items(item, &slot->list);
                slot->width = QUEST_WORKSPACE_MATCH(workspace.address)->len2;
                candidateLength = QUEST_WORKSPACE_MATCH(workspace.address)->len - 1;
            }
            break;
        case 0:
        default:
            if (kind != 0) {
                candidateLength = end;
            } else {
                slot->list = (Node_803EA384 *)-1;
                return -1;
            }
        }
    }
candidates:
    Node_803EA384 **items = &slot->list;
    for (; candidateLength >= end; candidateLength--) {
        if (kind != 0 && candidateLength == end) {
            Node_803EA384 *item = TQuestVmDownLoadServer__sub_803ECF84();
            if (item != NULL) {
                s8 maximum = end + 1;
                item->id = end;
                item->a = kind;
                item->b = 0;
                item->x4 = -1;
                item->c = 0;
                item->next = NULL;
                set_candidate_span(slot, maximum);
                append_candidate_items(item, items);
            }
        }
        if (TQuestVmDownLoadServer__sub_803F0268((char *)text, candidateLength, QUEST_WORKSPACE_MATCH(workspace.address)) == 1) {
            if (slot->width == -1) {
                slot->width = QUEST_WORKSPACE_MATCH(workspace.address)->len2;
            }
            Node_803EA384 *item = TQuestVmDownLoadServer::build_item_list(start, (Hdr_803EA384 *)QUEST_WORKSPACE_MATCH(workspace.address));
            append_candidate_items(item, items);
        }
    }
    return 1;
}
#pragma pop

s32 TQuestVmDownLoadServer::count_leading_entries(s32 i, s32 end) {
    Ent_803EA960 *e = &((Ent_803EA960 *)quest_download_slot_chain_table)[i];
    s32 n;
    s32 total = 0;
    while (i < end) {
        n = e->count;
        if (n == 0) {
            return -1;
        }
        if (e->obj != NULL && (u32)e->obj != 0xFFFFFFFF && e->obj->type != 0x28) {
            break;
        }
        total += n;
        i += n;
        e += n;
    }
    if (total == 0 || i >= end) {
        return total;
    }
    return total + n;
}

extern s32 lbl_805D7880;

#pragma push
#pragma dont_inline off
#pragma inline_depth(3)
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_lifetimes off
inline size_t selection_workspace_address(const Work_80595008 &workspace) {
    return reinterpret_cast<size_t>(&workspace);
}
inline size_t borrow_selection_address(const size_t &address) {
    return address;
}
inline s32 borrow_selection_limit(const s32 &limit) {
    return limit;
}
inline s32 select_download_length(s32 start, s32 end) {
    s32 length = TQuestVmDownLoadServer::select_best_slot_entry(start, end, -1);
    return length;
}
#pragma pop

#define QUEST_WORKSPACE_SLOT(address, index) \
    reinterpret_cast<Slot_803EA428 *>((address) + offsetof(Work_80595008, slots) + (index) * sizeof(Slot_803EA428))

#pragma push
#pragma dont_inline off
#pragma inline_depth(3)
#pragma opt_common_subs off
#pragma opt_lifetimes off
#pragma opt_propagation off
void TQuestVmDownLoadServer__sub_803EA9E8(s32 start, s32 inputEnd, s32 mode, s32 selectedLength) {
    s32 selectedEnd;
    u8 *text;
    Slot_803EA428 *first;
    s32 groupPos;
    s32 entryEnd;
    s32 remaining;
    Slot_803EA428 *following;
    Slot_803EA428 *slot;
    s32 pos;
    Out_803E9FFC **link;
    s32 groupLength;
    size_t workspaceAddress;
    Slot_803EA428 *walk;
    s32 next;
    const Ent_803E9DE0 *tokens;
    s32 length;
    Out_803E9FFC *entry;
    Out_803E9FFC *prunedEntry;
    s32 covered;
    s32 limit = borrow_selection_limit(inputEnd);
    Out_803E9FFC *allocated;
    s32 tokenLength;

    first = QUEST_WORKSPACE_SLOT(borrow_selection_address(workspaceAddress = selection_workspace_address(lbl_80595008)), start);
    text = (u8 *)&quest_download_scratch_storage + start;
    lbl_805D7888 = mode;
    slot = first;
    remaining = limit - start;
    while (remaining > 0) {
        if (slot->x0 == (const Ent_803E9DE0 *)0xFFFFFFFF) {
            tokens = ((TQuestVmDownLoadServer *)text)->find_longest_match_entry(remaining, &tokenLength);
            if (tokens == (const Ent_803E9DE0 *)0xFFFFFFFF) {
                break;
            }
            slot->x18 = tokenLength;
            slot->x0 = tokens;
        }
        text++;
        remaining--;
        slot++;
    }
    if (lbl_805D7888 == 3 && lbl_805D7880 != 0) {
        return;
    }
    pos = start;
    selectedEnd = start + selectedLength;
    while (pos < limit) {
        slot = QUEST_WORKSPACE_SLOT(workspaceAddress, pos);
        if (slot->x15 > 0) {
            pos += slot->x15;
            continue;
        }
        if (slot->list == NULL && TQuestVmDownLoadServer__sub_803EA428(pos, limit) == 0) {
            break;
        }
        if (slot->x8 == NULL && TQuestVmDownLoadServer__sub_803EA1A8(pos, limit) == 0) {
            break;
        }
        entry = slot->x8;
        while (entry != NULL) {
            entryEnd = pos + entry->off;
            next = entryEnd;
            if (entryEnd >= limit) {
                if (lbl_805D7888 >= 3) {
                    if (entry->a != 0xFF) {
                        break;
                    }
                    lbl_805D7888 = 0;
                }
            } else {
                following = QUEST_WORKSPACE_SLOT(workspaceAddress, next);
                if (following->list == NULL && TQuestVmDownLoadServer__sub_803EA428(next, limit) == 0) {
                    break;
                }
                if (following->x8 == NULL && TQuestVmDownLoadServer__sub_803EA1A8(next, limit) == 0) {
                    break;
                }
            }
            entry = entry->next;
        }

        if (pos == start) {
            if (lbl_805D7888 == 1) {
                TQuestVmDownLoadServer::select_best_slot_entry(pos, limit, selectedLength);
                first->x14 = 1;
                length = selectedLength;
                goto chosen_length;
            } else if (lbl_805D7888 == 2) {
                first->x14 = 1;
                length = selectedLength;
                goto chosen_length;
            }
        } else if (pos == selectedEnd && lbl_805D7888 == 2) {
            TQuestVmDownLoadServer::reset_slot_chain_timers(pos);
        }
        length = select_download_length(pos, limit);
        if (length == -1) {
            break;
        }
    chosen_length:
        prunedEntry = slot->x8;
        link = &slot->x8;
        while (prunedEntry != NULL) {
            if (prunedEntry->off == length) {
                link = &prunedEntry->next;
            } else {
                *link = prunedEntry->next;
                TQuestVmDownLoadServer::push_download_entry((s32 *)prunedEntry);
            }
            prunedEntry = *link;
        }
        TQuestVmDownLoadServer__sub_803EC460(pos, length);
        slot->x15 = length;
        pos += length;
    }
    for (groupPos = start; groupPos < limit;) {
        slot = QUEST_WORKSPACE_SLOT(workspaceAddress, groupPos);
        walk = slot;
        covered = walk->x15;

        if (walk->x14 != 0) {
            groupLength = covered;
        } else {
            groupLength = TQuestVmDownLoadServer::count_leading_entries(groupPos, limit);
            if (groupLength < 0) {
                return;
            }
            if (groupLength == 0) {
                groupLength = covered;
            }
            if (groupLength == covered) {
                walk->x14 = 1;
            } else {
                while (covered < groupLength) {
                    if ((u32)walk->x8 != 0xFFFFFFFF) {
                        TQuestVmDownLoadServer__sub_803ECD8C((Node_803ECD8C *)walk->x8);
                    }
                    walk->x8 = NULL;
                    walk->x15 = 0;
                    ((TQuestVmDownLoadServer *)walk->xc)->free_node_list();
                    walk->xc = NULL;
                    covered += (walk = QUEST_WORKSPACE_SLOT(workspaceAddress, groupPos + covered))->x15;
                }
                if ((u32)walk->x8 != 0xFFFFFFFF) {
                    TQuestVmDownLoadServer__sub_803ECD8C((Node_803ECD8C *)walk->x8);
                }
                walk->x8 = NULL;
                walk->x15 = 0;
                ((TQuestVmDownLoadServer *)walk->xc)->free_node_list();
                walk->xc = NULL;
                slot->x15 = groupLength;
                allocated = (Out_803E9FFC *)TQuestVmDownLoadServer__sub_803ECF48();
                if (allocated != NULL) {
                    allocated->off = groupLength;
                    allocated->a = 0x28;
                    allocated->b = 0;
                    allocated->src = NULL;
                    allocated->x8 = 0;
                    allocated->xa = 0;
                    allocated->next = NULL;
                    slot->x8 = allocated;
                    slot->x14 = 1;
                    TQuestVmDownLoadServer__sub_803EC460(groupPos, groupLength);
                }
            }
        }
        groupPos += groupLength;
    }
}
#pragma pop

void TQuestVmDownLoadServer__sub_803EADD4(Obj_803EADD4 *arg0, s32 arg1) {
    if (arg1 == 0) {
        arg0->x0 = -1;
        arg0->x18 = -1;
        if ((u32)arg0->x4 != 0xFFFFFFFF) {
            release_node_chain__22TQuestVmDownLoadServerFPv((Node_803ECDC4 *)(arg0->x4));
        }
        arg0->x4 = NULL;
        arg0->x17 = -1;
        arg0->x19 = -1;
        arg0->x16 = 0;
    }
    if (arg0->x8 != NULL && (u32)arg0->x8 != 0xFFFFFFFF) {
        TQuestVmDownLoadServer__sub_803ECD8C(arg0->x8);
    }
    arg0->x8 = NULL;
    if (arg0->xc != NULL) {
        ((TQuestVmDownLoadServer *)(arg0->xc))->free_node_list();
    }
    arg0->xc = NULL;
    arg0->x10 = 0;
    arg0->x14 = 0;
    arg0->x15 = 0;
}

void TQuestVmDownLoadServer__sub_803EAE84(s32 arg0, s32 arg1, void *arg2) {
    R_803EAE84 *p;
    R_803EAE84 *end;
    end = &((R_803EAE84 *)quest_download_slot_chain_table)[arg1];
    p = &((R_803EAE84 *)quest_download_slot_chain_table)[arg0];
    for (; p < end; p++) {
        TQuestVmDownLoadServer__sub_803EADD4((Obj_803EADD4 *)(p), (s32)arg2);
    }
}

struct Ent_803EAEF0 {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xc;
    s32 x10;
    u8 x14;
    u8 x15;
    u8 x16;
    s8 x17;
    s8 x18;
    s8 x19;
};

void TQuestVmDownLoadServer::init_entries() {
    Ent_803EAEF0 *p;

    for (p = (Ent_803EAEF0 *)quest_download_slot_chain_table; p < (Ent_803EAEF0 *)quest_download_slot_chain_table + 80; p++) {
        p->x0 = -1;
        p->x4 = 0;
        p->x8 = 0;
        p->xc = 0;
        p->x10 = 0;
        p->x14 = 0;
        p->x15 = 0;
        p->x16 = 0;
        p->x17 = -1;
        p->x18 = -1;
        p->x19 = -1;
    }
}
}
