#define  _CRT_SECURE_NO_WARNINGS 1
int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {

    //计算K的位数cnt
    int tmp = K;
    int cnt = 0;
    while (tmp) {
        ++cnt;
        tmp /= 10;
    }
    //比较A数组与K的长度，以确定需要分配的空间大小,为防止溢出都+1
    int size = (ASize + 1 > cnt + 1) ? ASize + 1 : cnt + 1;
    int* arr = (int*)malloc(sizeof(int) * size);

    //分配好数组可以进行相加了，从数组尾部开始加
    //循环结束条件为A加完或者K的每位都加完
    int n = size;
    int flag = 0;//标志位，判断是否溢出
    for (int i = ASize - 1; i >= 0 || K; i--) {
        //定义一个sum为两个末位之和（一个是数组末尾，一个是取余）
        int sum = (K ? K % 10 : 0) + (i >= 0 ? A[i] : 0) + flag;  //新数组最后一位等于两个数组的末位相加，以及是否有进位
        K = (K ? K / 10 : 0);       //K加完最后一位后需要删掉最后一位
        arr[--n] = sum % 10;    //将sum%10放入创建数组的末尾
        flag = sum / 10;        //count是溢出判断位，如果sum>=10,那么count就会变为1
    }
    if (flag)arr[--n] = 1;//A和K都比较完需要确认count,这样可以确定最终返回的数组大小
    *returnSize = size - n;//分配的新数组大小
    return arr + n;//最终返回的需要是arr数组的第n个位置，因为分配的数组更大，这样可以确保第一位没数据的话仍然可以正常返回。

}


