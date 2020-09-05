
bool myCmp(string s1, string s2)
{
    int l= min(s1.length(),s2.length());
    for(int i=0;i<l;i++)
        if(s1[i]>s2[i])
            return true;
        else if(s1[i]<s2[i])
            return false;
            
    if(s1.length()>l)
    {
        return s1[l-1]<s1[l];
    }
    if(s2.length()>l)
    {
        return s2[l-1]<s2[l];
    }
    
}

string Solution::largestNumber(const vector<int> &A) {

    vector<string> s;
    
    for(int i=0;i<A.size();i++)
        s.push_back(to_string(A[i]));

     sort(s.begin(),s.end(),myCmp);
    
    string temp;
    
    for(auto i:s)
    temp+=i;
    
    return temp;
    
}
