
#include <assert.h>
#include <unistd.h>
#include "src/mkdirp.h"

int exists(char *path) {
  struct stat b;
  return stat(path, &b);
}

void setup() {
  if (0 == exists("./tmp/foo/bar/baz")) rmdir("./tmp/foo/bar/baz");
  if (0 == exists("./tmp/foo/bar/")) rmdir("./tmp/foo/bar/");
  if (0 == exists("./tmp/foo/")) rmdir("./tmp/foo/");
  if (0 == exists("./tmp/")) rmdir("./tmp/");
}

int main(int argc, char **argv) {
  setup();
  assert(0 == mkdirp("./tmp/foo/bar/baz", 0777));
  assert(0 == exists("./tmp"));
  assert(0 == exists("./tmp/foo"));
  assert(0 == exists("./tmp/foo/bar"));
  assert(0 == exists("./tmp/foo/bar/baz"));
  assert(-1 == mkdirp("/root/i/dont/have/access/here", 1234));
  assert(-1 == exists("/root/i/dont/have/access/here"));
  return 0;
}
