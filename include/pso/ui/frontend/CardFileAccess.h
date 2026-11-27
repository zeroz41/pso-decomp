#ifndef PSO_UI_FRONTEND_CARDFILEACCESS_H
#define PSO_UI_FRONTEND_CARDFILEACCESS_H

#include "types.h"

// Write a stamped save file; the protected form also marks it no-copy/no-move.
s32 write_card_file_protected(s32 chan, const char *filename, void *buf, s32 blocks);
s32 write_card_file(s32 chan, const char *filename, void *buf, s32 blocks);
s32 read_card_file(s32 chan, const char *file_name, void *buffer);

#endif
