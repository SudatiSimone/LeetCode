int minOperations(int n) {
    int res=0, index_centro, centro;
    vector <int> vettore (n,1);
    int len= vettore.size();
    for (int i=0; i<len; ++i){
        vettore[i]+=2*i;
    }
    if (len%2!=0){// se dispari
        index_centro=(n/2)+1;
        centro= vettore[index_centro-1];
        for (int i=0; i<index_centro; ++i){
            res+= (centro-vettore[i]);
        }
    } else { //se pari 
        index_centro=(n/2)-1;
        centro= (vettore[index_centro+1]+vettore[index_centro])/2;
        for (int i=0; i<=index_centro;++i){
            res+=(centro-vettore[i]);
        }
    }
    return res;
}