
//
// path-normalize.c
//
// Copyright (c) 2013 Stephen Mathieson
// MIT licensed
//

#include <string.h>
#include "path-normalize.h"
#include "str-copy.h"

/*
 * Normalize the given `path`
 */

char *path_normalize(char *path) {
  if (!path) return NULL;

  char *copy = str_copy(path);
  if (NULL == copy) return NULL;

  size_t len = strlen(copy);
  char *ptr = copy;
  for (int i = 0; i < len; i++) {
    *ptr++ = path[i];
    if ('/' == path[i]) {
      i++;
      while ('/' == path[i]) i++;
      i--;
    }
  }
  *ptr = '\0';

  return copy;
}
