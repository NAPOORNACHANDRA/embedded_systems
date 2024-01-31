#include "stats.h"
double mean;
double median;
double minimum;
double maximum;
void print_array(char *numbers, int siz) {
    printf("The elements of the array are: ");
    for (int i = 0; i < siz; i++) {
        printf("%d, ", numbers[i]-'0');
    }
    printf("\n");
}
void merge(char *numbers,int low,int high,int mid,int siz){
         int i=low;
         int j=mid+1;
         int k=low;
         char sorted[siz];
         while(i<=mid&&j<=high){
               if( numbers[i]-'0'>= numbers[j]-'0'){
                     sorted[k]=numbers[i];
                     i++;
                     k++;
               }
               else{
                  sorted[k]=numbers[j];
                  j++;
                  k++;
               }
         }
         if(i<=mid){
            while(i<=mid){
               sorted[k]=numbers[i];
               i++;
               k++;
            }
         }
         else{
            while(j<=high){
               sorted[k]=numbers[j];
               j++;
               k++;
            }
         }
         for(int n=low;n<=high;n++){
            numbers[n]=sorted[n];
         }

}
void sort_function(int low,int high,char*numbers,int siz){
         if(low<high){
            int mid=(low+high)/2;
            sort_function(low,mid,numbers,siz);
            sort_function(mid+1,high,numbers,siz);
            merge(numbers,low,high,mid,siz);
         }
}
void sort_array(char *numbers,int siz){
         int low=0;
         int high=siz-1;
         sort_function(low,high,numbers,siz);

}
void find_median(const char *numbers,int siz){
      int mid=siz/2;
      if(siz%2==0){
         median=( numbers[mid]-'0'+ numbers[mid-1]-'0')/2;
      }
      else{
         median=( numbers[mid]-'0');
      }
}
void find_maximum(const char*numbers,int siz){
      maximum= numbers[0]-'0';
}
void find_minimum(const char *numbers,int siz){
      minimum= numbers[siz-1]-'0';
}
void find_mean(const char *numbers,int siz){
      double sum=0;
      for(int i=0;i<siz;i++){
         sum+=(numbers[i]-'0');
      }
      mean=sum/siz;
}

void print_statistics(){
      printf("\nThe mean of the array is : %lf\n",mean);
      printf("\nThe median of the array is : %lf\n",median);
      printf("\nThe maximum of the array is : %lf\n",maximum);
      printf("\nThe minimum of the array is : %lf\n",minimum);
}


int main() {
      char numbers[]={'1','2','5','7','9','2','4','8','3','0','5','9'};
      int siz=sizeof(numbers)/sizeof(numbers[0]);
      print_array(numbers,siz);
      sort_array(numbers,siz);
      print_array(numbers,siz);
      find_mean(numbers,siz);
      find_median(numbers,siz);
      find_maximum(numbers,siz);
      find_minimum(numbers,siz);
      print_statistics(numbers,siz);
}

