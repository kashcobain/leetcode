class Solution {
public:

string decToBinary(int n) {
    
    if(n==0) return "1";

    string bin = "";

    while (n > 0) {
        int bit = n % 2;
        bin.push_back('0' + bit);
        n /= 2;
    }

    reverse(bin.begin(), bin.end());

    for(int i=0;i<bin.size();i++)
    {
        if(bin[i]=='1')
            bin[i]='0';
        else
            bin[i]='1';
    }

    return bin;
}

int bitwiseComplement(int n) {
    string ans = decToBinary(n);
    return stoi(ans,0,2);
}
};