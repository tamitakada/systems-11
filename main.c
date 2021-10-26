#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int get_random() {
  int file = open("/dev/random", O_RDONLY, 0);
  if (file != -1) {
    int num[1];
    read(file, num, sizeof(int));
    return num[0];
  }
}

int main() {
  int rand_nums[10];
  int i;
  for (i = 0; i < 10; i++) {
    rand_nums[i] = get_random();
  }

  printf("Randomly populated array:\n[");
  for (i = 0; i < 10; i++) {
    printf("%d", rand_nums[i]);
    if (i == 9) printf("]\n");
    else printf(", ");
  }
}
