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
  return -1;
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

  int file = open("arr.txt", O_CREAT | O_WRONLY, 0644);
  write(file, rand_nums, sizeof(int) * 10);

  file = open("arr.txt", O_RDONLY, 0);
  int new_nums[10];
  read(file, new_nums, sizeof(int) * 10);

  printf("Reading array:\n[");
  for (i = 0; i < 10; i++) {
    printf("%d", new_nums[i]);
    if (i == 9) printf("]\n");
    else printf(", ");
  }

  remove("arr.txt");
}
