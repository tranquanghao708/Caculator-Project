/*		Chào mừng đén với dự án đầu tiên của tôi

	+ dự án này là gì? : nó là một máy tính nâng cao, tôi có ao ước từ thuở nhỏ là máy tính casio mà mình dùng tuy nhiều tính năng thạt nhưng nó ko cho mình thấy quá trình. Tôi hiện ko thích điều đó, nên dự án này tôi lập trình bằng ngôn ngữ C để phục vụ cho mục đích của tôi và trợ giúp các việc tính toán về sau

	+ Dự án sẽ được tích hợp các thuật toán tính toán, hàm printf ra các biểu thức và kiểm tra tránh lỗi bảo mật cấp thấp

	+ Dự án luôn được cải tiến thỉnh thoảng, mục đích là phục vụ cho việc tính toán trong tương lai khi dùng các phép toán phức tạp để làm việc với phần số học. Ừm, thêm mục đích phụ là vì tiện

	+ Dự án này giúp gì cho việc tính toán và tôi ?, nó cho phép tôi tính toán thấy toàn bộ quá trình của biểu thức toán học phục vụ cho việc hiểu vì sao lại ra đáp án như thế, để tránh sự hiểu lầm hay phụ thuộc che mắt với những lỗi như đặt dấu ngoặc đơn v.v. Thêm nữa là tôi hiểu nó hơn vì tôi tạo ra nó

	+ Những kiến thức tối thiểu mà tôi dùng cho dự án này : Các kiến thức về chương two complement code, IEEE754, lập trình C. Chỉ có thể nêu được nhiêu đây thôi

	+ Tại sao lại có dự án này? lúc đầu ko có ý định tạo nó đâu, tại thấy phèn quá. Nhưng khi học phần nhân tố trong IEEE754 CSAPP, cần phải có thuât toán thiên hướng lặp lại thế này, và tôi nghĩ là sẽ cần nhiều trong tương lai, ko rảnh để đi lấy từng code rời rạc trên github rồi compiler ra để phục vụ tính toán cũng khá tốn time. Nên project này tôi tạo nên chủ yếu để giải quyết nhu cầu tính toán cần thiết của tôi thôi

*/

#include <stdio.h>
#include "header/Argorithm_Cal.h"

int main(void){

	long long a = Pollard_s_Rho(9223372036854775808); //phần kiểm tra, chưa thêm gì cao siêu vào

	printf("%lld\n",a);
	return 0;
}