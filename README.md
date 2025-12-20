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
| A1349: [CSP-J 2025] 异或和 / xor                     | `2025/A1349_xor/`      |                                              |
| A1350: [CSP-J 2025] 多边形 / polygon                 | `2025/A1350_polygon/`  | dfs, TODO(40), online(100) 比较难, 暴力40分即可 |
| 9437: [2024年庐阳区初中区赛]最佳雇佣(hire)(3)           | `2024/hire/`           | online                                       |
| 9438: [2024年庐阳区初中区赛]充电桩(move)(4)            | `2024/move/`           | 数学公式, 区间和, TODO(90)                   |
| 9439: [2024年庐阳区初中区赛]减少毒素(dec)(5)           |                        | DP                                           |
| 9275: [CSP-J 2024] 接龙(chain)                      | `2024/csp_chain/`      |                                              |
| 9274: [CSP-J 2024] 小木棍(sticks)                   | `2024/sticks/`         |                                              |
| 7172: [AHOI2024初中]计数 (d)(4)                       | `2024/AHOI2024_d/`     |                                              |
| 7171: [AHOI2024初中]操作 (c)(3)                       | `2024/AHOI2024_c/`     | online, 差分数组, 前缀和                     |
| 7170: [AHOI2024初中]立方根 (b)(2)                     | `2024/AHOI2024_b/`     | online                                       |
| 6544: [CSP-J 2023] 旅游巴士(bus)                    | `2023/bus/`            | 图, priority_queue, online                   |
| 6543: [CSP-J 2023] 一元二次方程(uqe)                 | `2023/uqe/`            | 最大公因数, 开根号, online                   |
| 6542: [CSP-J 2023] 公路(road)                       | `2023/road/`           |                                              |
| 6246: [AHOI2023初中组]评分 (score)                   | `2023/AHOI2023_score/` | simple, sort(stl)                            |
| 6247: [AHOI2023初中组]数数 (count)                   | `2023/AHOI2023_count/` | dfs, 前缀和, 双指针                          |
| 6248: [AHOI2023初中组]行走 (walk)                    |                        |                                              |
| 6249: [AHOI2023初中组]石子 (stone)                   | `2023/AHOI2023_stone/` | dfs, DP, 前缀和, TODO(80)                    |
| 5844: [CSP-J 2022] 解密(decode)                    | `2022/decode/`         |                                              |
| 5845: [CSP-J 2022] 逻辑表达式(expr)                 | `2022/expr_5845/`      |                                              |
| 2007: [20CSPJ普及组]方格取数                         | `2020/grid_2007/`      |                                              |
| 1274: 合并石子                                       | `others/1274_store/`   |                                              |
| 3592: 表达式II (exp)                                 | `others/3592_exp/`     |                                              |


# Ref:

[信息学奥赛CSP和GESP答案](https://aimadao.com/wiki/1560506890453024)
