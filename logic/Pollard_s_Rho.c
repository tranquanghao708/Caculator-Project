#include <stdio.h>
#include "../header/Argorithm_Cal.h"

//hàm nhân tố số nguyên tố
long long Pollard_s_Rho(long long input){

/*
đầu tiên khi một số ko phải nguyên tố vào. Việc đầu tiên là :

1. áp dung dãy biểu thức như lý thuyết là bình phương lên cộng một và chia lấy dư
*/

int x = 0;
long long output = input; //tạo biến để lưu kết quả vào nhân tiếp
while(true){

	output = (output * output) + 1; //này là cái x bình phươn lên và cộng một như công thức x^2 + 1

	if(output == (long long)9223372036854775808 && output <= (long long)-1){ /* Như chương two complement code đã nói trước đó,
										để đảm bảo an toàn tránh overflow, condiction này check
										nó đã vượt Tmax, Umax của 64bit chưa nếu rồi thì kill ngay
										*/

		printf("[WARN] đã vượt tmax của long long, sau này số sẽ ra âm\n");

	}else if(output == (unsigned long long)-1){ //bước này so sánh cả Umax

		//printf("[ERR] Đã vượt Umax của long long. Thoát ngay để tránh overflow\n");
		//return -1; //phần này tạm ghu chú để kiểm tra giải pháp 1
		int i = 0;
		printf("[Frag=%d] %lld\n",i,output);
		i++;
	}

	if(output >= input){ /*làm sao cho số ngang hay lớn hơn modulo với input?
						  - nếu dùng phép lớn hay bé hơn thì trường hợp 3 mod 15 = 3 thì sao?
							nên ta dùng điều kiện so sánh lớn hơn hoặc bằng trước rồi dùng condiction lồng nhau
						 */
		output %= input; //modulo với input gán vào output

	/*[Vấn đề] Khi cung cấp vào một số vượt Tmax của 64bits, thì khi thực hiện modulo nó vẫn là chính nó và từ đó gây nên vòng lặp vô hạn và giới hạn số bit, ví dụ cung cấp số lớn hơn Umax hay Tmax 64bit thì chả khác nào bị hạn chế

	+ giải pháp 1 giới hạn số học với kiến trúc: tổng in ấn phân mảnh (total fragment printf), nghĩa là nếu condiction phát hiện thấy cái này nằm trong khoảng gần sắp vượt ngưỡng giới hạn kiến trúc, nó bắt đầu in ra là phân mảnh 1, và nó tiếp tục chạy cho tới khi hoàn thiện biểu thức và ta lấy số lần phân mảnh tính tổng lại. Ví dụ 4 bit, có 15 là Umax bây giờ thấy số chạm 15 là 1111 bắt đầu in [Frag=1] 15, nếu giá trị là 30 thì nó sẽ in [Frag=1] 15 , [Frag=2] 15 và nhiệm vụ của ta là tính tay hay bấm máy tính khác có architecture cao hơn để tính tổng 15 + 15 = 30*/
		

	}
	printf("%lld\n",output); //dòng này dùng để ghi log các output số
	x++;
}

	return output;
}
