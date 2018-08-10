#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void print(int * data, int M){
  for(int i=0; i<M; i++){
    printf("%d\n",data[i]);
  }
}

int max_check(int * data, int k, int M_n){
  int max = data[0];
  int j_m = 0;
  int i=0;

  while(data[i] != M_n){
    if(max<data[i]){
      max = data[i];
      j_m = i;
    }
    i++;
  }
  if(i <= k-1){
    return -1;
  }
  else if(j_m > k-1){
    return -1;
  }
  else
    return 1;
}

int random1(int lower, int higher) {
return lower + (int)((rand()*1.0 /RAND_MAX)* (higher - lower + 1));

}

int * shuffleArrayRecursively(int *cards, int i) {
if (i == 0) return cards;
shuffleArrayRecursively(cards, i - 1); /*II Shuffle earlier part 16*/
int k =random1(0, i); /*II Pick random index to swap with*/

// * Swap element k and i *1
int temp;
temp = cards[k];
cards[k]=cards[i];
cards[i]=temp;
// * Return shuffled array *1
return cards;
}

int main(){
  srand(time(NULL));
// int n;
// scanf("%d",&n);


  int n = 1000, N = 1000000, M_k, M_k_n, c=0, M_n;
  int k_list[n];
  // scanf("%d %d %d",&n,&k,&N);
  int data[n];
  for(int i=0; i<n; i++){
    k_list[i]=0;
    data[i]=i+1;
  }

  for(int i=1; i<=N; i++){

    shuffleArrayRecursively(data, n-1);
    for(int k=1; k<n; k++){
      M_k = max_check(data, k, n);
      if(M_k==1)
      k_list[k]++;

    }

  }
  for(int j=0; j<n; j++){

	   printf("k=%d prob = %f\n",j+1,1.0*k_list[j]/N);

	}

}
