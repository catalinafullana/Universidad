using namespace std;
#include <iostream>

int main() {
	int n, pmax;
    int act;
	int v[200000];
	cin >> n >> pmax;
	while(n!=0){
        for (int i = 0; i < n; i++) {
            cin >> act;

            //buscar indice
            int indice =0;
            while (v[indice] < act&& indice < n) indice++;

            for(int j=n;j>n;j--)
                v[i + 1] = v[i];


            v[indice] = act;
        }

        /*
		int total = 0;
        bool desorden = true;
        //quickSort(v, 0, n);
        for (int j = 0; j < n - 1; j++)
            for(int i=0;i<n-1;i++)
                if (v[i + 1] < v[i]) {
                    int temp = v[i + 1];
                    v[i+1] = v[i];
                    v[i] = temp;
                    desorden = true;
                }
        */

        bool si = true;
        int i = 0;
        int total = 0;
        while (i<n&&si) {
            int j = i+1;
            while (j < n&&si) {
                if (v[i] + v[j] >  pmax) si = false;
                else total++;
                j++;
            }
            i++;
        }
		cout << total << endl;
		cin >> n >> pmax;

	}
}