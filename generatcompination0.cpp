void get_com(int i, int lst_val) {

    if(i == r) {
        forn(j , comp.size()) vcom[c_c].push_back(comp[j]);
        ++c_c;
        return;
    }
    if(c_c > k) return;
    for(int j = (lst_val + 1); j <= c; j++) {
        comp.push_back(j - 1);
        get_com(i + 1, j);
        comp.pop_back();
    }

}
