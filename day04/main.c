#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <openssl/md5.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>

int main(int argc, char **argv) {
  assert(argc > 1 && "Provide at least one argument");

  char *key = argv[1];
  char buf[128];
  int result_p1 = INT_MAX;
  int result_p2 = INT_MAX;

  for (int i = 0;; i++) {
    unsigned char md5_digest[MD5_DIGEST_LENGTH] = {'A'};

    size_t len = snprintf(buf, sizeof(buf), "%s%d", key, i);

    MD5((unsigned char *)buf, len, md5_digest);

    if (result_p1 == INT_MAX && md5_digest[0] == 0 && md5_digest[1] == 0 &&
        (md5_digest[2] >> 4) == 0) {
      result_p1 = i;
    }

    if (result_p2 == INT_MAX && md5_digest[0] == 0 && md5_digest[1] == 0 &&
        md5_digest[2] == 0) {
      result_p2 = i;
      break;
    }
  }

  printf("Part One: %d; Part Two: %d\n", result_p1, result_p2);

  return EXIT_SUCCESS;
}
