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

const QuestDownloadMatchToken quest_download_lz_match_entry_table[] = {
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

// The default item prefix is followed by the original all-ones marker.
const QuestDownloadItemNode quest_download_lz_default_tokens = {
    0, 0x19, 0, -1, 0, {0, 0}, NULL,
};

// Character class of each byte for the romaji/kana converters (TQuestVmDownLoadServer_803EB0D8, _803E6970).
// Low nibble = kind: a i u e o = 1..5, n = 0xC, y = 0xF, other letters 0xD, half-width kana taking
// dakuten 0xA / handakuten 0xB, the two voicing marks 6/7, punctuation 9, rest 8. Flags: 0x80 digit,
// 0x40 letter, 0x20 closing mark, 0x10 hex letter. It closes this TU's .rodata (no pad after
// quest_download_lz_default_tokens): convert_romaji_to_kana loads it with its own lis/addi next to
// romaji_kana_rows, so it was not in that pooling TU. GC/1.2.5 C++ puts an external const in .data,
// hence the section.
__declspec(section ".rodata") extern const u8 romaji_kana_char_class_table[0x100] = {
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x28, 0x48, 0x48, 0x48, 0x48, 0x08, 0x08, 0x28, 0x08, 0x08, 0x09, 0x09, 0x09, 0x09,
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x08, 0x08, 0x08, 0x08, 0x28, 0x08,
    0x08, 0x51, 0x5D, 0x5D, 0x5D, 0x54, 0x5D, 0x4D, 0x4D, 0x42, 0x4D, 0x4D, 0x4D, 0x4D, 0x4C, 0x45,
    0x4D, 0x4D, 0x4D, 0x4D, 0x4D, 0x43, 0x4D, 0x4D, 0x4D, 0x4F, 0x4D, 0x09, 0x08, 0x29, 0x08, 0x08,
    0x08, 0x51, 0x5D, 0x5D, 0x5D, 0x54, 0x5D, 0x4D, 0x4D, 0x42, 0x4D, 0x4D, 0x4D, 0x4D, 0x4C, 0x45,
    0x4D, 0x4D, 0x4D, 0x4D, 0x4D, 0x43, 0x4D, 0x4D, 0x4D, 0x4F, 0x4D, 0x08, 0x08, 0x28, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x28, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x0A, 0x08, 0x08, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A,
    0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x06, 0x07,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
};

extern "C" {
s32 TQuestVmDownLoadServer::is_download_cmd_allowed(u8 cmd) {
    if ((lbl_805D7888 - 1) <= 1U) {
        return 0;
    }
    switch (cmd) {
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
inline s32 IsX_803E9FFC(u8 cmd) {
    if ((lbl_805D7888 - 1) <= 1U) {
        return 0;
    }
    switch (cmd) {
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
QuestDownloadSegment *TQuestVmDownLoadServer__sub_803E9A74(s32 pos, s32 end, u8 a, u8 b) {
    s32 n;
    const QuestDownloadSlot *slot;
    const QuestDownloadMatchToken *sub;
    const QuestDownloadMatchToken *e;
    QuestDownloadSegment *head;
    head = NULL;
    if (pos >= end) {
        if (lbl_805D7888 < 3) {
            return NULL;
        }
        return (QuestDownloadSegment *)-1;
    }
    slot = &quest_download_slot_chain_table[pos];
    e = slot->tokens;
    if ((uaddr)e == 0xFFFFFFFF) {
        return (QuestDownloadSegment *)-1;
    }
    if (e == NULL && IsBreakChar_803E9A74(quest_download_scratch_storage[pos])) {
        if (a == 0 || TQuestVmDownLoadServer::is_valid_item_for_slot(a, b)) {
            QuestDownloadSegment *s = TQuestVmDownLoadServer__alloc_quest_segment();
            if (s != NULL) {
                s->off = 1;
                s->a = 0xFF;
                s->reserved_2[0] = 0xFF;
                s->b = 0;
                s->reserved_2[1] = 0;
                s->next = NULL;
            }
            return s;
        }
    }
    // Entries that end at this position.
    for (; e != NULL; e -= (s8)e->d) {
        if (TQuestVmDownLoadServer::is_valid_item_for_slot(e->a, e->b)) {
            if (a == 0 || TQuestVmDownLoadServer__sub_803E7390(a, b, e->a)) {
                u8 *text = quest_download_scratch_storage + pos;
                n = quest_download_lz_match_strings[e->off];
                if (pos + n >= end || !IsX_803E9FFC(text[n])) {
                    QuestDownloadSegment *s = TQuestVmDownLoadServer__alloc_quest_segment();
                    if (s != NULL) {
                        s->off = n;
                        s->reserved_2[0] = s->a = e->a;
                        s->reserved_2[1] = s->b = e->b;
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
    for (sub = slot->tokens; sub != NULL; sub -= (s8)sub->d) {
        if (a == 0 || TQuestVmDownLoadServer__sub_803E7390(a, b, sub->a)) {
            QuestDownloadSegment *r;
            n = quest_download_lz_match_strings[sub->off];
            r = TQuestVmDownLoadServer__sub_803E9A74(pos + n, end, sub->a, sub->b);
            if ((uaddr)r == 0xFFFFFFFF) {
                TQuestVmDownLoadServer__free_quest_segment_chain(head);
                return (QuestDownloadSegment *)-1;
            }
            if (r != NULL) {
                QuestDownloadSegment *s;
                for (s = r;; s = s->next) {
                    s->off += n;
                    s->reserved_2[0] = sub->a;
                    s->reserved_2[1] = sub->b;
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

const QuestDownloadMatchToken *TQuestVmDownLoadServer::find_longest_match_entry(u8 *text, s32 remaining, s32 *arg2) {
    const u8 *s;
    u8 *a;
    s32 k;
    s32 rem;
    const QuestDownloadMatchToken *p;
    s32 m;
    s32 best = 1;
    u8 c = text[0];
    if (c < 0xA0) {
        *arg2 = 1;
        return NULL;
    }
    c -= 0xA0;
    for (p = &quest_download_lz_match_entry_table[quest_download_lz_match_index_table[c + 1]] - 1; p >= &quest_download_lz_match_entry_table[quest_download_lz_match_index_table[c]]; p--) {
        a = text + 1;
        rem = remaining - 1;
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
                    return (const QuestDownloadMatchToken *)-1;
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

void TQuestVmDownLoadServer::latch_slot_value(s32 index) {
    QuestDownloadSlot *slot = &quest_download_slot_chain_table[index];
    if (slot->x16 == 0 && slot->x14 != 0) {
        slot->x16 = slot->x15;
    }
}

s32 TQuestVmDownLoadServer__sub_803E9F54(s32 arg0) {
    QuestDownloadSlot *r;
    if (arg0 >= quest_text_end) {
        return 0;
    }
    r = &quest_download_slot_chain_table[arg0];
    if (lbl_805D7848 == 2 && r->x14 == 0) {
        return 0;
    }
    return r->x15;
}

QuestDownloadEntryNode *insert_quest_download_entry(QuestDownloadEntryNode *head, QuestDownloadEntryNode *entry) {
    QuestDownloadEntryNode *cur;
    QuestDownloadEntryNode *prev;
    s16 k = entry->prefix.off;
    if (head == NULL || head->prefix.off < k) {
        entry->next = head;
        return entry;
    }
    cur = head->next;
    prev = head;
    while (cur != NULL) {
        if (cur->prefix.off < k) {
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    prev->next = entry;
    entry->next = cur;
    return head;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
QuestDownloadEntryNode *TQuestVmDownLoadServer__sub_803E9FFC(s32 start, s32 end, const QuestDownloadItemNode *t) {
    s32 off;
    QuestDownloadEntryNode *head;
    QuestDownloadEntryNode *tail;
    s32 pos;
    QuestDownloadSegment *s;
    QuestDownloadSegment *first;
    QuestDownloadEntryNode *o;
    off = t->off;
    head = NULL;
    tail = NULL;
    pos = start + off;
    s = TQuestVmDownLoadServer__sub_803E9A74(pos, end, t->a, t->b);
    if ((uaddr)s == 0xFFFFFFFFU) {
        return (QuestDownloadEntryNode *)-1;
    }
    for (first = s; s != NULL; s = s->next) {
        o = TQuestVmDownLoadServer__alloc_quest_entry_node();
        if (o == NULL) {
            break;
        }
        if (head == NULL) {
            head = o;
        }
        o->prefix.off = off + s->off;
        o->prefix.a = s->a;
        o->prefix.b = s->b;
        o->prefix.source = t;
        o->cost = 0;
        o->base = 0;
        o->next = NULL;
        if (tail != NULL) {
            tail->next = o;
        }
        tail = o;
    }
    TQuestVmDownLoadServer__free_quest_segment_chain(first);
    if (off > 0 && TQuestVmDownLoadServer::is_valid_item_for_slot(t->a, t->b) != 0) {
        if (pos >= end || IsX_803E9FFC(quest_download_scratch_storage[pos]) == 0) {
            o = TQuestVmDownLoadServer__alloc_quest_entry_node();
            if (o != NULL) {
                if (head == NULL) {
                    head = o;
                }
                o->prefix.off = off;
                o->prefix.a = t->a;
                o->prefix.b = t->b;
                o->prefix.source = t;
                o->cost = 0;
                o->base = 0;
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
inline QuestDownloadEntryNode *merge_sorted_nodes(QuestDownloadEntryNode *head, QuestDownloadEntryNode *list) {
    QuestDownloadEntryNode *n;
    QuestDownloadEntryNode *next;
    for (n = list; n != NULL; n = next) {
        next = n->next;
        head = insert_quest_download_entry(head, n);
    }
    return head;
}
// inferred: stores the length of the run of download-allowed commands after start
inline void set_allowed_cmd_run(QuestDownloadEntryNode *o, s32 start, s32 end) {
    s32 i;
    for (i = start + 1; i < end; i++) {
        if (!TQuestVmDownLoadServer::is_download_cmd_allowed(quest_download_scratch_storage[i])) {
            break;
        }
    }
    o->prefix.off = i - start;
}
s32 TQuestVmDownLoadServer__sub_803EA1A8(s32 start, s32 end) {
    QuestDownloadSlot *e;
    QuestDownloadItemNode *tok;
    QuestDownloadEntryNode *list;
    QuestDownloadEntryNode *o;
    e = &quest_download_slot_chain_table[start];
    if ((uaddr)e->items != 0xFFFFFFFF) {
        for (tok = e->items; tok != NULL; tok = tok->next) {
            list = TQuestVmDownLoadServer__sub_803E9FFC(start, end, tok);
            if ((uaddr)list == 0xFFFFFFFF) {
                if (e->head != NULL) {
                    TQuestVmDownLoadServer__free_quest_entry_chain(e->head);
                    e->head = NULL;
                }
                return 0;
            }
            if (list != NULL) {
                e->head = merge_sorted_nodes(e->head, list);
            }
        }
    }
    list = TQuestVmDownLoadServer__sub_803E9FFC(start, end, &quest_download_lz_default_tokens);
    if ((uaddr)list == 0xFFFFFFFF) {
        if (e->head != NULL) {
            TQuestVmDownLoadServer__free_quest_entry_chain(e->head);
            e->head = NULL;
        }
        return 0;
    }
    if (list != NULL) {
        quest_download_slot_chain_table[start].head = merge_sorted_nodes(quest_download_slot_chain_table[start].head, list);
    }
    if (e->head == NULL) {
        o = TQuestVmDownLoadServer__alloc_quest_entry_node();
        if (o == NULL) {
            return -1;
        }
        set_allowed_cmd_run(o, start, end);
        o->prefix.a = 0x28;
        o->prefix.b = 0;
        o->prefix.source = NULL;
        o->cost = 0;
        o->base = 0;
        o->next = NULL;
        e->head = o;
        return 1;
    }
    return 1;
}
#pragma pop

QuestDownloadItemNode *TQuestVmDownLoadServer::build_item_list(s32 start, Hdr_803EA384 *hdr_803_ea384) {
    s16 id;
    s32 x4;
    s32 n;
    QuestDownloadQueryEntry *it;
    QuestDownloadItemNode *head;
    QuestDownloadItemNode *prev;
    QuestDownloadItemNode *node;
    u8 unused[8];
    it = hdr_803_ea384->entries;
    head = NULL;
    prev = NULL;
    id = hdr_803_ea384->len;
    x4 = hdr_803_ea384->x4;
    n = hdr_803_ea384->count;
    while (n-- != 0) {
        node = TQuestVmDownLoadServer__sub_803ECF84();
        if (node == NULL) {
            break;
        }
        if (head == NULL) {
            head = node;
        }
        node->off = id;
        node->a = it->a;
        node->b = it->b;
        node->x4 = x4;
        node->c = it->key;
        node->next = NULL;
        if (prev != NULL) {
            prev->next = node;
        }
        prev = node;
        it++;
    }
    return head;
}



#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
#pragma opt_propagation off
inline void append_candidate_items(QuestDownloadItemNode *item, QuestDownloadItemNode **tail) {
    while (*tail != NULL) {
        tail = &(*tail)->next;
    }
    *tail = item;
}
inline void set_candidate_span(QuestDownloadSlot *slot, s32 maximum) {
    slot->width = maximum;
}
struct QuestDownloadWorkspaceAddress {
    size_t address;
    QuestDownloadWorkspaceAddress(size_t base) : address(base) {}
};
#pragma pop

#define QUEST_WORKSPACE_MATCH(address) reinterpret_cast<QuestDownloadQueryResult *>((address) + offsetof(QuestDownloadWorkspace, result))

#pragma push
#pragma dont_inline off
#pragma inline_depth(2)
#pragma opt_lifetimes off
#pragma opt_propagation off
s32 TQuestVmDownLoadServer__sub_803EA428(s32 start, s32 end) {
    size_t position;
    QuestDownloadSlot *slot;
    s32 stop;
    u32 candidateLength;
    u8 *text;
    QuestDownloadInputEntry *last;
    u8 runKind;
    u32 length;
    u8 kind;

    QuestDownloadWorkspaceAddress workspace(reinterpret_cast<size_t>(&lbl_80595008));
    length = end - start;
    if (length == 0) {
        return 0;
    }
    text = quest_download_scratch_storage + start;
    // position holds the slot displacement on the run paths and an input address in the text scans.
    position = start * sizeof(QuestDownloadSlot);
    slot = reinterpret_cast<QuestDownloadSlot *>(workspace.address + sizeof(QuestDownloadWorkspace) + position);
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
    } else if ((s8)*text == 0 && ((quest_download_entry_table)[start].ch & 0xFF00) == 0) {
        for (stop = start + 1; stop < end; stop++) {
            if (((quest_download_entry_table)[stop].ch & 0xFF00) != 0) {
                break;
            }
        }
        runKind = 0x19;
        goto emit_run;
    } else if ((s8)*text == 0 && TQuestVmDownLoadServer::is_download_command((quest_download_entry_table)[start].ch, 0)) {
        for (stop = start + 1; stop < end; stop++) {
            if (!TQuestVmDownLoadServer::is_download_command((quest_download_entry_table)[stop].ch, 1)) {
                break;
            }
        }
        runKind = 0x19;
    emit_run:
        if (lbl_805D7888 >= 3 && stop == end) {
            return 0;
        }
        QuestDownloadItemNode *item = TQuestVmDownLoadServer__sub_803ECF84();
        if (item != NULL) {
            item->off = stop - start;
            item->a = runKind;
            item->b = 0;
            item->x4 = -1;
            item->c = 0;
            item->next = NULL;
            reinterpret_cast<s8 *>(workspace.address + sizeof(QuestDownloadWorkspace) + offsetof(QuestDownloadSlot, width))[position] = stop - start + 1;
            append_candidate_items(item, &slot->items);
        }
        return 1;
    } else if ((s8)*text == 0) {
        for (stop = start + 1, text++; stop < end; stop++, text++) {
            if ((s8)*text != 0) {
                break;
            }
        }
        QuestDownloadInputEntry *table = quest_download_entry_table;
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
                QuestDownloadItemNode *item = TQuestVmDownLoadServer::build_item_list(start, QUEST_WORKSPACE_MATCH(workspace.address));
                append_candidate_items(item, &slot->items);
                slot->width = QUEST_WORKSPACE_MATCH(workspace.address)->len2;
                candidateLength = QUEST_WORKSPACE_MATCH(workspace.address)->len - 1;
            }
            break;
        case 0:
        default:
            if (kind != 0) {
                candidateLength = end;
            } else {
                slot->items = (QuestDownloadItemNode *)-1;
                return -1;
            }
        }
    }
candidates:
    QuestDownloadItemNode **items = &slot->items;
    for (; candidateLength >= end; candidateLength--) {
        if (kind != 0 && candidateLength == end) {
            QuestDownloadItemNode *item = TQuestVmDownLoadServer__sub_803ECF84();
            if (item != NULL) {
                s8 maximum = end + 1;
                item->off = end;
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
            QuestDownloadItemNode *item = TQuestVmDownLoadServer::build_item_list(start, QUEST_WORKSPACE_MATCH(workspace.address));
            append_candidate_items(item, items);
        }
    }
    return 1;
}
#pragma pop

s32 TQuestVmDownLoadServer::count_leading_entries(s32 i, s32 end) {
    QuestDownloadSlot *e = &quest_download_slot_chain_table[i];
    s32 n;
    s32 total = 0;
    while (i < end) {
        n = e->x15;
        if (n == 0) {
            return -1;
        }
        if (e->head != NULL && (uaddr)e->head != 0xFFFFFFFF && e->head->prefix.a != 0x28) {
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
inline size_t selection_workspace_address(const QuestDownloadWorkspace &workspace) {
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
    reinterpret_cast<QuestDownloadSlot *>((address) + sizeof(QuestDownloadWorkspace) + (index) * sizeof(QuestDownloadSlot))

#pragma push
#pragma dont_inline off
#pragma inline_depth(3)
#pragma opt_lifetimes off
#pragma opt_propagation off
void TQuestVmDownLoadServer__sub_803EA9E8(s32 start, s32 inputEnd, s32 mode, s32 selectedLength) {
    s32 selectedEnd;
    u8 *text;
    QuestDownloadSlot *first;
    s32 groupPos;
    s32 entryEnd;
    s32 remaining;
    QuestDownloadSlot *following;
    QuestDownloadSlot *slot;
    s32 pos;
    QuestDownloadEntryNode **link;
    s32 groupLength;
    size_t workspaceAddress;
    QuestDownloadSlot *walk;
    s32 next;
    const QuestDownloadMatchToken *tokens;
    s32 length;
    QuestDownloadEntryNode *entry;
    QuestDownloadEntryNode *prunedEntry;
    s32 covered;
    s32 limit = borrow_selection_limit(inputEnd);
    QuestDownloadEntryNode *allocated;
    s32 tokenLength;

    first = QUEST_WORKSPACE_SLOT(borrow_selection_address(workspaceAddress = selection_workspace_address(lbl_80595008)), start);
    text = quest_download_scratch_storage + start;
    lbl_805D7888 = mode;
    slot = first;
    remaining = limit - start;
    while (remaining > 0) {
        if (slot->tokens == (const QuestDownloadMatchToken *)0xFFFFFFFF) {
            tokens = TQuestVmDownLoadServer::find_longest_match_entry(text, remaining, &tokenLength);
            if (tokens == (const QuestDownloadMatchToken *)0xFFFFFFFF) {
                break;
            }
            slot->x18 = tokenLength;
            slot->tokens = tokens;
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
        if (slot->items == NULL && TQuestVmDownLoadServer__sub_803EA428(pos, limit) == 0) {
            break;
        }
        if (slot->head == NULL && TQuestVmDownLoadServer__sub_803EA1A8(pos, limit) == 0) {
            break;
        }
        entry = slot->head;
        while (entry != NULL) {
            entryEnd = pos + entry->prefix.off;
            next = entryEnd;
            if (entryEnd >= limit) {
                if (lbl_805D7888 >= 3) {
                    if (entry->prefix.a != 0xFF) {
                        break;
                    }
                    lbl_805D7888 = 0;
                }
            } else {
                following = QUEST_WORKSPACE_SLOT(workspaceAddress, next);
                if (following->items == NULL && TQuestVmDownLoadServer__sub_803EA428(next, limit) == 0) {
                    break;
                }
                if (following->head == NULL && TQuestVmDownLoadServer__sub_803EA1A8(next, limit) == 0) {
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
        prunedEntry = slot->head;
        link = &slot->head;
        while (prunedEntry != NULL) {
            if (prunedEntry->prefix.off == length) {
                link = &prunedEntry->next;
            } else {
                *link = prunedEntry->next;
                TQuestVmDownLoadServer::push_download_entry(prunedEntry);
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
                    if ((uaddr)walk->head != 0xFFFFFFFF) {
                        TQuestVmDownLoadServer__free_quest_entry_chain(walk->head);
                    }
                    walk->head = NULL;
                    walk->x15 = 0;
                    free_quest_text_chain(walk->chain);
                    walk->chain = NULL;
                    covered += (walk = QUEST_WORKSPACE_SLOT(workspaceAddress, groupPos + covered))->x15;
                }
                if ((uaddr)walk->head != 0xFFFFFFFF) {
                    TQuestVmDownLoadServer__free_quest_entry_chain(walk->head);
                }
                walk->head = NULL;
                walk->x15 = 0;
                free_quest_text_chain(walk->chain);
                walk->chain = NULL;
                slot->x15 = groupLength;
                allocated = TQuestVmDownLoadServer__alloc_quest_entry_node();
                if (allocated != NULL) {
                    allocated->prefix.off = groupLength;
                    allocated->prefix.a = 0x28;
                    allocated->prefix.b = 0;
                    allocated->prefix.source = NULL;
                    allocated->cost = 0;
                    allocated->base = 0;
                    allocated->next = NULL;
                    slot->head = allocated;
                    slot->x14 = 1;
                    TQuestVmDownLoadServer__sub_803EC460(groupPos, groupLength);
                }
            }
        }
        groupPos += groupLength;
    }
}
#pragma pop

void TQuestVmDownLoadServer__sub_803EADD4(QuestDownloadSlot *slot, s32 mode) {
    if (mode == 0) {
        slot->tokens = reinterpret_cast<const QuestDownloadMatchToken *>(0xFFFFFFFFU);
        slot->x18 = -1;
        if ((uaddr)slot->items != 0xFFFFFFFF) {
            release_node_chain__22TQuestVmDownLoadServerFPv(slot->items);
        }
        slot->items = NULL;
        slot->width = -1;
        slot->x19 = -1;
        slot->x16 = 0;
    }
    if (slot->head != NULL && (uaddr)slot->head != 0xFFFFFFFF) {
        TQuestVmDownLoadServer__free_quest_entry_chain(slot->head);
    }
    slot->head = NULL;
    if (slot->chain != NULL) {
        free_quest_text_chain(slot->chain);
    }
    slot->chain = NULL;
    slot->timer = 0;
    slot->x14 = 0;
    slot->x15 = 0;
}

void TQuestVmDownLoadServer__sub_803EAE84(s32 begin, s32 end, s32 mode) {
    QuestDownloadSlot *slot;
    QuestDownloadSlot *limit;
    limit = &quest_download_slot_chain_table[end];
    slot = &quest_download_slot_chain_table[begin];
    for (; slot < limit; slot++) {
        TQuestVmDownLoadServer__sub_803EADD4(slot, mode);
    }
}

void TQuestVmDownLoadServer::init_entries() {
    QuestDownloadSlot *slot;
    for (slot = quest_download_slot_chain_table; slot < quest_download_slot_chain_table + 80; slot++) {
        slot->tokens = reinterpret_cast<const QuestDownloadMatchToken *>(0xFFFFFFFFU);
        slot->items = NULL;
        slot->head = NULL;
        slot->chain = NULL;
        slot->timer = 0;
        slot->x14 = 0;
        slot->x15 = 0;
        slot->x16 = 0;
        slot->width = -1;
        slot->x18 = -1;
        slot->x19 = -1;
    }
}
}
