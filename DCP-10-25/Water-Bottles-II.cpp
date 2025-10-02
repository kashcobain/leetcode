class Solution {
public:
    int maxBottlesDrunk(int numbottles, int numexchange) {
        int drink=numbottles;
        int empty=numbottles;
        while(empty>=numexchange)
        {
            empty-=numexchange;
            numexchange++;
            drink++;
            empty++;
        }
        return drink;
    }
};