class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area=0;

        area+=(ax2-ax1)*(ay2-ay1);
        area+=(bx2-bx1)*(by2-by1);

        int left=max(ax1,bx1);
        int right=min(ax2,bx2);

        int top=min(ay2,by2);
        int bottom=max(ay1,by1);

        int width=right-left;
        int height=top-bottom;

        int common=height*width;

        if(width <= 0 || height <= 0)
            common = 0;

        return area-common;
    }
};