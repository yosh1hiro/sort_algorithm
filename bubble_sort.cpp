#include <iostream>

/*
  安定なソート
  順番が逆になっている隣接要素がなくなるまで、次の処理を繰り返す
  - 配列の末尾から隣接する要素を順番に比べて行き、大小関係が逆ならば交換する。
  オーダーはO(N^2)
*/

// flagを用いたバブルソート
int bubbleSort(int A[], int N) {
  int sw = 0;
  bool flag = 1;
  for (int i = 0; flag; i++) {
    flag = 0;
    for (int j = N - 1; j >= i + 1; j--) {
      if (A[j] < A[j - 1]) {
        std::swap(A[j], A[j - 1]);
        flag = 1;
        sw++;
      }
    }
  }
  return sw;
}

int main() {
  int A[100], N, sw;
  std::cin >> N;
  for (int i = 0; i < N; i++) std::cin >> A[i];

  sw = bubbleSort(A, N);

  for (int i = 0; i < N; i++) {
    if(i) std::cout << " ";
    std::cout << A[i];
  }
  std::cout << std::endl;
  std::cout << sw << std::endl;

  return 0;
}
