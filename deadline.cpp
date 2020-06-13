#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
struct book_st{
	char ten[30];
	char theloai[30];
	int giatien;
};
void nhap(book_st *bookList){//nhap tung quyen sach
	for(int i=0;i<3;i++){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		printf("\nNhap quyen sach %d:\n",i+1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		printf("Ten: ");
		fflush(stdin);
		gets((bookList+i)->ten);
		printf("The loai: ");
		fflush(stdin);
		gets((bookList+i)->theloai);
		printf("Gia tien: ");
		scanf("%d",&(bookList+i)->giatien);
	}
}
void hienthi(book_st *bookList){//Sap xep sach va in ra man hinh
	int a;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("1. Sap xep tang dan theo the loai\n");
	printf("2. Sap xep giam dan theo the loai\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("Nhap lua chon cua ban ");
	scanf("%d",&a);
	switch(a){
		case 1:{//Sap xep sach A->Z
			for(int i=0;i<2;i++){
				for(int j=i+1;j<3;j++){
					if(strcmp((bookList+i)->theloai,(bookList+j)->theloai)>0){
						book_st t=*(bookList+i);
						*(bookList+i)=*(bookList+j);
						*(bookList+j)=t;
					}
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("%-4s%-30s%-30s%-8s\n","STT","Ten truyen","The loai","Gia tien");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			for(int i=0;i<3;i++){
				printf("%-4d%-30s%-30s%-8d\n",i+1,(bookList+i)->ten,(bookList+i)->theloai,(bookList+i)->giatien);
			}
			break;
		}
		case 2:{//sap xep sach Z->A
			for(int i=0;i<2;i++){
				for(int j=i+1;j<3;j++){
					if(strcmp((bookList+i)->theloai,(bookList+j)->theloai)<0){
						book_st t=*(bookList+i);
						*(bookList+i)=*(bookList+j);
						*(bookList+j)=t;
					}
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("%-4s%-30s%-30s%-8s\n","STT","Ten truyen","The loai","Gia tien");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
			for(int i=0;i<3;i++){
				printf("%-4d%-30s%-30s%-8d\n",i+1,(bookList+i)->ten,(bookList+i)->theloai,(bookList+i)->giatien);
			}
			break;
		}
	}
}
void thongke(book_st *bookList){//thong ke xem the loai X co bao nhieu cuon sach
	int d=1;
	char temp[30];
	for(int i=0;i<2;i++){
		for(int j=i+1;j<3;j++){
			if(stricmp((bookList+i)->theloai,(bookList+j)->theloai)==0){
				d=d+1;
				strcpy(temp,(bookList+i)->theloai);
			}
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	if(d==1){//khong co cuon sach nao co the loai giong nhau
		for(int i=0;i<3;i++){
			printf("%s co 1 quyen sach\n",(bookList+i)->theloai);
		}
	}
	if(d==2){//co 2 cuon sach co the loai giong nhau
		printf("%s co 2 quyen sach\n",temp);
		for(int i=0;i<3;i++){
			if(stricmp((bookList+i)->theloai,temp)!=0)
				printf("%s co 1 quyen sach\n",(bookList+i)->theloai);
		}
	}
	if(d==3){//co 3 cuon sach co the loai giong nhau
		printf("%s co %d quyen sach\n",bookList->theloai,d);
	}
}
void search(book_st *bookList){//Tim kiem sach theo the loai
	char theloai[30];
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf("Nhap the loai sach can tim ");
	fflush(stdin);
	gets(theloai);
	int d=-1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	for(int i=0;i<3;i++){
		if(stricmp(theloai,(bookList+i)->theloai)==0){
			printf("%-4s%-30s%-30s%-8s\n","STT","Ten truyen","The loai","Gia tien");//neu co the loai thi in ra
			break;
		}
	}
	for(int i=0;i<3;i++){
		if(stricmp(theloai,(bookList+i)->theloai)==0){//neu co the loai thi in ra
			d=1;
			printf("%-4d%-30s%-30s%-8d\n",i+1,(bookList+i)->ten,(bookList+i)->theloai,(bookList+i)->giatien);
		}
	}
	if(d==-1) printf("Khong co quyen sach thuoc the loai nay\n");
}
void ghifile(book_st *bookList){//Ghi noi dung cac quyen sach vao file
	FILE *t;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	if((t=fopen("book.dat","wb"))==NULL){
		printf("Error!");
		exit(1);
	}
	else printf("Ghi file thanh cong!!!\n");
	for(int i=0;i<3;i++){
		fwrite(bookList,sizeof(book_st),1,t);
	}
	fclose(t);
}
void menu(){//in ra menu
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	printf("\t\t____________________________________MENU_____________________________________\n");
	printf("\t\t|1__Nhap du lieu cua tung quyen sach                                        |\n");
	printf("\t\t|2__Sap xep va hien thi thong tin chi tiet cua tung quyen sach theo the loai|\n");
	printf("\t\t|3__Thong ke thong tin chi tiet tung quyen sach                             |\n");
	printf("\t\t|4__Tim quyen sach theo the loai                                            |\n");
	printf("\t\t|5__Ghi vao tap tin book.dat                                                |\n");
	printf("\t\t|6__Thoat___________________________________________________________________|\n");
}
void backmenu(){//xoa man hinh va nhan phim bat ki de tro ve MENU
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf("-->Nhan 1 phim bat ki de quay lai MENU ");
	getch();
	system("cls");
	menu();
}
int main(){
	struct book_st *bookList;
	bookList=(book_st*)malloc(3*sizeof(book_st));
	menu();
	int a;
	while(1){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		printf("\t\t-->Nhap lua chon cua ban tu MENU ");
		scanf("%d",&a);
		switch (a){
			case 1:{
				system("cls");
				nhap(bookList);
				backmenu();
				break;
			}
			case 2:{
				system("cls");
				hienthi(bookList);
				backmenu();
				break;
			}
			case 3:{
				system("cls");
				thongke(bookList);
				backmenu();
				break;
			}
			case 4:{
				system("cls");
				search(bookList);
				backmenu();
				break;
			}
			case 5:{
				system("cls");
				ghifile(bookList);
				backmenu();
				break;
			}
			case 6:{
				free(bookList);
				exit(0);
				break;
			}
		} 
	}
}


