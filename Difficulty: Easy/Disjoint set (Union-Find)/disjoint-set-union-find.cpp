/*Complete the functions below*/
int find(int par[], int x) {
    // add code here
    if(par[x]==x)return x;
    return par[x] = find(par,par[x]);
}

void unionSet(int par[], int x, int z) {
    // add code here.
    int parX = find(par,x);
    int parZ = find(par,z);
    if(parX==parZ)return;
    else par[parX]=parZ;
}