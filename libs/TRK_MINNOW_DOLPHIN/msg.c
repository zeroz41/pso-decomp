#include "PowerPC_EABI_Support/MetroTRK/trk.h"

DSError TRKMessageSend(TRKBuffer* msg)
{
    u8 checksum;
    u8 byte;
    u8 checksumByte;
    s32 error;
    s32 i;

    checksum = 0;
    for (i = 0; i < msg->length; i++) {
        checksum = checksum + msg->data[i];
    }
    checksum = checksum ^ 0xFF;
    error = WriteUART1(0x7E);
    if (error == 0) {
        for (i = 0; i < msg->length; i++) {
            byte = msg->data[i];
            if (byte == 0x7E || byte == 0x7D) {
                error = WriteUART1(0x7D);
                byte ^= 0x20;
                if (error != 0) {
                    break;
                }
            }
            error = WriteUART1(byte);
            if (error != 0) {
                break;
            }
        }
    }
    if (error == 0) {
        checksumByte = checksum;
        for (i = 0; i < 1; i++) {
            if (checksumByte == 0x7E || checksumByte == 0x7D) {
                error = WriteUART1(0x7D);
                checksumByte ^= 0x20;
                if (error != 0) {
                    break;
                }
            }
            error = WriteUART1(checksumByte);
            if (error != 0) {
                break;
            }
        }
    }
    if (error == 0) {
        error = WriteUART1(0x7E);
    }
    if (error == 0) {
        error = WriteUARTFlush();
    }
    return error;
}
