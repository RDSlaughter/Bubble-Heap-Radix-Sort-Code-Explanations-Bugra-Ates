
// Buðra ATEÞ 
// Heap Sort

  #include <stdio.h>
  
    // elemanlarýn iþaret ettiði adreslerin yer deðiþtirilmesini saðlayan swap fonksiyonu
void swapNumberPointers(int *firstNumPointer, int *secondNumPointer) 
{ 
    int temporaryNumPointer = *firstNumPointer; 
    *firstNumPointer = *secondNumPointer; 
    *secondNumPointer = temporaryNumPointer; 
} 
  // heap düzenini saðlayan heapify fonksiyonu (max heap)
  void heapify(int numberArray[], int n, int i) {
    
    int largest = i;         // root, right ve left childlarý bulma 
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && numberArray[left] > numberArray[largest]) //left ve right array boyutundan kücük olmalý
      largest = left;      // sol child roottan büyük ise yeni root left olmalý
  
    if (right < n && numberArray[right] > numberArray[largest])
      largest = right;     // sað child roottan büyük ise yeni root right olmalý
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swapNumberPointers(&numberArray[i], &numberArray[largest]); //eðer rootta bir deðiþiklik olduysa
      heapify(numberArray, n, largest);                           // yeni root belirlenmeli
    }                                                             // ardýndan heapify iþlemi tekrar yeni rootla devam edilmeli
  }
  
// heap sýralama fonksiyonu
  
  void heapSort(int arr[], int arraySize) {   // Maximum heap yaratýr
  
    for (int i = arraySize / 2 - 1; i >= 0; i--) // ilk olarak 5/2 = 2.5 - 1 = 1.5 integer deðeri = 
                                                 // yani 0 ve 1 sayýlarý uygun olmak üzere en baþta 2 kez döngü dön
    { 
      heapify(arr, arraySize, i); // heapify bu iþlemde ilk kez baþlýyor ve i olarak 1 yollanýyor
    }
  

    for (int i = arraySize - 1; i >= 0; i--)    // Heap sýralamasý
	{   
    	
      swapNumberPointers(&arr[0], &arr[i]); // baþ ve son eleman deðiþikliðini saðlar
      heapify(arr, i, 0);  // en yüksek numarayý tekrar root yapmayý saðlar
    }
  }
  
void printArray(int numberArray[], int arraySize)  // array elemanlarýný bastýran fonksiyon 
{     
    int i; 
    
    for (i=0; i < arraySize; i++)
	{
        printf("%d ", numberArray[i]); 
    }
} 
  
  int main() { // ana fonksiyon
  	
    int numberArray[] = {5,9,3,4,6}; 
    int arraySize = sizeof(numberArray)/sizeof(numberArray[0]);  // eleman sayýsý
    
    printf("\n Array before (heap) sort : "); 
    printArray(numberArray, arraySize); 
  
    heapSort(numberArray, arraySize);
  
    printf("\n\n Array after (heap) sort  : "); 
    printArray(numberArray, arraySize); 
    printf("\n");
  }
