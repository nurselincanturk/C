#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<conio.h>
#include <windows.h>







int i, sayi1, sayi2, sayi3;
int toplam;
int sayac = 0;
int buyuk = 0;
int kucuk = 0;
int orta = 0;
int krl3;
int sonuc;




void pulCek()
{


	
	
	sayi1 = rand() % 99 + 1;
	
	sayi2 = rand() % 99 + 1;
	sayi2 = (sayi2 == sayi1) ? rand() % 99 + 1 : sayi2;
	
	sayi3 = rand() % 99 + 1;
	sayi3 = (sayi3 == sayi1 || sayi3==sayi2) ? rand() % 99 + 1 : sayi3;
	printf("Pul  1 = %d\nPul  2 = %d\nPul  3 = %d\n", sayi1, sayi2, sayi3);
	
}


void topla()
{
	toplam = sayi1 + sayi2 + sayi3;
	
}

int asalSayi()
{

	for ( i = 2; i < toplam; i++)
	{
		if (toplam % i == 0)
		{
			sayac++;
		}
		
	}
	if (sayac == 0)
	{
		sonuc = true;
	}
	else
	{
		sonuc = false;
	}
	
	

	return 0;

}
void buyukKucuk()
{


	
	buyuk = (sayi1 > sayi2) ? sayi1 : sayi2;
	kucuk = (sayi3 > buyuk) ? sayi3 : buyuk;
	kucuk = (sayi1 < sayi2) ? sayi1 : sayi2;
	kucuk = (sayi3 < kucuk) ? sayi3 : kucuk;
	orta = (sayi1<buyuk&&sayi1>kucuk) ? sayi1 : orta;
	orta = (sayi2<buyuk&&sayi2>kucuk) ? sayi2 : orta;
	orta = (sayi3<buyuk&&sayi3>kucuk) ? sayi3 : orta;



	if ((buyuk-kucuk)>orta)
	{
		krl3 = true;
	}
	else
	{
		krl3 = false;
	}


}



int main()
{
	srand(time(NULL));
	char harf;
	printf("Oyuna baslamak icin herhangi bir tusa basiniz.\n");
	_getch();
	do
	{

	sayac = 0;
	pulCek();
	topla();
	asalSayi();
	buyukKucuk();

	if (toplam<150)
	{
		
		printf("Tebrikler kazandiniz. (1.kural)");
	}
	else if (sonuc == 1)
	{
		printf("Tebrikler kazandiniz. (2.kural)");
	}
	else if (krl3 == true)
	{
		printf("Tebrikler kazandiniz. (3.kural)");

	}
	else
	{
		printf("Malesef kaybettiniz....");
	}
	

	printf("\n\nDevam etmek icin [e/E]  \n\n");
	harf = _getch();

	} while (harf ='e' );


















}