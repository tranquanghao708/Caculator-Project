#include <stdio.h>
#include "../header/Argorithm_Cal.h"

//hàm nhân tố số nguyên tố
long long Pollard_s_Rho(long long input, long long *r_gcd){

/*
đầu tiên dựa vào writeup CSAPP floating point numbes khi một số ko phải nguyên tố vào. Việc đầu tiên là :

1. áp dung dãy biểu thức như lý thuyết là bình phương lên cộng một và chia lấy dư
*/

long long x = 2;
long long result_gcd;
long long result;
long long y; //tạo biến để lưu kết quả vào nhân tiếp
for(int i = 0; i <= input; i++){

	if(y,x > (unsigned long long)9223372036854775807 && y,x <= (long long)-1){ /* Như chương two complement code đã nói trước đó,
										để đảm bảo an toàn tránh overflow, condiction này check
										nó đã vượt Tmax, Umax của 64bit chưa nếu rồi thì kill ngay
										*/

		printf("[WARN] đã vượt tmax của long long, sau này số sẽ ra âm\n");

		break; //thử nghiệm break dễ debug

	}else if(y > (unsigned long long)-1){ //bước này so sánh cả Umax

		//printf("[ERR] Đã vượt Umax của long long. Thoát ngay để tránh overflow\n");
		//return -1; //phần này tạm ghu chú để kiểm tra giải pháp 1
		int i = 0;
		printf("[Frag=%d] %lld\n",i,y);
		i++;
	}

	x = (x * x) + 1;
	y = (x * x) + 1;

	if(y >= x){ /*làm sao cho số ngang hay lớn hơn modulo với input?
				  - nếu dùng phép lớn hay bé hơn thì trường hợp 3 mod 15 = 3 thì sao?
					nên ta dùng điều kiện so sánh lớn hơn hoặc bằng trước rồi dùng condiction lồng nhau
				 */
		x = x  % input;
		y = y  % input; //này là cái x bình phươn lên và cộng một như công thức x^2 + 1 và chia lấy dư

	/*[Vấn đề] Khi cung cấp vào một số vượt Tmax của 64bits, 
	thì khi thực hiện modulo nó vẫn là chính nó và từ đó gây
	nên vòng lặp vô hạn và giới hạn số bit, ví dụ cung cấp số
	lớn hơn Umax hay Tmax 64bit thì chả khác nào bị hạn chế

	+ giải pháp 1 giới hạn số học với kiến trúc: tổng in ấn phân mảnh (total fragment printf),
	nghĩa là nếu condiction phát hiện thấy cái này nằm trong khoảng gần sắp vượt ngưỡng giới 
	hạn kiến trúc, nó bắt đầu in ra là phân mảnh 1, và nó tiếp tục chạy cho tới khi hoàn thiện
	biểu thức và ta lấy số lần phân mảnh tính tổng lại. Ví dụ 4 bit, có 15 là Umax bây giờ thấy
	số chạm 15 là 1111 bắt đầu in [Frag=1] 15, nếu giá trị là 30 thì nó sẽ in [Frag=1] 15 , 
	[Frag=2] 15 và nhiệm vụ của ta là tính tay hay bấm máy tính khác có architecture cao hơn
	để tính tổng 15 + 15 = 30
	*/
		

	}

	result_gcd = gcd(y-x,input);
	result = input / result_gcd;

	*r_gcd = result_gcd;
	//printf("[x] = %lld,[y] = %lld, [GCD] = %lld\n",x,y, result_gcd); //dòng này dùng để ghi log các output số

}

	return result;
}
