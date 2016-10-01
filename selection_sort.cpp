#include <iostream>

/*
  安定なソートではない
  以下の処理をN-1回繰り返す
  - 未ソートの部分から最小の要素の位置minjを特定する
  - minjの位置にある要素と未ソートの部分の先頭要素を交換する
  O(N^2)
*/
int selectionSort(int A[], int N) {
  int minj, sw = 0;
  for (int i = 0; i < N; i++) {
    minj = i;
    for (int j = i; j < N; j++) {
      if(A[j] < A[minj]) minj = j;
    }
    std::swap(A[i], A[minj]);
    if (i != minj) sw++;
  }
  return sw;
}

int main() {
  int N, A[100], sw;

  std::cin >> N;

  for (int i = 0; i < N; i++) std::cin >> A[i];

  sw = selectionSort(A, N);
  for (int i = 0; i < N; i++) std::cout << A[i] << " ";
  std::cout << std::endl;
  std::cout << sw << std::endl;
}
