extern "C" char* __copy(char* to, char* from, unsigned long size) {
    if (!to)
        return to;
    if (!size)
        return to;
    char* d = to;
    do {
        *d++ = *from++;
    } while (--size);
    return to;
}
