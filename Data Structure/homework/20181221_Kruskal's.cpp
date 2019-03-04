#include <stdio.h>
#define sw(a,b,c) (a)=(b);(b)=(c);(c)=(a);

int main() {
	char vertex1[100], vertex2[100], temp;
	int edgenum, weight[100], tem;
	int all[26];

	scanf("%d", &edgenum);
    for (int i = 0; i < 26; i++){                           //初始化陣列
        all[i] = 0;
    }

    for (int i = 0; i < edgenum; i++) {                     //讀進所有edge
        scanf(" %c %c %d", &vertex1[i], &vertex2[i], &weight[i]);
        if (vertex1[i] > vertex2[i]) {                      //確保兩個node按照字母順序排
            sw(temp, vertex1[i], vertex2[i]);
        }
        all[vertex1[i] - 'a'] = vertex1[i] - 'a' + 1;       //把兩個node的關係存進array
        all[vertex2[i] - 'a'] = vertex2[i] - 'a' + 1;
    }

    for (int i = 0; i < (edgenum - 1); i++){                //利用bubble sort排出weight順序
        for (int j = 0; j < (edgenum - i - 1); j++){
            if (weight[j] > weight[j + 1]) {
                sw(tem, weight[j], weight[j + 1]);
                sw(temp, vertex2[j], vertex2[j + 1]);
                sw(temp, vertex1[j], vertex1[j + 1]);
            }
        }
    }

    for (int i = 0; i < edgenum; i++) {
        if (all[vertex1[i] - 'a'] != all[vertex2[i] - 'a']) {           //依照weight順序印出不重複node的edge
            for (int j = 0, t = all[vertex2[i] - 'a']; j < 26; j++) {
                if (t == all[j]){
                    all[j] = all[vertex1[i] - 'a'];
                }
            }
            printf("%c %c %d\n", vertex1[i], vertex2[i], weight[i]);
        }
    }

	return 0;
}
