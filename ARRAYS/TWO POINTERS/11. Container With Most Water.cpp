int maxArea(vector<int>& height) {
        int maxi=INT_MIN;
        int s=0;
        int e=height.size()-1;
        while(s<e){
            maxi=max(maxi,(e-s)* min(height[s],height[e]));
            if(height[s]<height[e])s++;
            else e--;
        }
        return maxi;
    }
