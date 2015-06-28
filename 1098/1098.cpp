#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <iostream>

void adjust(int datas[], int node, int len);

int main() 
{
    int datas[100];
    int s_datas[100];
    int len_of_datas;
    scanf("%d", &len_of_datas);
    for(int i = 0; i < len_of_datas; ++i) 
    {
        scanf("%d", datas + i);
    }
    for(int i = 0; i < len_of_datas; ++i) 
    {
        scanf("%d", s_datas + i);
    }

    // �ҵ�mid,s_datas������(mid,len_of_datas),��datas��һ��
    int mid;
    for(mid = len_of_datas - 1; s_datas[mid] == datas[mid] && mid >= 0; --mid);

    // �ж�s_datas(0,mid]�Ƿ����������Ϊ�������򣬷�֮������
    bool is_insertion = true;
    for(int i = 0; i < mid; ++i)
    {
        if(s_datas[i] > s_datas[i + 1])
        {
            is_insertion = false;
            break;
        }
    }

    if(is_insertion) // ���Ϊ��������
    {
        int s = mid; // ������Ԫ���±�
        if(s >= len_of_datas) 
        {
            // �Ѿ���ȫ�������
            printf("already sorted\n");
            return 2;
        }
        int insert; // ����λ�ã�֮ǰ��
        do {
            ++s;
            if(s >= len_of_datas) {
                break;
            }
            for(insert = 0; insert < s && s_datas[insert] < s_datas[s]; ++insert) ;
        } while(insert == s);
        if(s < len_of_datas) {
            int s_value = s_datas[s];
            memmove(s_datas + insert + 1, s_datas + insert, (s - insert) * sizeof(int));
            s_datas[insert] = s_value;
        }
    }
    else { // ���Ϊ������
        // ��������������(s,len_of_datas)
        int s;
        for(s = len_of_datas - 1; s >= 0 && s_datas[s] >= s_datas[0]; --s); // ѭ������ʽ����������Ԫ�ش��ڵ��ڶѶ�Ԫ�أ�[s,len_of_datas)���򣬱ض����㣩
        std::swap(s_datas[0], s_datas[s]);
        // ���µ�����
        adjust(s_datas, 0, s);
    }

    // ������
    if(is_insertion) 
    {
        printf("Insertion Sort\n");
    }
    else 
    {
        printf("Heap Sort\n");
    }
    printf("%d", s_datas[0]);
    for(int i = 1; i < len_of_datas; ++i) {
        printf(" %d", s_datas[i]);
    }
    printf("\n");
    return 0;
}

void adjust(int datas[], int node, int len) {
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    if(left < len && datas[left] > datas[node] && (right >= len || datas[left] > datas[right])) {
        std::swap(datas[node], datas[left]);
        adjust(datas, left, len);
    }
    else if(right < len && datas[right] > datas[node] && (left >= len || datas[right] > datas[left])) {
        std::swap(datas[node], datas[right]);
        adjust(datas, right, len);
    }
    else {
        return ;
    }
}