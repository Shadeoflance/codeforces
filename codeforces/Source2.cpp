#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//freopen("cities.in", "r", stdin);
	//freopen("cities.out", "w", stdout);
	int n;
	vector<pair<int,double>> a, b;
	vector<vector<int>> ans;
	cin>>n;
	for (int i=0; i<n; i++)
	{
		int x,y;
		cin>>x>>y;
		if (y==1) 
			b.push_back (make_pair(i,x)); 
		else 
			{
				a.push_back (make_pair(i,1.0*x/y));
			}	
	}
	bool t;
	t=false;
	while (t)
	{
		t=false;
		vector<double> c;
		for (int i=0; i<b.size(); i++)
		{
			for (int j=i+1; j<b.size(); i++)
			{
				
				double c=((b[i].second+b[j].second)/2);
				for (int k=0; k<a.size(); k++)
				{
					if (c==a[k].second )
					{
						b.push_back (a[k] );
						vector <int> d;
						d.push_back(a[k].first);
						d.push_back(b[i].first);
						d.push_back(b[j].first);
						ans.push_back (d);
						a.erase(a.begin() + k);
						k--;
						t=true; 
					}
				}
			}
		}
		
	}
	if (a.empty())
	{
		cout<<"YES";
		for (int i=2; i<n; i++)
		cout<<ans[i][0]<<' '<<ans[i][1]<<' '<<ans[i][2];
	}
	else
	{
		cout<<"NO"<<'\n'<<a[0].first;
		
	}
	return 0;
}