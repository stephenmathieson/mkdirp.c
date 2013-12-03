
//
// str-copy.c
//
// Copyright (c) 2013 Stephen Mathieson
// MIT licensed
//

#include <string.h>
#include <stdlib.h>
#include "str-copy.h"

char *str_copy(char *str) {
  int len = strlen(str) + 1;
  char *buf = (char *) malloc(len * sizeof(char *));
  memcpy(buf, str, len);
  return buf;
}
