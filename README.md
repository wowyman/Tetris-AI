Game xếp hình :

Cách chơi: sử dụng các phím W A D S để điều khiển khối gạch rơi xuống và xoay gạch. Khi một hàng đủ 10 viên thì sẽ biến mất. Game kết thúc khi gạch chạm đến đỉnh màn hình.

Ấn W để xoay khối gạch, A: sang trái ,D : sang phải ,S: dịch chuyển khối gạch xuống đáy bàn chơi.

Game dùng mảng 2 chiều để lưu bàn chơi và ánh xạ từ hệ tọa độ của mảng sang hệ tọa độ của SDL_RenderFillRect để tác động lên các khối gạch. 

High score được lưu vào file high_score.txt mỗi lần chơi được điểm cao hơn sẽ thay giá trị trong file.

Có chức năng AI để tự chơi,ấn RUN AI để chạy 
