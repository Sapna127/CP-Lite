//delete middle element of stack

void solve(stack<int> st,int k){
	if(k==1) st.pop();
	int temp=st.top();
	st.pop();
	solve(st,k+1);
	st.push(temp);
}
stack<int> deleteMiddleEle(stack<int> st, int n){
	if(st.size()==0) return st;
	int k=(n/2)+1;
	solve(s,k);
	return s;
}
