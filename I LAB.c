#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int a = 0, b, d,hapus, menu = 0, pilih, i = 1;
	char c['0'][30], search[30], nama['0'][30], nim['0'][30], kelas['0'][30], dosen['0'][30];

	printf("===PILIH MENU===");
	printf("\n1.INPUT DATA.\n");
	printf("2. SHOW DATA.\n");
	printf("3. UPDATE DATA.\n");
	printf("4. DELETE DATA.\n");
	printf("5. SEARCH DATA.\n");
	printf("6. EXIT DATA.\n");

	for(i = 0; 1 <= 1; i++)
	{
		printf("Masukkan Pilihan : ");
		scanf("%d", &pilih);
		printf("\n");

		switch(pilih)
		{
		case 1:
			system("cls");
			printf("==creat data==\n");
			masukan_nim:
			printf("input nim praktikum\t\t: ");
			scanf("%s", &nim[a]);
			if(strlen(nim[a]) > 10)
			{
				printf("nim yang anda masukkan lebih dari 10\n");
				goto masukan_nim;
			}
			if(a != 0)
			{
				for (i = 0; i < a; i++)//for looping untuk mencari mim yang sama sebanyak yang akan di masukkan
				{
					if(strcmp(nim[a], nim[i]) == 0)
					{
						printf("NIM Yang anda Masukan sudah ke input\n");
						goto masukan_nim;
					}
				}
			}
			printf("input nama praktikum\t\t: ");
			scanf(" %[^\n]s", &nama[a]);
			printf("input kelas pemrogaman dasar\t: ");
			scanf("%s", &kelas[a]);
			printf("input nama dosen pemgampu\t: ");
			scanf(" %[^\n]s", &dosen[a]);
			printf("=====================\n");
			printf("\nmenambah data\n");
			printf("\n=====================\n");
			a = a + 1; //untuk menandai variable
			break;

		case 2:
			system("cls");
			printf("==show data==\n");

			if(a < 1) //jika inputan tidak ada
			{
				printf("anda belum input data\n");
			}
			else
			{
				b = 0;
				while(b < a)
				{
					printf("%d. Nim praktikan			: %s\n", b + 1, nim[b]);
					printf("   Nama praktikan			: %s\n", nama[b]);
					printf("   Kelas Pemrogaman Dasar\t	: %s\n", kelas[b]);
					printf("   Dosen Pengampu			: %s\n", dosen[b]);
					printf("----------\n");
					b++;
				}
			}
			break;

		case 3:
			printf("==update data==\n");
			printf("masukkan Nim yang ingin di update : ");
			scanf(" %s", &c); //inputan nim
			b = 0;
			d = 0;
			while(b <= a && d == 0)
			{
				if(strcmp(c, nim[b]) == 0) //membandingkan dengan inputan fariable awal
				{
					d++;
				}
				b++;
			}
			if(d < 1)
			{
				printf("data yang akan anda update mungkin tidak ada");
			}
			else
			{
				b--;
				printf("Nim			: %s\n", nim[b]);
				printf("nama		: %s\n", nama[b]);
				printf("kelas		: %s\n", kelas[b]);
				printf("dosen		: %s\n", dosen[b]);
				printf("----------\n");
				printf("masukkan nim baru      : ");
				scanf("%s", nim[b]);
				printf("masukkan nama baru     : ");
				scanf(" %[^\n]s", nama[b]);
				printf("masukkan kelas baru    : ");
				scanf("%s", kelas[b]);
				printf("masukkan dosen baru    : ");
				scanf(" %[^\n]s", dosen[b]);
			}
			break;

		case 4:
			printf("masukkan NIM yang ingin di delete : ");
			scanf("%s", c);//masuk nim
			b = 0;//check dari nol
			d = 0;

			while(b < a && d == 0)//check inputan 
			{
				if(strcmp(c, nim[b]) == 0)//membandingkan inputan dng di data 
				{
					d++;
					hapus=b;
				}
				b++;
			}

			if(d < 1)//membandingkan jika nim sama
			{
				printf("data yang akan anda delete mungkin tidak ada\n");
			}
			else
			{
				printf("data %s berhaasil di delete\n", nama[b-1]);//kembali satu input supaya inputan yang terdapat inputan
																	//yang pertama
				while(hapus < a)
				{
					strcpy(nim[hapus], nim[hapus + 1]);//jumlah yang di input di copy ke indeks ke 0 untuk delete data nya
					strcpy(nama[hapus], nama[hapus + 1]);//atau membalikkan ke semula
					strcpy(kelas[hapus], kelas[hapus + 1]);
					strcpy(dosen[hapus], dosen[hapus + 1]);
					hapus++;
				}
				a--;
			}
			break;

		case 5:
			system("cls");
			printf(" === Search Data ===\n\n");
			printf("\n Masukkan NIM Praktikan : ");
			scanf("%s", &search);//input nim
			b = 0;
			d = 0;
			while(b <= a && d == 0)
			{
				if(strcmp(search, nim[b]) == 0)//membandingkan inputan untuk mencari nim
				{
					d++;
				}
				b++;
			}
			//tidak ada data
			if(d < 1)
			{
				printf(" Data Tidak Ditemukan\n");
			}
			else
			{
				b--;
				printf("\n NIM                 :%s", nim[b]);
				printf("\n Nama Praktikan      :%s ", nama[b]);
				printf("\n kelas			   :%s ", kelas[b]);
				printf("\n Dosen Pengampu	   :%s ", dosen[b]);

				printf("\n-----------------------------------------------");
				printf("\n\n  Data Berhasil Ditemukan\n");
				printf("\n\n-----------------------------------------------");
			}
			break;

		case 6:
			printf("EXIT.......\n");
			return 0;
		}
	}
	return 0;
}
