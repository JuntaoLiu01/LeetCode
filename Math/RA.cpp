class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (C-A)*(D-B) + (G-E)*(H-F);
        int overlap = 0;
        if(!((G<=A)||(E>=C)||(H<=B)||(F>=D))){
            overlap = (min(C,G)-max(A,E))*(min(H,D)-max(B,F));
            return area-overlap;
        }
        return area;
    }
};