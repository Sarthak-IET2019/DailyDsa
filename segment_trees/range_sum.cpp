#include<bits/stdc++.h>
using namespace std;


int seg[400001];

int build(vector<int>&arr,int l,int h,int ind){

    if(l==h) return seg[ind]=arr[l];

    int mid = l+(h-l)/2;

    int left_half = build(arr,l,mid,2*ind+1);
    int right_half = build(arr,mid+1,h,2*ind+2);

    seg[ind]=left_half+right_half;

    return seg[ind];
}

void build2(vector<int>&arr,int l,int h,int ind){
    
    if(l==h) {
        seg[ind]=arr[l];
        return;
    }

    int mid = l+(h-l)/2;
    build(arr,l,mid,2*ind+1);
    build(arr,mid+1,h,2*ind+2);

    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}

int query(int ql,int qr,int l,int r,int ind){
    
    if(ql>r or qr<l) return 0;
    if(ql<=l and qr>=r) return seg[ind];
   
    int mid = l+(r-l)/2;

    int lf = query(ql,qr,l,mid,2*ind+1);
    int rg = query(ql,qr,mid+1,r,2*ind+2);

    return lf+rg;

}

void point_update(int l,int r,int ind,int pt,int val){// in array update arr[pt]=val;

        if(pt>r or pt<l) return;
        if(l==pt and r==pt) {seg[ind]=val;
        return;
        }

        int mid = l + (r-l)/2;

        point_update(l,mid,2*ind+1,pt,val);
        point_update(mid+1,r,2*ind+2,pt,val);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];

}


void range_update(int l, int r,int ind,int ql,int qr,int val){
    
}

int main(){

    vector<int>arr={1,2,3,4,5};
    int n= arr.size();

    // int t = build(arr,0,n-1,0);
    build2(arr,0,n-1,0);
    for(int i=0;i<4*n;++i) cout<<seg[i]<<" ";  
    cout<<endl;


    // int q; cin>>q;
    // while(q--){
    //     int l,r;
    //     cin>>l>>r;
    //     cout<<query(l,r,0,n-1,0)<<endl;

    // }

    int uq;
    cin>>uq;
    while(uq--){

        int pt,val;
        cin>>pt>>val;
        point_update(0,n-1,0,pt,val);
        for(int i=0;i<4*n;++i) cout<<seg[i]<<" ";  
        cout<<endl;  

    }


    return 0;
}