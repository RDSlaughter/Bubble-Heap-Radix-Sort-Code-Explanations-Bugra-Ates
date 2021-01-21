
// Buðra ATEÞ 
// Radix Sort

#include <stdio.h>

int getMax(int arr[], int n) // elemanlarýmýzýn icinden maksimum olaný bulan fonksiyon
{
    int mx = arr[0];
    
    for (int i = 1; i < n; i++) if (arr[i] > mx)
	{
        mx = arr[i];
    }
    
    return mx;
}
 
void countSort(int numberArray[], int arraySize, int exp) // radix sort icin countSort methodu
{
    int output[arraySize]; // arrayimize sýralý dizini aktarmak için kullanacaðýmýz output arrayi
    int i, count[10] = {0}; // 0,1,2...9 rakam sayýsý kadar olan 10 elemanlý count arrayi
 
    for (i = 0; i < arraySize; i++) // birler,onlar vs. max sayýmýza göre iþlemler yapan ve 
                                    // input arrayimizin içinde olan numaralarýn hanelerini kullanarak
                                    // count arrayinin ayný numaraya sahip indexine +1 ekler
    {
        count[ (numberArray[i]/exp)%10 ]++;
    }
 
    for (i = 1; i < 10; i++)  // soldan saða doðru ikiþerli olarak soldakini saðdakinin üstüne ekleyip
                              // yeni sað eleman elde eder. Toplam 9 kere döner cünkü 2 serli gidiþ durumu
                              // 10 elemanlý bir arrayda soldan saða maksimum 9 kez olabilir
	{
	count[i] += count[i - 1]; 
    }
	
	for (i = arraySize - 1; i >= 0; i--) // arrayimizin i. elemanýný kullanarak o numaranýn aynýsý olan 
	                                     // count arrayinin indexinin içindeki elemaný alýr ve o elemaný da
	                                     // output arrayinin indexi için kullanýr. bu output arrayinin
	                                     // indexine de input arrayindeki i. index elemanýný koyar.
	                                     // 
    {
        output[count[ (numberArray[i]/exp)%10 ] - 1] = numberArray[i];
        count[ (numberArray[i]/exp)%10 ]--;
    }
	
    for (i = 0; i < arraySize; i++) 
	{
	numberArray[i] = output[i];  // yeni sýralamalarý input arrayimize aktararak günceller
	}
 } 
    
	void radixsort(int numberArray[], int arraySize) 
{ 
	int m = getMax(numberArray, arraySize);  // maksimum sayýyý alýp m'e atar.
	
	for (int exp = 1; m/exp > 0; exp *= 10) // maksimum sayýyý kullanýr ve exp'e baðlý 10'ar kat artarak devam 
	                                        // böylelikle maksimum sayýmýz 3 haneli ise 10'ar artýþta ilk olarak birler
	                                        // ardýndan onlar ve ardýndan da yüzler olarak 3 farklý sýralama uygular.
	{
    countSort(numberArray, arraySize, exp);
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
 
int main() // ana fonksiyon
{
    int numberArray[] = {5,9,3,4,6}; 
    int arraySize = sizeof(numberArray)/sizeof(numberArray[0]);  // eleman sayýsý
    
    printf("\n Array before (radix) sort : "); 
    printArray(numberArray, arraySize); 
    
    radixsort(numberArray, arraySize);
    
    printf("\n\n Array after (radix) sort  : "); 
    printArray(numberArray, arraySize); 
    printf("\n");
    
    return 0;
}
