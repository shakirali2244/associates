void setup(){
  println("starting");
  noLoop();
}
void draw(){
  int[] myArray = generateArray(10);
  println("The unsorted array");
  println (myArray);
  println("The start of the sorting");
  selectionSort(myArray);
  println("and finally, the sorted array");
  println(myArray);  
}
int[] generateArray(int n){
  int[] arr = new int[n];
  for (int i = 0; i<n; i++){
    arr[i] = (int)random(100);
  }
  return arr;
}
void selectionSort(int[] arr){
  for (int i = 1; i<arr.length; i++){
    int j = i;
    while(j > 0 && arr[j] < arr[j-1]){
       println(arr[j] + " is less than "+ arr[j-1] + " hence insert the lesser to lower position");
      int t = arr[j-1];
      arr[j-1] = arr[j];
      arr[j] = t;
      j--;
    }
  }
}