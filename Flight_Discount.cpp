//#define KPR_111


#include<bits/stdc++.h>
using namespace std;

#define ll long long 

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n+1);
    vector<ll> disc(n+1,1e18);  // disc vector to if the discount value if applied on that particular node
    vector<ll> dist(n+1,1e18);

    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }

    dist[1]=0;

	priority_queue<pair<ll,pair<ll,ll>>, 
	vector<pair<ll,pair<ll,ll>>>, 
	greater<pair<ll,pair<ll,ll>>> > pq;

    //c d f // cost destination flag
    pq.push({0,{1,0}});

    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();

        ll d=it.first;
        ll u=it.second.first;
        ll f=it.second.second;

        if(f==1){
            if(disc[u]<d)continue;
        }
        if(f==0){
            if(dist[u]<d)continue;
        }

        for(auto e : adj[u]){
            ll v=e.first;
            ll c=e.second;
            if(f==0)
            {
                if(dist[v]> c + d){
                    dist[v]=c+d;
                    pq.push({dist[v],{v,0}});
                }
                if(disc[v]> d + c/2 ){  // as we till now not used discount , we are using it here
                    disc[v]=d+c/2;
                    pq.push({disc[v],{v,1}});
                }
            }
			      if(f==1)
			      {
				        if(disc[v] > d + c)
				        {
					          disc[v] = d + c;
					          pq.push({disc[v], {v,1}});	
				        }
			      }
        }
    }
    cout<<disc[n]<<endl;
}