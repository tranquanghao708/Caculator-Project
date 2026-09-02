#include <stdio.h>
#include "../header/Argorithm_Cal.h"

long long gcd(long long input1, long long input2){

	/*Hypothesis 1: để tính quỷ này, ta cần phải tạo một condiction so sánh hai số, chọn một trong hai số số nào lớn nhất sẽ được đưa vào vòng lặp để thực hiện tính toán, vì với ước chung lớn nhất ta cần phải chọn một số chia hết cho cả hai số input lớn nhất vì vậy cần làm điều này để tiết kiệm thời gian và tài nguyên, việc lấy số lớn hơn hai số đầu vào đi chia hết cho hai số là vô nghĩa. Cái đúng là nên dùng số nhỏ hơn hoặc bằng hai số đầu vào lớn nhất để thực hiện phép toán*/

	long long input_largest;  //biến này dùng để lấy số lớn nhất của hai giá trị input1 và input2 để setup cái điều kiện chạy loop và tính toán
	if(input1 >= input2){
		input_largest = input1;
	}else if(input1 <= input2){
		input_largest = input2;
	}else if(input1 <= (long long)-1 || input2 <= (long long)-1){ //so sánh số âm, nguyên lý là nếu MSB = 1 hay lớn hơn số Tmin thì in lỗi
		printf("[ERR] Algorithm GCD lỗi vì hai input có một số âm\n");
		return -1;
	}

//Tới lượt phần vòng loop để thực hiện tính toán

	long long output; //biến này vai trò lưu trữ các kết quả tính toán và phục vụ cho so sánh condiction

	//__asm__ __volatile__("movl $0, %eax\n\t"); Gặp mấy ông lỏ trên kênh kael build hướng dẫn cái thêm vô ba cái lệnh gán lỏ này ko biết làm gì compiler, mà ghi 1 dòng y chang trên tiktok lỏ đó vô ko thấy tăng một chút vòng lặp gì. Đúng là kênh tiktok ko bằng đọc sách hay tài liệu nghiêm túc mà. Để đây nghiên cứu sau

	for(long long i = 1 ; i <= input_largest; i++){

		if(input1 % i == 0 && input2 % i == 0){ 
			output = i;
		}

		//printf("[LOG] loop gcd = %d\n",i);
	}
	return output;
}