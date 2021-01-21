
// Buðra ATEÞ 
// Bubble Sort

#include <stdio.h> 
  
  // elemanlarýn iþaret ettiði adreslerin yer deðiþtirilmesini saðlayan swap fonksiyonu
void swapNumberPointers(int *firstNumPointer, int *secondNumPointer) 
{ 
    int temporaryNumPointer = *firstNumPointer; 
    *firstNumPointer = *secondNumPointer; 
    *secondNumPointer = temporaryNumPointer; 
} 
  // bubble sort fonksiyonu
void bubbleSort(int numberArray[], int arraySize) 
{ 
   int i;
   int j;
   
   for (i = 0; i < arraySize-1; i++) // array boyutundan 1 eksik dönmeli çünkü ikiþerli ilerlemede bu gerekiyor
   {
       for (j = 0; j < arraySize-i-1; j++)  // her üst döngü sonrasý i çýkarýlmalý çünkü döngü sonunda bir numaranýn iþi bitiriliyor
                                            // kalanlar ile iþleme devam ediliyor
       {
           if (numberArray[j] > numberArray[j+1]) // bir önceki eleman sonrasýndaki elemandan büyük ise
           {
              swapNumberPointers(&numberArray[j], &numberArray[j+1]); // swap iþlemini yap
              printf("\n Pointers of numbers changed : %p <=> %p",&numberArray[j], &numberArray[j+1]); // pointer deðiþikliklerini bastýr
           }
       }
   }
}
  
void printArray(int numberArray[], int arraySize) // array elemanlarýný bastýran fonksiyon
{     
    int i; 
    
    for (i=0; i < arraySize; i++)
	{
        printf("%d ", numberArray[i]); 
    }
} 
void printNumberPointers(int numberArray[], int arraySize) // elemanlarýn bellek adreslerini bastýran fonksiyon
{     
    int i; 
    
    for (i=0; i < arraySize; i++)
	{
        printf("\n %d. Index | Number : %d | Pointer = %p ",i,numberArray[i], &numberArray[i]); 
    }
} 

int main() // ana fonksiyon
{ 
    int numberArray[] = {5,9,3,4,6}; 
    int arraySize = sizeof(numberArray)/sizeof(numberArray[0]); // eleman sayýsý
    
    printNumberPointers(numberArray,arraySize);
    
    printf("\n\n Array before (bubble) sort : "); 
    printArray(numberArray, arraySize); 
    printf("\n");
    
    bubbleSort(numberArray, arraySize); 
    
    printf("\n\n Array after (bubble) sort  : "); 
    printArray(numberArray, arraySize); 
    printf("\n");
    
    return 0; 
} 
