#include <stdio.h>

/*
  安定なソート
  配列は未ソートからソート済みに二分される
  - 先頭の要素をソート済みとする。
  - 配列から未ソートの部分がなくなるまで、以下の処理を繰り返す
    - 未ソート部分の先頭から要素を1つ取り出し変数vに記録する。
    - ソート済みの部分において、変数vより大きい要素を後方へ１つずつ移動する。
    - 最後に空いた位置に「取り出した変数v」を挿入する。
*/

/* 配列の要素を順番に出力 */
void trace(int A[], int N) {
  for (int i = 0; i < N; i++) {
    if ( i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

/* 挿入ソート (0オリジン配列) */
void insertionSort(int A[], int N) {
  int j, v;
  for (int i = 1; i < N; i++) {
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
    trace(A, N);
  }
}

int main() {
  int N, j;
  int A[100];

  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &A[i]);

  trace(A, N);
  insertionSort(A, N);

  return 0;
}
