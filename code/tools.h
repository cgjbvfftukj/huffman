#ifndef __TOOLS_H__
#define __TOOLS_H__

#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
using namespace std;

//��ȡ��С����λ
void getTwoMin(HuffmanTree& HT, int n, int& s1, int& s2){ //�õ�Ȩֵ��С������ֵ������s1<s2
	int min;

	//�ҵ�һ����Сֵ
	for (int i = 1; i <= n; i++){
		if (HT[i].parent == 0)
		{
			min = i;
			break;
		}
	}

	for (int i = min + 1; i <= n; i++){
		if (HT[i].parent == 0 && HT[i].weight < HT[min].weight)
			min = i;
	}
	
	s1 = min; //��һ����Сֵ��s1

	//�ҵڶ�����Сֵ
	for (int i = 1; i <= n; i++){
		if (HT[i].parent == 0 && i != s1)
		{
			min = i;
			break;
		}
	}
	for (int i = min + 1; i <= n; i++){
		if (HT[i].parent == 0 && HT[i].weight < HT[min].weight && i != s1)
			min = i;
	}
	s2 = min; //�ڶ�����Сֵ��s2
}

//������������
template <size_t size>
void CreateHuff(HuffmanTree& HT, int (&arr)[size]){

	int n = arr[size-2];
    int m = 2 * n - 1;  //�����������ܽ����
    HT = (HuffmanTree)calloc(m+1, sizeof(HTNode));  //�±�Ϊ���λ�ò��������
	HTnum = m + 1;

	int t = 1, sum = 0;

	//��㣬���Ȩֵ
    for (int i = 0; i < size-2; i++){

		if(arr[i] != 0){
			// HT[t].weight = 1.0 * arr[i] / arr[size - 1];
			HT[t].weight = arr[i];
			HT[t].data = char(i);
			t++;
		}    	
    }

	for (int i = n + 1; i <= m; i++) //������������
	{
		//ѡ��Ȩֵ��С��s1��s2���������ǵĸ����
		int s1, s2;
		getTwoMin(HT, i - 1, s1, s2); //���±�Ϊ1��i-1�ķ�Χ�ҵ�Ȩֵ��С������ֵ���±꣬����s1��ȨֵС��s2��Ȩֵ
		HT[i].weight = HT[s1].weight + HT[s2].weight; //i��Ȩ����s1��s2��Ȩ��֮��
		HT[s1].parent = i; //s1�ĸ�����i
		HT[s2].parent = i; //s2�ĸ�����i
		HT[i].lc = s1; //������s1
		HT[i].rc = s2; //�Һ�����s2
		HT[i].data = '@' ;
		HT[i].parent = 0;
	}
}

//���ɹ���������
void HuffCoding(HuffmanTree& HT, HuffmanCode& HC, int n)
{
	HC = (HuffmanCode)malloc(sizeof(char*)*(n + 1)); //��n+1���ռ䣬��Ϊ�±�Ϊ0�Ŀռ䲻��
	HCnum = n + 1;
	char* code = (char*)malloc(sizeof(char)*n); //�����ռ䣬�����Ϊn(�ʱ��ǰn-1�����ڴ洢���ݣ����1�����ڴ��'\0')
	code[n - 1] = '\0'; //�����ռ����һ��λ��Ϊ'\0'

	for (int i = 1; i <= n; i++)
	{
		int start = n - 1; //ÿ���������ݵĹ���������֮ǰ���Ƚ�startָ��ָ��'\0'
		int c = i; //���ڽ��еĵ�i�����ݵı���
		int p = HT[c].parent; //�ҵ������ݵĸ����
		while (p) //ֱ�������Ϊ0���������Ϊ�����ʱ��ֹͣ
		{
			if (HT[p].lc == c) //����ý�����丸�������ӣ������Ϊ0������Ϊ1
				code[--start] = '0';
			else
				code[--start] = '1';
			c = p; //�������Ͻ��б���
			p = HT[c].parent; //c�ĸ����
		}
		HC[i] = (char*)malloc(sizeof(char)*(n - start)); //�������ڴ洢������ڴ�ռ�
		HT[i].depth = n - start - 1;
		strcpy(HC[i], &code[start]); //�����뿽�����ַ�ָ�������е���Ӧλ��
	}

	delete[] code; //�ͷŸ����ռ�
}

void clearHT(HuffmanTree HT){

	free(HT);
}

void clearHC(HuffmanCode HC){

	for(int i = 1; i < HCnum; i++){

		free(HC[i]);
	}
}
#endif