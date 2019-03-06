#ifndef VENDOR_H
#define VENDOR_H


struct vendor {
    char *id;
    char *name;
};


void fetch_vendor_info(struct vendor *);
char* get_manufacturer_id();

#endif


