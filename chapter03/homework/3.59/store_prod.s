/*
 * 家庭作业3.59
 */
 
# void store_prod(int128_t* dest, int64_t x, int64_t y)
# dest in %rdi, x in %rsi, y in %rdx

# w为64，表示x和y的位数
# high_y 表示y的最高位，0或1
# sign_y 表示y的符号，0或-1
# 且hign_y == - sign_y

1  store_prod:
2   movq    %rdx, %rax      # %rax = y
3   cqto                    # %rdx = sign_y
4   movq    %rsi, %rcx      # %rcx = x
5   sarq    $63, %rcx       # %rcx = sign_x
6   imulq   %rax, %rcx      # %rcx = sign_x * y
7   imulq   %rsi, %rdx      # %rdx = sign_y * x
8   addq    %rdx, %rcx      # %rcx = sign_x * y + sign_y * x
9   mulq    %rsi            # %rdx:%rax = x * y; 无符号全乘法, %rdx为高64位, %rax位低64位; 
10  addq    %rcx, %rdx      # %rdx += sign_x * y + sign_y * x
11  movq    %rax, (%rdi)    # 存储低64位的值
12  movq    %rdx, 8(%rdi)   # 存储高64位的值
13  ret                     # 返回

# 参见本书第二章 68页 公式(2.18)
# x'和y'表示非负整数，x和y表示有符号整数

#   x' * y' = (x + high_x * 2^w) * (y + high_y * 2^w)
#           = x * y + (high_x * y + high_y * x) * 2^w + (high_x * high_y) * 2^(2*w)

# 上式最后一项为 (...) * 2^(2*w), 也就是(...) * 2^128, 可忽略, 即：
 
#   x * y = x' * y' - (high_x * y + high_y * x) * 2^w
# 即：

    x * y = x' * y' + (sign_x * y + sign_y * x) * 2^w
# 所以第10行才会将%rdx(高64位) 加上 (sign_x * y + high_y * x)