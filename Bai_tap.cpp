#include <stdio.h>
#include <math.h>

int kiem_tra(long long so_bit){
	int p = 0;
	int test = 0;
	while(so_bit > 0){
		test += (so_bit % 10) * pow(2, p);
		p++;
		so_bit /= 10;
	}
	return test;
}

int kiem_tra_2(long long so_bit_2){
	int p = 0;
	int test = 0;
	while(so_bit_2 > 0){
		test += (so_bit_2 % 10) * pow(2, p);
		p++;
		so_bit_2 /= 10;
	}
	return test;
}

int tinh(long long so_bit, long long so_bit_2){
	int kq = 0;
	for(int i=kiem_tra(so_bit); i<=kiem_tra_2(so_bit_2); i++){
		int kc = (int)sqrt(i);
		if(pow(kc, 2)==i){
			kq = kq+1;
		}	
	}
	return kq;
}

int main(){
	FILE *f;
	f=fopen("BAI2.INP", "w");
	if(f==NULL){
		printf("\nLoi tao or mo file!!!");
		exit(1);
	}
	long long so_bit, so_bit_2;
	printf("Nhap so bit: ");
	scanf("%lli", &so_bit);
	printf("\nNhap so bit_2: ");
	scanf("%lli", &so_bit_2);
	fprintf(f, "%d", so_bit);
	fprintf(f, "\n%d", so_bit_2);

	fclose(f);
	
	FILE *t;
	t=fopen("BAI2.OUT", "w");
	if(f==NULL){
		printf("\nLoi tao or mo file!!!");
		exit(1);
	}
	fprintf(t, "%d", tinh(so_bit, so_bit_2));
	fclose(t);
}
