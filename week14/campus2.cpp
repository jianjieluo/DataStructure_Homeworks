#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

#define MAX 210
#define INF 1000000

int edges[MAX][MAX];
int len[MAX];
bool judge[MAX];

int dijkstra(int b, int e, int n) {
    memset(judge, 0, sizeof(judge));
    // memset(len, INF, n);
    for (int i = 0; i < n; ++i) {
        len[i] = INF;
    }
    len[b] = 0;

    for (int i = 0; i < n; ++i) {
        int min = INF;
        int v = b;
        for (int j = 0; j < n; ++j) {
            if (!judge[j] && len[j]<min) {
                min = len[j];
                v = j;
            }
        }
        judge[v] = true;
        for (int j = 0; j < n; ++j) {
            if( !judge[j] && len[v]+edges[v][j]<len[j] )
				len[j] = len[v]+edges[v][j];
        }
    }
    if (judge[e]) return len[e];
    else return -1;
}

int main () {
    int T,n,l;
	string b,e;
	cin >> T;
	while( T-- ){
		cin >> n;
		map<string,int> s;
		int num = 0;
		for( int i=0 ; i<MAX ; i++ )
			for( int j=0 ; j<MAX ; j++ )
				edges[i][j] = (i==j?0:INF);
		for( int i=0 ; i<n ; i++ ){
			cin >> b >> e >> l;
			if( !s.count(b) ) s[b] = num++;
			if( !s.count(e) ) s[e] = num++;
			edges[s[b]][s[e]] = edges[s[e]][s[b]] = l;
		}
		cin >> b >> e;
		if( b==e ) cout << 0 << endl;
		else if( !s.count(b) || !s.count(e) ) cout << -1 << endl;
		else cout << dijkstra(s[b],s[e],num) << endl;
	}
    return 0;
}