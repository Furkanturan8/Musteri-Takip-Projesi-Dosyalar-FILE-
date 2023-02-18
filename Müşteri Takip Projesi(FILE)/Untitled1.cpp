#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

char ad[20];
char soyad[20];
char tel[20];
char adres[20];

FILE *dosya;
FILE *gecici; //dosya silmek i�in olu�turuldu.
FILE *gecici2; //dosya guncellemek icin olusturuldu.

void ekle(){	
	system("cls");
	printf ("Kayit Yapilacak Musterinin Bilgilerini Giriniz.\n\n");
	printf("�sim    :");	scanf(" %s",ad);
	printf("Soyisim :");	scanf(" %s",soyad);
	printf("Telefon :");	scanf(" %s",tel);
	printf("Adres   :");	scanf(" %s",adres);
	
	if ((dosya=fopen("muskayit.txt","a"))!=NULL  )
		fprintf(dosya, "%s\t%s\t%s\t%s\n",ad,soyad,tel,adres);
	
	printf("Kayit ��lemi Ba�ar�l�! Men�ye Y�nlendiriliyorsunuz...\n\n");
	fclose(dosya);
}

void veriguncelle(char *ptrIsim2){
	
	system("cls");
	
		if ((gecici2=fopen("guncelle.txt","w"))!=NULL){
		
		if ((dosya=fopen("muskayit.txt","r"))!=NULL){
			
			while(!feof(dosya)){
				fscanf(dosya,"%s\t%s\t%s\t%s\n",ad,soyad,tel,adres); //okuduk	
				fprintf(gecici2,"%s\t%s\t%s\t%s\n",ad,soyad,tel,adres); //yazdirdik	
			}					
		}
	} 
		
	remove("muskayit.txt");
	fclose(dosya);
	fclose(gecici2);
	
	if ((dosya=fopen("muskayit.txt","w"))!=NULL){ //silinmis olarak g�ncel halini eski dosyaya yazd�racag�z(gecici dosyadaki veriler sayesinde)
		
		if ((gecici2=fopen("guncelle.txt","r"))!=NULL){
			
			while(!feof(gecici2)){
				fscanf(gecici2,"%s\t%s\t%s\t%s\n",ad,soyad,tel,adres); //okuduk	
				//ama yazd�rmadan �nce g�ncellemek istedigimiz dosyay� bulal�m onu yenileyip oyle dosyaya aktaral�m
				if(strcmp(ad,ptrIsim2)==0){
					printf("G�ncellenecek M��terinin Yeni Bilgilerini giriniz...\n\n");
					printf("�sim    :");	scanf(" %s",ad);
					printf("Soyisim :");	scanf(" %s",soyad);
					printf("Telefon :");	scanf(" %s",tel);
					printf("Adres   :");	scanf(" %s",adres);
					fprintf(dosya,"%s\t%s\t%s\t%s\n",ad,soyad,tel,adres);
					continue;
				}
				
				fprintf(dosya,"%s\t%s\t%s\t%s\n",ad,soyad,tel,adres); //yazdirdik	
			}					
		}
	}
	remove("guncelle.txt");
	fclose(dosya);
	fclose(gecici2);
	
}

void listele(){
	
	system("cls");
	printf ("Kay�tl� M��terilerimiz\n");
	printf("--------------------------------------");
	printf("\nAD\tSOYAD\tTELEFON\t\tADRES\n");
	strcpy(ad,"");
	strcpy(soyad,"");
	strcpy(tel,"");
	strcpy(adres,"");
	
	if ((dosya=fopen("muskayit.txt","r")) !=NULL);{
			 
		while (! feof(dosya)){
			fscanf(dosya,"%s %s %s %s\n",ad, soyad ,tel, adres);
			printf("%s\t%s\t%s\t%s\t\n",ad, soyad, tel, adres);
		}
	
	printf("--------------------------------------\n");
	}
	printf("Listeleme ��lemi Ba�ar�l�! Men�ye Y�nlendiriliyorsunuz...\n\n");
	fclose(dosya);

}


void ara(){
		system("cls");
		char isim[20];
		int sonuc =0;
		printf("Arad���n�z M��terinin �smini Giriniz!\n\n");
		printf ("�sim:"); 	scanf("%s",isim);
	printf("\n----------------------------------\n");
	printf("\nAD\tSOYAD\tTELEFON\t\tADRES\n");
	
	if ((dosya=fopen("muskayit.txt","r"))!=NULL){
			
		while (!feof(dosya)){
			fscanf(dosya,"%s\t%s\t%s\t%s\n",ad, soyad ,tel, adres);				
			
			if(strcmp(ad,isim)==0){
				printf("%s\t%s\t%s\t%s\n",ad, soyad, tel, adres);
				fclose(dosya);
				sonuc=1;
				break;					
			}
			
		}
	printf("\n----------------------------------\n") ; 
	}

	fclose(dosya);
	if(sonuc==0)
		printf("%s �simli M��teri Yoktur!!! Men�ye Y�nlendiriliyorsunuz...\n\n",isim);
}

void kopyala(){
	
	if ((gecici=fopen("yedekle.txt","w"))!=NULL){
		
		if ((dosya=fopen("muskayit.txt","r"))!=NULL){
			
			while(!feof(dosya)){
				fscanf(dosya,"%s\t%s\t%s\t%s\n",ad,soyad,tel,adres); //okuduk	
				fprintf(gecici,"%s\t%s\t%s\t%s\n",ad,soyad,tel,adres); //yazdirdik	
			}					
		}
	}
		
	remove("muskayit.txt");
	fclose(dosya);
	fclose(gecici);
	
}

void yapistir(char *ptrIsim){ //isimi ptrIsim ile tutsun

	if ((dosya=fopen("muskayit.txt","w"))!=NULL){ //silinmis olarak g�ncel halini eski dosyaya yazd�racag�z(gecici dosyadaki veriler sayesinde)
		
		if ((gecici=fopen("yedekle.txt","r"))!=NULL){
			
			while(!feof(gecici)){
				fscanf(gecici,"%s\t%s\t%s\t%s\n",ad,soyad,tel,adres); //okuduk	
				//ama yazd�rmadan �nce silmek istedigimiz dosyay� bulal�m onu yazd�rmadan dosyaya aktaral�m
				if(strcmp(ad,ptrIsim)==0)
					continue;
				
				fprintf(dosya,"%s\t%s\t%s\t%s\n",ad,soyad,tel,adres); //yazdirdik	
			}					
		}
	}
	remove("yedekle.txt");
	fclose(dosya);
	fclose(gecici);
}


void sil(){
	
	system("cls");
	char isim[20];
	int sonuc=0;
	printf("Silmek �stedi�iniz M��terinin �smi:"); scanf("%s",isim);
	
	while(!feof(dosya)){
			
		fscanf(dosya,"%s\t%s\t%s\t%s\n",ad,soyad,tel,adres);
		if(strcmp(isim,ad)==0){
			fclose(dosya);
			kopyala();
			yapistir(isim);
			sonuc=1;
			break;
		}
	}
	fclose(dosya);
	if(sonuc==0)
		printf("%s �simli M��teri Yoktur!!! Men�ye Y�nlendiriliyorsunuz...\n\n",isim);
	else{
		printf("Silme ��lemi Ba�ar�l�! Men�ye Y�nlendiriliyorsunuz...\n\n");
	}
	
}

int main (){
	
	setlocale(LC_ALL,"Turkish");
	printf("|-----------------------------|\n");
	printf("| M��TER� VER� TABANI PROJES� |\n|\t\t\t      |\n");	
	int secim=-1;
	while (secim !=0)
	{
		printf("| <<<----//MENU\\\\---->>>      |\n|\t\t\t      |\n");
		printf("| 1-M��teri Kay�t Yap\t      |\n");
		printf("| 2-M��teri G�ncelle\t      |\n");
		printf("| 3-M��terileri Listele\t      |\n");
		printf("| 4-M��teri Ara\t\t      |\n");
		printf("| 5-M��teri Silme ��lemi      |\n");
		printf("| 0-��k��\t\t      |\n|\t\t\t      |\n| �leti�im:(+90)551 139 5140  |\n| turanfurkan@gmail.com       |\n");
		printf("|_____________________________|\n");
		printf("  Se�iminiz:" ); scanf("%d", &secim );  
	
		if(secim==1)
			ekle();
		
		else if(secim==2){
			char isim2[20];
				printf("\nG�ncellenecek M��terinin �smini Giriniz\n\n");
				printf("�sim:"); scanf("%s",isim2);
			veriguncelle(isim2);
		}
				
		else if(secim==3)
			listele();
		
		else if(secim==4)
			ara();
		
		else if(secim==5)
			sil();
		
		else if(secim==0)
			exit(0);
		
		else 
		printf("hatali secim!!!");
		
	}

	return 0;
}
