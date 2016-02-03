#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool p(pair<int, int> x, pair<int, int> y)
{
	return x.first < y.first;
}

int main()
{
	/*freopen("cond.in", "r", stdin);
	freopen("cond.out", "w", stdout);*/
	vector <int> a;
	vector<pair<int, int>> b;
	int i,n,m,j,x, y,c=0;
	cin>>n;
	for (i=0;i<n;i++) 
	{
		cin>>x;
		a.push_back(x);
	}
	cin>>m;
	for (i=0;i<m;i++) 
	{
		cin>>x>>y;
		b.push_back(make_pair(x, y));
	}
	sort(b.begin(), b.end(), p);
	for (int j = 0; j < m; j++)
	{
		cout << b[j].first << b[j].second << endl;
	}
	for (i=0;i<n;i++) 
	{
		int t=1001;
		for(j=0;j<m;j++)
		{
			if (b[j].first>=a[i])
			{
				if (b[j].second<t)
				{
					t=b[j].second;
				}
			}
		}
		c+=t;
	}
	cout<<c;
	return 0;
}