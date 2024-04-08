int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cntOnes=0;
        int cntZeroes=0;
        for(int i=0;i<students.size();i++){
            if(students[i]==1)cntOnes++;
            else cntZeroes++;
        }
        for(auto i: sandwiches){
            if(i==1){
                if(cntOnes==0)break;
                cntOnes--;
            }
            else{
                if(cntZeroes==0)break;
                cntZeroes--;
            }
        }
        return cntZeroes+cntOnes;
    }
