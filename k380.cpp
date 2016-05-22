#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "hidapi.h"

#define MAX_STR 255


const unsigned char k380_seq_fkeys_on[]  = {0x0,0x10, 0xff, 0x0b, 0x1e, 0x00, 0x00, 0x00};
const unsigned char k380_seq_fkeys_off[] = {0x0,0x10, 0xff, 0x0b, 0x1e, 0x01, 0x00, 0x00};

#define HID_VENDOR_ID_LOGITECH          0x046d
#define HID_DEVICE_ID_K380              0xb342

int main(int argc, char* argv[]) {
  const unsigned char *sequence;
  hid_device *handle = NULL;
  char *result;
  int res;

  sequence = k380_seq_fkeys_on;
  result = "on";

  if(argc == 2 && strcmp("off", argv[1]) == 0) {
    sequence = k380_seq_fkeys_off;
    result = "off";
  }

  res = hid_init();

  do {
  handle = hid_open(HID_VENDOR_ID_LOGITECH, HID_DEVICE_ID_K380, NULL);
  res = hid_write(handle, sequence, 8);
  hid_close(handle);
  } while (res < 0);

  printf("Fkeys %s\n", result);

}
