#include <stdio.h>
#include <math.h>
void giris(int no[], int notu[], int N);
float ortalama(int notu[], int N);
void goruntule(int no[], int notu[], int N);
float otele(int N, int notu[]);
void BNotuSýrala(int N,int no[],int notu[]);
void OgrNoSýrala(int N, int no[], int notu[]);
float standartsapma(int N, int notu[]);
void dikeyHistogram(int N, int no[], int notu[]);
void yatayHistogram(int N, int no[], int notu[]);

int notu[];
void main()
{
	int otelenmistplm=0;
	int otlnnOgr=0;

	int N;
	int OgrNo[BUFSIZ], BNotu[BUFSIZ];
	float ort;
	printf("Ogrenci sayisini giriniz: ");
	scanf("%d", &N);
	giris(OgrNo, BNotu, N);
	goruntule(OgrNo, BNotu, N);
	ort = ortalama(BNotu, N);
	printf("Not ortalamasi: %5.2f\n", ort);
	otele(N,BNotu);
	goruntule(OgrNo, BNotu, N);
	BNotuSýrala(N, OgrNo, BNotu);
	OgrNoSýrala(N, OgrNo, BNotu);
	standartsapma(N, BNotu);
	dikeyHistogram(N, OgrNo, BNotu);
	yatayHistogram(N, OgrNo, BNotu);
}
void giris(int no[], int notu[], int N)
{
	int i;
	for (i = 0; i<N; i++)
	{
		printf("Ogrenci no gir: ");
		scanf("%d", &no[i]);
		printf("%d numarali ogrencinin basari notunu gir : ", no[i]);
		scanf("%d", &notu[i]);
	}
}
void goruntule(int no[], int notu[], int N)
{
	printf("Ogrenci#\tNotu\n");
	for (int i = 0; i<N; i++)
		printf("%8d\t%3d\n", no[i], notu[i]);
}
float ortalama(int notu[], int N)
{
	float t;
	int i;
	t = 0;
	for (i = 0; i<N; i++)
		t = t + notu[i];
	float ort = t / N;
	return ort;
}
float otele(int N, int notu[])
{
	printf("\noteleme\n");
	float m=0;
	int n=0,fark;
	for (int i = 0; i <N ; i++)
	{
		if (notu[i]>=20)
		{
			m = m + notu[i];
			n++;
		}

	}
	float ortlma = m / n;
	if (ortlma<50)
	{
		fark = 50 - ortlma;
		for (int k = 0; k < N; k++)
		{
			if (notu[k] >= 30)
			{
				notu[k] = notu[k] + fark;

			}
		}
	}
	


	return ortlma;

}
 void BNotuSýrala(int N,int no[],int notu[])
{


	 int tmp;
	
	 for (int i = 0; i < N ; i++)
	 {
		 for ( int j = i+1; j < N; j++)
		 {
			 if (notu[i]>notu[j])
			 {
				 tmp = notu[i];
				 notu[i] = notu[j];
				 notu[j] = tmp;

				 tmp = no[i];
				 no[i] = no[j];
				 no[j] = tmp;

			 }
		 }
		
	 }
	 printf("\nbasari notu siralama\n");
	 printf("Ogrenci#\tNotu\n");
	 for (int i = 0; i<N; i++)
		 printf("%8d\t%3d\n", no[i], notu[i]);

}
 void OgrNoSýrala(int N, int no[], int notu[])
 {

	 int tmp;

	 for (int i = 0; i < N; i++)
	 {
		 for (int j = i+1; j < N; j++)
		 {
			 if (no[i]>no[j])
			 {
				 tmp = no[i];
				 no[i] = no[j];
				 no[j] = tmp;

				 tmp = notu[i];
				 notu[i] = notu[j];
				 notu[j] = tmp;

			 }
		 }

	 }
	 printf("\nogrenci  no siralama\n");
	 printf("Ogrenci#\tNotu\n");
	 for (int i = 0; i<N; i++)
		 printf("%8d\t%3d\n", no[i], notu[i]);


 }
 float standartsapma(int N,int notu[])
 {

	 int i, t=0;
	 for (i = 0; i<N; i++)
		 t = t + notu[i];
	 float ort = t / N;

	 float standartsapma;
	 int a;
	 int toplam = 0;
	 for (int i = 0; i < N; i++)
	 {
		 a = ort - notu[i];
		 toplam = toplam + (a*a);
	 }
	 standartsapma = sqrt(toplam / N);
	 printf("standar sapma   ===    %5.2f", standartsapma);
	 return standartsapma; 

 }
 void yatayHistogram(int N, int no[], int notu[])
 {
	 char harfler[] = {'A','A','B','B','C','C','D','D','E','F'};
	 int sayilar[] = { 1,2,1,2,1,2,1,2,' ',' ' };
	 int harf[10] = { 0,0,0,0,0,0,0,0,0,0 };
	 for (int k = 0; k < N; k++) {
		 if (notu[k] >= 90)
		 {
			 harf[0]++;
		 }
		 else if (notu[k] >= 80 && notu[k] <= 89)
		 {
			 harf[1]++;
		 }
		 else if (notu[k] >= 75 && notu[k] <= 79)
		 {
			 harf[2]++;
		 }
		 else if (notu[k] >= 70 && notu[k] <= 74)
		 {
			 harf[3]++;
		 }
		 else if (notu[k] >= 65 && notu[k] <= 69)
		 {
			 harf[4]++;
		 }
		 else if (notu[k] >= 60 && notu[k] <= 64)
		 {
			 harf[5]++;
		 }
		 else if (notu[k] >= 55 && notu[k] <= 59)
		 {
			 harf[6]++;
		 }
		 else if (notu[k] >= 50 && notu[k] <= 54)
		 {
			 harf[7]++;
		 }
		 else if (notu[k] >= 40 && notu[k] <= 49)
		 {
			 harf[8]++;
		 }
		 else if (notu[k] <= 39)
		 {
			 harf[9]++;
		 }
	 }

	 for (int i = 0; i < 10; i++)
	 {
		 printf("\n %c%3d |", harfler[i],sayilar[i]);
		 
		 for (int j = 0; j <harf[i]; j++)
		 {
			 
				 printf(" *  ");
	
		 }
		
	 }
	 
	 






 }
 void dikeyHistogram(int N, int no[], int notu[])
 {
	 int harf[10] = { 0,0,0,0,0,0,0,0,0,0};
	 for (int k = 0; k < N; k++) {
		 if (notu[k]>=90)
		 {
			 harf[0]++;
		 }
		 else if (notu[k]>=80 && notu[k]<=89)
		 {
			 harf[1]++;
		 }
		 else if (notu[k] >= 75 && notu[k] <= 79)
		 {
			 harf[2]++;
		 }
		 else if (notu[k] >= 70 && notu[k] <= 74)
		 {
			 harf[3]++;
		 }
		 else if (notu[k] >= 65 && notu[k] <= 69)
		 {
			 harf[4]++;
		 }
		 else if (notu[k] >= 60 && notu[k] <= 64)
		 {
			 harf[5]++;
		 }
		 else if (notu[k] >= 55 && notu[k] <= 59)
		 {
			 harf[6]++;
		 }
		 else if (notu[k] >= 50 && notu[k] <= 54)
		 {
			 harf[7]++;
		 }
		 else if (notu[k] >= 40 && notu[k] <= 49)
		 {
			 harf[8]++;
		 }
		 else if(notu[k]<=39)
		 {
			 harf[9]++;
		 }
	 }


	 printf("\n");
	 printf("\n");
	 printf("Basari notlari dagilim araliklari(dikey histogram)");
	 for (int i = N; i > 0; i--)
	 {
		 printf("\n%3d  |", i);

		 for (int j = 0; j < 10 ; j++)
		 {
			 if (harf[j]>=i)
			 {
				 printf(" **  ");
			 }
			 else
			 {
				 printf("     ");
			 }

		 }
		 printf("|");
	 }
	 printf("\n-----+----+----+----+----+----+----+----+----+----+-----+      ");
	 printf("\n       A1   A2   B1   B2   C1   C2   D1   D2   E    F   |\n\n");




 }