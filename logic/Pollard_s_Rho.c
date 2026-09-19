#include <stdio.h>
#include "../header/Argorithm_Cal.h"

unsigned long long f(unsigned long long x){
	return (x * x) + 1;
}


//hàm nhân tố số nguyên tố
unsigned long long Pollard_s_Rho(unsigned long long input, unsigned long long *r_gcd){

/*
đầu tiên dựa vào writeup CSAPP floating point numbes khi một số ko phải nguyên tố vào. Việc đầu tiên là :

1. áp dung dãy biểu thức như lý thuyết là bình phương lên cộng một và chia lấy dư
*/

unsigned long long x = 2, result_gcd, result;

unsigned long long y = 2; //tạo biến để lưu kết quả vào nhân tiếp

for(int i = 0; i <= input; i++){

	if((long long)y-x < 0 || (long long)input < 0){printf("[ERR] negative numbers\n"); break;}

	x = f(x);
	y = f(f(x));

	if(y >= x){ /*làm sao cho số ngang hay lớn hơn modulo với input?
				  - nếu dùng phép lớn hay bé hơn thì trường hợp 3 mod 15 = 3 thì sao?
					nên ta dùng điều kiện so sánh lớn hơn hoặc bằng trước rồi dùng condiction lồng nhau
				 */
		x = x  % input;
		y = y  % input; //này là cái x bình phươn lên và cộng một như công thức x^2 + 1 và chia lấy dư

	}

	result_gcd = gcd(y-x,input);
	result = input / result_gcd;

	*r_gcd = result_gcd;
	//printf("[x] = %lld,[y] = %lld, [GCD] = %lld\n",x,y, result_gcd); //dòng này dùng để ghi log các output số

}

	return result;
}
