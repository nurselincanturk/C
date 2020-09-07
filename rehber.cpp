
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <io.h>
#include<fileapi.h>
#include<errors.h>

struct kisi
{
	int kayitno ;
	char ad[40];
	char soyad[20];
	char evTel[12];
	char cepTel[11];
	char isTel[11];
	char eposta[100];
	struct 
	{
		int yil;
		int ay;
		int gun;
	}dGunu;
	struct 
	{
		char mahalle[20];
		char sokak[20];
		char il[20];
		char ilce[20];
	}adres;
};
struct kisi kayit;
int kisiSayi;
void sil();
void arama();
void goruntule();
void guncelle();
void menu();
void kisiEkle();
void rmve();
int main()
{
	
	menu();
	




}

void menu()
{
	
	int a;
	printf("   #MENU#\n");
	printf("______________\n");
	printf("(1)-Kisi ekle\n(2)-Goruntule\n(3)-Guncelle\n(4)-Sil\n(5)-Arama\nCikmak icin herhangi bir tusa basiniz.");
	printf("Yapmak istediginiz islemi seciniz.");
	scanf("%d",&a);
	while (1)
	{
		if (a == 1)
		{
			system("CLS");
			kisiEkle();
			

		}
		else if (a == 2)
		{
			system("CLS");
			goruntule();
			menu();
		}
		else if (a == 3)
		{
			system("CLS");
			goruntule();
			guncelle();
		}
		else if (a == 4)
		{
			system("CLS");
			goruntule();
			sil();
			
	
		
		}
		else if (a==5)
		{
			system("CLS");
			arama();
		}
		else
		{
			

			
			break;
		}
	}
	


}


void kisiEkle()
{
	FILE *dosya;
	



	if ((dosya = fopen("kisiler.txt", "a+")) == NULL)
	{
		printf("dosya bulunamadi.");
	}
	else
	{
		int devam;
		do {


			printf("\nad :");
			scanf("%s", &kayit.ad);
			printf("\nsoyad :");
			scanf("%s", &kayit.soyad);
			printf("\nev telefonu :");
			scanf("%s", &kayit.evTel);
			printf("\ncep telefonu :");
			scanf("%s", &kayit.cepTel);
			printf("\nis telefonu :");
			scanf("%s", &kayit.isTel);
			printf("\neposta :");
			scanf("%s", &kayit.eposta);
			printf("\ndoðum tarihi (gun ay yil) :");
			scanf("%d", &kayit.dGunu.gun);
			scanf("%d", &kayit.dGunu.ay);
			scanf("%d", &kayit.dGunu.yil);
			printf("\nil :");
			scanf("%s", &kayit.adres.il);
			printf("\nilce :");
			scanf("%s", &kayit.adres.ilce);
			printf("\nmahalle :");
			scanf("%s", &kayit.adres.mahalle);
			printf("\nsokak :");
			scanf("%s", &kayit.adres.sokak);

			printf("\nYeni kayit eklemek istiyorsaniz 1'e basin.\n");
			scanf("%d", &devam);
			
					
					fprintf(dosya, "%21s %21s %12s %12s %12s %21s %d %d %d %21s %21s %21s %21s", kayit.ad, kayit.soyad, kayit.evTel, kayit.cepTel, kayit.isTel, kayit.eposta, kayit.dGunu.gun, kayit.dGunu.ay, kayit.dGunu.yil, kayit.adres.il, kayit.adres.ilce, kayit.adres.mahalle, kayit.adres.sokak);
					fprintf(dosya, "\n");
			

		} while (devam == 1);
		fclose(dosya);
		menu();
	}
}
void goruntule()
{
	FILE *dosya;
	unsigned int number_of_lines = 0;
	FILE *infile = fopen("kisiler.txt", "r");
	int ch;

	
	if ((dosya = fopen("kisiler.txt", "r")) == NULL)
	{
		rewind(dosya);
		printf("bulunamadi");
	}
	else
	{
		rewind(dosya);
		printf("no   \tAD\t          SOYAD\t       EV TEL       \tCEP TEL\t\tIS TEL\t\t\tEPOSTA\t\t\t DOGUM TARIHI\t\t     IL\t          ILCE\t\t MAHALLE\t    SOKAK");
		printf("\n============================================================================================================================================================================================================");
		while (!feof(dosya)) {
			
			if ('\n' == (ch = getc(infile))) {

				number_of_lines++;

				fscanf(dosya, "%s %s %s %s %s %s %d %d %d %s %s %s %s ", &kayit.ad, &kayit.soyad, &kayit.evTel, &kayit.cepTel, &kayit.isTel, &kayit.eposta,
					&kayit.dGunu.gun, &kayit.dGunu.ay, &kayit.dGunu.yil,
					&kayit.adres.il, &kayit.adres.ilce, &kayit.adres.mahalle, &kayit.adres.sokak);


				//printf("%u\n", number_of_lines);


				printf("\n%d\t%8s\t%8s\t%8s\t%8s\t%8s\t%25s\t%3d/%3d/%3d\t\t%8s\t%8s\t%8s\t%8s", number_of_lines, kayit.ad, kayit.soyad, kayit.evTel, kayit.cepTel, kayit.isTel, kayit.eposta,
					kayit.dGunu.gun, kayit.dGunu.ay, kayit.dGunu.yil,
					kayit.adres.il, kayit.adres.ilce, kayit.adres.mahalle, kayit.adres.sokak);
				printf("\n");

			}
			
		}

		fclose(dosya);
		//fclose(infile);
		printf("\n");
		printf("\n");
		//menu(); 
	




	}
}
void sil()
{
	
	FILE *dosya, *dosya2;
	
	char a;
	char ch;
	int i=1,silinecek, gecici = 1;
	



		dosya = fopen("kisiler.txt", "r");

		printf(" \n silinecek satir:");
		scanf("%d", &silinecek);
		printf("Silmek istediginize emin misiniz\n(E)VET\t(H)AYIR\n");
		scanf("%s",&a);
		if (a=='e')
		{
			dosya2 = fopen("kisiler1.txt", "w");
			ch = 'A';
			while (ch != EOF)
			{
				ch = getc(dosya);

				if (gecici != silinecek)
				{

					putc(ch, dosya2);
				}
				if (ch == '\n')
				{
					gecici++;
				}

			}	fclose(dosya);
			fclose(dosya2);
			printf("\n");

			rmve();
			menu();

		}
		else
		{
			fclose(dosya);
			menu();
		}
		
		

	
	
	
}

void rmve()
{
	remove("kisiler.txt");
	FILE *dosya, *dosya2;
	dosya = fopen("kisiler1.txt", "r");
	int ch = 'A';
	int gecici=1;
	while (ch != EOF)
	{
		ch = getc(dosya);

		if (ch == '\n')
		{
			gecici++;
		}

	}
	

	rewind(dosya);
	dosya2 = fopen("kisiler.txt", "w");
	int i = 1;
	printf("\n");
	while (i<gecici)
	{
		fscanf(dosya, "%s %s %s %s %s %s %d %d %d %s %s %s %s ", &kayit.ad, &kayit.soyad, &kayit.evTel, &kayit.cepTel, &kayit.isTel, &kayit.eposta,
			&kayit.dGunu.gun, &kayit.dGunu.ay, &kayit.dGunu.yil,
			&kayit.adres.il, &kayit.adres.ilce, &kayit.adres.mahalle, &kayit.adres.sokak);

		
		fprintf(dosya2, "%21s %21s %12s %12s %12s %21s %d %d %d %21s %21s %21s %21s", kayit.ad, kayit.soyad, kayit.evTel, kayit.cepTel, kayit.isTel, kayit.eposta, kayit.dGunu.gun, kayit.dGunu.ay, kayit.dGunu.yil, kayit.adres.il, kayit.adres.ilce, kayit.adres.mahalle, kayit.adres.sokak);
		fprintf(dosya2, "\n");
			

		i++;
	}
	
		

	

	fclose(dosya);
	fclose(dosya2);
	

}


void guncelle() {


	FILE *dosya, *dosya2;


	char ch;
	int i = 1, silinecek, gecici = 1;




	dosya = fopen("kisiler.txt", "r");

	printf(" \n Guncellenecek kayit no:");
	scanf("%d", &silinecek);

	dosya2 = fopen("kisiler1.txt", "w");
	ch = 'A';
	while (ch != EOF)
	{
		ch = getc(dosya);

		if (gecici != silinecek)
		{

			putc(ch, dosya2);
		}
		if (ch == '\n')
		{
			gecici++;
		}

	}


	fclose(dosya);
	fclose(dosya2);
	printf("\n");

	rmve();

	printf("kisi bilgilerini yeniden giriniz.");





	(dosya = fopen("kisiler.txt", "a+"));

	int devam;


	printf("\nad :");
	scanf("%s", &kayit.ad);
	printf("\nsoyad :");
	scanf("%s", &kayit.soyad);
	printf("\nev telefonu :");
	scanf("%s", &kayit.evTel);
	printf("\ncep telefonu :");
	scanf("%s", &kayit.cepTel);
	printf("\nis telefonu :");
	scanf("%s", &kayit.isTel);
	printf("\neposta :");
	scanf("%s", &kayit.eposta);
	printf("\ndoðum tarihi (gun ay yil) :");
	scanf("%d", &kayit.dGunu.gun);
	scanf("%d", &kayit.dGunu.ay);
	scanf("%d", &kayit.dGunu.yil);
	printf("\nil :");
	scanf("%s", &kayit.adres.il);
	printf("\nilce :");
	scanf("%s", &kayit.adres.ilce);
	printf("\nmahalle :");
	scanf("%s", &kayit.adres.mahalle);
	printf("\nsokak :");
	scanf("%s", &kayit.adres.sokak);



	fprintf(dosya, "%21s %21s %12s %12s %12s %21s %d %d %d %21s %21s %21s %21s", kayit.ad, kayit.soyad, kayit.evTel, kayit.cepTel, kayit.isTel, kayit.eposta, kayit.dGunu.gun, kayit.dGunu.ay, kayit.dGunu.yil, kayit.adres.il, kayit.adres.ilce, kayit.adres.mahalle, kayit.adres.sokak);
	fprintf(dosya, "\n");



	fclose(dosya);
	menu();










}


void arama()
{

	FILE *dosya;
	char  bilgi[100];

	dosya = fopen("kisiler.txt", "r");
	printf("aramak istediginiz bilgiyi giriniz:");
	scanf("%s",&bilgi);

	printf("AD\t          SOYAD\t       EV TEL       \tCEP TEL\t\tIS TEL\t\t\tEPOSTA\t\t\t DOGUM TARIHI\t\t     IL\t          ILCE\t\t MAHALLE\t    SOKAK");
	printf("\n============================================================================================================================================================================================================");
	while (!feof(dosya))
	{
		fscanf(dosya, "%s %s %s %s %s %s %d %d %d %s %s %s %s ", &kayit.ad, &kayit.soyad, &kayit.evTel, &kayit.cepTel, &kayit.isTel, &kayit.eposta,
			&kayit.dGunu.gun, &kayit.dGunu.ay, &kayit.dGunu.yil,
			&kayit.adres.il, &kayit.adres.ilce, &kayit.adres.mahalle, &kayit.adres.sokak);

		if (!strcmp(kayit.ad, bilgi))
		{

			printf("\n%8s\t%8s\t%8s\t%8s\t%8s\t%25s\t%3d/%3d/%3d\t\t%8s\t%8s\t%8s\t%8s", kayit.ad, kayit.soyad, kayit.evTel, kayit.cepTel, kayit.isTel, kayit.eposta,
				kayit.dGunu.gun, kayit.dGunu.ay, kayit.dGunu.yil,
				kayit.adres.il, kayit.adres.ilce, kayit.adres.mahalle, kayit.adres.sokak);
			printf("\n");

		}

		else if (!strcmp(kayit.soyad, bilgi))
		{
			printf("\n%8s\t%8s\t%8s\t%8s\t%8s\t%25s\t%3d/%3d/%3d\t\t%8s\t%8s\t%8s\t%8s", kayit.ad, kayit.soyad, kayit.evTel, kayit.cepTel, kayit.isTel, kayit.eposta,
				kayit.dGunu.gun, kayit.dGunu.ay, kayit.dGunu.yil,
				kayit.adres.il, kayit.adres.ilce, kayit.adres.mahalle, kayit.adres.sokak);
			printf("\n");

		}
		else if (!strcmp(kayit.eposta, bilgi))
		{
			printf("\n%8s\t%8s\t%8s\t%8s\t%8s\t%25s\t%3d/%3d/%3d\t\t%8s\t%8s\t%8s\t%8s", kayit.ad, kayit.soyad, kayit.evTel, kayit.cepTel, kayit.isTel, kayit.eposta,
				kayit.dGunu.gun, kayit.dGunu.ay, kayit.dGunu.yil,
				kayit.adres.il, kayit.adres.ilce, kayit.adres.mahalle, kayit.adres.sokak);
			printf("\n");

		}
		else if (!strcmp(kayit.adres.il, bilgi))
		{
			printf("\n%8s\t%8s\t%8s\t%8s\t%8s\t%25s\t%3d/%3d/%3d\t\t%8s\t%8s\t%8s\t%8s", kayit.ad, kayit.soyad, kayit.evTel, kayit.cepTel, kayit.isTel, kayit.eposta,
				kayit.dGunu.gun, kayit.dGunu.ay, kayit.dGunu.yil,
				kayit.adres.il, kayit.adres.ilce, kayit.adres.mahalle, kayit.adres.sokak);
			printf("\n");

		}
		else if (!strcmp(kayit.adres.ilce, bilgi))
		{
			printf("\n%8s\t%8s\t%8s\t%8s\t%8s\t%25s\t%3d/%3d/%3d\t\t%8s\t%8s\t%8s\t%8s", kayit.ad, kayit.soyad, kayit.evTel, kayit.cepTel, kayit.isTel, kayit.eposta,
				kayit.dGunu.gun, kayit.dGunu.ay, kayit.dGunu.yil,
				kayit.adres.il, kayit.adres.ilce, kayit.adres.mahalle, kayit.adres.sokak);
			printf("\n");

		}

	}printf("\n\n");
	menu();
	fclose(dosya);
}
