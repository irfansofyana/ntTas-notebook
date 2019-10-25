void search(string text, string pattern) 
{ 
    string concat = pattern + "$" + text; 
    int l = concat.length(); 
    int Z[l]; 
    getZarr(concat, Z); 
    for (int i = 0; i < l; ++i) { 
        if (Z[i] == pattern.length()) 
            cout << "Pattern found at index "
                << i - pattern.length() -1 << endl; 
    }
} 

void getZarr(string s, Z[]){
    int L = 0, R = 0;
    int n = s.size();
    for (int i = 1; i < n; ++i) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R] == s[R-L]) ++R;
            Z[i] = R-L; --R;
        }
        else {
            int k = i-L;
            if (Z[k] < R-i+1) Z[i] = Z[k];
            else {
                L = i;
                while (R < n && s[R] == s[R-L]) ++R;
                Z[i] = R-L; --R;
            }
        }
    }
}