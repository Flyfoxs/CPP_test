# Precondition
brew instal gcc@14


# CPP_test
- clang++ -o build/main.out main.cpp && ./build/main.out
- g++ -o build/main.out main.cpp && ./build/main.out
- rm ./build/split_box && clang++ -o build/split_box split_box.cpp && ./build/split_box
- CodeLLDB is required


# Local
g++-14 -o main.out decode.cpp && ./main.out
g++-14 -o main.out main.cpp && ./main.out


A1348: [CSP-J 2025] 座位 / seat
A1349: [CSP-J 2025] 异或和 / xor
A1350: [CSP-J 2025] 多边形 / polygon

# Project Structure

## Directories

| Description                                          | Directory              | Tag                                          |
| ---------------------------------------------------- | ---------------------- | -------------------------------------------- |
| A1349: [CSP-J 2025] 异或和 / xor                     | [2025/A1349_xor/main.cpp](./2025/A1349_xor/main.cpp) | 前缀和                                    |
| A1350: [CSP-J 2025] 多边形 / polygon                 | [2025/A1350_polygon/main.cpp](./2025/A1350_polygon/main.cpp) | dfs, TODO(40), online(100) 比较难, 暴力40分即可 |
| 9437: [2024年庐阳区初中区赛]最佳雇佣(hire)(3)           | [2024/hire/main.cpp](./2024/hire/main.cpp) | 语文题, 一个项目只能一个工人                    |
| 9438: [2024年庐阳区初中区赛]充电桩(move)(4)            | [2024/move/main.cpp](./2024/move/main.cpp) | 数学公式, 区间和, TODO(90)                   |
| 9439: [2024年庐阳区初中区赛]减少毒素(dec)(5)           |  [2024/dec/main_ex.cpp](./2024/dec/main_ex.cpp)  | DP, 完全背包                                          |
| 9275: [CSP-J 2024] 接龙(chain)                      | [2024/csp_chain/main.cpp](./2024/csp_chain/main.cpp) | 区间DP, 比较难                                             |
| 9274: [CSP-J 2024] 小木棍(sticks)                   | [2024/sticks/main.cpp](./2024/sticks/main.cpp) |  DP, 思路巧                                            |
| 7172: [AHOI2024初中]计数 (d)(4) 糖果                  | [2024/AHOI2024_d/main.cpp](./2024/AHOI2024_d/main.cpp) | 2次 dp (比较难, 看不懂答案)                |
| 7171: [AHOI2024初中]操作 (c)(3)                       | [2024/AHOI2024_c/main.cpp](./2024/AHOI2024_c/main.cpp) | online, 差分数组, 前缀和                     |
| 7170: [AHOI2024初中]立方根 (b)(2)                     | [2024/AHOI2024_b/main.cpp](./2024/AHOI2024_b/main.cpp) | 数学, 分段累计                                       |
| 6544: [CSP-J 2023] 旅游巴士(bus)                    | [2023/bus/main.cpp](./2023/bus/main.cpp) | 图, priority_queue, online(比较难)                  |
| 6543: [CSP-J 2023] 一元二次方程(uqe)                 | [2023/uqe/main.cpp](./2023/uqe/main.cpp) | 数学,方程, 最大公因数, 开根号, online                   |
| 6542: [CSP-J 2023] 公路(road)                       | [2023/road/main.cpp](./2023/road/main.cpp) |                             |
| 6246: [AHOI2023初中组]评分 (score)                   | [2023/AHOI2023_score/main.cpp](./2023/AHOI2023_score/main.cpp) | simple, sort(stl)                            |
| 6247: [AHOI2023初中组]数数 (count)                   | [2023/AHOI2023_count/main.cpp](./2023/AHOI2023_count/main.cpp) | dfs, 前缀和, 双指针, 三角形                       |
| 6248: [AHOI2023初中组]行走 (walk)                    |  题目不容易读懂          |               |
| 6249: [AHOI2023初中组]石子 (stone)                   | [2023/AHOI2023_stone/main.cpp](./2023/AHOI2023_stone/main.cpp) | dfs, DP, 前缀和, TODO(80), 固定开始点                    |
| 5844: [CSP-J 2022] 解密(decode)                    | [2022/decode/decode.cpp](./2022/decode/decode.cpp) |   数学, 方程                                           |
| 5845: [CSP-J 2022] 逻辑表达式(expr)                 | [2022/expr_5845/main.cpp](./2022/expr_5845/main.cpp) |   stack   
| 5846. [CSP-J 2022] 上升点列（point）                 | [2022/point/main.cpp](./2022/point/main.cpp) |    DP(DAG), T4                                 |
| 3203：【AHOI2021初中】坑（hole）（2）                    |[2021/hole/main_ex.cpp](./2021/hole/main_ex.cpp) | 二分查找, 贪心 」
| 2007: [20CSPJ普及组]方格取数                         | [2020/grid_2007/main.cpp](./2020/grid_2007/main.cpp) |    DP                                          |
| 1274: 合并石子                                       | [others/1274_store/main.cpp](./others/1274_store/main.cpp) |   DP (2种解法) + 前缀和, 任意开始点              |
| 3592: 表达式II (exp)                                 | [others/3592_exp/main.cpp](./others/3592_exp/main.cpp) |   DP, DFS             |
| 6687: 【剪枝优化】子集和问题                            | [others/zy_6687/main.cpp/](./others/zy_6687/main.cpp) | DFS, 剪枝 |
| 6688. 剪格子                                          | [others/zy_6688/main_v2.cpp](./others/zy_6688/main_v2.cpp) | DFS |

# Ref:

[信息学奥赛CSP和GESP答案](https://aimadao.com/wiki/1560506890453024)
