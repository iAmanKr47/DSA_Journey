//[start, end): end is not included
class MyCalendar {
public:
    set<pair<int,int>>st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(st.empty()){
            st.insert({start,end});
            return true;

        }
        //comapre the current interval with the interbals present int the set
        //first find lower bound of current interval// which will return the just greater interval  ( >=x )
        auto it=st.lower_bound({start,end});
        //it will point to the just greater intrval present in the set 
        //now check will it collide or not 
        if(it!=st.end() && it->first<end)return false;
        
        //current intreval can also collide with just prev interval of lower bound also
        auto prevItr=prev(it); //prev return the prevoius pointer
        if(it!=st.begin() && prevItr->second>start)return false;

        //if current interval is not colliding with any of these then it safe to include that interval
        st.insert({start,end});
        return true;

    }
};
