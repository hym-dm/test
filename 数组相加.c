#define  _CRT_SECURE_NO_WARNINGS 1
int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {

    //����K��λ��cnt
    int tmp = K;
    int cnt = 0;
    while (tmp) {
        ++cnt;
        tmp /= 10;
    }
    //�Ƚ�A������K�ĳ��ȣ���ȷ����Ҫ����Ŀռ��С,Ϊ��ֹ�����+1
    int size = (ASize + 1 > cnt + 1) ? ASize + 1 : cnt + 1;
    int* arr = (int*)malloc(sizeof(int) * size);

    //�����������Խ�������ˣ�������β����ʼ��
    //ѭ����������ΪA�������K��ÿλ������
    int n = size;
    int flag = 0;//��־λ���ж��Ƿ����
    for (int i = ASize - 1; i >= 0 || K; i--) {
        //����һ��sumΪ����ĩλ֮�ͣ�һ��������ĩβ��һ����ȡ�ࣩ
        int sum = (K ? K % 10 : 0) + (i >= 0 ? A[i] : 0) + flag;  //���������һλ�������������ĩλ��ӣ��Լ��Ƿ��н�λ
        K = (K ? K / 10 : 0);       //K�������һλ����Ҫɾ�����һλ
        arr[--n] = sum % 10;    //��sum%10���봴�������ĩβ
        flag = sum / 10;        //count������ж�λ�����sum>=10,��ôcount�ͻ��Ϊ1
    }
    if (flag)arr[--n] = 1;//A��K���Ƚ�����Ҫȷ��count,��������ȷ�����շ��ص������С
    *returnSize = size - n;//������������С
    return arr + n;//���շ��ص���Ҫ��arr����ĵ�n��λ�ã���Ϊ��������������������ȷ����һλû���ݵĻ���Ȼ�����������ء�

}


