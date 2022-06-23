#include "huf.h"
#include "read.h"
#include "tools.h"
#include "write.h"
#define SIZE 128
//chcp 65100; g++ main.cpp -o main.exe; ./main.exe  ���������
int main(){

    // while()
    string path = "../flowers.txt";
    int PL[SIZE+2] = {0};      //Ȩ�أ� �����λ�ֱ����Ȩ�ط���ĸ�������PL�ܺ�

    if(TongJi(path, PL)){

        cout << "�ɹ���\n";
    } 

    HuffmanTree HT;
    CreateHuff(HT, PL);
    //region
    // for(int i = 0; i < 128; i++){
    //     if(PL[i] > 0){
    //         cout << char(i) << "  " << 1.0 * PL[i] / PL[SIZE+1] << endl;
    //     }
    // }
    cout << "�������� " << PL[SIZE] << endl;

    HuffmanCode HC;
    HuffCoding(HT, HC, PL[SIZE]); //��������������

    double sum = 0.0;
    int k = 0;


    //region
	// for (int i = 1; i <= PL[SIZE]; i++) //��ӡ����������
	// {
	// 	printf("����%c�ı���Ϊ:%s\n", HT[i].data, HC[i]);
    //     sum += HT[i].weight;
    //     cout << k + 1 << "&&" << sum << endl;
    //     k++;
	// }  
    // for(int i = 1; i <= 2 * PL[SIZE] - 1; i++){
    //     cout << HT[i].weight << "  ";
    // }

    writeYS("../flowers.txt", HT, HC, PL[SIZE]);
    cout << "����ʲô���ˣ�\n";
    // for(int i = 1; i <= PL[SIZE]; i++){

    //     cout << HT[i].data + "$$" ;
    //     printf("%s\n", HC[i]);
    // }

    Clear(HT);
    Clear(HC);
    system("pause");
    return 0;
}