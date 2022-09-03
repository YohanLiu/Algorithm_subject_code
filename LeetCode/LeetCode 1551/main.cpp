class Solution {
public:
    /*˼·���£�
    **����Ԫ����������������Ԫ�ر�����м���Ǹ�ֵ��
    **������[1,3,5]������Ԫ�أ�����Ҫ������Ԫ�ر��3
    **����Ԫ��ż������������Ԫ�ر�����м��������ֵ��ƽ��ֵ��
    **������[1,3,5,7]������Ԫ�أ�����Ҫ������Ԫ�ر��(3+5)/2=4
    */
    int minOperations(int n) {
        int res = 0;
        if(n % 2 == 0) {
            int m = n / 2 - 1;
            int temp = 1 + 1 + (2 * m);
            for(int i = 0; i <= m; i++)
                res += temp - ((2 * i) + 1);
        }
        else {
            int m = n / 2;
            int temp = 1 + (2 * m);
            for(int i = 0; i < m; i++)
                res += temp - ((2 * i) + 1);
        }
        return res;
    }
};