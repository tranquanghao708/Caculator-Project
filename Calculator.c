/*		Chào mừng đén với dự án đầu tiên của tôi

	+ dự án này là gì? : nó là một máy tính nâng cao, tôi có ao ước từ thuở nhỏ là máy tính casio mà mình dùng tuy nhiều tính năng thạt nhưng nó ko cho mình thấy quá trình. Tôi hiện ko thích điều đó, nên dự án này tôi lập trình bằng ngôn ngữ C để phục vụ cho mục đích của tôi và trợ giúp các việc tính toán về sau

	+ Dự án sẽ được tích hợp các thuật toán tính toán, hàm printf ra các biểu thức và kiểm tra tránh lỗi bảo mật cấp thấp

	+ Dự án luôn được cải tiến thỉnh thoảng, mục đích là phục vụ cho việc tính toán trong tương lai khi dùng các phép toán phức tạp để làm việc với phần số học. Ừm, thêm mục đích phụ là vì tiện

	+ Dự án này giúp gì cho việc tính toán và tôi ?, nó cho phép tôi tính toán thấy toàn bộ quá trình của biểu thức toán học phục vụ cho việc hiểu vì sao lại ra đáp án như thế, để tránh sự hiểu lầm hay phụ thuộc che mắt với những lỗi như đặt dấu ngoặc đơn v.v. Thêm nữa là tôi hiểu nó hơn vì tôi tạo ra nó

	+ Những kiến thức tối thiểu mà tôi dùng cho dự án này : Các kiến thức về chương two complement code, IEEE754, lập trình C. Chỉ có thể nêu được nhiêu đây thôi

	+ Tại sao lại có dự án này? lúc đầu ko có ý định tạo nó đâu, tại thấy phèn quá. Nhưng khi học phần nhân tố trong IEEE754 CSAPP, cần phải có thuât toán thiên hướng lặp lại thế này, và tôi nghĩ là sẽ cần nhiều trong tương lai, ko rảnh để đi lấy từng code rời rạc trên github rồi compiler ra để phục vụ tính toán cũng khá tốn time. Nên project này tôi tạo nên chủ yếu để giải quyết nhu cầu tính toán cần thiết của tôi thôi

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/Argorithm_Cal.h"
#include <pthread.h>

void help(){
	printf("HELP:\n\t--mode :"
		   "\n\tp : Pollard_s_RHO Algorithm\n"
			);
}

//lam viec da luong

typedef struct rho{
	unsigned long long b;
	unsigned long long r_gcd;
	unsigned long long a;
} rho_t;

void *work_RHO(void *arg){

	rho_t *rho = arg;
			rho->b = 9083793275; //atoll(argv[3]); //atoi thường trả int, atoll trả long long

			rho->a = Pollard_s_Rho(rho->b,&rho->r_gcd); /* note : cái r_gcd là dạng transmit
													  values gcd trong thuật toán ra ngoài, 
													  ta truyền địa chỉ vào trong đó và từ 
													  đó nó giải tham chiếu ra và truyền lại đây
													*/
	printf("[Cal] %lld = %lld x %lld\n",rho->b,rho->a,rho->r_gcd);

	return NULL;
}

int main(int argc, char *argv[]){

	if(argv[1] == NULL){
		printf("[ERR] Please transmit or using many modes in the program\n");
	return 1;
	}

	if(strcmp(argv[1], "--mode") == 0){ /*lỗi chí mạng từng phạm vào ngày 2/9/2026
										  đi lấy argv[1] == "--mode" (thực chất chúng
										  chỉ so sánh hai địa chỉ phải bằng nhau) 
										  theo GDB đã debug, thì cái này lỗi vì nó
										  đi cmp hai cái chuỗi y hệt nhau là '--mode'
										  nhưng vấn đề một cái là ở stack đi so sánh
										  với vaddr chương trình
										*/
		if(strcmp(argv[2], "p") == 0){
			pthread_t threads[4];
			rho_t rho_p[4];

			for (int i = 0; i < 4; i++) {
   				 pthread_create(&threads[i], NULL, work_RHO, &rho_p[i]);
			}
			
			for (int i = 0; i < 4; i++) {
   				 pthread_join(threads[i], NULL);
			}
			// Ý tưởng: thêm tính năng rainbow attack, nghĩa là khi nó tính xong một cái số gì đó thì nó sẽ vừa in ra và vừa ghi vào một file ghi trong thư mục, khi lần thử tính tiếp theo cái đầu tiên nó sẽ duyệt vào bảng tra xem có tồn tại ko, nếu có thì in ra luôn còn nếu ko thì nó sẽ thực hiện tính toán và ghi các kết quả mới vào bảng

		}
	}else{
		printf("\nAlgrument invalid\n");
		help();
		return -1;
	}
	//printf("gcd test= %lld\n",gcd(2379,4654));

	return 0;
}