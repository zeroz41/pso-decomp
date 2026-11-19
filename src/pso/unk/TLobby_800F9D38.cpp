#include "pso/system/ResourceFile.h"
#include "pso/system/TGStream.h"

u8 *load_disc_file(const char *filename) {
    disc_read_filename = filename;
    return TGStream::load_file(filename);
}

s32 read_disc_file_sectors(const char *filename, void *destination) {
    disc_read_filename = filename;
    return TGStream::load_sct_file(filename, (u8 *)destination);
}
