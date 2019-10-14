int N=100;
int status[100/32+2];

bool Check(int N, int pos){
    return (bool) (N & (1<<pos));
}

int Set(int N, int pos) {
    return N=N | (1<<pos);
}

void sieve(){
     int i, j, s;
     s=sqrt(N);
     for (i=3;i<=s;i+=2){
        if (Check(status[i>>5], i&31)==0){
            for (j=i*i;j<=N;j+=(i<<1))
                status[j>>5]=Set(status[j>>5], j&31);
        }
    }
    cout<<2<<endl;
    for(i=3;i<=N;i+=2){
        if(Check(status[i>>5], i&31)==0) cout<<i<<endl;
    }
}
