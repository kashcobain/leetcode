class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        int r = radius;

        int x = max(x1, min(xCenter, x2));
        int y = max(y1, min(yCenter, y2));

        int dx = xCenter - x;
        int dy = yCenter - y;

        if(dx * dx + dy * dy <= r * r)
            return true;

        return false;
    }
};