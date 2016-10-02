#include <iostream>

struct Card { char suit, value; };

void bubble(struct Card C[], int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N - 1; j++) {
      if (C[j].value > C[j + 1].value) {
        std::swap(C[j], C[j + 1]);
      }
    }
  }
}

void selection(struct Card C[], int N) {
  for (int i = 0; i < N; i++) {
    int minj = i;
    for (int j = i; j < N; j++) {
      if (C[j].value < C[minj].value) minj = j;
    }
    std::swap(C[i], C[minj]);
  }
}

void print(struct Card C[],int N) {
  for (int i = 0; i < N; i++) {
    std::cout << C[i].suit  << C[i].value << " ";
  }
  std::cout << std::endl;
}

bool isStable(struct Card C1[], struct Card C2[], int N) {
  for (int i = 0; i < N; i++) {
    if (C1[i].suit != C2[i].suit) return false;
  }
  return true;
}

int main () {
  int N;
  Card C1[36], C2[36];
  char ch;

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> C1[i].suit >> C1[i].value;
  }

  for (int i = 0; i < N; i++) C2[i] = C1[i];

  bubble(C1, N);
  selection(C2, N);

  print(C1, N);
  std::cout << "Stable" << std::endl;
  print(C2, N);
  if (isStable(C1, C2, N)) {
    std::cout << "Stable" << std::endl;
  } else {
    std::cout << "Not stable" << std::endl;
  }

  return 0;
}
