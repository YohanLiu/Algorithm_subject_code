class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0)
            return 0;
        int s1cnt = 0, index = 0, s2cnt = 0;
        //注意s2要从第index个字符开始匹配
        unordered_map<int, pair<int, int>> recall;
        pair<int, int> pre_loop, in_loop;
        while (true) {
            //我们多遍历一个s1，看看能不能找到循环节(鸽笼原理)
            s1cnt++;
            for (int i = 0; i < s1.length(); i++) {
                if (s1[i] == s2[index]) {
                    index++;
                    if (index == s2.length()) {
                        s2cnt++;
                        index = 0;
                    }
                }
            }
            //还没有找到循环节，所有的s1就用完了
            if (s1cnt == n1)
                return s2cnt / n2;
            //出现了之前的index，表示找到了循环节
            if (recall.count(index)) {
                auto [s1cnt_prime, s2cnt_prime] = recall[index];
                // 前 s1cnt' 个 s1 包含了 s2cnt' 个 s2
                pre_loop = {s1cnt_prime, s2cnt_prime};
                // 以后的每 (s1cnt - s1cnt') 个 s1 包含了 (s2cnt - s2cnt') 个 s2
                in_loop = {s1cnt - s1cnt_prime, s2cnt - s2cnt_prime};
                break;
            }
            else {
                recall[index] = {s1cnt, s2cnt};
            }
        }
        // ans 存储的是 S1 包含的 s2 的数量，考虑的之前的 pre_loop 和 in_loop
        int ans = pre_loop.second + (n1 - pre_loop.first) / in_loop.first * in_loop.second;
        // S1 的末尾还剩下一些 s1，我们暴力进行匹配
        int rest = (n1 - pre_loop.first) % in_loop.first;
        for (int i = 0; i < rest; ++i) {
            for (int i = 0; i < s1.length(); i++) {
                if (s1[i] == s2[index]) {
                    index++;
                    if (index == s2.length()) {
                        ans++;
                        index = 0;
                    }
                }
            }
        }
        //S1包含ans个s2，那么就包含ans / n2个S2
        return ans / n2;
    }
};
