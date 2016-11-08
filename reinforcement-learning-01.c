#include <stdio.h>
#include <stdlib.h>

int main() {
  
  int options[10];
  int feedbacks[10];
  int result;
  int feedback;
  char try;
  int flag;
  unsigned int seed;
  
  int i;
  for(i = 0; i < 10; i++) {
    options[i] = i;
    feedbacks[i] = -1;
  }

  do {
    printf("Enter seed: ");
    scanf("%u", &seed);
    getchar();
    srand(seed);
    flag = 1;
    do {
      result = rand() % 10;
      printf("Intermidiate Result: %d, Feedback: %d\n", result, feedbacks[result]);
      if(feedbacks[result] != -1) {
        if(feedbacks[result] == 0) {
          flag = 1;
        } else {
          flag = 0;
        }
      } else {
        flag = 0;
      }
    } while(flag == 1);
    printf("Result: %d\n", result);
    printf("Enter feedbak (0/1): ");
    scanf("%d", &feedback);
    getchar();
    feedbacks[result] = feedback;
    printf("Try again? (y/n): ");
    scanf("%c", &try);
  } while(try == 'y');

  for(i = 0; i < 10; i++) {
    printf("[%d, %d]", options[i], feedbacks[i]);
    if(i < 9) {
      printf(", ");
    }
  }
  printf("\n");
  
  return 0;
}
