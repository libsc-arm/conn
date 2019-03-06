#ifndef CPUINFO_H
#define CPUINFO_H


struct cpu_signature_t {
    unsigned stepping:4;
    unsigned model:4;
    unsigned family:4;
    unsigned type:2;
    unsigned reserved1:2;
    unsigned ext_model:4;
    unsigned ext_family:8;
    unsigned reserved2:4;
};

void fetch_cpu_info(struct cpu_signature_t *);

#endif
