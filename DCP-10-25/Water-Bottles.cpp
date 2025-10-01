class Solution {
public:
    int numWaterBottles(int numbottles, int numexchange) {
        int total=0;
        int empty=0;
        while(numbottles>0)
        {
            total+=numbottles;
            empty+=numbottles;
            numbottles=empty/numexchange;
            empty=empty%numexchange;
        }
        return total;
    }
};