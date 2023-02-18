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
FILE *gecici; //dosya silmek için oluþturuldu.
FILE *gecici2; //dosya guncellemek icin olusturuldu.

void ekle(){	
	system("cls");
	printf ("Kayit Yapilacak Musterinin Bilgilerini Giriniz.\n\n");
	printf("Ýsim    :");	scanf(" %s",ad);
	printf("Soyisim :");	scanf(" %s",soyad);
	printf("Telefon :");	scanf(" %s",tel);
	printf("Adres   :");	scanf(" %s",adres);
	
	if ((dosya=fopen("muskayit.txt","a"))!=NULL  )
		fprintf(dosya, "%s\t%s\t%s\t%s\n",ad,soyad,tel,adres);
	
	printf("Kayit Ýþlemi Baþarýlý! Menüye Yönlendiriliyorsunuz...\n\n");
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
	
	if ((dosya=fopen("muskayit.txt","w"))!=NULL){ //silinmis olarak güncel halini eski dosyaya yazdýracagýz(gecici dosyadaki veriler sayesinde)
		
		if ((gecici2=fopen("guncelle.txt","r"))!=NULL){
			
			while(!feof(gecici2)){
				fscanf(gecici2,"%s\t%s\t%s\t%s\n",ad,soyad,tel,adres); //okuduk	
				//ama yazdýrmadan önce güncellemek istedigimiz dosyayý bulalým onu yenileyip oyle dosyaya aktaralým
				if(strcmp(ad,ptrIsim2)==0){
					printf("Güncellenecek Müþterinin Yeni Bilgilerini giriniz...\n\n");
					printf("Ýsim    :");	scanf(" %s",ad);
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
	printf ("Kayýtlý Müþterilerimiz\n");
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
	printf("Listeleme Ýþlemi Baþarýlý! Menüye Yönlendiriliyorsunuz...\n\n");
	fclose(dosya);

}


void ara(){
		system("cls");
		char isim[20];
		int sonuc =0;
		printf("Aradýðýnýz Müþterinin Ýsmini Giriniz!\n\n");
		printf ("Ýsim:"); 	scanf("%s",isim);
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
		printf("%s Ýsimli Müþteri Yoktur!!! Menüye Yönlendiriliyorsunuz...\n\n",isim);
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

	if ((dosya=fopen("muskayit.txt","w"))!=NULL){ //silinmis olarak güncel halini eski dosyaya yazdýracagýz(gecici dosyadaki veriler sayesinde)
		
		if ((gecici=fopen("yedekle.txt","r"))!=NULL){
			
			while(!feof(gecici)){
				fscanf(gecici,"%s\t%s\t%s\t%s\n",ad,soyad,tel,adres); //okuduk	
				//ama yazdýrmadan önce silmek istedigimiz dosyayý bulalým onu yazdýrmadan dosyaya aktaralým
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
	printf("Silmek Ýstediðiniz Müþterinin Ýsmi:"); scanf("%s",isim);
	
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
		printf("%s Ýsimli Müþteri Yoktur!!! Menüye Yönlendiriliyorsunuz...\n\n",isim);
	else{
		printf("Silme Ýþlemi Baþarýlý! Menüye Yönlendiriliyorsunuz...\n\n");
	}
	
}

int main (){
	
	setlocale(LC_ALL,"Turkish");
	printf("|-----------------------------|\n");
	printf("| MÜÞTERÝ VERÝ TABANI PROJESÝ |\n|\t\t\t      |\n");	
	int secim=-1;
	while (secim !=0)
	{
		printf("| <<<----//MENU\\\\---->>>      |\n|\t\t\t      |\n");
		printf("| 1-Müþteri Kayýt Yap\t      |\n");
		printf("| 2-Müþteri Güncelle\t      |\n");
		printf("| 3-Müþterileri Listele\t      |\n");
		printf("| 4-Müþteri Ara\t\t      |\n");
		printf("| 5-Müþteri Silme Ýþlemi      |\n");
		printf("| 0-Çýkýþ\t\t      |\n|\t\t\t      |\n| Ýletiþim:(+90)551 139 5140  |\n| turanfurkan@gmail.com       |\n");
		printf("|_____________________________|\n");
		printf("  Seçiminiz:" ); scanf("%d", &secim );  
	
		if(secim==1)
			ekle();
		
		else if(secim==2){
			char isim2[20];
				printf("\nGüncellenecek Müþterinin Ýsmini Giriniz\n\n");
				printf("Ýsim:"); scanf("%s",isim2);
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
