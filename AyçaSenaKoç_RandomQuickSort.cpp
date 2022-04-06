// Ayça Sena Koç - 2004040029
//Lomuto'nun partition şeması kullanılarak QuickSort
#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;


//Bu fonksiyon rastgele bir şekilde array içinden bir pivot seçer.
//Pivotu array'in en sonuna gönderir.
//Daha sonra seçtiği pivotu doğru konumuna (solundaki sayılar pivottan küçük, sağındakiler pivottan büyük) getirir.
int partition(int arr[], int low, int high)
{
	// pivot
	int pivot = arr[high]; 

	
	int i = (low - 1);//i=-1
	
	//ARRAY: 10 7 8 9 1 5 
	for (int j = low; j <= high - 1; j++)
	{
		// j indexindeki eleman pivottan küçük veya eşitse
		if (arr[j] <= pivot) {

			// i'yi arttır
			// ve i indexindeki sayı ile j indexindeki sayının yerini değiştir.
			i++;
			swap(arr[i], arr[j]);
		}
	}
	//for döngüsü bittikten sonra i'nin bir fazlası indexteki sayı ile pivotun yeri
	//yeri değiştirilir ve pivot doğru konumuna gelmiş olur.
	swap(arr[i + 1], arr[high]);
	return (i + 1);//pivotun doğru konumu
}


//Rastgele pivot seçilir. Array'in en sağındaki sayı ile pivotun yeri değiştirilir.
//Partition fonksiyonu çağırılır.
int partition_r(int arr[], int low, int high)//low=0 high=5
{
	
	srand(time(NULL));
	int random = low + rand() % (high - low);//0 ve 5 arasinda random index secilir

	swap(arr[random], arr[high]);//random secilen sayi yani pivot arrayde en sagdakiyle yer degistirir

	return partition(arr, low, high);//10 7 5 9 1 8
}

/*
arr[] --> düzensiz Array,
low --> başlangıç index'i,
high --> son index */
void quickSort(int arr[], int low, int high)
{
	if (low < high) {//low=0 high=5

		// pi = partitioning index
		//pi: doğru konuma gelmiş pivotun konumu
		
		int pi = partition_r(arr, low, high);
		
		quickSort(arr, low, pi - 1); //doğru konumdaki pivotun sol kısmında kalan sayılar için quick sort
		quickSort(arr, pi + 1, high);//doğru konumdaki pivotun sağ kısmında kalan sayılar için quick sort
	}
}

/* Yazdırma fonksiyonu */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout<<arr[i]<<" ";
}


int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]); //n: array size
	
	quickSort(arr, 0, n - 1);
	printf("Sorted array: \n");
	printArray(arr, n);
	
	return 0;
}
