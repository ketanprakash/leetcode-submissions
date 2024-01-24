class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int s1 = max(0, (n1 - n2) / 2), e1 = min(n1, (n1 + n2) / 2), cut1, cut2;
        int l1, l2, r1, r2;

        while (s1 <= e1){
            cut1 = s1 + (e1 - s1) / 2;
            cut2 = (n1 + n2) / 2 - cut1;
            l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            r1 = cut1 == n1 ? INT_MAX : nums1[cut1];

            l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            r2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1){
                if ((n1 + n2) % 2 == 0){
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                else {
                    return min(r1, r2);
                }
            }
            else if (l1 > r2){
                e1 = cut1 - 1; 
            }
            else {
                s1 = cut1 + 1;
            }
        }

        return 0;
    }
};