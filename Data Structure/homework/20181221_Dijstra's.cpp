#include <stdio.h>
#define sw(a,b,c) (a)=(b);(b)=(c);(c)=(a);
int main() {
	int all[26], editNum[26], editNumBuff[26];
	char vertex1[100], vertex2[100], temp, start;
	int edgenum, weight[100], i, j;                 //i�Mj�O�{�ɻݭn�Ϊ��ɭԥΪ�

	scanf("%d", &edgenum);                          //Ū�iedge���ƶq
	for (i = 0; i < 26; i++){                       //��l�Ҧ��}�C
		all[i] = -1, editNum[i] = 0, editNumBuff[i] = 0;
	}


	for (i = 0; i < edgenum; i++){                  //Ū�i�Ҧ�edge
		scanf(" %c %c %d", &vertex1[i], &vertex2[i], &weight[i]);
	}

	scanf(" %c", &start);                           //Ū�i�_�lnode
	for (i = 0; i < edgenum; i++) {
		if (vertex1[i] == start) {
			all[vertex2[i] - 'a'] = weight[i];      //�⦳�_�lnode��edge��weight�s�i�}�C
			editNum[vertex2[i] - 'a'] = 1;          //editNum�]��1�N���q�L�L�F
		}
	}

	for (int i1 = 0; i1 < edgenum; i1++) {          //���_�lnode�������t���h�A�n�@��������sweight
		for (int i2 = 0; i2 < 26; i2++) {
			if (editNum[i2] == 1) {
				for (int i3 = 0; i3 < edgenum; i3++) {
					if (vertex1[i3] == i2 + 'a') {
						if (all[vertex2[i3] - 'a'] > weight[i3] + all[i2])
							all[vertex2[i3] - 'a'] = weight[i3] + all[i2];
						editNumBuff[vertex2[i3] - 'a'] = 1;

					}
				}
			}
		}
		for (int i2 = 0; i2 < 26; i2++) {
			editNum[i2] = editNumBuff[i2];
			editNumBuff[i2] = 0;
		}
	}

	printf("%c %d\n", start, 0);
	i = 0, j = 0;
	int k4[26];
	for (int z; i < 26; i++) {
		if (all[i] != 0xffff) {
			all[j] = all[i];
			k4[j++] = i;
		}
	}

	for (int i1 = 0; i1<j - 1; i1++){
		for (int i2 = 0, i3; i2<j - i1 - 1; i2++)
			if (all[i2] > all[i2 + 1]) {
				sw(i3, all[i2 + 1], all[i2])
					sw(i3, k4[i2 + 1], k4[i2])
			}
	}

	for (i = 0; i<j; i++){
		printf("%c %d\n", k4[i] + 'a', all[i]);         //�٭n�O�o��̫᪺'a�[�a�^�h
	}

	return 0;
}
