#include <stdlib.h>

#include "vendor.h"
#include "cpuleaf.h"


static void cast_to_char(uint32_t reg, char *buf, int index) {
    *(uint32_t *)(&buf[index]) = reg;
}

void fetch_vendor_info(struct vendor *v) {
    return;
}

char* get_manufacturer_id() {
    struct cpu_regs_t cr;
    /* Make cpuid call using leaf 0, manufacturer id is returned in
     * ebx, edx, ecx in that order.
     */
    cpuid(0, &cr);
    char *buf = malloc(sizeof(char) * 12);
    cast_to_char(cr.ebx, buf, 0);
    cast_to_char(cr.edx, buf, 4);
    cast_to_char(cr.ecx, buf, 8);

    return buf;
}


