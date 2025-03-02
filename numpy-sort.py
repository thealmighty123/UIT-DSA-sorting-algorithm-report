import os
import time
import numpy as np  # Import numpy nếu cần xử lý số liệu

# Đường dẫn thư mục chứa các file input
folder_path = r"C:\Users\ADMIN\Documents\gen-test"  # Dùng r"..." để tránh lỗi UnicodeEscape

# Lấy danh sách tất cả file .inp trong thư mục
input_files = [f for f in os.listdir(folder_path) if f.endswith(".inp")]

# Giới hạn chỉ lấy 10 file (nếu có nhiều hơn)
input_files = input_files[:10]

# Kiểm tra nếu không có file nào
if not input_files:
    print("❌ Không tìm thấy file .inp nào trong thư mục!")
    exit()

# Duyệt qua từng file và đo thời gian xử lý
for file_name in input_files:
    file_path = os.path.join(folder_path, file_name)

    # Bắt đầu tính thời gian chạy
    start_time = time.time()

    # Đọc dữ liệu từ file
    with open(file_path, "r") as file:
        data = file.read()  # Đọc toàn bộ nội dung
        numbers = list(map(float, data.split()))  # Chuyển thành danh sách số
    numbers.pop(0); # Bỏ phần tử đầu tiên (số lượng phần tử)
    sorted_numbers = np.sort(numbers)

    # Kết thúc tính thời gian
    end_time = time.time()

    # Tính thời gian chạy (ms)
    elapsed_time = (end_time - start_time) * 1000  

    # Xuất kết quả
    print(f"📂 File: {file_name} | ⏳ Thời gian chạy: {elapsed_time:.4f} ms")

print("\n✅ Hoàn thành chạy 10 file input!")
